#include "client.h"
int main()
{
    Init_socket();

    if()
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
int Login()
{
    do
    {
    
    PACK *send_pack;
    send_pack=(PACK*)malloc(sizeof(PACK));
    

    char name[MAX];
    char password[MAX];

    printf("请输入账号:\n");
    fgets(name,sizeof(name),stdin);
    printf("请输入密码:\n");
    fgets(password,sizeof(password),stdin);


    strcpy(send_pack->data.send_name,name);
    strcpy(send_pack->data.recv_name,password);
    send_pack->flag=LOGIN;
    send_pack->data.send_fd=cfd;
    if(send(cfd,send_pack,sizeof(PACK),0)<0)
		my_err("send error", __LINE__);
    

    PACK* recv_pack;
    recv_pack=(PACK*)malloc(sizeof(PACK));
    if(recv(cfd,recv_pack,sizeof(PACK),0)<0)
    {
        my_err("recv error",__LINE__);
    }

    //printf("wait--------\n");
    if(recv_pack->flag==LOGIN)
    {
        if(recv_pack==1)
        {
            printf("%s\n",recv_login.data.send_name);
            printf("%s\n",recv_login.data.recv_name);
            printf("%s\n",recv_login.data.message);
            puts("登录成功!\n");
            strcpy(user.username,name);
            printf("%s\n",user.username);
            printf("按任意键返回\n");
            getchar();
            return 1;
        }
        else if(login_flag==0)
        {
            printf("密码不正确!\n");
            printf("按任意键返回\n");
            getchar();
            return 0;
        }
        
        else if(login_flag==2)
        {
             printf("%s\n",recv_login.data.send_name);
            printf("%s\n",recv_login.data.recv_name);
            printf("%s\n",recv_login.data.message);
            printf("账号不存在!\n");
            return 0;
        }
        else if(login_flag==3)
        {
            printf("%s\n",recv_login.data.send_name);
            printf("%s\n",recv_login.data.recv_name);
            printf("%s\n",recv_login.data.message);
            puts("账号已经登录!\n");
            return 0;
        }
    }
    }while(1);
    //free(recv_login);
}
int Login_menu()
{
    int choice;
    do
    {
        system("clear");
        printf("\t\t\033[44;34m\033[44;37m**************************\033[0m\n");
        printf("\t\t\033[1;34m*        1.注册          \033[1;34m*\033[0m \n");
        printf("\t\t\033[1;34m*        2.登录          \033[1;34m*\033[0m \n");
        printf("\t\t\033[1;34m*        0.退出          \033[1;34m*\033[0m \n");
        printf("\t\t\033[44;34m\033[44;37m**************************\033[0m\n");
        printf("\t\tchoice：");
        scanf("%d",&choice);
        getchar();
    
        switch(choice)
        {
            case 1:
                puts("注册");
                Register();
                break;
            case 2:
                puts("登录");
                if(Login())
                    return 1;
                break;
            /*case 3:
                puts("找回密码");
                Modify_password();
                break;*/
            case 0:
                exit(0);
                break;
        }
    
    }while(1);
    return 0;
}
void my_err(const char* err_string,int line)
{
    fprintf(stderr,"line:%d",line);
    perror(err_string);
    exit(1);
}