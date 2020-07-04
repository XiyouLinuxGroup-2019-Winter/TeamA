#include "wrang.h"
#define SERV_PORT 9000
int main()
{
    int i,j;
    int lfd,cfd;
    int efd;
    int flag;

    char buf[10];
    struct sockaddr_in cli_addr,serv_addr;
    socklen_t cli_addr_len;
    struct pollfd client[1024];

    lfd=socket(AF_INET,SOCK_STREAM,0);

    int opt=1;
    setsockopt(lfd,SOL_SOCKET,SO_REUSEADDR,(void*)&opt,sizeof(opt));
    bzero(&serv_addr,sizeof(serv_addr));
    serv_addr.sin_family=AF_INET;
    serv_addr.sin_port=htons(SERV_PORT);
    serv_addr.sin_addr.s_addr=htonl(INADDR_ANY);

    bind(lfd,(struct sockaddr*)&serv_addr,sizeof(serv_addr));
    Listen(lfd,128);

    struct epoll_event event;
    struct epoll_event resevent[10];
    int ret,len;

    efd=epoll_create(10);
    event.events=EPOLLIN | EPOLLET;//ET
    

    cli_addr_len=sizeof(cli_addr);

    cfd=Accept(lfd,(struct sockaddr*)&cli_addr,&cli_addr_len);

    flag=fcntl(cfd,F_GETFL);
    flag|=O_NONBLOCK;
    fcntl(cfd,F_SETFL,flag);


    event.data.fd=cfd;
    epoll_ctl(efd,EPOLL_CTL_ADD,cfd,&event);

    while(1)
    {
        ret=epoll_wait(efd,resevent,10,-1);
        printf("ret:%d\n",ret);
        if(resevent[0].data.fd==cfd)
        {
            while((len=read(cfd,buf,5))>0)
                write(STDOUT_FILENO,buf,len);
        }
    }

}