/*************************************************************************
	> File Name: test2.c
	> Author: 
	> Mail: 
	> Created Time: 2020年01月31日 星期五 10时23分47秒
 ************************************************************************/

/*#include<stdio.h>
#include <math.h>
int main()
{
    float x;
    scanf("%f",&x);
    float y=sqrt(x);
    printf("%.4f",y);
}

#include <stdio.h>
#include <math.h>
int main()
{
    int a,b,c;
    char d,e;
    int cnt=0;
    scanf("%d %c %d %c %d",&a,&d,&b,&e,&c);
        if(d=='+')
        {
            if(c==a+b)
                puts("correct\n");
            else
                puts("incorrect\n");
        }
        if(d=='-')
        {
            if(c==a-b)
                puts("correct\n");
            else
                puts("incorrect\n");
        }
        if(d=='*')
        {
            if(c==a*b)
                puts("correct\n");
            else
                puts("incorrect\n");
        }
        if(d=='/')
        {
            if(d==a/b)
                puts("correct\n");
            else
            puts("incorrect\n");
        }
}
*/
/*#include <stdio.h>
int main()
{
    int x;
    scanf("%d",&x);
    if(90<=x&& x<=100)
        puts("A");
    else if(80<=x&& x<90)
        puts("B");
    else if(70<=x && x<80)
        puts("C");
    else if(60<=x && x<70)
        puts("D");
    else if(0<=x && x<60)
        puts("E");
    else if(x<0 || x>100)
        puts("ERROR");

}*/
/*#include <stdio.h>
#include <string.h>
int main()
{
    int a[100],b[100];
    int i;
    int x;
    for(i=0;i<100;i++)
        scanf("%d",&a[i]);
    int n=strlen(a);
    i=0;
    for(int j=strlen(a),i=0;j>=0;j--)
        b[i++]=a[j];
    int sum=0;
    for(i=0;i<n;i++)
    {
        sum=a[i]+b[i];
        printf("%s + %s=%d",a[i],b[i],sum);
    }
}

#include <stdio.h>
int main()
{
    int m,n;
    int cnt=0;
    scanf("%d %d",&m,&n);
    int i,j;
    for(i=m;i<=n;i++)
    {
        if(i>=2)
        {
            int j;
            for(j=2;j<=i/2;j++)
                if(i%j==0)
                    break;
            if(j>i/2)
            {
                printf("%d ",i);
                cnt++;
                if(cnt%5==0)
                    printf("\n");
            }
            //if(cnt%5==0)
                //printf("\n");
        }        
    }  
}
*/
/*#include <stdio.h>
#include <string.h>
int main()
{
    int a[101];
    int i;
    for(i=0;i<100;i++)
    {
        scanf("%d",&a[i]);
        if(a[i]==-1)
            break; 
    }
    int min=0;
    int n=strlen(a)-1;
    for(i=1;i<n-1;i++)
    {
        if(a[i]<=min)
            min=i;
    }
    int t=a[0];
    a[0]=a[min];
    a[min]=t;

    int max=0;
    for(i=1;i<n-1;i++)
    {
        if(a[i]>=max)
            max=i;
    }
    int tem=a[n-2];
    a[n-2]=a[max];
    a[max]=tem;

    int sum=0;
    for(i=0;i<n-1;i++)
        sum+=a[i];
    int aver=0;
    aver=sum/(n-1);
    printf("max=%d\n",a[0]);
    printf("min=%d\n",a[n-1]);
    printf("average=%d\n",aver);
    
}*/
/*#include <stdio.h>

struct Inner{
    short S;
    double d;
    int f;
}Inner;
struct Outer{
    short ch[3];
    int i;
    double d;
    short S;
    struct Inner n;
}Outer;
int main()
{
    printf("%d %d",sizeof(Inner),sizeof(Outer));
}
*/
/*#include<math.h>
#include <stdio.h>
void main()

{

 float x,y,z;

    scanf("%f,%f",&x,&y);

    z=x/y;

    while(1)

    {  if(fabs(z)>1.0)

      {

 x=y;

 y=x;

 z=x/y;

 }

     else  break;

   }

   printf("%f",y);

}*/
/*#include<stdio.h>

void main()

{

int i,n=0;

  for(i=2;i<5;i++)

  {

do

      {

  if(i%3) continue;

         n++;

      } while(!i);

      n++;

   }

   printf("n=%d",n);

}*/
/*#include<stdio.h>

void main()

{

   int n=4;

   while(n)

    printf("%d",--n);

}*/
/*#include <stdio.h>
int main()
{
for(int i=2;i==0;)
   printf("%d",i--);
}*/
/*#include<stdio.h>
int main()
{
int n=10;

  while(n>7)

  { 

 printf("%d,\n",n);

      n--;

   }
}


void main()

{

int i=5;

  for(;i<15;)

  {

 i++;

    if(i%4==0)    printf("%2d",i);

    else          continue;

  }

}*/
/*#include<stdio.h>

#include<string.h>

void main()

{

char str[10]="Ch\nina";

printf("%d",strlen(str));
*/
#include<stdio.h>

    void main()

   {

    int i,j,s=0;

    int a[4][4]={1,2,3,4,0,2,4,6,3,6,9,12,3,2,1,0};

    for(j=0;j<4;j++)

   {

      i=j;

      if(i>2) i=3-j;

      s+=a[i][j];

   }

   printf("%d\n",s);

   }
