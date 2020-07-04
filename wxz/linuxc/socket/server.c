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
    char buf[BUFSIZ];//4096
    char client_IP[1024];

    struct sockaddr_in serv_addr,clit_addr;

    lfd=socket(AF_INET,SOCK_STREAM,0);
    serv_addr.sin_family=AF_INET;
    serv_addr.sin_port=htons(SERV_PORT);
    serv_addr.sin_addr.s_addr=htonl(INADDR_ANY);
    


    bind(lfd,(struct sockaddr*)&serv_addr,sizeof(serv_addr));
    listen(lfd,128);

    socklen_t clit_addr_len=sizeof(clit_addr);
    
    
    cfd=accept(lfd,(struct sockaddr*)&clit_addr,&clit_addr_len);

    printf("client ip:%s,port:%d\n",
            inet_ntop(AF_INET,&clit_addr.sin_addr.s_addr,client_IP,sizeof(client_IP)),
            ntohs(clit_addr.sin_port));

    //int ret;
    //char buf[BUFSIZ];//4096
    
    
    while(1)
    {
        ret=read(cfd,buf,sizeof(buf));
        write(STDOUT_FILENO,buf,ret);
        for(int i=0;i<ret;i++)
            buf[i]=toupper(buf[i]);

        write(cfd,buf,ret);
    }
    close(lfd);
    close(cfd);
}