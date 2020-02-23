#include"sharemem.h"
int main()
{
    int semid,shmid;
    char*shmaddr;
    char write_str[SHM_SIZE];
    shmid=createshm(".",'m',SHM_SIZE);
    shmaddr=shmat(shmid,(char*)0,0);
    semid=createsem(".",'s',1,1);
    while(1)
    {
        wait_sem(semid,0);
        sem_p(semid,0);
        printf("writer:");
        fgets(write_str,SHM_SIZE,stdin);
        int len=strlen(write_str)-1;// /n->/0 
        write_str[len]='\0';
        strcpy(shmaddr,write_str);
        // sleep(10);
        sem_v(semid,0);
         sleep(10);
    }
}