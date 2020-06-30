#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <ctype.h>

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
}Node;
typedef struct Tag_Node
{
    Node per;
    struct Tag_Node* next;
}TNode;

void sys_err(char* str);//用于打印错误
void clear_buffer();//用于清空缓冲区


TNode* Create();//用于初始化链表
void Add_Tail(TNode** head);//用于在链表结尾添加人员信息结点
TNode* Delete_Num(TNode* head,int num);//用于根据人员号码删除人员信息
void Delete_Name(TNode* head);//用于根据人员名字删除人员信息
void Find_Num(TNode* head);//用于根据人员号码查找人员信息
void Find_Name(TNode* head);//用于根据人员名字查找人员信息
void Combined_Query(TNode* head);//用于根据人员年龄和电话组合查找人员信息
void Change_Num(TNode* head);//用于根据人员号码修改人员信息
void Show(TNode* head);//用于显示所有人员信息
void Ascending_Sort(TNode* head);//用于根据人员号码升序排序
void Descending_Sort(TNode* head);//用于根据人员号码降序排序
void Report_Printing(TNode* head);//用于数据报表统计人员信息
void Free_Node(TNode** head);//用于释放链表内存
void Read_File_Show(TNode* head);

void Read_File(TNode* head);//用于读取文件人员信息
void Save_File(TNode* head);//用于保存文件人员信息


void Login_Menu();//用于创建登录界面
void Developor();//用于打印作者简介
void Menu();//用于创建菜单
void Format();//用于打印格式
void Any_Key_Continue();//用于打印格式
void display(char* str);//用于打印格式


char getch();//自定义getch()函数
long long int Get_Num();//用于获取电话号码
void Hidden_password(char *password);//用于隐式输入密码
void Enter();//用于用户登录
void Login();//用于用户注册
void Find_password();//用于用户找回密码


void Create_User_File();//用于创建储存用户账号
void Create_Person_File();//用于创建储存人员信息


void Delete_Person_Menu(TNode*head);//用于删除人员信息菜单
void Find_Person_Menu(TNode* head);//用于查找人员信息菜单
void Sort_Person_Menu(TNode* head);//用于排序人员信息菜单

int Get_int();//用于获取整数输入
int Get_choice();//用于获取输入选项
char* Get_string(char* str,int n);//用于获取字符串输入

TNode* Find_Min_Num(TNode* head);
TNode* Find_Max_Num(TNode* head);
TNode* Find_Delete_Num(TNode* head,int num);