#include "./head.h"

int master = 0;//1为群主，0为群员
int forbidden_flag = 0; //1为被禁言，0为没有被禁言
int lift_flag = 0; //1为被解禁，0为没有解禁
int non_people = 0; //1为没有找到此人
int fd;
int start = 1; //启动开关
int len;
int chat_flag = 0;
int pidchoice;
pthread_t tid;
struct sockaddr_in servaddr,cliaddr;
socklen_t addrlen,cliaddr_len;
struct msg *sm,*rm;
struct Login login;
char mypasswd[20]={0};
int kick = 0; //被踢（1）
//客户端强制退出
void sigfun()
{
	free(sm);
	free(rm);
	close(fd);
	exit(0);
}
//客户端一般退出
void close_cli()
{
	free(sm);
	free(rm);
	close(fd);
	exit(0);
}
//客户端初始化
void init_cli()
{
	//对信息进行初始化
	sm=(struct msg*)malloc(MAXSIZE);
	rm=(struct msg*)malloc(MAXSIZE);
	//socket
	fd = socket( AF_INET , SOCK_STREAM , 0 );
    if( fd < 0 )
		perror("socket error!");
	puts("socket success!");
    bzero( &servaddr , sizeof(servaddr) );
    servaddr.sin_family = AF_INET ;
    servaddr.sin_port = htons( PORT );
    servaddr.sin_addr.s_addr = inet_addr( IPNET );
	//connect
    if( connect( fd , (struct sockaddr *)&servaddr , sizeof(servaddr) ) < 0 )//连接套接字
		perror("connect error!");
	puts("connect success!");
}
//用户注册函数
void add_msg()
{
	getchar();
	//发送注册信号给服务器
	sm->type = MSG_ADD;
	sm->data_len = 0;
	if( send( fd , (void *)sm , MAXSIZE , 0 ) < 0 ) 
		perror("send_add");
	//接收来自服务器的回复
	len = recv( fd , (void *)rm , MAXSIZE , 0 );
	if( len < 0 )
		perror("add_recv_len2");
	//服务器不允许注册
	if( rm->type == MSG_UNACK )
	{
		puts("目前不能进行用户注册！");
		return;
	}
	while(1)
	{
		//输入帐号
		bzero( sm , sizeof( struct msg ));//将字符串rm前msg个字节清零
		puts("please enter your username:");
		scanf("%s",login.name);
		sm->type = MSG_DATA;
		sm->data_len = strlen(login.name);
		memcpy(sm->data,login.name,sm->data_len);//将login.name拷贝到data中
		//将帐号发送给服务器判断是否存在
		if( send( fd , (void *)sm , MAXSIZE , 0 ) < 0 ) 
			perror("send_add");
		len = recv( fd , (void *)rm , MAXSIZE , 0 );
		if( len < 0 )
			perror("add_recv_len2");
		if( rm->type == MSG_UNACK )
		{
			puts("该帐号已存在！");
			continue;
		}
		puts("该帐号可以使用！");
		while(1)
		{
			puts("please enter your passwd:");
			scanf("%s",login.passwd);
			puts("please enter your passwd again:");
			scanf("%s",mypasswd);
			if( strcmp(login.passwd,mypasswd) == 0 )
			{
				break;
			}
			else
				puts("两次密码不同，请重新输入！");
		}
		//将密码发送给服务器
		bzero( sm , sizeof( struct msg ));//将字符串rm前msg个字节清零
		sm->type = MSG_DATA;
		sm->data_len = strlen(login.passwd);
		memcpy(sm->data,login.passwd,sm->data_len);//将login.passwd拷贝到data中
		if( send( fd , (void *)sm , sizeof(struct msg) , 0 ) < 0 ) 
			perror("send_add");
		len = recv( fd , (void *)rm , MAXSIZE , 0 );
		if( len < 0 )
			perror("add_recv_len2");
		if( rm->type == MSG_ACK )
		{
			//将邮箱发送给服务器
			puts("please enter your email:");
			scanf("%s",login.email);
			bzero( sm , sizeof( struct msg ));//将字符串rm前msg个字节清零
			sm->type = MSG_DATA;
			sm->data_len = strlen(login.email);
			memcpy(sm->data,login.email,sm->data_len);
			if( send( fd , (void *)sm , sizeof(struct msg) , 0 ) < 0 ) 
				perror("send_add");
			len = recv( fd , (void *)rm , MAXSIZE , 0 );
			if( len < 0 )
				perror("add_recv_len2");
			if( rm->type == MSG_ACK )
			{
				puts("注册成功！");
				break;
			}
		}
	}
}
//更改密码函数
void chg_msg()
{
	getchar();
	//发送更改信号给服务器
	sm->type = MSG_CHANGE;
	sm->data_len = 0;
	if( send( fd , (void *)sm , MAXSIZE , 0 ) < 0 ) 
		perror("send_add");
	//接收来自服务器的回复
	len = recv( fd , (void *)rm , MAXSIZE , 0 );
	if( len < 0 )
		perror("add_recv_len2");
	//服务器不允许更改
	if( rm->type == MSG_UNACK )
	{
		puts("目前不能进行密码更改！");
		return;
	}
	//输入帐号
	bzero( sm , sizeof( struct msg ));
	puts("please enter your username:");
	scanf("%s",login.name);
	sm->type = MSG_DATA;
	sm->data_len = strlen(login.name);
	memcpy(sm->data,login.name,sm->data_len);//将login.name拷贝到data中
	//将帐号发送给服务器判断是否存在
	if( send( fd , (void *)sm , MAXSIZE , 0 ) < 0 ) 
		perror("send_add");
	len = recv( fd , (void *)rm , MAXSIZE , 0 );
	if( len < 0 )
		perror("add_recv_len2");
	if( rm->type == MSG_UNACK )
	{
		puts("该帐号不存在！");
		return;
	}
	//将邮箱发送给服务器
	puts("please enter your email:");
	scanf("%s",login.email);
	bzero( sm , sizeof( struct msg ));//将字符串sm前msg个字节清零
	sm->type = MSG_DATA;
	sm->data_len = strlen(login.email);
	memcpy(sm->data,login.email,sm->data_len);//将login.email拷贝到data中
	if( send( fd , (void *)sm , sizeof(struct msg) , 0 ) < 0 ) 
		perror("send_add");
	len = recv( fd , (void *)rm , MAXSIZE , 0 );
	if( len < 0 )
		perror("add_recv_len2");
	if( rm->type == MSG_UNACK )
	{
		puts("邮箱错误！");
		return;
	}
	//将新密码发送给服务器
	puts("please enter your newpasswd:");
	scanf("%s",login.passwd);
	bzero( sm , sizeof( struct msg ));//将字符串sm前msg个字节清零
	sm->type = MSG_DATA;
	sm->data_len = strlen(login.passwd);
	memcpy(sm->data,login.passwd,sm->data_len);//将login.passwd拷贝到data中
	if( send( fd , (void *)sm , sizeof(struct msg) , 0 ) < 0 ) 
		perror("send_add");
	puts("修改成功！");
}
//私聊
void chat_private()
{
	usleep(100);//线程挂起
	char projectName[25] = {0};
	char content[100] = {0};
	if( forbidden_flag == 1 )
	{
		printf("您已被禁言！\n");
		return;
	}
	//输入对方用户名
	getchar();
	printf("请输入对方用户名:");
	scanf("%s",projectName);
	bzero( sm , sizeof( struct msg ));//将字符串sm前msg个字节清零
	sm->type = MSG_DATA;
	sm->data_len = sizeof(projectName);
	memcpy( sm->data , projectName , sm->data_len);//将projecName拷贝到data中
	//将帐号发送给服务器判断是否存在
	if( send( fd , (void *)sm , MAXSIZE , 0 ) < 0 ) 
		perror("send_add");
	if( non_people == 1 )
	{
		puts("该用户不存在（或已离线）！");
		return;
	}
	printf("请输入要发送的内容：");
	getchar();
	fgets( content , sizeof(content) , stdin );
	bzero( sm , sizeof( struct msg ));//将字符串rm前msg个字节清零
	sm->type = MSG_PRIVATE;
	sm->data_len = strlen(content);
	memcpy( sm->data , content , sm->data_len);//将content拷贝到data中
	//将内容发送给服务器
	if( send( fd , (void *)sm , MAXSIZE , 0 ) < 0 ) 
		perror("send_add");
	if( non_people == 1 )
	{
		puts("该用户不存在（或已离线）！");
		return;
	}
}
//群聊
void chat_group()
{
	usleep(100);//线程挂起
	char content[100] = {0};
	if( forbidden_flag == 1 )
	{
		printf("您已被禁言！\n");
		return;
	}
	printf("请输入要发送的内容：");
	getchar();
	fgets( content , sizeof(content) , stdin );
	bzero( sm , sizeof( struct msg ));
	sm->type = MSG_GROUP;
	sm->data_len = strlen(content);
	memcpy( sm->data , content , sm->data_len);//将content拷贝到data中
	//将内容发送给服务器，通过服务器发送给对方
	if( send( fd , (void *)sm , MAXSIZE , 0 ) < 0 ) 
		perror("send_add");
}
//文件传输
void file_transfer()
{
	char filename[100];
	FILE *fp;
	char buf[1024]={0};
	size_t fsize;
	usleep(100);//线程挂起
	if( forbidden_flag == 1 )
	{
		printf("您已被禁言！\n");
		return;
	}
	printf("请输入需要传输的文件名:");
	scanf("%s",filename);
	fp = fopen(filename,"r");
	if(fp == NULL)
	{
		perror("openfile");
		exit(1);
	}
	rewind(fp);
	bzero( sm , sizeof(struct msg));//将字符串rm前msg个字节清零
	while((fsize = fread(sm->data,sizeof(char),sizeof(sm->data)-1,fp)))
	{
		
		sm->type = 4;
		sm->data_len = sizeof(sm->data)-1;
		if(send(fd,(void *)sm,sizeof(struct msg),0)<0)
			perror("send_add");
		if(fsize < sizeof(sm->data)-1)
			break;
		bzero( sm , sizeof(struct msg));
	}
	bzero( sm , sizeof(struct msg));
	fclose(fp);
}
//踢人
void kick_people()
{
	usleep(100);//线程挂起
	char kick_name[25]={0};
	if( master == 0 )
	{
		puts("您不是群主！");
		return;
	}
	else if( master == 1 )
	{
		getchar();
		printf("尊贵的群主，请输入你要踢的用户名称:");
		scanf("%s",kick_name);
		bzero( sm , sizeof( struct msg ));//将字符串rm前msg个字节清零
		sm->type = MSG_DATA;
		sm->data_len = sizeof(kick_name);
		memcpy( sm->data , kick_name , sm->data_len);
		if( send( fd , (void *)sm , MAXSIZE , 0 ) < 0 ) 
			perror("send_add");
		if( non_people == 1 )
		{
			puts("该用户不存在！");
			return;
		}
		puts("成功踢出！");
	}
}
//禁言
void forbidden_people()
{
	usleep(100);
	char forbidden_name[25]={0};
	if( master == 0 )
	{
		puts("您不是群主！");
		return;
	}
	else if( master == 1 )
	{
		getchar();
		printf("尊贵的群主，请输入你要禁言的用户名称:");
		scanf("%s",forbidden_name);
		bzero( sm , sizeof( struct msg ));//将字符串sm前msg个字节清零
		sm->type = MSG_DATA;
		sm->data_len = sizeof(forbidden_name);
		memcpy( sm->data , forbidden_name , sm->data_len);
		if( send( fd , (void *)sm , MAXSIZE , 0 ) < 0 ) 
			perror("send_add");
		if( non_people == 1 )
		{
			puts("该用户不存在！");
			return;
		}
		puts("成功禁言！");
	}
}
//解禁
void lift_a_ban()
{
	usleep(100);
	char lift_name[25]={0};
	if( master == 0 )
	{
		puts("您不是群主！");
		return;
	}
	else if( master == 1 )
	{
		getchar();
		printf("尊贵的群主，请输入你要解禁的用户名称:");
		scanf("%s",lift_name);
		bzero( sm , sizeof( struct msg ));//将字符串sm前msg个字节清零
		sm->type = MSG_DATA;
		sm->data_len = sizeof(lift_name);
		memcpy( sm->data , lift_name , sm->data_len);
		if( send( fd , (void *)sm , MAXSIZE , 0 ) < 0 ) 
			perror("send_add");
		if( non_people == 1 )
		{
			puts("该用户不存在！");
			return;
		}
		puts("成功解禁！");
	}
}
//用户注销
void cancellation_user()
{
	//发送请求信号给服务器
	sm->type = 0;
	sm->data_len = 0;
	if( send( fd , (void *)sm , MAXSIZE , 0 ) < 0 ) 
		perror("send_add");//输出错误原因
}
//接收函数
void *server_receive()
{
	while(1)
	{
		bzero( rm , sizeof( struct msg ));//将字符串sm前msg个字节清零
		recv( fd , (void *)rm , MAXSIZE , 0 );
		if( rm->type == MSG_PRIVATE )//接受私聊消息
		{
			printf("\n");
			puts(rm->data);
		}
		else if( rm->type == MSG_GROUP ) //接收群发消息
		{
			printf("\n");
			puts(rm->data);
		}
		else if( rm->type == MSG_FILE )
		{
		}
		else if( rm->type == MSG_NUM ) //在线人数打印
		{
			printf("\n当前在线人数为：%s\n",rm->data);
		}
		else if( rm->type == MSG_KICK )
		{
			kick = 1;
			cancellation_user();//用户注销
			chat_flag = 1;
			printf("\n你已被踢出群聊！请按任意键继续\n");
			pthread_cancel(tid);
		}
		else if( rm->type == MSG_MASTER )
		{
			master = 1; //代表是群主
		}
		else if( rm->type == MSG_UNMASTER )
		{
			master = 0; //代表不是群主
		}
		else if( rm->type == MSG_FORBIDDEN )
		{
			forbidden_flag = 1; //被禁言
			lift_flag = 0; //没有被解禁
		}
		else if( rm->type == MSG_LIFT )
		{
			printf("您已被解除禁言！\n");
			forbidden_flag = 0; //被禁言
			lift_flag = 1; //被解禁
		}
		else if( rm->type == MSG_PEOPLE )
		{
			non_people = 0;
		}
		else if( rm->type == MSG_NONPEOPLE )
		{
			non_people = 1;
		}
	}
}
//聊天界面
void chat_menu() 
{
	int ret = 0;
	//创建子进程
	ret = pthread_create(&tid, NULL, server_receive, NULL);
    if(0 != ret)
        perror("pthread_create");//输出错误原因
	while(start)
	{
		int choice;
		if( kick == 0)
		{
			puts(" ---------------------------------- ");
			puts(" ---------------------------------- ");
			puts(" -------   聊天群功能界面：   ------ ");
			puts(" ---------------------------------- ");
			puts(" ---------1:在线人数查询------------ ");
			puts(" ---------2:私聊-------------------- ");
			puts(" ---------3:群聊-------------------- ");
			puts(" ---------4:文件传输---------------- ");
			puts(" ---------5:踢人（限群主使用）------- ");
			puts(" ---------6:禁言（限群主使用）------- ");
			puts(" ---------7:解禁（限群主使用）------- ");
			puts(" ---------0:注销-------------------- ");
			puts(" ----------------------------------- ");
			puts(" ----------------------------------- ");
			printf("please choice one:");
			scanf("%d",&choice);
			switch(choice)
			{
				case 1:
						sm->type = 1; //在线人数查询
						sm->data_len = 0;
						if( send( fd , (void *)sm , MAXSIZE , 0 ) < 0 ) 
						perror("send_add");//输出错误原因
						break;
				case 2:
						sm->type = 2;
						sm->data_len = 0;
						if( send( fd , (void *)sm , MAXSIZE , 0 ) < 0 ) 
						perror("send_add");//输出错误原因
						chat_private(); //私聊
						break;
				case 3:
						sm->type = 3;
						sm->data_len = 0;
						if( send( fd , (void *)sm , MAXSIZE , 0 ) < 0 ) 
						perror("send_add");//输出错误原因
						chat_group();//群聊
						break;
				case 4:
						bzero(sm,sizeof(struct msg));
						sm->type = 4;
						sm->data_len = 0;
						if( send( fd , (void *)sm , MAXSIZE , 0 ) < 0 ) 
						perror("send_add");//输出错误原因
						file_transfer();//文件传输
						break;
				case 5:
						sm->type = 5;
						sm->data_len = 0;
						if( send( fd , (void *)sm , MAXSIZE , 0 ) < 0 ) 
						perror("send_add");//输出错误原因
						kick_people();//踢人
						break;
				case 6:
						sm->type = 6;
						sm->data_len = 0;
						if( send( fd , (void *)sm , MAXSIZE , 0 ) < 0 ) 
						perror("send_add");//输出错误原因
						forbidden_people();//禁言
						break;
				case 7:
						sm->type = 7;
						sm->data_len = 0;
						if( send( fd , (void *)sm , MAXSIZE , 0 ) < 0 ) 
						perror("send_add");//输出错误原因
						lift_a_ban();//解禁
						break;
				case 0:
						cancellation_user();//用户注销
						pthread_cancel(tid);//输出错误原因
						chat_flag = 1;
						break;
				default:
						puts(" ---  enter right choice  --- ");
						continue;
			}
			if( chat_flag == 1 )
			{
				break;
			}
		}
		else
		{
			getchar();
			break;
		}
	}	
}
//用户登录函数
void login_msg()
{
	getchar();
	//发送登录信号给服务器
	sm->type = MSG_LOGIN;
	sm->data_len = 0;
	if( send( fd , (void *)sm , MAXSIZE , 0 ) < 0 ) 
		perror("send_add");//输出错误原因
	//接收来自服务器的回复
	len = recv( fd , (void *)rm , MAXSIZE , 0 );
	if( len < 0 )
		perror("add_recv_len2");//输出错误原因
	//服务器不允许登录
	if( rm->type == MSG_UNACK )
	{
		puts("目前不能进行用户登录！");
		return;
	}
	//输入帐号
	bzero( sm , sizeof( struct msg ));
	puts("please enter your username:");
	scanf("%s",login.name);
	sm->type = MSG_DATA;
	sm->data_len = strlen(login.name);
	memcpy(sm->data,login.name,sm->data_len);
	//将帐号发送给服务器判断是否存在
	if( send( fd , (void *)sm , MAXSIZE , 0 ) < 0 ) 
		perror("send_add");//输出错误原因
	len = recv( fd , (void *)rm , MAXSIZE , 0 );
	if( len < 0 )
		perror("add_recv_len2");//输出错误原因
	if( rm->type == MSG_UNACK )
	{
		puts("该帐号不存在！");
		return;
	}
	//输入密码
	bzero( sm , sizeof( struct msg ));
	puts("please enter your passwd:");
	scanf("%s",login.passwd);
	sm->type = MSG_DATA;
	sm->data_len = strlen(login.passwd);
	memcpy(sm->data,login.passwd,sm->data_len);
	//将密码发送给服务器判断是否正确
	if( send( fd , (void *)sm , MAXSIZE , 0 ) < 0 ) 
		perror("send_add");//输出错误原因
	len = recv( fd , (void *)rm , MAXSIZE , 0 );
	if( len < 0 )
		perror("add_recv_len2");//输出错误原因
	if( rm->type == MSG_UNACK )
	{
		puts("密码错误！");
		return;
	}
	//发送登录信号，查看是否已经在线
	sm->type = MSG_LOGIN;
	sm->data_len = 0;
	if( send( fd , (void *)sm , MAXSIZE , 0 ) < 0 ) 
		perror("send_add");//输出错误原因
	//接收来自服务器的回复
	len = recv( fd , (void *)rm , MAXSIZE , 0 );
	if( len < 0 )
		perror("add_recv_len2");//输出错误原因
	//用户已经在线
	if( rm->type == MSG_UNACK )
	{
		puts("用户登录已达上限！");
		return;
	}
	//调用聊天菜单
	chat_menu();
}
//用户退出函数
void logout_msg()
{
	//发送退出信号给服务器
	sm->type = MSG_LOGOUT;
	sm->data_len = 0;
	if( send( fd , (void *)sm , MAXSIZE , 0 ) < 0 ) 
		perror("send_add");//输出错误原因
	puts("成功退出！");
}
//菜单
void cli_menu()
{
	int menu_flag = 0;
	while(start)
	{
		int choice;
		puts(" ----------------------- ");
		puts(" ----------------------- ");
		puts(" ---      choice：   --- ");
		puts(" -------1:用户注册------- ");
		puts(" -------2:更改密码------- ");
		puts(" -------3:用户登录------- ");
		puts(" -------4:用户退出------- ");
		puts(" ----------------------- ");
		puts(" ----------------------- ");
		printf("please choice one:");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1:
						add_msg(); //用户注册
						break;
			case 2:
						chg_msg(); //更改密码
						break;
			case 3:
						login_msg();//用户登录
						break;
			case 4:
						logout_msg();//用户退出
						menu_flag = 1;
						close_cli();
						break;
			default:
						puts(" ---  enter right choice  --- ");
						continue;
		}
		if( menu_flag == 1 )
		{
			break;
		}
	}
}
int main()
{
	signal(SIGINT,sigfun);
	init_cli();
	cli_menu();
	return 0;
}

