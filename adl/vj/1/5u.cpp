#include<cstdio>
#include<cstring>
using namespace std;
char s[500005];
int main()
{
int i,j,len;   // i , j 控制循坏，len测出字符串的长度
int start=0,place1=0,flag1=0,F1=0;   //start 记录首个"["的位置，place1记录最邻近"["的 ：,F1,flag1,分别标记这两个位置是否已经找到
int end=0,place2=0,flag2=0,F2=0;  //end记录最后的"]"的位置，place2记录最邻近"]"的 ：,F2,flag2,分别标记这两个位置是否已经找到
int sum=0; //记录最长 Accordion 的长度
scanf("%s",s);
len=strlen(s)-1;
for(i=0;i<=len;i++)  //从前往后找出第一个"["的位置
{
if(s[i]=='[')
{
start=i;sum++;F1=1;   //找到了，便进行相关的数据处理，就可以结束了
break;
}
}
for(j=len;j>i;j--)  //从最末尾开始搜索最后一个"]"的位置，只需在(i,len)之间搜索即可
{
if(s[j]==']')
{
end=j;sum++;F2=1;  //数据处理
break;  //结束循坏
}
}
if(F1&&F2)   //是否找到了"[""]"，是就继续，否则就可以结束了
{
for(i=start+1;i<=end-1;i++) //从start的下一个位置开始搜索 ：的位置
  {
  if(s[i]==':')
  {
  place1=i;flag1=1;sum++;  //数据处理
  break;
   } 
  } 
for(j=end-1;j>i;j--)  //从end前一个位置开始搜索 ：的位置，在(i,end-1)之间搜索即可
{
if(s[j]==':')  
{
place2=j;flag2=1;sum++; //printf("%d\n",place2);   这是 dig bug
break;
}
  }
  if(flag1&&flag2)  //找到了，就继续，没找到，就可以结束了
  {
  for(i=place1+1;i<=place2-1;i++)  //在（place1+1,place2-1）之间找“|”
  {
  if(s[i]=='|') sum++;
}
printf("%d\n",sum);  //输出总长度
}
else printf("-1\n");
    //printf("%d %d %d start,flag1,place1\n%d %d %d end,flag2,place2\n%d %d\n",start,flag1,place1,end,flag2,place2,cnt1,cnt2);   dig bug
}
else printf("-1\n");
return 0;
}