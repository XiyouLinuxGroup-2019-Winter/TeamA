#include "final.h"
void sys_err(const char* s,int line,MYSQL mysql)
{
    fprintf(stderr,"line:%d,why:%s",line,mysql_error(&mysql));
    perror(s);
    mysql_close(&mysql);
}

void Connect_mysql(MYSQL mysql)
{
    mysql_init(&mysql);
    //初始化数据库
    mysql_library_init(0,NULL,NULL);
    if(!mysql_real_connect(&mysql,"localhost","root","wxz","bokket",0,NULL,0))
    {
        sys_err("连接失败!",__LINE__,&mysql);
    }
    if(mysql_set_character_set(&mysql,"utf8"))
    {
        sys_err("设置中文字符集失败!",__LINE__,&mysql);
    }
    printf("连接MYSQL数据库成功!\n");
}

void Use_mysql(const char *string, MYSQL mysql)
{
	int i;
	MYSQL_RES   *result;
	MYSQL_ROW   row;
	MYSQL_FIELD *field;

	if(mysql_query(&mysql, string))
    {
        sys_err("发送MYSQL语句失败！",__LINE__,&mysql);
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
void Mysql_save_message(PACK* pack_t)
{
    char buf[MAX];
    memset(buf,0,MAX);
    
    sprintf(buf,"insert into message values('%s','%s','%s')",pack_t->data.send_name,pack_t->data.recv_name,pack_t->data.message);
    int ret;
    ret=mysql_real_query(&mysql,buf,strlen(buf));

    if(ret)
    {
        sys_err("发送MYSQL语句失败！",__LINE__,&mysql);
        return ;
    }
    printf("the message write into the mysql\n");

}
void Close_mysql(MYSQL mysql)
{
    mysql_close(&mysql);
    mysql_free_result(result);
    mysql_library_end();
    printf("MYSQL数据库关闭!\n");
}
void Send_record(PACK* pack_t);

