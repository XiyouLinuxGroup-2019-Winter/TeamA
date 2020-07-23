#include "client.h"
#include "tools.c"
void Add_friend()
{
    int flag=ADD_FRIEND;
    char name_buf[MAX];

    display("请输入要添加的好友账号:");
    Get_string(name_buf,MAX);



    Send_pack_message(flag,username,name_buf,"");

    return;
}
void Del_friend()
{
    int flag=DEL_FRIEND;
    char name_buf[MAX];

    display("请输入要删除的好友账号:");
    Get_string(name_buf,MAX);

    Send_pack_message(flag,username,"server",name_buf);


    return;
}
void Query_friend()
{
    int flag=QUERY_FRIEND;
    char name_buf[MAX];

    display("请输入要的好友账号:");
    Get_string(name_buf,MAX);

    Send_pack_message(flag,username,name_buf,"");


    return;
}
void Shield_friend()
{
    int flag=SHIELD;
    char name_buf[MAX];
    printf("请输入要屏蔽的好友名称:");
    Get_string(name_buf,MAX);

    Send_pack_message(flag,username,"server",name_buf);

}
void Unshield_friend()
{
    int flag=UNSHIELD;
    char name_buf[MAX];
    printf("请输入要解除屏蔽的好友名称:");
    Get_string(name_buf,MAX);

    Send_pack_message(flag,username,"server",name_buf);
}
void View_friend_list()
{
    char name_buf[MAX];
    int flag=QUERY_FRIEND;

    memset(name_buf,0,MAX);
    
    FRIEND_INFO friend_info;
    memset(&friend_info,0,sizeof(FRIEND_INFO));


    

    Send_pack_message(flag,username,"server","1");


    printf("\n\t\t\033[0;34m**********friends*********\033[0m\n");
    if(friend_info.num==0)
        printf("\t\t");
    else
    {
        for(int i=0;i<friend_info.num;i++)
        {
            if(friend_info.status[i]==1)
            {
                flag=GET_FRIEND_STATUS;
                Send_pack_message(flag,friend_info.name[i],"server","");
            }
            else if(friend_info.status[i]==2)
            {
                printf("\n\t\t\033[0;34m**********%s*********\033[0m\n",friend_info.name[i]);
            }
            
        }
    }
    
    
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


void Show_friend()
{

}
void Friend_menu()
{
    int choice=1;
    system("clear");
    
    while(choice)
    {
        printf("\t\t\033[44;34m\033[44;37m**************************\033[0m\n");
        printf("\t\t\033[;36m\033[1m*********朋友管理*********\033[0m\n");
        printf("\t\t\033[1;36m|\033[0m--------1.添加好友-------\033[1;36m|\033[0m\n");
        printf("\t\t\033[1;36m|\033[0m--------2.删除好友-------\033[1;36m|\033[0m\n");
        printf("\t\t\033[1;36m|\033[0m--------3.查询好友-------\033[1;36m|\033[0m\n");
        printf("\t\t\033[1;36m|\033[0m--------4.私聊好友-------\033[1;36m|\033[0m\n");
        printf("\t\t\033[1;36m|\033[0m--------5.屏蔽好友-------\033[1;36m|\033[0m\n");
        printf("\t\t\033[1;36m|\033[0m------6.解除屏蔽好友-----\033[1;36m|\033[0m\n");
        printf("\t\t\033[1;36m|\033[0m------7.查看好友列表-----\033[1;36m|\033[0m\n");
        printf("\t\t\033[1;36m|\033[0m------8.显示好友状态-----\033[1;36m|\033[0m\n");
        printf("\t\t\033[1;36m|\033[0m------9.查看聊天记录-----\033[1;36m|\033[0m\n");
        printf("\t\t\033[1;36m|\033[0m-------- 0.退出 ---------\033[1;36m|\033[0m\n");
  
        printf("请输入选择:");
        scanf("%d",&choice);
        Clear_buffer();
        switch (choice)
        {
            case 1:
                Add_friend();
                break;
            case 2:
                Del_friend();
                break;
            case 3:
                Query_friend();
                break;
            case 4:
                Private_chat();
                break;
            case 5:
                Shield_friend();
                break;
            case 6:
                Unshield_friend();
                break;
            case 7:
                View_friend_list();
                break;
            case 8:
                Show_friend_status();
                break;
            case 9:
                View_chat_history();
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
    int flag=ADD_GROUP;
    char name_buf[MAX];

    printf("请输入想要加入的群名称:");
    Get_string(name_buf,MAX);

    Send_pack_message(flag,username,"server",name_buf);


}

void Withdraw_group()
{
    int flag=WITHDRAW_GROUP;
    char name_buf[MAX];
    printf("请输入想要退出的群名称:");
    Get_string(name_buf,MAX);

    Send_pack_message(flag,username,"server",name_buf);
}

void Del_group()
{
    int flag=DEL_GROUP;
    char name_buf[MAX];
    printf("请输入想要解散的群名称:");
    Get_string(name_buf,MAX);

    Send_pack_message(flag,username,"server",name_buf);
}
void Set_group_admin()
{
    
}
void Group_leader_menu()
{

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
