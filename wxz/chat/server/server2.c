#include "server.h"
#include "pthreadpool.h"
#include "common.h"
#include "prest.h"
int main()
{
    int sys_log;


    Read_from_mysql();

    printf("线程池启动\n");
    pool_init(MAX_THREAD_NUM);
    printf("线程池启动成功!\n");
    sleep(2);


    Init_socket();

    Connect_mysql(&mysql);

    Close_mysql(&mysql);
    pool_destroy();

}
void Init_socket()
{
    //初始化链表list。链表为带头结点的双向循环链表
    List_Init(list_ser,server_user_node_t);
  
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

    epfd=epoll_create(1024);
    struct epoll_event tep,ep[1024];
    tep.events=EPOLLIN;
    tep.data.fd=lfd;
    epoll_ctl(epfd,EPOLL_CTL_ADD,lfd,&tep);

    while(1)
    {
        ret=epoll_wait(epfd,ep,1024,-1);
        for(i=0;i<ret;i++)
        {
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
                int n=recv(ep[i].data.fd,&recv_t,sizeof(PACK),0);
                recv_t.data.send_fd=events[i].data.fd;

                Recv_pack_message(recv_t);

                if(n<0)
                {
                    close(ep[i].data.fd);
                    sys_err("接收错误!",__LINE__);
                    continue;
                }
                else if(n==0)
                {
                    server_list_t pos;
                    //使用指针pos依次遍历链表list_ser
                    List_ForEach(list_ser,pos)
                    {
                        if(pos->data.socket_id==ep[i].data.fd)
                        {
                            List_DelNode(pos);
                            printf("%s downline\n",pos->data.username);
                            break;
                        }
                    }
                    printf("客户端连接断开\n");
                    tep.data.fd=ep[i].data.fd;
                    epoll_ctl(epfd,EPOLL_CTL_DEL,ep[i].data.fd,&tep);
                    close(ep[i].data.fd);
                    continue;
                }

                PACK *recv_pack_t;
                recv_pack_t=(recv_pack_t*)malloc(sizeof(PACK));
                memcpy(recv_pack,&recv_t,sizeof(PACK));

                threadpool_add(work,(void*)recv_pack_t);

               
            }
            
        }
    }
    free(pack_t);
    close(epfd);
    close(lfd);
}