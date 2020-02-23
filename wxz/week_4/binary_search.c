/*************************************************************************
	> File Name: binary_search.c
	> Author: 
	> Mail: 
	> Created Time: 2020年02月11日 星期二 16时19分04秒
 ************************************************************************/

#include<stdio.h>
int list[length];
int binary_search(int key)
{
    int left=0;
    int right=length-1;
    while(left<=right)
    {
        int min=(left+right)/2;
        if(list[min]<key)
            left=mid+1;
        else if(list[mid]>key)
            right=mid-1;
        else
            return mid;
    }
    return -1;
}
