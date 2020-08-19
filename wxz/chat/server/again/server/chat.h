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
#include <time.h>
#include <pthread.h>
#include <mysql/mysql.h>
#include "wrang.h"
//#include "prest.h"
#include "pthreadpool.h"


#define SERV_ADDRESS "127.0.0.1"
#define SERV_PORT 8013
#define EPOLLEVENT 1024



typedef struct group_info
{

    char member_name[MAX_CHAR][MAX_CHAR];
    int member_num;

    char group_name[MAX];
    char group_message[MAX_CHAR][MAX_CHAR];
    int group_num;
    
    char group_owner[MAX];
    int type;
    int status[MAX_CHAR];
}GROUP_INFO;

typedef struct file
{
    int flag;
    int file_size;
    char file_name[100];
    char send_name[MAX];
    char recv_name[MAX];
    char message[MAX_CHAR];
}file;

typedef struct data
{
    char send_name[MAX];
    char recv_name[MAX];
    int send_fd;
    int recv_fd;

    char message[MAX_CHAR*2];
    char group_chat[MAX];
}DATA;

typedef struct package
{
    int flag;
    DATA data;
}PACK;









typedef struct account_info
{
    char username[MAX];
    char password[MAX];
    int online;
    int connfd;

    char chat[MAX_CHAR];
    struct account_info* next;
    /*int friend_num;
    char friend_message[MAX][MAX];
    int friend_relation[MAX];

    int group_num;
    int member_num;
    char group_message[MAX][MAX];

    FRIEND_INFO friends[MAX_CHAR];
    GROUP_INFO group[MAX_CHAR];
    RELATION_INFO relation[MAX_CHAR];*/
}ACCOUNT_INFO;






int cfd,lfd,epfd;
MYSQL mysql;

void Connect_mysql();


void Register(PACK* pack_t);

