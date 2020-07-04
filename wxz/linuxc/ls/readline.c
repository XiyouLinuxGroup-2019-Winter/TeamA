/*************************************************************************
	> File Name: readline.c
	> Author: 
	> Mail: 
	> Created Time: 2020年04月04日 星期六 04时01分55秒
 ************************************************************************/

//#include<stdio.h>
#include<iostream>
#include <readline/readline.h>
#include <readline/history.h>
using namespace std;
int main()
{
    while(true)
    {
        char * p =readline("myshell:")  ;
        add_history(p);//加入历史列表
        p = readline("myshell:");
    }
}

