#include "server.h"
#include "common.h"
#include "prest.h"
#include "work.h"

void *work(void* arg)
{
    PACK* recv_pack_t;
    recv_pack_t=(PACK*)arg;
    switch (recv_pack_t.flag)
    {
        case LOGIN:
            Login(recv_pack_t);
            break;
        case REGISTER:
            register(recv_pack_t);
            break;
        case ADD_FRIEND:
            Add_friend(recv_pack_t);
            break;
        case DEL_FRIEND:
            Del_friend(recv_pack_t);
            break;
        case QUERY_FRIEND:
            Query_friend(recv_pack_t);
            break;
        case VIEW_FRIEND_LIST:
            View_friend_list(recv_pack_t);
            break;
        case SHOW_FRIEND_STATUS:
            Show_friend_status(recv_pack_t);
            break;
        case VIEW_CHAT_HISTORY:
            View_chat_history(recv_pack_t);
            break;
        case SHIELD:
            Shield_friend(recv_pack_t);
            break;
        case UNSHIELD:
            Unshield_friend(recv_pack_t);
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
