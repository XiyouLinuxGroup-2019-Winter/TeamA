#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <unistd.h>
#include <sys/types.h>
#include <ctype.h>
#include <arpa/inet.h>

#define SERV_PORT 9527
int main()
{
    int lfd=0,cfd=0;
    int ret;
    int count=10;
    char buf[BUFSIZ];
    struct sockaddr_in serv_addr;

    cfd=socket(AF_INET,SOCK_STREAM,0);
    serv_addr.sin_family=AF_INET;
    serv_addr.sin_port=htons(SERV_PORT);

    inet_pton(AF_INET,"127.0.0.1",&serv_addr.sin_addr.s_addr);
   
    

    connect(cfd,(struct sockaddr*)&serv_addr,sizeof(serv_addr));

    while(count--)
    {
        write(cfd,"hello",5);
        ret=read(cfd,buf,sizeof(buf));
        write(STDOUT_FILENO,buf,ret);
        sleep(1);
    }
    close(cfd);
}




