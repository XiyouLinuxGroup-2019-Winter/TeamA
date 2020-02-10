#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<string.h>
#include<sys/types.h>
#include<sys/wait.h>
#include<fcntl.h>
#include<sys/stat.h>
#include<dirent.h>
#include<stdlib.h>
#define normal 0
#define out_redirect 1
#define in_redirect 2
#define have_pipe 3
void print_prompt();
void get_intput(char*);
void explin_input(char*,int*,char a[][]);
void do_cmd(int,char a[][]);
int find_command(char*);

int main(int argc,char**argv)
{
    int i;
    int argcount=0;
    char arglist[100][256];
    char **arg=NULL;
    char*buf=NULL;
    if((buf=(char*)malloc(256))==NULL){
        perror("malloc failed");
        exit(-1);
    }
    while(1){
        memset(buf,0,256);
        print_prompt();
        get_intput(buf);
        if(strcmp(buf,"exit\n")==0||strcmp(buf,"logout\n")==0)
            break;
        for(i=0;i<100;i++)
            arglist[i][0]='\0';
        argcount=0;
        explin_input(buf,&argcount,arglist);
        do_cmd(argcount,arglist);    
    }
    if(buf!=NULL){
        free(buf);
        buf=NULL;
    }
    exit(0);
}    

void print_prompt()
{
    printf("myshell$$   ");
}
void get_input(char*buf)
{
    int len=0;
    int ch;
    ch=getchar();//a aa255\n
    while(len<256&&ch!='\n'){
        buf[len++]=ch;
        ch=getchar();
    }
    //while(len<356&&((ch=getchar())!='\n'))他是考虑到了254个字符才这么花里呼哨
    if(len==256){
        printf("commond is too long\n");
        exit(-1);
    }
    buf[len]='\n';
    len++;
    buf[len]='\0';
}