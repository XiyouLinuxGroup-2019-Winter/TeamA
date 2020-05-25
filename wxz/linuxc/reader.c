#include <sharemem.h>
int main()
{
    int semid,shmid;
    char* shmaddr;
    char write_str[SHM_SIZE];
    shmid=createshm(".",'m',SHM_SIZE);
    shmaddr=shmat(shmid,(char*)0,0);
    semid=opensem(".",'s');
    while(1)
    {
        printf("reader:");
        wait_sem(semid,0);
        sem_p(semid,0);
        
        printf("%s\n",shmaddr);
        
        sleep(10);
        sem_v(semid,0);
        sleep(10);
    }
}