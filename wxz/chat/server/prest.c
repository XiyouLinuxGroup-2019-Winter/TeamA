#include "final.h"
int Read_linked_list_from_file(server_list_t list)
{
    server_user_node_t *new;
    server_user_t data;
    int cnt;
    //释放链表list中所有数据结点
    List_Free(list,server_user_node_t);

    FILE* fp=fopen("server","rb");
    if(fp==NULL)
    {
        my_err("fopen error!",__LINE__);
        return 0;
    }
    while(!feof(fp))
    {
        if(fread(&data,sizeof(server_user_t),1,fp))
        {
            new=(server_user_node_t*)malloc(sizeof(server_user_node_t));
            if(new==NULL)
            {
                sys_err("malloc error!",__LINE__);
                break;
            }
            new->data=data;
            data.online=0;
            data.connfd=-1;
            //链表尾插法，list为头指针，new为新节点
            List_AddTail(list,new);
            cnt++;
        }
    }
    fclose(fp);
    return cnt;
}
int Write_infor_to_file(server_user_t* data)
{
    assert(data!=NULL);
    FILE* fp=fopen("server","ab+");
    int ret;
    if(fp==NULL)
    {
        printf("fopen error!",__LINE__);
        return 0;
    }
    ret=fwrite(data,sizeof(server_user_t),1,fp);
    fclose(fp);
    return ret;
}
int Update_user_info(server_user_t* data)
{
    ssert(data!=NULL);
    FILE* fp=fopen("server","rb+");
    if(fp==NULL)
    {
        sys_err("fopen error!",__LINE__);
        return 0;
    }
    int flag=0;
    server_user_t tmp;
    while(!feof(fp))
    {
        if(fread(&tmp,sizeof(server_user_t),1,fp))
        {
            if(strcmp(tmp.username,data->username)==0)
            {
                printf("tmp=%s data:%s\n",tmp.username,data->username);
                fseek(fp,sizeof(server_user_t),SEEK_CUR);
                fwrite(data,sizeof(server_user_t),1,fp);
                flag=1;
                break;
            }
        }
    }
    
    fclose(fp);
    return flag;
}

//朋友
int Read_friendlinked_list_from_file(friend_list_t list,char* name)
{
    friend_node_t *new;
    FRIEND_INFO data;
    int cnt;
    List_Free(list,friend_node_t);
    
    char buf[30];
    strcpy(buf,"user:");
    strcat(buf,name);
    

    FILE* fp=fopen(buf,"rb");
    if(fp==NULL)
    {
        sys_err("fopen error!",__LINE__);
        return 0;
    }
    while(!feof(fp))
    {
        if(fread(&data,sizeof(FRIEND_INFO),1,fp))
        {
            new=(friend_node_t*)malloc(sizeof(friend_node_t));
            new->data=data;

            List_AddTail(list,new);
            cnt++;
        }
    }
    fclose(fp);
    return cnt;
}

//将朋友信息写入文件
int Write_friendinfor_to_file(FRIEND_INFO* data,char* name)
{
    assert(data!=NULL);
    char buf[30];
    strcpy(buf,"user:");
    strcat(buf,name);


    FILE* fp=fopen(buf,"ab+");
    if(fp==NULL)
    {
        sys_err("fopen error!",__LINE__);
        return 0;
    }
    int ret=fwrite(data,sizeof(FRIEND_INFO),1,fp);

    fclose(fp);
    return ret;
}

int Byname_delete_friend(char* name,char* opt)
{
    char buf[30];
    strcpy(buf,"user:");
    strcat(buf,name);     

    char temp[30];
    strcpy(temp,"user:");
    strcat(temp,name);    

       
	if(rename(buf,temp)<0)
    {
		sys_err("rename error!",__LINE__);
		return 0;
	}

	FILE *fpsrv, *fptar;
	fpsrv=fopen(temp, "rb");
	if(fpsrv==NULL)
    {
		sys_err("fopen error!",__LINE__);
		return 0;
	}
        
	fptar=fopen(buf,"wb");
	if(fptar==NULL)
    {
		sys_err("fopen error!",__LINE__);
		return 0;
	}


	FRIEND_INFO BUF;
	int flag=0;

	while(!feof(fpsrv))
    {
		if(fread(&BUF,sizeof(FRIEND_INFO),1,fpsrv))
        {
			printf("the name is %s , the bufname is %s\n",name,BUF.name);
			if(strcmp(opt,BUF.name)==0)
            {
                printf("the name is %s , the bufname is %s\n",name,BUF.name);
				flag=1;
				continue;
			}
			fwrite(&BUF,sizeof(FRIEND_INFO),1,fptar);
		}
	}

	fclose(fptar);
	fclose(fpsrv);
	remove(temp);
	return flag;
}

int Add_syslog(syslog_t* data)
{
    assert(data!=NULL);
    FILE* fp=fopen("syslog","ab+");
    if(fp==NULL)
    {
        sys_err("fopen error!",__LINE__);
        return 0;
    }
    int ret=fwrite(data,sizeof(syslog_t),fp);
    fclose(fp);

    if(ret==0)
    {
        sys_err("fwrite error!",__LINE__);
        return 0;
    }
    return ret;
}
int Make_syslog(server_user_t tmp,char* string)
{
    printf("生成日志信息\n");
    int result;
    syslog_t* syslog;
    syslog=(syslog_t*)malloc(sizeof(syslog_t));

    memset(syslog,0,sizeof(syslog_t));

    memset(syslog->name,0,sizeof(syslog->name));
    strcpy(syslog->name,tmp.username);
    syslog->name[strlen(tmp.username)+1]='\0';
    syslog->name[strlen(tmp.username)+2]=' ';
    syslog->name[strlen(tmp.username)+3]=' ';
    //strcat(syslog->name,'\0');

    time_t timep;
    time(&timep);

    memset(syslog->time,0,sizeof(syslog->time));
    strcat(syslog->time,ctime(&timep));
    //memecpy(syslog->time,ctime(&timep),sizeof(ctime(&timep)));

    strcpy(syslog->work,string);
    strcat(syslog->work,'\n');

    result=Add_syslog(syslog);
    return result;
}

int login(int connfd,server_user_t *tmp,struct sockaddr_in cli_addr,server_list_t list)
{
    char buf[BUFSIZ];

    ACCOUNT_INFO check;
    int ret;

    while(1)
    {
        int flag=1;
        if(ret=recv(connfd,buf,sizeof(buf),0)<0)
        {
            sys_err("recv error!",__LINE__);
        }
        else
        {
            break;
        }
        printf("the buf:%s\n",buf);
        memcpy(&check,buf,sizeof(check));

        if(check.statue==1)
        {
            server_list_t pos;
            for(pos=list->next;pos!=list;pos=pos->next)
            {
                printf("the name is check :%s,pos:%s\n",check.username,pos->data.username);
                if(strcmp(check.username,pos->data.username)==0)
                    return 3;
            }
        

            char temp[30];
            strcpy(temp,"user:");
            strcat(temp,check.username);
            printf("username :%s\n",temp);


            //创建一个自己的文件，以后用来存离线消息
            FILE *fp=fopen(temp,"ab");
	        if(NULL==fp) 
            {
		        sys_err("fopen error!",__LINE__);
		        return 0;
	        }
	        fclose(fp);
	        printf("the user is already submit\n");

	        strcpy(tmp->username,check.username);
            strcpy(tmp->password,check.password);
    	    tmp->useraddr=cil_addr;
    	    tmp->previe=check.previe;
            tmp->many=check.many;
            tmp->online=1;
            tmp->connfd=connfd;
            Add_new_user_to_file(tmp);
           
            return 1;
        }   
        else
        {
        
    	    strcpy(tmp->username,check.username);
            strcpy(tmp->username,check.password);
    	    tmp->useraddr=cil_addr;
    	    tmp->previe=check.previe;
    	    tmp->many=check.many;
    	    tmp->online=1;
    	    tmp->connfd=connfd;
            return 0;
        }
    }


}

int Add_new_user_to_file(server_user_t* data)
{
    int ret ;
    ret=Write_infor_to_file(data);
    if(0==ret)
    {
        sys_err("fwrite error!",__LINE__);
        return 0;
    }
    return 1;
}

int Read_linked_list_into_memory(server_list_t list)
{
    int ret;
    ret=Read_linked_list_from_file(list);
    if(0==ret)
    {
        sys_err("fread error!",__LINE__);
        return 0;
    }
    return 1;
}

int Find_server_user(server_list_t list_ser,char *username,char *password,int cfd)
{
    server_list_t pos;

    for(pos=list_ser->next;pos!=list_ser;pos=pos->next)
    {
        if((strcmp(pos->data.username,username)==0)&&(strcmp(pos->data.password,password)==0))
        {
            printf("pos:%s %s\n",pos->data.username,username);
            printf("pwd:%s %s\n",pos->data.password,password);
            
            server_user_t date;
            date=pos->data;
            date.online=1;
            date.connfd=connfd;
            //下线更改用户状态
	        Downline_change_status(&data);
            return 1;
        }
    }
    return 0;
}
int Downline_change_status(server_user_t* data)
{
    int flag;

	flag=Update_user_info(data);
    printf("flag=%d\n",flag);
    return 0;
}