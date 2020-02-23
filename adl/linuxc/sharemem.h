#include<sys/types.h>
#include<sys/shm.h>
#include<sys/sem.h>
#include<errno.h>
#include<fcntl.h>


#include<string.h>

#include<sys/ipc.h>

#include<unistd.h>
#include<stdio.h>
#include<stdlib.h>

#define SHM_SIZE 1024
union semun{
    int val;
    struct semid_ds *buf;
    unsigned short *array;
};
int createsem(const char *pathname,int proj_id,int members,int  init_val)
{
    key_t msgkey;
    int index,sid;
    union semun semopts;
    msgkey=ftok(pathname,proj_id);
    sid=semget(msgkey,members,IPC_CREAT|0666);
    semopts.val=init_val;
    for ( index = 0; index < members; index++)
    {
        semctl(sid,index,SETVAL,semopts);
    }
    return sid;    
}
int opensem(const char*pathname,int proj_id)
{
    key_t msgkey;
    int sid;
    msgkey=ftok(pathname,proj_id);
    sid=semget(msgkey,0,IPC_CREAT|0666);
    return sid;
}
int sem_p(int semid,int index)
{
    struct sembuf buf={0,-1,IPC_NOWAIT};
    if(index<0)
    {
        perror("index of array cannot equals a minus value!");
        return -1;
    }
    buf.sem_num=index;
    semop(semid,&buf,1);
    return 0;
}
int sem_v(int semid,int index)
{
    struct sembuf buf={0,1,IPC_NOWAIT};
    if(index<0)
    {   
        perror("index of array cannot equals a minus value!");
        return -1;
    }
    buf.sem_num=index;
    semop(semid,&buf,1);
    return 0;
}
int sem_delete(int semid)
{
    return (semctl(semid,0,IPC_RMID)==0);
}
int wait_sem(int semid,int index)
{
    while(semctl(semid,index,GETVAL,0)==0)
    {
        sleep(1);
    }
    return 1;
}
int createshm(char *pathname,int proj_id,size_t size)
{
    key_t shmkey;
    int sid;
    shmkey=ftok(pathname,proj_id);
    sid=shmget(shmkey,size,IPC_CREAT|0666);
    return sid;
}