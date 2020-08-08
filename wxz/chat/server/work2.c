#include "final.h"
void *work(void* arg)
{
    PACK* pack_t;
    pack_t=(PACK*)arg;

    switch(pack_t->flag)
    {
        case LOGIN:
            Login(pack_t);
            break;
        case REGISTER:
            Register(pack_t);
            break;
        case ADD_FRIEND:
            Add_friend(pack_t);
            break;
        case DEL_FRIEND:
            Del_friend(pack_t);
            break;
        case QUERY_FRIEND:
            //Query_friend(pack_t);
            break;
        case PRIVATE_CHAT:
            Private_chat(pack_t);
            break;
        //写在一起比较好
        case SHOW_FRIEND_STATUS:
            Show_friend_status(pack_t);
        case VIEW_FRIEND_LIST:
            View_friend_list(pack_t);
            break;
        case VIEW_CHAT_HISTORY:
            //View_chat_history(pack_t);
            break;
        case SHIELD:
            Shield_friend(pack_t);
            break;
        case UNSHIELD:
            Unshield_friend(pack_t);
            break;
        case CREAT_GROUP:
            Create_group(pack_t);
            break;
        case ADD_GROUP:
            Add_group(pack_t);
            break;
        case WITHDRAW_GROUP:
            Withdraw_group(pack_t);
            break;
        case VIEW_ADD_GROUP:
            View_add_group(pack_t);
            break;
        case VIEW_GROUP_MEMBER:
            View_group_member(pack_t);
            break;        
        case VIEW_GROUP_RECORD:
            //View_group_record(pack_t);
            break;
        case DEL_GROUP:
            Del_group(pack_t);
            break;
        case SET_GROUP_ADMIN:
            //Set_group_admin(pack_t);
            break;
        case KICK:
            //Kick(pack_t);
            break;
        case SEND_FILE:
            //Send_file(pack_t);
            break;
        case GROUP_CHAT:
            Group_chat(pack_t);
            break;
        case 0:
            break;
    }
    return NULL;
}
void Register(PACK* pack_t)
{
    char register_flag[10];
    int flag;
    char buf[MAX];

    server_list_t pos;
    for(pos=list_ser->next;pos!=list_ser;pos=pos->next)
    {
        if(strcmp(pos->data.username,pack_t->data.send_name)==0)
        {
            printf("pos:%s\n%s\n",pos->data.username,pos->data.password);
            flag=1;
            break;
        }
    }

    server_user_node_t *new;
    new=(server_user_node_t*)malloc(sizeof(server_user_node_t));

    if(flag==0)
    {
        strcpy(new->data.username,pack_t->data.send_name);
        strcpy(new->data.password,pack_t->data.message);
        new->data.online=DOWNLINE;
        new->data.friend_num=0;
        new->data.group_num=0;
        
        //链表尾插法，list为头指针，new为新节点
        List_AddTail(list_ser,new);
        user_num++;


        memset(buf,0,sizeof(buf));
        sprintf(buf,"insert into account values('%s','%s','%d')",pack_t->data.send_name,pack_t->data.message,pos->data.online);
        mysql_real_query(&mysql,buf,strlen(buf));
        register_flag[0]='1';
    }
    else
    {
        register_flag[0]='0';
    }
    register_flag[1]='\0';

    Send_recv_pack(pack_t->data.send_fd,pack_t,register_flag);
    free(pack_t);
}
//登录
void Login(PACK* pack_t)
{
    char login_flag[10];
    int ret;
    int flag=0;
    
    
    server_list_t pos;
    for(pos=list_ser->next;pos!=list_ser;pos=pos->next)
    {
        if((strcmp(pos->data.username,pack_t->data.send_name)==0)&&(strcmp(pos->data.password,pack_t->data.message)==0))
        {
            printf("pos:%s\n%s\n",pos->data.username,pos->data.password);
            flag=1;
            
            break;
        }
    }

    
    //没有注册
    if(flag==0)
        login_flag[0]='2';
    else
    {
        //账号已经登录
        if(pos->data.online==ONLINE)
            login_flag[0]='3';
        else if(pos->data.online==DOWNLINE)
        {
            //登录成功
            login_flag[0]='1';
            pos->data.online=ONLINE;
            pos->data.connfd=pack_t->data.send_fd;
        }
        else
        {
            //密码错误
            login_flag[0]='0';
        }
    }
    login_flag[1]='\0';

    Send_recv_pack(pack_t->data.send_fd,pack_t,login_flag);
    
    free(pack_t);
}

void Add_friend(PACK* pack_t)
{

    int flag=ADD_FRIEND_APPLY;
    char buf[MAX];
    int flag_t;
    int flag_tt;
    friend_list_t pos;

    char flag_add[10];
    
    for(pos=friend_ser->next;pos!=friend_ser;pos=pos->next)
    {
        if((strcmp(pos->data.username,pack_t->data.send_name)==0)&&(strcmp(pos->data.friend_name,pack_t->data.recv_name)==0))
        {
            printf("pos:%s\n%s\n",pos->data.username,pos->data.friend_name);
            flag_t=1;
        }
    }


    if(flag_t==0)
    {
        
        server_list_t pos_friend;
    
        for(pos_friend=list_ser->next;pos_friend!=list_ser;pos_friend=pos_friend->next)
        {
            if((strcmp(pos_friend->data.username,pack_t->data.recv_name)==0))
            {
                printf("pos_friend:%s\n,password:%s\n",pos_friend->data.username,pos_friend->data.password);
                flag_tt=1;      
            }
        }
        //好友不存在
        if(flag_tt==0)
        {
            flag_add[0]='3';
            flag_add[1]='\0';
            Send_pack_type(pack_t->data.send_fd,flag,pack_t,flag_add);
            return ;
        }
        else
        {
            if(pack_t->data.message[0]=='0')
            {
                flag=ADD_FRIEND_APPLY;
                flag_add[0]='0';

                flag_add[1]='\0';
                //更改接受者名字
                char recv_name_t[MAX];
                strcpy(recv_name_t,pack_t->data.recv_name);
                strcpy(pack_t->data.recv_name,pack_t->data.send_name);
                strcpy(pack_t->data.send_name,recv_name_t);
                Send_pack_type(pos_friend->data.connfd,flag,pack_t,flag_add);
            }
            else if(pack_t->data.message[0]=='y')
            {
                friend_node_t *new=(friend_node_t*)malloc(sizeof(friend_node_t));

                flag_add[0]='1';
                strcpy(new->data.username,pack_t->data.recv_name);
                strcpy(new->data.friend_name,pack_t->data.send_name);
                new->data.status=1;//朋友

                pos_friend->data.friend_num++;

                List_AddTail(friend_ser,new);

                memset(buf,0,sizeof(buf));
                sprintf(buf,"insert into friend values('%s','%s','%d')",pack_t->data.recv_name,pack_t->data.send_name,1);
                mysql_real_query(&mysql,buf,strlen(buf));
                
                char recv_name_t[MAX];
                strcpy(recv_name_t,pack_t->data.recv_name);
                strcpy(pack_t->data.recv_name,pack_t->data.send_name);
                strcpy(pack_t->data.send_name,recv_name_t);
                Send_pack_type(pos_friend->data.connfd,flag,pack_t,flag_add);

            }
            else if(pack_t->data.message[0]=='n')
            {
                flag_add[0]='2';
                char recv_name_t[MAX];
                strcpy(recv_name_t,pack_t->data.recv_name);
                strcpy(pack_t->data.recv_name,pack_t->data.send_name);
                strcpy(pack_t->data.send_name,recv_name_t);
                Send_pack_type(pos_friend->data.connfd,flag,pack_t,flag_add);
            }
        }
    }
    //已经为好友
    else if(flag_t==1)
    {
        flag_add[0]='4';
        Send_pack_type(pack_t->data.send_fd,flag,pack_t,flag_add);
        return ;
    }
    /*se_pos_friendrver_list_t pos;
    server_list_t pos_friend;
    pos=Find_server_user(pack_t->data.send_name);
    pos_friend=Find_server_user(pack_t->data.message);

    strcpy(pos->data.friend_message[ (pos->data.friend_num) ++],pack_t->data.message);
    //strcpy(pos->data.friend_message[ (pos->data.friend_num) ++],pos_friend->data.username);
    strcpy(pos_friend->data.friend_message[ (pos_friend->data.friend_num) ++],pack_t->data.send_name);
    //strcpy(pos_friend->data.friend_message[ (pos_friend->data.friend_num) ++],pos->data.username);
    
    free(pack_t);*/
    
}

void Del_friend(PACK* pack_t)
{
    char buf[MAX];
    int flag=DEL_FRIEND_APPLY;
    char flag_del[10];
    int flag_t;

    friend_list_t pos;

    for(pos=friend_ser->next;pos!=friend_ser;pos=pos->next)
    {
        if((strcmp(pos->data.username,pack_t->data.send_name)==0)&&(strcmp(pos->data.friend_name,pack_t->data.message)==0))
        {
            printf("pos:%s\n%s\n",pos->data.username,pos->data.friend_name);
            flag_t=1;
        }
    }

    server_list_t pos_user;
    pos_user=Find_server_user(pack_t->data.send_name);
    if(pos_user)
    {
        if(flag_t==1)
        {
        
                //从链表中删除并释放结点node    //从链表中删除并释放结点node
                List_FreeNode(pos);

                memset(buf,0,sizeof(buf));
                sprintf(buf,"delete from friend where username='%s' and friend_name='%s'",pack_t->data.send_name,pack_t->data.message);
                mysql_real_query(&mysql,buf,strlen(buf));
                flag_del[0]='1';
                Send_pack_type_name(pack_t->data.send_fd,flag,pack_t,flag_del);
                pos_user->data.friend_num--; 
                memset(buf,0,sizeof(buf));
                sprintf(buf,"delete from friend where username='%s' and friend_name='%s'",pack_t->data.send_name,pack_t->data.message);
                mysql_real_query(&mysql,buf,strlen(buf));
                flag_del[0]='1';
                Send_pack_type_name(pack_t->data.send_fd,flag,pack_t,flag_del);
            
            
        }
    }
    else if(pos_user==NULL || flag_t==0)
    {
        flag_del[0]='0';
        Send_pack_type_name(pack_t->data.send_fd,flag,pack_t,flag_del);
    }
    


    /*server_list_t pos;
    server_list_t pos_friend;

    pos=Find_server_user(pack_t->data.send_name);
    Find_del_server_user(pos,pack_t->data.message);

    pos_friend=Find_server_user(pack_t->data.message);
    Find_del_server_user(pos_friend,pack_t->data.send_name);

    free(pack_t);*/
}
/*void Query_friend(PACK* pack_t)
{
    char buf[MAX];
    int flag=QUERY_FRIEND_APPLY;
    char flag_query[10];

    int flag_t;
    friend_list_t pos;
    for(pos=friend_ser->next;pos!=friend_ser;pos=pos->next)
    {
        if((strcmp(pos->data.username,pack_t->data.send_name)==0)&&(strcmp(pos->data.friend_name,pack_t->data.message)==0)) 
        {
            flag_t=1;
            break;
        }
    }
    if(flag_t==0)
    {
        flag_query[0]='0';
        Send_pack_type_name(pack_t->data.send_fd,flag,pack_t,flag_query);
    }
    else
    {
        
        memset(buf,0,sizeof(buf));
        sprintf(buf,"select *from friend where username='%s' and friend_name='%s'",pack_t->data.send_name,pack_t->data.message);
        int ret=mysql_real_query(&mysql,buf,strlen(buf));
        if(ret)
        {
            Mysql_with_error(&mysql);
        }
        
        flag_query[0]='1';
        flag_query[1]='\0';

        Send_pack_type_name(pack_t->data.send_fd,flag,pack_t,flag_query);
    
    }

}*/
void Private_chat(PACK* pack_t)
{
    Mysql_save_message(pack_t);
    Send_pack(pack_t);
    free(pack_t);
}
void Shield_friend(PACK* pack_t)
{
    char buf[MAX];
    int flag=SHIELD_APPLY;
    char flag_shield[10];

    int flag_t;
    friend_list_t pos;
    
    for(pos=friend_ser->next;pos!=friend_ser;pos=pos->next)
    {
        if((strcmp(pos->data.username,pack_t->data.send_name)==0)&&(strcmp(pos->data.friend_name,pack_t->data.message)==0)) 
        {
            flag_t=1;
            break;
        }
    }

    if(flag_t==0)
    {
        flag_shield[0]='0';
        Send_pack_type_name(pack_t->data.send_fd,flag,pack_t,flag_shield);
    }
    else
    {
        pos->data.relation=BLACK;//屏蔽好友
        memset(buf,0,sizeof(buf));
        sprintf(buf,"update friend set status=%d where username='%s' and friend_name='%s'",pos->data.status,pack_t->data.send_name,pack_t->data.message);
        mysql_real_query(&mysql,buf,strlen(buf));

        flag_shield[0]='1';
        flag_shield[1]='\0';

        Send_pack_type_name(pack_t->data.send_fd,flag,pack_t,flag_shield);
    }
}
void Unshield_friend(PACK* pack_t)
{
    char buf[MAX];
    int flag=UNSHIELD_APPLY;
    char flag_unshield[10];

    int flag_t;
    friend_list_t pos;
    
    for(pos=friend_ser->next;pos!=friend_ser;pos=pos->next)
    {
        if((strcmp(pos->data.username,pack_t->data.send_name)==0)&&(strcmp(pos->data.friend_name,pack_t->data.message)==0)) 
        {
            flag_t=1;
            break;
        }
    }

    if(flag_t==0)
    {
        flag_unshield[0]='0';
        Send_pack_type_name(pack_t->data.send_fd,flag,pack_t,flag_unshield);
    }
    else
    {
        pos->data.relation=UNBLACK;//解除屏蔽
        memset(buf,0,sizeof(buf));
        sprintf(buf,"update friend set status=%d where username='%s' and friend_name='%s'",pos->data.status,pack_t->data.send_name,pack_t->data.message);
        mysql_real_query(&mysql,buf,strlen(buf));

        flag_unshield[0]='1';
        flag_unshield[1]='\0';

        Send_pack_type_name(pack_t->data.send_fd,flag,pack_t,flag_unshield);
    }
}
//一起实现
void View_friend_list(PACK* pack_t)
{
    int flag=VIEW_FRIEND_LIST_APPLY;
    MYSQL_RES* result;
    MYSQL_ROW row;
    char buf[MAX_CHAR];

    int rows;
    memset(buf,0,sizeof(buf));
    sprintf(buf,"select *from friend where username='%s' or friend_name='%s'",pack_t->data.send_name,pack_t->data.send_name);
    mysql_real_query(&mysql,buf,strlen(buf));

    result=mysql_store_result(&mysql);
    rows=mysql_num_rows(result);
    
    int i;
    server_list_t pos;
    pos=Find_server_user(pack_t->data.send_name);
    if(rows==0)
        pack_t->relation.friend_num=0;
    else
    {
        while((row=mysql_fetch_row(result)))
        {
            i=0;
            if(strcmp(row[0],pack_t->data.send_name)==0)
            {
                strcpy(pack_t->relation.friend_message[i],row[1]);
                pack_t->relation.friend_relation[i]=row[2][0];
                i++;
            }
            else if(strcmp(row[1],pack_t->data.send_name)==0)
            {
                strcpy(pack_t->relation.friend_message[i],row[0]);
                pack_t->relation.friend_relation[i]=row[2][0];
                i++;
            }
        }
    }
    Send_pack_type(pack_t->data.send_fd,flag,pack_t,"");

    /*char status[MAX_CHAR*2];
    char buf[MAX_CHAR];
    char name_t[MAX_CHAR];
    int cnt;

    memset(status,0,sizeof(status));
    server_list_t pos;
    pos=Find_server_user(pack_t->data.send_name);
    
    status[cnt++]=pos->data.friend_num;
    
    int i,j,k;
    for(i=1;i<=pos->data.friend_num;i++)
    {
        strcpy(name_t,pos->data.friend_message[i]);
        for(j=1;j<=user_num;j++)
        {
            if(strcmp(name_t,pos->data.username)==0)
            {
                memset(buf,0,sizeof(buf));
                if(pos->data.online==ONLINE)
                    sprintf(buf,"[%s]:[%d]",pos->data.username,ONLINE);
                else
                {
                    sprintf(buf,"[%s]:[%d]",pos->data.username,DOWNLINE);
                }
                printf("buf=%s\n",buf);
                for(k=0;k<SAVE;k++)
                    status[k+cnt]=buf[k];
                cnt+=SAVE;
            }
        }
    }

    strcpy(pack_t->data.recv_name,pack_t->data.send_name);
    strcpy(pack_t->data.send_name,"server");
    memcpy(pack_t->data.message,status,sizeof(status));
    pack_t->data.recv_fd=pack_t->data.send_fd;
    pack_t->data.send_fd=lfd;

    Send_pack(pack_t);
    free(pack_t);*/

}
void Show_friend_status(PACK* pack_t)
{
    int flag=SHOW_FRIEND_STATUS_APPLY;
    char flag_status[50];
    server_list_t pos;
    int flag_t;

    char message[50];
    for(pos=list_ser->next;pos!=list_ser;pos=pos->next)
    {
        if((strcmp(pos->data.username,pack_t->data.send_name)==0)) 
        {
            flag_t=1;
            break;
        }
    }

    if(pos->data.online==DOWNLINE)
    {
        flag_status[0]='0';
        strcpy(message,"DOWNLINE");
        strcat(flag_status,message);
        flag_status[strlen(flag_status)+1]='\0';
        Send_pack_type_name(pack_t->data.send_fd,flag,pack_t,flag_status);
    }
    else if(pos->data.online==ONLINE)
    {
        flag_status[0]='1';
        strcpy(message,"ONLINE");
        strcat(flag_status,message);
        flag_status[strlen(flag_status)+1]='\0';
        Send_pack_type_name(pack_t->data.send_fd,flag,pack_t,flag_status);
    }
}
void View_chat_history(PACK* pack_t)
{

}
void Create_group(PACK* pack_t)
{

    
    int flag=CREAT_GROUP_APPLY;
    char buf[MAX_CHAR];
    char flag_create[10];
    int flag_t;

    group_list_t pos;

    for(pos=group_ser->next;pos!=group_ser;pos=pos->next)
    {
        if((strcmp(pos->data.group_name,pack_t->data.message)==0))
        {
            printf("group_name:%s\n",pos->data.group_name);
            flag_t=1;
        }
    }

    if(flag_t==0)
    {
        flag_create[0]='1';
        group_node_t* new;
        new=(group_node_t*)malloc(sizeof(group_node_t));
        
        strcpy(new->data.group_name,pack_t->data.message);
        strcpy(new->data.group_owner,pack_t->data.send_name);
        group_num++;
        new->data.member_num=1;
        new->data.type=ONLINE;
        List_AddTail(group_ser,new);
   
        memset(buf,0,sizeof(buf));
        sprintf(buf,"insert into account_group values('%s','%s')",pack_t->data.send_name,pack_t->data.message);
        mysql_real_query(&mysql,buf,strlen(buf));
        Send_pack_type_name(pack_t->data.send_fd,flag,pack_t,flag_create);
    }
    else
    {
        flag_create[0]='0';
        Send_pack_type_name(pack_t->data.send_fd,flag,pack_t,flag_create);
    }
    


    /*strcpy(pack_t->data.recv_name,pack_t->data.send_name);
    strcpy(pack_t->data.send_name,"server");
    pack_t->data.message[0]=1;
    Send_pack(pack_t);
    free(pack_t);
    return ;
    //新建群信息
    group_node_t* new;
    new=(group_node_t*)malloc(sizeof(group_node_t));
    new->data.member_num=0;
    //群名
    strcpy(new->data.group_name,pack_t->data.message);
    //群主
    strcpy(new->data.member_name[new->data.member_num],pack_t->data.send_name);
    new->data.type[new->data.member_num]=1;
    new->data.member_num=1;

    server_user_node_t* new_user;
    new_user=Find_server_user(pack_t->data.send_name);
    strcpy(new_user->data.group[new_user->data.group_num++].group_name,pack_t->data.message);

    //链表尾插法，list为头指针，new为新节点
    List_AddTail(group_ser,new);
    group_num++;

    printf("\ngroup:%s create !\n",pack_t->data.message);

    strcpy(pack_t->data.recv_name,pack_t->data.send_name);
    strcpy(pack_t->data.send_name,"server");

    pack_t->data.message[0]=2;
    Send_pack(pack_t);
    free(pack_t);*/
}
void Add_group(PACK* pack_t)
{
    int flag=ADD_GROUP_APPLY;
    char flag_add[10];
    int flag_t;
    char buf[MAX_CHAR];

    group_list_t pos;

    for(pos=group_ser->next;pos!=group_ser;pos=pos->next)
    {
        if((strcmp(pos->data.group_name,pack_t->data.message)==0)&&(pos->data.type==ONLINE))
        {
            printf("group_name:%s\n",pos->data.group_name);
            strcpy(pack_t->data.recv_name,pos->data.group_owner);
            flag_t=1;
        }
    }
    if(flag_t==1)
    {
        server_list_t temp;
        for(temp=list_ser->next;temp!=list_ser;temp=temp->next)
        {
            if((strcmp(temp->data.username,pack_t->data.recv_name)==0))
            {
                flag_add[0]='1';
                strcpy(pack_t->message,pack_t->data.message);
                Send_pack_type(temp->data.connfd,flag,pack_t,flag_add);
                return ;
            }
        }
    }
    else if(flag_t==0)
    {
        flag_add[0]='0';
        Send_pack_type(pack_t->data.send_fd,flag,pack_t,flag_add);
    }


    if(strcmp(pack_t->data.message,"y")==0)
    {
        server_list_t pos_user;
        for(pos_user=list_ser->next;pos_user!=list_ser;pos_user=pos_user->next)
        {
            if((strcmp(pos_user->data.username,pack_t->data.recv_name)==0))
            {
               break;
            }
        }
        flag_add[0]='2';
        printf("群名%s\n",pack_t->message);
        group_node_t* new;
        new=(group_node_t*)malloc(sizeof(group_node_t));
        
        strcpy(new->data.group_name,pack_t->message);
        strcpy(new->data.group_owner,pack_t->data.send_name);
        strcpy(new->data.member_name[++(new->data.member_num)],pack_t->data.recv_name);
        printf("群人数:%d\n",new->data.member_num);
        new->data.type=ONLINE;

        pos_user->data.member_num=new->data.member_num;

        List_AddTail(group_ser,new);

        memset(buf,0,sizeof(buf));
        sprintf(buf,"insert into group_member values('%s','%s','%d','%d')",pack_t->message,pack_t->data.recv_name,pos->data.member_num,3);
        mysql_real_query(&mysql,buf,sizeof(buf));
        Send_pack_type(pos_user->data.connfd,flag,pack_t,flag_add);
    }
    else if(strcmp(pack_t->data.message,"n")==0)
    {
        server_list_t pos_user;
        for(pos_user=list_ser->next;pos_user!=list_ser;pos_user=pos_user->next)
        {
            if((strcmp(pos_user->data.username,pack_t->data.recv_name)==0))
            {
               break;
            }
        }
        flag_add[0]='3';
        Send_pack_type(pos_user->data.connfd,flag,pack_t,flag_add);
        return ;
    }
        /*strcpy(pos->data.member_name[pos->data.member_num],pack_t->data.send_name);
        pos->data.type[pos->data.member_num]=3;
        pos->data.status[pos->data.member_num]=1;
        pos->data.member_num++;


        strcpy(pack_t->data.recv_name,pack_t->data.send_name);
        strcpy(pack_t->data.send_name,"server");

        pack_t->data.message[0]=2;

        printf("\nuser:%s add group:%s successfully !\n",pack_t->data.recv_name,pack_t->data.message);

        Send_pack(pack_t);
        free(pack_t);
        return ;
    }
    strcpy(pack_t->data.recv_name,pack_t->data.send_name);
    strcpy(pack_t->data.send_name,"server");

    pack_t->data.message[0]=1;
    Send_pack(pack_t);
    free(pack_t);*/
}
void Withdraw_group(PACK* pack_t)
{

    int flag=WITHDRAW_GROUP_APPLY;
    char flag_withdraw[10];
    int flag_t;
    char buf[MAX_CHAR];

    group_list_t pos;

    for(pos=group_ser->next;pos!=group_ser;pos=pos->next)
    {
        if((strcmp(pos->data.group_name,pack_t->data.message)==0))
        {
            printf("group_name:%s\n",pos->data.group_name);
            flag_t=1;
        }
    }
    if(flag_t==1)
    {
        strcpy(pack_t->message,pack_t->data.message);
        flag_withdraw[0]='1';
        List_FreeNode(pos);

        memset(buf,0,sizeof(buf));
        sprintf(buf,"delete from group_member where group_name='%s' and member_name='%s'",pack_t->data.message,pack_t->data.send_name);
        mysql_real_query(&mysql,buf,strlen(buf));
        Send_pack_type(pack_t->data.send_fd,flag,pack_t,flag_withdraw);
        return ;
    }
    else
    {
        flag_withdraw[0]='0';
        Send_pack_type(pack_t->data.send_fd,flag,pack_t,flag_withdraw);
        return ;
    }
    /*int i,j,k;
    group_list_t pos;
    pos=Find_server_group(pack_t->data.message);
    
    for(i=1;i<=group_num;i++)
    {
        if(strcmp(pack_t->data.message,pos->data.group_name)==0)
        {
            for(j=1;j<=pos->data.member_num;j++)
            {
                if(strcmp(pack_t->data.send_name,pos->data.member_name[j])==0)
                {
                    for(k=j;k<pos->data.member_num;k++)
                    {
                        strcpy(pos->data.member_name[k],pos->data.member_name[k+1]);
                        pos->data.type[k]=pos->data.type[k+1];
                        pos->data.status[k]=pos->data.status[k+1];
                    }
                    pos->data.member_num--;
                }
            }
        }
    }*/
}
void View_add_group(PACK* pack_t)
{
    char status[MAX_CHAR*2];
    char buf[MAX_CHAR];
    char name_t[MAX_CHAR];
    int cnt;

    memset(status,0,sizeof(status));
    server_list_t pos;
    pos=Find_server_user(pack_t->data.send_name);
    
    
    status[cnt++]=pos->data.group_num;
    int i,j,k;
    for(i=1;i<=pos->data.group_num;i++)
    {
        memset(buf,0,sizeof(buf));
        strcpy(name_t,pos->data.group_message[i]);
        sprintf(buf,"[%s]",name_t);
        for(j=0;j<SAVE;j++)
            status[j+cnt]=buf[j];
        cnt+=SAVE;
    }



    strcpy(pack_t->data.recv_name,pack_t->data.send_name);
    strcpy(pack_t->data.send_name,"server");
    memcpy(pack_t->data.message,status,sizeof(status));
    pack_t->data.recv_fd=pack_t->data.send_fd;
    pack_t->data.send_fd=lfd;

    Send_pack(pack_t);
    free(pack_t);
}
void View_group_member(PACK* pack_t)
{
    char status[MAX_CHAR*2];
    int type_t;
    int status_t;
    char buf[MAX_CHAR];
    char name_t[MAX_CHAR];
    int cnt;

    memset(status,0,sizeof(status));
    group_list_t pos;
    pos=Find_server_group(pack_t->data.message);

    status[cnt++]=pos->data.member_num;

    int i,j,k;


    for(i=1;i<=pos->data.member_num;i++)
    {
        memset(buf,0,sizeof(buf));
        strcpy(name_t,pos->data.member_name[i]);
        type_t=pos->data.type[i];
        status_t=pos->data.status[i];
        sprintf(buf,"[%s]:[权限:%d]([%d])",name_t,type_t,status_t);
        for(j=0;j<SAVE;j++)
            status[j+cnt]=buf[j];
        cnt+=SAVE;
    }


    strcpy(pack_t->data.recv_name,pack_t->data.send_name);
    strcpy(pack_t->data.send_name,"server");
    memcpy(pack_t->data.message,status,sizeof(status));
    pack_t->data.recv_fd=pack_t->data.send_fd;
    pack_t->data.send_fd=lfd;

    Send_pack(pack_t);
    free(pack_t);

}
/*void View_group_record(PACK* pack_t);*/
void Group_chat(PACK* pack_t)
{
    group_list_t pos;
    pos=Find_server_group(pack_t->data.recv_name);
    char send_name[SAVE];

    int i;
    int len=strlen(pack_t->data.message);
    for(i=len;i>=0;i--)
    {
        pack_t->data.message[i+SAVE]=pack_t->data.message[i];
    }
    //把客户端消息copy
    strcpy(send_name,pack_t->data.send_name);

    for(i=0;i<SAVE;i++)
    {
        pack_t->data.message[i]=pack_t->data.send_name[i];
    }
    strcpy(pack_t->data.send_name,pack_t->data.recv_name);

    for(i=1;i<=pos->data.member_num;i++)
    {
        strcpy(pack_t->data.recv_name,pos->data.member_name[i]);
        if(strcmp(send_name,pos->data.member_name[i])!=0)
        {
            Mysql_save_message(pack_t);

            Send_pack(pack_t);
        }
    }
    free(pack_t);

}


void Del_group(PACK* pack_t)
{
    
    /*int i;
    int j;
    group_list_t pos=Find_server_group(pack_t->data.message);
    for(i=1;i<=group_num;i++)
    {
        if(strcmp(pos->data.group_name,pack_t->data.message)==0)
        {
           if(strcmp(pos->data.member_name[1],pack_t->data.send_name)==0)
           {
               //从链表中删除并释放结点node
               //
               List_FreeNode(pos);
               pack_t->data.message[0]=2;
           }
           else
           {
               pack_t->data.message[0]=1;
           }
           
        }
    }
    strcpy(pack_t->data.recv_name,pack_t->data.send_name);
    strcpy(pack_t->data.send_name,"server");

 
    Send_pack(pack_t);
    free(pack_t);*/
}
void Set_group_admin(PACK* pack_t)
{

}
void Kick(PACK* pack_t)
{

}


void sys_err(const char* s,int line)
{
    fprintf(stderr,"line:%d",line);
    perror(s);
    mysql_close(&mysql);
}

void Connect_mysql()
{
    mysql_init(&mysql);
    //初始化数据库
    mysql_library_init(0,NULL,NULL);
    if(!mysql_real_connect(&mysql,"localhost","root","wxz","bokket",0,NULL,0))
    {
        sys_err("connect error!",__LINE__);
    }
    if(mysql_set_character_set(&mysql,"utf8"))
    {
        sys_err("set error!",__LINE__);
    }
    printf("连接MYSQL数据库成功!\n");
}
void  Mysql_save_message(PACK* pack_t)
{
    char buf[MAX];
    memset(buf,0,MAX);
    
    sprintf(buf,"insert into message values('%s','%s','%s')",pack_t->data.send_name,pack_t->data.recv_name,pack_t->data.message);
    int ret;
    ret=mysql_real_query(&mysql,buf,strlen(buf));

    if(ret)
    {
        sys_err("query error！",__LINE__);
        return ;
    }
    printf("the message write into the mysql\n");

}
void Close_mysql(MYSQL mysql)
{
    mysql_close(&mysql);
    //mysql_free_result(result);
    mysql_library_end();
    printf("MYSQL数据库关闭!\n");
}
void Send_record(PACK* pack_t);
