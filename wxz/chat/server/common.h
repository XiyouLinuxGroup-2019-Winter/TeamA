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


#define DOWNLINE 0
#define ONLINE 1


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
    char name[MAX];
    server_user_t data;
}FRIEND_INFO;

typedef struct friend_node
{
    FRIEND_INFO data;
    struct friend_node *next;
    struct friend_node *pre;
}friend_node_t,*friend_list_t;

friend_list_t head;
pthread_rwlock_t lock;


typedef struct group_info
{
    int group_num;
    char name[MAX];
    char member_name[MAX][MAX];
}GROUP_INFO;

typedef struct group_node
{
    GROUP_INFO data;
    struct group_node *next;
    struct group_node *pre;
}group_node_t,*group_list_t;


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
    int status;
    int sid;
    char username[MAX];
    char password[MAX];
    
    char phone[MAX];
    char e_mail[MAX];

    FRIEND_INFO data[MAX_CHAR];
    GROUP_INFO data[MAX_CHAR];
    int friend_num;
    int group_num;

}ACCOUNT_INFO;

typedef struct account_node
{
    ACCOUNT_INFO data;
    struct account_node *next;
    struct account_node *pre;
}user_node_t,*user_list_t;



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
    char password[20];
    struct sockaddr_in useraddr;
    int socket_id;
    int previe;
    int many;
    int online;      //1:开;0:关
    int connfd;      //链接套接字
}server_user_t;          

typedef struct server_user_node
{
    server_user_t data;
    struct server_user_node *next;
    struct server_user_node *pre;
}server_user_node_t,*server_list_t;

server_list_t list_ser;
int user_num;

PACK pack_send [MAX_CHAR*2];
int send_num;

GROUP_INFO group[MAX_CHAR];
int group_num;

FILE_INFO file [MAX_CHAR];
int file_num;

int lfd;
int epfd;
int cfd;


void Login(PACK* pack_t);
void Register(PACK* pack_t);

void Add_friend(PACK* pack_t);
void Del_friend(PACK* pack_t);
void Query_friend();
void Private_chat();
void Shield_friend();
void Unshield_friend();
void Show_friend_status();
void View_friend_list();
void View_chat_history();

void Create_group();
void Add_group();
void Withdraw_group();
void View_add_group();
void View_group_member();
void View_group_record();
void Group_menu();


void Del_group();
void Set_group_admin();
void Kick();
void Group_leader_menu();

void Send_file();