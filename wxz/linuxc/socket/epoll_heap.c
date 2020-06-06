#include "wrang.h"
#define SERV_PORT 8080

void recvdata(int fd,int events,void* arg);
void senddata(int fd,int events,void* arg);
struct myevent_s{
    int fd;
    int events;
    void* arg;
    void (*call_back)(int fd,int events,void* arg);
    int status;
    char buf[BUFSIZ];
    int len;
    long last_active;
};
int epfd;
struct myevent_s g_events[1025];

//eventset(&g_events[1024],lfd,acceptconnet,&g_events[1024]);
void eventset(struct myevent_s* ev,int fd,void (*call_back)(int,int,void*),void* arg)
{
    ev->fd=fd;
    ev->call_back=call_back;
    ev->events=0;
    ev->arg=arg;
    ev->status=0;
    memset(ev->buf,0,sizeof(ev->buf));
    ev->len=0;
    ev->last_active=time(NULL);
}

//eventadd(epfd,EPOLLIN,&g_events[1024])
void eventadd(int epfd,int events,struct myevent_s* ev)
{
    struct epoll_event epv;
    int op;
    epv.data.ptr=ev;
    epv.events=ev->events=events;
    if(ev->status==0)
    {
        op=EPOLL_CTL_ADD;
        ev->status=1;
    }
    
    epoll_ctl(epfd,op,ev->fd,&epv);

}
int main(int argc,char *argv[])
{
    unsigned short port=SERV_PORT;
    if(argc==2)
        port=atoi(argv[1]);
    
    epfd=epoll_create(1025);
    initsocket(epfd,port);

    struct epoll_event events[1025];
    int i;
    
    int n=epoll_wait(epfd,events,1025,1000);

    for(i=0;i<n;i++)
    {
        struct myevent_s *ev=(struct myevent_s*)events[i].data.ptr;
        if((events[i].events &EPOLLIN)&&(ev->events &EPOLLIN))
        {
            //void (*call_back)(int fd,int events,void* arg);
            ev->call_back(ev->fd,events[i].events,ev->arg);
        }
        if((events[i].events &EPOLLOUT)&&(ev->events &EPOLLOUT))
        {
            //void (*call_back)(int fd,int events,void* arg);
            ev->call_back(ev->fd,events[i].events,ev->arg);
        }
    }
}
void initsocket(int epfd,short port)
{
    int lfd;
    lfd=Socket(AF_INET,SOCK_STREAM,0);
    fcntl(lfd,F_SETFL,O_NONBLOCK);

    struct sockaddr_in serv_addr;

    memset(&serv_addr,0,siezof(serv_addr));
    serv_addr.sin_family=AF_INET;
    serv_addr.sin_port=htons(SERV_PORT);
    serv_addr.sin_addr.s_addr=htonl(INADDR_ANY);

    bind(lfd,(struct sockaddr*)&serv_addr,sizeof(serv_addr));
    Listen(lfd,128);

    //void eventset(struct myevent_s* ev,int fd,void (*call_back)(int,int,void*),void *arg)
    eventset(&g_events[1024],lfd,acceptconnet,&g_events[1024]);

    eventadd(epfd,EPOLLIN,&g_events[1024]);
}

void acceptconnet(int lfd,int events,void* arg)
{
    struct sockaddr_in clin_addr;
    socklen_t clin_addr_len;
    clin_addr_len=sizeof(clin_addr);
    int cfd,i;

    cfd=accept(lfd,(struct sockaddr*)&clin_addr,&clin_addr_len);

    do
    {
        for(i=0;i<1024;i++)
        {
            if(g_events[i].status==0)
                break;
        }
        int flag=0;
        flag=fcntl(cfd,F_SETFL,O_NONBLOCK);

        eventset(&g_events[i],cfd,recvdata,&g_events[i]);
    } while (0);
    
}
