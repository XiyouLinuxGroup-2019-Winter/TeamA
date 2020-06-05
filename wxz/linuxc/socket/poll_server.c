#include "wrang.h"
#define SERV_PORT 8000
int main()
{
    int i,j,n,ret;

    int maxi;

    int lfd,cfd;
    int sockfd;

    char buf[BUFSIZ];
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

    client[0].fd=lfd;
    client[0].events=POLL_IN;
    
    for(i=1;i<1024;i++)
    {
        client[i].fd=-1;
    }

    maxi=0;

    while(1)
    {
        n=poll(client,maxi+1,-1);
        if(client[0].revents & POLL_IN)
        {
            cli_addr_len=sizeof(cli_addr);
            cfd=Accept(lfd,(struct sockaddr*)&cli_addr,&cli_addr_len);
            for(i=1;i<1024;i++)
            {
                if(client[i].fd<0)
                {
                    client[i].fd=cfd;
                    break;
                }
            }
            if(i==1024)
            {
                sys_err("too many clinets");
            }

            client[i].events=POLL_IN;

            if(i>maxi)
                maxi=i;

            if(--n<=0)
                continue;
        }
        for(i=1;i<=maxi;i++)
        {
            if((sockfd=client[i].fd)<0)
                continue;
            if(client[i].revents & POLL_IN)
            {
                ret=Read(sockfd,buf,sizeof(buf));
                if(ret<0)
                {
                    if(errno==ECONNRESET)
                    {
                        close(sockfd);
                        client[i].fd=-1;
                    }
                
                    else
                    {
                        sys_err("read error");
                    }
                }
                else if(ret==0)
                {
                    close(sockfd);
                    client[i].fd=-1;
                }
                else
                {
                    for(j=0;j<ret;j++)
                        buf[j]=toupper(buf[j]);
                        Write(sockfd,buf,ret);
                }
                if(--n<=0)
                    break;
            }
        }
    }
}