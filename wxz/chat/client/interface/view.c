#include <stdio.h>
void Login_menu();
void Clear_buffer()
{
    char ch;
    while(getchar()!='\n')
		continue;
    /*while((ch=getchar())!='\n' && ch!=EOF)
            continue;*/
}
int main()
{
    Login_menu();
}
void Login_menu()
{
    int choice=1;
    while(choice)
    {
        //printf("\033[1m\033[44;37m  [1]注册   [2]登录   [0]退出   [4]找回密码  \033[0m\n");
        printf("\t\t\033[44;34m\033[44;37m**************************\033[0m\n");
        printf("\t\t\033[44;34m\033[44;37m*\033[37m        1.注册          \033[44;37m\33[1m*\033[0m \n");
        printf("\t\t\033[44;34m\033[44;37m*\033[37m        2.登录          \033[44;37m\33[1m*\033[0m \n");
        printf("\t\t\033[44;34m\033[44;37m*\033[37m        3.找回密码      \033[44;37m\33[1m*\033[0m \n");
        printf("\t\t\033[44;34m\033[44;37m*\033[37m        0.退出          \033[44;37m\33[1m*\033[0m \n");
        printf("\t\t\033[44;34m\033[44;37m**************************\033[0m\n");
        scanf("%d",&choice);
        Clear_buffer();
        switch(choice)
        {
            case 1:
                puts("注册");
                //Register();
                break;
            case 2:
                puts("登录");
                //Login();
                break;
            case 3:
                puts("找回密码");
                //Find_passwd();
                break;
            case 0:
                break;
        }
    }
    return ;
}