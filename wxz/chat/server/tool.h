#include "client.h"
int Send_cmessage(int flag,int receiver,char* buf);
int Send_smessage(int flag,int receiver,int sender,char *buf);
int Send_message(int flag,char* buf);
void Send_pack_message(int flag,char *send_name,char* recv_name,char* message);





void display(char* str);
void my_err(const char* err_string,int line);
char* Get_string(char* buf,int len);
char getch();
