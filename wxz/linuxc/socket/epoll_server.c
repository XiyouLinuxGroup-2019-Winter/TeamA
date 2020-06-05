#include "wrang.h"
#define SERV_PORT 8000
int main()
{
    int i,j,n,ret;

    int lfd,cfd;
    int sockfd;

    char buf[BUFSIZ];
    struct sockaddr_in cli_addr,serv_addr;
    socklen_t cli_addr_len;

    lfd=socket(AF_INET,SOCK_STREAM,0);

    int opt=1;
    setsockopt(lfd,SOL_SOCKET,SO_REUSEADDR,(void*)&opt,sizeof(opt));
    bzero(&serv_addr,sizeof(serv_addr));
    serv_addr.sin_family=AF_INET;
    serv_addr.sin_port=htons(SERV_PORT);
    serv_addr.sin_addr.s_addr=htonl(INADDR_ANY);

    bind(lfd,(struct sockaddr*)&serv_addr,sizeof(serv_addr));
    Listen(lfd,128);

    int epfd=epoll_create(1024);
    struct epoll_event tep,ep[1024];
    tep.events=EPOLLIN;
    tep.data.fd=lfd;

    epoll_ctl(epfd,EPOLL_CTL_ADD,lfd,&tep);

    while(1)
    {
        ret=epoll_wait(epfd,ep,1024,-1);
        for(i=0;i<ret;i++)
        {
            if(ep[i].data.fd==lfd)
            {
                cli_addr_len=sizeof(cli_addr);
                cfd=Accept(lfd,(struct sockaddr*)&cli_addr,&cli_addr_len);
                tep.events=EPOLLIN;
                tep.data.fd=lfd;
                epoll_ctl(epfd,EPOLL_CTL_ADD,cfd,&tep);
            }
            else
            {
                sockfd=ep[i].data.fd;
                n=Read(sockfd,buf,sizeof(buf));
                if(n<0)
                {
                    epoll_ctl(epfd,EPOLL_CTL_DEL,sockfd,NULL);
                    close(sockfd);
                }
                if(n==0)
                {
                    epoll_ctl(epfd,EPOLL_CTL_DEL,sockfd,NULL);
                    close(sockfd);
                }
                else
                {
                    for(j=0;j<n;j++)
                        buf[j]=toupper(buf[j]);
                    write(sockfd,buf,n);
                }
            }
        }
    }
    close(lfd);
    close(epfd);
}
