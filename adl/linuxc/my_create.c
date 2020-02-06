#include<stdio.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>//open
#include<unistd.h>
#include<errno.h>//errno
#include<string.h>//strerror
#include<stdlib.h>//exit
int main()
{
    int fd;
    if((fd=open("example_62.c",O_CREAT|O_EXCL,S_IRUSR|S_IWUSR))==-1){//creat（若文件不存在则创建）|excl(检验文件是否存在
        //  perror("打开失败");
       if((fd=creat("example_62.c",S_IRWXU))==-1){//const S_IRWXU = S_IRUSR or S_IWUSR or S_IXUSR
            // perror("open");
            printf("open:%s with errno :%d\n",strerror(errno),errno);
            exit(1);
        }else{
            printf("create file success\n");
        }
    }
    close(fd);
    return 0;
}
//和所符不同