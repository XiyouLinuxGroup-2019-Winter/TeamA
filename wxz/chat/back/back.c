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
                Query_friend(pack_t);
                break;
            case PRIVATE_CHAT:
                Private_chat(pack_t);
                break;
            //写在一起比较好
            case SHOW_FRIEND_STATUS:
            case VIEW_FRIEND_LIST:
                Show_friend_status(pack_t);
                break;
            case VIEW_CHAT_HISTORY:
                View_chat_history(pack_t);
                break;
            case SHIELD:
                Shield_friend(pack_t);
                break;
            case UNSHIELD:
                Unshield_friend(pack_t);
                break;
            case CREAT_GROUP:
                Create_group();
                break;
            case ADD_GROUP:
                Add_group();
                break;
            case WITHDRAW_GROUP:
                Withdraw_group();
                break;
            case VIEW_ADD_GROUP():
                View_add_group();
                break;
            case VIEW_GROUP_MEMBER:
                View_group_member();
                break;        
            case VIEW_GROUP_RECORD:
                View_group_record();
                break;
            case DEL_GROUP():
                Del_group();
                break;
            case SET_GROUP_ADMIN:
                Set_group_admin();
                break;
            case KICK:
                Kick();
                break;
            case SEND_FILE:
                Send_file();
                break;
            case 0:
                break;
        }
    }

}
void Register(PACK* pack_t)
{
    char register_flag[10];
    int flag;
    char buf[MAX];

    server_list_t pos;
    for(pos=list_ser->next;pos!=list_ser;pos=pos->next)
    {
        if((strcmp(pos->data.username,username)==0)
        {
            printf("pos:%s\n%s\n",pos->data.username.pos->data.password);
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
        
        //链表尾插法，list为头指针，new为新节点
        List_AddTail(list_ser,new);
        user_num++;


        memset(buf,0,sizeof(buf));
        sprintf(buf,"insert into account values('%s','%s')",pack_t->data.send_name,pack_t->data.message);
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
        if((strcmp(pos->data.username,username)==0)&&strcmp(pos->data.password,pack_t->data.message)==0)
        {
            printf("pos:%s\n%s\n",pos->data.username.pos->data.password);
            flag=1;
            
            break;
        }
    }

    //账号已经登录
    if(flag==1)
    {
        if(pos->data.online==ONLINE)
            login_flag[0]='3';
    }

    //密码不正确
    if(flag==0)
        login_flag[0]='0';
    else
    {
        if(pos->data.online==DOWNLINE)
        {
            //登录成功
            login_flag[0]='1';
            pos->data.online=ONLINE;
            pos->data.connfd=pack_t->data.send_fd;
        }
        else
        {
            //账号不存在
            login_flag[0]='2';
        }
    }
    login_flag[1]='\0';

    Send_recv_pack(pack_t->data.send_fd,pack_t,login_flag);
    
    free(pack_t);
}

void Add_friend(PACK* pack_t)
{
    server_list_t pos;
    server_list_t pos_friend;
    pos=Find_server_user(pack_t->data.send_name);
    pos_friend=Find_server_user(pack_t->data.message);

    strcpy(pos->data.friend_message[ (pos->data.friend_num) ++],pack_t->data.message);
    //strcpy(pos->data.friend_message[ (pos->data.friend_num) ++],pos_friend->data.username);
    strcpy(pos_friend->data.friend_message[ (pos_friend->data.friend_num) ++],pack_t->data.send_name);
    //strcpy(pos_friend->data.friend_message[ (pos_friend->data.friend_num) ++],pos->data.username);
    
    free(pack_t);
}
void Del_friend(PACK* pack_t)
{
    server_list_t pos;
    server_list_t pos_friend;

    pos=Find_server_user(pack_t->data.send_name);
    Find_del_server_user(pos,pack_t->data.message);

    pos_friend=Find_server_user(pack_t->data.message);
    Find_del_server_user(pos_friend,pack_t->data.send_name);

    free(pack_t);
}
/*void Query_friend(PACK* pack_t)
{
    
}*/
void Private_chat(PACK* pack_t)
{
    Mysql_save_message(pack_t);
    Send_pack(pack_t);
    free(pack_t);
}
/*void Shield_friend(PACK* pack_t);
void Unshield_friend(PACK* pack_t);*/
void Show_friend_status(PACK* pack_t);
{
    char status[MAX_CHAR2*2];
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
                    sprintf(buf,"[%s]:[%d]\0",pos->data.username,ONLINE);
                else
                {
                    sprintf(buf,"[%s]:[%d]\0",pos->data.username,DOWNLINE);
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
    memcpy(pack_t->date.message,status,sizeof(status));
    pack_t->data.recv_fd=pack->data.send_fd;
    pack_t->data.send_fd=lfd;

    Send_pack(pack_t);
    free(pack_t);
}

/*void View_friend_list(PACK* pack_t);*/
//void View_chat_history(PACK* pack_t);
void Create_group(PACK* pack_t)
{

    
    int flag;
    group_list_t pos;

    pos=Find_server_group(pack_t->data.message);

    if(pos!=NULL)
    {
        strcpy(pack_t->data.recv_name,pack_t->data.send_name);
        strcpy(pack_t->data.send_name,"server");
        pack_t->data.message[0]=1;
        Send_pack(pack_t);
        free(pack_t);
        return ;
    }

    //新建群信息
    friend_node_t* new;
    new=(friend_node_t*)malloc(sizeof(friend_node_t));
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
    free(pack_t);
}
void Add_group(PACK* pack_t)
{
    group_list_t pos;
    pos=Find_server_group(pack_t->data.message);
    if(pos!=NULL)
    {
        strcpy(pos->data.member_name[pos->data.member_num],pack_t->data.send_name);
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
    free(pack_t);
}
void Withdraw_group(PACK* pack_t)
{
    int i,j,k;
    group_list_t pos;
    pos=Find_server_group(pack_t->data.message);
    
    for(i=1;i<=group_num;i++)
    {
        if(strcmp(pack_t->data.message,pos->data.group_name[i])==0)
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
    }
}
void View_add_group(PACK* pack_t)
{
    char status[MAX_CHAR2*2];
    char buf[MAX_CHAR];
    char name_t[MAX_CHAR];
    int cnt;

    memset(status,0,sizeof(status));
    group_list_t pos;
    pos=Find_server_group(pack_t->data.message);
    
    
    status[cnt++]=pos->data.group_num;
    int i,j,k;
    for(i=1;i<=pos->data.group_num;i++)
    {
        memset(buf,0,sizeof(buf));
        strcpy(name_t,pos->data.group_message[i]);
        sprintf(buf,"[%s]\0",name_t);
        for(j=0;j<SAVE;j++)
            status[j+cnt]=buf[j];
        cnt+=SAVE;
    }



    strcpy(pack_t->data.recv_name,pack_t->data.send_name);
    strcpy(pack_t->data.send_name,"server");
    memcpy(pack_t->date.message,status,sizeof(status));
    pack_t->data.recv_fd=pack->data.send_fd;
    pack_t->data.send_fd=lfd;

    Send_pack(pack_t);
    free(pack_t);
}
void View_group_member(PACK* pack_t)
{
    char status[MAX_CHAR2*2];
    char type_t[MAX_CHAR];
    char status_t[MAX_CHAR];
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
        strcpy(type_t,pos->data.type[i]);
        strcpy(status_t,pos->data.status[i]);
        sprintf(buf,"[%s]:[权限:%s]([%s])\0",name_t,type_t,status_t);
        for(j=0;j<SAVE;j++)
            status[j+cnt]=buf[j];
        cnt+=SAVE;
    }


    strcpy(pack_t->data.recv_name,pack_t->data.send_name);
    strcpy(pack_t->data.send_name,"server");
    memcpy(pack_t->date.message,status,sizeof(status));
    pack_t->data.recv_fd=pack->data.send_fd;
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
    int i;
    int j;
    group_list_t pos=Find_server_group(pack_t->data.message);
    for(i=1;i<=group_num;i++)
    {
        if(strcmp(pos->data.group_name[i],pack_t->data.message)==0)
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
    free(pack_t);
}
/*void Set_group_admin(PACK* pack_t);
void Kick(PACK* pack_t);*/
