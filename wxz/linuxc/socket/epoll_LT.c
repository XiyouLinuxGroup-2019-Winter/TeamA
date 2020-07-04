#include "wrang.h"
int main()
{
    int i,j;
    int pfd[2];
    pid_t pid;
    char buf[10],ch='a';
    pipe(pfd);

    int efd;
    pid=fork();
    if(pid==0)
    {
        close(pfd[0]);//读端
        while(1)
        {
            for(i=0;i<5;i++)
                buf[i]=ch;
            buf[i-1]='\n';
            //aaaa\n
            ch++;
            for(;i<10;i++)
                buf[i]=ch;
            //bbbb\n
            buf[i-1]='\n';
            ch++;
            //aaaa\nbbbb\n
            write(pfd[1],buf,sizeof(buf));
            sleep(5);
        }
        close(pfd[1]);
    }
    else if(pid>0)
    {
        struct epoll_event event;
        struct epoll_event resevent[10];
        int ret,len;

        close(pfd[1]);

        efd=epoll_create(10);
        event.events=EPOLLIN;
        event.data.fd=pfd[0];
        epoll_ctl(efd,EPOLL_CTL_ADD,pfd[0],&event);

        while(1)
        {
            ret=epoll_wait(efd,resevent,10,-1);
            printf("ret:%d\n",ret);
            if(resevent[0].data.fd==pfd[0])
            {
                len=read(pfd[0],buf,5);
                write(STDOUT_FILENO,buf,len);
            }
        }
        close(pfd[0]);
        close(efd);
    }
}