#include "wrang.h"
#define SERV_PORT 8000
int main()
{
    int lfd;
    char buf[BUFSIZ];
    struct sockaddr_in serv_addr,clie_addr;
    char str[INET_ADDRSTRLEN];
    int i,n;
    socklen_t clie_addr_len;

    lfd=socket(AF_INET,SOCK_DGRAM,0);

    bzero(&serv_addr,sizeof(serv_addr));
    serv_addr.sin_family=AF_INET;
    serv_addr.sin_port=htons(SERV_PORT);
    serv_addr.sin_addr.s_addr=htonl(INADDR_ANY);
    


    bind(lfd,(struct sockaddr*)&serv_addr,sizeof(serv_addr));
    listen(lfd,128);

    while(1)
    {
        clie_addr_len=sizeof(clie_addr);
        n=recvfrom(lfd,buf,BUFSIZ,0,(struct sockaddr*)&clie_addr,&clie_addr_len);

        for(int i=0;i<n;i++)
            buf[i]=toupper(buf[i]);
        n=sendto(lfd,buf,n,0,(struct sockaddr*)&clie_addr,clie_addr_len);
    }
   close(lfd);
}
