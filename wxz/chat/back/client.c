#include "client.h"

void register()
{
    char user_buf[BUFSIZ];
    REGISTER_INFO user;
    while(1)
    {
        memset(&user,0,sizeof(REGISTER_INFO));
        user.flag=1;
        printf("请输入用户名:");
        Get_string(user.username,10);
        printf("请输入密码:");
        Get_string(user.password,10);
        memset(user_buf,0,sizeof(user_buf));
        memcpy(user_buf,&user,sizeof(REGISTER_INFO));
        if(send(cfd,user_buf,BUFSIZ,0)!=BUFSIZ)
        {
            my_err("send error",__LINE__);
        }
        memset(user_buf,0,sizeof(user_buf));
        recv(cfd,user_buf,sizeof(user_buf),0);
        if()
    }
    
}