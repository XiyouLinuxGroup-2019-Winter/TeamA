#include "./server.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <errno.h>
#include <pthread.h>
#include <unistd.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <arpa/inet.h>


typedef struct syslog
{
    char name[20];
    char time[100];
    char work[20];
}syslog_t;

//服务器保存用户信息结构体
typedef struct server_user
{
    char username[20];
    char userpasd[20];
    struct sockaddr_in useraddr;
    int previe;
    int many;
    int online;      //1:开;0:关
    int connfd;      //链接套接字
}server_user_t;            

int Add_prest_syslog(syslog_t * data);
int Make_syslog(server_user_t tmp,char* string);