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
void Send_recv_pack(int fd,PACK* recv_pack,char* flag)
{
    PACK pack_send;
    
    memcpy(&pack_send,recv_pack,sizeof(PACK));
    printf("%s\n%s\n",pack_send.data.recv_name,pack_send.data.send_name);

    strcpy(pack_send.data.recv_name,pack_send.data.send_name);
    strcpy(pack_send.data.send_name,"server");
    strcpy(pack_send.data.message,flag);
    printf("%s\n%s\n",pack_send.data.recv_name,pack_send.data.send_name);

    printf("s\n",pack_send.data.message);
    pack_send.data.recv_fd=pack_send.data.send_fd;
    pack_send.data.send_fd=fd;

    if(send(fd,&pack_send,sizeof(PACK),0)<0)
    {
        my_err("send error!",__LINE__);
    }
}
void Send_pack(PACK* send_pack_t)
{
    pthread_mutex_lock(&mutex);
    memcpy(&(send_pack[send_num++]),send_pack_t,sizeof(PACK));
    pthread_mutex_unlock(&mutex);
}
server_list_t Find_server_user(char *username)
{
    if(user_num==0)
        return NULL;
    
    server_list_t pos=list_ser;
    if(pos==NULL)
        return NULL;
    for(pos=list_ser->next;pos!=list_ser;pos=pos->next)
    {
        if((strcmp(pos->data.username,username)==0))
        {
            printf("pos:%s\n%s\n",pos->data.username,pos->data.password);
            return pos;
        }
    }
    return NULL;
}
void Find_del_server_user(server_list_t pos,char* friend_name)
{
    int i;
    int index;
    for(pos=list_ser->next,i=0;pos!=list_ser;pos=pos->next,i++)
    {
        if((strcmp(pos->data.friend_message[i],friend_name)==0))
        {
            printf("pos:%s\n%s\n",pos->data.username,pos->data.password);
            index=i;
        }
    }
    for(pos=list_ser->next,i=index;pos!=list_ser;pos=pos->next,i++)
    {
        strcpy(pos->data.friend_message[i],pos->data.frined_message[i+1]);
    }
    pos->data.frined_num--;
}

group_list_t Find_server_group(char* group_name)
{
    group_list_t pos=group_ser;
    if(group_num==0)
        return NULL;
    if(pos==NULL)
        return NULL;
    for(pos=group_ser->next;pos!=group_ser;pos=pos->next)
    {
        if((strcmp(pos->data.group_name,group_name)==0))
        {
            printf("pos:%d\n%s\n",pos->data.group_num,pos->data.group_name);
            return pos;
        }
    }
    return NULL;
}