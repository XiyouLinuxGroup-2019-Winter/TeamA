#include "server.h"
#include "prest.h"
#include "common.h"
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
