#include<stdio.h>
#include<string.h> 
void pubblesort(int st[],int n);
int main(void)
{	 int i,n; 
scanf("%d",&n);
int a[n];
for(i=0;i<n;i++)
scanf("%d",&a[i]);
pubblesort(a,n);
for(i=0;i<n;i++)
printf("%d",a[i]);	
	return 0;
 } 
void pubblesort(int st[],int n )
 {
 	int temp,j,i;
	int  index;//ÿһ�����һ��Ҫ�Ƚϵ��������ĵ�һ�� 
 	int book=1;	//�������� 
 
 	index=n-2;//5����23154����һ�ζ���Ҫȫ�ȵģ�5��a[3]; 
 	int k=index; 
	 for(i=0;i<n;i++)
	  {
	  	for(j=0;j<=k;j++)
	  	{
	  		if(st[j]>st[j+1])
	  		{temp=st[j];
	  		st[j]=st[j+1];
	  		st[j+1]=temp;
			  book=0; 
			  index=j-1;
			  }
		  }
	  if(book) 
	  return;
	  k=index;
	  }
 	
 }
