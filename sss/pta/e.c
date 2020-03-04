#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
int main()
{
          int len1,len2,i=0,j=0,flag1=0,flag2=0;
          char s1[100],s2[100],ch;
          while((ch=getchar())!=' ')
          s1[i++]=ch;
          s1[i]='\0';
          while((ch=getchar())!='\n')
                 s2[j++]=ch;
          s2[j]='\0';
          len1=strlen(s1), len2=strlen(s2);
          for(i=0;i<len1;i++)
          if(!isdigit(s1[i])||atoi(s1)<1||atoi(s1)>1000)
          {
                 flag1=1;
                  break;
            }
           if(len1==0)
             flag1=1;
           for(i=0;i<len2;i++)
                if(!isdigit(s2[i])||atoi(s2)<1||atoi(s2)>1000)
                {
                            flag2=1;
                            break;
                }
           if(flag1==1&&flag2!=1)
                         printf("? + %s = ?",s2);
           if(flag1!=1&&flag2==1)
                         printf("%s + ? = ?",s1);
           if(flag1==1&&flag2==1)
                         printf("? + ? = ?");
           if(flag1!=1&&flag2!=1) 
                         printf("%s + %s = %d",s1,s2,(atoi(s1)+atoi(s2)));
       return 0;
}
