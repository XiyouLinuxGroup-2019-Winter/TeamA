#include "mysql.h"
#include "List.h"
#include "common.h"


void Recv_pack_message(PACK recv_t);
void display(char* str);
void my_err(const char* err_string,int line);
char* Get_string(char* buf,int len);
char getch();
void Clear_buffer();
void Send_recv_pack(int fd,PACK* recv_pack,char* flag);
server_list_t Find_server_user(char *username);
void Find_del_server_user(server_list_t pos,char* friend_name);
group_list_t Find_server_group(char* group_name);
void Read_from_mysql();