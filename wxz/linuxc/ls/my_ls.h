/*************************************************************************
	> File Name: my_ls.h
	> Author: 
	> Mail: 
	> Created Time: 2020年03月08日 星期日 03时08分30秒
 ************************************************************************/

#ifndef _MY_LS_H
#define _MY_LS_H
#include<stdio.h>
#include <string.h>
#include <time.h>
#include <sys/stat.h>
#include <unistd.h>
#include <sys/types.h>
//#include <limits.h>
#include <dirent.h>
#include <grp.h>
#include <pwd.h>
#include <errno.h>

#define PARAM_NONE 0 //无参数
#define PARAM_A    1    //-a:显示所有文件
#define PARAM_L    2  //-l：一行只显示一个文件的详细信息
#define MAXLEN  80 //一行显示的最多字符数

int g_leave_len=MAXLEN; //一行剩余长度，用于输出对齐
extern int g_maxlen;      //存放某目录下最长文件名的长度

void my_err(const char* err_string,int line);
void display_attribute(struct stat buf,char* name);
void display_single(char* name);
void display(int flag,char* pathname);
void display_dir(int flag_param,char* path);

#endif
