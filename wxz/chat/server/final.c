#include "chat.h"
#define EPOLLEVENT 1024
int sys_log;
MYSQL mysql;


void Add_node(int fd,int id);
void Send_register_pack(int fd,int flag,char* buf,int id);
int main()
{

   


    /*if((sys_log=open("sys_log",O_WRONLY | O_CREAT | O_APPEND,S_IRUSR|S_IWUSR))<0)
    {
        sys_err("open error",__LINE__);
        return 0;
    }
    dup2(sys_log,1);*/

    
    signal(SIGINT,Signal_close);

    pthread_mutex_init(&mutex,NULL);
    pthread_cond_init(&cond,NULL);

    Connect_mysql();
    /*printf("线程池启动\n");
    pool_init(MAX_THREAD_NUM);
    printf("线程池启动成功!\n");
    sleep(2);*/

    //Read_from_mysql();
    Init_socket();


    //threadpool_destroy();

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
  
    List_Init(list_ser,server_user_node_t);
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
    pthread_t pid;
    char buf[BUFSIZ];
    memset(buf,0,sizeof(buf));
    while(1)
    {
        ret=epoll_wait(epfd,ep,EPOLLEVENT,-1);
        for(i=0;i<ret;i++)
        {

            //printf("the event is %x\n",ep[i].events);

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
                int n=recv(ep[i].data.fd,buf,sizeof(buf),MSG_WAITALL);
                int fd=ep[i].data.fd;
                printf("////////////////////////////\n");
                /*printf("%d\n",recv_t.data.send_fd);
                printf("%d\n",recv_t.data.recv_fd);
                printf("server message%s\n",recv_t.data.message);
                printf("server recv:%s\n",recv_t.data.send_name);*/


                if(n<0)
                {
                    close(ep[i].data.fd);
                    sys_err("recv error!",__LINE__);
                    continue;
                }
                else if(n==0)
                {
                    printf("??????\n");
                    server_list_t pos;
                    List_ForEach(list_ser,pos)
                    {
                        if(pos->data.connfd==ep[i].data.fd)
                        {    
                            List_FreeNode(pos);   
                            printf("%d下线了:%d\n",pos->data.id,pos->data.connfd);
                            break;
                        }
                    }
                    tep.data.fd=ep[i].data.fd;
                    printf("客户端:%d连接断开\n",tep.data.fd);
                   
                    epoll_ctl(epfd,EPOLL_CTL_DEL,ep[i].data.fd,&tep);
                    close(ep[i].data.fd);
                    continue;
                }

                int flag;
                memcpy(&flag,buf,sizeof(int));
                printf("flag:%d\n",flag);
                //threadpool_add(work,(void*)recv_pack_t);
                switch(flag)
                {
                    case LOGIN:
                        Login(fd,buf);
                        break;
                    case REGISTER:
                        Register(fd,buf);
                        break;
                        
                    case ADD_FRIEND:
                        Add_friend(fd,buf);
                        break;
                    case ADD_FRIEND_ACCEPT:
                        Add_friend_accept(fd,buf);
                        break;
                    case DEL_FRIEND:
                        Del_friend(fd,buf);
                        break;
                    case PRIVATE_CHAT:
                        Private_chat(fd,buf);
                        break;
                    //写在一起比较好
                    //case SHOW_FRIEND_STATUS:
                    case VIEW_FRIEND_LIST:
                        View_friend_list(fd,buf);
                        break;
                    case SHIELD:
                        Shield_friend(fd,buf);
                        break;
                    case UNSHIELD:
                        Unshield_friend(fd,buf);
                        break;
                    case VIEW_CHAT_HISTORY:
                        View_chat_history(fd,buf);
                    case CREAT_GROUP:
                        Create_group(fd,buf);
                        break;
                    case ADD_GROUP:
                        Add_group(fd,buf);
                        break;
                    case ADD_GROUP_ACCEPT:
                        Add_group_accept(fd,buf);
                        break;
                    case WITHDRAW_GROUP:
                        Withdraw_group(fd,buf);
                        break;
                    //一起实现
                    //case VIEW_GROUP_MEMBER:
                    case VIEW_ADD_GROUP:
                        View_add_group(fd,buf);
                        break;
                    case SET_GROUP_ADMIN:
                        Set_group_admin(fd,buf);
                        break;
                    case KICK:
                        Kick(fd,buf);
                        break;
                    case GROUP_CHAT:
                        Group_chat(fd,buf);
                        break;
                    case VIEW_GROUP_RECORD:
                        View_group_record(fd,buf);
                        break;
                     case SEND_FILE:
                        Send_file(fd,buf);
                        break;
                    case 0:
                        break;
                }
            }       
            else if(ep[i].events & EPOLLOUT)
            {
                printf("写事件\n");
                if(send(ep[i].data.fd,buf,sizeof(buf),0)<0)
                {
                    my_err("send error\n",__LINE__);
                    close(ep[i].data.fd);
                }
                else 
                    printf("发送消息成功\n");
                memset(buf,0,sizeof(buf));
            }
        }
    }
    close(epfd);
    close(lfd);
}

void Register(int fd,char* buf)
{
    Account_t account;
    memcpy(&account,buf,sizeof(account));
    printf("server name:%s\n",account.name);
    printf("server password:%s\n",account.password);
    server_user_t user;
    strcpy(user.name,account.name);
    strcpy(user.password,account.password);
    printf("server username:%s\n",user.name);
    printf("server password:%s\n",user.password);

    account.online=DOWNLINE;

   
    
    char buf_t[BUFSIZ];
    sprintf(buf_t,"insert into account values(NULL,'%s','%s','%d')",account.name,account.password,account.online);
    printf("buf_t:%s\n",buf_t);
    int ret=mysql_real_query(&mysql,buf_t,strlen(buf_t));
    if(ret)
    {
        Mysql_with_error(&mysql);
    }
    else 
        printf("注册成功\n");

    memset(buf_t,0,sizeof(buf_t));
    sprintf(buf_t,"select LAST_INSERT_ID()");
    printf("buf_t:%s\n",buf_t);
    ret=mysql_query(&mysql,buf_t);
    if(ret)
    {
        Mysql_with_error(&mysql);
    }
    MYSQL_RES *result;  
    MYSQL_ROW  row;
    result=mysql_store_result(&mysql);
    row=mysql_fetch_row(result);
    int id=atoi(row[0]);
    printf("server username:%d",id);
    char str[256];
    //strcpy(str,account.username);
    sprintf(str,"账号[%d]注册成功",id);
    

    Send_register_pack(fd,REGISTER_APPLY,str,id);
    printf("666666666\n");   
}               


void Send_register_pack(int fd,int flag,char* buf,int id)
{
    char str[BUFSIZ];
    message mes;

    mes.flag=flag;
    mes.id=id;
    strcpy(mes.message,buf);
    printf("server send message:%s\n",mes.message);
    memcpy(str,&mes,sizeof(mes));
    
    printf("server send id:%d\n",mes.id);
    printf("server send flag:%d\n",mes.flag);
    if(send(fd,str,sizeof(str),0)<0)
    {
        my_err("send error!",__LINE__);
        close(fd);
    }
}


void Login(int fd,char* buf)
{
    Account_t account;
    memcpy(&account,buf,sizeof(account));
    printf("server id:%d\n",account.id);
    printf("server password:%s\n",account.password);

    
    server_list_t pos;
    List_ForEach(list_ser,pos)
    {
        if(pos->data.id==account.id)
        {
            printf("账号已登录\n");
            Send_pack(fd,LOGIN_APPLY,"a");
            return;
        }
    }
    char buf_t[BUFSIZ];
    sprintf(buf_t,"select *from account where id=%d",account.id);
    printf("buf_t:%s\n",buf_t);
    int ret=mysql_real_query(&mysql,buf_t,strlen(buf_t));
    if(ret)
    {
        Mysql_with_error(&mysql);
    }
    MYSQL_RES *result;  
    MYSQL_ROW  row;
    result=mysql_store_result(&mysql);
    row=mysql_fetch_row(result);
        printf("row[0]:%s\n",row[0]);
    if(row==NULL)
    {
        printf("/////\n");
        Send_pack(fd,LOGIN_APPLY,"n");
        return ;
    }
    else
    {
        //if(strcmp(row[0],user.username)==0)
        //{
          //  memset(buf_t,0,sizeof(buf_t));
            //sprintf(buf_t,"select username from account");
            //printf("buf_t:%s\n",buf_t);
            if(strcmp(row[2],account.password)==0)
            {
                Add_node(fd,account.id);
                server_list_t p;
                List_ForEach(list_ser,p)
                {
                    printf("username:%d\n",p->data.id);
                    printf("connfd:%d\n",p->data.connfd);
                }
                Send_pack(fd,LOGIN_APPLY,"y");
                memset(buf_t,0,sizeof(buf_t));
                sprintf(buf_t,"update account set status=1 where id=%d",account.id);
                printf("buf_t:%s\n",buf_t);
                int ret=mysql_real_query(&mysql,buf_t,strlen(buf_t));
                if(ret)
                {
                    Mysql_with_error(&mysql);
                }
                return;
            }
            else
                Send_pack(fd,LOGIN_APPLY,"n");
        //}
    }
}
void Add_node(int fd,int id)
{
    server_list_t pos=(server_list_t)malloc(sizeof(server_user_node_t));
    pos->data.connfd=fd;
    pos->data.id=id;
    List_AddTail(list_ser,pos);
}

void Add_friend(int fd,char* buf)
{

    Relation_t relation;
    memcpy(&relation,buf,sizeof(relation));
    printf("server/ friend send:%d\n",relation.send);
    printf("server/ friend recv:%d\n",relation.recv);
    printf("server/ friend message:%s\n",relation.message);

    char buf_t[BUFSIZ];
    //查询有没有这两个人的账号
    sprintf(buf_t,"select *from friend where (uid=%d and fid=%d) or (uid=%d and fid=%d)",relation.send,relation.recv,relation.recv,relation.send);
    printf("%s\n",buf_t);
    int ret=mysql_real_query(&mysql,buf_t,strlen(buf_t));
    if(ret)
    {
        Mysql_with_error(&mysql);
    }
    MYSQL_RES *result;  
    MYSQL_ROW  row;
    result=mysql_store_result(&mysql);
    row=mysql_fetch_row(result);
    //获得申请者的客户端套接字
    int send_fd;
    send_fd=Get_connfd(relation.send);
    //如果没有这两个的信息
    if(row==NULL)
    {
        relation.relation=STRANGER;
        memset(buf_t,0,sizeof(buf_t));
        sprintf(buf_t,"insert into friend values('%d','%d','%d')",relation.send,relation.recv,relation.relation);
        printf("%s\n",buf_t);
        ret=mysql_real_query(&mysql,buf_t,strlen(buf_t));
        if(ret)
        {
            Mysql_with_error(&mysql);
        }
        printf("用户%d对%d发起了好友申请\n",relation.send,relation.recv);

        //获得被申请好友的客户端套接字
        //如果在线
        int recv_fd=relation.recv;
        printf("hehehheheheh>>>>>>>>>\n");
        printf("recv_fd:%d\n",recv_fd);
        if(recv_fd<0)
        {
            printf("所申请的用户[%d]不在线\n",relation.recv);
            Send_pack(send_fd,PRINT_APPLY,"d");
            return;
        }
        else
        {
            char str[256];
            sprintf(str,"用户[%d]向你发送了好友请求",relation.send);
            Send_connfd_pack(ADD_FRIEND_APPLY,relation.send,relation.recv,str);
        }
    }
    else if(row!=NULL)
    {
        Send_pack(send_fd,PRINT_APPLY,"w");
        return;
    }


}
void Send_connfd_pack(int flag,int sender,int recver,char* buf)
{
    int recv_fd;
    server_list_t pos;
    //获得接受者套接字
    List_ForEach(list_ser,pos)
    {
        if(pos->data.id==recver)
        {
            printf("该用户的客户端套接字为:%d\n",pos->data.connfd);
            recv_fd=pos->data.connfd;
        }
    }
    int send_fd;
    send_fd=Get_connfd(sender);

    char str[BUFSIZ];
    box_t box;
    box.flag=flag;
    box.sender=sender;//申请者
    box.recver=recver;//被申请者
    box.send_fd=send_fd;//申请者客户端号
    box.recv_fd=recv_fd;//被申请者客户端号

    //buf:用户[%d]向你发送了好友请求
    strcpy(box.message,buf);

    memcpy(str,&box,sizeof(box));

    printf("server send message:%s\n",box.message);
    printf("server send flag:%d\n",box.flag);
    printf("server/ friend send id:%d\n",box.sender);
    printf("server/ friend recv id:%d\n",box.recver);
    //朋友客户端号
    printf("server/ friend recv_fd:%d\n",recv_fd);
    printf("server/ friend send_fd:%d\n",send_fd);

    if(send(recv_fd,str,sizeof(str),0)<0)
    {
        my_err("send error!",__LINE__);
    }

}
void Add_friend_accept(int fd,char* buf)
{
    Relation_t relation;
    memcpy(&relation,buf,sizeof(relation));
    printf("server/ friend accpet send:%d\n",relation.send);
    printf("server/ friend accpet recv:%d\n",relation.recv);
    printf("server/ friend accpet message:%s\n",relation.message);

    char str1[BUFSIZ];
    char str2[BUFSIZ];
    if(strcmp(relation.message,"y")==0)
    {
        char buf[BUFSIZ];
        relation.relation=PAL;
        sprintf(buf,"update friend set status =%d where (uid=%d and fid=%d) ",relation.relation,relation.recv,relation.send);
        printf("buf:%s\n",buf);
        int ret=mysql_real_query(&mysql,buf,strlen(buf));
        if(ret)
        {
            Mysql_with_error(&mysql);
        }
        printf("[%d]成为了[%d]的新朋友\n",relation.send,relation.recv);

        sprintf(str1,"[%d]通过了您的好友请求",relation.send);
        Send_pack_name(ADD_FRIEND_ACCEPT_APPLY,relation.send,relation.recv,str1);//发给申请者

        sprintf(str2,"你已经和[%d]成为了朋友",relation.recv);
        Send_pack_name(ADD_FRIEND_ACCEPT_APPLY,relation.recv,relation.send,str2);//发给被申请者
    }
    else
    {
        char buf[BUFSIZ];
        sprintf(buf,"delete from friend where (uid=%d and fid=%d)",relation.recv,relation.send);
        printf("buf:%s\n",buf);
        int ret=mysql_real_query(&mysql,buf,strlen(buf));
        if(ret)
        {
            Mysql_with_error(&mysql);
        }
        printf("[%d]拒绝成为[%d]的好友\n",relation.send,relation.recv);

        memset(str1,0,sizeof(str1));
        sprintf(str1,"[%d]拒绝了您的好友请求",relation.send);
        Send_pack_name(ADD_FRIEND_ACCEPT_APPLY,relation.send,relation.recv,str1);//发给申请者

    }
}

void Send_pack_name(int flag ,int sender,int recver,char *buf)
{
    int recv_fd=Get_connfd(recver);
    char str[BUFSIZ];
    apply_messgae mes;

    mes.flag=flag;
    mes.sender=sender;//被申请者
    mes.recver=recver;//申请者
    strcpy(mes.message,buf);
    printf("server/ friend accept apply send:%d\n",mes.sender);
    printf("server/ friend accept apply recv:%d\n",mes.recver);
    printf("server/ friend accept apply send message:%s\n",mes.message);

    memcpy(str,&mes,sizeof(mes));
    
    printf("server send message:%s\n",mes.message);
    printf("server send flag:%d\n",mes.flag);
    if(send(recv_fd,str,sizeof(str),0)<0)
    {
        my_err("send error!",__LINE__);
    }


}
int Get_connfd(int id)
{
    server_list_t pos;
    List_ForEach(list_ser,pos)
    {
        if(pos->data.id==id)
        {
            printf("用户套接字:%d\n",pos->data.connfd);
            return pos->data.connfd;
        }
    }
    return -1;
}

void Del_friend(int fd,char* buf)
{
    
    Relation_t relation;
    memcpy(&relation,buf,sizeof(relation));
    printf("server/ friend send:%d\n",relation.send);
    printf("server/ friend recv:%d\n",relation.recv);
    printf("server/ friend message:%s\n",relation.message);

    char buf_t[BUFSIZ];
    //更新这两个人的关系
    sprintf(buf_t,"delete from friend where (uid=%d and fid=%d) or (uid=%d and fid=%d)",relation.send,relation.recv,relation.recv,relation.send);
    printf("%s\n",buf_t);
    int ret=mysql_real_query(&mysql,buf_t,strlen(buf_t));
    if(ret)
    {
        Mysql_with_error(&mysql);
        printf("删除好友失败\n");
    }
    printf("[%d]删除了与[%d]的好友关系\n",relation.send,relation.recv);

    //获得发送者的端口号
    int send_fd=Get_connfd(relation.send);
    char str1[BUFSIZ];
    char str2[BUFSIZ];
    sprintf(str1,"你与[%d]的朋友关系已经解除",relation.recv);
    Send_pack(send_fd,DEL_FRIEND_APPLY,str1);

    //被删除者的端口号
    int recv_fd=Get_connfd(relation.recv);
    sprintf(str2,"你已经被[%d]删除了好友关系",relation.send);
    Send_pack(recv_fd,DEL_FRIEND_APPLY,str2);


    /*server_list_t pos;
    server_list_t pos_friend;

    pos=Find_server_user(pack_t->data.send_name);
    Find_del_server_user(pos,pack_t->data.message);

    pos_friend=Find_server_user(pack_t->data.message);
    Find_del_server_user(pos_friend,pack_t->data.send_name);

    free(pack_t);*/
}

void Private_chat(int fd,char* buf)
{
    Chat_message mes;
    memcpy(&mes,buf,sizeof(mes));

    printf("server/ friend chat send:%d\n",mes.sender);
    printf("server/ friend chat recv:%d\n",mes.recver);
    //printf("server/ friend chat time:%s\n",mes.time);
    printf("server/ friend chat message:%s\n",mes.message);

    //先插入mysql
    char str[BUFSIZ];
    sprintf(str,"insert into chat_message values('%d','%d','%s','%d')",mes.sender,mes.recver,mes.message,0);
    //没发前状态为0
    printf("str:%s\n",str);
    int ret=mysql_real_query(&mysql,str,strlen(str));
    if(ret)
    {
        Mysql_with_error(&mysql);
    }

    printf("[%d]对[%d]聊天记录以及写入mysql\n",mes.sender,mes.recver);

    //获取聊天对方的套接字
    int recv_fd=Get_connfd(mes.recver);
    int send_fd=Get_connfd(mes.sender);
    if(recv_fd<0)
    {
        printf("[%d]不在线\n",mes.recver);
        Send_pack(send_fd,PRIVATE_CHAT_APPLY,"d");
    }
    else
    {
    
        char buf[BUFSIZ];
        sprintf(buf,"select *from chat_message where (uid=%d and fid=%d and status=%d)",mes.sender,mes.recver,0);//0未发送
        printf("buf:%s\n",buf);
        ret=mysql_real_query(&mysql,buf,strlen(buf));
        printf("?????\n");
        if(ret)
        {
            printf(">>>>>\n");
            Mysql_with_error(&mysql);
        }

        MYSQL_RES *result;
        MYSQL_ROW row;
        result=mysql_store_result(&mysql);

        
        while((row=mysql_fetch_row(result)))
        {
            //标志位改为1并且发送
            char str[BUFSIZ];
            sprintf(str,"update chat_message set status=%d where (uid=%d and fid=%d)",2,mes.sender,mes.recver);//2已经发送
            printf("str:%s\n",str);
            int ret=mysql_real_query(&mysql,str,strlen(str));
            if(ret)
            {
                Mysql_with_error(&mysql);
            }
            else
            {
                Chat_message mes_t;
                mes_t.flag=PRIVATE_CHAT_APPLY;
                mes_t.sender=atoi(row[0]);
                mes_t.recver=atoi(row[1]);
                //strcpy(mes_t.time,mes.time);
                printf("row[2]:%s\n",row[2]);
                strcpy(mes_t.message,row[2]);
                printf("mes_t.flag:%d\n",mes_t.flag);
                printf("mes_t.sender:%d\n",mes_t.sender);
                printf("mes_t.recver:%d\n",mes_t.recver);
                printf("mes_t.mes:%s\n",mes_t.message);
                //printf("mes_t.time:%s\n",mes_t.time);
                char buf[BUFSIZ];
                memcpy(buf,&mes_t,sizeof(mes_t));
                if(send(recv_fd,buf,sizeof(buf),0)<0)
                {
                    my_err("send error!",__LINE__);
                }
                printf("[%d]正在对[%d]聊天\n",mes_t.sender,mes_t.recver);
            }  
        }
    }
}
void View_chat_history(int fd,char* buf)
{
    Chat_message mes;
    memcpy(&mes,buf,sizeof(mes));

    char str[BUFSIZ];
    sprintf(str,"select *from friend where (uid=%d and fid=%d) or (uid=%d and fid=%d)",mes.sender,mes.recver,mes.recver,mes.sender);
    printf("str:%s\n",str);
    int ret=mysql_real_query(&mysql,str,strlen(str));
    if(ret)
    {
        Mysql_with_error(&mysql);
    }
    MYSQL_RES *result;  
    MYSQL_ROW  row;
    result=mysql_store_result(&mysql);
    row=mysql_fetch_row(result);
    if(row==NULL)
    {
        Send_pack(fd,PRINT_APPLY,"你们还不是好友，请先添加好友聊天");
        printf("[%d]查询聊天记录失败\n",mes.sender);
    }

    char str2[BUFSIZ];
    sprintf(str2,"select *from chat_message where (uid=%d and fid=%d) or (uid=%d and fid=%d)",mes.sender,mes.recver,mes.recver,mes.sender);
    printf("str2:%s\n",str2);
    ret=mysql_real_query(&mysql,str2,strlen(str2));
    if(ret)
    {
        Mysql_with_error(&mysql);
    }

    int send_fd=Get_connfd(mes.sender);
    char str1[256];
    printf("22222222\n");
    MYSQL_RES *result2;  
    MYSQL_ROW  row2;
    result2=mysql_store_result(&mysql);
    while((row2=mysql_fetch_row(result2)))
    {
        printf("1111111\n");
        sprintf(str1,"[%d]----------[%d]:   %s",atoi(row2[0]),atoi(row2[1]),row2[2]);
        Send_pack(send_fd,VIEW_CHAT_HISTORY_APPLY,str1);
    }
    printf("[%d]查询了与[%d]的聊天记录\n",mes.sender,mes.recver);


}

void Shield_friend(int fd,char* buf)
{
    Relation_t relation;
    memcpy(&relation,buf,sizeof(relation));
    printf("server/ friend send:%d\n",relation.send);
    printf("server/ friend recv:%d\n",relation.recv);
    printf("server/ friend message:%s\n",relation.message);

    char buf_t[BUFSIZ];
    //更新这两个人的关系
    relation.relation=BLACK;
    sprintf(buf_t,"updata friend set status=2 where (uid=%d and fid=%d) or (uid=%d and fid=%d)",relation.send,relation.recv,relation.recv,relation.send);
    printf("buf_t:%s\n",buf_t);
    int ret=mysql_real_query(&mysql,buf_t,strlen(buf_t));
    if(ret)
    {
        Mysql_with_error(&mysql);
        printf("屏蔽好友失败\n");
    }
    printf("[%d]屏蔽了与[%d]的好友关系\n",relation.send,relation.recv);

    //获得发送者的端口号
    int send_fd=Get_connfd(relation.send);
    char str1[BUFSIZ];

    sprintf(str1,"你已经屏蔽了[%d]",relation.recv);
    Send_pack(send_fd,SHIELD_APPLY,str1);

}
void Unshield_friend(int fd,char* buf)
{
    Relation_t relation;
    memcpy(&relation,buf,sizeof(relation));
    printf("server/ friend send:%d\n",relation.send);
    printf("server/ friend recv:%d\n",relation.recv);
    printf("server/ friend message:%s\n",relation.message);

    char buf_t[BUFSIZ];
    //更新这两个人的关系
    relation.relation=BLACK;
    sprintf(buf_t,"updata friend set status=3 where (uid=%d and fid=%d) or (uid=%d and fid=%d)",relation.send,relation.recv,relation.recv,relation.send);
    printf("buf_t:%s\n",buf_t);
    int ret=mysql_real_query(&mysql,buf_t,strlen(buf_t));
    if(ret)
    {
        Mysql_with_error(&mysql);
        printf("解除屏蔽失败\n");
    }
    printf("[%d]成功解除了屏蔽与[%d]的好友关系\n",relation.send,relation.recv);

    //获得发送者的端口号
    int send_fd=Get_connfd(relation.send);
    char str1[BUFSIZ];

    sprintf(str1,"你已经成功解除屏蔽[%d]",relation.recv);
    Send_pack(send_fd,UNSHIELD_APPLY,str1);
}

//一起实现
//void Show_friend_status();
void View_friend_list(int fd,char* buf)
{
    Friend_t friend;
    memcpy(&friend,buf,sizeof(friend));

    printf("server/ friend list send:%d\n",friend.send);
    printf("server/ friend list recv:%d\n",friend.recv);
    printf("server/ friend list message:%s\n",friend.message);


    char str[BUFSIZ];
    sprintf(str,"select *from friend where (uid=%d or fid=%d)",friend.send,friend.recv);
    printf("str:%s\n",str);
    int ret=mysql_real_query(&mysql,str,strlen(str));
    if(ret)
    {
        Mysql_with_error(&mysql);
        printf("[%d]查询好友失败\n",friend.send);
    }
    int send_fd=Get_connfd(friend.send);
    int id;
    MYSQL_RES *result;  
    MYSQL_ROW  row;
    result=mysql_store_result(&mysql);
    while((row=mysql_fetch_row(result)))
    {
        if(atoi(row[0])==friend.send)
            id=atoi(row[1]);
        else
            id=atoi(row[0]);
    
        printf("id:%d\n",id);
        int status;
        server_list_t pos;
        List_ForEach(list_ser,pos)
        {
            if(pos->data.id==id)
                friend.status=ONLINE;
            else
                friend.status=DOWNLINE;
        }
        if(atoi(row[2])>=1)
        {
            if(friend.status==ONLINE)
            {
                sprintf(str,"[%d]     [%d]",id,friend.status);
                Send_pack(send_fd,VIEW_FRIEND_LIST_APPLY,str);
            }
            else
            {
                sprintf(str,"[%d]     [%d]",id,friend.status);
                Send_pack(send_fd,VIEW_FRIEND_LIST_APPLY,str);
            }
            
        }
    }
    printf("[%d]查询好友成功\n",friend.send);
}
    

void Create_group(int fd,char* buf)
{

    Group_t group;
    memcpy(&group,buf,sizeof(group));
    printf("server/ create group_name:%s",group.group_name);
    printf("server/ create group_id:%d",group.group_owner);
    printf("server/ create group_owner:%d",group.group_owner);
    printf("server/ create group_admin:%d",group.admin);


    char str[BUFSIZ];
    sprintf(str,"insert into groups values('%d','%s')",group.group_owner,group.group_name);
    printf("str:%s\n",str);
    int ret=mysql_real_query(&mysql,str,strlen(str));
    if(ret)
    {
        Mysql_with_error(&mysql);
        printf("注册群失败\n");
    }


    int send_fd=Get_connfd(group.group_owner);
    char str1[256];
    sprintf(str1,"群名[%s]----群号[%d]创建成功",group.group_name,group.group_owner);
    printf("str1:%s\n",str1);
    Send_pack(send_fd,CREAT_GROUP_APPLY,str1);

    memset(str,0,sizeof(str));
    //群号  群成员 群地位
    sprintf(str,"insert into group_member values('%d','%d','%d')",group.group_owner,group.group_owner,OWNER);
    printf("str:%s\n",str);
    ret=mysql_real_query(&mysql,str,strlen(str));
    if(ret)
    {
        Mysql_with_error(&mysql);
    }
    printf("[%d]注册群成功\n",group.group_owner);

   
}
void Add_group(int fd,char* buf)
{
    Relation_t relation;
    memcpy(&relation,buf,sizeof(relation));

    //先插入数据到 group_member
    //待审核 adopter 4
    char str[BUFSIZ];
    sprintf(str,"insert into group_member values('%d','%d','%d')",relation.recv,relation.send,ADOPTER);
    printf("str:%s\n",str);
    int ret=mysql_real_query(&mysql,str,strlen(str));
    if(ret)
    {
        Mysql_with_error(&mysql);
    }
    printf("[%d]请求加入群[%d]\n",relation.send,relation.recv);

    int send_fd=Get_connfd(relation.send);



    //查询是否已经是群成员
    memset(str,0,sizeof(str));
    sprintf(str,"select status from group_member where gid=%d && mid=%d",relation.recv,relation.send);
    printf("str:%s\n",str);
    ret=mysql_real_query(&mysql,str,strlen(str));
    if(ret)
    {
        Mysql_with_error(&mysql);
    }
    MYSQL_RES *result1;
    MYSQL_ROW  row1;
    result1=mysql_store_result(&mysql);
    while((row1=mysql_fetch_row(result1)))
    {
        if(atoi(row1[0])<=3)
        {
            char str[256];
            sprintf(str,"您已经是该群[%d]的群员\n",relation.recv);
            Send_pack(send_fd,GROUP_APPLY,str);
        }
        else if(atoi(row1[0])==4)
        {
            char str[256];
            sprintf(str,"您的申请正在待审核，请勿重复添加该群[%d]\n",relation.recv);
            Send_pack(send_fd,GROUP_APPLY,str);
        }
    }

    //查询是否存在群
    char str1[BUFSIZ];
    sprintf(str1,"select *from groups where gid=%d",relation.recv);
    printf("str1:%s\n",str1);
    ret=mysql_real_query(&mysql,str1,strlen(str1));
    if(ret)
    {
        Mysql_with_error(&mysql);
    }
    MYSQL_RES *result;
    MYSQL_ROW  row;
    result=mysql_store_result(&mysql);
    row=mysql_fetch_row(result);
    if(row==NULL)
    {
        char str[256];
        sprintf(str,"您申请的该群[%d]不存在\n",relation.recv);
        Send_pack(send_fd,GROUP_APPLY,str);
    }
    
    //查询管理人员
    //找到群主
    memset(str,0,sizeof(str));
    sprintf(str,"select mid from group_member where gid=%d and status=%d",relation.recv,OWNER);
    printf("str:%s\n",str);
    ret=mysql_real_query(&mysql,str,strlen(str));
    if(ret)
    {
        Mysql_with_error(&mysql);
    }
    Group_t group;
    MYSQL_RES *result2;
    MYSQL_ROW  row2;
    result2=mysql_store_result(&mysql);
    row2=mysql_fetch_row(result2);
    if(row2==NULL)
    {
        char str[256];
        sprintf(str,"您申请的该群[%d]不存在\n",relation.recv);
        Send_pack(send_fd,GROUP_APPLY,str);
    }
    group.group_owner=atoi(row2[0]);
    //群管理
    memset(str,0,sizeof(str));
    sprintf(str,"select mid from group_member where gid=%d and status=%d",relation.recv,ADMIN);
    printf("str:%s\n",str);
    ret=mysql_real_query(&mysql,str,strlen(str));
    if(ret)
    {
        Mysql_with_error(&mysql);
    }
    MYSQL_RES *result3;
    MYSQL_ROW  row3;
    result3=mysql_store_result(&mysql);
    row3=mysql_fetch_row(result3);
    if(row3==NULL)
    {
        printf("群[%d]暂时没有管理员\n",relation.recv);
    }
    printf("row3:%d\n",atoi(row3[0]));
    group.admin=atoi(row3[0]);


    printf("[%d]向群主[%d]发起了群申请\n",relation.send,group.group_owner);
    //群主处理
    char str2[256];
    sprintf(str2,"用户[%d]向你(群主[%d])发送了群申请",relation.send,group.group_owner);
    printf("str2:%s\n",str2);
    Send_connfd_pack(ADD_GROUP_APPLY,relation.send,group.group_owner,str2);

    printf("[%d]向群管理[%d]发送了群申请\n",relation.send,group.admin);
    char str3[256];
    sprintf(str3,"用户[%d]向你(群管理[%d])发送了群申请",relation.send,group.admin);
    printf("str3:%s\n",str3);
    Send_connfd_pack(ADD_GROUP_APPLY,relation.send,group.admin,str3);
}
void Add_group_accept(int fd,char* buf)
{
    Relation_t relation;
    memcpy(&relation,buf,sizeof(relation));
    printf("server/ group accpet send:%d\n",relation.send);//管理员
    printf("server/ group accpet recv:%d\n",relation.recv);//申请者
    printf("server/ group accpet message:%s\n",relation.message);

    char str1[BUFSIZ];
    char str2[BUFSIZ];
    if(strcmp(relation.message,"y")==0)
    {
        char buf[BUFSIZ];
        relation.relation=COMMON;
        sprintf(buf,"update group_member set status =%d where mid=%d ",relation.relation,relation.recv);
        printf("buf:%s\n",buf);
        int ret=mysql_real_query(&mysql,buf,strlen(buf));
        if(ret)
        {
            Mysql_with_error(&mysql);
        }
        printf("[%d]同意了[%d]的入群请求\n",relation.send,relation.recv);

        sprintf(str1,"[%d]通过了您的入群请求",relation.send);
        Send_pack_name(ADD_GROUP_ACCEPT_APPLY,relation.send,relation.recv,str1);//发给申请者

        sprintf(str2,"您已经拒绝了[%d]的入群请求",relation.recv);
        Send_pack_name(ADD_GROUP_ACCEPT_APPLY,relation.recv,relation.send,str2);//发给管理员
    }
    else
    {
        char buf[BUFSIZ];
        relation.relation=ADOPTER;
        sprintf(buf,"delete from group_member where (mid=%d and status=%d)",relation.recv,relation.relation);
        printf("buf:%s\n",buf);
        int ret=mysql_real_query(&mysql,buf,strlen(buf));
        if(ret)
        {
            Mysql_with_error(&mysql);
        }
        printf("[%d]拒绝了[%d]的入群请求\n",relation.send,relation.recv);

        memset(str1,0,sizeof(str1));
        sprintf(str1,"[%d]拒绝了您的入群请求",relation.send);
        Send_pack_name(ADD_FRIEND_ACCEPT_APPLY,relation.send,relation.recv,str1);//发给申请者

    }
}
void Withdraw_group(int fd,char* buf)
{
    Relation_t relation;
    memcpy(&relation,buf,sizeof(relation));
    

    char str[BUFSIZ];
    sprintf(str,"delete from group_member where (mid=%d and gid=%d)",relation.send,relation.recv);
    printf("str:%s\n",str);
    int ret=mysql_real_query(&mysql,str,strlen(str));
    if(ret)
    {
        Mysql_with_error(&mysql);
    }
        //查询群主
        Group_t group;
        group.group_owner=relation.recv;

        int send_fd=Get_connfd(group.group_owner);

        char mes[256];
        printf("[%d]退出了群聊[%d]\n",relation.send,relation.recv);
        sprintf(mes,"[%d]退出了群聊[%d]",relation.send,relation.recv);
        Send_pack(send_fd,WITHDRAW_GROUP_APPLY,mes);
  
        /*char str1[BUFSIZ];
        sprintf(str1,"select *from groups where gid=%d",relation.recv);
        printf("str1:%s\n",str1);
        ret=mysql_real_query(&mysql,str1,strlen(str1));
        if(ret)
        {
            Mysql_with_error(&mysql);
        }*/
    
        //如果群主解散
        if(relation.send==group.group_owner)
        {
            char str1[BUFSIZ];
            sprintf(str1,"delete from groups where gid=%d)",relation.recv);
            printf("str1:%s\n",str1);
            ret=mysql_real_query(&mysql,str1,strlen(str1));
            if(ret)
            {
                Mysql_with_error(&mysql);
            }
            char str2[256];
            sprintf(str2,"群[%d]已经解散",relation.recv);
            Send_pack(send_fd,DEL_GROUP_APPLY,str2);
        }
        
        //获得申请退群者的端口号
        int fd_t=Get_connfd(relation.send);
        memset(mes,0,sizeof(mes));
        sprintf(mes,"您已经退出了群聊[%d]\n",relation.recv);
        printf("mes:%s\n",mes);
        Send_pack(fd_t,WITHDRAW_GROUP_APPLY,mes);




}
//void View_group_member(int fd,char* buf);
void View_add_group(int fd,char* buf)
{
    Relation_t relation;
    memcpy(&relation,buf,sizeof(relation));

    char str[BUFSIZ];
    sprintf(str,"select *from group_member where gid=%d and status=2",relation.send);
    printf("str:%s\n",str);
    int ret=mysql_real_query(&mysql,str,strlen(str));
    if(ret)
    {
        Mysql_with_error(&mysql);
        printf("[%d]查询群信息失败\n",relation.send);
    }
    MYSQL_RES *result;  
    MYSQL_ROW  row;
    result=mysql_store_result(&mysql);


    Group_t group;
    while((row=mysql_fetch_row(result)))
    {
        group.group_owner=atoi(row[0]);
        group.admin=atoi(row[1]);

        char str1[BUFSIZ];
        sprintf(str1,"select *from groups where gid=%d",relation.send);
        printf("str1:%s\n",str1);
        ret=mysql_real_query(&mysql,str1,strlen(str1));
        if(ret)
        {
            Mysql_with_error(&mysql);
        }
        MYSQL_RES *result1;
        MYSQL_ROW  row1;
        result1=mysql_store_result(&mysql);
        row1=mysql_fetch_row(result1);
        strcpy(group.group_name,row[1]);
        
        char mes[256];
        sprintf(mes,"%d\t%d\t%d\t%s",group.group_owner,group.group_owner,group.admin,group.group_name);
        Send_pack(fd,VIEW_ADD_GROUP_APPLY,mes);
    }
    printf("[%d]查询群信息成功\n",relation.send);

}

void Group_chat(int fd,char* buf)
{
    Chat_message mes;
    memcpy(&mes,buf,sizeof(mes));
    printf("mes.send= %d\n",mes.sender);
    printf("mes.recv= %d\n",mes.recver);
    printf("mes.message= %s\n",mes.message);

//是否是群成员
    char str[BUFSIZ];
    sprintf(str,"select *from group_member where gid=%d and mid=%d",mes.recver,mes.sender);
    printf("str:%s\n",str);
    int ret=mysql_real_query(&mysql,str,strlen(str));
    if(ret)
    {
        Mysql_with_error(&mysql);
    }
    MYSQL_RES *result;  
    MYSQL_ROW  row;
    result=mysql_store_result(&mysql);
    row=mysql_fetch_row(result);
    if(row==NULL)
        Send_pack(fd,GROUP_CHAT,"你还不是该群成员");
    

    //先插入mysql
    char str1[BUFSIZ];
    //0未发送
    sprintf(str1,"insert into group_message values('%d','%d','%s','%d')",mes.sender,mes.recver,mes.message,0);

    printf("str1:%s\n",str1);
    ret=mysql_real_query(&mysql,str1,strlen(str1));
    if(ret)
    {
        Mysql_with_error(&mysql);
    }

    printf("[%d]对[%d]群聊聊天记录以及写入mysql\n",mes.sender,mes.recver);

    char str2[BUFSIZ];
    sprintf(str2,"select *from group_messgae where recv_name=%d",mes.recver);
    ret=mysql_real_query(&mysql,str2,strlen(str2));
    if(ret)
    {
        Mysql_with_error(&mysql);
    }
    MYSQL_RES *result1;  
    MYSQL_ROW  row1;
    result1=mysql_store_result(&mysql);
    row1=mysql_fetch_row(result1);
    
    Chat_message mes_t;
    mes_t.flag=GROUP_CHAT_APPLY;
    mes_t.sender=mes.recver;//发送者变成群

    char mes1[256];
    sprintf(mes1,"[%d]:%s",mes.sender,mes.message);

    //strcpy(mes_t.message,row[2]);
    char str3[BUFSIZ];
    while((row1=mysql_fetch_row(result1)))
    {
        if(atoi(row1[1])!=mes.sender)
        {
            mes_t.recver=atoi(row1[0]);
            memcpy(str3,&mes_t,sizeof(mes_t));
            int recv_fd=Get_connfd(atoi(row1[0]));
            printf("recv_fd:%d\n",recv_fd);
            printf("mes_t.flag:%d\n",mes_t.flag);
            printf("mes_t.sender:%d\n",mes_t.sender);
            printf("mes_t.recver:%d\n",mes_t.recver);
            printf("mes_t.mes:%s\n",mes_t.message);
            if(send(recv_fd,buf,sizeof(buf),0)<0)
            {
                my_err("send error!",__LINE__);
            }
            printf("[%d]正在群[%d]聊天\n",mes_t.sender,mes_t.recver);
        }
    }




}
void View_group_record(int fd,char* buf)
{
    Chat_message mes;
    memcpy(&mes,buf,sizeof(mes));

    char str[BUFSIZ];
    sprintf(str,"select *from group_member where (gid=%d and mid=%d)",mes.recver,mes.sender);
    printf("str:%s\n",str);
    int ret=mysql_real_query(&mysql,str,strlen(str));
    if(ret)
    {
        Mysql_with_error(&mysql);
    }
    MYSQL_RES *result;  
    MYSQL_ROW  row;
    result=mysql_store_result(&mysql);
    row=mysql_fetch_row(result);
    if(row==NULL)
    {
        Send_pack(fd,VIEW_GROUP_RECORD_APPLY,"你还不是群成员，请先添加群");
        printf("[%d]查询群聊天记录失败\n",mes.sender);
    }

    char str2[BUFSIZ];
    sprintf(str2,"select *from group_message where recv_name=%d",mes.recver);
    printf("str2:%s\n",str2);
    ret=mysql_real_query(&mysql,str2,strlen(str2));
    if(ret)
    {
        Mysql_with_error(&mysql);
    }

    MYSQL_RES *result1;
    MYSQL_ROW  row1;
    result1=mysql_store_result(&mysql);
    
    int send_fd=Get_connfd(mes.sender);
    char str1[256];
    //循环读取每一行数据
    while((row1=mysql_fetch_row(result1)))
    {
        printf("1111111\n");
        sprintf(str1,"[%d]在群[%d]:   %s",atoi(row1[0]),atoi(row1[1]),row1[2]);
        Send_pack(send_fd,VIEW_GROUP_RECORD_APPLY,str1);
    }
       printf("[%d]查询了他在群[%d]的聊天记录\n",mes.sender,mes.recver);
   

}

void Set_group_admin(int fd,char* buf)
{
    Group_leader leader;
    memcpy(&leader,buf,sizeof(leader));
    printf("server set flag:%d\n",leader.flag);
    printf("server set sender:%d\n",leader.sender);
    printf("server set recver:%d\n",leader.recver);
    printf("server set admin:%d\n",leader.admin);
    printf("server set message:%s\n",leader.message);

    char buff[BUFSIZ]; 
    sprintf(buff,"update group_member set status=2 where gid=%d and mid=%d",leader.recver,leader.admin);
    printf("buff:%s\n",buff);
    int ret=mysql_real_query(&mysql,buff,strlen(buff));
    if(ret)
    {
        Mysql_with_error(&mysql);
        printf("[%d]设置管理员[%d]失败\n",leader.sender,leader.admin);
    }
    printf("[%d]设置管理员[%d]成功\n",leader.sender,leader.admin);

    int send_fd=Get_connfd(leader.sender);
    char mes[256];
    sprintf(mes,"您已经成功设置[%d]为管理员",leader.admin);
    Send_pack(send_fd,SET_GROUP_ADMIN_APPLY,mes);
}
void Kick(int fd,char* buf)
{
    Group_leader leader;
    memcpy(&leader,buf,sizeof(leader));
    printf("server kick flag:%d\n",leader.flag);
    printf("server kick sender:%d\n",leader.sender);
    printf("server kick recver:%d\n",leader.recver);
    printf("server kick admin:%d\n",leader.admin);
    printf("server kick message:%s\n",leader.message);

    //先查询他是不是管理员
    char str[BUFSIZ];
    sprintf(str,"select mid from group_member where gid=%d and (status=1 ||status=2)",leader.recver);
    printf("str:%s\n",str);
    int ret=mysql_real_query(&mysql,str,strlen(str));
    if(ret)
    {
        Mysql_with_error(&mysql);
    }
    int send_fd=Get_connfd(leader.sender);
    MYSQL_RES *result;  
    MYSQL_ROW  row;
    result=mysql_store_result(&mysql);
    row=mysql_fetch_row(result);
    if(row==NULL)
    {
        printf("[%d]不是群管理或群主,操作无效\n",leader.sender);
        char mes[256];
        sprintf(mes,"您不是该群[%d]群管理或群主，无法操作",leader.recver);
        Send_pack(send_fd,KICK_APPLY,mes);
    }

    char buff[BUFSIZ];
    sprintf(buff,"delete from group_meber where gid=%d and mid=%d",leader.recver,leader.admin);
    printf("buff:%s\n",buff);
    ret=mysql_real_query(&mysql,buff,strlen(buff));
    if(ret)
    {
        Mysql_with_error(&mysql);
        printf("[%d]踢出[%d]失败\n",leader.sender,leader.admin);
    }
    printf("[%d]踢出[%d]成功\n",leader.sender,leader.admin);
    char mes[256];
    sprintf(mes,"您踢出群成员[%d]成功",leader.admin);
    Send_pack(send_fd,KICK_APPLY,mes);

    memset(&mes,0,sizeof(mes));
    sprintf(mes,"您已经被管理员[%d]踢出群[%d]",leader.admin,leader.recver);
    Send_pack(send_fd,KICK_APPLY,mes);

}

void Send_file(int fd,char* buf)
{
    char *str=(char*)malloc(sizeof(file));
    memcpy(str,buf,sizeof(file));
    pthread_t recv_file_id;
    pthread_create(&recv_file_id,NULL,Recv_file,(void*)str);
}
void *Recv_file(void *arg)
{
    char *buf=(char*)arg;
    file file_t;
    memcpy(&file_t,buf,sizeof(file_t));

    printf("name=%s\n",file_t.file_name);
    printf("recv=%d\n",file_t.recver);
    printf("send=%d\n",file_t.sender);
    printf("filesize=%d\n",file_t.file_size);

    //得到好友套接字
    int recv_fd=Get_connfd(file_t.recver);
    //向好友转发
    if(send(recv_fd,buf,sizeof(buf),0)<0)
    {
        my_err("send file error",__LINE__);
    }
    free(buf);
    return NULL;
}
void Connect_mysql()
{
    mysql_init(&mysql);
    //初始化数据库
    mysql_library_init(0,NULL,NULL);
    if(!mysql_real_connect(&mysql,"47.94.14.45","Linux_7136","18861757136","chat_room_7136",0,NULL,0))
    {
        sys_err("connect error!",__LINE__);
    }
    if(mysql_set_character_set(&mysql,"utf8"))
    {
        sys_err("set error!",__LINE__);
    }
    printf("连接MYSQL数据库成功!\n");
}

void Close_mysql(MYSQL mysql)
{
    mysql_close(&mysql);
    //mysql_free_result(result);
    mysql_library_end();
    printf("MYSQL数据库关闭!\n");
}

/*
void Read_from_mysql()
{

    Server_user();//读取用户信息
    //Server_friend();
    //Server_group();
    //Server_group_member();
}
*/
void my_err(const char* err_string,int line)
{
    fprintf(stderr,"line:%d",line);
    perror(err_string);
    exit(1);
}
void Clear_buf()
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

void Send_pack(int fd,int flag,char* buf)
{
    char str[BUFSIZ];
    message mes;

    mes.flag=flag;
    strcpy(mes.message,buf);
    printf("server send message:%s\n",mes.message);
    memcpy(str,&mes,sizeof(mes));
    
    printf("server send message:%s\n",mes.message);
    printf("server send flag:%d\n",mes.flag);
    if(send(fd,str,sizeof(str),0)<0)
    {
        my_err("send error!",__LINE__);
        close(fd);
    }
}
