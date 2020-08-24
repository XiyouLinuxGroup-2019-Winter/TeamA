#include "epoll.h"
#define SIZE 100
void Print_menu();

int Check_data(char *num);//检查输入是否为数字
int Get_choice_int(char* str);
char *Time();
void Print_apply(char* buf);
int GetPassword(char *password);
int main()
{
    Init_socket();

    List_Init(head,box_node_t);
    List_Init(fhead,box_node_t);
    pthread_mutex_init(&mutex_login,NULL);
    pthread_cond_init(&cond_login,NULL);
    pthread_mutex_init(&mutex,NULL);
    pthread_cond_init(&cond,NULL);


    Login_menu();
    //printf("开始收包\n");
    Turn_worker_thread();
    //Menu();
    close(cfd);
}
void Init_socket()
{
    
    
    printf("客户端启动\n");
    struct sockaddr_in serv_addr;


    cfd=Socket(AF_INET,SOCK_STREAM,0);

    bzero(&serv_addr,sizeof(serv_addr));
    serv_addr.sin_family=AF_INET;
    serv_addr.sin_port=htons(SERV_PORT);
    inet_pton(AF_INET,SERV_ADDRESS,&serv_addr.sin_addr.s_addr);
    //serv_addr.sin_addr.s_addr=htonl(INADDR_ANY);
    Connect(cfd,(struct sockaddr*)&serv_addr,sizeof(serv_addr));

    Turn_worker_thread();

    printf("客户端启动成功!\n");

}

//密码回显
//返回值不包括'\0'
int GetPassword(char *password)
{
	char ch;
	int i=0;
    do
    {
        ch = getch();
        if(ch != '\n' && ch != '\r' && ch!=127)
        {
            password[i]=ch;
            printf("*");
            i++;
        }
        else if(((ch!='\n')|(ch!='\r'))&&(ch==127))
        {
            if(i>0)
            {
                i--;
                printf("\b \b");
            }
        }
    }while(ch!='\n'&&ch!='\r');
    password[i]='\0';
	return i;
}
void Register()
{
    Account_t register_t;
    
    char buf[BUFSIZ];
    memset(buf,0,sizeof(buf));
    printf("用户名:");
    printf("[此用户名为您暂时的名字,并不是登录账号]\n");
    scanf("%s",register_t.name);
    //fgets(register_t.username,sizeof(register_t.username),stdin);
    printf("密码:");
    scanf("%s",register_t.password);
    //fgets(register_t.password,sizeof(register_t.password),stdin);
    register_t.flag=REGISTER;

    memcpy(buf,&register_t,sizeof(Account_t));

    printf("client flag:%d\n",register_t.flag);
    printf("client message:%s\n",register_t.password);
    printf("client send:%s\n",register_t.name);
    if(send(cfd,buf,sizeof(buf),0)<0)
    {
        my_err("send error!",__LINE__);
    }
}
void Register_apply(char* buf)
{
    message mes;
    memcpy(&mes,buf,sizeof(mes));

    printf("--------%s\n",mes.messsge);
    int id=mes.id;
    printf("----等会输入账号时请输入系统给您的账号\n");
    printf("您的账号是:%d\n",mes.id);
    printf(">...\n");
    printf("正在返回登录界面\n");
    usleep(1000);
    Login_menu();
    //sleep(1);
    //getchar();
}
/*void Register_error_apply(char* buf)
{
    message mes;
    printf("-----%s\n",mes.messsge);

}*/
int Check_data(char *num)
{
    int i;
    for(i=0;num[i];i++) 
    {
        if(num[i]>'9' || num[i]<'0')//只要有非数字，就返回错误
        {
            printf("您的输入不为数字\n");
            return 0;
        }
    }

    if(i>100)//长度超过100位，返回错误
    {
        printf("超出数字长度\n");
        return 0;
    }
    return 1;
}
int Get_choice_int(char* str)
{
    while (1)
    {
        scanf("%s",str);
        if (Check_data(str)==0)
        {
            //printf("wraning------[[[不要输入之前注册的用户名]]]\n");
            printf("输入错误,请重新输入整数\n");
        }
        else
        {
            printf("输入正确\n");
            break;
        }
    }
    int choice;
    choice=atoi(str);
    return choice;
}
void Login()
{
    char buf[BUFSIZ];
    Account_t account;
    account.flag=LOGIN;
    //printf("wraning------[[[不要输入之前注册的用户名]]]\n");
    printf("请输入账号:\n");
    //scanf("%d",&account.id);
    char str[SIZE];
    while (1)
    {
        scanf("%s",str);
        if (Check_data(str)==0)
        {
            printf("wraning------[[[不要输入之前注册的用户名]]]\n");
            printf("输入错误,请重新输入\n");
        }
        else
        {
            printf("账号输入正确\n");
            break;
        }
    }

    //printf("%d\n", atoi(str));
    account.id=atoi(str);

    printf("请输入密码:\n");
    scanf("%s",account.password);
    
    username=account.id;
    memcpy(buf,&account,sizeof(account));
    if(send(cfd,buf,sizeof(buf),0)<0)
    {
        my_err("send error!",__LINE__);
    }

    pthread_mutex_lock(&mutex_login);
    pthread_cond_wait(&cond_login,&mutex_login);
    if(flag_login==1)
        Menu();
    flag_login=0;
    pthread_mutex_unlock(&mutex_login);
}
void Login_apply(char* buf)
{
    message mes;
    memcpy(&mes,buf,sizeof(mes));
    pthread_mutex_lock(&mutex_login);
    if(strcmp(mes.messsge,"y")==0)
    {
        printf("登录成功\n");
        flag_login=1;
    }
    else if(strcmp(mes.messsge,"a")==0)
        printf("账号已登录\n");
    else if(strcmp(mes.messsge,"n")==0)
        printf("密码错误或账户不存在\n");
    /*else if 
    {
        printf("---%s\n",mes.message);
    }*/
    
    
    pthread_cond_signal(&cond_login);
    pthread_mutex_unlock(&mutex_login);
}
void Login_menu()
{

    int choice=-1;
   
    //int choice=-1;
    while(choice)
    {
        usleep(10000);
        //system("clear");
        printf("\t\t\033[44;34m\033[44;37m**************************\033[0m\n");
        printf("\t\t\033[1;34m*        1.注册          \033[1;34m*\033[0m \n");
        printf("\t\t\033[1;34m*        2.登录          \033[1;34m*\033[0m \n");
        printf("\t\t\033[1;34m*        0.退出          \033[1;34m*\033[0m \n");
        printf("\t\t\033[44;34m\033[44;37m**************************\033[0m\n");
        printf("\t\tchoice：");
        char choice_t[SIZE];
        choice=Get_choice_int(choice_t);
        //choice=Get_choice_int();
        //scanf("%d",&choice);
        //while(getchar()!='\n');
        //choice=Get_choice(choice_t);    
        switch(choice)
        {
            case 1:
                puts("注册");
                Register();
                break;
            case 2:
                puts("登录");
                Login();
                break;
            /*case 3:
                puts("找回密码");
                Modify_password();
                break;*/
            default:
                break;
        }
    }
}
void Exit()
{
    message mes;
    mes.flag=EXIT;
    mes.id=username;
    char mess[256];
    sprintf(mess,"用户[%d]退出登录\n",username);
    strcpy(mes.messsge,mess);

    char buf[BUFSIZ];
    memcpy(buf,&mes,sizeof(mes));
    if(send(cfd,buf,sizeof(buf),0)<0)
    {
        my_err("send error",__LINE__);
    }
   // Login_menu();
}
/*void Exit_apply(char* buf)
{   
    pthread_mutex_lock(&mutex);
    message mes;
    printf("---%s\n",mes.messsge);
    pthread_cond_wait(&cond,&mutex);
    pthread_mutex_unlock(&mutex);

}*/
void *Recv_pack(void *arg)
{
    pthread_t apply_id;
    char buf[BUFSIZ];    
    while(1)
    {
        int n=recv(cfd,buf,sizeof(buf),0);
        if(n<0)
        {
            my_err("recv error",__LINE__);
        }
        //printf("client recv:%s\n",buf);
        //pthread_mutex_lock(&mutex);
        else if(n==0)
        {
            printf("\n服务端已经停止了工作,请退出客户端\n");
            exit(0);
        }
        int flag;
        memcpy(&flag,buf,sizeof(int));
        printf("client recv flag:%d\n",flag);
        switch (flag)
        {
            /*case EXIT_APPLY:
                pthread_mutex_lock(&mutex);
                Exit_apply(buf);
                pthread_cond_signal(&cond);
                pthread_mutex_unlock(&mutex);
                break;*/
            case PRINT_APPLY:
                //pthread_mutex_lock(&mutex);
                Print_apply(buf);
                //pthread_cond_signal(&cond);
                break;
            case REGISTER_APPLY:
                Register_apply(buf);
                break;
            /*case REGISTER_ERROR_APPLY:
                Register_error_apply(buf);
                break;*/
            case LOGIN_APPLY:
                Login_apply(buf);
                break;
            case ADD_FRIEND_APPLY:
                Add_friend_apply(buf);
                break;
            case ADD_FRIEND_ACCEPT_APPLY:
                Add_friend_accept_appy(buf);
            case DEL_FRIEND_APPLY:
                Del_friend_apply(buf);
                break;
            //一起实现
            //case SHOW_FRIEND_STATUS_APPLY:
            case VIEW_FRIEND_LIST_APPLY:
                View_friend_list_apply(buf);
                //pthread_cond_signal(&cond);
                break;
            case SHIELD_APPLY:
                Shield_friend_apply(buf);
                break;
            case UNSHIELD_APPLY:
                Unshield_friend_apply(buf);
                break;
            case PRIVATE_CHAT_APPLY:
                Private_chat_apply(buf);
                break;
            case VIEW_CHAT_HISTORY_APPLY:
                View_chat_history_apply(buf);
                break;
            case CREAT_GROUP_APPLY:
                Create_group_apply(buf);
                break;
            case ADD_GROUP_APPLY:
                Add_group_apply(buf);
                break;
            case GROUP_APPLY:
                Group_apply(buf);
                break;
            case ADD_GROUP_ACCEPT_APPLY:
                Add_group_accept_apply(buf);
                break;
            //一起实现
            case DEL_GROUP_APPLY:
                Del_group_apply(buf);
                break;
            case WITHDRAW_GROUP_APPLY:
                Withdraw_group_apply(buf);
                break;
            case VIEW_GROUP_MEMBER_APPLY:
                View_group_member_apply(buf);
                break;
            case VIEW_ADD_GROUP_APPLY:
                View_add_group_apply(buf);
                break;
            case GROUP_CHAT_APPLY:
                Group_chat_apply(buf);
                break;
            case VIEW_GROUP_RECORD_APPLY:
                View_group_record_apply(buf);
                break;
            case SET_GROUP_ADMIN_APPLY:
                Set_group_admin_apply(buf);
                break;
            case KICK_APPLY:
                Kick_apply(buf);
                break;
            case RECV_FILE:
                Recv_file(buf);
                break;
        }
        //pthread_mutex_unlock(&mutex);
    }
}
void Turn_worker_thread()
{
    pthread_t pid_recv;
    pthread_create(&pid_recv,NULL,Recv_pack,NULL);
}
void Friend_box()
{
    //printf("111");
    Relation_t relation;
    //box_list_t pos=head;
    box_list_t pos;
    List_ForEach(head,pos)
    {
        if(pos->data.recver==username)
        {
            printf("uid\tsender\trecver\tmessage\n");
            printf("%d\t%d\t%d\t%s\n",username,pos->data.sender,pos->data.recver,pos->data.message);
        //pos=pos->next;
            break;
        }
    }
    List_ForEach(head,pos)
    {
        if(pos->data.recver==username)
        {
            List_DelNode(pos);
            char ch;
            printf("请输入同意还是不同意:\n");
            printf("同意[y or Y]不同意[n]");
        scanf("%c",&ch);
        if(ch=='Y' || ch=='y')
        {
                char str[BUFSIZ];
                memset(str,0,sizeof(str));
                
                relation.flag=ADD_FRIEND_ACCEPT;
                strcpy(relation.message,"y");
                relation.sender=pos->data.recver;//被申请者
                relation.recver=pos->data.sender;//申请者
                //mes.send_fd=box_tt.send_fd;//申请者客户端端口号
                //mes.recv_fd=box_tt.recv_fd;//被申请者客户端端口号
                memcpy(str,&relation,sizeof(relation));
                if(send(cfd,str,sizeof(str),0)<0)
                {
                    my_err("send error",__LINE__);
                }
                printf("同意好友申请发送成功\n");
        }
        else
        {
            char str[BUFSIZ];
            memset(str,0,sizeof(str));
                
            relation.flag=ADD_FRIEND_ACCEPT;
            strcpy(relation.message,"n");
            relation.sender=pos->data.recver;//被申请者
            relation.recver=pos->data.sender;//申请者
            //mes.send_fd=box_tt.send_fd;//申请者客户端端口号
            //mes.recv_fd=box_tt.recv_fd;//被申请者客户端端口号
            memcpy(str,&relation,sizeof(relation));
            if(send(cfd,str,sizeof(str),0)<0)
            {
                my_err("send error",__LINE__);
            }
            printf("拒绝好友申请发送成功\n");
        }
        }
    }
    /*
    system("clear");
    box_list_t pos;
    while(pos!=NULL)
    {
        printf("好友消息盒子信息\n");
        printf("uid\tsend_fd\trecv_fd\t消息\n");
        printf("%d\t%d\t%d\t%s\t",username,pos->data.send_fd,pos->data.recv_fd,pos->data.message);
        pos=pos->next;
    }
    apply_messgae mes;
    char str[BUFSIZ];
    memset(&mes,0,sizeof(mes));
    mes.flag=ADD_FRIEND_ACCPET;
    //strcpy(mes.message,"y");
    mes.sender=username;//被申请者
    mes.recver=pos->data.sender;//申请者
    mes.send_fd=pos->data.send_fd;//申请者客户端端口号
    mes.recv_fd=pos->data.recv_fd;//被申请者客户端端口号
    memcpy(str,&mes,sizeof(mes));
    printf("cfd:%d\n",cfd);
    int id;
    List_ForEach(head,pos)
    {
        apply_messgae mes;
        memcpy(&mes,buf,sizeof(mes));
        printf("[%d]申请向您添加为好友\n",mes.recver);
        char ch;
        scanf("%c",&ch);
        getchar();
        if(ch=='Y' || ch=='y')
        {
            //strcpy(mes.message,"y");
            if(send(,str,sizeof(str),0)<0)
            {
                my_err("send error",__LINE__);
            }
            printf("同意好友申请发送成功\n");
        }
        else
        {
            char str1[BUFSIZ];
            //memset(&mes,0,sizeof(mes));
            mes.flag=ADD_FRIEND_ACCPET;
            strcpy(mes.message,"n");
            mes.sender=username;//被申请者
            mes.recver=pos->data.sender;//申请者
            memcpy(str1,&mes,sizeof(mes));
            if(send(cfd,str1,sizeof(str1),0)<0)
            {
                my_err("send error",__LINE__);
            }
            printf("拒绝好友申请发送成功\n");
        }
     
    }   
*/
    
}

void Print_apply(char* buf)
{
    
    message mes;
    memcpy(&mes,buf,sizeof(mes));
    //pthread_mutex_lock(&mutex);
    if(strcmp(mes.messsge,"d")==0)
    {
        printf("您申请的好友不在线,您可以选择添加其他朋友\n");
    }
    else if(strcmp(mes.messsge,"w")==0)
        printf("正在等待对方验证，请不要重复发好友申请\n");
    else 
        printf("--%s\n",mes.messsge);
    //pthread_cond_wait(&cond,&mutex);
    //pthread_mutex_unlock(&mutex);    
}
void Add_friend_accept_appy(char* buf)
{
    apply_messgae mes;
    memcpy(&mes,buf,sizeof(mes));
    printf("-----%s\n",mes.message);
}
void Add_friend_apply(char* buf)
{
    //apply_messgae mes;
    box_t box;
    memcpy(&box,buf,sizeof(box));
    

    
    box_list_t new;
    new=(box_list_t)malloc(sizeof(box_node_t));
    printf("你有请求消息来了,在消息盒子\n");
   

    new->data.flag=box.flag;
    new->data.sender=box.sender;//申请者
    new->data.recver=box.recver;//被申请者
    new->data.send_fd=box.send_fd;//申请者客户端端口号
    new->data.recv_fd=box.recv_fd;//被申请者客户端端口号
    strcpy(new->data.message,box.message);
    List_AddTail(head,new);

    printf("client message:%s\n",new->data.message);

    printf("server send message:%s\n",box.message);
    printf("server send flag:%d\n",box.flag);
    printf("server/ friend send id:%d\n",box.sender);
    printf("server/ friend recv id:%d\n",box.recver);
    //朋友客户端号
    printf("server/ friend recv_fd:%d\n",new->data.recv_fd);
    printf("server/ friend send_fd:%d\n",new->data.send_fd);
    


    usleep(100);

    /*if(mes.sender==username)
    {
        printf("不能向自己发送好友申请\n");
        return;
    }*/
 
}
void Add_friend()
{
    int id;
    puts("请输入想要添加好友的账号[id]:\n");
    scanf("%d",&id);
    if(id==username)
        printf("请不要添加自己为好友\n");
    
    char buf[BUFSIZ];
    sprintf(buf,"%d",id);
    printf("buf:%s\n",buf);

    char str[BUFSIZ];
    memset(str,0,sizeof(str));
    Relation_t relation;
    relation.flag=ADD_FRIEND;
    relation.sender=username;//发送者
    relation.recver=id;//被申请者
    strcpy(relation.message,"");
    memcpy(str,&relation,sizeof(relation));

    printf("client flag:%d\n",relation.flag);
    printf("client message:%s\n",relation.message);
    printf("client send:%d\n",relation.sender);
    printf("client recv:%d\n",relation.recver);

    if(send(cfd,str,sizeof(str),0)<0)
    {
        my_err("send error!",__LINE__);
    }
}


void Del_friend()
{
    
    int id;
    puts("请输入要删除的好友账号:");
    scanf("%d",&id);

    char buf[BUFSIZ];
    sprintf(buf,"%d",id);
    printf("buf:%s\n",buf);

    char str[BUFSIZ];
    memset(str,0,sizeof(str));
    Relation_t relation;
    relation.flag=DEL_FRIEND;
    relation.sender=username;//发送者
    relation.recver=id;//被申请者
    strcpy(relation.message,"");
    memcpy(str,&relation,sizeof(relation));

    printf("client flag:%d\n",relation.flag);
    printf("client message:%s\n",relation.message);
    printf("client send:%d\n",relation.sender);
    printf("client recv:%d\n",relation.recver);

    if(send(cfd,str,sizeof(str),0)<0)
    {
        my_err("send error!",__LINE__);
    }

    return;
}
void Del_friend_apply(char* buf)
{
    message mes;
    memcpy(&mes,buf,sizeof(mes));

    printf("--%s\n",mes.messsge);

}
void Shield_friend()
{
    int id;
    printf("请输入你要屏蔽的好友账号:\n");
    scanf("%d",&id);
    char buf[BUFSIZ];
    sprintf(buf,"%d",id);
    printf("buf:%s\n",buf);

    char str[BUFSIZ];
    memset(str,0,sizeof(str));
    Relation_t relation;
    relation.flag=SHIELD;
    relation.sender=username;//发送者
    relation.recver=id;//被申请者
    strcpy(relation.message,"");
    memcpy(str,&relation,sizeof(relation));

    if(send(cfd,str,sizeof(str),0)<0)
    {
        my_err("send error",__LINE__);
    }

    printf("client flag:%d\n",relation.flag);
    printf("client message:%s\n",relation.message);
    printf("client send:%d\n",relation.sender);
    printf("client recv:%d\n",relation.recver);


}
void Shield_friend_apply(char* buf)
{
    message mes;
    memcpy(&mes,buf,sizeof(mes));

    printf("--%s\n",mes.messsge);
}
void Unshield_friend()
{
    int id;
    printf("请输入你要解除屏蔽的好友账号:\n");
    scanf("%d",&id);
    char buf[BUFSIZ];
    sprintf(buf,"%d",id);
    printf("buf:%s\n",buf);

    char str[BUFSIZ];
    memset(str,0,sizeof(str));
    Relation_t relation;
    relation.flag=UNSHIELD;
    relation.sender=username;//发送者
    relation.recver=id;//被申请者
    strcpy(relation.message,"");
    memcpy(str,&relation,sizeof(relation));

    if(send(cfd,str,sizeof(str),0)<0)
    {
        my_err("send error",__LINE__);
    }

    printf("client flag:%d\n",relation.flag);
    printf("client message:%s\n",relation.message);
    printf("client send:%d\n",relation.sender);
    printf("client recv:%d\n",relation.recver); 
}
void Unshield_friend_apply(char* buf)
{
    message mes;
    memcpy(&mes,buf,sizeof(mes));

    printf("--%s\n",mes.messsge);
}

//一起实现
//void Show_friend_status();
void View_friend_list()
{
    
    //pthread_mutex_lock(&mutex);
    printf("-----------------------\n");
    printf("账号\t姓名\t状态\t关系\n");
    

    char str[BUFSIZ];
    memset(str,0,sizeof(str));
    Friend_t friend;
    friend.flag=VIEW_FRIEND_LIST;
    friend.send=username;//发送者
    friend.recv=username;//接收者
    strcpy(friend.message,"");
    memcpy(str,&friend,sizeof(friend));

    if(send(cfd,str,sizeof(str),0)<0)
    {
        my_err("send error",__LINE__);
    }

    //printf("client flag:%d\n",friend.flag);
    //printf("client message:%s\n",friend.message);
    //printf("client send:%d\n",friend.send);
    //printf("client recv:%d\n",friend.recv); 

    printf("-------------------------\n");
    //pthread_cond_wait(&cond,&mutex);
    //pthread_mutex_unlock(&mutex);
    
}
void View_friend_list_apply(char* buf)
{
    message mes;
    memcpy(&mes,buf,sizeof(mes));
    printf("%s\n",mes.messsge);
}


void Private_chat()
{
    int id;
    printf("请输入要私聊的好友账号:\n");
    scanf("%d",&id);
    //Chat_message mes;
    //memset(&mes, 0, sizeof(message));
  
 
    char buf[256];
    //char time[100];
    //char str[BUFSIZ];

    /*char time[30];

    memset(time,0,sizeof(time));
    strcpy(time,Time());*/
    system("clear");

    printf("-----正在与 %d 聊天-----\n",id);
    printf("   --- quit 退出 ---\n");

    printf("=============================\n");
    //printf("time:%s",time);
    scanf("%s",buf);
    do
    {

        char str[BUFSIZ];
       
        Chat_message mes;
        mes.flag=PRIVATE_CHAT;
        mes.sender=username;
        mes.recver=id;
        //strcpy(mes.time,time);
        //printf("client send:%s\n",time);
        strcpy(mes.message,buf);
        memcpy(str,&mes,sizeof(mes));
        if(send(cfd,str,sizeof(str),0)<0)
        {
            my_err("send error!",__LINE__);
        }
        //memset(buf,0,sizeof(buf));
        //memset(str,0,sizeof(str));
        //memset(&mes, 0, sizeof(message));


        //fgets(buf,sizeof(buf),stdin);
        scanf("%s",buf);

        /*if(strcmp(buf,"quit")==0)
            break;*/


    }while(strcmp(buf,"quit"));
   /* printf("按任意键返回\n");
    getchar();*/
    return ;
}
char *Time()
{
    /*time_t time_t;
    char timep[100];
    int len;
    //时间
    time(&time_t);
    strcpy(timep,ctime(&time_t));
    len=strlen(timep);
    timep[len-5]='\0'; */

    char* str;
    time_t  time_t;
    time(&time_t);

    str=ctime(&time_t);
    str[strlen(str-1)]='\0';
    return str;
}
void Private_chat_apply(char* buf)
{
    message mes;
    memcpy(&mes,buf,sizeof(mes));
    //if(strcmp(mes.message,"d")==0)
    //    printf("[%d]不在线 \n",mes.recver);
    //else
    //{
        //printf("                       %s",mes.time);
        printf("账号\t姓名\t消息\n");
        printf("%s\n",mes.messsge);
    //} 
}


void View_chat_history()
{
   
    int id;
    //system("clear");
    printf("请输入要查询聊天的好友账号:");
    scanf("%d",&id);
    
    char buf[BUFSIZ];
    Chat_message mes;
    mes.flag=VIEW_CHAT_HISTORY;
    strcpy(mes.message,"");
    mes.sender=username;
    mes.recver=id;
    memcpy(buf,&mes,sizeof(mes));
    if(send(cfd,buf,sizeof(buf),0)<0)
    {
        my_err("send error!",__LINE__);
    }


    /*pthread_mutex_lock(&lock_msg);
    pthread_cond_wait(&cond_msg,&lock_msg);
    pthread_mutex_unlock(&lock_msg);*/
}
void View_chat_history_apply(char*  buf)
{
    Chat_message mes;
    memcpy(&mes,buf,sizeof(mes));
    printf("--------------------聊天记录-------------------------\n");
    printf("%s\n",mes.message);
}

void Create_group()
{
    char buf[BUFSIZ];
    Group_t group; 
 

    printf("请输入群名:");
    scanf("%s",group.group_name);
    printf("此群名只是当前群的称谓,创建者id为该群唯一标识\n");
    group.group_owner=username;
    group.flag=CREAT_GROUP;
    memcpy(buf,&group,sizeof(group));
    if(send(cfd,buf,sizeof(buf),0)<0)
    {
        my_err("send error",__LINE__);
    }    
}
void Create_group_apply(char* buf)
{
    message mes;
    memcpy(&mes,buf,sizeof(mes));

    printf("--%s\n",mes.messsge);

}
void Add_group()
{
   int id;
   printf("请输入要加入的群号:\n");
   scanf("%d",&id);

    char buf[BUFSIZ];
    Relation_t relation;
    relation.flag=ADD_GROUP;
    relation.sender=username;
    relation.recver=id;
    strcpy(relation.message,"");
    memcpy(buf,&relation,sizeof(relation));
    if(send(cfd,buf,sizeof(buf),0)<0)
    {
        my_err("send error",__LINE__);
    }    
}
void Add_group_apply(char* buf)
{
    box_t box;
    memcpy(&box,buf,sizeof(box));
    

    
    box_list_t new;
    new=(box_list_t)malloc(sizeof(box_node_t));
    printf("你有群请求消息来了,在消息盒子\n");
   

    new->data.flag=box.flag;
    new->data.sender=box.sender;//申请者
    new->data.recver=box.recver;//管理员
    new->data.send_fd=box.send_fd;//申请者客户端端口号
    new->data.recv_fd=box.recv_fd;//管理员客户端端口号
    strcpy(new->data.message,box.message);
    List_AddTail(fhead,new);

    printf("client message:%s\n",new->data.message);

    printf("server send message:%s\n",box.message);
    printf("server send flag:%d\n",box.flag);
    printf("server/ group apply send id:%d\n",box.sender);
    printf("server/ group apply recv id:%d\n",box.recver);
    //管理员客户端号
    printf("server/ group recv_fd:%d\n",new->data.recv_fd);
    printf("server/ group send_fd:%d\n",new->data.send_fd);
    


    usleep(100);
}
void Group_box()
{
    //printf("111");
    Relation_t relation;

    box_list_t pos;
    List_ForEach(fhead,pos)
    {
        if(pos->data.recver==username)
        {
            printf("uid\tsender\trecver\tmessage\n");
            printf("%d\t%d\t%d\t%s\n",username,pos->data.sender,pos->data.recver,pos->data.message);
        //pos=pos->next;
            break;
        }
    }
    List_ForEach(fhead,pos)
    {
        if(pos->data.recver==username)
        {
            List_DelNode(pos);
            char ch;
            printf("请输入同意还是不同意:\n");
             printf("同意[y or Y]不同意[n]");
            scanf("%c",&ch);
            if(ch=='Y' || ch=='y')
            {
                    char str[BUFSIZ];
                    memset(str,0,sizeof(str));
                    
                    relation.flag=ADD_GROUP_ACCEPT;
                    strcpy(relation.message,"y");
                    relation.sender=pos->data.recver;//管理员
                    relation.recver=pos->data.sender;//申请者
                    //mes.send_fd=box_tt.send_fd;//申请者客户端端口号
                    //mes.recv_fd=box_tt.recv_fd;//被申请者客户端端口号
                    memcpy(str,&relation,sizeof(relation));
                    if(send(cfd,str,sizeof(str),0)<0)
                    {
                        my_err("send error",__LINE__);
                    }
                    printf("同意群申请发送成功\n");
            }
            else
            {
                char str[BUFSIZ];
                memset(str,0,sizeof(str));
                    
                relation.flag=ADD_GROUP_ACCEPT;
                strcpy(relation.message,"n");
                relation.sender=pos->data.recver;//被申请者
                relation.recver=pos->data.sender;//申请者
                //mes.send_fd=box_tt.send_fd;//申请者客户端端口号
                //mes.recv_fd=box_tt.recv_fd;//被申请者客户端端口号
                memcpy(str,&relation,sizeof(relation));
                if(send(cfd,str,sizeof(str),0)<0)
                {
                    my_err("send error",__LINE__);
                }
                printf("拒绝群申请发送成功\n");
            }
        }
    }
}
void Add_group_accept_apply(char* buf)
{
    apply_messgae mes;
    memcpy(&mes,buf,sizeof(mes));
    printf("-----%s\n",mes.message);
}
void Group_apply(char* buf)
{
    message mes;
    memcpy(&mes,buf,sizeof(mes));

    printf("%s\n",mes.messsge);
}

//一起实现
//void Del_group();
void Withdraw_group()
{
    int id;
    printf("请输入你要退出的群号:");
    scanf("%d",&id);

    char buf[BUFSIZ];
    Relation_t relation;
    relation.flag=WITHDRAW_GROUP;
    relation.sender=username;
    relation.recver=id;
    strcpy(relation.message,"");
    memcpy(buf,&relation,sizeof(relation));
    if(send(cfd,buf,sizeof(buf),0)<0)
    {
        my_err("send error",__LINE__);
    }    
    
    

}
void Withdraw_group_apply(char* buf)
{
    message mes;
    memcpy(&mes,buf,sizeof(mes));

    printf("%s\n",mes.messsge);
}
void Del_group_apply(char* buf)
{
    message mes;
    memcpy(&mes,buf,sizeof(mes));

    printf("%s\n",mes.messsge);
}

void View_group_member()
{
    int id;
    printf("请输入你要查询的群号:");
    scanf("%d",&id);

    char buf[BUFSIZ];
    Relation_t relation;
    relation.flag=VIEW_GROUP_MEMBER;
    relation.sender=username;
    relation.recver=id;
    strcpy(relation.message,"");
    memcpy(buf,&relation,sizeof(relation));
    if(send(cfd,buf,sizeof(buf),0)<0)
    {
        my_err("send error",__LINE__);
    }    
}
void View_group_member_apply(char* buf)
{
    printf("----------------------------\n");
    printf("账号\t姓名\t状态\n");
    
    message mes;
    memcpy(&mes,buf,sizeof(mes));

    printf("%s\n",mes.messsge);
}
void View_add_group()
{
    char str[BUFSIZ];
    memset(str,0,sizeof(str));
    Relation_t relation;
    relation.flag=VIEW_ADD_GROUP;
    relation.sender=username;//发送者
    relation.recver=username;//群号
    strcpy(relation.message,"");
    memcpy(str,&relation,sizeof(relation));

    if(send(cfd,str,sizeof(str),0)<0)
    {
        my_err("send error",__LINE__);
    }
    printf("-----------------------------\n");
 
}
void View_add_group_apply(char* buf)
{
    printf("----------------------------\n");
    printf("群号\t群名\t地位\n");
    message mes;
    memcpy(&mes,buf,sizeof(mes));

    printf("%s\n",mes.messsge);

}


void Group_chat()
{
    int id;
    printf("请输入要发送聊天的群账号:\n");
    scanf("%d",&id);
    while(getchar()!='\n');
    //Chat_message mes;
    //memset(&mes, 0, sizeof(message));
  
 
    char buf[256];
    //char time[100];
    //char str[BUFSIZ];

    /*char time[30];

    memset(time,0,sizeof(time));
    strcpy(time,Time());*/
    system("clear");

    printf("-----正在与 %d 群里聊天-----\n",id);
    printf("   --- quit 退出 ---\n");

    printf("=============================\n");
    //printf("time:%s",time);
    //fgets(buf,sizeof(buf),stdin);
    scanf("%s",buf);
    do
    {

        char str[BUFSIZ];
       
        Chat_message mes;
        mes.flag=GROUP_CHAT;
        mes.sender=username;
        mes.recver=id;
        //strcpy(mes.time,time);
        //printf("client send:%s\n",time);
        strcpy(mes.message,buf);
        memcpy(str,&mes,sizeof(mes));
        if(send(cfd,str,sizeof(str),0)<0)
        {
            my_err("send error!",__LINE__);
        }
        //memset(buf,0,sizeof(buf));
        //memset(str,0,sizeof(str));
        //memset(&mes, 0, sizeof(message));
        scanf("%s",buf);

        //fgets(buf,sizeof(buf),stdin);
       
        /*if(strcmp(buf,"quit")==0)
            break;*/


    }while(strcmp(buf,"quit"));

}
void Group_chat_apply(char* buf)
{
    message mes;
    memcpy(&mes,buf,sizeof(mes));
    /*if(strcmp(mes.message,"d")==0)
        printf("[%d]不在线 \n",mes.recver);*/
    //else
    //{
        //printf("                       %s",mes.time);
        printf("账号\t名字\t信息\n");
        printf("%s\n",mes.messsge);
    //} 
   
}
void View_group_record()
{
    int id;
    //system("clear");
    printf("请输入要查询聊天的群账号:");
    scanf("%d",&id);
    
    char buf[BUFSIZ];
    Chat_message mes;
    mes.flag=VIEW_GROUP_RECORD;
    strcpy(mes.message,"");
    mes.sender=username;
    mes.recver=id;
    memcpy(buf,&mes,sizeof(mes));
    if(send(cfd,buf,sizeof(buf),0)<0)
    {
        my_err("send error!",__LINE__);
    }

}
void View_group_record_apply(char* buf)
{

    message mes;
    memcpy(&mes,buf,sizeof(mes));
    printf("--------------------聊天记录-------------------------\n");
    printf("%s\n",mes.messsge);
}

void Set_group_admin()
{
    char buf[BUFSIZ];
    Group_leader leader;
    leader.flag=SET_GROUP_ADMIN;
    leader.sender=username;
    printf("请输入你设置的群号:");
    scanf("%d",&leader.recver);
    printf("请输入你要设置管理员的账号：");
    scanf("%d",&leader.admin);
    strcpy(leader.message,"");

    memcpy(buf,&leader,sizeof(leader));
    if(send(cfd,buf,sizeof(buf),0)<0) 
    {
        my_err("send error",__LINE__);
    }
}
void Set_group_admin_apply(char *buf)
{
    
    Group_leader leader;
    memcpy(&leader,buf,sizeof(leader));
    printf("%s\n",leader.message);
}
void Kick()
{
    char buf[BUFSIZ];
    Group_leader leader;
    leader.flag=KICK;
    leader.sender=username;
    printf("请输入你设置的群号:");
    scanf("%d",&leader.recver);
    printf("请输入你要删除成员的账号：");
    scanf("%d",&leader.admin);
    strcpy(leader.message,"");

    memcpy(buf,&leader,sizeof(leader));
    if(send(cfd,buf,sizeof(buf),0)<0) 
    {
        my_err("send error",__LINE__);
    }
    
}
void Kick_apply(char *buf)
{
    Group_leader leader;
    memcpy(&leader,buf,sizeof(leader));
    printf("%s\n",leader.message);
}
void Send_file()
{
    int id;
    printf("请输入要发送文件的好友账号");
    scanf("%d",&id);
    char file_name[100];
    printf("请输入要发送的文件的路径");
    scanf("%s",file_name);
    
    
    int flag=0;
    file file_t;
    char buf[BUFSIZ];

    file_t.recver=id;
    file_t.sender=username;
    file_t.flag=SEND_FILE;
    strcpy(file_t.file_name,file_name);
    printf("sizeof(file)=%ld\n",sizeof(file));
    int fd=open(file_name,O_RDONLY);
    if(fd<0)
    {
        my_err("open error",__LINE__);
    }

    //read返回值为0表示读到尾
    while((file_t.file_size=read(fd,file_t.message,sizeof(file_t.message)))!=0)
    {
        len+=file_t.file_size;
        memcpy(buf,&file_t,sizeof(file_t));
        if(send(cfd,buf,sizeof(buf),0)<0)
        {
            flag=1;
            sys_err("send error",__LINE__);
        } 
    }
    close(fd);
    if(flag==0)
    {
        printf("文件发送成功\n");
        usleep(1000);
        getchar();
    }
    else if(flag==1)
    {
        printf("文件发送失败\n");
        usleep(1000);
        getchar();
    }
}
void Recv_file(char *buf)
{
    int fd;
    file file_t;
    memcpy(&file_t,buf,sizeof(file_t));
    //如果文件不存在创建文件
    if((fd=open(file_t.file_name,O_RDWR | O_CREAT | O_APPEND,0600))<0)
    {
        my_err("open file_name error",__LINE__);
    }
    
    
    int ret=write(fd,file_t.message,file_t.file_size);
    if(ret<0)
    {
        my_err("write file error",__LINE__);
    }

    printf("ret=%d\n",ret);
    printf("file_name=%s\n",file_t.file_name);
    printf("recver=%d\n",file_t.recver);
    printf("sender=%d\n",file_t.sender);
    printf("file_size=%d\n",file_t.file_size);
    close(fd);
}
void Friend_menu()
{
    int choice=1;
    system("clear");
    
    while(choice)
    {
        usleep(1000);
        printf("\t\t\033[;36m\033[1m*********朋友管理*********\033[0m\n");
        printf("\t\t\033[1;36m|\033[0m--------1.添加好友-------\033[1;36m|\033[0m\n");
        printf("\t\t\033[1;36m|\033[0m--------2.好友消息盒子-------\033[1;36m|\033[0m\n");
        printf("\t\t\033[1;36m|\033[0m--------3.删除好友-------\033[1;36m|\033[0m\n");
        printf("\t\t\033[1;36m|\033[0m--------4.私聊好友-------\033[1;36m|\033[0m\n");
        printf("\t\t\033[1;36m|\033[0m--------5.屏蔽好友-------\033[1;36m|\033[0m\n");
        printf("\t\t\033[1;36m|\033[0m------6.解除屏蔽好友-----\033[1;36m|\033[0m\n");
        printf("\t\t\033[1;36m|\033[0m------7.查看好友列表-----\033[1;36m|\033[0m\n");
        printf("\t\t\033[1;36m|\033[0m------8.查看聊天记录-----\033[1;36m|\033[0m\n");
        printf("\t\t\033[1;36m|\033[0m------0.退出-----\033[1;36m|\033[0m\n");
        printf("\t\tchoice:\n");
        //printf("请输入选择:");
        scanf("%d",&choice);
        while(getchar() != '\n');
        switch (choice)
        {
            case 1:
                Add_friend();
                break;
            case 2:
                Friend_box();
                break;
            case 3:
                Del_friend();
                break;
            case 4:
                Private_chat();
                break;
            case 5:
                Shield_friend();
                break;
            case 6:
                Unshield_friend();
                break;
            case 7:
                View_friend_list();
                break;
            case 8:
                View_chat_history();
                break;
            case 0:
                break;
        }
    }
    return;
}
void Group_menu()
{
    system("clear");
    int choice=1;
    while(choice)
    {
        usleep(1000);
        //printf("\t\t\033[;34m\033[1m*********群管理*********\033[0m\n");
        printf("\t\t\033[1;34m|\033[0m--------1.创建群-------\033[1;34m|\033[0m\n");
        printf("\t\t\033[1;34m|\033[0m--------2.添加群-------\033[1;34m|\033[0m\n");
        printf("\t\t\033[1;34m|\033[0m--------3.群消息盒子-------\033[1;34m|\033[0m\n");
        printf("\t\t\033[1;34m|\033[0m--------4.退群---------\033[1;34m|\033[0m\n");
        printf("\t\t\033[1;34m|\033[0m--------5.群聊---------\033[1;34m|\033[0m\n");
        printf("\t\t\033[1;34m|\033[0m--------6.已加群-------\033[1;34m|\033[0m\n");
        printf("\t\t\033[1;34m|\033[0m--------7.群成员-------\033[1;34m|\033[0m\n");
        printf("\t\t\033[1;34m|\033[0m-----8.查看聊天记录----\033[1;34m|\033[0m\n");
        //printf("\t\t\033[1;34m|\033[0m------群管理权限-----\033[1;34m|\033[0m\n");
        //printf("\t\t\033[1;34m|\033[0m-------------------\033[1;34m|\033[0m\n");
        //printf("\t\t\033[1;34m|\033[0m*群主--1,2,3/管理员--3权限*\033[1;34m|\033[0m\n");
        //printf("\t\t\033[1;34m|\033[0m-------------------\033[1;34m|\033[0m\n");
        printf("\t\t\033[1;34m|\033[0m------9.设置管理员------\033[1;34m|\033[0m\n");
        printf("\t\t\033[1;34m|\033[0m------10.踢人-----\033[1;34m|\033[0m\n");
        printf("\t\t\033[1;34m|\033[0m--------0.退出--------\033[1;34m|\033[0m\n");
        printf("\t\tchoice:\n");
        scanf("%d",&choice);
        while(getchar() != '\n');
        switch (choice)
        {
            case 1:
                Create_group();
                break;
            case 2:
                Add_group();
                break;
            case 3:
                Group_box();
                break;
            case 4:
                Withdraw_group();
                break;
            case 5:
                Group_chat();
                break;
            case 6:
                View_add_group();
                break;
            case 7:
                View_group_member();
                break;
            case 8:
                View_group_record();
                break;
            case 9:
                Set_group_admin();
                break;
            case 10:
                Kick();
                break;
            case 0:
                break;
        }
    }
    return;
}

void Print_menu()
{
    printf("\t\t\033[1;34m**************************\033[0m\n");
    printf("\t\t\033[1;34m|        1.好友管理      \033[1;34m|\033[0m \n");
    printf("\t\t\033[1;34m|        2.群管理        \033[1;34m|\033[0m \n");
    printf("\t\t\033[1;34m|        3.发送文件      \033[1;34m|\033[0m \n");
    printf("\t\t\033[1;34m|        0.退出          \033[1;34m|\033[0m \n");
    printf("\t\t\033[1;34m**************************\033[0m\n");
    printf("\t\tchoice:");
}
void Menu()
{
    system("clear");
    int choice=1;
    //char choice_t[50];

    do
    {
      
        Print_menu();
        scanf("%d",&choice);
        //choice=Get_choice(choice_t);
       
        switch (choice)
        {
            case 1:
                Friend_menu();
                break;
            case 2:
                Group_menu();
                break;
            case 3:
                Send_file();
                break;
            case 0:
                Exit();
                //Login_menu();
                break;
        }
    }while(choice!=0);
 
}
void my_err(const char* err_string,int line)
{
    fprintf(stderr,"line:%d",line);
    perror(err_string);
    exit(1);
}
void Clear_buffer()
{
    char ch;
    while(getchar()!='\n')
		continue;
    /*while((ch=getchar())!='\n' && ch!=EOF)
            continue;*/
}
void display(char* str)
{
    int i;
    system("clear");
    for(i=0;i<50;i++)
        putchar('-');
    putchar('\n');
    printf("       %s\n",str);
    for(i=0;i<50;i++)
        putchar('-');
    putchar('\n');
    return;
}
char getch()
{
	char ch;

    system("stty -echo");//不回显
    system("stty -icanon");//设置一次性读完操作，如使用getchar()读操作,不需要按回车
    ch = getchar();
    system("stty icanon");//取消上面的设置
    system("stty echo");//回显

    return ch;
}
char* Get_string(char* buf,int len)
{
    char* str;
    int i=0;
    str=fgets(buf,len,stdin);
	if(str!=NULL)
	{
		while(str[i]!='\0' && str[i]!='\n')
			i++;
		if(str[i]=='\n')
			str[i]='\0';
		else
			while(getchar()!='\n')
				continue;
	}
	return str;
}
int Get_choice(char *choice_t)
{
    int choice =0;
    for(int i=0;i<strlen(choice_t) ;i++)
        if(choice_t[i]<'0' || choice_t[i]>'9')
            return -1;
    for(int i=0;i<strlen(choice_t);i++)
    {
        int t=1;
        for(int j=1;j<strlen(choice_t)-i;j++)
        {
            t *=10;
        }
        choice += t*(int)(choice_t[i] - 48);
    }
    return choice;
}
