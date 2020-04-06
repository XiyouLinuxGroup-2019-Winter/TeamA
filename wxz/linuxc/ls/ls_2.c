/*************************************************************************
	> File Name: 7.c
	> Author: 
	> Mail: 
	> Created Time: 2020年04月04日 星期六 03时59分34秒
 ************************************************************************/

#include<stdio.h>
/*************************************************************************
    > File Name: my_ls.c
    > Author: YinJianxiang
    > Mail: YinJianxiang123@gmail.com
    > Created Time: 2017年07月20日 星期四 11时32分26秒
 ************************************************************************/

#include<stdio.h>
#include <string.h>
#include <stdlib.h>
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
//#define 
int g_leave_len=MAXLEN; //一行剩余长度，用于输出对齐
int g_maxlen;      //存放某目录下最长文件名的长度
int colour;        //颜色


void my_err(const char* err_string,int line);
void display_attribute(struct stat buf,char* name);
void display(int flag,char* pathname);
void display_dir(int flag_param,char* path);
void display_R(int flag_param,char* path);
void display_colour(char name[]);

/*简单错误处理*/
void my_err(const char *err_string,int line) {
    fprintf(stderr,"line:%d ",line);
    perror(err_string);
    if(errno!=13) 
        exit(0);
    else 
        printf("无权限\n"); 
}

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

//获取文件属性并打印
void display_attribute(struct stat buf,char* name)
{
    char buf_time[32];
    struct passwd *psd;//从该结构体中获取文件所有者的用户名
    struct group *grp;//从该结构体中获取文件所有者所属组的组名

    //display_colour(name);
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

    printf("\t");

    //根据uid与gid获取文件所有者的用户名与组名
    psd=getpwuid(buf.st_uid);
    grp=getgrgid(buf.st_gid);
    printf("%4ld ",buf.st_nlink); //打印文件的链接数
    printf("%-8s ",psd->pw_name);//文件所有者的名字
    printf("%-8s",grp->gr_name);//用户组的名字

    printf("%6ld",buf.st_size);  //打印文件的大小
    strcpy(buf_time,ctime(&buf.st_mtime));//文件的最后修改时间
    buf_time[strlen(buf_time)-1]='0'; //去掉换行符
    printf("  %s",buf_time);
    display_colour(name);
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
    printf(" \033[%dm%s\033[0m",colour,name);
    //display_colour(name,buf);

    for(i=0;i<len;i++)
        printf(" ");

    printf(" ");

    //下面的2指示空两格
    g_leave_len-=(g_maxlen+2);//一行中剩下的字符数量
}
  


/*
*  根据命令行参数和完整路径名显示目标文件
*  参数flag:  命令行参数
*　参数pathname:　包含了文件名的路径名
*/
void display(int flag,char *pathname) {
    int i,j;
    struct stat buf;
    char name[NAME_MAX + 1];
    int flag_color;
    
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

    if(S_ISDIR(buf.st_mode))  
        flag_color = 1;

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
                {   display_attribute(buf,name);
                    if(flag_color==1)
                        printf(" \033[%dm%s\033[0m\n",colour,name);
                    else
                        printf(" %-s",name);
                }
            break;
        case PARAM_R://-R
            if(name[0]!='.')
            {
                if(name[0]!='.')
                    display_single(name);
            }
                //display_single(name);
            break;
        case PARAM_A + PARAM_L: //同时有-a和-l选项的情况
            display_attribute(buf,name);
            if(flag_color==1)
                printf(" \033[%dm%s\033[0m\n",colour,name);
            else
                printf(" %-s\n",name);
            break;
        case PARAM_A+ PARAM_R://-AR
            if(name[0]!='.')
            {
                if(name[0]!='.')   
                    display_single(name);
            }
            //display_single(name);
            break;
        case PARAM_L+ PARAM_R://－LR
            if(name[0]!='.')
                {   display_attribute(buf,name);
                    if(flag_color==1)
                        printf(" \033[%dm%s\033[0m\n",colour,name);
                    else
                        printf(" %-s\n",name);
                }
            break;
        case PARAM_A+PARAM_L+PARAM_R://－ARL
            display_attribute(buf,name);
            if(flag_color==1)
                printf(" \033[%dm%s\033[0m\n",colour,name);
            else
                printf(" %-s\n",name);
            break;

        default:
            break;
    }
}
/*
* 显示目录中的文件
* 参数
* 权限
* 路径
* 
* */

void display_dir(int flag_param,char *path) {
    DIR *dir;
    struct dirent *ptr;
    int flag_param_temp=flag_param;
    int count = 0;
    struct stat buf;
    char name[256];
    
    char temp[PATH_MAX];


    dir = opendir(path);    //打开目录
    printf( "\npath %s\n",path);
    if(dir == NULL){
        my_err("opendir",__LINE__);
    }
    /*获取目录下文件的个数，以及最大长度*/
    while((ptr = readdir(dir))!= NULL){
        if(g_maxlen < strlen(ptr->d_name))
            g_maxlen = strlen(ptr->d_name);
        count++;
    }
    char **filenames=(char **)malloc(sizeof(char *) *count);
    int t;
    for(t = 0;t < 20000;t++) 
        filenames[t] = (char *)malloc(PATH_MAX+1);

    closedir(dir);

    if(count > 256) {
        my_err("too many files under this directory",__LINE__);
    }

    int i;
    int j,k;
    int len = strlen(path);

    dir = opendir(path);

    /*获取该目录下所有的文件名*/
    for(i = 0;i < count;i++)
    {
        ptr = readdir(dir);
        if(ptr == NULL)
        {
            my_err("readdir",__LINE__);
        }
        strncpy(filenames[i],path,len);
        filenames[i][len]='\0';
        strcpy(filenames[i],ptr->d_name);
        filenames[i][len + strlen(ptr->d_name)]='\0';
    }

    for(int i = 0;i < count;i++)
	{
		int len = strlen(path);
		temp[len+1] = '\0';
		strcat(temp,filenames[i]);
		strcpy(filenames[i],temp);
		strcpy(temp,path);

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

    for(i = 0;i < count;i++) 
	{
	//	if(strcmp(filenames[i],"") == 0) continue;
		display(flag_param,filenames[i]);
	} 

        if(flag_param & PARAM_R)
	    {
			//flag_param -= PARAM_R;
            for(int i=0;i<count;i++)
            {
                if(lstat(filenames[i],&buf)==-1)
                {
                    my_err("lstat",__LINE__);
                    exit(1);
                }
                if(S_ISDIR(buf.st_mode))
                {
                    len=strlen(filenames[i]);
                    //if(filenames[i][len-1]=='.' && filenames[i][len-2]=='/'||filenames[i][len-1] == '.' && filenames[i][len-2]=='.'&&filenames[i][len-3]=='/')
					//	continue;
                    for(j = 0,k = 0;j < strlen(filenames[i]);j++)
					{   
				                if(filenames[i][j] == '/')
              				        {   
        		        		        k = 0;
              	 	 			        continue;
       					            }   
     					        name[k++] = filenames[i][j];
    	  			}   
		     		   name[k] = '\0';
                    if(strcmp(name,".") == 0 || strcmp(name,"..") == 0)  
                        continue;
                    int len = strlen(filenames[i]);
                    if(flag_param & PARAM_A)
				    {
					    if(filenames[i][strlen(filenames[i]) - 1] != '/')
					    {
						    filenames[i][len] = '/';
						    filenames[i][len+1] = '\0';
					    }
					    display_dir(flag_param,filenames[i]);
					    free(filenames[i]);
				    }
                    else
				    {
					    if(name[0] != '.')
					    {
						    if(filenames[i][strlen(filenames[i]) - 1] != '/')
						    {
							    filenames[i][len] = '/';
							    filenames[i][len+1] = '\0';
						    }
						    display_dir(flag_param,filenames[i]);
                            free(filenames[i]);
                        }
                    }
                }
                    //printf("\n\n%s :\n",filenames[i]);
            /*filenames[i][len]='/';
			filenames[i][len+1]='\0';
			display_R(flag_param_temp,filenames[i]);*/
                    //len=strlen(filenames[i]);
                    //filenames[i][len]='/';
				    //filenames[i][len+1]='\0';
                    //display_dir(flag_param_temp,filenames[i]);
                //else 
                  //  display(flag_param,filenames[i]);
            }
        }
        



    if((flag_param & PARAM_L) == 0) 
    {
        printf("\n");
    }

    closedir(dir);
//    for(i = 0;i < 20000;i++)
  //      free(filenames[i]);

}

int main(int argc, char *argv[])
{
    int i;
    int j;
    int k;
    int num;
    char path[PATH_MAX+1];
    char param[32];
    int  flag_param = PARAM_NONE;
    struct stat  buf;

    j = 0;
    num = 0;

    //解析其参数，以-为标志
    for(i = 1; i < argc;i++) {
        if(argv[i][0] == '-') {
            for(k = 1;k < strlen(argv[i]);k++,j++) {
                param[j] = argv[i][k];
            }
            num++;
        }
    }


    //利用位运算确定具体参数
    for(i = 0;i < j;i++) 
    {
        if(param[i] == 'a')
        {
            flag_param |= PARAM_A;//利用位运算
            continue;
        }
        else if(param[i] == 'l')
        {
            flag_param |= PARAM_L;
            continue;
        } 
       
        else if(param[i] == 'R')
        {
            flag_param |= PARAM_R;
            continue;
        }    
        else
        {
            printf("my_ls: incalid option -%c\n", param[i]);
            exit(1);
        }
    }

    param[j] = 0;

    //默认为当前路径
    if((num+1) == argc) {
        strcpy(path,"./");
        path[2] =  0;
        display_dir(flag_param,path);
        return 0;
    }

    i = 1;
    do
    { 
        if(argv[i][0] == '-')
        {
            i++;
            continue;
        }
        else
        {
            //得到具体路径
            strcpy(path, argv[i]);
            if(stat(path,&buf) == -1)
                my_err("stat",__LINE__);

            //判断是否为目录文件 
            if(S_ISDIR(buf.st_mode)) 
            {
                //如果目录最后忘记了/则加上
                if(path[strlen(argv[i]) - 1] != '/')
                {
                    path[strlen(argv[i])]  = '/';
                    path[strlen(argv[i])+1] = 0;
                }
                else 
                    path[strlen(argv[i])] = 0;

                display_dir(flag_param,path);//按照目录输出
                i++;
            }
            else
            {
                //按照文件输出
                display(flag_param,path);
                i++;
            }
        }
    } while(i < argc);
}





