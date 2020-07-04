#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define MAX 50
typedef struct user
{
    char id[100];         //账号
    char password[100];   //密码
    long long int telephonenum; //电话
}user;
typedef struct Node
{
    int num;
    int age;
    char name[20];
    char phone[50];
    char come[100];
    char thing[100];
    struct Node *next;
}Node;

void Clear_Buffer();

Node* Add(Node* head);
void Find_Person_Menu(Node* head);

void Read_File(Node* head);
void Save_File(Node* head);
void Login_Menu();
void Developor();
void Menu();
void Format();
void Any_Key_Continue();


void Display(char* str);
char getch();
long long int Get_Num();
void Hidden_password(char *password);
void Enter();
void Login();
void Find_password();


void Create_User_File();
void Create_Person_File();

void Delete_Person_Menu(Node*head);
void Find_Person_Menu(Node* head);
void Sort_Person_Menu(Node* head);

int Get_int();