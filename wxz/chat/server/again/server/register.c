void Register(PACK* pack_t)
{
    char register_flag[10];
    int flag=REGISTER;
    char buf[BUFSIZ];

    server_list_t pos;
    for(pos=list_ser->next;pos!=list_ser;pos=pos->next)
    {
        if(strcmp(pos->data.username,pack_t->data.send_name)==0)
        {
            printf("pos:%s\n%s\n",pos->data.username,pos->data.password);
            flag=1;
            break;
        }
    }


    server_user_node_t *new;
    new=(server_user_node_t*)malloc(sizeof(server_user_node_t));



    PACK *send_pack=NULL;
    send_pack=(PACK *)malloc(sizeof(PACK));
    if(flag==0)
    {
        strcpy(new->data.username,pack_t->data.send_name);
        strcpy(new->data.password,pack_t->data.message);
        new->data.online=DOWNLINE;
        new->data.friend_num=0;
        new->data.group_num=0;
        
        //链表尾插法，list为头指针，new为新节点
        List_AddTail(list_ser,new);
        user_num++;


        memset(buf,0,sizeof(buf));
        sprintf(buf,"insert into account values('%s','%s','%d')",pack_t->data.send_name,pack_t->data.message,pos->data.online);
        mysql_real_query(&mysql,buf,strlen(buf));
        //register_flag[0]='1';

       send_pack->flag=REGISTER;
       send_pack->data.recv_fd=pack_t->data.send_fd;
       send_pack->data.message[0]='1';
    }
    else
    {
        register_flag[0]='0';
    }
    register_flag[1]='\0';

    Send_pack_type(pack_t->data.send_fd,flag,pack_t,register_flag);
    free(pack_t);
}