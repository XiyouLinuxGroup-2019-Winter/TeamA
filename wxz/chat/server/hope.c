#include <stdio.h>

void Send_file()
{
    int id;
    printf("请输入要发送文件的好友账号:\n");
    scanf("%d",&id);

  
	printf("请输入文件名:\n");
	char pathname[100];


	//get_str(pathname,100);
    scanf("%s",pathname);
    
    int fd=open(pathname,O_RDONLY);
    if(fd<0)
    {
       printf("请输入正确的文件路径\n");
       return ;
    }

    file_t file;
    memset(&file,0,sizeof(file));
    file.recver=id;
    file.sender=username;
    file.flag=SEND_FILE;
    strcpy(file.file_name,pathname);



    struct stat stat;
	int fs=fstat(fd,&stat);
	long file_size=0;
	file_size=stat.st_size;
   // file.file_size=file_size;
    printf("file.file_size=%d\n",file.file_size);
    
    printf("sizeof(file)=%ld\n",sizeof(file));
    printf("file_size=%ld\n",file_size);
    
    //int len;
    char buf[BUFMAX];
        //read 返回值为0表示读到文件尾
        while( (file.file_size = read(fd,file.data,sizeof(file.data)))>0)
        {
            printf("11111\n");
            len+=file.file_size;
            memcpy(buf,&file,sizeof(file));
            if(send(cfd,buf,1024,0)<0)
            {
                my_err("send error",__LINE__);
            } 
           //if(file_size==len)
             //   break;
            printf("33333333333333\n");
        }

        /*file_t file_over;
        file_over.sender=username;
        file_over.recver=id;
        file_over.file_size=len;
        strcpy(file_over.data,"over");*/

        printf("2222222\n");
        close(fd);    
}
void Recv_file(char* buf)
{
   // arg=(char*)arg;
    int fd;
    file_t file;
    memcpy(&file,buf,sizeof(file));
    printf("file name:%s\n",file.file_name);
    //如果文件不存在创建文件
    if((fd=open(file.file_name,O_RDWR | O_CREAT | O_APPEND,0777))<0)
    {
        my_err("open file_name error",__LINE__);
    }
    
    
    int ret=write(fd,file.data,file.file_size);
    if(ret<0)
    {
        my_err("write file error",__LINE__);
    }

    /*
    printf("ret=%d\n",ret);
    printf("file_name=%s\n",file.file_name);
    printf("recver=%d\n",file.recver);
    printf("sender=%d\n",file.sender);
    printf("file_size=%d\n",file.file_size);
    */
    close(fd);
}


