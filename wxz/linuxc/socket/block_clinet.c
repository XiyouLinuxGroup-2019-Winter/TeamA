#include "wrang.h"
#define SERV_PORT 9000
int main()
{
    int cfd;
    int ret;
    int i;
    char ch='a';
    char buf[10];
    struct sockaddr_in serv_addr;

    cfd=socket(AF_INET,SOCK_STREAM,0);
    serv_addr.sin_family=AF_INET;
    serv_addr.sin_port=htons(SERV_PORT);

    inet_pton(AF_INET,"127.0.0.1",&serv_addr.sin_addr.s_addr);
   
    

    connect(cfd,(struct sockaddr*)&serv_addr,sizeof(serv_addr));

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
            write(cfd,buf,sizeof(buf));
            sleep(5);
    }
    close(cfd);
}
