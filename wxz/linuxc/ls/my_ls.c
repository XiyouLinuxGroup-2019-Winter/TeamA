/*************************************************************************
	> File Name: my_ls.c
	> Author: 
	> Mail: 
	> Created Time: 2020年03月08日 星期日 00时34分36秒
 ************************************************************************/

#include<stdio.h>
#include <stdlib.h>
#include "my_ls.h"

extern int g_leave_len;

void my_err(const char* err_string,int line)
{
    fprintf(stderr,"line:%d",line);
    perror(err_string);
    exit(1);
}

//获取文件属性并打印
void display_attribute(struct stat buf,char* name)
{
    char buf_time[32];
    struct passwd *psd;  //从该结构体中获取文件所有者的用户名
    struct group *grp;   //从该结构体中获取文件所有者所属组的组名


    //获取并打印文件类型
    if(S_ISLNK(buf.st_mode))  //符号链接
        printf("l");
    else if(S_ISREG(buf.st_mode))//一般文件
        printf("-");
    else if(S_ISDIR(buf.st_mode)) //目录文件
        printf("d");
    else if(S_ISCHR(buf.st_mode))  //字符设备文件
        printf("c");
    else if(S_ISBLK(buf.st_mode)) //块设备文件
        printf("b");
    else if(S_ISFIFO(buf.st_mode)) //先进先出FIFO
        printf("f");
    else if(S_ISSOCK(buf.st_mode)) //socket
        printf("s");

    //获取并打印文件所有者的权限
    if(buf.st_mode & S_IRUSR)  //所有者可读
        printf("r");
    else
        printf("-");

   if(buf.st_mode & S_IWGRP) //　　　　可写
        printf("w");
    else
        printf("-");

    if(buf.st_mode & S_IXGRP) //       可执行
        printf("x");
    else
        printf("-");


    //获取并打印其他用户对该文件的操作权限
    if(buf.st_mode & S_IROTH) //其他用户具有可读权限
        printf("r");
    else
        printf("-");
    
    if(buf.st_mode & S_IWOTH)//             可写权限
        printf("w");
    else
        printf("-");

    if(buf.st_mode & S_IXOTH)//             可执行权限
        printf("x");
    else
        printf("-");

    printf("  ");

    //根据uid与gid获取文件所有者的用户名与组名
    psd=getpwuid(buf.st_uid);
    grp=getgrgid(buf.st_gid);
    printf("%4d ",buf.st_nlink); //打印文件的链接数
    printf("%-8s",psd->pw_name);
    printf("%-8s",grp->gr_name);

    printf("%6d",buf.st_size);  //打印文件的大小
    strcpy(buf_time,ctime(&buf.st_mtime));
    buf_time[strlen(buf_time)-1]='0'; //去掉换行符
    printf("  %s",buf_time);
}
//在没有使用-l选项时，打印一个文件名，打印时上下行对齐
void display_single(char* name)
{
    int i,len;

    //如果本行不足以打印一个文件名则换行
    if(g_leave_len<g_maxlen)
    {
        printf("\n");
        g_leave_len=MAXLEN;
    }

    len=strlen(name);
    len=g_maxlen-len;
    printf("%-s",name);
    
    for(i=0;i<len;i++)
        printf(" ");

    printf(" ");

    //下面的2指示空两格
    g_leave_len-=(g_maxlen+2);
}

/*
*  根据命令行参数和完整路径名显示目标文件
*  参数flag:  命令行参数
*　参数pathname:　包含了文件名的路径名
*/
void display(int flag,char* pathname)
{
    int i,j;
    struct stat buf;
    char name[NAME_MAX+1];

    //从路径中解析出文件名
    for(i=0,j=0;i<strlen(pathname);i++)
    {
        if(pathname[i]=='/')
        {
            j=0;
            continue;
        }
        name[j++]=pathname[i];
    }
    name[j]='\0';

    //用lstat而不是stat以方便解析链接文件
    if(lstat(pathname,&buf)==-1)
        my_err("stat",__LINE__);

    switch(flag)
    {
        case PARAM_NONE:  //没有-l和-a选项
            if(name[0]!='-')
                display_single(name);
            break;
        case PARAM_A:     //-a:显示包括隐藏文件在内的所有文件
            display_single(name);
            break;
        case PARAM_L:     //-l：每个文件单独占一行，显示文件的详细属性信息
            if(name[0]!='.')
            {
                display_attribute(buf,name);
                printf("  %-s\n",name);
            }
            break;
        case PARAM_A + PARAM_L: //同时有-a和-l选项的情况
            display_attribute(buf,name);
            printf("  %-s\n",name);
            break;
        default:
            break;
    }
}
void display_dir(int flag_param,char* path)
{
    DIR *dir;
    struct dirent  *ptr;
    int count=0;
    char filenames[256][PATH_MAX+1],temp[PATH_MAX+1];

    //获取该目录下文件总数和最长的文件名
    dir=opendir(path);
    if(dir==NULL)
        my_err("opendir",__LINE__);
    while((ptr=readdir(dir))!=NULL)
    {
        if(g_maxlen<strlen(ptr->d_name))
            g_maxlen=strlen(ptr->d_name);
        count++;
    }
    closedir(dir);

    if(count>256)
        my_err("too mant files under this dir",__LINE__);

    int i,j,len=strlen(path);
    //获取该目录下所有的文件名
    dir=opendir(path);
    for(i=0;i<count;i++)
    {
        ptr=readdir(dir);
        if(ptr==NULL)
            my_err("readdir",__LINE__);

        strncpy(filenames[i],path,len);
        filenames[i][len]='\0';
        strcat(filenames[i],ptr->d_name);
        filenames[i][len+strlen(ptr->d_name)]='\0';
    }

    //使用冒泡法对文件名进行排序，排序后文件名按字母顺序存储于filenames
    for(i=0;i<count-1;i++)
    {
        for(j=0;j<count-1-i;j++)
        {
            if(strcmp(filenames[j],filenames[j+1])>0)
            {
                strcpy(temp,filenames[j+1]);
                temp[strlen(filenames[j+1])]='\0';
                strcpy(filenames[j+1],filenames[j]);
                filenames[j+1][strlen(filenames[j])]='\0';
                strcpy(filenames[j],temp);
                filenames[j][strlen(temp)]='\0';
            }
        }
    }
    for(i=0;i<count;i++)
        display(flag_param,filenames[i]);
    
    closedir(dir);

    //如果命令行中没有-l选项，打印一个换行符
    if((flag_param & PARAM_L)==0)
        printf("\n");
}

