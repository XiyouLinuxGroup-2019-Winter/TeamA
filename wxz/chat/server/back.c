void Register()
{
    Account_t register_t;
    
    char buf[BUFSIZ];
    memset(buf,0,sizeof(buf));
    printf("用户名:");
    printf("[此用户名为您暂时的名字,并不是登录账号]\n");
    scanf("%s",register_t.name);
    //fgets(register_t.username,sizeof(register_t.username),stdin);
    printf("密码:");
    scanf("%s",register_t.password);
    //GetPassword(register_t.password);
    //fgets(register_t.password,sizeof(register_t.password),stdin);
    register_t.flag=REGISTER;

    memcpy(buf,&register_t,sizeof(Account_t));

    //printf("client flag:%d\n",register_t.flag);
    //printf("client message:%s\n",register_t.password);
    //printf("client send:%s\n",register_t.name);
    if(send(cfd,buf,sizeof(buf),0)<0)
    {
        my_err("send error!",__LINE__);
    }
}
void Register_apply(char* buf)
{
    message mes;
    memcpy(&mes,buf,sizeof(mes));

    printf("%s\n",mes.messsge);
    int id=mes.id;
    printf("----等会输入账号时请输入系统给您的账号\n");
    printf("您的账号是:%d\n",mes.id);
    printf(">...\n");
    printf("正在返回登录界面\n");
    usleep(1000);
    Login_menu();
    //sleep(1);
    //getchar();
}
/*void Register_error_apply(char* buf)
{
    message mes;
    printf("-----%s\n",mes.messsge);

}*/
int Check_data(char *num)
{
    int i;
    for(i=0;num[i];i++) 
    {
        if(num[i]>'9' || num[i]<'0')//只要有非数字，就返回错误
        {
            printf("您的输入不为数字\n");
            return 0;
        }
    }

    if(i>100)//长度超过100位，返回错误
    {
        printf("超出数字长度\n");
        return 0;
    }
    return 1;
}
int Get_choice_int(char* str)
{
    while (1)
    {
        scanf("%s",str);
        while(getchar()!='\n');
        if (Check_data(str)==0)
        {
            //printf("wraning------[[[不要输入之前注册的用户名]]]\n");
            printf("输入错误,请重新输入整数\n");
        }
        else
        {
            printf("输入正确\n");
            break;
        }
    }
    int choice;
    choice=atoi(str);
    return choice;
}
void Login()
{
    char buf[BUFSIZ];
    Account_t account;
    account.flag=LOGIN;
    //printf("wraning------[[[不要输入之前注册的用户名]]]\n");
    printf("请输入账号:\n");
    scanf("%d",&account.id);
    char str[SIZE];
    while (1)
    {
        scanf("%s",str);
        if (Check_data(str)==0)
        {
            printf("wraning------[[[不要输入之前注册的用户名]]]\n");
            printf("输入错误,请重新输入\n");
        }
        else
        {
            printf("账号输入正确\n");
            break;
        }
    }

    //printf("%d\n", atoi(str));
    account.id=atoi(str);

    printf("请输入密码:\n");
    scanf("%s",account.password);

    //GetPassword(account.password);

    username=account.id;
    memcpy(buf,&account,sizeof(account));
    if(send(cfd,buf,sizeof(buf),0)<0)
    {
        my_err("send error!",__LINE__);
    }

    pthread_mutex_lock(&mutex_login);
    pthread_cond_wait(&cond_login,&mutex_login);
    if(flag_login==1)
        Menu();
    flag_login=0;
    pthread_mutex_unlock(&mutex_login);
}
void Login_apply(char* buf)
{
    message mes;
    memcpy(&mes,buf,sizeof(mes));
    pthread_mutex_lock(&mutex_login);
    if(strcmp(mes.messsge,"y")==0)
    {
        printf("登录成功\n");
        flag_login=1;
    }
    else if(strcmp(mes.messsge,"a")==0)
        printf("账号已登录\n");
    else if(strcmp(mes.messsge,"n")==0)
        printf("密码错误或账户不存在\n");
    /*else if 
    {
        printf("---%s\n",mes.message);
    }*/
    
    
    pthread_cond_signal(&cond_login);
    pthread_mutex_unlock(&mutex_login);
}
void Login_menu()
{

    int choice=-1;
   
    //int choice=-1;
    while(choice)
    {
        usleep(10000);
        //system("clear");
        printf("\t\t\033[44;34m\033[44;37m**************************\033[0m\n");
        printf("\t\t\033[1;34m*        1.注册          \033[1;34m*\033[0m \n");
        printf("\t\t\033[1;34m*        2.登录          \033[1;34m*\033[0m \n");
        printf("\t\t\033[1;34m*        0.退出          \033[1;34m*\033[0m \n");
        printf("\t\t\033[44;34m\033[44;37m**************************\033[0m\n");
        printf("\t\tchoice：");
        char choice_t[SIZE];
        choice=Get_choice_int(choice_t);
        //choice=Get_choice_int();
        //scanf("%d",&choice);
        //while(getchar()!='\n');
        //choice=Get_choice(choice_t);    
        switch(choice)
        {
            case 1:
                puts("注册");
                Register();
                break;
            case 2:
                puts("登录");
                Login();
                break;
            /*case 3:
                puts("找回密码");
                Modify_password();
                break;*/
            default:
                break;
        }
    }
}




void Client_cd()
{
    command_t command;
    printf("ftp:\n");
    char line[256];
    fflush(stdout);

    while(fgets(line,sizeof(line),stdin)!=NULL)
    {
        if(Split(command,line)<0)
        {
            my_err("split error",__LINE__);
        }

        if(strcasecmp(command.name, "cd") == 0)
        {
            if(Do_cd(command.argv[1])<0)
            {
                my_err("cd error",__LINE__);
            }
        }
        memset(&command,0,sizeof(command));
         printf("ftp:\n");
        fflush(stdout);
    }

}
void Del_blank(int i,char* line)
{   
    do
    { 
        while(line[i]!='\0' && (line[i]==' ' || line[i]=='\t'))
                 i++;
    }while(0);
}
void Get_arg(char* arg,int i,char* line) 
{
    do
    {
         int j=0; 
         while(line[i]!='\0' && line[i]!=' ' && line[i]!='\t')
                 arg[j++]=line[i++];
    }while(0);
}
int Split(command_t command,char* line)
{
     int i=0,j=0;
 
    line[strlen(line)-1]='\0';  // 将换行符\n替换为结束符\0
         Del_blank(j,line);    // 过滤空格，直到遇到第一个参数
 
        while(line[j]!='\0')
        {
            if((command.argv[i]=(char *)malloc(sizeof(char)*BUFFSIZE))==NULL)
            {
                my_err("fail to malloc",__LINE__);
                return -1;
            }
            Get_arg(command.argv[i],j,line);
                 /*{
                         int j = 0;
                         while(cline[p]!='\0' && cline[p]!=' ' && cline[p]!='\t') 
                                 command->argv[i][j++] = cline[p++]; 
                         
                 }*/
            i++;
            Del_blank(j,line);
        }
 
        command.argv[i]=NULL;        // 命令参数数组以NULL结尾
        command.name = command.argv[0];       // 命令名和第一个参数指向同一内存区域
        return i;
}
int Do_cd(char* path)
{
    if(chdir(path)<0) //chdir改变当前工作目录
    {
        perror("fail to change directory");
        return -1;
    }
    return 0;
}
void Send_file()
{
    int id;
    printf("请输入要发送文件的好友账号");
    scanf("%d",&id);
    char file_name[256];
    printf("请输入要发送的文件的路径");
    scanf("%s",file_name);

    
    int flag=0;
    file file_t;
    char buf[BUFSIZ];

    file_t.recver=id;
    file_t.sender=username;
    file_t.flag=SEND_FILE;
    strcpy(file_t.file_name,file_name);
    printf("sizeof(file)=%ld\n",sizeof(file));
    int fd=open(file_name,O_RDONLY);
    if(fd<0)
    {
        my_err("open error",__LINE__);
    }

    //read返回值为0表示读到尾
    while((file_t.file_size=read(fd,file_t.message,sizeof(file_t.message)))!=0)
    {
        len+=file_t.file_size;
        memcpy(buf,&file_t,sizeof(file_t));
        if(send(cfd,buf,sizeof(buf),0)<0)
        {
            flag=1;
            sys_err("send error",__LINE__);
        } 
    }
    close(fd);
    if(flag==0)
    {
        printf("文件发送成功\n");
        usleep(1000);
        getchar();
    }
    else if(flag==1)
    {
        printf("文件发送失败\n");
        usleep(1000);
        getchar();
    }
}
void Recv_file(char *buf)
{
    int fd;
    file file_t;
    memcpy(&file_t,buf,sizeof(file_t));
    //如果文件不存在创建文件
    if((fd=open(file_t.file_name,O_RDWR | O_CREAT | O_APPEND,0600))<0)
    {
        my_err("open file_name error",__LINE__);
    }
    
    
    int ret=write(fd,file_t.message,file_t.file_size);
    if(ret<0)
    {
        my_err("write file error",__LINE__);
    }

    printf("ret=%d\n",ret);
    printf("file_name=%s\n",file_t.file_name);
    printf("recver=%d\n",file_t.recver);
    printf("sender=%d\n",file_t.sender);
    printf("file_size=%d\n",file_t.file_size);
    close(fd);
}
void Send_file(int fd,char* buf)
{
    printf("....\n");
    char *str=(char*)malloc(sizeof(file));
    memcpy(str,buf,sizeof(file));
    pthread_t recv_file_id;
    pthread_create(&recv_file_id,NULL,Recv_file,(void*)str);
    printf(">>>>\n");
}
void *Recv_file(void *arg)
{
    char *buf=(char*)arg;
    file file_t;
    memcpy(&file_t,buf,sizeof(file_t));

    printf("name=%s\n",file_t.file_name);
    printf("recv=%d\n",file_t.recver);
    printf("send=%d\n",file_t.sender);
    printf("filesize=%d\n",file_t.file_size);

    //得到好友套接字
    int recv_fd=Get_connfd(file_t.recver);
    int send_fd=Get_connfd(file_t.sender);
    if(recv_fd<0)
    {
        char mes[256];
        sprintf(mes,"好友[%d]不在线",file_t.recver);
        Send_pack(send_fd,RECV_APPLY,mes);
        return NULL;
    }
    //向好友转发
    file_t.flag=RECV_FILE;
    if(send(recv_fd,&file_t,sizeof(file_t),0)<0)
    {
        my_err("send file error",__LINE__);
    }

    free(buf);
    return NULL;
}










void Send_file()
{
  
     int id;
    printf("请输入要发送文件的好友账号:\n");
    scanf("%d",&id);

    char file_name[256];
    printf("请输入要发送的文件的路径:\n");
    scanf("%s",file_name);
    

    file_t file;
    file.recver=id;
    file.sender=username;
    file.flag=SEND_FILE;
    strcpy(file.file_name,file_name);
 


    
    int fd=open(file_name,O_RDONLY);
    if(fd<0)
    {
       printf("请输入正确的文件路径\n");
       return ;
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
    file.file_size=file_len;

    close(fd);
    
    printf("sizeof(file)=%ld\n",sizeof(file));
    
    char buf[BUFSIZ];
    memset(buf,0,sizeof(buf));
    memcpy(buf,&file,sizeof(file));

    if(send(cfd,buf,sizeof(buf),0)<0) 
    {
        my_err("send error",__LINE__);
    }

    printf("....\n");

    char *str=(char*)malloc(sizeof(file_t));
    memset(&str,0,sizeof(str));

    memcpy(str,&file,sizeof(file));
    pthread_t recv_file_id;
    pthread_create(&recv_file_id,NULL,Recv_file,(void*)str);
    printf(">>>>\n");
}
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




}






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
    strncpy(pathname,file.file_name,sizeof(pathname));
    printf("pathname=%s\n",pathname);


 
    int ffd=Socket(AF_INET,SOCK_STREAM,0);
  
    //链接服务器
    Connect(ffd,(struct sockaddr*)&serv_addr,sizeof(struct sockaddr_in));
        

    int fd = open(pathname, O_RDONLY);

    printf(">>>\n");

	int r_size = 0;
	int w_size = 0;
	char buf[1024];
	char buf2[20];
	r_size = read(ffd,buf,sizeof(buf));
	if(strncmp(buf, "success", 10) != 0)
	{
		printf("收到服务端异常数据\n");
		getch();
		return NULL;
	}
    printf("?????\n");
    if(fd<0)
	{
		printf("文件不存在\n");
        write(ffd, "error", 6);
		close(ffd);
		pthread_exit(NULL);
	}
	else
	{
       /* //请求连接服务器
        PACK request;
        request.flag=SEND_FILE;
        strcpy(request.data,"start");
        request.len=strlen(request.data);

        char request_buf[BUFSIZ];
        memset(request_buf,0,sizeof(request_buf));
        memcpy(request_buf,&request,sizeof(request));

        if(send(ffd,request_buf,sizeof(request_buf),0)<0)
        {
            my_err("send error",__LINE__);
        }

		usleep(100000);*/
        
        write(ffd, "success", 8);
		usleep(100000);
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
        write(ffd, filename, strlen(filename) + 1);

		usleep(100000);

        memset(buf, 0, sizeof(buf));
		r_size = read(ffd, buf, sizeof(buf));
		if(strncmp(buf, "success", 10) != 0)
		{
			printf("收到服务端异常数据\n");
			getch();
			return NULL;
		}
		else
		{
			printf("收到服务端返回success\n");
		}
		
		sleep(1);
        /*PACK request;
        request.flag=SEND_FILE;
        strcpy(request.data,filename);
        request.len=strlen(request.data)+1;

        char request_buf[BUFSIZ];
        memset(request_buf,0,sizeof(request_buf));
        memcpy(request_buf,&request,sizeof(request));

        if(send(ffd,request_buf,sizeof(request_buf),0)<0)
        {
            my_err("send error",__LINE__);
        }*/
	

        /*char recv[10];
        memset(recv,0,sizeof(recv));
        Recv_file_pack(ffd,recv,sizeof(recv));

        if(strncmp(recv,"start",10) != 0)
		{
			pthread_exit(NULL);
		}

        printf("成功收到服务端返回值:%s\n",recv);*/


		//设置文件读写位置为文件尾部
		lseek(fd, 0, SEEK_END);
		// 获取文件字节数（尾部位置）
		off_t end_pos = lseek(fd, 0, SEEK_CUR);
		//pf("end_pos:%d\n", end_pos);
		//设置文件读写位置为文件头部
		lseek(fd, 0, SEEK_SET);

		do
		{
			//pf("  进入while循环...\n");
			r_size = read(fd, buf, 1024);

			printf("[读取文件字节数:%d ", r_size);

			w_size = write(ffd, buf, r_size);
			printf("发送字节数:%d ", w_size);

			read(ffd, buf2, sizeof(buf2));
			if(strncmp(buf2, "success", 10) == 0)
			{
				printf("成功收到服务端返回的success]\n");
			}
			usleep(10000);

			off_t cur_pos = lseek(fd, 0, SEEK_CUR);
			//pf("cur_pos:%d\n", cur_pos);
			if(cur_pos == end_pos && w_size == 1024)
			{
				char end[1] = "\0";
				printf("[读取文件字节数:1 ");
				w_size = write(ffd, end, sizeof(end));
				printf("发送字节数:%d ", w_size);
				read(ffd, buf2, sizeof(buf2));
				
				if(strncmp(buf2, "success", 10) == 0)
				{
					printf("成功收到服务端返回的success]\n");
				}
				else
				{
					printf("收到服务端返回的异常数据:%s]\n", buf2);
				}
				break;
			}
		} while (r_size == 1024);

		close(fd);

		char result[20];
		read(ffd, result, sizeof(result));
		if(strncmp(buf2, "success", 10) == 0)
		{
			printf("成功收到服务端返回值:%s,服务器接收文件成功\n", result);
		}
		else if(strncmp(buf2, "error", 10) == 0)
		{
			printf("成功收到服务端返回值:%s,服务器接收文件异常\n", result);
		}
		else
		{
			printf("收到服务端返回值:%s,数据异常\n", result);
		}
			
		getch();
	}

	return NULL;
}
int Recv_file_pack(int cfd,char *data,int len)
{
    //接收数据类型
    int flag;
    memset(&flag,0,sizeof(flag));
    if(read(cfd,&flag,sizeof(flag))<0)
    {
        my_err("read",__LINE__);
    }

    //接收数据长度
    int len1;
    memset(&len1,0,sizeof(len1));
    if(read(cfd,&len1,sizeof(len1))<0)
    {
        my_err("read",__LINE__);
    }
    printf("client recv_pack len:%d\n",len1);
    printf("client recv_pack flag:%d\n",flag);

    //接收数据
    int ret;
    //memset(data,0,sizeof(data));

    if((ret=read(cfd,data,len1)<0))
    {
        my_err("recv",__LINE__);
    }
    printf("client recv_pack data:%s\n",data);
    return ret;
}
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
}
