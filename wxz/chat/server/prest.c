int Add_syslog(syslog_t* data)
{
    assert(data!=NULL);
    FILE* fp=fopen("syslog","ab+");
    if(fp==NULL)
    {
        sys_err("打开文件错误!",__LINE__);
    }
    int ret=fwrite(data,sizeof(syslog_t),fp);
    fclose(fp);

    if(ret==0)
    {
        sys_err("文件写入错误!",__LINE__);
        return 0;
    }
    return 1;
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
}
