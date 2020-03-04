#include <stdio.h>
#include <stdlib.h>
int main()
{
         typedef struct STU
         {
             char num[17];
             int s1;
             int s2;
         }stu;
      int i,j,N,M;
      scanf("%d",&N);
      stu *s;
      s=(stu*)malloc(sizeof(stu)*N);
      for(i=0;i<N;i++)
      {

      scanf("%s%d%d",&(s[i].num),&(s[i].s1),&(s[i].s2));
      }

      scanf("%d",&M);
      int *p;
      p=(int*)malloc(sizeof(int)*M);
      for(i=0;i<M;i++)
      scanf("%d",p+i);
      for(i=0;i<M;i++)
      {
               for(j=0;j<N;j++)
                  if(s[j].s1==p[i])
                   printf("%s %d\n",s[j].num,s[j].s2);
       }
}
