#include "wrang.h"
#include <strings.h>
#include <string.h>
#include <ctype.h>
#include <arpa/inet.h>
#include <sys/un.h>
#include <stddef.h>

int main()
{
    int cfd,len;
    struct sockaddr_un clieaddr,servaddr;
    char buf[BUFSIZ];

    cfd=socket(AF_UNIX,SOCK_STREAM,0);

    clieaddr.sun_family=AF_UNIX;
    strcpy(clieaddr.sun_path,"clie.socket");

    len=offsetof(struct sockaddr_un,sun_path)+strlen("clie.socket");

    unlink("clie.socket");

    bind(cfd,(struct sockaddr*)&clieaddr,len);


    bzero(&servaddr,sizeof(servaddr));
    servaddr.sun_family=AF_UNIX;
    strcpy(servaddr.sun_path,"serv.socket");

    len=offsetof(struct sockaddr_un,sun_path)+strlen("serv.socket");
    connect(cfd,(struct sockaddr*)&servaddr,len);

    while(fgets(buf,sizeof(buf),stdin)!=NULL)
    {
        write(cfd,buf,strlen(buf));
        len=read(cfd,buf,sizeof(buf));
        write(STDOUT_FILENO,buf,len);
    }
    close(cfd);
}