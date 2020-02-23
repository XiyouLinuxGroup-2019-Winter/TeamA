#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <cstring>
using namespace std;
int ans;
int sum1[16000001];
int sum2[16000001];
int main()
{
    int n;
    scanf("%d", &n);
    int x[n][4];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            scanf("%d", &x[i][j]);
        }
    }
    int p = 0, q = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            sum1[p++] = x[i][0] + x[j][1];
            sum2[q++] = x[i][2] + x[j][3];
        }
    }
    sort(sum2, sum2 + q);
    // printf("\n");
    // for (int i = 0; i < q; i++)
    // {
    //     printf("%d ",sum2[i]);
    // }
    // printf("\n");
    // for (int  i = 0; i < p; i++)
    // {
    //     printf("%d  ",sum1[i]);
    // }
    
    
    for (int i = 0; i < p; i++)
    {
        int low = 0;
        int high = q-1;
        
            
        while (high >= low)
        {
            //if(i==p-1)
    //        printf("i=%d,sum1[i]=%d,high=%d.low=%d,mid=%d,sum2[mid]=%d\n",i,sum1[i],high,low,(high+low)/2,sum2[(high+low)/2]);
            int mid = (low + high) / 2;
            if (sum1[i] ==- sum2[mid])
            {
          //     printf("hahaha %d\n",sum1[i]);
                int down = 0;
                int up = 0;//mid=3,down=3,,
                while (down <= mid && sum2[mid] == sum2[mid - down])
                    down++;
                while (up + mid < q && sum2[mid] == sum2[mid + up])
                    up++;//q=6,mid=3,   345,up=2; 
                ans += up + down-1;
                break;
            }
            else if (sum1[i] + sum2[mid]<0)
                low = mid + 1;
            else
                high = mid - 1;
        }
    }
    printf("%d",ans);
}