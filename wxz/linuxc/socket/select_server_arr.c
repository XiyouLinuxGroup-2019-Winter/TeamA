#include "wrang.h"
#define SERV_PORT 6666
int main()
{
    int i,j,n,ret,maxi;

    int maxfd=0;

    int lfd,cfd[FD_SETSIZE];
    int connfd,sockfd;

    char buf[BUFSIZ],str[INET_ADDRSTRLEN];//16
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

    fd_set rset,allset;
    maxfd=lfd;
    maxi=-1;
    for(i=0;i<FD_SETSIZE;i++)
        cfd[i]=-1;
    FD_ZERO(&allset);//清空监听集合
    FD_SET(lfd,&allset);//将待监听fd添加到监听集合

    while(1)
    {
        rset=allset;
        n=select(maxfd+1,&rset,NULL,NULL,NULL);
        if(n<0)
        {
            sys_err("select error");
        }
        if(FD_ISSET(lfd,&rset))//lfd满足监听的读事件
        {
            cli_addr_len=sizeof(cli_addr);
            connfd=Accept(lfd,(struct sockaddr*)&cli_addr,&cli_addr_len);//建立链接---不会阻塞

            for(i=0;i<FD_SETSIZE;i++)
            {
                if(cfd[i]<0)
                {
                    cfd[i]=connfd;
                    break;
                }
            }

            if(i==FD_SETSIZE)
            {
                fputs("too many clinets\n",stderr);
                exit(1);
            }

            FD_SET(connfd,&allset);//将新产生的fd,添加到监听集合中,监听数据读事件
            if(connfd>maxfd)
                maxfd=connfd;
            
            if(i>maxi)
                maxi=i;
                
            if(--n==0)
                continue;//说明select只返回一个,并且是lfd,后续执行无须执行
        }
        for(i=0;i<=maxi;i++)
        {
            if((sockfd=cfd[i])<0)
                continue;
            if(FD_ISSET(sockfd,&rset))
            {
                ret=Read(sockfd,buf,sizeof(buf));
                if(ret==0)
                {
                    close(sockfd);
                    FD_CLR(sockfd,&allset);
                    cfd[i]=-1;
                }
                else if(ret>0)
                { 
                    for(j=0;j<ret;j++)
                        buf[j]=toupper(buf[j]);
                    write(sockfd,buf,ret);
                    write(STDOUT_FILENO,buf,ret);
                }
                if(--n==0)
                    break;
            }
        }
    }
    close(lfd);
}