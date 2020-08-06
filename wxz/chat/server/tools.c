#include "final.h"
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
    printf("\033[1;33m|\033[0m 接受包的名字  :%s\n",recv_t.data.recv_name);
    printf("\033[1;33m|\033[0m 信息  :%s\n",recv_t.data.message);
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

    printf("%s\n",pack_send.data.message);
    pack_send.data.recv_fd=pack_send.data.send_fd;
    pack_send.data.send_fd=fd;

    if(send(fd,&pack_send,sizeof(PACK),0)<0)
    {
        my_err("send error!",__LINE__);
    }
}
void Send_pack_type(int fd,int type,PACK* recv_pack,char* flag)
{
    PACK pack_send;
    char recv_name_t[MAX];
    memcpy(&pack_send,recv_pack,sizeof(PACK));
    printf("%s\n%s\n",pack_send.data.recv_name,pack_send.data.send_name);


    strcpy(recv_name_t,pack_send.data.recv_name);
    pack_send.flag=type;
    strcpy(pack_send.data.recv_name,pack_send.data.send_name);
    strcpy(pack_send.data.send_name,recv_name_t);
    strcpy(pack_send.data.message,flag);
    printf("%d\n",pack_send.flag);
    printf("%s\n%s\n",pack_send.data.recv_name,pack_send.data.send_name);

    printf("%s\n",pack_send.data.message);
    pack_send.data.recv_fd=pack_send.data.send_fd;
    pack_send.data.send_fd=fd;
   
    
    if(send(fd,&pack_send,sizeof(PACK),0)<0)
    {
        my_err("send error!",__LINE__);
    }
}
void Send_pack_type_name(int fd,int type,PACK* recv_pack,char* flag)
{
    PACK pack_send;
    memcpy(&pack_send,recv_pack,sizeof(PACK));
 
    pack_send.flag=type;
    strcpy(pack_send.data.recv_name,pack_send.data.send_name);
    strcpy(pack_send.data.send_name,pack_send.data.message);
    strcpy(pack_send.data.message,flag);
    printf("%d\n",pack_send.flag);
    printf("%s\n%s\n",pack_send.data.recv_name,pack_send.data.send_name);

    printf("%s\n",pack_send.data.message);

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
    memcpy(&(pack_send[send_num++]),send_pack_t,sizeof(PACK));
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
        strcpy(pos->data.friend_message[i],pos->data.friend_message[i+1]);
    }
    pos->data.friend_num--;
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
            printf("pos:%s\n",pos->data.group_name);
            return pos;
        }
    }
    return NULL;
}

void Read_from_mysql()
{

    //初始化链表list。链表为带头结点的双向循环链表
    List_Init(list_ser,server_user_node_t);
    List_Init(group_ser,group_node_t);


    Server_user(list_ser);
    Server_friend(friend_ser);
    Server_group(group_ser);
    Server_group_member(group_ser);


}
void Server_user(server_list_t list_ser)
{
    MYSQL_ROW row;//行
    MYSQL_RES* result;
    char buf[MAX];
    int rows;
    int fields;
    sprintf(buf,"select *from account");
    mysql_real_query(&mysql,buf,strlen(buf));

    result=mysql_store_result(&mysql);
    rows=mysql_num_rows(result);//行
    fields=mysql_num_fields(result);//列

    while((row=mysql_fetch_row(result)))
    {
        server_user_node_t* new;
        new=(server_user_node_t*)malloc(sizeof(server_user_node_t));
        strcpy(new->data.username,row[0]);
        strcpy(new->data.password,row[1]);
        new->data.online=DOWNLINE;
        
    
        List_AddTail(list_ser,new);
        user_num++;
        
    }
    server_list_t pos;
    pos=list_ser;
    list_ser=list_ser->next;

    List_DelNode(pos);
}
void Server_friend(friend_list_t friend_ser)
{
    MYSQL_ROW row;//行
    MYSQL_RES* result;
    char buf[MAX];
    int rows;
    int fields;

    server_list_t pos;
    pos=list_ser;
    int num=0;
    while(num!=user_num)
    {
        sprintf(buf,"select *from friend where name_1=%s",pos->data.username);
        mysql_real_query(&mysql,buf,strlen(buf));
        result=mysql_store_result(&mysql);
    
        rows=mysql_num_rows(result);//行
        fields=mysql_num_fields(result);//列


        int i=0;
        while((row=mysql_fetch_row(result)))
        {


            for(pos=list_ser->next,i=0;pos!=list_ser;pos=pos->next,i++)
            {
                if((strcmp(pos->data.username,row[0])==0))
                {
                    strcpy(pos->data.friend_message[i],row[1]);
                    i++;
                    continue;
                }
            }
            
        }
        num++;
        pos->data.friend_num=rows;

    }
}
void Server_group(group_list_t group_ser)
{
    MYSQL_ROW row;//行
    MYSQL_RES* result;
    char buf[MAX];
    int rows;
    int fields;
    sprintf(buf,"select *from group");
    mysql_real_query(&mysql,buf,strlen(buf));

    result=mysql_store_result(&mysql);
    rows=mysql_num_rows(result);//行
    fields=mysql_num_fields(result);//列

    group_num=0;
    while((row=mysql_fetch_row(result)))
    {
        group_node_t* new;
        new=(group_node_t*)malloc(sizeof(group_node_t));
        strcpy(new->data.group_name,row[0]);
       
        new->data.member_num=row[1][0];
        
    
        List_AddTail(group_ser,new);
        group_num++;
        
    }
    group_list_t pos;
    pos=group_ser;
    group_ser=group_ser->next;

    List_DelNode(pos);    

}

void Server_group_member(group_list_t group_ser)
{
    MYSQL_ROW row;//行
    MYSQL_RES* result;
    char buf[MAX];
    int rows;
    int fields;

    group_list_t pos;
    pos=group_ser;
    int num=0;
    while(num!=user_num)
    {
        sprintf(buf,"select *from group_number where group_name=%s",pos->data.group_name);
        mysql_real_query(&mysql,buf,strlen(buf));
        result=mysql_store_result(&mysql);
    
        rows=mysql_num_rows(result);//行
        fields=mysql_num_fields(result);//列


        int i=0;
        while((row=mysql_fetch_row(result)))
        {


           strcpy(pos->data.member_name[i],row[1]);
           pos->data.status[i]=row[2][0];

           pos->data.type[i]=row[3][0];
           i++;


            
        }
        num++;
        pos=pos->next;
    }
}

