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

                
                /*if(ep[i].events & EPOLLRDHUP)
                {
                    server_list_t pos;
                    //使用指针pos依次遍历链表list_ser

                    List_ForEach(list_ser,pos)
                    {
                        if(pos->data.connfd==ep[i].data.fd)
                        {
                            List_DelNode(pos);
                            printf("下线删除成功\n");
                            break;
                        }
                    }
                   // tep.data.fd=ep[i].data.fd;
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
                    close(ep[i].data.fd);
                    continue;
                }


                /*Recv_pack_message(recv_t);*/
                printf("send_name  :%s\n",recv_t.data.send_name);
                printf("recv_name  :%s\n",recv_t.data.recv_name);
                printf("message  :%s\n",recv_t.data.message);
                printf("send_fd  :%d\n",recv_t.data.send_fd);


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
    MYSQL_RES *result;
    MYSQL_ROW row;
    MYSQL_FIELD *field;
    int ret, i, j;
    char flag_register[10];

    server_user_t *new;
    new=(server_user_t *)malloc(sizeof(server_user_t));
    strcpy(new->username,pack_t->data.send_name);
    strcpy(new->password,pack_t->data.message);
    new->online=DOWNLINE;

    

    char buf[BUFSIZ];
    memset(buf, 0,sizeof(buf));
    sprintf(buf,"select username from account where username='%s'",new->username);
    ret=mysql_real_query(&mysql, buf,strlen(buf)); //查询语句
    if(ret)
    {
        printf("select error:%s\n",mysql_error(&mysql));
    }
    else
    {
        result=mysql_store_result(&mysql); 

        //检索所有的行，
        if(mysql_num_rows(result)==0)
        {
            memset(buf, 0, sizeof(buf));
            printf("没有此人可以注册此账户\n");
            sprintf(buf, "insert into account values('%s','%s','%d')", new->username, new->password,new->online);
            printf("%s\n", buf);

            ret=mysql_real_query(&mysql, buf,strlen(buf)); //查询语句

            if(ret)
            {
                printf("select error:%s\n",mysql_error(&mysql));
                flag_register[0]='0';
                Send_pack_type(pack_t->data.send_fd,REGISTER,pack_t,flag_register);
                return ;
            }
            flag_register[0]='1';
            Send_pack_type(pack_t->data.send_fd,REGISTER,pack_t,flag_register);
        }
        else if(mysql_num_rows(result)>0)
        {
            printf("该账户已存在，请提示重新输入\n");
            flag_register[0]='0';
            Send_pack_type(pack_t->data.send_fd,REGISTER,pack_t,flag_register);
        }
        mysql_free_result(result);
    }

}               
void Login(PACK* pack_t)
{
    MYSQL_RES *result;
    MYSQL_ROW row;
    MYSQL_FIELD *field;
    int ret, i, j;
    char flag_login[10];
    

    char buf[BUFSIZ];
    memset(buf, 0,sizeof(buf));
    sprintf(buf,"select username from account where username='%s' and password='%s'",pack_t->data.send_name,pack_t->data.recv_name);
    ret=mysql_real_query(&mysql, buf,strlen(buf)); //查询语句
    if(ret)
    {
        printf("select error:%s\n",mysql_error(&mysql));
    }
    
    result=mysql_store_result(&mysql); 
    int rows=mysql_num_row(result);
    //行
    PACK* send_pack;
    send_pack=(PACK*)malloc(sizeof(PACK));
    if(rows==0)
    {
        printf("没有找到要登录的账号\n");
        send_pack->flag=LOGIN;
        send_pack->data.recv_fd=pack_t->data.send_fd;
        send_pack->data.massge[0]='0';

        if(send(pack_t->data.recv_fd,send_pack,sizeof(PACK),0)<0)
            my_err("send error", __LINE__);
    }
    else if(rows>0)
    {
        printf("登录成功\n");
            
        account_node_t* new;
        new=(account_node_t*)malloc(sizeof(account_node_t));
        new->data.connfd=pack_t->data.recv_fd;
           

        int rows=mysql_num_rows(result));
        printf("%d\n",rows);
        j=mysql_num_fields(result);                                //获取 列数
        while((row=mysql_fetch_row(result)))
        { 

            strcpy(new->data.username,pack_t->data.send_name);

            for(i=0;i<j;i++)
            {
                printf("socket_id:%s\n",row[i]);
                new->data.socket_id= atoi(row[i]);
            }
            List_AddHead(list_ser,new);
            printf("\n");
        }
        if(mysql_errno(&mysql))
        {
            fprintf(stderr, "Retrive error:%s\n", mysql_error(&mysql));
        }


    
           

           
        }
        mysql_free_result(result);
    }
}