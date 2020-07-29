#include "server.h"
#include "common.h"
#include "prest.h"
#include "work.h"

void *work(void* arg)
{
    char buf[BUFSIZ];

    int *cnt;
    cnt=(int*)arg;

    friend_list_t list_friend;
    List_Init(list_friend,friend_node_t);
    head=list_friend;
    pthread_rwlock_init(&lock,NULL);


    server_list_t pos;
    server_user_t data;
    for(pos=list_ser->next;pos!=list_ser;pos=pos->next)
    {
        if(pos->data.connfd==*cnt)
        {    
            data=pos->data;
            break;
        }
    }

    //从文件中读取用户好友进链表
    Add_friend_infor_to_list(head,lock,data.username);





    while(recv(*cnt,buf,sizeof(buf),0)<0)
    {
        //从文件中读取用户好友进链表
       Add_friend_infor_to_list(head,lock,data.username);
     
        //从文件中读取链表进内存
       Read_linked_list_into_memory(list_ser);
    

        PACK *pack_t;
        memcpy(pack_t,buf,sizeof(BUFSIZ));

        switch(pack_t.flag)
        {
            case LOGIN:
                Login(&pack_t);
                break;
            case REGISTER:
                Register(&pack_t);
                break;
            case ADD_FRIEND:
                Add_friend(&pack_t);
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
void Add_friend(PACK* recv_pack)
{
    
}



void Private_chat(PACK* recv_pack)
{
    server_list_t pos;
    server_user_t data;
    char buf[BUFSIZ];

    memcpy(buf,recv_pack->data,sizeof(PACK));
    printf("the server get:%s\n",recv_pack->data.message);
    for(pos=list_ser->next;pos!=list_ser;pos=pos->next)
    {
        if(strcmp(recv_pack->data.recv_name,pos->data.username)==0)
        {
            data=pos->data;
            break;
        }
    }
    if(data.online==0)
    {
        //记录离线消息
        Log_downline_message(recv_pack->data,recv_pack->data.recv_name);


    }
    else
    {
        send(data.connfd,buf,sizeof(buf),0);
    }
}

//从文件中读取好友信息到链表
int Add_friend_infor_to_list(friend_list_t head,pthread_rwlock_t lock,char* name)
{
     int ret;
     pthread_rwlock_wrlock(&lock);
     ret=Read_friendlinked_list_from_file(head,name);
     pthread_rwlock_unlock(&lock);
     if(ret==0)
     {
         printf("fread error!",__LINE__);
         return 0;
     }
     return 1;
 } 