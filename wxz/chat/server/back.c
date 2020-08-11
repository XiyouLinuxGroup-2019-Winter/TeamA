#include "final.h"
#define EPOLLEVENT 1024
int sys_log;
MYSQL mysql;
int main()
{

    //初始化链表list。链表为带头结点的双向循环链表
    List_Init(list_ser,server_user_node_t);
    List_Init(group_ser,group_node_t);


    if((sys_log=open("sys_log",O_WRONLY | O_CREAT | O_APPEND,S_IRUSR|S_IWUSR))<0)
    {
        sys_err("open error",__LINE__);
        return 0;
    }
    dup2(sys_log,1);

    
    signal(SIGINT,Signal_close);

    pthread_mutex_init(&mutex,NULL);
    pthread_cond_init(&cond,NULL);

    printf("线程池启动\n");
    pool_init(MAX_THREAD_NUM);
    printf("线程池启动成功!\n");
    sleep(2);

    //Read_from_mysql();
    Init_socket();

    Connect_mysql();


    threadpool_destroy();

}
void Signal_close(int i)
{
    close(sys_log);
    Close_mysql(mysql);
    printf("服务器关闭\n");
    exit(1);
}
void Init_socket()
{
  
    PACK recv_t;
    printf("服务端启动\n");
    struct sockaddr_in serv_addr;
    struct sockaddr_in cli_addr;

    socklen_t cli_addr_len;

    lfd=Socket(AF_INET,SOCK_STREAM,0);

    //端口复用
    int opt=1;
    setsockopt(lfd,SOL_SOCKET,SO_REUSEADDR,(void*)&opt,sizeof(opt));

    bzero(&serv_addr,sizeof(serv_addr));

    serv_addr.sin_family=AF_INET;
    serv_addr.sin_port=htons(SERV_PORT);
    serv_addr.sin_addr.s_addr=htonl(INADDR_ANY);

    Bind(lfd,(struct sockaddr*)&serv_addr,sizeof(serv_addr));
    Listen(lfd,128);

    printf("服务器启动成功!\n");

    epfd=epoll_create(EPOLLEVENT);
    struct epoll_event tep,ep[EPOLLEVENT];
    tep.events=EPOLLIN;
    tep.data.fd=lfd;
    epoll_ctl(epfd,EPOLL_CTL_ADD,lfd,&tep);

    int i;
    int ret;
    while(1)
    {
        ret=epoll_wait(epfd,ep,EPOLLEVENT,-1);
        for(i=0;i<ret;i++)
        {

            printf("the event is %x\n",ep[i].events);
            if (!(ep[i].events & EPOLLIN))      //如果不是"读"事件, 继续循环
                continue;

            if(ep[i].data.fd==lfd)
            {
                cli_addr_len=sizeof(cli_addr);
                cfd=Accept(lfd,(struct sockaddr*)&cli_addr,&cli_addr_len);
                printf("连接到新的客户端ip:%s\n端口号:%d\n",inet_ntoa(cli_addr.sin_addr),cli_addr.sin_port);
                tep.events=EPOLLIN;
                tep.data.fd=cfd;
                epoll_ctl(epfd,EPOLL_CTL_ADD,cfd,&tep);
            }
            else if(ep[i].events & EPOLLIN)
            {
                int n=recv(ep[i].data.fd,&recv_t,sizeof(PACK),MSG_WAITALL);
                recv_t.data.send_fd=ep[i].data.fd;

                
                /*if(ep[i].events & EPOLLRDHUP)
                {
                    server_list_t pos;
                    //使用指针pos依次遍历链表list_ser
                    List_ForEach(list_ser,pos)
                    {
                    
                        if(pos->data.connfd==ep[i].data.fd)
                        {
                            List_FreeNode(pos);
                            printf("%s downline\n",pos->data.username);
                            break;
                        }
                    }
                    tep.data.fd=ep[i].data.fd;
                    printf("客户端:%d连接断开\n",tep.data.fd);
                   
                    epoll_ctl(epfd,EPOLL_CTL_DEL,ep[i].data.fd,NULL);
                    //close(ep[i].data.fd);
                    continue;
                }
                else
                {
                    int n=recv(ep[i].data.fd,&recv_t,sizeof(PACK),0);
                    recv_t.data.send_fd=ep[i].data.fd;
                    //Recv_pack_message(recv_t);

                    PACK *recv_pack_t;
                    recv_pack_t=(PACK*)malloc(sizeof(PACK));
                    memcpy(recv_pack_t,&recv_t,sizeof(PACK));
                    Recv_pack_message(*recv_pack_t);

                    threadpool_add(work,(void*)recv_pack_t);
                }*/
                
                if(n<0)
                {
                    close(ep[i].data.fd);
                    sys_err("recv error!",__LINE__);
                    continue;
                }
                else if(n==0)
                {
                    server_list_t pos;
                    //使用指针pos依次遍历链表list_ser
                    List_ForEach(list_ser,pos)
                    {
                    
                        if(pos->data.connfd==ep[i].data.fd)
                        {
                            List_FreeNode(pos);
                            printf("%s downline\n",pos->data.username);
                            break;
                        }
                    }
                    tep.data.fd=ep[i].data.fd;
                    printf("客户端:%d连接断开\n",tep.data.fd);
                   
                    epoll_ctl(epfd,EPOLL_CTL_DEL,ep[i].data.fd,&tep);
                    //close(ep[i].data.fd);
                    continue;
                }


                Recv_pack_message(recv_t);

                PACK *recv_pack_t;
                recv_pack_t=(PACK*)malloc(sizeof(PACK));
                memcpy(recv_pack_t,&recv_t,sizeof(PACK));

                threadpool_add(work,(void*)recv_pack_t);

               
            }
            
        }
    }

    close(epfd);
    close(lfd);
}
void *work(void* arg)
{
    PACK* pack_t;
    pack_t=(PACK*)arg;

    switch(pack_t->flag)
    {
        case LOGIN:
            Login(pack_t);
            break;
        case REGISTER:
            Register(pack_t);
            break;
        case ADD_FRIEND:
            Add_friend(pack_t);
            break;
        case DEL_FRIEND:
            Del_friend(pack_t);
            break;
        case QUERY_FRIEND:
            //Query_friend(pack_t);
            break;
        case PRIVATE_CHAT:
            Private_chat(pack_t);
            break;
        //写在一起比较好
        case SHOW_FRIEND_STATUS:
            Show_friend_status(pack_t);
        case VIEW_FRIEND_LIST:
            View_friend_list(pack_t);
            break;
        case SHIELD:
            Shield_friend(pack_t);
            break;
        case UNSHIELD:
            Unshield_friend(pack_t);
            break;
        case CREAT_GROUP:
            Create_group(pack_t);
            break;
        case ADD_GROUP:
            Add_group(pack_t);
            break;
        case WITHDRAW_GROUP:
            Withdraw_group(pack_t);
            break;
        case VIEW_ADD_GROUP:
            View_add_group(pack_t);
            break;
        case VIEW_GROUP_MEMBER:
            View_group_member(pack_t);
            break;
        case DEL_GROUP:
            Del_group(pack_t);
            break;
        case SET_GROUP_ADMIN:
            Set_group_admin(pack_t);
            break;
        case KICK:
            Kick(pack_t);
            break;
        case GROUP_CHAT:
            Group_chat(pack_t);
            break;
        case SEND_FILE:
            //Send_file(pack_t);
            break;
        case VIEW_CHAT_HISTORY:
        case VIEW_GROUP_RECORD:
            Send_record(pack_t);
            break;
        case 0:
            break;
    }
    return NULL;
}
void Register(PACK* pack_t)
{
    char register_flag[10];
    int flag=REGISTER;
    char buf[BUFSIZ];

    server_list_t pos;
    for(pos=list_ser->next;pos!=list_ser;pos=pos->next)
    {
        if(strcmp(pos->data.username,pack_t->data.send_name)==0)
        {
            printf("pos:%s\n%s\n",pos->data.username,pos->data.password);
            flag=1;
            break;
        }
    }

    server_user_node_t *new;
    new=(server_user_node_t*)malloc(sizeof(server_user_node_t));

    if(flag==0)
    {
        strcpy(new->data.username,pack_t->data.send_name);
        strcpy(new->data.password,pack_t->data.message);
        new->data.online=DOWNLINE;
        new->data.friend_num=0;
        new->data.group_num=0;
        
        //链表尾插法，list为头指针，new为新节点
        List_AddTail(list_ser,new);
        user_num++;


        memset(buf,0,sizeof(buf));
        sprintf(buf,"insert into account values('%s','%s','%d')",pack_t->data.send_name,pack_t->data.message,pos->data.online);
        mysql_real_query(&mysql,buf,strlen(buf));
        register_flag[0]='1';
    }
    else
    {
        register_flag[0]='0';
    }
    register_flag[1]='\0';

    Send_pack_type(pack_t->data.send_fd,flag,pack_t,register_flag);
    free(pack_t);
}
//登录
void Login(PACK* pack_t)
{
    char login_flag[10];
    int ret;
    int flag=LOGIN;
    
    
    server_list_t pos;
    for(pos=list_ser->next;pos!=list_ser;pos=pos->next)
    {
        if((strcmp(pos->data.username,pack_t->data.send_name)==0)&&(strcmp(pos->data.password,pack_t->data.message)==0))
        {
            printf("pos:%s\n%s\n",pos->data.username,pos->data.password);
            flag=1;
            
            break;
        }
    }

    
    //没有注册
    if(flag==0)
        login_flag[0]='2';
    else
    {
        //账号已经登录
        if(pos->data.online==ONLINE)
            login_flag[0]='3';
        else if(pos->data.online==DOWNLINE)
        {
            //登录成功
            login_flag[0]='1';
            pos->data.online=ONLINE;
            pos->data.connfd=pack_t->data.send_fd;
        }
        /*
        else
        {
            //密码错误
            login_flag[0]='0';
        }*/
    }
    login_flag[1]='\0';

    Send_pack_type(pack_t->data.send_fd,flag,pack_t,login_flag);
    
    free(pack_t);
}

void Add_friend(PACK* pack_t)
{

    int flag=ADD_FRIEND_APPLY;
    char buf[MAX_CHAR];
    int flag_t;
    int flag_tt;
    friend_list_t pos;

    char flag_add[10];
    
    for(pos=friend_ser->next;pos!=friend_ser;pos=pos->next)
    {
        if((strcmp(pos->data.username,pack_t->data.send_name)==0)&&(strcmp(pos->data.friend_name,pack_t->data.recv_name)==0))
        {
            printf("pos:%s\n%s\n",pos->data.username,pos->data.friend_name);
            flag_t=1;
        }
    }


    if(flag_t==0)
    {
        
        server_list_t pos_friend;
    
        for(pos_friend=list_ser->next;pos_friend!=list_ser;pos_friend=pos_friend->next)
        {
            if((strcmp(pos_friend->data.username,pack_t->data.recv_name)==0))
            {
                printf("pos_friend:%s\n,password:%s\n",pos_friend->data.username,pos_friend->data.password);
                flag_tt=1;      
            }
        }
        //好友不存在
        if(flag_tt==0)
        {
            flag_add[0]='3';
            flag_add[1]='\0';
            Send_pack_type(pack_t->data.send_fd,flag,pack_t,flag_add);
            return ;
        }
        else
        {
            if(pack_t->data.message[0]=='0')
            {
                flag=ADD_FRIEND_APPLY;
                flag_add[0]='0';

                flag_add[1]='\0';
                //更改接受者名字
                char recv_name_t[MAX];
                strcpy(recv_name_t,pack_t->data.recv_name);
                strcpy(pack_t->data.recv_name,pack_t->data.send_name);
                strcpy(pack_t->data.send_name,recv_name_t);
                Send_pack_type(pos_friend->data.connfd,flag,pack_t,flag_add);
            }
            else if(pack_t->data.message[0]=='y')
            {
                friend_node_t *new=(friend_node_t*)malloc(sizeof(friend_node_t));

                flag_add[0]='1';
                strcpy(new->data.username,pack_t->data.recv_name);
                strcpy(new->data.friend_name,pack_t->data.send_name);
                new->data.status=1;//朋友

                pos_friend->data.friend_num++;

                List_AddTail(friend_ser,new);

                memset(buf,0,sizeof(buf));
                sprintf(buf,"insert into friend values('%s','%s','%d')",pack_t->data.recv_name,pack_t->data.send_name,1);
                mysql_real_query(&mysql,buf,strlen(buf));
                
                char recv_name_t[MAX];
                strcpy(recv_name_t,pack_t->data.recv_name);
                strcpy(pack_t->data.recv_name,pack_t->data.send_name);
                strcpy(pack_t->data.send_name,recv_name_t);
                Send_pack_type(pos_friend->data.connfd,flag,pack_t,flag_add);

            }
            else if(pack_t->data.message[0]=='n')
            {
                flag_add[0]='2';
                char recv_name_t[MAX];
                strcpy(recv_name_t,pack_t->data.recv_name);
                strcpy(pack_t->data.recv_name,pack_t->data.send_name);
                strcpy(pack_t->data.send_name,recv_name_t);
                Send_pack_type(pos_friend->data.connfd,flag,pack_t,flag_add);
            }
        }
    }
    //已经为好友
    else if(flag_t==1)
    {
        flag_add[0]='4';
        Send_pack_type(pack_t->data.send_fd,flag,pack_t,flag_add);
        return ;
    }
    /*se_pos_friendrver_list_t pos;
    server_list_t pos_friend;
    pos=Find_server_user(pack_t->data.send_name);
    pos_friend=Find_server_user(pack_t->data.message);

    strcpy(pos->data.friend_message[ (pos->data.friend_num) ++],pack_t->data.message);
    //strcpy(pos->data.friend_message[ (pos->data.friend_num) ++],pos_friend->data.username);
    strcpy(pos_friend->data.friend_message[ (pos_friend->data.friend_num) ++],pack_t->data.send_name);
    //strcpy(pos_friend->data.friend_message[ (pos_friend->data.friend_num) ++],pos->data.username);
    
    free(pack_t);*/
    
}

void Del_friend(PACK* pack_t)
{
    char buf[BUFSIZ];
    int flag=DEL_FRIEND_APPLY;
    char flag_del[10];
    int flag_t;

    friend_list_t pos;

    for(pos=friend_ser->next;pos!=friend_ser;pos=pos->next)
    {
        if((strcmp(pos->data.username,pack_t->data.send_name)==0)&&(strcmp(pos->data.friend_name,pack_t->data.message)==0))
        {
            printf("pos:%s\n%s\n",pos->data.username,pos->data.friend_name);
            flag_t=1;
        }
    }

    server_list_t pos_user;
    pos_user=Find_server_user(pack_t->data.send_name);
    if(pos_user)
    {
        if(flag_t==1)
        {
        
                //从链表中删除并释放结点node    //从链表中删除并释放结点node
                List_FreeNode(pos);

                memset(buf,0,sizeof(buf));
                sprintf(buf,"delete from friend where username='%s' and friend_name='%s'",pack_t->data.send_name,pack_t->data.message);
                mysql_real_query(&mysql,buf,strlen(buf));
                flag_del[0]='1';
                Send_pack_type_name(pack_t->data.send_fd,flag,pack_t,flag_del);
                pos_user->data.friend_num--; 
                memset(buf,0,sizeof(buf));
                sprintf(buf,"delete from friend where username='%s' and friend_name='%s'",pack_t->data.send_name,pack_t->data.message);
                mysql_real_query(&mysql,buf,strlen(buf));
                flag_del[0]='1';
                Send_pack_type_name(pack_t->data.send_fd,flag,pack_t,flag_del);
            
            
        }
    }
    else if(pos_user==NULL || flag_t==0)
    {
        flag_del[0]='0';
        Send_pack_type_name(pack_t->data.send_fd,flag,pack_t,flag_del);
    }
    


    /*server_list_t pos;
    server_list_t pos_friend;

    pos=Find_server_user(pack_t->data.send_name);
    Find_del_server_user(pos,pack_t->data.message);

    pos_friend=Find_server_user(pack_t->data.message);
    Find_del_server_user(pos_friend,pack_t->data.send_name);

    free(pack_t);*/
}
/*void Query_friend(PACK* pack_t)
{
    char buf[MAX];
    int flag=QUERY_FRIEND_APPLY;
    char flag_query[10];

    int flag_t;
    friend_list_t pos;
    for(pos=friend_ser->next;pos!=friend_ser;pos=pos->next)
    {
        if((strcmp(pos->data.username,pack_t->data.send_name)==0)&&(strcmp(pos->data.friend_name,pack_t->data.message)==0)) 
        {
            flag_t=1;
            break;
        }
    }
    if(flag_t==0)
    {
        flag_query[0]='0';
        Send_pack_type_name(pack_t->data.send_fd,flag,pack_t,flag_query);
    }
    else
    {
        
        memset(buf,0,sizeof(buf));
        sprintf(buf,"select *from friend where username='%s' and friend_name='%s'",pack_t->data.send_name,pack_t->data.message);
        int ret=mysql_real_query(&mysql,buf,strlen(buf));
        if(ret)
        {
            Mysql_with_error(&mysql);
        }
        
        flag_query[0]='1';
        flag_query[1]='\0';

        Send_pack_type_name(pack_t->data.send_fd,flag,pack_t,flag_query);
    
    }

}*/
void Private_chat(PACK* pack_t)
{
    Mysql_save_message(pack_t,VIEW_CHAT_HISTORY);
    Send_pack(pack_t);
    free(pack_t);
}


void Group_chat(PACK* pack_t)
{
    group_list_t pos;
    pos=Find_server_group(pack_t->data.recv_name);
    char send_name[SAVE];

    int i;
    int len=strlen(pack_t->data.message);
    for(i=len;i>=0;i--)
    {
        pack_t->data.message[i+SAVE]=pack_t->data.message[i];
    }
    //把客户端消息copy
    strcpy(send_name,pack_t->data.send_name);

    for(i=0;i<SAVE;i++)
    {
        pack_t->data.message[i]=pack_t->data.send_name[i];
    }
    strcpy(pack_t->data.send_name,pack_t->data.recv_name);

    for(i=1;i<=pos->data.member_num;i++)
    {
        strcpy(pack_t->data.recv_name,pos->data.member_name[i]);
        if(strcmp(send_name,pos->data.member_name[i])!=0)
        {
            Mysql_save_message(pack_t,VIEW_GROUP_RECORD);

            Send_pack(pack_t);
        }
    }
    free(pack_t);

}


void Shield_friend(PACK* pack_t)
{
    char buf[BUFSIZ];
    int flag=SHIELD_APPLY;
    char flag_shield[10];

    int flag_t;
    friend_list_t pos;
    
    for(pos=friend_ser->next;pos!=friend_ser;pos=pos->next)
    {
        if((strcmp(pos->data.username,pack_t->data.send_name)==0)&&(strcmp(pos->data.friend_name,pack_t->data.message)==0)) 
        {
            flag_t=1;
            break;
        }
    }

    if(flag_t==0)
    {
        flag_shield[0]='0';
        Send_pack_type_name(pack_t->data.send_fd,flag,pack_t,flag_shield);
    }
    else
    {
        pos->data.relation=BLACK;//屏蔽好友
        memset(buf,0,sizeof(buf));
        sprintf(buf,"update friend set status=%d where username='%s' and friend_name='%s'",pos->data.status,pack_t->data.send_name,pack_t->data.message);
        mysql_real_query(&mysql,buf,strlen(buf));

        flag_shield[0]='1';
        flag_shield[1]='\0';

        Send_pack_type_name(pack_t->data.send_fd,flag,pack_t,flag_shield);
    }
}
void Unshield_friend(PACK* pack_t)
{
    char buf[BUFSIZ];
    int flag=UNSHIELD_APPLY;
    char flag_unshield[10];

    int flag_t;
    friend_list_t pos;
    
    for(pos=friend_ser->next;pos!=friend_ser;pos=pos->next)
    {
        if((strcmp(pos->data.username,pack_t->data.send_name)==0)&&(strcmp(pos->data.friend_name,pack_t->data.message)==0)) 
        {
            flag_t=1;
            break;
        }
    }

    if(flag_t==0)
    {
        flag_unshield[0]='0';
        Send_pack_type_name(pack_t->data.send_fd,flag,pack_t,flag_unshield);
    }
    else
    {
        pos->data.relation=UNBLACK;//解除屏蔽
        memset(buf,0,sizeof(buf));
        sprintf(buf,"update friend set status=%d where username='%s' and friend_name='%s'",pos->data.status,pack_t->data.send_name,pack_t->data.message);
        mysql_real_query(&mysql,buf,strlen(buf));

        flag_unshield[0]='1';
        flag_unshield[1]='\0';

        Send_pack_type_name(pack_t->data.send_fd,flag,pack_t,flag_unshield);
    }
}
//一起实现
void View_friend_list(PACK* pack_t)
{
    int flag=VIEW_FRIEND_LIST;
    MYSQL_RES* result;
    MYSQL_ROW row;
    char buf[MAX_CHAR];

    int rows;
    memset(buf,0,sizeof(buf));
    sprintf(buf,"select *from friend where username='%s' or friend_name='%s'",pack_t->data.send_name,pack_t->data.send_name);
    mysql_real_query(&mysql,buf,strlen(buf));

    result=mysql_store_result(&mysql);
    rows=mysql_num_rows(result);
    
    int i;
    server_list_t pos;
    pos=Find_server_user(pack_t->data.send_name);
    if(rows==0)
        pack_t->relation.friend_num=0;
    else
    {
        i=0;
        while((row=mysql_fetch_row(result)))
        {
            if(strcmp(row[0],pack_t->data.send_name)==0)
            {
                strcpy(pack_t->relation.friend_message[i],row[1]);
                pack_t->relation.friend_relation[i]=row[2][0];
                i++;
            }
            else if(strcmp(row[1],pack_t->data.send_name)==0)
            {
                strcpy(pack_t->relation.friend_message[i],row[0]);
                pack_t->relation.friend_relation[i]=row[2][0];
                i++;
            }
        }
        pack_t->relation.friend_num=i;
    }
    Send_pack_type(pack_t->data.send_fd,flag,pack_t,"");

    /*char status[MAX_CHAR*2];
    char buf[MAX_CHAR];
    char name_t[MAX_CHAR];
    int cnt;

    memset(status,0,sizeof(status));
    server_list_t pos;
    pos=Find_server_user(pack_t->data.send_name);
    
    status[cnt++]=pos->data.friend_num;
    
    int i,j,k;
    for(i=1;i<=pos->data.friend_num;i++)
    {
        strcpy(name_t,pos->data.friend_message[i]);
        for(j=1;j<=user_num;j++)
        {
            if(strcmp(name_t,pos->data.username)==0)
            {
                memset(buf,0,sizeof(buf));
                if(pos->data.online==ONLINE)
                    sprintf(buf,"[%s]:[%d]",pos->data.username,ONLINE);
                else
                {
                    sprintf(buf,"[%s]:[%d]",pos->data.username,DOWNLINE);
                }
                printf("buf=%s\n",buf);
                for(k=0;k<SAVE;k++)
                    status[k+cnt]=buf[k];
                cnt+=SAVE;
            }
        }
    }

    strcpy(pack_t->data.recv_name,pack_t->data.send_name);
    strcpy(pack_t->data.send_name,"server");
    memcpy(pack_t->data.message,status,sizeof(status));
    pack_t->data.recv_fd=pack_t->data.send_fd;
    pack_t->data.send_fd=lfd;

    Send_pack(pack_t);
    free(pack_t);*/

}
void Show_friend_status(PACK* pack_t)
{
    int flag=SHOW_FRIEND_STATUS_APPLY;
    char flag_status[50];
    server_list_t pos;
    int flag_t;

    char message[50];
    for(pos=list_ser->next;pos!=list_ser;pos=pos->next)
    {
        if((strcmp(pos->data.username,pack_t->data.send_name)==0)) 
        {
            flag_t=1;
            break;
        }
    }

    if(pos->data.online==DOWNLINE)
    {
        flag_status[0]='0';
        strcpy(message,"DOWNLINE");
        strcpy(pack_t->message,message);
        flag_status[strlen(flag_status)+1]='\0';
        Send_pack_type_name(pack_t->data.send_fd,flag,pack_t,flag_status);
    }
    else if(pos->data.online==ONLINE)
    {
        flag_status[0]='1';
        strcpy(message,"ONLINE");
        strcpy(pack_t->message,message);
        flag_status[strlen(flag_status)+1]='\0';
        Send_pack_type_name(pack_t->data.send_fd,flag,pack_t,flag_status);
    }
}
void Create_group(PACK* pack_t)
{

    
    int flag=CREAT_GROUP_APPLY;
    char buf[BUFSIZ];
    char flag_create[10];
    int flag_t;

    group_list_t pos;

    for(pos=group_ser->next;pos!=group_ser;pos=pos->next)
    {
        if((strcmp(pos->data.group_name,pack_t->data.message)==0))
        {
            printf("group_name:%s\n",pos->data.group_name);
            flag_t=1;
        }
    }

    if(flag_t==0)
    {
        flag_create[0]='1';
        group_node_t* new;
        new=(group_node_t*)malloc(sizeof(group_node_t));
        
        strcpy(new->data.group_name,pack_t->data.message);
        strcpy(new->data.group_owner,pack_t->data.send_name);
        group_num++;
        new->data.member_num=1;
        new->data.type=OWNER;
        new->data.status[group_ser->data.member_num]=ONLINE;
        strcpy(new->data.member_name[group_ser->data.member_num],pack_t->data.send_name);
        List_AddTail(group_ser,new);
   
        memset(buf,0,sizeof(buf));
        sprintf(buf,"insert into account_group values('%s','%s')",pack_t->data.send_name,pack_t->data.message);
        mysql_real_query(&mysql,buf,strlen(buf));
        Send_pack_type_name(pack_t->data.send_fd,flag,pack_t,flag_create);
    }
    else
    {
        flag_create[0]='0';
        Send_pack_type_name(pack_t->data.send_fd,flag,pack_t,flag_create);
    }
    


    /*strcpy(pack_t->data.recv_name,pack_t->data.send_name);
    strcpy(pack_t->data.send_name,"server");
    pack_t->data.message[0]=1;
    Send_pack(pack_t);
    free(pack_t);
    return ;
    //新建群信息
    group_node_t* new;
    new=(group_node_t*)malloc(sizeof(group_node_t));
    new->data.member_num=0;
    //群名
    strcpy(new->data.group_name,pack_t->data.message);
    //群主
    strcpy(new->data.member_name[new->data.member_num],pack_t->data.send_name);
    new->data.type[new->data.member_num]=1;
    new->data.member_num=1;

    server_user_node_t* new_user;
    new_user=Find_server_user(pack_t->data.send_name);(pos->data.member_name[i],pack_t->data.message)==0) )
        {
    List_AddTail(group_ser,new);
    group_num++;

    printf("\ngroup:%s create !\n",pack_t->data.message);

    strcpy(pack_t->data.recv_name,pack_t->data.send_name);
    strcpy(pack_t->data.send_name,"server");

    pack_t->data.message[0]=2;
    Send_pack(pack_t);
    free(pack_t);*/
}
void Add_group(PACK* pack_t)
{
    int flag=ADD_GROUP_APPLY;
    char flag_add[10];
    int flag_t;
    char buf[BUFSIZ];

    group_list_t pos;

    for(pos=group_ser->next;pos!=group_ser;pos=pos->next)
    {
        if((strcmp(pos->data.group_name,pack_t->data.message)==0)&&(pos->data.type==OWNER))
        {
            printf("group_name:%s\n",pos->data.group_name);
            strcpy(pack_t->data.recv_name,pos->data.group_owner);
            flag_t=1;
        }
    }
    if(flag_t==1)
    {
        server_list_t temp;
        for(temp=list_ser->next;temp!=list_ser;temp=temp->next)
        {
            if((strcmp(temp->data.username,pack_t->data.recv_name)==0))
            {
                flag_add[0]='1';
                strcpy(pack_t->message,pack_t->data.message);
                Send_pack_type(temp->data.connfd,flag,pack_t,flag_add);
                return ;
            }
        }
    }
    else if(flag_t==0)
    {
        flag_add[0]='0';
        Send_pack_type(pack_t->data.send_fd,flag,pack_t,flag_add);
    }


    if(strcmp(pack_t->data.message,"y")==0)
    {
        server_list_t pos_user;
        for(pos_user=list_ser->next;pos_user!=list_ser;pos_user=pos_user->next)
        {
            if((strcmp(pos_user->data.username,pack_t->data.recv_name)==0))
            {
               break;
            }
        }
        flag_add[0]='2';
        printf("群名%s\n",pack_t->message);
        group_node_t* new;
        new=(group_node_t*)malloc(sizeof(group_node_t));
        
        strcpy(new->data.group_name,pack_t->message);
        strcpy(new->data.group_owner,pack_t->data.send_name);
        strcpy(new->data.member_name[++(new->data.member_num)],pack_t->data.recv_name);
        printf("群人数:%d\n",new->data.member_num);
        new->data.type=COMMON;
        new->data.status[new->data.member_num]=ONLINE;
        pos_user->data.member_num=new->data.member_num;

        List_AddTail(group_ser,new);

        memset(buf,0,sizeof(buf));
        sprintf(buf,"insert into group_member values('%s','%s','%d','%d')",pack_t->message,pack_t->data.recv_name,pos->data.member_num,COMMON);
        mysql_real_query(&mysql,buf,sizeof(buf));
        Send_pack_type(pos_user->data.connfd,flag,pack_t,flag_add);
    }
    else if(strcmp(pack_t->data.message,"n")==0)
    {
        server_list_t pos_user;
        for(pos_user=list_ser->next;pos_user!=list_ser;pos_user=pos_user->next)
        {
            if((strcmp(pos_user->data.username,pack_t->data.recv_name)==0))
            {
               break;
            }
        }
        flag_add[0]='3';
        Send_pack_type(pos_user->data.connfd,flag,pack_t,flag_add);
        return ;
    }
        /*strcpy(pos->data.member_name[pos->data.member_num],pack_t->data.send_name);
        pos->data.type[pos->data.member_num]=3;
        pos->data.status[pos->data.member_num]=1;
        pos->data.member_num++;


        strcpy(pack_t->data.recv_name,pack_t->data.send_name);
        strcpy(pack_t->data.send_name,"server");

        pack_t->data.message[0]=2;

        printf("\nuser:%s add group:%s successfully !\n",pack_t->data.recv_name,pack_t->data.message);

        Send_pack(pack_t);
        free(pack_t);
        return ;
    }
    strcpy(pack_t->data.recv_name,pack_t->data.send_name);
    strcpy(pack_t->data.send_name,"server");

    pack_t->data.message[0]=1;
    Send_pack(pack_t);
    free(pack_t);*/
}
void Withdraw_group(PACK* pack_t)
{

    int flag=WITHDRAW_GROUP_APPLY;
    char flag_withdraw[10];
    int flag_t;
    char buf[BUFSIZ];

    group_list_t pos;

    for(pos=group_ser->next;pos!=group_ser;pos=pos->next)
    {
        if((strcmp(pos->data.group_name,pack_t->data.message)==0))
        {
            printf("group_name:%s\n",pos->data.group_name);
            flag_t=1;
        }
    }
    if(flag_t==1)
    {
        strcpy(pack_t->message,pack_t->data.message);
        flag_withdraw[0]='1';
        List_FreeNode(pos);
        pos->data.member_num--;
        memset(buf,0,sizeof(buf));
        sprintf(buf,"delete from group_member where group_name='%s' and member_name='%s'",pack_t->data.message,pack_t->data.send_name);
        mysql_real_query(&mysql,buf,strlen(buf));
        Send_pack_type(pack_t->data.send_fd,flag,pack_t,flag_withdraw);
        return ;
    }
    else
    {
        flag_withdraw[0]='0';
        Send_pack_type(pack_t->data.send_fd,flag,pack_t,flag_withdraw);
        return ;
    }
    /*int i,j,k;
    group_list_t pos;
    pos=Find_server_group(pack_t->data.message);
    
    for(i=1;i<=group_num;i++)
    {
        if(strcmp(pack_t->data.message,pos->data.group_name)==0)
        {
            for(j=1;j<=pos->data.member_num;j++)
            {
                if(strcmp(pack_t->data.send_name,pos->data.member_name[j])==0)
                {
                    for(k=j;k<pos->data.member_num;k++)
                    {
                        strcpy(pos->data.member_name[k],pos->data.member_name[k+1]);
                        pos->data.type[k]=pos->data.type[k+1];
                        pos->data.status[k]=pos->data.status[k+1];
                    }
                    pos->data.member_num--;
                }
            }
        }
    }*/
}
void View_add_group(PACK* pack_t)
{
    int flag=VIEW_ADD_GROUP_APPLY;

    int i;
    group_list_t pos;
    for(pos=group_ser->next,i=0;pos!=group_ser;pos=pos->next,i++)
    {
        if((strcmp(pos->data.member_name[i],pack_t->data.send_name)==0) && (strcmp(pos->data.member_name[i],pack_t->data.send_name)==0) && (pos->data.type==OWNER || pos->data.type==ADMIN || pos->data.type==COMMON))
        {
            strcpy(pack_t->group.group_message[i],pos->data.group_name);
        }
    }
    pack_t->group.group_num=group_num;
    Send_pack_type(pack_t->data.send_fd,flag,pack_t,"");
    /*char status[MAX_CHAR*2];
    char buf[MAX_CHAR];
    char name_t[MAX_CHAR];
    int cnt;

    memset(status,0,sizeof(status));
    server_list_t pos;
    pos=Find_server_user(pack_t->data.send_name);
    
    
    status[cnt++]=pos->data.group_num;
    int i,j,k;
    for(i=1;i<=pos->data.group_num;i++)
    {
        memset(buf,0,sizeof(buf));
        strcpy(name_t,pos->data.group_message[i]);
        sprintf(buf,"[%s]",name_t);
        for(j=0;j<SAVE;j++)
            status[j+cnt]=buf[j];
        cnt+=SAVE;
    }



    strcpy(pack_t->data.recv_name,pack_t->data.send_name);
    strcpy(pack_t->data.send_name,"server");
    memcpy(pack_t->data.message,status,sizeof(status));
    pack_t->data.recv_fd=pack_t->data.send_fd;
    pack_t->data.send_fd=lfd;

    Send_pack(pack_t);
    free(pack_t);*/
}
void View_group_member(PACK* pack_t)
{
    int flag=VIEW_GROUP_MEMBER_APPLY;
    int i;
    group_list_t pos;
    for(pos=group_ser->next,i=0;pos!=group_ser;pos=pos->next,i++)
    {
        if((strcmp(pos->data.group_name,pack_t->data.message)==0) && (strcmp(pos->data.member_name[i],pack_t->data.send_name)==0) && (pos->data.type==OWNER || pos->data.type==ADMIN || pos->data.type==COMMON))
        {
            strcpy(pack_t->relation.friend_message[i],pos->data.member_name[i]);
        }
    }
    pack_t->relation.friend_num=pos->data.member_num;
    Send_pack_type(pack_t->data.send_fd,flag,pack_t,"");

    /*char status[MAX_CHAR*2];
    int type_t;
    int status_t;
    char buf[MAX_CHAR];
    char name_t[MAX_CHAR];
    int cnt;

    memset(status,0,sizeof(status));
    group_list_t pos;
    pos=Find_server_group(pack_t->data.message);

    status[cnt++]=pos->data.member_num;

    int i,j,k;


    for(i=1;i<=pos->data.member_num;i++)
    {
        memset(buf,0,sizeof(buf));
        strcpy(name_t,pos->data.member_name[i]);
        type_t=pos->data.type[i];
        status_t=pos->data.status[i];
        sprintf(buf,"[%s]:[权限:%d]([%d])",name_t,type_t,status_t);
        for(j=0;j<SAVE;j++)
            status[j+cnt]=buf[j];
        cnt+=SAVE;
    }


    strcpy(pack_t->data.recv_name,pack_t->data.send_name);
    strcpy(pack_t->data.send_name,"server");
    memcpy(pack_t->data.message,status,sizeof(status));
    pack_t->data.recv_fd=pack_t->data.send_fd;
    pack_t->data.send_fd=lfd;

    Send_pack(pack_t);
    free(pack_t);*/

}
void Del_group(PACK* pack_t)
{
    char buf[BUFSIZ];
    char flag_del[10];
    int flag=DEL_GROUP_APPLY;
    int flag_t;
    int flag_tt;
    group_list_t pos;
    for(pos=group_ser->next;pos!=group_ser;pos=pos->next)
    {
        if((strcmp(pos->data.group_name,pack_t->data.message)==0))
        {
            printf("pos:%s\n",pos->data.group_name);
            flag_t=1;
            break;
        }
    }
    for(pos=group_ser->next;pos!=group_ser;pos=pos->next)
    {
        if((strcmp(pos->data.member_name[1],pack_t->data.send_name)==0) && (strcmp(pos->data.group_name,pack_t->data.message)==0) &&(pos->data.type==OWNER))
        {
            printf("群名:%s,群主:%s\n",pos->data.group_name,pos->data.member_name[1]);
            flag_tt=1;
            break;
        }
    }
    if(flag_t==1 && flag_tt==1)
    {
        flag_del[0]='1';
        for(pos=group_ser->next;pos!=group_ser;pos=pos->next)
        {
            if((strcmp(pos->data.group_name,pack_t->data.message)==0))
            {
                printf("pos:%s\n",pos->data.group_name);
                List_FreeNode(pos);
            }
        }
        group_num--;
        memset(buf,0,sizeof(buf));
        sprintf(buf,"delete from account_group where group_name='%s'",pack_t->data.message);
        mysql_real_query(&mysql,buf,strlen(buf));
        Send_pack_type_name(pack_t->data.send_fd,flag,pack_t,flag_del);
    }
    else if(flag_t==1 && flag_tt==0)
    {
        flag_del[0]='2';
        Send_pack_type_name(pack_t->data.send_fd,flag,pack_t,flag_del);
    }
    else if(flag_t==0)
    {
        
        flag_del[0]='0';
        Send_pack_type_name(pack_t->data.send_fd,flag,pack_t,flag_del);
    }
    
    /*int i;
    int j;
    group_list_t pos=Find_server_group(pack_t->data.message);
    for(i=1;i<=group_num;i++)
    {
        if(strcmp(pos->data.group_name,pack_t->data.message)==0)
        {
           if(strcmp(pos->data.member_name[1],pack_t->data.send_name)==0)
           {
               //从链表中删除并释放结点node
               //
               List_FreeNode(pos);
               pack_t->data.message[0]=2;
           }
           else
           {
               pack_t->data.message[0]=1;
           }
           
        }
    }
    strcpy(pack_t->data.recv_name,pack_t->data.send_name);
    strcpy(pack_t->data.send_name,"server");

 
    Send_pack(pack_t);
    free(pack_t);*/
}
void Set_group_admin(PACK* pack_t)
{
    char buf[BUFSIZ];
    int flag_t;
    int flag_tt;
    int flag_ttt;
    char flag_set[10];
    int flag=SET_GROUP_ADMIN_APPLY;
    int i;
    group_list_t pos;
    for(pos=group_ser->next;pos!=group_ser;pos=pos->next)
    {
        if((strcmp(pos->data.group_name,pack_t->data.recv_name)==0))
        {
            printf("pos:%s\n",pos->data.group_name);
            flag_t=1;
            break;
        }
    }
    for(pos=group_ser->next,i=1;pos!=group_ser;pos=pos->next,i++)
    {
        if((strcmp(pos->data.group_name,pack_t->data.recv_name)==0) && (strcmp(pos->data.member_name[i],pack_t->data.message)==0) )
        {
            flag_tt=1;
            break;
        }
    }
    for(pos=group_ser->next;pos!=group_ser;pos=pos->next)
    {
        if((strcmp(pos->data.group_name,pack_t->data.recv_name)==0) && (strcmp(pos->data.member_name[1],pack_t->data.send_name)==0) && (pos->data.type==OWNER))
        {
            flag_ttt=1;
            break;
        }
    }
    server_list_t pos_user;
    
    if(flag_ttt==1 && flag_t==1 && flag_tt==1)
    {
        for(pos=group_ser->next,i=1;pos!=group_ser;pos=pos->next,i++)
        {
            if((strcmp(pos->data.group_name,pack_t->data.recv_name)==0) && (strcmp(pos->data.member_name[i],pack_t->data.message)==0) )
            {
                pos->data.type=ADMIN;
                break;
            }
        }

        for(pos_user=list_ser->next;pos_user!=list_ser;pos_user=pos_user->next)
        {
            if((strcmp(pos_user->data.username,pack_t->data.message)==0) )
            {
               flag_set[0]='4';
               strcpy(pack_t->message,pack_t->data.message);
               Send_pack_type(pos_user->data.connfd,flag,pack_t,flag_set);
            }
        }
        flag_set[0]='1';
        memset(buf,0,sizeof(buf));
        sprintf(buf,"update group_member set authority=%d where group_name='%s' and member_name='%s'",ADMIN,pack_t->data.recv_name,pack_t->data.message);
        mysql_real_query(&mysql,buf,strlen(buf));
        strcpy(pack_t->message,pack_t->data.message);
        Send_pack_type(pack_t->data.send_fd,flag,pack_t,flag_set);
    }
    else if(flag_ttt==0 &&flag_t==1 &&flag_tt==1)
    {
        flag_set[0]='2';
        Send_pack_type(pack_t->data.send_fd,flag,pack_t,flag_set);
    }
    else if(flag_tt==0)
    {
        flag_set[0]='3';
        strcpy(pack_t->message,pack_t->data.message);
        Send_pack_type(pack_t->data.send_fd,flag,pack_t,flag_set);
    }
    else if(flag_t==0)
    {
        flag_set[0]='0';
        Send_pack_type(pack_t->data.send_fd,flag,pack_t,flag_set);
    }
    

}
void Kick(PACK* pack_t)
{
    char buf[BUFSIZ];
    int flag=KICK_APPLY;
    int flag_t;
    int flag_tt;
    int flag_ttt;
    int flag_tttt;
    char flag_kick[10];
    int i;
    group_list_t pos;
    //群信息
    for(pos=group_ser->next;pos!=group_ser;pos=pos->next)
    {
        if((strcmp(pos->data.group_name,pack_t->data.recv_name)==0))
        {
            printf("pos:%s\n",pos->data.group_name);
            flag_t=1;
            break;
        }
    }
    //删除人员信息
    for(pos=group_ser->next,i=1;pos!=group_ser;pos=pos->next,i++)
    {
        if((strcmp(pos->data.group_name,pack_t->data.recv_name)==0) && (strcmp(pos->data.member_name[i],pack_t->data.message)==0) )
        {
            flag_tt=1;
            break;
        }
    }
    //群主或管理员信息
    for(pos=group_ser->next;pos!=group_ser;pos=pos->next)
    {
        if((strcmp(pos->data.group_name,pack_t->data.recv_name)==0) && (strcmp(pos->data.member_name[i],pack_t->data.send_name)==0) && (pos->data.type==OWNER || pos->data.type==ADMIN))
        {
            flag_ttt=1;
            break;
        }
    }
    //普通成员
    for(pos=group_ser->next,i=1;pos!=group_ser;pos=pos->next,i++)
    {
        if((pos->data.type==COMMON) && (strcmp(pos->data.member_name[i],pack_t->data.message)==0) )
        {
            flag_tttt=1;
            break;
        }
    }
    server_list_t pos_user;


    if(flag_t==1 &&flag_tt==1&& flag_ttt==1 && flag_tttt==1)
    {
        flag_kick[0]='1';
        List_FreeNode(pos);
        pos->data.member_num--;

        for(pos_user=list_ser->next;pos_user!=list_ser;pos_user=pos_user->next)
        {
            if((strcmp(pos_user->data.username,pack_t->data.message)==0) )
            {
               flag_kick[0]='5';
               strcpy(pack_t->message,pack_t->data.message);
               Send_pack_type(pos_user->data.connfd,flag,pack_t,flag_kick);
            }
        }
        memset(buf,0,sizeof(buf));
        sprintf(buf,"delete from group_member where group_name='%s' and member_name='%s'",pack_t->data.recv_name,pack_t->data.message);
        mysql_real_query(&mysql,buf,strlen(buf));
        strcpy(pack_t->message,pack_t->data.message);
        Send_pack_type(pack_t->data.send_fd,flag,pack_t,flag_kick);
    }
    else if(flag_ttt==0 && flag_t==1 && flag_tt==1 && flag_tttt==1)
    {
        flag_kick[0]='2';
        Send_pack_type(pack_t->data.send_fd,flag,pack_t,flag_kick);
    }
    else if(flag_tt==0)
    {
        flag_kick[0]='3';
        strcpy(pack_t->message,pack_t->data.message);
        Send_pack_type(pack_t->data.send_fd,flag,pack_t,flag_kick);
    }
    else if(flag_tttt==0)
    {
        flag_kick[0]='4';
        Send_pack_type(pack_t->data.send_fd,flag,pack_t,flag_kick);
    }
    else if(flag_t==0)
    {
        flag_kick[0]='0';
        Send_pack_type(pack_t->data.send_fd,flag,pack_t,flag_kick);
    }

}


void Connect_mysql()
{
    mysql_init(&mysql);
    //初始化数据库
    mysql_library_init(0,NULL,NULL);
    if(!mysql_real_connect(&mysql,"localhost","root","wxz","bokket",0,NULL,0))
    {
        sys_err("connect error!",__LINE__);
    }
    if(mysql_set_character_set(&mysql,"utf8"))
    {
        sys_err("set error!",__LINE__);
    }
    printf("连接MYSQL数据库成功!\n");
}
void Mysql_save_message(PACK* pack_t,int flag)
{
    char buf[MAX_CHAR*4];
    memset(buf,0,sizeof(buf));
    if(flag==VIEW_CHAT_HISTORY)
    {
        sprintf(buf,"insert into chat_message values('%s','%s','%s')",pack_t->data.send_name,pack_t->data.recv_name,pack_t->data.message);
    }
    else if(flag==VIEW_CHAT_HISTORY) 
    {
         sprintf(buf,"insert into group_message values('%s','%s','%s')",pack_t->data.send_name,pack_t->data.recv_name,pack_t->data.message);
    }
        
        int ret;
        ret=mysql_real_query(&mysql,buf,strlen(buf));

        if(ret)
        {
            Mysql_with_error(&mysql);
            return ;
        }
        printf("the message write into the mysql\n");

}
void Close_mysql(MYSQL mysql)
{
    mysql_close(&mysql);
    //mysql_free_result(result);
    mysql_library_end();
    printf("MYSQL数据库关闭!\n");
}
void Send_record(PACK* pack_t)
{
    char buf[MAX_CHAR*6];
    memset(buf,0,sizeof(buf));
    char send_name[MAX_CHAR];
    char recv_name[MAX_CHAR];
    
    PACK *send_record_pack=(PACK *)malloc(sizeof(PACK));
    strcpy(send_name,pack_t->data.send_name);
    strcpy(recv_name,pack_t->data.message);
    


    if(pack_t->flag==VIEW_CHAT_HISTORY)
    {
        sprintf(buf,"select message from chat_message where (send_name='%s' and recv_name='%s') or (send_name='%s' and recv_name='%s')",send_name,recv_name,recv_name,send_name);
    }


    if(pack_t->flag==VIEW_GROUP_RECORD)
    {
        sprintf(buf,"select message from group_message where recv_name='%s'",pack_t->data.message);            
    }
       

    int ret=mysql_real_query(&mysql,buf,strlen(buf));
    
    if(ret) 
    {
       Mysql_with_error(&mysql);
       return ;
    }
    
    MYSQL_RES* result=mysql_store_result(&mysql);                             
    
    if(result==NULL)
    {
        Mysql_with_error(&mysql);     
        return ;
    }

    //行数
    int rows=mysql_num_rows(result);                                    
    printf("rows:%d\n",rows);                        
    //列数
    int fields=mysql_num_fields(result); 
    printf("fields is:%d\n",fields);  


    int i=0;
    MYSQL_ROW row;
    while((row=mysql_fetch_row(result))) 
    {     
        send_record_pack->flag=pack_t->flag;
        strcpy(send_record_pack->data.send_name,"server");
        strcpy(send_record_pack->data.recv_name,send_name);
        strcpy(send_record_pack->data.message,row[i]);
        strcpy(send_record_pack->data.group_chat,row[i]);
        //strcpy(send_record_pack->data.message+SAVE,row[3]);
        //strcpy(send_record_pack->data.message+SAVE,row[2]);
        printf("%s\n",send_record_pack->data.message);
        Send_pack(send_record_pack);
        usleep(100000);   
    }
    
    usleep(100000);
    printf("OK!\n");
    
    //发送包，表示已经传输完毕
    send_record_pack->flag=MESSAGE_RECORD;
    strcpy(send_record_pack->data.send_name,"server");
    strcpy(send_record_pack->data.recv_name,send_name);
    strcpy(send_record_pack->data.message,"end");
    Send_pack(send_record_pack);
 
    usleep(10000);
    free(send_record_pack);
}

void Read_from_mysql()
{

    Server_user(list_ser);//读取用户信息
    Server_friend(friend_ser);
    Server_group(group_ser);
    Server_group_member(group_ser);
}
void Server_user(server_list_t list_ser)
{
    MYSQL_ROW row;//行
    MYSQL_RES* result;
    char buf[MAX];
    int rows;
    int fields;
    sprintf(buf,"select *from account");
    mysql_real_query(&mysql,buf,strlen(buf));

    result=mysql_store_result(&mysql);
    rows=mysql_num_rows(result);//行
    fields=mysql_num_fields(result);//列

    while((row=mysql_fetch_row(result)))
    {
        server_user_node_t* new;
        new=(server_user_node_t*)malloc(sizeof(server_user_node_t));
        strcpy(new->data.username,row[0]);
        strcpy(new->data.password,row[1]);
        new->data.online=row[2][0];
        
        List_AddTail(list_ser,new);
        user_num++;
        
    }
}
void Server_friend(friend_list_t friend_ser)
{
    MYSQL_ROW row;//行
    MYSQL_RES* result;
    char buf[MAX];
    int rows;
    int fields;


    sprintf(buf,"select *from friend");
    mysql_real_query(&mysql,buf,strlen(buf));
    result=mysql_store_result(&mysql);
    
    rows=mysql_num_rows(result);//行
    fields=mysql_num_fields(result);//列


    while((row=mysql_fetch_row(result)))
    {
        friend_node_t *new=(friend_node_t*)malloc(sizeof(friend_node_t));
        strcpy(new->data.username,row[0]);
        strcpy(new->data.friend_name,row[1]);
        new->data.status=row[2][0];

        List_AddTail(friend_ser,new);
        new->data.friend_num++;

    }
}
void Server_group(group_list_t group_ser)
{
    MYSQL_ROW row;//行
    MYSQL_RES* result;
    char buf[MAX];
    int rows;
    int fields;
    sprintf(buf,"select *from account_group");
    mysql_real_query(&mysql,buf,strlen(buf));

    result=mysql_store_result(&mysql);
    rows=mysql_num_rows(result);//行
    fields=mysql_num_fields(result);//列

    group_num=0;
    while((row=mysql_fetch_row(result)))
    {
        group_node_t* new;
        new=(group_node_t*)malloc(sizeof(group_node_t));
        strcpy(new->data.group_owner,row[0]);
        strcpy(new->data.group_name,row[1]);
    
        List_AddTail(group_ser,new);
        group_num++;
        
    }
}
void Server_group_member(group_list_t group_ser)
{
    MYSQL_ROW row;//行
    MYSQL_RES* result;
    char buf[MAX];
    int rows;
    int fields;

   
    
    sprintf(buf,"select *from group_member");
    mysql_real_query(&mysql,buf,strlen(buf));
    result=mysql_store_result(&mysql);
    
    rows=mysql_num_rows(result);//行
    fields=mysql_num_fields(result);//列
    int i=0;
    while((row=mysql_fetch_row(result)))
    {
        group_node_t* new;
        new=(group_node_t*)malloc(sizeof(group_node_t));

        strcpy(new->data.group_name,row[0]);
        strcpy(new->data.member_name[i],row[1]);
        i++;
        new->data.member_num=atoi(row[2]);
        new->data.type=atoi(row[3]);
    }
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
void Mysql_with_error(MYSQL* mysql)
{
    fprintf(stderr,"%s\n",mysql_error(mysql));
    mysql_close(mysql);
    return ;
}
void Recv_pack_message(PACK recv_t)
{
    printf("\n----------PACK----------\n");
    printf("类型  :\n");
    printf("发送包的名字  :%s\n",recv_t.data.send_name);
    printf("接受包的名字  :%s\n",recv_t.data.recv_name);
    printf("信息  :%s\n",recv_t.data.message);
    printf("发送者fd  :%d\n",recv_t.data.send_fd);
    printf("接收者fd  :%d\n",recv_t.data.recv_fd);
    printf("发送包的数量:%d\n",send_num);
}
   
void Send_recv_pack(int fd,PACK* recv_pack,char* flag)
{
    PACK pack_send;
    
    memcpy(&pack_send,recv_pack,sizeof(PACK));
    printf("%s\n%s\n",pack_send.data.recv_name,pack_send.data.send_name);

    strcpy(pack_send.data.recv_name,pack_send.data.send_name);
    strcpy(pack_send.data.send_name,"server");
    strcpy(pack_send.data.message,flag);
    printf("%s\n%s\n",pack_send.data.recv_name,pack_send.data.send_name);

    printf("%s\n",pack_send.data.message);
    pack_send.data.recv_fd=pack_send.data.send_fd;
    pack_send.data.send_fd=fd;

    if(send(fd,&pack_send,sizeof(PACK),0)<0)
    {
        my_err("send error!",__LINE__);
    }
}
void Send_pack_type(int fd,int type,PACK* recv_pack,char* flag)
{
    PACK pack_send;
    char recv_name_t[MAX];
    memcpy(&pack_send,recv_pack,sizeof(PACK));
    printf("%s\n%s\n",pack_send.data.recv_name,pack_send.data.send_name);


    strcpy(recv_name_t,pack_send.data.recv_name);
    pack_send.flag=type;
    strcpy(pack_send.data.recv_name,pack_send.data.send_name);
    strcpy(pack_send.data.send_name,recv_name_t);
    strcpy(pack_send.data.message,flag);
    printf("%d\n",pack_send.flag);
    printf("%s\n%s\n",pack_send.data.recv_name,pack_send.data.send_name);

    printf("%s\n",pack_send.data.message);
    pack_send.data.recv_fd=pack_send.data.send_fd;
    pack_send.data.send_fd=fd;
   
    
    if(send(fd,&pack_send,sizeof(PACK),0)<0)
    {
        my_err("send error!",__LINE__);
    }
}
void Send_pack_type_name(int fd,int type,PACK* recv_pack,char* flag)
{
    PACK pack_send;
    memcpy(&pack_send,recv_pack,sizeof(PACK));
 
    pack_send.flag=type;
    strcpy(pack_send.data.recv_name,pack_send.data.send_name);
    strcpy(pack_send.data.send_name,pack_send.data.message);
    strcpy(pack_send.data.message,flag);
    printf("%d\n",pack_send.flag);
    printf("%s\n%s\n",pack_send.data.recv_name,pack_send.data.send_name);

    printf("%s\n",pack_send.data.message);

    pack_send.data.recv_fd=pack_send.data.send_fd;
    pack_send.data.send_fd=fd;
   
    
    if(send(fd,&pack_send,sizeof(PACK),0)<0)
    {
        my_err("send error!",__LINE__);
    }

}
void Send_pack(PACK* send_pack_t)
{
    pthread_mutex_lock(&mutex);
    memcpy(&(pack_send[send_num++]),send_pack_t,sizeof(PACK));
    pthread_mutex_unlock(&mutex);
}
server_list_t Find_server_user(char *username)
{
    /*if(user_num==0)
        return NULL;
    */
    server_list_t pos=list_ser;
    if(pos==NULL)
        return NULL;
    for(pos=list_ser->next;pos!=list_ser;pos=pos->next)
    {
        if((strcmp(pos->data.username,username)==0))
        {
            printf("pos:%s\n%s\n",pos->data.username,pos->data.password);
            return pos;
        }
    }
    return NULL;
}
void Find_del_server_user(server_list_t pos,char* friend_name)
{
    int i;
    int index;
    for(pos=list_ser->next,i=0;pos!=list_ser;pos=pos->next,i++)
    {
        if((strcmp(pos->data.friend_message[i],friend_name)==0))
        {
            printf("pos:%s\n%s\n",pos->data.username,pos->data.password);
            index=i;
        }
    }
    for(pos=list_ser->next,i=index;pos!=list_ser;pos=pos->next,i++)
    {
        strcpy(pos->data.friend_message[i],pos->data.friend_message[i+1]);
    }
    pos->data.friend_num--;
}

group_list_t Find_server_group(char* group_name)
{
    group_list_t pos=group_ser;
    if(group_num==0)
        return NULL;
    if(pos==NULL)
        return NULL;
    for(pos=group_ser->next;pos!=group_ser;pos=pos->next)
    {
        if((strcmp(pos->data.group_name,group_name)==0))
        {
            printf("pos:%s\n",pos->data.group_name);
            return pos;
        }
    }
    return NULL;
}