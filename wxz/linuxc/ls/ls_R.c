/*************************************************************************
	> File Name: ls_R.c
	> Author: 
	> Mail: 
	> Created Time: 2020年03月23日 星期一 23时09分47秒
 ************************************************************************/

#include<stdio.h>
#include <unistd.h>
#include <sys/stat.h>
#include <dirent.h>
#include <stdlib.h>
#include <string.h>

#define PATH_LEN 256

void isfile(char* name);
/*void fetchdir(const char* dir,void (*fcn)(char*))//该函数被调用，即已经被判定为目录
{
    char name[PATH_LEN];
    struct dirent* sdp;
    DIR* dp;
    if((dp=opendir(dir))==NULL)
    {
        fprintf(stderr,"fetchdir : can't open %s\n",dir);
        return ;
    }
    while((sdp=readdir(dp))!=NULL)
    {
        if(strcmp(sdp->d_name,".")==0 || strcmp(sdp->d_name,"..")==0)//防止出现无限递归
        continue;

    if(strlen(dir)+strlen(sdp->d_name)+2 >sizeof(name))
        fprintf(stderr,"fetchdir:name %s %s too long\n",dir,sdp->d_name);
    else
    {
        sprintf(name,"%s/%s",dir,sdp->d_name);
        (*fcn)(name);
    }
    }
    closedir(dp);
}*/

void read_dir(char *dir,void (*func)(char *))
{
    DIR* dp;
    dp=opendir(dir);
    if(dp==NULL)
    {
        perror("opendir error");
        return ;
    }
    struct dirent *sdp;
    char path[256];
    while((sdp=readdir(dp))!=NULL)
    {
        if(strcmp(sdp->d_name,".")==0 || strcmp(sdp->d_name,"..")==0)
            continue;
        //fprintf();
        sprintf(path,"%s/%s",dir,sdp->d_name);
        //isfile(path);
        //func(path);
        (*func)(path);
    }
    closedir(dp);
    return ;
}
void isfile(char* name)//处理目录/文件
{
    struct stat sbuf;
    if(stat(name,&sbuf)==-1)
    {
        fprintf(stderr,"isfile can't access %s\n",name);
        exit(1);
    }
    if(S_ISDIR(sbuf.st_mode))//为真就是目录
    {
        read_dir(name,isfile);
    }
    /*if((sbuf.st_mode & S_IFMT)==S_IFDIR)//是否为目录
        fetchdir(name,isfile);//回调函数
    */
    printf("%10s\t\t%ld\n",name,sbuf.st_size);//不是目录，
}
int main(int argc,char* argv[])
{
    if(argc==1)
        isfile(".");
    else
        isfile(argv[1]);
        /*while(--argc>0)
    isfile(*++argv);*/
}
