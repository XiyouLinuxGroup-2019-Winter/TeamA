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


int cfd;


typedef struct message
{
    int flag;
    char messsge[256];
}message;

typedef struct chat_message
{
    char name[MAX_CHAR];
    char time[MAX_CHAR];
    char message[MAX_CHAR];
}CHAT_MESSAGE;




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

typedef struct group_node
{
    GROUP_INFO group;
    struct group_info_node* next;
    struct group_info_node* prev;
}group_node_t,*group_list_t;


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

typedef struct box
{
    char send_name[MAX];
    char recv_name[MAX];
    int send_fd;
    int recv_fd;

    char message[MAX_CHAR];
    int flag;
}BOX;

typedef struct bos_node
{
   BOX data;
   struct box_info* next;
   struct box_info* prev;
}box_node_t,*box_list_t;






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

typedef struct account_node
{
    ACCOUNT_INFO data;
    struct account_node* next;
    struct account_node* prev;
}account_node_t,*account_list_t;


void my_err(const char* err_string,int line);