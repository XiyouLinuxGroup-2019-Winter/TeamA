#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<sys/ipc.h>
#include<sys/msg.h>
#define BUF_SIZE 256
#define PROJ_ID 32
#define PATH_NAME "."
int main()
{
    struct mymsgbuf
    {
        long msgtype;
        char ctrlstring[BUF_SIZE];
    }msgbuffer;
    int qid;
    int msglen;
    int msgkey;
    if((msgkey=ftok(PATH_NAME,PROJ_ID))==-1)
    {
        perror("ftok error!\n");
        exit(1);
    }
    if((qid=msgget(msgkey,IPC_CREAT|0660))==-1)
    {
        perror("msgget error!\n");
        exit(1);
    }
    msgbuffer.msgtype=3;
    strcpy(msgbuffer.ctrlstring,"hello message queue");
    msglen=sizeof(struct mymsgbuf)-4;
    if(msgsnd(qid,&msgbuffer,msglen,0)==-1)
    {
        perror("msgget error!\n");
        exit(1);
    }
    exit(0);

    
}