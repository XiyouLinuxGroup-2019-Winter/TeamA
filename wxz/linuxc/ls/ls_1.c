/*************************************************************************
	> File Name: ls_1.c
	> Author: 
	> Mail: 
	> Created Time: 2020年03月16日 星期一 02时09分21秒
 ************************************************************************/

#include<stdio.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<unistd.h>
#include<errno.h>
#include<dirent.h>
#include<pwd.h>
#include<errno.h>
#include<grp.h>
#include<time.h>
#include<stdlib.h>
#include<string.h>

#define PARAM_NONE 0 //无参数
#define PARAM_A    1    //-a:显示所有文件
#define PARAM_L    2  //-l：一行只显示一个文件的详细信息
#define PARAM_R    4  //-R:使用递归连同目录中的子目录中的文件显示出来，如果要显示隐藏文件就要添加-a参数
#define MAXLEN  80 //一行显示的最多字符数

int g_leave_len=MAXLEN; //一行剩余长度，用于输出对齐
int g_maxlen;      //存放某目录下最长文件名的长度
int colour;        //颜色


void my_err(const char* err_string,int line);
void display_attribute(struct stat buf,char* name);
void display(int flag,char* pathname);
void display_dir(int flag_param,char* path);
void display_R(int flag_param,char* path);
void display_colour(char name[]);
void resolve_name(char *path,char* name);



/*
30: 黑
31: 红
32: 绿
33: 黄
34: 蓝
35: 紫
36: 深绿
37: 白色
*/
void display_colour(char name[])
{
    struct stat buf;
    lstat(name,&buf);
    if(S_ISREG(buf.st_mode))//　　一般文件
    {
        colour=37;//　　　　　　白色
        if((buf.st_mode&S_IXOTH)||(buf.st_mode&S_IXGRP)||(buf.st_mode&S_IXUSR))//    文件所有者，用户组，其他用户可执行权限
            colour=32;//        绿色
    }
    else if(S_ISDIR(buf.st_mode))//   目录文件
        colour = 34;//          蓝色
    else if(S_ISCHR(buf.st_mode))//   字符设备文件
        colour = 33;//          黄色
    else if(S_ISBLK(buf.st_mode))//   块设备文件
        colour = 33;//　　　　　黄色
    else if(S_ISFIFO(buf.st_mode))//　FIFO
        colour = 35;//          紫红色
    else if(S_ISLNK(buf.st_mode))//   符号链接
        colour = 36;// 　　　　　青蓝色
    else if(S_ISSOCK(buf.st_mode))//  SOCKET
        colour = 36;//          青蓝色
}
void resolve_name(char* path,char* name)
{
    int i,j;
    for(i=0;j=0;i<strlen(path);i++)
    {
        if(path[i]=='/')
        {
            j=0;
            continue;
        }
        name[j++]=path[i];
    }
    name[j]='\0';
}


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
    struct passwd *psd;//从该结构体中获取文件所有者的用户名
    struct group *grp;//从该结构体中获取文件所有者所属组的组名

    display_colour(name);
    //获取并打印文件类型
    if(S_ISLNK(buf.st_mode))//符号链接
        printf("l");
    else if(S_ISREG(buf.st_mode))//一般文件
        printf("-");
    else if(S_ISDIR(buf.st_mode))//目录文件
        printf("d");
    else if(S_ISCHR(buf.st_mode))//字符设备文件
        printf("c");
    else if(S_ISBLK(buf.st_mode))//块设备文件
        printf("b");
    else if(S_ISFIFO(buf.st_mode))//先进先出FIFO
        printf("f");
    else if(S_ISSOCK(buf.st_mode))//socket
        printf("s");

    //获取并打印文件所有者的权限
    if(buf.st_mode & S_IRUSR)//所有者可读
        printf("r");
    else
        printf("-");

   if(buf.st_mode & S_IWGRP)//　　　　可写
        printf("w");
    else
        printf("-");

    if(buf.st_mode & S_IXGRP)//       可执行
        printf("x");
    else
        printf("-");

    //获取并打印用户组的权限
    if(buf.st_mode & S_IRGRP)//用户组具有可读权限
        printf("r");
    else
        printf("-");
    if(buf.st_mode & S_IWGRP)//　　　可写
        printf("w");
    else
        printf("-");
    if(buf.st_mode & S_IXGRP)//　　　可执行　　
        printf("x");
    else
        printf("-");

    //获取并打印其他用户对该文件的操作权限
    if(buf.st_mode & S_IROTH)//其他用户具有可读权限
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

    //printf("  ");

    //根据uid与gid获取文件所有者的用户名与组名
    psd=getpwuid(buf.st_uid);
    grp=getgrgid(buf.st_gid);
    printf("%4d ",buf.st_nlink); //打印文件的链接数
    printf("%-8s",psd->pw_name);//文件所有者的名字
    printf("%-8s",grp->gr_name);//用户组的名字

    printf("%6d",buf.st_size);  //打印文件的大小
    strcpy(buf_time,ctime(&buf.st_mtime));//文件的最后修改时间
    buf_time[strlen(buf_time)-1]='0'; //去掉换行符
    printf("  %s",buf_time);
}

//在没有使用-l选项时，打印一个文件名，打印时上下行对齐
void display_single(char* name)
{
    int i,len;
    struct stat buf;
    //如果本行不足以打印一个文件名则换行
    if(g_leave_len<g_maxlen)
    {
        printf("\n");
        g_leave_len=MAXLEN;
    }

    len=strlen(name);
    len=g_maxlen-len;
    display_colour(name);
    printf("\033[%dm%s\033[0m",colour,name);
    //display_colour(name,buf);

    for(i=0;i<len;i++)
        printf(" ");

    printf(" ");

    //下面的2指示空两格
    g_leave_len-=(g_maxlen+2);//一行中剩下的字符数量
}



void display_R(int flag_param,char* path)
{
    struct stat buf;
    struct stat buff;
    DIR* dir;
    struct dirent* ptr;
    char filenames[256][256],name[256][256],temp[256];
    int i=0,j.k.len,cnt=0;

    if(lstat(path,&buf)==-1)
    {
        my_err("lstat",__LINE__);
        exit(0);
    }

    if(S_ISDIR(buf.st_mode))  //目录文件
    {
        printf("\n%s\n",path);
        cnt=0;
        dir=opendir(path);
        if(dir==NULL)
            my_err("opendir",__LINE__);
        while((ptr==readdir(dir))!=NULL) //获取子目录下文件名，变成绝对路径名"/"
        {
            len=0;
            cnt++;
            strncpy(filenames[i],path,strlen(path));
            filenames[i][strlen(path)]='/';
            filenames[i][strlen(path+1)]='\0';
            strncat(filenames[i],ptr->d_name,strlen(ptr->d_name));
            filenames[i][strlen(filenames)]='\0';
            i++;
        }

        for(i=0;i<cnt;i++)
            resolve_name(filenames[i],name[i]);

        for(i=0;i<cnt;i++)
        {
            if(name[i][0]!='.')
            {
                if(lstat(filenames[i],&buff)==-1)
                    my_err("lstat",__LINE__);

                if(S_ISDIR(buff.st_mode)) //目录文件
                {
                    char* _filenames=(char*)malloc(strlen(filenames[i])*sizeof(char));
                    display_R(flag_param,_filenames);
                    free(_filenames);
                }
                else
                {
                    if(flag_param>)
                }
            }
        }
    }


}
//递归显示目录下的文件
/*void display_R(int flag_param,char * path)
{
    DIR *dir;
    struct dirent *ptr;
    int count=0;
    char filenames[256][256],temp[256],name[256][256];
    int ans=0;
    int i,j,k,len;
    struct stat buf;

    dir=opendir(path);  //统计文件名数量
    if(dir==NULL)
        my_err("opendir",__LINE__);

    //统计出最长文件名长度和文件总数
    while((ptr=readdir(dir))!=NULL)
    {
        if(g_maxlen<strlen(ptr->d_name))
        {
            g_maxlen=strlen(ptr->d_name);
        }
        count++;
    }
    closedir(dir);

    if(count>256)
    {
        my_err("too many file under this dir!\n",__LINE__);
    }

    //printf("%d\n",count);
    len=strlen(path);

    dir=opendir(path);
    for(i=0;i<count;i++)
    {
        ptr=readdir(dir);
        if(ptr==NULL) 
            my_err("readdir",__LINE__);
        strncpy(filenames[i],path,len);
        filenames[i][len]='\0';  //strcat的实现需要最后一位是‘\0’
        if(filenames[i][0]=='.') 
            continue;
        strcat(filenames[i],ptr->d_name);
        filenames[i][len+strlen(ptr->d_name)]='\0';
        if(flag_param>=8)
            display(3,filenames[i]);
        else
            display(flag_param-4,filenames[i]);
    

        lstat(filenames[i],&buf);
        if(S_ISDIR(buf.st_mode))  //目录文件
            strcpy(name[ans++],filenames[i]); //保存下所有的目录文件
    }
    closedir(dir);


    if(flag_param & PARAM_L ==0)  //没有l的时候打印一个换行符
        printf("\n");
    for(k=0;k<ans;k++)
    {
        int flag=0;
        for(i=0;i<strlen(name[k])-1;i++)
        {
            if(name[k][i]=='/' && name[k][i+1]=='.')
            {
                flag=1;
                break;
            }
        }
        if(flag) 
            continue;
        printf("\n%s:\n",name[k]);
        display_R(flag_param,strcat(name[k],"/"));
        printf("\n");
    }
}*/

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

    //\e[1; --开启颜色输出  + 颜色号码 + 字符串 + \e[0m 关闭颜色输出
    switch(flag)
    {
        case PARAM_NONE:  //没有-l和-a选项
            if(name[0]!='.')
                display_single(name);
            break;
        case PARAM_A:     //-a:显示包括隐藏文件在内的所有文件
            display_single(name);
            break;
        case PARAM_L:     //-l：每个文件单独占一行，显示文件的详细属性信息
            if(name[0]!='.')
            {
                display_attribute(buf,name);
                printf("\033[%dm%s\033[0m\n",colour,name);
            }
            break;
        case PARAM_A + PARAM_L: //同时有-a和-l选项的情况
            display_attribute(buf,name);
            printf("\033[%dm%s\033[0m\n",colour,name);
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

    if(flag_param>=4) //已有-R
        display_R(flag_param,path);
    else
    {
        //获取该目录下文件总数和最长的文件名
        dir=opendir(path); //统计文件名数量
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
}

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
    
    //只支持参数a和l,R,如果含有其他选项就报错
    for(i=0;i<j;i++)
    {
        if(param[i]=='a')
        {
            flag_param|=PARAM_A;
            continue;
        }else if(param[i]=='l')
        {
            flag_param|=PARAM_L;
            continue;
        }else if(param[i]=='R')
        {
            flag_param|=PARAM_R;
            continue;
        }else
        {
            printf("my_ls:invalid option -%c\n",param[i]);
            exit(1);
        }
    }
    int _flag_param=0;
    _flag_param=flag_param;

    param[j]='\0';

    //如果没有输入文件名或目录，就显示当前目录
    if(num+1==argc)
    {
        strcpy(path,".");  
        path[2]='\0';
        //printf("%d  :flag_param: \n",_flag_param);
        display_dir(flag_param,path);
        return 0;
    }
    i=1;
    do{
        //如果不是目标文件或目录，解析下一个命令行参数
        if(argv[i][0]=='-')
        {
            i++;
            continue;
        }
        else
        {
            strcpy(path,argv[i]);

            //如果目标文件或目录不存在，报错并退出程序
            if(stat(path,&buf)==-1)
            {
                my_err("stat",__LINE__);
            }
            if(S_ISDIR(buf.st_mode))
            {
                if(path[strlen(argv[i])-1]!='/') //argc[i]是一个目录，如果目录最后一个字符不是'/'，就加上'/'
                {
                    path[strlen(argv[i])]='/';
                    path[strlen(argv[i])+1]='\0';
                }
                else
                    path[strlen(argv[i])]='\0';
                
                display_dir(flag_param,path);//按目录输出
                i++;
            }
            else
            {
                //按文件输出
                display(flag_param,path);//argc[i]是一个文件
                i++;
            }
            //i++;
        }
    }while(i<argc);
}
