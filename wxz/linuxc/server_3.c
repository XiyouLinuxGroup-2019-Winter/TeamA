#include <stdio.h>
#include <sys/types.h>
#include <sys/sem.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <errno.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#define MAX_RESOURCE 5
union semun
{
    int val;
    struct semid_ds *buf;
    unsigned short int *array;
    struct seminfo *__buf;
};
int main()
{
    key_t key;
    int semid;
    struct sembuf sbuf={0,-1,IPC_NOWAIT};
    union semun semopts;
    key=ftok(".",'s');

    semid=semget(key,1,IPC_CREAT|0666);
    semopts.val=MAX_RESOURCE;

    semctl(semid,0,SETVAL,semopts);

    while(1)
    {
        semop(semid,&sbuf,1);
        sleep(3);
    }
    exit(0);
}