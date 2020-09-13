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
   
    struct sockaddr_in serv_file;
	int f_fd=Socket(AF_INET,SOCK_STREAM,0);

	bzero(&serv_file,sizeof(serv_file));
	serv_file.sin_family = AF_INET;
	serv_file.sin_port = htons(SERV_PORT);
	inet_pton(AF_INET,SERV_ADDRESS,&serv_file.sin_addr.s_addr);
    //inet_aton("SERV_ADDRESS",&serv_file.sin_addr);
    printf("文件套接字连接\n");
	Connect(f_fd,(struct sockaddr *)&serv_addr,sizeof(struct sockaddr));
    printf("连接成功!\n");


    int pipe_fd[2];
    char send_buf[BUFMAX];
    message mes;
    mes.id=username;
    mes.flag=SEND_FILE;
    strcpy(mes.messsge,"start send file");
    memcpy(send_buf,&mes,sizeof(mes));

    int send_ret;
    
    send_ret=send(f_fd,send_buf,BUFMAX,0);
	send_ret=pipe(pipe_fd);

    while(1)
    {

		send_ret=splice(f_fd,NULL,pipe_fd[1],NULL,BUF,SPLICE_F_MORE|SPLICE_F_NONBLOCK);
		if(send_ret==0)
        {
			break;
		}
		send_ret=splice(pipe_fd[0],NULL,fd,NULL,BUF,SPLICE_F_MORE|SPLICE_F_NONBLOCK);
		if(send_ret==-1)
        {
			if(errno==EINTR || errno==EAGAIN)
			      continue;
			break;
		}
	}

	close(fd);
	close(f_fd);

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

