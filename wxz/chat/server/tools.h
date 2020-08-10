#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <errno.h>
#include <pthread.h>
#include <unistd.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <arpa/inet.h>


void display(char* str);
void my_err(const char* err_string,int line);
char* Get_string(char* buf,int len);
char getch();
void Clear_buffer();

void Recv_pack_message(PACK recv_t);//收到包的信息
void Send_recv_pack(int fd,PACK* recv_pack,char* flag);
void Send_pack(PACK* send_pack_t);
void Send_pack_type(int fd,int type,PACK* recv_pack,char* flag);

void Mysql_with_error(MYSQL* mysql);

server_list_t Find_server_user(char *username);
void Find_del_server_user(server_list_t pos,char* friend_name);
group_list_t Find_server_group(char* group_name);
void Read_from_mysql();
void Server_user(server_list_t list_ser);
void Server_friend(friend_list_t friend_ser);
void Server_group(group_list_t group_ser);
void Server_group_member(group_list_t group_ser);
