#include <mysql/mysql.h>
#include <stdio.h>

void sys_err(const char* s,int line);
MYSQL Connect_mysql();
int Use_mysql(const char *string, MYSQL mysql);
int Close_mysql(MYSQL mysql);