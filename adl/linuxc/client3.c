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
    int semid,semval;
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

    while(1)
    {
        if((semval=semctl(semid,0,GETVAL,0))==-1)//getval从semid得到val=5,4,3,2,1
        { 
            perror("semctl error!\n");
            exit(1);
        }
        if(semval>0)
        {
            printf("still %d resouces can be used\n",semval);
        }
        else{
            printf("no more resouces can be used\n");
            break;
        }
        sleep(3);
    }

}