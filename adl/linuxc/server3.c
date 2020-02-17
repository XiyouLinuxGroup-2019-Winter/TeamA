#include<sys/types.h>
#include<linux/sem.h>
#include<stdio.h>
#include<fcntl.h>
#include<stdlib.h>
#include<unistd.h>
#include<string.h>
#include<sys/types.h>
#include<sys/stat.h>

#define MAX_RESOURCE 5
int main()
{
    key_t key;
    int semid;
    struct sembuf sbuf={0,-1,IPC_NOWAIT};
    union semun semopts;
    if((key=ftok(".",'s'))==-1)
    {
        perror("ftok error\n");
        exit(1);
    }
    if((semid=semget(key,1,IPC_CREAT|0666))==-1)
    {
        perror("semget error\n");
        exit(1);
    }
    semopts.val=MAX_RESOURCE;
    if(semctl(semid,0,SETVAL,semopts)==-1)//semctl 设置SETVAL 5，初始化计数器
    {
        perror("semctl error\n");
        exit(1);
    }
    while(1)
    {
        if(semop(semid,&sbuf,1)==-1)//sbuf.sem_op=-1,则信号量递减,到0,semop error!: Resource temporarily unavailable
        { 
            perror("semop error!\n");
            exit(1);
        }
        sleep(3);
    }

}