#include "server.h"
#include "common.h"
#include "prest.h"
#include "work.h"
#include "tools.h"
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
            case VIEW_FRIEND_LIST:
                View_friend_list(pack_t);
                break;
            case SHOW_FRIEND_STATUS:
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
    char buf[BUFSIZ];

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

        memset(buf,0,sizeof(buf));
        sprintf(buf,"insert into userinfo values('%s','%s')",pack_t->data.send_name,pack_t->data.message);
        mysql_real_query(&mysql,buf,strlen(buf));
        register_flag[0]='1';
    }
    else
    {
        register_flag[0]='0';
    }
    register_flag[1]='\0';

    Send_pack(pack_t->data.send_fd,pack_t,register_flag);
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

    Send_pack(pack_t->data.send_fd,pack_t,login_flag);
    
    free(pack_t);
}
void Add_friend(PACK* pack_t)
{
    char buf[BUFSIZ];
    memset(buf,0,sizeof(BUFSIZ));

    printf("%s\n",pack_t->data.message);

}
