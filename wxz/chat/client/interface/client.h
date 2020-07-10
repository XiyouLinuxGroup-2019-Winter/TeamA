#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 50
#define MAX_CHAR         300

typedef struct  friend_info
{
    int statue;
    //好友的信息数
    int message_num;
    char name[MAX_CHAR];
}FRIEND_INFO;

typedef struct  user_group_info
{
    char group_name[20];
    int types[10];//群中职位
    int num;
    int group_member_num;
    char group_memeber_name[20][20];
    int statue[10];
}USER_GROUP_INFO;

typedef struct user_infor
{
    char username [MAX_CHAR];
    FRIEND_INFO friends [MAX_CHAR];
    int friends_num;
    int group_num;
    char group [MAX_CHAR][MAX_CHAR];
}USER_INFO;

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




typedef struct person_account
{
    int flag;
    char name[30];
    char password[30];
    char phone[30];
    char e_mail[50];
}account;

typedef struct person_account_find
{
    int flag;
    char name[30];
    char password[30];
    char phone[30];
    char e_mail[50];
}account_find;

/*typedef struct package
{

};*/
void Clear_buffer();
void Login_menu();
void Register();
void Login();
void Modify_password();
