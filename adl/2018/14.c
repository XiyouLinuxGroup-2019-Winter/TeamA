#include<stdio.h>
int Convert(const char*num)
{
  
   char ch;
   static int s;
   while ((ch=*num++)!='\0')
   {
       s=(ch-'0')+s*10;
   }
   return s;
}
int main()
{
    char*str="12345";
    int res=Convert(str);
    printf("%d",res);
}