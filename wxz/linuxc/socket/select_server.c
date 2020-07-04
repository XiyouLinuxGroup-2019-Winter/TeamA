#include "wrang.h"
#define SERV_PORT 6666
int main()
{
    int i,j,n,ret;

    int maxfd=0;

    int lfd,cfd;

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

    fd_set rset,allset;
    maxfd=lfd;
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
            cfd=Accept(lfd,(struct sockaddr*)&cli_addr,&cli_addr_len);//建立链接---不会阻塞

            FD_SET(cfd,&allset);//将新产生的fd,添加到监听集合中,监听数据读事件
            if(maxfd<cfd)
                maxfd=cfd;
            
            if(n==1)
                continue;//说明select只返回一个,并且是lfd,后续执行无须执行
        }
        for(i=lfd+1;i<=maxfd;i++)
        {
            if(FD_ISSET(i,&rset))
            {
                ret=Read(i,buf,sizeof(buf));
                if(ret==0)
                {
                    close(i);
                    FD_CLR(i,&allset);
                }
                else if(ret>0)
                {    
                    for(j=0;j<ret;j++)
                        buf[j]=toupper(buf[j]);
                    write(i,buf,ret);
                    write(STDOUT_FILENO,buf,ret);
                }
            }
        }
    }
    close(lfd);
}