include <stdio.h>
int main()
{
int m,n,i;
scanf("%d%d",&m,&n);
int a[m],b[m];
for(i=0;i<m;i++)
scanf("%d",a+i);
for(i=0;i<m;i++){
if(i+n>m-1)
b[(i+n-m)%m]=a[i];
else b[i+n]=a[i];
}
for(i=0;i<m-1;i++)
printf("%d ",b[i]);
printf("%d",b[m-1]);
}
。。。。。。。。。。
#include <stdio.h>
#include <string.h>
void multi(char a[],char b[]){
int len1=strlen(a),i,m;
if(a[0]-'0'<5){
for(i=len1-1;i>=0;i--){
if(b[i]=='\0')
b[i]='0';
if((a[i]-'0')*2>=10)
b[i]=b[i]+((a[i]-'0')*2)%10,b[i-1]='1';
else b[i]=b[i]+(a[i]-'0')*2;
}
}
else{
for(i=len1-1;i>=0;i--){
if(b[i+1]=='\0')
b[i+1]='0';
if((a[i]-'0')*2>=10)
b[i+1]=b[i+1]+((a[i]-'0')*2)%10,b[i]='1';
else b[i+1]=b[i+1]+(a[i]-'0')*2;
}
}
}
void Aarr(char a[])
{
int i,j,len=strlen(a),term;
for(i=0;i<len-1;i++)
for(j=len-1;j>i;j--)
if(a[j-1]>a[j])
term=a[j-1],a[j-1]=a[j],a[j]=term;
}
int main(){
char a[22],b[22],term[22];
int i,j,count=0;
for(i=0;i<22;i++)
b[i]='\0',term[i]='\0'; 
gets(a);
int len=strlen(a);
multi(a,b);
for(i=0;i<len;i++)
term[i]=b[i];
if(a[0]>='5')
printf("%s\n","No"),puts(b);
else{
Aarr(a);
Aarr(b);
if(strcmp(a,b)==0)
printf("%s\n","Yes"),puts(term);
else 
printf("%s\n","No"),puts(term);
}
}
