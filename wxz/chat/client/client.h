#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <pthread.h>
#include <sys/socket.h>
#include <unistd.h>
#include "tools.c"

#define MAX 30
#define MAX_CHAR 300
typedef struct user
{
    char username [30];

}user;
typedef struct  group
{
    char group_name[10];
    char admin_name[10];
    user memeber[10]; 
}group;
typedef struct  register_info
{
    int flag;
    char username[10];
    char password[10];
}REGISTER_INFO;
typedef struct users
{
    user user;
    char password[10];
    int friend_num;
    user friend[10];
    group group[10];
    struct users *next;
};

typedef struct  message
{
    char type[2];
    group group;
}message;


void Clear_buffer();
void Login_menu();
void Register();
void Login();
void Modify_password();


void Add_friend();
void Del_friend();
void Query_friend();
void Friend_menu();
void Show_friend();




