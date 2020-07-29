#include "server.h"
#include "common.h"
#include "prest.h"
#include "work.h"

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
void Add_friend(PACK* pack_t)
{
    char buf[BUFSIZ];
    memset(buf,0,sizeof(BUFSIZ));

    printf("%s\n",pack_t->data.message);
    
}
