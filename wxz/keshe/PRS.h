#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define MAX 1024
typedef struct user
{
    char id[100];         //账号
    char password[100];   //密码
    long long int telephonenum; //电话
}user;
typedef struct PERSON
{
    int num;
    int age;
    char name[20];
    char phone[50];
    char come[100];
    char thing[100];
    struct PERSON*next;
}PERSON;
void sys_err(char* str);
void clear_buffer();
PERSON* Create();
PERSON* Create_node();
void Add_head(PERSON* head);
void Add_tail(PERSON* head);
void Delete_Num(PERSON* head,int pos);
void Delete_Name(PERSON* head,char name[]);
void Find_Num(PERSON* head,int pos);
void Find_Name(PERSON* head,char name[]);
void Combined_Query(PERSON* head,int age,char phone[]);
void Change_Num(PERSON* head,int num);
void show(PERSON* head);
void Ascending_sort(PERSON* head);
void Descending_Sort(PERSON* head);

void Read_File(PERSON* head);
long long int Get_Num();
void Login_Menu();