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
void get_input(char*);
void explain_input(char*,int*,char a[][256]);
void do_cmd(int,char a[][256]);
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
        get_input(buf);
        if(strcmp(buf,"exit\n")==0||strcmp(buf,"logout\n")==0)
            break;
        for(i=0;i<100;i++)
            arglist[i][0]='\0';
        argcount=0;
        explain_input(buf,&argcount,arglist);
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
    printf("myshell$$");
}
void get_input(char*buf)
{
    int len=0;
    int ch;
    ch=getchar();//a aa254\n\0
    while(len<256&&ch!='\n'){
        buf[len++]=ch;
        ch=getchar();
    }
    //while(len<256&&((ch=getchar())!='\n'))他是考虑到了254个字符才这么花里呼哨
    if(len==256){
        printf("commond is too long\n");
        exit(-1);
    }
    buf[len]='\n';
    len++;
    buf[len]='\0';
}
void explain_input(char*buf,int *argcount,char arglist[100][256])
{
    char*p=buf;
    char*q=buf;
    int number =0;
    while(1){
        if(p[0]=='\n')
            break;
        if(p[0]==' ')
            p++;
        else{
            q=p;
            number=0;
            while((q[0]!=' ')&&(q[0]!='\n')){
                number++;
                q++;
            }
            strncpy(arglist[*argcount],p,number+1);
            arglist[*argcount][number]='\0';
            (*argcount)++;
            p=q;
        }
    }
}
void do_cmd(int argcount,char arglist[100][256])
{
    int flag=0;
    int how=0;
    int background=0;
    int status;
    int i;
    int fd;
    char*arg[argcount+1];
    char*argnext[argcount+1];
    char*file;
    pid_t pid;
    for(i=0;i<argcount;i++){
        arg[i]=(char*)arglist[i];
    }
    arg[argcount]=NULL;
    for ( i = 0; i < argcount; i++)
    {
        if(strncmp(arg[i],"&",1)==0){
            if(i==argcount-1){
                background=1;
                arg[argcount-1]=NULL;
                break;
            }else{
                printf("wrong command\n");
                return;
            }
        }
    }
    for ( i = 0; arg[i] !=NULL; i++)
    {   
        if(strcmp(arg[i],">")==0){
            flag++;
            how=out_redirect;
            if(arg[i+1]==NULL)
                flag++;
        }
        if(strcmp(arg[i],"<")==0){
            flag++;
            how=in_redirect;
            if(i==0)
                flag++;
                //为什么这里不用考虑arg[i+1]==NULL
        }
        /*hzn@sadl:~/桌面/寒假1周/adl/linuxc$ >s.txt
hzn@sadl:~/桌面/寒假1周/adl/linuxc$ s.txt<
bash: 未预期的符号 `newline' 附近有语法错误*/
        if(strcmp(arg[i],"|")==0){
            flag++;
            how=have_pipe;
            if(arg[i+1]==NULL)
                flag++;
            if(i==0)
                flag++;
        }
    }
    if(flag>1){
        printf("wrong command\n");
        return;
    }
    if(how==out_redirect){
        for ( i = 0; arg[i]!=NULL; i++)
        {
            if(strcmp(arg[i],">")==0){
                file=arg[i+1];
                arg[i]=NULL;
            }
        }
    }
    if(how==in_redirect){
        for ( i = 0; arg[i]!=NULL; i++)
        {
            if(strcmp(arg[i],"<")==0){
                file=arg[i+1];
                arg[i]=NULL;
            }
        }
    }
    if(how==have_pipe){
        for ( i = 0; arg[i] !=NULL; i++)
        {
            if(strcmp(arg[i],"|")==0){
                arg[i]=NULL;
          //      printf("%s%s",arg[i+1],arg[i+2]);
//          printf("%d%d%d%d%d%d",arg[i+2][0],arg[i+2][1],arg[i+2][2],arg[i+2][3],arg[i+2][4],arg[i+2][5]);
                int j;
                for(j=i+1;arg[j]!=NULL;j++){
                    argnext[j-i-1]=arg[j];
                }
                argnext[j-i-1]=arg[j];
                break;
            }
        }
    }
    if((pid=fork())<0){
        printf("fork error\n");
        return;
    }
    switch (how)
    {
    case 0:
        if(pid==0){
            if(!find_command(arg[0])){
                printf("%s: commmand not found \n",arg[0]);
                exit(0);
            }
            execvp(arg[0],arg);
            exit(0);
        }
        break;
    case 1:
        if(pid==0){
            if(!find_command(arg[0])){
                printf("%s: commmand not found \n",arg[0]);
                exit(0);
            }
            fd=open(file,O_RDWR|O_CREAT|O_TRUNC,0644);        
            dup2(fd,1);
            execvp(arg[0],arg);
            exit(0);
        }
        break;
    case 2:
        if(pid==0){
            if(!find_command(arg[0])){
                printf("%s: commmand not found \n",arg[0]);
                exit(0);
            }
            fd=open(file,O_RDONLY);        
            dup2(fd,0);
            execvp(arg[0],arg);
            exit(0);
        }
        break;            
    case 3:
        if(pid==0){
            int pid2;
            int status2;
            int fd2;
            if((pid2=fork())<0){
                printf("fork2 error\n");
                return;
            }
            else if (pid2==0){
                if(!find_command(arg[0])){
                    printf("%s : command not found\n",arg[0]);
                    exit(0);
                }
            
            fd2=open("/tmp/youdonotknowfile",O_WRONLY|O_CREAT|O_TRUNC,0644);
                dup2(fd2,1);
                execvp(arg[0],arg);//执行ls -al--->1--->fd2
                exit(0);
            }
            if(waitpid(pid2,&status2,0)==-1)
                printf("wait for child process error\n");
            if(!(find_command(argnext[0]))){
                printf("%s : command not found\n",argnext[0]);
                exit(0);
            }
            fd2=open("/tmp/youdonotknowfile",O_RDONLY);
            dup2(fd2,0);
     //       printf("%s\n",argnext[0]);
          //  printf("%s\n",argnext[1]);
            
            execvp(argnext[0],argnext);
            // if(remove("/tmp/youdonotknowfile"))
            //     printf("remove error\n");
            exit(0);
        }
        break;
    default:
        break;
    }
    if(background==1){
        printf("progress id  [%d]\n",pid);
        return;
    }
    if(waitpid(pid,&status,0)==-1)
        printf("wait for child process error\n");
}

int find_command(char*command)
{
    DIR*dp;
    struct dirent*dirp;
    char*path[]={"./","/bin","/usr/bin",NULL};
    if(strncmp(command,"./",2)==0)
        command=command+2;
    int i=0;
    while(path[i]!=NULL)
    {
        if((dp=opendir(path[i]))==NULL)
            printf("can't open /bin\n");
        while((dirp=readdir(dp))!=NULL){
            if(strcmp(dirp->d_name,command)==0){
                closedir(dp);
                return 1;
            }
        }
        closedir(dp);
        i++;
    }
    return 0;
}