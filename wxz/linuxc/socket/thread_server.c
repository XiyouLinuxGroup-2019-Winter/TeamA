#include "wrang.h"

#define SRV_PORT 8000
#define MAXLINE 8192

struct s_info
{
    struct sockaddr_in cliaddr;
    int clinfd;
};

void *do_work(void* arg)
{
    int n,i;
    struct s_info *ts=(struct s_info*)arg;
    char buf[BUFSIZ];
    char str[INET_ADDRSTRLEN];

    while(1)
    {
        n=Read(ts->clinfd,buf,sizeof(buf));
        if(n==0)
        {
            break;
        }
        for(i=0;i<n;i++)
            buf[i]=toupper(buf[i]);

        Write(STDOUT_FILENO,buf,n);
        Write(ts->clinfd,buf,n);
    }
    close(ts->clinfd);

    return (void*)0;
} 

int main()
{
    int lfd,cfd;
    int ret;
    int i;
    pid_t pid;
    struct s_info ts[256];
    pthread_t tid;

    lfd=Socket(AF_INET,SOCK_STREAM,0);
    struct sockaddr_in servaddr,cliaddr;

    socklen_t cliaddr_len;
    char buf[BUFSIZ];

    //memset(&srv_addr,0,sizeof(srv_addr));
    bzero(&servaddr,sizeof(servaddr));

    servaddr.sin_family=AF_INET;
    servaddr.sin_port=htons(SRV_PORT);
    servaddr.sin_addr.s_addr=htonl(INADDR_ANY);


    Bind(lfd,(struct sockaddr*)&servaddr,sizeof(servaddr));

    Listen(lfd,128);
    
    cliaddr_len=sizeof(cliaddr);

    while(1)
    {
        cfd=Accept(lfd,(struct sockaddr*)&cliaddr,&cliaddr_len);
        ts[i].cliaddr=cliaddr;
        ts[i].clinfd=cfd;

        pthread_create(&tid,NULL,do_work,(void*)&ts[i]);
        pthread_detach(tid);
        i++;
    }
}