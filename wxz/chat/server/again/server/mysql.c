#include "chat.h"
void Connect_mysql()
{
    mysql_init(&mysql);
    //初始化数据库
    mysql_library_init(0,NULL,NULL);
    if(!mysql_real_connect(&mysql,"47.94.14.45","Linux_7136","18861757136","chat_room_7136",0,NULL,0))
    {
        sys_err("connect error!",__LINE__);
    }
    if(mysql_set_character_set(&mysql,"utf8"))
    {
        sys_err("set error!",__LINE__);
    }
    //printf("连接MYSQL数据库成功!\n");
    printf("connect mysql success\n");
}