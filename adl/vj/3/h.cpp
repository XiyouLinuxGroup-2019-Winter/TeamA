#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cstdlib>
#include<cstring>
using namespace std;
#define min(x,y) x>y?y:x
#define max(x,y) x>y?x:y
int ans;int n,c;int *book;int *x;

void dfs( int cc,int mi,int pre_distance)//q,为第几只，cc为所剩奶牛数,mi最小距离
{
    if(cc==0)
    {
        ans=max(ans,mi);
        return;
    }
    int temp=mi;
    for (int i = 0; i < n; i++)
    {
        if(!book[i])
        {
            book[i]=1;
            mi=min(mi,x[i]-pre_distance);
            dfs(cc-1,mi,x[i]);
            // if(cc-1==0)
            //     mi=0x3f3f3f;
            book[i]=0;
        }
        mi=temp;
    }
  //  mi=0x3f3f3f;
    

    
    

}
int main()
{
    
    scanf("%d%d",&n,&c);
    
    x=(int *)malloc(n*sizeof(int));
    book=(int *)malloc(n*sizeof(int));
    memset(book,0,n*sizeof(int));
    for (int i = 0; i < n; i++)
        scanf("%d",&x[i]);
    sort(x,x+n);
    dfs(c,0x3f3f3f3f,-0x3f3f3f3f);
    printf("%d",ans);
}