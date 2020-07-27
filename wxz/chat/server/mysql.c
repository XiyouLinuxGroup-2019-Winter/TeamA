#include "mysql.h"
void sys_err(const char* s,int line,MYSQL* mysql)
{
    fprintf(stderr,"line:%d,why:%s",line,mysql_error(mysql));
    perror(s);
    exit(1);
}

MYSQL Connect_mysql()
{
    MYSQL mysql;
    mysql_init(&mysql);
    mysql_library_init(0,NULL,NULL);
    if(!mysql_real_connect(&mysql,"localhost","root","wxz","test",0,NULL,0))
    {
        sys_err("连接失败!",__LINE__,&mysql);
    }
    if(mysql_set_character_set(&mysql,"utf8"))
    {
        sys_err("设置中文字符集失败!",__LINE__,&mysql);
    }
    printf("连接MYSQL数据库成功!\n");
    return mysql;
}

int Use_mysql(const char *string, MYSQL mysql)
{
	int i;
	MYSQL_RES   *result;
	MYSQL_ROW   row;
	MYSQL_FIELD *field;

	if(mysql_query(&mysql, string))
    {
        sys_err("发生MYSQL语句失败！",__LINE__,&mysql);
    }

	
	result=mysql_store_result(&mysql);
    if(result==NULL)
    {
        sys_err("查询失败!\n",__LINE__,&mysql);
    }
    else
    {
       while((field=mysql_num_fields(result))
            printf("%-20s",field->name);
        printf("\n");

        while(row=mysql_fetch_row(result))
        {
	        for(i=0;i<mysql_num_fields(result);i++)
            {
                if(row[i])
		            printf("%-20s\n",cols[i]);
            }
            printf("\n");
        }
        mysql_free_result(result);
    }
}
int Close_mysql(MYSQL mysql)
{
    mysql_close(&mysql);
    mysql_library_end();
    printf("MYSQL数据库关闭!\n");
}
