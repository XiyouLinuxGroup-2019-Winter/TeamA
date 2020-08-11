#include "server.h"
int main()
{

}
void Init_socket()
{

    PACK recv_t;
    PACK *recv_pack;
    printf("服务端启动\n");
    struct sockaddr_in serv_addr;
    struct sockaddr_in cli_addr;

    socklen_t cli_addr_len;

    lfd=Socket(AF_INET,SOCK_STREAM,0);

    //端口复用
    int opt=1;
    setsockopt(lfd,SOL_SOCKET,SO_REUSEADDR,(void*)&opt,sizeof(opt));

    bzero(&serv_addr,sizeof(serv_addr));

    serv_addr.sin_family=AF_INET;
    serv_addr.sin_port=htons(SERV_PORT);
    serv_addr.sin_addr.s_addr=htonl(INADDR_ANY);

    Bind(lfd,(struct sockaddr*)&serv_addr,sizeof(serv_addr));
    Listen(lfd,128);

    printf("服务器启动成功!\n");

    epfd=epoll_create(1024);
    struct epoll_event tep,ep[1024];
    tep.events=EPOLLIN;
    tep.data.fd=lfd;
    epoll_ctl(epfd,EPOLL_CTL_ADD,lfd,&tep);

    while(1)
    {
        ret=epoll_wait(epfd,ep,1024,-1);
        for(i=0;i<ret;i++)
        {
            if (!(ep[i].events & EPOLLIN))      //如果不是"读"事件, 继续循环
                continue;

            if(ep[i].data.fd==lfd)
            {
                cli_addr_len=sizeof(cli_addr);
                cfd=Accept(lfd,(struct sockaddr*)&cli_addr,&cli_addr_len);
                printf("连接到新的客户端ip:%s\n端口号:%d\n",inet_ntoa(cli_addr.sin_addr),cli_addr.sin_port);
                tep.events=EPOLLIN;
                tep.data.fd=cfd;
                epoll_ctl(epfd,EPOLL_CTL_ADD,cfd,&tep);
            }
            else if(ep[i].events & EPOLLIN)
            {
                int n=recv(ep[i].data.fd,&recv_t,sizeof(PACK),0);
                recv_t.data.send_fd=events[i].data.fd;

                Recv_pack_message(recv_t);

                if(n<0)
                {
                    close(ep[i].data.fd);
                    sys_err("接收错误!",__LINE__);
                    continue;
                }
                else if(n==0)
                {
                    for(int i=0;i<=user_num;i++)
                    {
                        if(ep[i].data.fd==user[i].sid)
                        {
                            printf("%s已下线\n",user[i].username);
                            user[i].status=DOWNLINE;
                            break;
                        }
                    }
                    tep.data.fd=ep[i].data.fd;
                    epoll_ctl(epfd,EPOLL_CTL_DEL,ep[i].data.fd,&tep);
                    close(ep[i].data.fd);
                    continue;
                }
                recv_pack=(PACK*)malloc(sizeof(PACK));
                memcpy(recv_pack,&recv_t,sizeof(PACK));


                pthread_create(&pid,NULL,Work,(void*)recv_pack)
            }
            
        }
    }
}



    
    memset(buf,0,sizeof(buf));
      
    if(pack_t->flag==VIEW_CHAT_HISTORY)
    {
        sprintf(buf,"select send_name from chat_message where send_name='%s' and recv_name='%s' or send_name='%s' and recv_name='%s'",send_name,recv_name,recv_name,send_name);
    }
    if(pack_t->flag==VIEW_GROUP_RECORD)
    {
        sprintf(buf,"select send_name from group_message where recv_name='%s'",pack_t->data.message);            
    }
   


    int ret_t=mysql_real_query(&mysql,buf,strlen(buf));
    
    if(ret_t) 
    {
       Mysql_with_error(&mysql);
       return ;
    }
    
    MYSQL_RES* result_t=mysql_store_result(&mysql);                             
    
    if(result_t==NULL)
    {
        Mysql_with_error(&mysql);     
        return ;
    }

    //行数
    int rows_t=mysql_num_rows(result);                                    
    printf("rows:%d\n",rows_t);                        
    //列数
    int fields_t=mysql_num_fields(result); 
    printf("fields is:%d\n",fields_t);  

    
    //============================================================================================
    
    
    
    
    
    
    
    
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

    
    
    
    
    
    
    
    
    
    
    
    
    
