#include "List.h"
#include "common.h"
#include "server.h"




 //从文件中读取链表
int Read_linked_list_from_file(server_list_t list);

//将信息写入文件
int Write_infor_to_file(server_user_t* data);

//更新用户信息
int Update_user_info(server_user_t* data);

//将日志写入文件
int Add_syslog(syslog_t* data)；

//写日志文件进文件
int Make_syslog(server_user_t tmp,char* string);

//从文件中读取链表
int Read_friendlinked_list_from_file(friend_list_t list,char* name);

//将朋友信息写入文件
int Write_friendinfor_to_file(FRIEND_INFO* data,char* name);

//将朋友信息从文件删除
int Byname_delete_friend(char* name,char* opt);

//从文件中读取链表进内存
int Read_linked_list_into_memory(server_list_t list);

//添加一个新用户到文件
int Add_new_user_to_file(server_user_t* data);

//查找链表中是否有这个用户
int Find_server_user(server_list_t list_ser,char *username,char *password,int cfd);

//下线更改在线状态
int Downline_change_status(server_user_t* data);

int login(int connfd,server_user_t *tmp,struct sockaddr_in cli_addr,server_list_t list);