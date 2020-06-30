#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <errno.h>
//1000个人的信息
//名字，性别，年龄，地址，电话
//
//1.增加
//2.删除
//3.查找
//4.修改
//5.显示
//6.排序
//


enum Option
{
	EXIT,
	ADD,
	DEL,
	SEARCH,
	MODIFY,
	SHOW,
	SORT
};

#define MAX 1000
#define NAME_MAX 20
#define SEX_MAX 5
#define TELE_MAX 12
#define ADDR_MAX 25
#define DEFAULT_SZ 3

//一个人的信息
typedef struct PeoInfo
{
	char name[NAME_MAX];
	short age;
	char sex[SEX_MAX];
	char tele[TELE_MAX];
	char addr[ADDR_MAX];
}PeoInfo;

//通讯录结构体
//typedef struct Contact
//{
//	PeoInfo data[MAX];//存放真实数据的空间
//	int sz;//记录有效数据的个数
//}Contact;

typedef struct Contact
{
	PeoInfo* data;
	int sz;//有效元素个数
	int capacity;//容量
}Contact;


void InitContact(struct Contact* pcon);
void AddContact(Contact* pcon);
void ShowContact(const Contact* pcon);
void DelContact(Contact* pcon);
void DestroyContact(Contact* pcon);
