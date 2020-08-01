#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <mysql/mysql.h>

#define MAX 50
#define MAX_CHAR 300


MYSQL mysql;
void sys_err(const char* s,int line);
void Connect_mysql(MYSQL mysql);
void Use_mysql(const char *string, MYSQL mysql);
void Close_mysql(MYSQL mysql);
void Mysql_save_message(PACK* pack_t);
void Send_record(PACK* pack_t);