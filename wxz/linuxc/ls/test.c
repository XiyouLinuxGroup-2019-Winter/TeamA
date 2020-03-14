/*************************************************************************
	> File Name: test.c
	> Author: 
	> Mail: 
	> Created Time: 2020年03月08日 星期日 03时47分56秒
 ************************************************************************/

#include<stdio.h>
#include "my_ls.h"
#include <stdlib.h>

int main(int argc,char** argv)
{
    int i,j,k,num;
    char path[PATH_MAX+1];
    char param[32];  //保存命令行参数，目标文件名和目录名不在此列
    int flag_param=PARAM_NONE;  //参数种类，即是否有-l和-a选项
    struct stat buf;


    //命令行参数的解析 ,分析-l,-a,-al,-la选项
    j=0;
    num=0;
    for(i=1;i<argc;i++)
    {
        if(argv[i][0]=='-')
        {
            for(k=1;k<strlen(argv[i]);k++,j++)
                param[j]=argv[i][k]; //获取-后面的参数保存到数组param中
        }
        num++;  //保存"-"的个数
    }

    //只支持参数a和l,如果含有其他选项就保错
    for(i=0;i<j;i++)
    {
        if(param[i]=='a')
        {
            flag_param |=PARAM_A;
            continue;
        }
        else if(param[i]=='l')
        {
            flag_param |=PARAM_L;
            continue;
        }
        else
        {
            printf("my_ls:invalid option -%c\n",param[i]);
            exit(1);
        }
    }
    param[j]='\0';

    //如果没有输入文件名或目录，就显示当前目录
    if((num+1)==argc)
    {
        strcpy(path,"./");
        path[2]='\0';
        display_dir(flag_param,path);
    }
    i=1;
    do{
        //如果不是目标文件名或目录，解析下一个命令行参数
        if(argv[i][0]=='-')
        {
            i++;
            continue;
        }
        else
        {
            strcpy(path,argv[i]);
        }
            //如果目录文件或目录不存在，报错并退出程序
            if(stat(path,&buf)==-1)
                my_err("stat",__LINE__);

            if(S_ISDIR(buf.st_mode))  //argv[i]是一个目录，如果目录的最后一个字符不是'/',就加上"/"
            {
                if(path[strlen(argv[i])-1]!='/')
                {
                    path[strlen(argv[i])]='/';
                    path[strlen(argv[i])+1]='\0';
                }
            else
                path[strlen(argv[i])]='\0';
            display_dir(flag_param,path);
            i++;
            }
            else
            {
                //argv[i]是一个文件
                display(flag_param,path);
                i++;
            }
    }while(i<argc);
}
