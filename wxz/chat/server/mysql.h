#include "mysql/mysql.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>



void sys_err(const char* s,int line);
void Connect_mysql();
void Use_mysql(const char *string, MYSQL mysql);
void Close_mysql(MYSQL mysql);


