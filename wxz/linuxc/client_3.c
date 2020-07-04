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
    int semid,semval;
    union semun semopts;
    key=ftok(".",'s');

    semid=semget(key,1,IPC_CREAT|0666);

    while(1)
    {
        semval=semctl(semid,0,GETVAL,0);
        if(semval>0)
            printf("still %d resources can be used\n",semval);
        else
        {
            printf("no more resources can be used\n");
            break;
        }
        sleep(3);
    }
    exit(0);
}