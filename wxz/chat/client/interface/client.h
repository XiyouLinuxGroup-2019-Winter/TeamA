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





typedef struct  message
{
    int flag;
    char msg[256];
}message;

typedef struct  chat_message
{
    int flag;
    char msg[256];
    int send;
    int receive;
}chat_message;


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
    char name[MAX][MAX];
}GROUP_INFO;

typedef struct file
{
    int flag;
    int send;
    int receiver;
    int size;
    char name[100];
    char data[1000];
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
}PACK;




typedef struct account_info
{
    int flag;
    char username[30];
    char password[30];
    
    char phone[30];
    char e_mail[50];

    FRIEND_INFO friend [MAX_CHAR];
    GROUP_INFO group [MAX_CHAR];
    int friend_num;
    int group_num;

}ACCOUNT_INFO;


ACCOUNT_INFO user;


PACK pack_send [MAX_CHAR];
int send_num;

//PACK pack_recv


void Menu();

void Login_menu();
void Register();
void Login();
void Modify_password();

void Friend_menu();
void Add_friend();
void Del_friend();
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
void Turn_worke_thread();