/*************************************************************************
	> File Name: cpp_14_3.c
	> Author: 
	> Mail: 
	> Created Time: 2020年01月11日 星期六 16时58分15秒
 ************************************************************************/

#include<stdio.h>
#include <string.h>
#define MAXTITL 40
#define MAXAUTL 40
#define MAXBKS 100
struct book{
    char title[MAXTITL];
    char author[MAXAUTL];
    float value;
};
void show(struct book *a[],int n);
void show_value(struct book* a[],int n);
int main()
{
    struct book library[MAXBKS];
    struct book *order[100];
    int count=0;
    int index;
    printf("Please enter the book title.\n");
    printf("press [enter] at the start of a line to stop.\n");
    while(count<MAXBKS && fgets(library[count].title,MAXTITL,stdin)!=NULL && library[count].title[0]!='\0')
    {
        printf("Now enter the author.\n");
        scanf("%s",library[count].author);
        printf("Now enter the value.\n");
        scanf("%f",library[count].value);
        while(getchar()!='\n')
        continue;
        if(count<MAXBKS)
        printf("Enter the next title.\n");
    }
    if(count>0)
    {
        printf("Here is the list of your books:\n");
        for(index=0;index<count;index++)
        printf("%s by %s :$%.2f\n",library[index].title,library[index].author,library[index].value);
        printf("按标题字母升序输出:\n");
        show(order,count);
        printf("按value值升序输出:\n");
        show_value(order,count);
    }    
    else
        printf("No books?Too bad.\n");
}

void show(struct book* a[],int n)
{
    struct book* temp;
    int i,j;
    for(i=0;i<n-1;i++)
    {
        for(j=i;j<n;j++)
        {
            if(strcmp((a[i]->title),(a[j]->title))>0)
            {
                temp=a[i];
                a[i]=a[j];
                a[j]=temp;
            }
        }
    }
    for(i=0;i<n;i++)
    printf("%s by %s :$%.2f\n",a[i]->title,a[i]->author,a[i]->value);
}

void show_value(struct book* a[],int n)
{
    struct book* temp;
    int i,j;
    for(i=0;i<n-1;i++)
    {
        for(j=i;j<n;j++)
        {
            if(strcmp((a[i]->value),(a[j]->value))>0)
            {
                temp=a[i];
                a[i]=a[j];
                a[j]=temp;
            }
        }
    }
    for(i=0;i<n;i++)
    printf("%s by %s :$%.2f\n",a[i]->title,a[i]->author,a[i]->value);
}
