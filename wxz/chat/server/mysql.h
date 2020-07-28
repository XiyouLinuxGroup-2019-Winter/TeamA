#include <mysql/mysql.h>
#include <stdio.h>

void sys_err(const char* s,int line);
void Connect_mysql(MYSQL mysql);
void Use_mysql(const char *string, MYSQL mysql);
void Close_mysql(MYSQL mysql);