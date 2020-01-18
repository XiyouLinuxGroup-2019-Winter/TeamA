#include<stdio.h>
#include<string.h>
int main()
{
    char s[1010];
   
    while (scanf("%s",s)==1&&strcmp(s,"0")!=0)
    {
         int he=0;
        int i=0;
        while (s[i]!='\0')
        {
            he+=s[i]-'0';
            i++;
        }
        while (he>=10)
        {
            int temp=he;
            he=0;
            while(temp)
            {
                he+=temp%10;
                temp/=10;
            }
            
        }
        printf("%d\n",he);
        
    }
    
    return 0;
}