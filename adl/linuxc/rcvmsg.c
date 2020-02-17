#include<stdio.h>
#include<stdlib.h>
#include<sys/ipc.h>
#include<sys/msg.h>
#include<string.h>
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
    key_t msgkey;
    if((msgkey=ftok(PATH_NAME,PROJ_ID))==-1)
    {
        perror("ftok error");
        exit(1);
    }
    if((qid=msgget(msgkey,IPC_CREAT|0660))==-1)
    {
        perror("msgget error !\n");
        exit(1);
    }
    msglen=sizeof(struct mymsgbuf)-4;
    if(msgrcv(qid,&msgbuffer,msglen,3,0)==-1)
    {
        perror("msgrcv error\n");
        exit(1);
    }
    printf("Get message %s\n",msgbuffer.ctrlstring);
    exit(0);
    
}