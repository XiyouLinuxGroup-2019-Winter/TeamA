#include <stdio.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <stdlib.h>
#include <string.h>
#include <sys/msg.h>
#define BUF_SIZE 256
#define PROJ_ID 32
#define PATH_NAME "."
int main()
{
    struct mymsgbuf{
        long msgtype;
        char ctrlstring[BUF_SIZE];
    }msgbuffer;

    int qid;
    int msglen;
    key_t msgkey;

    msgkey=ftok(PATH_NAME,PROJ_ID);

    qid=msgget(msgkey,IPC_CREAT|0660);


    msgbuffer.msgtype=3;
    strcpy(msgbuffer.ctrlstring,"hello,message queue");
    msglen=sizeof(struct mymsgbuf)-4;
    msgsnd(qid,&msgbuffer,msglen,0);
    exit(0);

}