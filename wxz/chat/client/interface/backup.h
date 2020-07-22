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
#define MAX 50
#define MAX_CHAR 300

int cfd;
int enternum;
int prichat;

typedef struct  message
{
    int flag;
    char msg[256];
    char from[10];

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
    char name[MAX_CHAR];
}FRIEND_INFO;


typedef struct group
{
    int flag;
    int num;//群号
    char name[MAX];
    int ower;
    int admin1;//管理员
    int admin2;
    int admin3;
}group;

typedef struct  file
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
    int type;
    DATA data;
}PACK;




typedef struct account
{
    int flag;
    int username;
    //char username[30];
    char password[30];
    char phone[30];
    char e_mail[50];
}account;

typedef struct person_account_find
{
    int flag;
    int username;
    //char name[30];
    char password[30];
    char phone[30];
    char e_mail[50];
}account_find;


void Clear_buffer();
void Login_menu();
void Register();
void Login();
void Modify_password();


void Add_friend();
void Del_friend();
void Query_friend();
void Private_chat();
void Friend_message();
void Friend_menu();
void Show_friend();


int Send_cmessage(int flag,int receiver,char* buf);
int Send_smessage(int flag,int receiver,int sender,char *buf);
int Send_message(int flag,char* buf);





void display(char* str);
void my_err(const char* err_string,int line);
char* Get_string(char* buf,int len);
char getch();