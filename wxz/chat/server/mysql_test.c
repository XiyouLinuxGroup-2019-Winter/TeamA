#include "mysql.h"
#include "common.h"
void sys_err(const char* s,int line,MYSQL* mysql)
{
    fprintf(stderr,"line:%d,why:%s",line,mysql_error(mysql));
    perror(s);
    mysql_close(&mysql);
}

