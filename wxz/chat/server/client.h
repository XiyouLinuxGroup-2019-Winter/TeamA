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
#include "wrang.h"
#include "tool.h"

#define SERV_ADDRESS "127.0.0.1"
#define SERV_PORT 8000

#define MAX 50
#define MAX_CHAR 300
#define SAVE 10

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


#define CREAT_GROUP_APPLY 33
#define ADD_GROUP_APPLY 34
#define DEL_GROUP_APPLY 35
#define WITHDRAW_GROUP_APPLY 36
#define SET_GROUP_ADMIN_APPLY 37
#define KICK_APPLY 38
#define VIEW_ADD_GROUP_APPLY 39
#define VIEW_GROUP_MEMBER_APPLY 40


#define OWNER 1
#define ADMIN 2
#define COMMON 3

#define DOWNLINE 0
#define ONLINE 1
#define UNBLACK 1
#define BLACK 0

#define EXIT -1

pthread_mutex_t mutex;
pthread_cond_t cond;
int cfd;


typedef struct message
{
    int flag;
    char messsge[256];
}message;



typedef struct relation_info
{
    int friend_relation[MAX];
    //好友的信息数
    int message_num;
    int friend_num;
    char friend_message[MAX][MAX];

}RELATION_INFO;
RELATION_INFO relation;

typedef struct friend_info
{
    int status;
    int relation;
    int friend_num;
    
    char username[MAX];
    char friend_name[MAX];
}FRIEND_INFO;


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
GROUP_INFO group;

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
    char send_name[20];
    char recv_name[20];
    int send_fd;
    int recv_fd;

   char message[MAX_CHAR*2];
}DATA;

typedef struct package
{
    int flag;
    DATA data;

    RELATION_INFO relation;
    GROUP_INFO group;
    char message[MAX_CHAR*2];
}PACK;


typedef struct chat_message
{
    char name[MAX_CHAR];
    char time[MAX_CHAR];
    char message[MAX_CHAR];
}CHAT_MESSAGE;

CHAT_MESSAGE print_mes[10];
int flag_print_mes;
PACK recv_chat_pack[MAX_CHAR];
int chat_num;
int print_message_num;


typedef struct account_info
{
    int flag;
    char username[30];
    char password[30];

    char phone[30];
    char e_mail[50];

    int friend_num;
    char friend_message[MAX][MAX];
    int friend_relation[MAX];

    int group_num;
    int member_num;
    char group_message[MAX][MAX];

    FRIEND_INFO friends[MAX_CHAR];
    GROUP_INFO group[MAX_CHAR];
    RELATION_INFO relation[MAX_CHAR];


}ACCOUNT_INFO;


ACCOUNT_INFO user;


PACK pack_send[MAX_CHAR];
int send_num;

PACK check_friend[MAX_CHAR];
int check_num;



void Menu();

void Login_menu();
void Register();
void Login();
void Modify_password();

void Friend_menu();
void Add_friend_apply(PACK recv_pack);
void Add_friend();
void Update_friend_message();
void Del_friend_apply(PACK recv_pack);
void Del_friend();
void Query_friend();
void Query_friend_apply(PACK recv_pack);

void Private_chat();
void Send_message(int flag,char* buf);
void Show_message_print(char* name,char* message);
void *Show_message(void *arg);
void print_message(int id);

void Shield_friend();
void Shield_friend_apply(PACK recv_pack);
void Unshield_friend();
void Unshield_friend_apply(PACK recv_pack);
void Show_friend_status();
void Show_friend_status_apply(PACK recv_pack);
void View_friend_list();
void View_friend_list_apply(PACK recv_pack);
void View_chat_history();

void Create_group();
void Create_group_apply(PACK recv_pack);
void Add_group();
void Add_group_apply(PACK recv_pack);
void Withdraw_group();
void Withdraw_group_apply(PACK recv_pack);
void Group_chat();

void View_add_group();
void View_add_group_apply(PACK recv_pack);
void View_group_member();
void View_group_member_apply(PACK recv_pack);
void View_group_record();
void View_group_record_apply(PACK recv_pack);
void Group_menu();


void Del_group();
void Del_group_apply(PACK recv_pack);
void Set_group_admin();
void Set_group_admin_apply(PACK recv_pack);
void Kick();
void Kick_apply(PACK recv_pack);
void Group_leader_menu();


void Send_file();

int Send_cmessage(int flag,int receiver,char* buf);
int Send_smessage(int flag,int receiver,int sender,char *buf);
int Send_message(int flag,char* buf);
void Send_pack_message(int flag,char *send_name,char* recv_name,char* message);





void display(char* str);
void my_err(const char* err_string,int line);
char* Get_string(char* buf,int len);
char getch();
void Clear_buffer();

void Init_socket();
void *Recv_pack(void* arg);
void Turn_worker_thread();

void *Update_status(void* arg);