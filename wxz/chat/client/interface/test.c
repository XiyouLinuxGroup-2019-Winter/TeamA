#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "client.h"
#define MAX_CHAR 300
int main()
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