/*************************************************************************
	> File Name: pthrd_endof3.c
	> Author: 
	> Mail: 
	> Created Time: 2020年04月21日 星期二 00时18分32秒
 ************************************************************************/

#include<stdio.h>
#include <unistd.h>
#include <pthread.h>
void* tfn1(void* arg);
void* tfn2(void* arg);
void* tfn3(void* arg);
void* tfn1(void* arg)
{
    printf("thread 1 returning\n");
    return (void*)111;//exit(111)
}
void* tfn2(void* arg)
{
    printf("thread 2 exiting\n");
    pthread_exit((void*)222);
}
void tfn3(void* arg)
{
    while(1)
    {
        printf("thread 3:I'm going to die in 3 seconds....\n ");
        sleep(1);
    }
    return (void*)666;
}
int main()
{
    pthread_t tid;
    void* tret=NULL;

    pthread_create(&tid,NULL,tfn1,NULL);
    pthread_join(tid,&tret);
    printf("thread 1 exit code=%d\n",(int)tret);

    pthread_create(&tid,NULL,tfn2,NULL);
    pthread_join(tid,&tret);
    printf("thread 2 exit code=%d\n",(int)tret);

    pthread_create(&tid,NULL,tfn3,NULL);
    sleep(3);
    pthread_cancle(tid);
    pthread_join(tid,&tret);
    printf("thread 3 exit code=%d\n",(int)tret);


}
