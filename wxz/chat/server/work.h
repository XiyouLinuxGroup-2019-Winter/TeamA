#include "server.h"

void *work(void *arg);


void Add_friend(PACK* recv_pack);
void Del_friend();
void Query_friend();
void Private_chat(PACK* recv_pack);
void Shield_friend();
void Unshield_friend();
void Show_friend_status();
void View_friend_list();
void View_chat_history();

void Create_group();
void Add_group();
void Withdraw_group();
void View_add_group();
void View_group_member();
void View_group_record();



void Del_group();
void Set_group_admin();
void Kick();



void Send_file();


//记录离线消息
void Log_downline_message();
//从文件中读取好友信息到链表
int Add_friend_infor_to_list(friend_list_t head,pthread_rwlock_t lock,char* name);