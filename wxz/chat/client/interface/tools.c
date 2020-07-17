#include "client.h"
void my_err(const char* err_string,int line)
{
    fprintf(stderr,"line:%d",line);
    perror(err_string);
    exit(1);
}
void display(char* str)
{
    int i;
    system("clear");
    for(i=0;i<50;i++)
        putchar('-');
    putchar('\n');
    printf("       %s\n",str);
    for(i=0;i<50;i++)
        putchar('-');
    putchar('\n');
    return;
}
char getch()
{
	char ch;

    system("stty -echo");//不回显
    system("stty -icanon");//设置一次性读完操作，如使用getchar()读操作,不需要按回车
    ch = getchar();
    system("stty icanon");//取消上面的设置
    system("stty echo");//回显

    return ch;
}
void Input_password()
{
    
}
char* Get_string(char* buf,int len)
{
    char* str;
    int i=0;
    str=fgets(buf,len,stdin);
	if(str!=NULL)
	{
		while(str[i]!='\0' && str[i]!='\n')
			i++;
		if(str[i]=='\n')
			str[i]='\0';
		else
			while(getchar()!='\n')
				continue;
	}
	return str;
}

int Send_cmessage(int flag,int receiver,char* buf)
{
    char str[BUFSIZ];
    chat_message msg;
    msg.flag=flag;
    strcpy(msg.msg,buf);
    msg.send=enternum;
    msg.receive=receiver;
    memcpy(str,&msg,sizeof(msg));
    if(send(cfd,str,BUFSIZ,0)==-1)
    {
        my_err("send error",__LINE__);
        return 0;
    }
    return 1;
}

int Send_smessage(int flag,int receiver,int sender,char *buf)
{
    char str[BUFSIZ];
    chat_message msg;
    msg.flag=flag;
    strcpy(msg.msg,buf);
    msg.send=sender;
    msg.receive=receiver;
    memcpy(str,&msg,sizeof(msg));
    
    if(send(cfd,str,BUFSIZ,0)==-1)
    {
        my_err("send error",__LINE__);
        return 0;
    }
    return 1;
}
int Send_message(int flag,char* buf)
{
    char str[BUFSIZ];
    message msg;
    msg.flag=flag;
    strcpy(msg.msg,buf);
    memcpy(str,&msg,sizeof(msg));
    if(send(cfd,str,BUFSIZ,0)==-1)
    {
        my_err("send error",__LINE__);
        return 0;
    }
    return 1;
}