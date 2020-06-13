#include "wrang.h"
#define SERV_PORT 8000
int main()
{
    int cfd;
    
    int n,i;
    char buf[BUFSIZ];
    struct sockaddr_in serv_addr;

    cfd=socket(AF_INET,SOCK_DGRAM,0);

    serv_addr.sin_family=AF_INET;
    serv_addr.sin_port=htons(SERV_PORT);
    inet_pton(AF_INET,"127.0.0.1",&serv_addr.sin_addr.s_addr);
   
    

    bind(cfd,(struct sockaddr*)&serv_addr,sizeof(serv_addr));

    while(fgets(buf,BUFSIZ,stdin)!=NULL)
    {
        n=sendto(cfd,buf,strlen(buf),0,(struct sockaddr*)&serv_addr,sizeof(serv_addr));
        n=recvfrom(cfd,buf,BUFSIZ,0,NULL,0);
        write(STDOUT_FILENO,buf,n); 
    }
    close(cfd);
}




