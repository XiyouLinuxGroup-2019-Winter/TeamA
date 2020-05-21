#include<stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
#include <string.h>

int cnt=0;
int buf[10];
int take=0;
int put=0;
int point=0;
int blank=10;

int flag=0;
pthread_mutex_t lock=PTHREAD_MUTEX_INITIALIZER;
pthread_cond_t notfull=PTHREAD_COND_INITIALIZER;
pthread_cond_t notempty=PTHREAD_COND_INITIALIZER;

void *product(void* arg)
{
    while(flag)
    {
        pthread_mutex_lock(&lock);
        while(!blank)
            pthread_cond_wait(&notfull,&lock);
        
        buf[put]=cnt++;
        put=(put+1)%10;
        point++;
        blank--;

    
        pthread_cond_signal(&notempty);
        pthread_mutex_unlock(&lock); 

        printf("product %d ----cnt=%d\n",pthread_self(),cnt);
        for(int i=0;i<10;i++)
            printf("%d\n",buf[i]);
       
    }
    pthread_exit(NULL);
}
void* consumer(void *arg)
{
    while(flag)
    {
        pthread_mutex_lock(&lock);
        while(!point)
            pthread_cond_wait(&notfull,&lock);

        buf[take]=-1;
        take=(take+1)%10;
        cnt--;
        point--;
        blank++;

        pthread_cond_signal(&notfull);
        pthread_mutex_unlock(&lock);
        
        printf("consumer %d ---cnt=%d",pthread_self(),cnt);

        for(int i=0;i<10;i++)
            printf("%d\n",buf[i]);

    }
    pthread_exit(NULL);
}
int main()
{
    memset(buf,-1,sizeof(buf));
    pthread_t tid[10],cid[10];
    int i=0;

    for(i=0;i<10;i++)
    {
        pthread_create(&tid[i],NULL,product,NULL);
        pthread_create(&cid[i],NULL,consumer,NULL);
    }
    sleep(1);

    flag=-1;
    for(i=0;i<10;i++)
    {
        pthread_join(tid[i],NULL);
        pthread_join(cid[i],NULL);
    }
}