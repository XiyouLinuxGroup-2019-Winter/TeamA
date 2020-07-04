#include "wrang.h"

#define SERV_PORT 9999
int main()
{
    int lfd=0,cfd=0;
    int ret;
    int count=10;
    char buf[BUFSIZ];
    struct sockaddr_in serv_addr;

    cfd=Socket(AF_INET,SOCK_STREAM,0);



    serv_addr.sin_family=AF_INET;
    serv_addr.sin_port=htons(SERV_PORT);

    inet_pton(AF_INET,"127.0.0.1",&serv_addr.sin_addr.s_addr);
   
    

    Connect(cfd,(struct sockaddr*)&serv_addr,sizeof(serv_addr));

    while(fgets(buf,BUFSIZ,stdin)!=NULL)
    {
        write(cfd,buf,strlen(buf));
        ret=read(cfd,buf,sizeof(buf));
        write(STDOUT_FILENO,buf,ret);
        
    }
    close(cfd);
}



