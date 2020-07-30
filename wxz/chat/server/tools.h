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
#include "wrang.h"
#include "mysql.h"
#include "prest.h"

#define SERV_ADDRESS "127.0.0.1"
#define SERV_PORT 8000

#define MAX 50
#define MAX_CHAR 300

#define REGISTER 1
#define LOGIN 2
#define MODIFY 3

#define ADD_FRIEND 4
#define DEL_FRIEND 5
#define QUERY_FRIEND 6
#define PRIVATE_CHAT 7
#define VIEW_FRIEND_LIST 8
#define SHOW_FRIEND_STATUS 9
#define VIEW_CHAT_HISTORY 10
#define SHIELD 11
#define UNSHIELD 12
#define SHOW_FRIEND 13
#define GET_FRIEND_STATUS 14

#define CREAT_GROUP 15
#define ADD_GROUP 16
#define DEL_GROUP 17
#define WITHDRAW_GROUP 18
#define KICK 19
#define SET_GROUP_ADMIN 20
#define VIEW_ADD_GROUP 21
#define VIEW_GROUP_MEMBER 22 
#define VIEW_GROUP_RECORD 23
#define SEND_FILE 24

pthread_mutex_t mutex;
pthread_cond_t cond;
int cfd;
int enternum;
char username[MAX];


typedef struct  friend_info
{
    int statue;
    //好友的信息数
    int message_num;
    int friend_num;
    char name[MAX_CHAR];
}FRIEND_INFO;


typedef struct group_info
{
    int group_num;
    char name[MAX];
    char member_name[MAX][MAX];
}GROUP_INFO;

typedef struct file
{
    int flag
    int size;
    char name[100];
    char send[MAX];
    char recv[MAX];
}FILE_INFO;

typedef struct data
{
    char send_name[MAX];
    char recv_name[MAX];
    int send_fd;
    int recv_fd;

   char message[MAX_CHAR*2];
}DATA;

typedef struct package
{
    int flag;
    DATA data;
}PACK;




typedef struct account_info
{
    int flag;
    int statue;
    int sid;
    char username[MAX];
    char password[MAX];
    
    char phone[MAX];
    char e_mail[MAX];

    FRIEND_INFO friend [MAX_CHAR];
    GROUP_INFO group [MAX_CHAR];
    int friend_num;
    int group_num;

}ACCOUNT_INFO;

typedef struct syslog
{
    char name[20];
    char time[100];
    char work[20];
}syslog_t;

typedef struct server_user
{
    char username[20];
    char userpasd[20];
    struct sockaddr_in useraddr;
    int    previe    ;
    int    many      ;
    int    online    ;      //1:开;0:关
    int    connfd    ;      //链接套接字
}server_user_t;             //服务器保存用户信息结构体

ACCOUNT_INFO user;
int user_num;

PACK pack_send [MAX_CHAR*2];
int send_num;

GROUP_INFO group[MAX_CHAR];
int group_num;

FILE_INFO file [MAX_CHAR];
int file_num;

int lfd;
int epfd;
int sockfd;

MYSQL mysql;

//PACK pack_recv

void Init_socket();


void Recv_pack_message(PACK recv_t);
void display(char* str);
void my_err(const char* err_string,int line);
char* Get_string(char* buf,int len);
char getch();
void Clear_buffer();
void Send_pack(int fd,PACK* recv_pack,char* flag);
server_list_t Find_server_user(char *username);
void Find_del_server_user(server_list_t pos,char* friend_name);