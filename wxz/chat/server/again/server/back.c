void Register(PACK* pack_t)
{
    MYSQL_RES *result;
    MYSQL_ROW row;
    MYSQL_FIELD *field;
    int ret, i, j;
    char flag_register[10];

    server_user_t *new;
    new=(server_user_t *)malloc(sizeof(server_user_t));
    strcpy(new->username,pack_t->data.send_name);
    strcpy(new->password,pack_t->data.message);
    new->online=DOWNLINE;

    

    char buf[BUFSIZ];
    memset(buf, 0,sizeof(buf));
    sprintf(buf,"select username from account where username='%s'",new->username);
    ret=mysql_real_query(&mysql, buf,strlen(buf)); //查询语句
    if(ret)
    {
        printf("select error:%s\n",mysql_error(&mysql));
    }
    else
    {
        result=mysql_store_result(&mysql); 

        //检索所有的行，
        if(mysql_num_rows(result)==0)
        {
            memset(buf, 0, sizeof(buf));
            printf("没有此人可以注册此账户\n");
            sprintf(buf, "insert into account values('%s','%s','%d')", new->username, new->password,new->online);
            printf("%s\n", buf);

            ret=mysql_real_query(&mysql, buf,strlen(buf)); //查询语句

            if(ret)
            {
                printf("select error:%s\n",mysql_error(&mysql));
                flag_register[0]='0';
                Send_pack_type(pack_t->data.send_fd,REGISTER,pack_t,flag_register);
                return ;
            }
            flag_register[0]='1';
            Send_pack_type(pack_t->data.send_fd,REGISTER,pack_t,flag_register);
        }
        else if(mysql_num_rows(result)>0)
        {
            printf("该账户已存在，请提示重新输入\n");
            flag_register[0]='0';
            Send_pack_type(pack_t->data.send_fd,REGISTER,pack_t,flag_register);
        }
        mysql_free_result(result);
    }

}               
void Login(PACK* pack_t)
{
    MYSQL_RES *result;
    MYSQL_ROW row;
    MYSQL_FIELD *field;
    int ret, i, j;
    char flag_login[10];
    

    char buf[BUFSIZ];
    memset(buf, 0,sizeof(buf));
    sprintf(buf,"select username from account where username='%s' and password='%s'",pack_t->data.send_name,pack_t->data.recv_name);
    ret=mysql_real_query(&mysql, buf,strlen(buf)); //查询语句
    if(ret)
    {
        printf("select error:%s\n",mysql_error(&mysql));
    }
    
    result=mysql_store_result(&mysql); 
    int rows=mysql_num_row(result);
    //行
    PACK* send_pack;
    send_pack=(PACK*)malloc(sizeof(PACK));
    if(rows==0)
    {
        printf("没有找到要登录的账号\n");
        send_pack->flag=LOGIN;
        send_pack->data.recv_fd=pack_t->data.send_fd;
        send_pack->data.massge[0]='0';

        if(send(pack_t->data.recv_fd,send_pack,sizeof(PACK),0)<0)
            my_err("send error", __LINE__);
    }
    else if(rows>0)
    {
        printf("登录成功\n");
            
        account_node_t* new;
        new=(account_node_t*)malloc(sizeof(account_node_t));
        new->data.connfd=pack_t->data.recv_fd;
           

        int rows=mysql_num_rows(result));
        printf("%d\n",rows);
        j=mysql_num_fields(result);                                //获取 列数
        while((row=mysql_fetch_row(result)))
        { 

            strcpy(new->data.username,pack_t->data.send_name);

            for(i=0;i<j;i++)
            {
                printf("socket_id:%s\n",row[i]);
                new->data.socket_id= atoi(row[i]);
            }
            List_AddHead(list_ser,new);
            printf("\n");
        }
        if(mysql_errno(&mysql))
        {
            fprintf(stderr, "Retrive error:%s\n", mysql_error(&mysql));
        }


    
           

           
        }
        mysql_free_result(result);
    }
}