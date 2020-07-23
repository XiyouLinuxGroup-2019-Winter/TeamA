#include "client.h"
int main()
{
    Login_menu();
}
void Clear_buffer()
{
    char ch;
    while(getchar()!='\n')
		continue;
    /*while((ch=getchar())!='\n' && ch!=EOF)
            continue;*/
}

/*void Register()
{
    int flag=0;
    char name_t[MAX];
    char password_t[MAX];

    printf("账号:");
    scanf("%s",name_t);
    printf("密码:");
    scanf("%s",password_t);
    if(Send_register(name_t,password_t))
        printf("登录成功!\n");
    else
        printf("该账号已存在，请重新输入\n");
    
}*/
/*int Send_register(char name_t[],char password_t[])
{

}*/
void Register()
{
    char password[30];
    char name[MAX];
    account per;
    printf("账号:");
    scanf("%s",per.name);
    int flag=0;
    do
    {
        if(flag)
            puts("两次输入的密码不一致，请重新输入:");
        printf("密码:");
        scanf("%s",per.password);
        printf("请再次输入密码:");
        scanf("%s",password);
        flag=1;
    } while (strcmp(password,per.password));

    per.flag=1;
    printf("请输入手机号:");
    scanf("%s",per.phone);
    printf("请输入要绑定的邮箱:");
    scanf("%s",per.e_mail); 

    memcpy(name,&per,sizeof(account));

    /*if(send(lfd,name,MAX,0)==-1)
    {
        my_err("注册错误",__LINE__);
    } */  
    return;
}
void Login()
{
    account per;
    char name_t[MAX];
    per.flag=2;
    printf("账号:");
    scanf("%s",per.name);
    printf("密码:");
    scanf("%s",per.password);
    
    memcpy(name_t,&per,sizeof(account));
    /*if(send(lfd,name_t,MAX,0)==-1)
    {
        my_err("登录错误",__LINE__);
    }*/
    return;
}
void Modify_password()
{
    account_find per;
    printf("账号:");
    scanf("%s",per.name);
    printf("手机号:");
    scanf("%s",per.phone);
    printf("电子邮箱:");
    scanf("%s",per.e_mail);
    printf("新密码:");
    scanf("%s",per.password);

    char name_t[MAX];
    per.flag=3;

    memcpy(name_t,&per,sizeof(account_find));
    /*if(send(lfd,name_t,MAX,0)==-1)
    {
        my_err("修改密码错误",__LINE__);
    }*/
    //else
    {
        printf("        修改成功!");
    }

    
}
void Login_menu()
{
    int choice=1;
    while(choice)
    {
        printf("\t\t\033[44;34m\033[44;37m**************************\033[0m\n");
        printf("\t\t\033[44;34m\033[44;37m*\033[37m        1.注册          \033[44;37m\33[1m*\033[0m \n");
        printf("\t\t\033[44;34m\033[44;37m*\033[37m        2.登录          \033[44;37m\33[1m*\033[0m \n");
        printf("\t\t\033[44;34m\033[44;37m*\033[37m        3.修改密码      \033[44;37m\33[1m*\033[0m \n");
        printf("\t\t\033[44;34m\033[44;37m*\033[37m        0.退出          \033[44;37m\33[1m*\033[0m \n");
        printf("\t\t\033[44;34m\033[44;37m**************************\033[0m\n");
        printf("\t\tchoice：");
        scanf("%d",&choice);
        Clear_buffer();
        switch(choice)
        {
            case 1:
                puts("注册");
                Register();
                break;
            case 2:
                puts("登录");
                Login();
                break;
            case 3:
                puts("找回密码");
                Modify_password();
                break;
            case 0:
                break;
        }
    }
    return ;
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
