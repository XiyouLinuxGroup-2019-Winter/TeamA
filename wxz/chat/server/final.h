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
#include "List.h"
#include "pthreadpool.h"




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
#define GROUP_CHAT 25

#define ADD_FRIEND_APPLY 26
#define DEL_FRIEND_APPLY 27
#define QUERY_FRIEND_APPLY 28
#define SHIELD_APPLY 29
#define UNSHIELD_APPLY 30
#define VIEW_FRIEND_LIST_APPLY 31
#define SHOW_FRIEND_STATUS_APPLY 32


#define DOWNLINE 0
#define ONLINE 1

#define SAVE 10
#define MAX_THREAD_NUM 10

typedef struct  friend_info
{
    int status;
    //好友的信息数
    //int message_num;
    int friend_num;
    char username[MAX];

    char friend_name[MAX];
}FRIEND_INFO;

typedef struct friend_node
{
    FRIEND_INFO data;
    struct friend_node *next;
    struct friend_node *prev;
}friend_node_t,*friend_list_t;

friend_list_t friend_ser;


typedef struct group_info
{
    char member_name[MAX][MAX];
    int member_num;

    char group_name[MAX];
 
    int type[MAX_CHAR];
    int status[MAX_CHAR];
}GROUP_INFO;

typedef struct group_node
{
    GROUP_INFO data;
    struct group_node *next;
    struct group_node *prev;
}group_node_t,*group_list_t;


typedef struct file
{
    int flag;
    int file_size;
    char file_name[100];
    char send_name[MAX];
    char recv_name[MAX];
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
    //int previe;
    //int many;
    
    int online;      //1:开;0:关
    int connfd;      //链接套接字


    int friend_num;
    char friend_message[MAX][MAX];

    int group_num;
    char group_message[MAX][MAX];

    GROUP_INFO group[MAX];//群组信息
}server_user_t;          

typedef struct server_user_node
{
    server_user_t data;
    struct server_user_node *next;
    struct server_user_node *prev;
}server_user_node_t,*server_list_t;


pthread_mutex_t mutex;
pthread_cond_t cond;

server_list_t list_ser;
int user_num;

PACK pack_send[MAX_CHAR*2];
int send_num;


struct group_node* group_ser;
int group_num;

FILE_INFO file[MAX_CHAR];
int file_num;



int lfd;
int epfd;
int cfd;

void Init_socket();

void *work(void* arg);

void Login(PACK* pack_t);
void Register(PACK* pack_t);

void Add_friend(PACK* pack_t);
void Add_friend_apply(PACK* pack_t);
void Del_friend(PACK* pack_t);
void Query_friend(PACK* pack_t);
void Private_chat(PACK* pack_t);
void Shield_friend(PACK* pack_t);
void Unshield_friend(PACK* pack_t);
//一起实现
void Show_friend_status(PACK* pack_t);
void View_friend_list(PACK* pack_t);
void View_chat_history(PACK* pack_t);

void Create_group(PACK* pack_t);
void Add_group(PACK* pack_t);
void Withdraw_group(PACK* pack_t);
void View_add_group(PACK* pack_t);
void View_group_member(PACK* pack_t);
void View_group_record(PACK* pack_t);
void Group_chat(PACK* pack_t);


void Del_group(PACK* pack_t);
void Set_group_admin(PACK* pack_t);
void Kick(PACK* pack_t);


void Send_file();
void Send_record(PACK* pack_t);


MYSQL mysql;
void sys_err(const char* s,int line);
void Connect_mysql();
void Use_mysql(const char *string, MYSQL mysql);
void Close_mysql(MYSQL mysql);
void Mysql_save_message(PACK* pack_t);


void Recv_pack_message(PACK recv_t);//收到包的信息
void Send_recv_pack(int fd,PACK* recv_pack,char* flag);
void Send_pack(PACK* send_pack_t);
void Send_pack_type(int fd,int type,PACK* recv_pack,char* flag);
void Send_pack_type_name(int fd,int type,PACK* recv_pack,char* flag);

server_list_t Find_server_user(char *username);
void Find_del_server_user(server_list_t pos,char* friend_name);
group_list_t Find_server_group(char* group_name);
void Read_from_mysql();
void Server_user(server_list_t list_ser);
void Server_friend(friend_list_t friend_ser);
void Server_group(group_list_t group_ser);
void Server_group_member(group_list_t group_ser);

void Mysql_with_error(MYSQL* mysql);


int threadpool_add(void *(*process)(void *arg),void *arg);  
int threadpool_destroy();
void *thread_routine(void *arg); 
void pool_init(int max_thread_num);  



