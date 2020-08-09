#include "client.h"
int main()
{
    Init_socket();

    Turn_worker_thread();


    Login_menu();

    Menu();
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

    Connect(cfd,(struct sockaddr*)&serv_addr,sizeof(serv_addr));

    printf("客户端启动成功!\n");

}

void *Update_status(void* arg)
{
    int i;
    while(1)
    {
        pthread_mutex_lock(&mutex);
        for(i=1;i<=friend_;i++)
        {
            
        }
        pthread_mutex_unlock(&mutex);
        usleep(1);
    }
}
void *Recv_pack(void *arg)
{
    PACK pack_t;
    pthread_t pid;
    int flag;
    while(1)
    {
        if(recv(cfd,&pack_t,sizeof(PACK),0)<0)
        {
            my_err("recv error",__LINE__);
        }



        pthread_mutex_lock(&mutex);

        for(int i=1;i<=check_friend_num;i++)
        {
            if(strcmp(user.friends[i].name,pack_t.data.send_name)==0)
            {
                user.friends[i].message_num++;
                break;
            }
        }

        switch (pack_t.flag)
        {
            case ADD_FRIEND_APPLY:
                Add_friend_apply(pack_t);
                break;
            case DEL_FRIEND_APPLY:
                Del_friend_apply(pack_t);
                break;
            /*case QUERY_FRIEND_APPLY:
                Query_friend_apply(pack_t);
                break;*/
            //一起实现
            case VIEW_FRIEND_LIST_APPLY:
                View_friend_list_apply(pack_t);
                break;
            case SHOW_FRIEND_STATUS_APPLY:
                Show_friend_status_apply(pack_t);
                break;
            case VIEW_CHAT_HISTORY:
                
                break;
            case SHIELD_APPLY:
                Shield_friend_apply(pack_t);
                break;
            case UNSHIELD_APPLY:
                Unshield_friend_apply(pack_t);
            case GROUP_CHAT:
                flag=pack_t.data.message[0];
            case CREAT_GROUP_APPLY:
                Create_group_apply(pack_t);
                break;
            case ADD_GROUP_APPLY:
                Add_group_apply(pack_t);
                break;
            case DEL_GROUP_APPLY:
                Del_group_apply(pack_t);
                break;
            case WITHDRAW_GROUP_APPLY:
                Withdraw_group_apply(pack_t);
                break;
            case KICK_APPLY:
                Kick_apply(pack_t);
                break;
            case SET_GROUP_ADMIN_APPLY:
                Set_group_admin_apply(pack_t);
                break;
            case VIEW_ADD_GROUP_APPLY:
                View_add_group_apply(pack_t);
                break;
            case VIEW_GROUP_MEMBER_APPLY:
               View_group_member_apply(pack_t);
               break;
            case VIEW_GROUP_RECORD:
                flag=pack_t.data.message[0];
            case SEND_FILE:
                flag=pack_t.data.message[0];  
        }
        pthread_mutex_unlock(&mutex);
    }
}
void Turn_worker_thread()
{
    pthread_t pid_recv;
    pthread_create(&pid_recv,NULL,Recv_pack,NULL);
}

void Register()
{
    int flag=REGISTER;
    char password[MAX];
    char name[MAX];

    PACK recv_register;
    int recv_register_flag;

    printf("账号:");
    scanf("%s",name);
    printf("密码:");
    scanf("%s",password);

    Send_pack_message(flag,name,"server",password);


    if(recv(cfd,&recv_register,sizeof(PACK),0)==-1)
    {
        my_err("recv error",__LINE__);
    }
    recv_register_flag=recv_register.data.message[0];

    if(recv_register_flag)
        printf("注册成功!\n");
    else
    {
        printf("该账号已存在!\n");
    }
}
void Login()
{
    int flag=LOGIN;
    char name[MAX];
    char password[MAX];

    printf("请输入账号:\n");
    scanf("%s",name);
    printf("请输入密码:\n");
    scanf("%s",password);

    PACK recv_login;
    int login_flag;

    Send_pack_message(flag,name,"server",password);

    if(recv(cfd,&recv_login,sizeof(PACK),0)<0)
    {
        my_err("recv error",__LINE__);
    }
    login_flag=recv_login.data.message[0];

    if(login_flag==1)
    {
        printf("登录成功!\n");
        strcpy(user.username,name);
    }
    if(login_flag==2)
    {
        printf("账号不存在!\n");
    }
    if(login_flag==3)
    {
        printf("账号已经登录!\n");
    }
    if(login_flag==0)
    {
        printf("密码不正确!\n");
    }
}

void Login_menu()
{
    int choice=1;
    while(choice)
    {
        printf("\t\t\033[44;34m\033[44;37m**************************\033[0m\n");
        printf("\t\t\033[1;34m*        1.注册          \033[1;34m*\033[0m \n");
        printf("\t\t\033[1;34m*        2.登录          \033[1;34m*\033[0m \n");
        printf("\t\t\033[1;34m*        0.退出          \033[1;34m*\033[0m \n");
        printf("\t\t\033[44;34m\033[44;37m**************************\033[0m\n");
        printf("\t\tchoice：");
        scanf("%d",&choice);
        Clear_buffer();
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
            case 0:
                break;
        }
    }
    return ;
}
void Add_friend_apply(PACK recv_pack)
{
    int flag_add;
    char choice;
    flag_add=recv_pack.data.message[0];
    if(flag_add==0)
    {
        printf("---[%s]想要添加你为好友!\n",recv_pack.data.send_name);
        
        printf("[1]:同意\t\t[2]:不同意\n");
        scanf("%c",&choice);
        switch (choice)
        {
            case 'y':
                Send_pack_message(ADD_FRIEND,recv_pack.data.recv_name,"server","y");
            case 'n':
                Send_pack_message(ADD_FRIEND,recv_pack.data.recv_name,"server","n");
        }
    }
    else if(flag_add==1)
    {
        printf("%s同意了%s的请求,添加成功!\n",recv_pack.data.send_name,recv_pack.data.recv_name);
        user.friend_num++;
    }
    else if(flag_add==2)
        printf("%s拒绝了%s的请求!\n",recv_pack.data.send_name,recv_pack.data.recv_name);
    else if(flag_add==3)
        printf("%s不存在!\n",recv_pack.data.send_name);
    else if(flag_add==4)
        printf("%s已经是你的好友!\n",recv_pack.data.send_name);
}
void Add_friend()
{
    int flag=ADD_FRIEND;
    char name_buf[MAX];

    display("请输入要添加的好友账号:");
    Get_string(name_buf,MAX);

    Send_pack_message(flag,user.username,name_buf,"");

    Update_friend_message();
    return;
}
void Update_friend_message()
{
    PACK friend_message;
    friend_message.flag=VIEW_FRIEND_LIST;
    strcpy(friend_message.data.send_name,friend_message.data.recv_name);
    strcpy(friend_message.data.recv_name,"server");
    memset(friend_message.data.message,0,sizeof(friend_message.data.message));
    if(send(cfd,&friend_message,sizeof(PACK),0)<0)
    {
        my_err("send error!",__LINE__);
    }

}
void Del_friend()
{
    int flag=DEL_FRIEND;
    char name_buf[MAX];

    display("请输入要删除的好友账号:");
    Get_string(name_buf,MAX);

    Send_pack_message(flag,user.username,"server",name_buf);
    Update_friend_message();

    return;
}
void Del_friend_apply(PACK recv_pack)
{
    int flag_del=recv_pack.data.message[0];
    if(flag_del==1)
    {
        printf("删除好友%s成功!",recv_pack.data.send_name);
        user.friend_num--;
    }
    else if(flag_del==0)
    {
        printf("%s不是你的好友",recv_pack.data.send_name);
    }
}
/*void Query_friend()
{
    int flag=QUERY_FRIEND;
    char name_buf[MAX];
    pthread_mutex_lock(&mutex);
    display("请输入要查询的好友账号:");
    Get_string(name_buf,MAX);

    Send_pack_message(flag,user.username,"server",name_buf);
    pthread_cond_wait(&cond,&mutex);
    pthread_mutex_unlock(&mutex);

    return;
}
void Query_friend_apply(PACK recv_pack)
{
    int flag_query;
    flag_query=recv_pack.data.message[0];
    if(flag_query==1)
    {
        printf("查询%s成功!\n",recv_pack.data.send_name);
    }
    else if(flag_query==0)
        printf("%s不是你的好友!\n",recv_pack.data.send_name);
    
    pthread_cond_signal(&cond);
}*/
void Shield_friend()
{
    int flag=SHIELD;
    char name_buf[MAX];
    pthread_mutex_lock(&mutex);
    printf("请输入要屏蔽的好友名称:");
    Get_string(name_buf,MAX);

    Send_pack_message(flag,user.username,"server",name_buf);
    pthread_cond_wait(&cond,&mutex);
    pthread_mutex_unlock(&mutex);
}
void Shield_friend_apply(PACK recv_pack)
{
    int flag_shield;
    flag_shield=recv_pack.data.message[0];
    if(flag_shield==1)
        printf("屏蔽%s成功!\n",recv_pack.data.send_name);
    else if(flag_shield==0)
        printf("%s不是你的好友!\n",recv_pack.data.send_name);
    
    pthread_cond_signal(&cond);
}
void Unshield_friend()
{
    int flag=UNSHIELD;
    char name_buf[MAX];
    pthread_mutex_lock(&mutex);
    printf("请输入要解除屏蔽的好友名称:");
    Get_string(name_buf,MAX);

    Send_pack_message(flag,user.username,"server",name_buf);
    pthread_cond_wait(&cond,&mutex);
    pthread_mutex_unlock(&mutex);
}
void Unshield_friend_apply(PACK recv_pack)
{

    int flag_unshield;
    flag_unshield=recv_pack.data.message[0];
    if(flag_unshield==1)
        printf("解除屏蔽%s成功!\n",recv_pack.data.send_name);
    else if(flag_unshield==0)
        printf("%s不是你的好友!\n",recv_pack.data.send_name);
    
    pthread_cond_signal(&cond);
}
void View_friend_list()
{
    int flag=VIEW_FRIEND_LIST;
    char buf[MAX_CHAR];
    memset(buf,0,sizeof(buf));
    memset(&relation,0,sizeof(RELATION_INFO));

    pthread_mutex_lock(&mutex);
    Send_pack_message(flag,user.username,"server","");
    pthread_cond_wait(&cond, &mutex);

    printf("\n\t\t\033[0;34m**********好友列表*********\033[0m\n");
    if(relation.friend_num==0)
        printf("\t暂无好友!,请先添加\n");
    else
    {
        for(int i=0;i<relation.friend_num;i++)
        {
            switch (relation.friend_relation[i])
            {
                case BLACK:
                    printf("[%s]----[%d]\n",relation.friend_message[i],relation.friend_relation[i]);
                    break;
                
                case UNBLACK:
                    printf("[%s]----[%d]\n",relation.friend_message[i],relation.friend_relation[i]);
            }
        }
    }
    pthread_mutex_unlock(&mutex);

    /*for(int i=0;i<=user.friend_num;i++)
        {
            if(user.friend_status[i]==1)
            {
               printf("\t\t\033[1;32m联系人:%s  (在线)\033[0m\n",user.friends[i].name);
               if(user.friends[i].message_num)
                    printf("\t\t\033[1;32m未回复的消息数:%d  \033[0m\n",user.friends[i].message_num);
                else
                {
                    printf("\t\t\033[1;32m暂未消息  \033[0m\n");
                }
            }
            else if(user.friends[i].statue==2)
            {
                printf("\t\t\033[1;32m联系人:%s  (已下线)\033[0m\n",user.friends[i].name);
                if(user.friends[i].message_num)
                    printf("\t\t\033[1;32m未回复的消息数:%d  \033[0m\n",user.friends[i].message_num);
                else
                {
                    printf("\t\t\033[1;32m暂未消息  \033[0m\n");
                }
            }
            
        }*/
}
void View_friend_list_apply(PACK recv_pack)
{
    memcpy(&relation,&recv_pack.relation,sizeof(RELATION_INFO));
    pthread_cond_signal(&cond);
}
void Show_friend_status()
{
    int flag=SHOW_FRIEND_STATUS;
    char name_buf[MAX];
    pthread_mutex_lock(&mutex);
    printf("请输入要查看好友状态的名称:");
    Get_string(name_buf,MAX);

    Send_pack_message(flag,user.username,"server",name_buf);
    pthread_cond_wait(&cond,&mutex);
    pthread_mutex_unlock(&mutex);
}
void Show_friend_status_apply(PACK recv_pack)
{
    int flag_status;
    char message[50];
    flag_status=recv_pack.data.message[0];
    if(flag_status==0)
    {
        strcpy(message,recv_pack.data.message[1]);
        if(strcmp(message,"D")==0)
        {
            printf("[%s] 状态:[%d]",recv_pack.data.send_name,DOWNLINE);
        }
    }
    else if(flag_status==1)
    {
        strcpy(message,recv_pack.data.message[1]);
        if(strcmp(message,"O")==0)
        {
            printf("[%s] 状态:[%d]",recv_pack.data.send_name,ONLINE);
        }
    }
    pthread_cond_signal(&cond);
}
void Private_chat()
{
    char name_buf[BUFSIZ];
    message msg;
    FILE* fp;
    char username_buf[15];
    memset(&msg,0,sizeof(message));
    memset(name_buf,0,BUFSIZ);
    memcpy(msg.from,username_buf,15);
    printf("请输入想私聊的好友账号:");
    Get_string(username_buf,15);
    printf("[---------------]正在加载");
    sleep(1);
    system("clear");
    printf("[---------------]正在与%s聊天(quit退出)\n",username_buf);
    while(1)
    {
        memcpy(name_buf,&msg,sizeof(message));
        if(send(cfd,name_buf,BUFSIZ,0)!=BUFSIZ)
        {
            my_err("send error!",__LINE__);
        }
        return ;
    }
}
void Friend_menu()
{
    int choice=1;
    system("clear");
    
    while(choice)
    {
        printf("\t\t\033[;36m\033[1m*********朋友管理*********\033[0m\n");
        printf("\t\t\033[1;36m|\033[0m--------1.添加好友-------\033[1;36m|\033[0m\n");
        printf("\t\t\033[1;36m|\033[0m--------2.删除好友-------\033[1;36m|\033[0m\n");
        printf("\t\t\033[1;36m|\033[0m--------3.查询好友-------\033[1;36m|\033[0m\n");
        printf("\t\t\033[1;36m|\033[0m--------4.私聊好友-------\033[1;36m|\033[0m\n");
        printf("\t\t\033[1;36m|\033[0m--------5.屏蔽好友-------\033[1;36m|\033[0m\n");
        printf("\t\t\033[1;36m|\033[0m------6.解除屏蔽好友-----\033[1;36m|\033[0m\n");
        printf("\t\t\033[1;36m|\033[0m------7.查看好友列表-----\033[1;36m|\033[0m\n");
        printf("\t\t\033[1;36m|\033[0m------8.显示好友状态-----\033[1;36m|\033[0m\n");
        printf("\t\t\033[1;36m|\033[0m------9.查看聊天记录-----\033[1;36m|\033[0m\n");
        printf("\t\t\033[1;36m|\033[0m-------- 0.退出 ---------\033[1;36m|\033[0m\n");
  
        printf("请输入选择:");
        scanf("%d",&choice);
        Clear_buffer();
        switch (choice)
        {
            case 1:
                Add_friend();
                break;
            case 2:
                Del_friend();
                break;
            case 3:
                //Query_friend();
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
                Show_friend_status();
                break;
            case 9:
                View_chat_history();
                break;
            case 0:
                break;
        }
    }
    return;
}


void Create_group()
{
    int flag=CREAT_GROUP;
    char name_buf[MAX];
    pthread_mutex_lock(&mutex);
    printf("请输入要创建的群名称:");
    Get_string(name_buf,MAX);

    Send_pack_message(flag,user.username,"server",name_buf);
    pthread_cond_wait(&cond, &mutex);
    pthread_mutex_unlock(&mutex);
}
void Create_group_apply(PACK recv_pack)
{
    int flag_create;
    flag_create=recv_pack.data.message[0];
    if(flag_create==0)
        printf("群%s已存在\n",recv_pack.data.send_name);
    else if(flag_create==1)
        printf("群%s成功建立\n",recv_pack.data.send_name);
    pthread_cond_signal(&cond);
}
void Add_group()
{
    int flag=ADD_GROUP;
    char name_buf[MAX];

    printf("请输入想要加入的群名称:");
    Get_string(name_buf,MAX);

    Send_pack_message(flag,user.username,"server",name_buf);
}
void Add_group_apply(PACK recv_pack)
{
    int flag_add;
    char choice;
    flag_add=recv_pack.data.message[0];
    if(flag_add==0)
    {
        printf("群%s不存在\n",recv_pack.message);
    }
    else if(flag_add==1)
    {
        printf("---[%s]想要加入群聊%s!\n",recv_pack.data.send_name,recv_pack.message);
        
        printf("[1]:同意\t\t[2]:不同意\n");
        scanf("%c",&choice);
        switch (choice)
        {
            case 'y':
                Send_pack_message(ADD_FRIEND,recv_pack.data.recv_name,recv_pack.data.send_name,choice);
            case 'n':
                Send_pack_message(ADD_FRIEND,recv_pack.data.recv_name,recv_pack.data.send_name,choice);
        }
    }
    else if(flag_add==2)
    {
        printf("%s同意了%s的请求,添加成功!\n",recv_pack.data.recv_name,recv_pack.data.send_name);
        user.member_num++;
    }
    else if(flag_add==3)
        printf("%s拒绝了%s的请求!\n",recv_pack.data.recv_name,recv_pack.data.send_name);
}

void Withdraw_group()
{
    int flag=WITHDRAW_GROUP;
    char name_buf[MAX];
    pthread_mutex_lock(&mutex);
    printf("请输入想要退出的群名称:");
    Get_string(name_buf,MAX);

    Send_pack_message(flag,user.username,"server",name_buf);
    pthread_cond_wait(&cond, &mutex);
    pthread_mutex_unlock(&mutex);
}
void Withdraw_group_apply(PACK recv_pack)
{
    int flag_withdraw;
    flag_withdraw=recv_pack.data.message[0];
    if(flag_withdraw==0)
    {
        printf("群%s不存在\n",recv_pack.message);
    }
    else if(flag_withdraw==1)
    {
        printf("%s退群%s成功\n",recv_pack.data.recv_name,recv_pack.message);
    }
    pthread_cond_signal(&cond);
}
void View_add_group()
{
    int flag=VIEW_ADD_GROUP;
    char buf[MAX_CHAR];
    memset(&group,0,sizeof(GROUP_INFO));

    pthread_mutex_lock(&mutex);
    Send_pack_message(flag,user.username,"server","");
    pthread_cond_wait(&cond, &mutex);

    printf("\n\t\t\033[0;34m**********群组列表*********\033[0m\n");
    if(group.group_num==0)
        printf("\t\t暂无群组!,请先添加\n");
    else
    {
        for(int i=0;i<group.group_num;i++)
        {       
            printf("\t\t\033[1;32m群组名称:%s  \033[0m\n",group.group_message[i]);
        }
    }
    pthread_mutex_unlock(&mutex);



    /*else
    {
        for(int i=0;i<user.group_num;i++)
        {       
            printf("\t\t\033[1;32m群组名称:%s  \033[0m\n",user.group[i].name);
        }
    }
    pthread_mutex_unlock(&mutex);*/
}
void View_add_group_apply(PACK recv_pack)
{
    memcpy(&group,&recv_pack.group,sizeof(GROUP_INFO));
    pthread_cond_signal(&cond);
}
void View_group_member()
{
    
}
void View_group_member_apply(PACK recv_pack)
{

}
void View_group_record()
{

}
void Group_chat()
{

}
void Group_menu()
{
    int choice=1;
    while(choice)
    {
        printf("\t\t\033[;34m\033[1m*********群管理*********\033[0m\n");
        printf("\t\t\033[1;34m|\033[0m--------1.创建群-------\033[1;34m|\033[0m\n");
        printf("\t\t\033[1;34m|\033[0m--------2.添加群-------\033[1;34m|\033[0m\n");
        printf("\t\t\033[1;34m|\033[0m--------3.退群---------\033[1;34m|\033[0m\n");
        printf("\t\t\033[1;34m|\033[0m--------4.群聊---------\033[1;34m|\033[0m\n");
        printf("\t\t\033[1;34m|\033[0m--------5.已加群-------\033[1;34m|\033[0m\n");
        printf("\t\t\033[1;34m|\033[0m--------6.群成员-------\033[1;34m|\033[0m\n");
        printf("\t\t\033[1;34m|\033[0m-----7.查看聊天记录----\033[1;34m|\033[0m\n");
        printf("\t\t\033[1;34m|\033[0m------8.群管理权限-----\033[1;34m|\033[0m\n");
        printf("\t\t\033[1;34m|\033[0m-------- 0.退出--------\033[1;34m|\033[0m\n");
        printf("请输入选择:");
        scanf("%d",&choice);
        Clear_buffer();
        switch (choice)
        {
            case 1:
                Create_group();
                break;
            case 2:
                Add_group();
                break;
            case 3:
                Withdraw_group();
                break;
            case 4:
                Group_chat();
                break;
            case 5:
                View_add_group();
                break;
            case 6:
                View_group_member();
                break;
            case 7:
                View_group_record();
                break;
            case 8:
                Group_leader_menu();
                break;
            case 0:
                break;
        }
    }
    return;
}

void Del_group()
{
    int flag=DEL_GROUP;
    char name_buf[MAX];
    pthread_mutex_lock(&mutex);

    printf("请输入想要解散的群名称:");
    Get_string(name_buf,MAX);

    Send_pack_message(flag,user.username,"server",name_buf);
    pthread_cond_wait(&cond, &mutex);
    pthread_mutex_unlock(&mutex);
}
void Del_group_apply(PACK recv_pack)
{
    int flag_del;
    flag_del=recv_pack.data.message[0];
    if(flag_del==0)
    {
        printf("群%s不存在\n",recv_pack.data.send_name);
    }
    else if(flag_del==1)
    {
        printf("群主%s解散了群%s成功!\n",recv_pack.data.recv_name,recv_pack.data.send_name);
    }
    else if(flag_del==2)
    {
        printf("只有群主%s才能解散群\n",recv_pack.data.recv_name);
    }
    pthread_cond_signal(&cond);
}
void Set_group_admin()
{
    int flag=SET_GROUP_ADMIN;
    char group_name_buf[MAX];
    char admin_buf[MAX];
    pthread_mutex_lock(&mutex);
    printf("请输入设置某个群里的管理员:");
    Get_string(group_name_buf,MAX);

    Get_string(admin_buf,MAX);
   

    Send_pack_message(flag,user.username,group_name_buf,admin_buf);
    pthread_cond_wait(&cond, &mutex);
    pthread_mutex_unlock(&mutex);
}
void Set_group_admin_apply(PACK recv_pack)
{
    int flag_set;
    flag_set=recv_pack.data.message[0];
    if(flag_set==0)
    {
        printf("群%s不存在\n",recv_pack.data.send_name);
    }
    else if(flag_set==1)
    {
        printf("设置群成员%s为群%s管理员成功\n",recv_pack.message,recv_pack.data.send_name);
    }
    else if(flag_set==2)
    {
        printf("只有群主%s可以设置群%s管理员\n",recv_pack.data.recv_name,recv_pack.data.send_name);
    }
    else if(flag_set==3)
    {
        printf("群成员%s不在群%s中\n",recv_pack.message,recv_pack.data.send_name);
    }
    else if(flag_set==4)
    {
        printf("您%s已经被设置为群%s的管理员\n",recv_pack.message,recv_pack.data.send_name);
    }
}
void Kick()
{
    int flag=KICK;
    char group_name_buf[MAX];
    char staff_buf[MAX];
    pthread_mutex_lock(&mutex);
    printf("请输入踢出某个群里的人员:");
    Get_string(group_name_buf,MAX);

    Get_string(staff_buf,MAX);
   

    Send_pack_message(flag,user.username,group_name_buf,staff_buf);
    pthread_cond_wait(&cond, &mutex);
    pthread_mutex_unlock(&mutex);

}
void Kick_apply(PACK recv_pack)
{
    int flag_kick;
    flag_kick=recv_pack.data.message[0];
    if(flag_kick==0)
    {
        printf("群%s不存在\n",recv_pack.data.send_name);
    }
    else if(flag_kick==1)
    {
        printf("群%s踢出%s成功\n",recv_pack.data.send_name,recv_pack.message);
    }
    else if(flag_kick==2)
    {
        printf("只有群主%s或者管理员才能踢人\n",recv_pack.data.recv_name);
    }
    else if(flag_kick==3)
    {
        printf("该成员%s不在群中\n",recv_pack.message);
    }
    else if(flag_kick==4)
    {
        printf("你不是该群%s成员，无法踢人\n",recv_pack.data.send_name);
    }
    else if(flag_kick==5)
    {
        printf("你%s被踢出了群聊%s",recv_pack.message,recv_pack.data.send_name);
    }
    pthread_cond_signal(&cond);
}
void Group_leader_menu()
{
    int choice=1;
    system("clear");
    while(choice)
    {
        printf("\t\t\033[;33m\033[1;37m**************************\033[0m\n");
        printf("\n\t\t\033[1;31m    群主--1,2,3/管理员--3权限     \033[0m\n");
        printf("\t\t\033[1;31m         1.解散群  \033[0m\n");
        printf("\t\t\033[1;31m         2.设置管理员\033[0m\n");
        printf("\t\t\033[1;31m         3.踢人  \033[0m\n");
        printf("\t\t\033[1;31m         0.返回  \033[0m\n");
        printf("请输入选择:");
        scanf("%d",&choice);
        Clear_buffer();
        switch (choice)
        {
            case 1:
                Del_group();
                break;
            case 2:
                Set_group_admin();
                break;
            case 3:
                Kick();
                break;
            case 0:
                break;
        }
    }
}

void Send_file()
{
    int flag=SEND_FILE;
    

}
void Menu()
{
    int choice=1;
    while(choice)
    {
        
        printf("\t\t\033[1;34m**************************\033[0m\n");
        printf("\t\t\033[1;34m|        1.好友管理      \033[1;34m|\033[0m \n");
        printf("\t\t\033[1;34m|        2.群管理        \033[1;34m|\033[0m \n");
        printf("\t\t\033[1;34m|        3.发送文件      \033[1;34m|\033[0m \n");
        printf("\t\t\033[1;34m|        5.离线传输      \033[1;34m|\033[0m \n");
        printf("\t\t\033[1;34m|        0.退出          \033[1;34m|\033[0m \n");
        printf("\t\t\033[1;34m**************************\033[0m\n");
        printf("\t\tchoice:");
        scanf("%d",&choice);

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
            case 4:
                Offline_transmission();
                break;
            case 0:
                break;
        }
    }

}