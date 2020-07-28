#include "server.h"
int main()
{

}
void Init_socket()
{

    PACK recv_t;
    PACK *recv_pack;
    printf("服务端启动\n");
    struct sockaddr_in serv_addr;
    struct sockaddr_in cli_addr;

    socklen_t cli_addr_len;

    lfd=Socket(AF_INET,SOCK_STREAM,0);

    //端口复用
    int opt=1;
    setsockopt(lfd,SOL_SOCKET,SO_REUSEADDR,(void*)&opt,sizeof(opt));

    bzero(&serv_addr,sizeof(serv_addr));

    serv_addr.sin_family=AF_INET;
    serv_addr.sin_port=htons(SERV_PORT);
    serv_addr.sin_addr.s_addr=htonl(INADDR_ANY);

    Bind(lfd,(struct sockaddr*)&serv_addr,sizeof(serv_addr));
    Listen(lfd,128);

    printf("服务器启动成功!\n");

    epfd=epoll_create(1024);
    struct epoll_event tep,ep[1024];
    tep.events=EPOLLIN;
    tep.data.fd=lfd;
    epoll_ctl(epfd,EPOLL_CTL_ADD,lfd,&tep);

    while(1)
    {
        ret=epoll_wait(epfd,ep,1024,-1);
        for(i=0;i<ret;i++)
        {
            if (!(ep[i].events & EPOLLIN))      //如果不是"读"事件, 继续循环
                continue;

            if(ep[i].data.fd==lfd)
            {
                cli_addr_len=sizeof(cli_addr);
                cfd=Accept(lfd,(struct sockaddr*)&cli_addr,&cli_addr_len);
                printf("连接到新的客户端ip:%s\n端口号:%d\n",inet_ntoa(cli_addr.sin_addr),cli_addr.sin_port);
                tep.events=EPOLLIN;
                tep.data.fd=cfd;
                epoll_ctl(epfd,EPOLL_CTL_ADD,cfd,&tep);
            }
            else if(ep[i].events & EPOLLIN)
            {
                int n=recv(ep[i].data.fd,&recv_t,sizeof(PACK),0);
                recv_t.data.send_fd=events[i].data.fd;

                Recv_pack_message(recv_t);

                if(n<0)
                {
                    close(ep[i].data.fd);
                    sys_err("接收错误!",__LINE__);
                    continue;
                }
                else if(n==0)
                {
                    for(int i=0;i<=user_num;i++)
                    {
                        if(ep[i].data.fd==user[i].sid)
                        {
                            printf("%s已下线\n",user[i].username);
                            user[i].statue=DOWNLINE;
                            break;
                        }
                    }
                    tep.data.fd=ep[i].data.fd;
                    epoll_ctl(epfd,EPOLL_CTL_DEL,ep[i].data.fd,&tep);
                    close(ep[i].data.fd);
                    continue;
                }
                recv_pack=(PACK*)malloc(sizeof(PACK));
                memcpy(recv_pack,&recv_t,sizeof(PACK));


                pthread_create(&pid,NULL,Deal,(void*)recv_pack)
            }
            
        }
    }
}
void *Deal(void* arg)
{
    PACK* recv_pack_t;
    recv_pack_t=(PACK*)arg;
    switch (recv_pack_t.flag)
    {
        case LOGIN:
            Login(recv_pack_t);
            break;
        case REGISTER:
            register(recv_pack_t);
            break;
        case ADD_FRIEND:
            Add_friend(recv_pack_t);
            break;
        case DEL_FRIEND:
            Del_friend(recv_pack_t);
            break;
        case QUERY_FRIEND:
            Query_friend(recv_pack_t);
            break;
        case VIEW_FRIEND_LIST:
            View_friend_list(recv_pack_t);
            break;
        case SHOW_FRIEND_STATUS:
            Show_friend_status(recv_pack_t);
            break;
        case VIEW_CHAT_HISTORY:
            View_chat_history(recv_pack_t);
            break;
        case SHIELD:
            Shield_friend(recv_pack_t);
            break;
        case UNSHIELD:
            Unshield_friend(recv_pack_t);
            break;
        case CREAT_GROUP:
            Create_group();
            break;
        case ADD_GROUP:
            Add_group();
            break;
        case WITHDRAW_GROUP:
            Withdraw_group();
            break;
        case VIEW_ADD_GROUP():
            View_add_group();
            break;
        case VIEW_GROUP_MEMBER:
            View_group_member();
            break;        
        case VIEW_GROUP_RECORD:
            View_group_record();
            break;
        case DEL_GROUP():
            Del_group();
            break;
        case SET_GROUP_ADMIN:
            Set_group_admin();
            break;
        case KICK:
            Kick();
            break;
        case SEND_FILE:
            Send_file();
            break;
        case 0:
            break;
    }

}
