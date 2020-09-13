#include <stdio.h>
void get_input(char* buf)
{
    int len=0;
    int ch;

    ch=getchar();
    while(len<256 && ch!='\n')
    {
        buf[len++]=ch;
        ch=getchar();
    }

    if(len==256)
    {
        my_err("len too long",__LINE__);
        //printf("command is too long \n");
        //exit(-1);//输入的命令过长则退出程序
    }

    buf[len]='\n';
    len++;
    buf[len]='\0';
}
void Do_cmd(int argcount,char arglist[100][256])
{

    int i;

    char* arg[argcount+1];

    //将命令取出
    for(i=0;i<argcount;i++)
        arg[i]=(char*)arglist[i];

    arg[argcount]=NULL;

    if(strcmp(arg[0],"cd")==0)
    {
        Do_cd(arg,argcount);
    }
}
void Do_cd(char* arg[],int argcount)
{
    char cd_pathname[PATH_MAX];
    getcwd(cd_pathname,256);
    
    if((argcount==1) || strcmp(arg[1],"~")==0)
    {
        strcpy(pathname,cd_pathname);
        chdir("/home/taciturn-wu/");
    }
    else if(strcmp(arg[1],"-")==0)
    {
        chdir(pathname);
        printf("%s\n",pathname);
        strcpy(pathname,cd_pathname);
    }
    else
    {
        strcpy(pathname,cd_pathname);
        chdir(arg[1]);
    }
}

void Client_cd()
{
     int i;
    int argcount=0;
    char arglist[100][256];
    char **arg=NULL;
    char *buf=NULL;
    buf=(char*)malloc(sizeof(char)*256);
    if(buf==NULL)
    {
        perror("malloc failed");
        exit(-1);
    }

    while(1)
    {
        //将buf所指向的空间清零
        memset(buf,0,256);
        printf("ftp:\n");
        printf("若输入的命令为exit或logout则退出本程序");
        get_input(buf);
        

        if(strcmp(buf,"\n")==0)
            continue;
        //若输入的命令为exit或logout则退出本程序
        if(strcmp(buf,"exit\n")==0 || strcmp(buf,"logout\n")==0)
            break;

        for(i=0;i<100;i++)
        {
            arglist[i][0]='\0';
        }
        argcount=0;
        
        Do_cmd(argcount,arglist);
    }
    if(buf!=NULL)
    {
        free(buf);
        buf=NULL;
    }
    exit(0);
}
