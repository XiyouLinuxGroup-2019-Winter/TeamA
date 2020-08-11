#include "final.h"
MYSQL mysql;
int main()
{
    Connect_mysql();
    Use_mysql("insert into account username='wxz'",mysql);
    Close_mysql(mysql);
}
void sys_err(const char* s,int line)
{
    fprintf(stderr,"line:%d",line);
    perror(s);
    mysql_close(&mysql);
}

void Connect_mysql()
{
    mysql_init(&mysql);
    //初始化数据库
    mysql_library_init(0,NULL,NULL);
    if(!mysql_real_connect(&mysql,"localhost","root","wxz","bokket",0,NULL,0))
    {
        sys_err("connect error!",__LINE__);
    }
    if(mysql_set_character_set(&mysql,"utf8"))
    {
        sys_err("set error!",__LINE__);
    }
    printf("连接MYSQL数据库成功!\n");
}
/*void Mysql_save_message(PACK* pack_t)
{
    char buf[MAX];
    memset(buf,0,MAX);
    
    sprintf(buf,"insert into message values('%s','%s','%s')",pack_t->data.send_name,pack_t->data.recv_name,pack_t->data.message);
    int ret;
    ret=mysql_real_query(&mysql,buf,strlen(buf));

    if(ret)
    {
        sys_err("query error！",__LINE__);
        return ;
    }
    printf("the message write into the mysql\n");

}*/
void Close_mysql(MYSQL mysql)
{
    mysql_close(&mysql);
    //mysql_free_result(result);
    mysql_library_end();
    printf("MYSQL数据库关闭!\n");
}

void Use_mysql(const char *string, MYSQL mysql)
{
	int i;
	MYSQL_RES   *result;
	MYSQL_ROW   row;
	MYSQL_FIELD *field;

	if(mysql_query(&mysql, string))
    {
        sys_err("query error！",__LINE__);
    }

	int fields;
	result=mysql_store_result(&mysql);
    if(result==NULL)
    {
        sys_err("store error!\n",__LINE__);
    }
    else
    {
       while((fields=mysql_num_fields(result)))
            printf("%-20s",field->name);
        printf("\n");

        while((row=mysql_fetch_row(result)))
        {
	        for(i=0;i<mysql_num_fields(result);i++)
            {
                if(row[i])
		            printf("%-20s\n",row[i]);
            }
            printf("\n");
        }
        mysql_free_result(result);
    }
}
