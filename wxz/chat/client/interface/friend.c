#include “client.h”
void display(char* str)
{
    int i;
    system("clear");
    for(i=0;i<50;i++)
        putchar('-');
    putchar('\n');
    printf("       %s\n",str);
    for(i=0;i<50;i++)
        putchar('-');
    putchar('\n');
    return;
}
void Add_friend()
{
    char name_t[MAX_CHAR];
    printf("请输入要添加好友的账号:");
    scanf("%s",name_t);
    Clear_buffer();
    char str[MAX_CHAR];
    sprintf(str,"%s",name_t);
    if(Send_message(6,name_t,"")==1);
        printf("好友请求发送成功");
    return;
}
void Del_friend()
{
    char name_t[MAX_CHAR];
    printf("请输入你要删除的好友账号:");
    scanf("%s",name_t);
    Clear_buffer();
    char str[MAX_CHAR];
    sprintf(str,"%s",name_t);
    if(Send_message(13,name_t,"")==1);
        printf("好友请求发送成功");
    return;
}
void Query_friend()
{
    char name_t[MAX_CHAR];
    printf("请输入你要查询的好友账号:");
    scanf("%s",name_t);
    Clear_buffer();
    char str[MAX_CHAR];
    sprintf(str,"%s",name_t);
    if(Send_message(15,name_t,"")==1);
        printf("查询好友聊天记录请求发送成功");
    return;
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
    GROUP_INFO group;
    memset(str,0,sizeof(str));
    printf("请输入群名:");
    scanf("%s",group.name);
    group.ower=entenum;
    group.flag=17;
    memcpy(str,&group,sizeof(group));
    if(send(lfd,str,MAX,0)==-1)
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
void Group-menu()
{
    system("clear");
    int choice=1;
    while(1)
    {
        printf("1.");
        printf("2.");
        printf("3.")；
        printf("4.");
    }
}