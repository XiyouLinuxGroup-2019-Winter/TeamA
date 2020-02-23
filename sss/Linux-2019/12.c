#include <stdio.h>
int main()
{
	int nums[6]={6,3,2,4,2,5};
	for(int i=0;i<6;i++)
	{
		for(int j=i;j<6;j++)
		{
			if(nums[i]>nums[j])
			{
				int c=nums[i];
				nums[i]=nums[j];
				nums[j]=c;
			}
		}
	}
}

