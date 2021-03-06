#include "client.h"
#include "tools.h"
#include "wrang.h"
int main()
{
    Init_socket();

    Turn_worke_thread();

}
void Init_socket()
{
    printf("客户端启动\n");
    struct sockaddr_in serv_addr;


    cfd=Socket(AF_INET,SOCK_STREAM,0);

    bzero(&serv_addr,sizeof(serv_addr));
    serv_addr.sin_family=AF_INET;
    serv_addr.sin_port=htons(SERV_PORT);
    inet_pton(AF_INET,SERV_ADDRESS,&serv_addr.sin_addr.s_addr);

    Connect(cfd,(struct sockaddr*)&serv_addr,sizeof(serv_addr));

    printf("客户端启动成功!\n");

}
void *Recv_pack()
{
    PACK pack_t;
    pthread_t pid;
    while(1)
    {
        if(recv(cfd,&pack_t,sizeof(PACK),0)<0)
        {
            my_err("recv error",__LINE__);
        }



        pthread_mutex_lock(&mutex);

        

        switch (pack_t.flag)
        {
            case ADD_FRIEND:
                flag=pack_t.data.message[0];
                if(flag==0)
                {

                }
                break;
            case DEL_FRIEND:
                flag=pack_t.data.message[0];
                break;
            case QUERY_FRIEND:
                flag=pack_t.data.message[0];
                break;
            case VIEW_FRIEND_LIST:
                flag=pack_t.data.message[0];
                break;
            case SHOW_FRIEND_STATUS:
                flag=pack_t.data.message[0];
                break;
            case VIEW_CHAT_HISTORY:
                flag[++]=pack_t;
                break;
            case SHIELD:
                flag=pack_t.data.message[0];
                break;
            case UNSHIELD:
                flag=pack_t.data.message[0];
            
        }
        pthread_mutex_unlock(&mutex);
    }
}
void Turn_worke_thread()
{
    pthread_t pid_recv;
    pthread_create(&pid_recv,NULL,Recv_pack,NULL);
}
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
    pthread_mutex_lock(&mutex);

    printf("\n\t\t\033[0;34m**********好友列表*********\033[0m\n");
    if(user.friend_num==0)
        printf("\t\t暂无好友!,请先添加\n");
    else
    {
        for(int i=1;i<=user.friend_num;i++)
        {
            if(user.friend[i].statue==1)
            {
               printf("\t\t\033[1;32m联系人:%s  (在线)\033[0m\n",user.friend[i].name);
               if(user.friend[i].message_num)
                    printf("\t\t\033[1;32m未回复的消息数:%d  \033[0m\n",user.friend[i].message_num)；
                else
                {
                    printf("\t\t\033[1;32m暂未消息  \033[0m\n");
                }
            }
            else if(user.friend[i].statue==2)
            {
                printf("\t\t\033[1;32m联系人:%s  (已下线)\033[0m\n",user.friend[i].name);
                if(user.friend[i].message_num)
                    printf("\t\t\033[1;32m未回复的消息数:%d  \033[0m\n",user.friend[i].message_num)；
                else
                {
                    printf("\t\t\033[1;32m暂未消息  \033[0m\n");
                }
            }
            
        }
    }
    pthread_mutex_unlock(&mutex);
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
    printf("[---------------]正在加载");
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
        return ;
    }
}


/*void Show_friend()
{
    
}*/
void Friend_menu()
{
    int choice=1;
    system("clear");
    
    while(choice)
    {
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
    int flag=CREAT_GROUP;
    char name_buf[MAX];
    printf("请输入要创建的群名称:");
    Get_string(name_buf,MAX);

    Send_pack_message(flag,username,"server",name_buf);
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

void View_add_group()
{
   pthread_mutex_lock(&mutex);

    printf("\n\t\t\033[0;34m**********群组列表*********\033[0m\n");
    if(user.group_num==0)
        printf("\t\t暂无群组!,请先添加\n");
    else
    {
        for(int i=1;i<=user.group_num;i++)
        {       
            printf("\t\t\033[1;32m群组名称:%s  \033[0m\n",user.group[i].name);
        }
    }
}
void View_group_member()
{
    
}
void View_group_record()
{

}
void Group_menu()
{
    int choice=1;
    while(choice)
    {
        printf("\t\t\033[;34m\033[1m*********群管理*********\033[0m\n");
        printf("\t\t\033[1;34m|\033[0m--------1.创建群-------\033[1;34m|\033[0m\n");
        printf("\t\t\033[1;34m|\033[0m--------2.添加群-------\033[1;34m|\033[0m\n");
        printf("\t\t\033[1;34m|\033[0m--------3.退群---------\033[1;34m|\033[0m\n");
        printf("\t\t\033[1;34m|\033[0m--------4.已加群-------\033[1;34m|\033[0m\n");
        printf("\t\t\033[1;34m|\033[0m--------5.群成员-------\033[1;34m|\033[0m\n");
        printf("\t\t\033[1;34m|\033[0m-----6.查看聊天记录----\033[1;34m|\033[0m\n");
        printf("\t\t\033[1;34m|\033[0m------7.群管理权限-----\033[1;34m|\033[0m\n");
        printf("\t\t\033[1;34m|\033[0m-------- 0.退出--------\033[1;34m|\033[0m\n");
        printf("请输入选择:");
        scanf("%d",&choice);
        Clear_buffer();
        switch (choice)
        {
            case 1:
                Create_group();
                break;
            case 2:
                Add_group();
                break;
            case 3:
                Withdraw_group();
                break;
            case 4:
                View_add_group();
                break;
            case 5:
                View_group_member();
                break;
            case 6:
                View_group_record();
                break;
            case 7:
                Group_leader_menu();
                break;
            case 0:
                break;
        }
    }
    return;
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
    int flag=SET_GROUP_ADMIN;
    char leader_buf[MAX];
    char admin_buf[MAX];

    printf("请输入设置某个群里的管理员:");
    Get_string(leader_buf,MAX);

    Get_string(admin_buf,MAX);
   

    Send_pack_message(flag,username,leader_buf,admin_buf);
}
void Kick()
{
    int flag=KICK;
    char admin_buf[MAX];
    char staff_buf[MAX];

    printf("请输入踢出某个群里的人员:");
    Get_string(admin_buf,MAX);

    Get_string(staff_buf,MAX);
   

    Send_pack_message(flag,username,admin_buf,staff_buf);

}
void Group_leader_menu()
{
    int choice=1;
    system("clear");
    while(choice)
    {
        printf("\t\t\033[;33m\033[1;37m**************************\033[0m\n");
        printf("\n\t\t\033[1;31m    群主--1,2,3/管理员--3权限     \033[0m\n");
        printf("\t\t\033[1;31m         1.解散群  \033[0m\n");
        printf("\t\t\033[1;31m         2.设置管理员\033[0m\n");
        printf("\t\t\033[1;31m         3.踢人  \033[0m\n");
        printf("\t\t\033[1;31m         0.返回  \033[0m\n");
        printf("请输入选择:");
        scanf("%s",&choice);
        Clear_buffer();
        switch (choice)
        {
            case 1:
                Del_group();
                break;
            case 2:
                Set_group_admin();
                break;
            case 3:
                Kick();
                break;
            case 0:
                break;
        }
    }
}
