char buf[BUFSIZ];

    int flag;
    Account_t* pos=head;
    while(pos)
    {
        if(strcmp(pos->username,pack_t->data.send_name)==0)
        {
            printf("333333333333\n");
            flag=1;
            break;
        }
        pos=pos->next;
    }
    printf("1111111111\n");
    if(flag==0)
    {
        pack_t->data.other_message[0]='1';
        //添加用户
        Account_t *new;
        new=(Account_t*)malloc(sizeof(Account_t));
        strcpy(new->username,pack_t->data.send_name);
        strcpy(new->password,pack_t->data.message);
        new->online=DOWNLINE;
        
        Add_account(new);
        user_num++;

        
        printf("regist success!\n");
        printf("username:%s\n",new->username);
        printf("passward:%s\n",new->password);
        printf("user_num:%d\n\n",user_num);
        printf("online:%d\n",new->online);

        memset(buf,0,sizeof(buf));
        sprintf(buf,"insert into account values(NULL,'%s','%s','%d')",pack_t->data.send_name,pack_t->data.message,new->online);
        printf("buf:%s\n",buf);
        int ret=mysql_real_query(&mysql,buf,strlen(buf));
        if(ret)
        {
            printf("insert error:%s\n",mysql_error(&mysql));
        }
        printf("222222222222\n");
        //注册成功
        pack_t->data.other_message[0]='1';
    }
    else
    {
        printf("55555555555\n");
        //该用户已存在
        pack_t->data.other_message[0]='0';
    }
    
    //包信息赋值
    strcpy(pack_t->data.recv_name,pack_t->data.send_name);
    strcpy(pack_t->data.send_name,"server");
    pack_t->data.recv_fd=pack_t->data.send_fd;
    pack_t->data.send_fd=lfd;
    
    //发送包
    if(send(pack_t->data.recv_fd,pack_t,sizeof(PACK),0)<0)
    {
        my_err("send error",__LINE__);
    }
    printf("666666666\n");
    free(pack_t);
   
}               
void Login(PACK* pack_t)
{

    printf("server message%s\n",pack_t->data.message);
    printf("server recv:%s\n",pack_t->data.recv_name);
    int id=0;
    int flag;
    
    Account_t* pos=head;
    while(pos)
    {
        if(strcmp(pos->username,pack_t->data.send_name)==0 && strcmp(pos->password,pack_t->data.message)==0)
        {
            flag=1;
            break;
        }
        pos=pos->next;
    }
    printf("111111111\n");
    if(flag==0)
    {
        printf("222222222");
        //没有注册
        pack_t->data.other_message[0]='0';
        printf("========\n");
    }
    else if(flag==1)
    {
        if(pos->online==ONLINE)
        {
            printf("why>>\n");
            //已登录
            printf("已经登陆\n");
            //发送信息
            strcpy(pack_t->data.send_name,"server");
            pack_t->data.other_message[0]='2';
            pack_t->data.recv_fd=pack_t->data.send_fd;
            pack_t->data.send_fd=lfd;
            //pack_t->data.other_message[1]='0';
            
             if(send(pack_t->data.recv_fd,pack_t,sizeof(PACK),0)<0)
            {
                my_err("send error",__LINE__);
            }
            return ;
        }
        else if(pos->online==DOWNLINE)
        {
            //登录成功
            //pack_t->data.other_message[0]='1';

            pos->connfd=pack_t->data.send_fd;
            printf("statu:    %d\n",pos->online); 
            pos->online=ONLINE;
            printf("\n********登录**********\n");
            printf("%s 登陆成功\n", pack_t->data.send_name);
            printf("statu:    %d\n",pos->online); 
            printf("connfd:%d\n\n",pos->connfd);
            pack_t->data.other_message[0]='1';
            //修改状态
            usleep(10000);
        }
    }
    
    
    strcpy(pack_t->data.recv_name,pack_t->data.send_name);
    strcpy(pack_t->data.send_name,"server");
    pack_t->data.recv_fd=pack_t->data.send_fd;
    pack_t->data.send_fd=lfd;
    
    if(send(pack_t->data.recv_fd,pack_t,sizeof(PACK),0)<0)
    {
        my_err("send error",__LINE__);
    }
    
    sleep(1);
    
    free(pack_t);
}

void Add_account(Account_t *new);
void Add_relation(Relation_t* new);
void Add_record(Record_t* new);
void Delete_account();
void Delete_relation();
void Delete_record();

Account_t* Server_user();
Relation_t* Server_friend();

void Add_account(Account_t *new)//用户信息链表 
{
    Account_t *pos=head;
    while(pos && pos->next!=NULL)
        pos=pos->next;
    pos->next = new;
    new->next = NULL;
}

void Add_relation(Relation_t* new)//好友信息链表 
{
    Relation_t *pos=pRelat;
    while(pos && pos->next!= NULL)
        pos=pos->next;
    pos->next =new;
    new->next = NULL;
}

void Add_record(Record_t* new)//聊天信息链表 
{
    Record_t *pos=pRead;
    while(pos && pos->next != NULL)
        pos = pos->next;
    pos->next = new;
    new->next = NULL;
}
void Delete_account()//回收用户信息链表 
{
    Account_t *pos=head;
    if(head==NULL)
        return;
    while(head)
    {
        pos=head->next;
        free(head);
        head=pos;
    }
	head=NULL;
}

void Delete_relation()//回收关系链表 
{
    Relation_t *pos=pRelat;
    if(pRelat==NULL)
        return;
    while(pRelat)
    {
        pos=pRelat->next;
        free(pRelat);
        pRelat=pos;
    }
	pRelat=NULL;
}

void Delete_record()// 回收消息链表 
{
    Record_t *pos=pRead;
    if(pRead==NULL)
        return;
    while(pRead)
    {
        pos=pRead->next;
        free(pRead);
        pRead=pos;
    }
	pRead=NULL;
}
