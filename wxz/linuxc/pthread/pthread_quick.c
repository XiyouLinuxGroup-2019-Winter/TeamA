/*************************************************************************
	> File Name: pthread_quick.c
	> Author: 
	> Mail: 
	> Created Time: 2020年05月17日 星期日 16时18分41秒
 ************************************************************************/

#include<stdio.h>
#include <sys/time.h>
#include <pthread.h>
#include <unistd.h>
#include <stdlib.h>


struct node
{
    int l,r;
    int id;
};
int max=100;
int a[100];
pthread_mutex_t lock=PTHREAD_MUTEX_INITIALIZER;


void meger(int left1,int right1,int left2,int right2)
{
    int n=right2-left1+1;
    int b[n];
    
    int *data=b;
    for(int i=0;i<n;i++)
        data[i]=0;
    int l1=left1,l2=left2;
    int i=0;
    while(l1<=right1 && l2<=right2)
    {
        if(a[l1]<a[l2])
            data[i++]=a[l1++];
        else   
            data[i++]=a[l2++];
    }
 
    while(l1 <= right1) 
        data[i++] = a[l1++];
    while(l2 <= right2) 
        data[i++] = a[l2++];

    int id=0;
    for(i=left1;i<=right2;i++)
        a[i]=data[id++];

    free(data);
}
void swap(int *a,int *b)
{
    int temp=*a;
    *a=*b;
    *b=temp;
}
void qsorts(int left,int right)
{
    if(left>=right)
        return;

    
    int i=left;
    int j=right;
    while(i<j)
    {
        while(j>i && a[i]<=a[j])
            i++;
        if(i!=j)
            swap(&a[i],&a[j]);
        while(i<j && a[i]<=a[j])
            j--;
        if(i!=j)
            swap(&a[i],&a[j]);

    }
       

    qsorts(left,i-1);
    qsorts(i+1,right);



}

void *play(void *arg)
{
    struct node* sort;
    sort=(struct node*)arg;
    printf("thread sort->id:%d sort begin!\n",pthread_self());
    qsorts(sort->l,sort->r);
    printf("thread sort->id:%d sort end!\n",pthread_self());
}

int main()
{
    srand((unsigned)time(NULL));
    int i;
    for(i=0;i<100;i++)
        a[i]=rand()%1000;
    
    for(i=0;i<100;i++)
        printf("%d ",a[i]);
    printf("\n");
    

    struct node s[10];
    for(i=0;i<10;i++)
    {
        s[i].id=i;
        s[i].l=i*10;
        s[i].r=i*10+9;
    }
    pthread_t tid[10];
    for(i=0;i<10;i++)
        pthread_create(&tid[i],NULL,play,(void*)&s[i]);
    
    for(i=0;i<10;i++)
        pthread_join(tid[i],NULL);
    
    int left=0;
    int right=9;
    for(i=1;i<10;i++)
    {
        meger(left,right,s[i].l,s[i].r);
        right+=10;
    }
    for(i=0;i<100;i++)
        printf("%d ",a[i]);
    printf("\n");
}
