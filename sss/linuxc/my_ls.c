/*我电脑中没有Linux/limits.h这个头文件*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <unistd.h>
#include <sys/types.h>
#include <dirent.h>
#include <grp.h>
#include <pwd.h>
#include <errno.h>
#include <time.h>
#include <limits.h>
#include <signal.h>

#define PARAM_NONE  0  //没有参数
#define PARAM_A     1  // -a 显示所有文件，包括隐藏文件
#define PARAM_L     2  // -l 显示文件详细信息，一行一个
#define MAXPOWLEN   80 // 一行允许的最多字符数

int g_leave_len = MAXPOWLEN;	//一行剩余长度，用于输出对齐
int g_maxlen; //存放在目录下 最长文件名

void print(struct stat buf);
void display_attribute(struct stat buf,char *name); // 一行一个文件 输出详细信息
void display_single(char *name); //只是打印文件名，不打印详细信息
void display(int flag,char *pathname); //解析文件名及其具体命令，对应调用上面两个函数
void display_dir(int flag_param,char *path);//对目录操作，获取文件并传参

int main(int argc,char **argv)
{

   char path[PATH_MAX+1];	
   int num=0,i=0,j=0,k=0;	//num判断有没有输入文件名或目录名
   char param[32];	//保存命令行参数
   int flag_param = PARAM_NONE;  //参数种类 -l -a -al等
   struct stat buf;

   //对 -l -a -la等进行分析
   for(i=1;i<argc;i++)
   {
	   if(argv[i][0]=='-')  // 先找到那个参数所在位置
	   {

		   for(k=1;k<strlen(argv[i]);k++,j++)
			  {
			
                        
			   param[j]=argv[i][k];  // 把-后面的参数保存到param中
			
			  }
	   num++;
	   }
   }
  // printf("%s",param);
   //只支持有意义的参数
   for(i=0;i<j;i++)
   {
	   if(param[i]=='a')
	   {
		   flag_param |=PARAM_A;
		   continue;
	   }
	   else if (param[i] == 'l')
	   {
		   flag_param |PARAM_L;
	           continue;
	   }
	   else
	   {
		   printf("my_ls: invaild option -%c\n",param[i]);
		   exit(1);
	   }
   }
   param[j]='\0';

   //判断有没有输入文件名或者目录，如果没有的话 显示当前目录
   
   if((num+1)==argc)  //没有目录或文件
   {
	   strcpy(path,"./");
	   path[2]='\0';
	   display_dir(flag_param,path);
	   return 0;
   }
    i=1;
    
    //解析
    do
    {
          if(argv[i][0]=='-')   //找到目标文件或目录
	  {
		  i++;
		  continue;
	  }
	  else
	  {
		  strcpy(path,argv[i]);
		  //目录或文件不存在时 报错
		  if(stat(path,&buf)==-1)
		  {
			  perror("stat");
			  exit(1);
		  }
		  if(S_ISDIR(buf.st_mode))    //目录时
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
	           
		  else    //文件时
		  {
			  display(flag_param,path);
			  i++;
		  }
	  }
    }while(i<argc);
    printf("\n");
}

void print(struct stat buf)
{
	struct passwd *pwd; //文件所有者名字
	struct group *grp;// 文件所有者所属组名
	
	/*通过uid gid获取文件获取信息*/
	pwd=getpwuid(buf.st_uid);
	grp=getgrgid(buf.st_gid);

	printf("%s ",pwd->pw_name);
	printf("%s ",grp->gr_name);
}



/*打印文件具体信息，一行一个*/
void display_attribute(struct stat buf,char *name)
{
        
	char buf_time[30];
/*文件类型*/
	struct passwd *psd;
	struct group *grp;
	if(S_ISLNK(buf.st_mode))
		printf("l");

	else if(S_ISREG(buf.st_mode))
		printf("-");		
	
	else if(S_ISDIR(buf.st_mode))
		printf("d");			
	
	else if(S_ISCHR(buf.st_mode))
	        printf("c");		
	
	else if(S_ISBLK(buf.st_mode))
		printf("b");

	else if(S_ISFIFO(buf.st_mode))
		printf("f");			
	
	else if(S_ISSOCK(buf.st_mode))
	        printf("s");

/*文件所有者权限*/
	 if(buf.st_mode & S_IRUSR)   
		printf("r");	 	
	 else 
		printf("-");
	 if(buf.st_mode & S_IWUSR)						
		printf("w");
	 else 
		printf("-");
	 if(buf.st_mode & S_IXUSR)
		printf("x");
	 else 
	        printf("-");
						
/*打印组内用户对文件的权限*/	 
	if(buf.st_mode & S_IRGRP)
		printf("r");
	else 
        	printf("-");
	if(buf.st_mode & S_IWGRP)
    		printf("w");    
	else 
	        printf("-");  
	if(buf.st_mode & S_IXGRP)
		printf("x");
	 else 
		printf("-");   				     	
	 
/*其他用户的权限*/	 
	 if(buf.st_mode & S_IROTH)
	        printf("r");
	 else 
	        printf("-");
	if(buf.st_mode & S_IWOTH)
	        printf("w");
	else 
	        printf("-");
	if(buf.st_mode & S_IXOTH)
	        printf("x");
	else 
	        printf("-");
      
	 printf("  ");
         
	 printf("%d ",buf.st_nlink);  // 打印链接数
	 print(buf); //打印所有者和用户组的信息
         printf("%6d",buf.st_size);//打印文件大小

	 strcpy(buf_time,ctime(&buf.st_mtime));
	 buf_time[strlen(buf_time)-1]='\0';
	 printf(" %s",buf_time);//打印时间
}

/*不使用-l时 上下行对齐*/ 
void display_single(char *name)
{
       int i,len;
       if(g_leave_len<g_maxlen)
       {
	       printf("\n");
	       g_leave_len=MAXPOWLEN;
       }
       len=strlen(name);
       len=g_maxlen-len;
       printf("%-s",name);

       for(i=0;i<len;i++)
       {
	       printf(" ");
       }
       printf("  ");
       g_leave_len-=(g_maxlen+2);
}

/*解析文件名与具体命令，根据不同命令调用不同函数*/
void display(int flag,char *pathname)
{
	int i,j;
	struct stat buf;
	char name[NAME_MAX+1];
        //解析出文件名，并把它放到name数组里
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
      
	if(lstat(pathname,&buf)==-1)
	{
		perror("stat");
		exit(1);
	}
       //根据命令不同，调用不同的函数
	switch(flag)
	{

		case PARAM_NONE:  //没有-l -a
			if(name[0]!='.')
				display_single(name);
			break;
		case PARAM_A:
			display_single(name);
			break;
		case PARAM_L:
			if(name[0]!='.')
			{
				display_attribute(buf,name);
			        printf("   %-s",name);
                	}
			break;
		case PARAM_L+PARAM_A:
			display_attribute(buf,name);
			printf("  %-s",name);
			break;
	}
}

/*操作目录，提取出目录中全部的文件，并依次调用文件处理函数*/
void display_dir(int flag_param,char *path)
{
	struct dirent *ptr;
	int count=0,i=0,j=0,len=strlen(path);
	char filename[256][PATH_MAX+1],temp[PATH_MAX+1];
	DIR *dir;

	/*获取目录下文件总数和最长文件名*/
	 dir=opendir(path);
	 if(dir==NULL)//判断是否成功
	 {
		 perror("dir");
		 exit(1);
	 }
	 while((ptr=readdir(dir))!=NULL)   //遍历所有文件
	 {
		 if(g_maxlen<strlen(ptr->d_name))
			 g_maxlen=strlen(ptr->d_name);
		count++;
       	}
       closedir(dir);
       if(count>256)
       {
       perror("too many file under this dir ");
       exit(1);
       }

       //获取目录下所有文件名
       dir=opendir(path);
       for(i=0;i<count;i++)
       {
             ptr=readdir(dir);
	     if(ptr==NULL)
	     {
	         perror("reddir");
		 exit(1);
        	 }
	     strncpy(filename[i],path,len);
	     filename[i][len]='\0';
	     strcat(filename[i],ptr->d_name);
	     filename[i][len+strlen(ptr->d_name)]='\0';
       }
       
       for(i=0;i<count;i++)  //按文件名字母排序
	       for(j=0;j<count-i-1;j++)
	       {
		       if (strcmp(filename[j], filename[j+1]) > 0)
		       {
			       strcpy(temp, filename[j+1]);
			       strcpy(filename[j+1], filename[j]);
			       strcpy(filename[j], temp);
		       }
	       }

        for(i=0;i<count;i++)// 依次调用函数
		display(flag_param,filename[i]);



	closedir(dir);
}


