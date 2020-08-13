#include "chat.h"
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
        case DEL_GROUP:
            Del_group(pack_t);
            break;
        case SET_GROUP_ADMIN:
            Set_group_admin(pack_t);
            break;
        case KICK:
            Kick(pack_t);
            break;
        case GROUP_CHAT:
            Group_chat(pack_t);
            break;
        case SEND_FILE:
            //Send_file(pack_t);
            break;
        case VIEW_CHAT_HISTORY:
        case VIEW_GROUP_RECORD:
            Send_record(pack_t);
            break;
        case 0:
            break;
    }
}