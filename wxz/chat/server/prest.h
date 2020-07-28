#include "List.h"
#include "common.h"
#include "server.h"
 //从文件中读取链表
int Read_linked_list_from_file(server_list_t list);
//将信息写入
int Write_infor_to(server_user_t* data);
//将信息写入
int Update_user_info(server_user_t* data);
//将日志写入文件
int Add_syslog(syslog_t* data);

int Make_syslog(server_user_t tmp,char* string);
