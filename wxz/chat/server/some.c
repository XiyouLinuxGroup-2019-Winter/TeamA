#include <stdio.h>

int main()
{
    void Upload()
{
    int id;
    printf("请输入要发送文件的好友账号:\n");
    scanf("%d",&id);

  
	printf("请输入文件名(相对路径):\n");
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


  /*  struct stat stat;
	int fs=fstat(fd,&stat);
	long file_size=0;
	file_size=stat.st_size;
     printf("file_size=%ld\n",file_size);

    file_t file;
    memset(&file,0,sizeof(file));
    file.recver=id;
    file.sender=username;
    file.flag=UPLOAD;
    strcpy(file.file_name,pathname);
 
   
    
    printf("sizeof(file)=%ld\n",sizeof(file));
    printf("file_size=%d\n",file.file_size);
    close(fd);
    
    char buf[BUFMAX];
    memset(buf,0,sizeof(buf));
    memcpy(buf,&file,sizeof(file));

    if(send(cfd,buf,sizeof(buf),0)<0) 
    {
        my_err("send error",__LINE__);
    }

    printf("....\n");*/

    //char *arg=(char*)malloc(1024*sizeof(char));
   // char *arg=(char*)malloc(sizeof(file_t));
    //memset(arg,0,sizeof(arg));
   

   /* memcpy(arg,&file,sizeof(file));
    pthread_t send_file_id;
    pthread_create(&send_file_id,NULL,Send_file,(void*)arg);
    printf(">>>>\n");
}*/
/*void *Send_file(void *arg)
{
     arg=(char*)arg;

     file_t file;
     memcpy(&file,arg,sizeof(file));*/
   /* printf("flag= %d\n",file.flag);

    printf("file_flag=%d\n",file.flag);
    printf("file_name=%s\n",file.file_name);
    printf("file_recver=%d\n",file.recver);
    printf("file_sender=%d\n",file.sender);
    printf("server file_size=%d\n",file.file_size);*/
    
 /*   int fd=open(file.file_name,O_RDONLY);
    if(fd<0)
    {
       printf("请输入正确的文件路径\n");
       return NULL;
    }

    file_t file_t;
    memset(&file_t,0,sizeof(file_t));
    file_t.recver=file.recver;
    file_t.sender=username;
    file_t.flag=SEND_FILE;
    strcpy(file_t.file_name,file.file_name);*/
    //file.file_size=file_size;
    //printf("file_size=%d\n",file.file_size);
    
   /* printf("sizeof(file)=%ld\n",sizeof(file));
    printf("file_size=%d\n",file_t.file_size);*/
    
   /* int len;
    char buf[BUFMAX];
        //读文件发结构体 read 返回值为0表示读到文件尾
        while( (file_t.file_size = read(fd,file_t.data,sizeof(file_t.data))) != 0)
        {
            //printf("11111\n");
            len+=file_t.file_size;
            printf("file_t.size = %d\n",file_t.file_size);

            memcpy(buf,&file_t,sizeof(file_t));
            if(send(cfd,buf,sizeof(buf),0)<0)
            {
                my_err("send error",__LINE__);
            }*/ 
            //printf("33333333333333\n");
        //}
        //printf("2222222\n");
        //close(fd);

    /*memset(&file_t,0,sizeof(file_t));
    file_t.sender=username;
    file_t.recver=file.recver;
    file_t.flag=SEND_FILE;
    sprintf(file_t.data,"%s","over");

    char str[BUFMAX];
        memset(str,0,sizeof(str));
        memcpy(str,&file_t,sizeof(file_t));
        if(send(cfd,str,sizeof(str),0)<0)
        {
                my_err("send error",__LINE__);
        } */
        
        /*message mes;
        mes.flag=SEND_FILE;
        sprintf(mes.messsge,"%s","over");
        char str[BUFMAX];
        memset(str,0,sizeof(str));
        memcpy(str,&mes,sizeof(mes));
        if(send(cfd,str,sizeof(str),0)<0)
        {
                my_err("send error",__LINE__);
        } */

  //      return NULL;
}
}

