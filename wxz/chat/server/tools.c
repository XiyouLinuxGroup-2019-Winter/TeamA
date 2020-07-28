#include "tools.h"
void my_err(const char* err_string,int line)
{
    fprintf(stderr,"line:%d",line);
    perror(err_string);
    exit(1);
}
void Clear_buffer()
{
    char ch;
    while(getchar()!='\n')
		continue;
    /*while((ch=getchar())!='\n' && ch!=EOF)
            continue;*/
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
void Recv_pack_message(PACK recv_t)
{
    printf("\n\033[1;33m--------PACK--------\033[0m\n");
    printf("\033[1;33m|\033[0m 类型  :\n");
    printf("\033[1;33m|\033[0m 发送包的名字  :%s\n",recv_t.data.send_name);
    printf("\033[1;33m|\033[0m 接受包的名字  :%d\n",recv_t.data.recv_name);
    printf("\033[1;33m|\033[0m 信息  :%d\n",recv_t.data.message);
    printf("\033[1;33m|\033[0m 发送者fd  :%d\n",recv_t.data.send_fd);
    printf("\033[1;33m|\033[0m 接收者fd  :%d\n",recv_t.data.recv_fd);
    printf("\033[1;33m|\033[0m 发送包的数量:%d\n",send_num);
    printf("\033[1;33m---------------------\033[0m\n");
}