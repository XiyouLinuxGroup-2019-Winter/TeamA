#include "wrang.h"
#include <strings.h>
#include <string.h>
#include <ctype.h>
#include <arpa/inet.h>
#include <sys/un.h>
#include <stddef.h>


int main()
{
    int lfd,cfd;
    char buf[BUFSIZ];

    
    int i,len;
    int size;

    struct sockaddr_un servaddr,clieaddr;

    lfd=socket(AF_UNIX,SOCK_STREAM,0);

    bzero(&servaddr,sizeof(servaddr));

    servaddr.sun_family=AF_UNIX;
    strcpy(servaddr.sun_path,"serv.socket");

    len=offsetof(struct sockaddr_un,sun_path)+strlen("serv.socket");

    unlink("serv.socket");
    bind(lfd,(struct sockaddr*)&servaddr,len);
    listen(lfd,128);

    while(1)
    {
        len=sizeof(clieaddr);
        cfd=Accept(lfd,(struct sockaddr*)&clieaddr,(socklen_t*)&len);
        len-=offsetof(struct sockaddr_un,sun_path);

        clieaddr.sun_path[len]='\0';
        printf("clinet bind filenames %s\n",clieaddr.sun_path);

        while((size=read(cfd,buf,sizeof(buf)))>0)
        {
            for(int i=0;i<size;i++)
                buf[i]=toupper(buf[i]);
           write(cfd,buf,size);
        }
        close(cfd);
    }
   close(lfd);
}
