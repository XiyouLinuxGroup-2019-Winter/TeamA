/*#include <stdio.h>
#include <string.h>
struct book
{
    int status;
    int time;
}b[1000];

int main()
{
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        memset(b,0,sizeof(struct book)*1000);
        int cnt=0;
        int a,c,d;
        char e;
        double sum=0;
        while(1)
        {
            scanf("%d %c %d:%d",&a,&e,&c,&d);
            if(a==0)
                break;
            else
            {
                if(e=='S')
                {
                    b[a].status=1;
                    b[a].time=c*60+d;
                }
                else if(b[a].status==1 && e=='E')
                {
                    b[a].status=0;
                    b[a].time=c*60+d-b[a].time;
                    cnt++;
                    sum+=b[a].time;
                }
            }
        }
        
        if(cnt==0 || sum==0)
            printf("0 0\n");
        else
            printf("%d %.0f\n",cnt,sum/cnt);

    }
}*/
#include <stdio.h>
int main()
{
    int x,y,z;
    int n;
    int flag=0;
    scanf("%d",&n);
    int i=0;
    for(x=0;x<=100;x++)
    {
        for(y=0;y<=100;y++)
        {
            for(z=0;z<=100;z++)
            {
                if(x+y+z==100 && x*5+y*3+z/3==100 && z%3==0)
                {
                    flag=0;
                    i++;
                    if(x > 0 && i<= n)
					{
                        flag=1;
                        //if(i>n)
                          // break;
                    }
                    else if(x>0 && i>n)
                        flag=

                }
            }
        }
    }
}
