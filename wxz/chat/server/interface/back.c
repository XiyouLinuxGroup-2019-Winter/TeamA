#include "client.h"
#include "tools.c"
void Add_friend()
{
    char name_buf[BUFSIZ];
    message msg;
    char username_buf[15];
    memset(&msg,0,sizeof(message));
    memset(name_buf,0,BUFSIZ);
    memcpy(msg.from,username_buf,15);
    display("请输入要添加的好友账号:");
    Get_string(msg.username,15);
    memcpy(name_buf,&msg,sizeof(message));
    if(send(cfd,name_buf,BUFSIZ,0)!=BUFSIZ)
    {
        my_err("send error!",__LINE__);
    }
    return;
}
void Del_friend()
{
    char name_buf[BUFSIZ];
    message msg;
    char username_buf[15];
    memset(&msg,0,sizeof(message));
    memset(name_buf,0,BUFSIZ);
    memcpy(msg.from,username_buf,15);
    display("请输入要删除的好友账号:");
    Get_string(msg.username,15);
    memcpy(name_buf,&msg,sizeof(message));
    if(send(cfd,name_buf,BUFSIZ,0)!=BUFSIZ)
    {
        my_err("send error!",__LINE__);
    }
    return;
}
void Query_friend()
{
    char name_buf[BUFSIZ];
    message msg;
    char username_buf[15];
    memset(&msg,0,sizeof(message));
    memset(name_buf,0,BUFSIZ);
    memcpy(msg.from,username_buf,15);
    display("请输入要查询的好友账号:");
    Get_string(msg.username,15);
    memcpy(name_buf,&msg,sizeof(message));
    if(send(cfd,name_buf,BUFSIZ,0)!=BUFSIZ)
    {
        my_err("send error!",__LINE__);
    }
    return;
}
void View_friend_list()
{
    char name_buf[BUFSIZ];
    message msg;
    char username_buf[15];
    memset(&msg,0,sizeof(message));
    memset(name_buf,0,BUFSIZ);
    memcpy(msg.from,username_buf,15);
    memcpy(name_buf,&msg,sizeof(message));
    if(send(cfd,name_buf,BUFSIZ,0)!=BUFSIZ)
    {
        my_err("send error!",__LINE__);
    }
    return;
}
void Show_friend_status()
{
    char name_buf[BUFSIZ];
    message msg;
    char username_buf[15];
    memset(&msg,0,sizeof(message));
    memset(name_buf,0,BUFSIZ);
    memcpy(msg.from,username_buf,15);
    memcpy(name_buf,&msg,sizeof(message));
    if(send(cfd,name_buf,BUFSIZ,0)!=BUFSIZ)
    {
        my_err("send error!",__LINE__);
    }
    return;
}
void Private_chat()
{
    char name_buf[BUFSIZ];
    message msg;
    FILE* fp;
    char username_buf[15];
    memset(&msg,0,sizeof(message));
    memset(name_buf,0,BUFSIZ);
    memcpy(msg.from,username_buf,15);
    printf("请输入想私聊的好友账号:");
    Get_string(username_buf,15);
    printf("[---------------]正在加载")
    sleep(1);
    system("clear");
    printf("[---------------]正在与%s聊天(quit退出)\n",username_buf);
    while(1)
    {
        memcpy(name_buf,&msg,sizeof(message));
        if(send(cfd,name_buf,BUFSIZ,0)!=BUFSIZ)
        {
            my_err("send error!",__LINE__);
        }
        return;
}
void Friend_message()
{
    int i;
    message msg;
    message msg_t[100];
    msg=msg_t[n];
    printf("[验证消息]您有一个新的消息:[来自%s查找]\n");
    printf("--------用户%s想成为您好友----------\n",msg.from);
    printf("--------同意输入[y],不同意输入[n]\n----n");
    char choice;
    char apply_buf[BUFSIZ];
    switch (choice)
    {
    case 'y':
        memset(apply_buf,0,BUFSIZ);
        memcpy(apply_buf,&msg,sizeof(message));
        if(send(cfd,apply_buf,BUFSIZ,0)!=BUFSIZ)
        {
            my_err("send error!",__LINE__);
        }
        printf("用户%s已经成为好友\n",msg.from);
        break;
    case 'n':
        printf("\n");
        memset(apply_buf,0,BUFSIZ);
        memcmp(apply_buf,&msg,sizeof(message));
        if(send(cfd,apply_buf,BUFSIZ,0)!=BUFSIZ)
        {
            my_err("send error!",__LINE__);
        }
        printf("您拒绝了用户%s的好友请求\n",msg.from);
        break;
    }
    for(i=n;i<10;i++)
    {
        msg_t[i]=msg_t[i+1];
    }

    
}

void Show_friend()
{

}
void Friend_menu()
{
    int choice=1;
    printf("\33[2J\n");
    printf("\33[1;1H\n");
    printf("\033[;35m\33[1m\t  ***********the list of friends************* \033[0m \n");
    while(choice)
    {
        printf("1.我的好友");
        printf("2.添加好友");
        printf("3.删除好友");
        printf("4.查看聊天记录");
        printf("0.退出\n");

        printf("请输入选择:");
        scanf("%d",&choice);
        Clear_buffer();
        switch (choice)
        {
            case 1:
                //Show_friend();
                break;
            case 2:
                Add_friend();
                break;
            case 3:
                Del_friend();
                break;
            case 4:
                Query_friend();
                break;
            case 0:
                break;
        }
    }
    return;
}


void Create_group()
{
    char name_t[30];
    char str[MAX_CHAR];
    group group;
    memset(str,0,sizeof(str));
    printf("请输入群名:");
    scanf("%s",group.name);
    group.ower=enternum;
    group.flag=17;
    memcpy(str,&group,sizeof(group));
    if(send(cfd,str,MAX,0)==-1)
    {
        my_err("注册群发生错误",__LINE__);
    }
    return;
}

void Add_group()
{
    int num;
    display("请输入要加入的群号:");
    scanf("%d",&num);
    if(Send_cmessage(18,num,"")==1)
    {
        printf("  申请加群请求发送成功");
    }
    return ;
}
void Show_group()
{

}
void Delete_group()
{
    char user;
    display("请输入要退出的群账号:");
    scanf("%s",user);

    char str[30];
    sprintf(str,"%s",user);
    if(Send_cmessage(23,user,"")==1)
    {
        printf("退出群聊请求发生成功\n");
    }
    return;
}
void Group_menu()
{
    system("clear");
    int choice=1;
    while(1)
    {
        printf("1.");
        printf("2.");
        printf("3.");
        printf("4.");
    }
}
void Add_group()
{
    
}