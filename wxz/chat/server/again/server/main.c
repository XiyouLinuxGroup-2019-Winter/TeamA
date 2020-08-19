#include "chat.h"
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
                bzero(&recv_t,sizeof(PACK));
                int n=recv(ep[i].data.fd,&recv_t,sizeof(PACK),MSG_WAITALL);
                recv_t.data.send_fd=ep[i].data.fd;

                
                if(n<0)
                {
                    close(ep[i].data.fd);
                    sys_err("recv error!",__LINE__);
                    continue;
                }
                else if(n==0)
                {
                    
                    
                    tep.data.fd=ep[i].data.fd;
                    printf("客户端:%d连接断开\n",tep.data.fd);
                   
                    epoll_ctl(epfd,EPOLL_CTL_DEL,ep[i].data.fd,&tep);
                    close(ep[i].data.fd);
                    continue;
                }


                /*Recv_pack_message(recv_t);
                printf("send_name  :%s\n",recv_t.data.send_name);
                printf("recv_name  :%s\n",recv_t.data.recv_name);
                printf("message  :%s\n",recv_t.data.message);
                printf("send_fd  :%d\n",recv_t.data.send_fd);*/


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
void Register(PACK* pack_t)
{
    char buf[BUFSIZ];

    server_list_t pos=list_ser;
    pos=Find_server_user(pack_t->data.send_name);

    if(pos==NULL)
    {
        pack_t->data.other_message=1;
        //添加用户
        server_user_node_t *new;
        new=(server_user_node_t*)malloc(sizeof(server_user_node_t));
        strcpy(new->data.username,pack_t->data.send_name);
        strcpy(new->data.password,pack_t->data.message);
        new->data.online=DOWNLINE;
        new->data.friend_num=0;
        new->data.group_num=0;
        List_AddTail(list_ser,new);
        user_num++;

        
        printf("regist success!\n");
        printf("username:%s\n",new->data.username);
        printf("passward:%s\n",new->data.password);
        printf("user_num:%d\n\n",user_num);
        printf("online:%d\n",new->data.online);

        memset(buf,0,sizeof(buf));
        sprintf(buf,"insert into account values(NULL,'%s','%s','%d')",pack_t->data.send_name,pack_t->data.message,new->data.online);
        printf("buf:%s\n",buf);
        int ret=mysql_real_query(&mysql,buf,strlen(buf));
        if(ret)
        {
            printf("insert error:%s\n",mysql_error(&mysql));
        }

        //注册成功
        pack_t->data.other_message=1;
    }
    else 
        //该用户已存在
        pack_t->data.other_message=0;
    
    //包信息赋值
    strcpy(pack_t->data.recv_name,pack_t->data.send_name);
    strcpy(pack_t->data.send_name,"server");
    pack_t->data.recv_fd=pack_t->data.send_fd;
    pack_t->data.send_fd=lfd;
    
    //发送包
    Send_pack(pack_t);
    free(pack_t);

}               
void Login(PACK* pack_t)
{
    int id=0;
    char login_flag[10];
    
    server_list_t pos;
    
    pos=Find_server_user(pack_t->data.send_name);
    
    if(pos==NULL)
    {
        //没有注册
        pack_t->data.other_message=2;
        printf("========\n");
    }
    else if(pos->data.online==ONLINE)
    {
        //已登录
        printf("已经登陆\n");
        //发送信息
        strcpy(pack_t->data.send_name,"server");
        pack_t->data.other_message=3;
        pack_t->data.recv_fd=pack_t->data.send_fd;
        pack_t->data.send_fd=lfd;
        
        Send_pack(pack_t);
        return ;
    }
    else if(strcmp(pos->data.password,pack_t->data.message)==0)
    {
        //登录成功
        pack_t->data.other_message=1;

        pos->data.connfd=pack_t->data.send_fd;
        printf("statu:    %d\n",pos->data.online); 
        pos->data.online=ONLINE;
        printf("\n********登录**********\n");
        printf("%s 登陆成功\n", pos->data.username);
        printf("statu:    %d\n",pos->data.online); 
        printf("connfd:%d\n\n",pos->data.connfd);
        
        //修改状态
        //usleep(10000);
        
    }
    else
    {
        //密码不匹配
        pack_t->data.other_message=0; 
    }
    
    
    strcpy(pack_t->data.recv_name,pack_t->data.send_name);
    strcpy(pack_t->data.send_name,"server");
    pack_t->data.recv_fd=pack_t->data.send_fd;
    pack_t->data.send_fd=lfd;
    
    Send_pack(pack_t);
    
    sleep(1);
    
    free(pack_t);
}



void Insert(User *pNew)//插入用户信息链表 
{
    User *t = pHead;
    while(t && t->next != NULL)
        t = t->next;
    t->next = pNew;
    pNew->next = NULL;
}

void Insert_R(Relation *pNew)//插入好友关系链表 
{
    Relation *t = pStart;
    while(t && t->next != NULL)
        t = t->next;
    t->next = pNew;
    pNew->next = NULL;
}

void Insert_RC(Recordinfo *pNew)//插入消息记录链表 
{
    Recordinfo *p = pRec;
    while(p && p->next != NULL)
        p = p->next;
    p->next = pNew;
    pNew->next = NULL;
}
