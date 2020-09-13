#include <stdio.h>

/*
void* Recv_file(void* arg)
{
    char *buf=(char*)arg;
    file_t file;

    memcpy(&file,buf,sizeof(file_t));
    printf("name=%s\n",file.file_name);
    printf("recv=%d\n",file.recver);
    printf("send=%d\n",file.sender);
    printf("filesize=%d\n",file.file_size);
    printf("flag=%d\n",file.flag);
    
    int fd=open(file.file_name,O_RDONLY);
    if(fd<0)
    {
        printf("open error\n");
        close(fd);
        pthread_exit(NULL);
    }
    //char send_request[256];
    //memset(send_request,0,sizeof(send_request));
    message mes;
    mes.flag=RECV_FILE;
    mes.id=username;
    strcpy(mes.messsge,file.file_name);
    char str[BUFSIZ];
    memset(str,0,sizeof(str));
    memcpy(str,&mes,sizeof(mes));
    if(send(cfd,str,sizeof(str),0)<0)
    {
        my_err("send error!",__LINE__);
    }
    return NULL;
}*/
/*void Send_file()
{
    int id;
    printf("请输入要发送文件的好友账号:\n");
    scanf("%d",&id);
    char file_name[256];
    printf("请输入要发送的文件的路径:\n");
    scanf("%s",file_name);

    
    int flag=0;
    file file_t;
    char buf[1024];

    memset(buf,0,sizeof(buf));
    memset(&file_t,0,sizeof(file_t));

     int len=sizeof(file_t);
    printf("sizeof(file)=%ld\n",sizeof(file_t));

    file_t.recver=id;
    file_t.sender=username;
    file_t.flag=SEND_FILE;
    strcpy(file_t.file_name,file_name);



    int fd=open(file_name,O_RDONLY);
    if(fd<0)
    {
        printf("");
        return;
    }

     //计算文件大小
    if(lseek(fd,0,SEEK_END)<0)
    {
        my_err("lseek error", __LINE__);
    }    

    int file_len=lseek(fd,0,SEEK_CUR);
    if(file_len<0)
    {
        my_err("lseek error", __LINE__);
    }
    if(lseek(fd,0,SEEK_SET)<0)
    {
        my_err("lseek error", __LINE__);
    }
    file_t.file_size=file_len;

    //memcpy(buf,&file_t,sizeof(file_t));
    if(send(cfd,&file_t,sizeof(file_t),0)!=len)
    {
        my_err("send error", __LINE__);
    }

    int size=0;
    //memset(buf,0,sizeof(buf));
    //read返回值为0表示读到尾
    while((size=read(fd,file_t.message,sizeof(file_t.message)))>0)
    {
         printf("正在发送文件......size = %d\n", size);

       
        if(send(cfd,&file_t,sizeof(file_t),0)<0)
        {
            sys_err("send error",__LINE__);
        }

        memset(&file_t,0,sizeof(file_t));
        file_t.end=0;
        file_t.flag=SEND_FILE; 
    }
    close(fd);
   
     printf("发送结束...\n");
}
*/












*
void Upload()
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
    }*/

    //从路径名中解析出文件名
    /*char filenames[256];
    int len=0;
    for(int i=0;i<strlen(pathname);i++){
        if(pathname[i]=='/')
        {
            len=0;
            continue;
        }
        filenames[len++]=pathname[i];
    }
    filenames[len]=0;
    printf("filenames is %s\n",filenames);*/


    /*struct stat stat;
	int fs=fstat(fd,&stat);
	long file_size=0;
	file_size=stat.st_size;

    file_t file;
    memset(&file,0,sizeof(file));
    file.recver=id;
    file.sender=username;
    file.flag=UPLOAD;
    strcpy(file.file_name,pathname);
    file.file_size=file_size;
    printf("file_size=%ld\n",file_size);
    
    printf("sizeof(file)=%ld\n",sizeof(file));
    printf("file_size=%d\n",file.file_size);
    close(fd);
    
    char buf[BUFSIZ];
    memset(buf,0,sizeof(buf));
    memcpy(buf,&file,sizeof(file));

    if(send(cfd,buf,sizeof(buf),0)<0) 
    {
        my_err("send error",__LINE__);
    }

    printf("....\n");

    char *str=(char*)malloc(sizeof(file));
    memset(str,0,sizeof(file));

    memcpy(str,&file,sizeof(file));
    pthread_t send_file_id;
    pthread_create(&send_file_id,NULL,Send_file,(void*)str);
    printf(">>>>\n");
}*/
/*
void* Send_file(void *arg)
{
    char *buf1=(char*)arg;
    file_t file;
    memcpy(&file,buf1,sizeof(file));

    printf("name=%s\n",file.file_name);
    printf("recv=%d\n",file.recver);
    printf("send=%d\n",file.sender);
    printf("filesize=%d\n",file.file_size);

    char *filename = malloc(50);
	memset(filename, 0, 50);

    char pathname[100];
    strncpy(pathname,file.file_name,sizeof(file.file_name));
    printf("pathname=%s\n",pathname);*/
        

    //int fd = open(pathname, O_RDONLY);

   // printf(">>>\n");
    /*if(fd<0)
	{
		printf("文件不存在\n");
		close(fd);
		pthread_exit(NULL);
	}*/
	
        
/*
		if (strrchr(pathname,'/')==NULL)
		{
			strncpy(filename,pathname,50);
		}
		else
		{
			filename = strrchr(pathname, '/');
			filename += 1;
		}

		printf("发送文件名:%s 至服务端\n", filename);
         
        file_t send_file;
        char buf[1024];
        	
        printf("?????\n");
        send_file.sender =username;
        send_file.recver=file.recver;
        send_file.flag=SEND_FILE;
        strcpy(send_file.file_name,filename);

         printf("send_file.file_name=%s\n",send_file.file_name);

        int ffd=open(filename,O_RDONLY);
        
        int len;
        //读文件发结构体 read 返回值为0表示读到文件尾
        while( (send_file.file_size = read(ffd,send_file.data,sizeof(send_file.data))) != 0)
        {
            len+=send_file.file_size;
            memcpy(buf,&send_file,sizeof(send_file));
            if(send(cfd,buf,sizeof(buf),0)<0)
            {
                my_err("send error",__LINE__);
            } 
        }

        close(ffd);


		usleep(100000);
	return NULL;
}*/
