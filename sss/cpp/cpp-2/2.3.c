#include <stdio.h>
int main()
{
	int i,j,k,n,m;
	scanf("%d-%d-%d",&i,&j,&k);
	n=2020-i;
	if(n==0)
		printf("%d",17-k);
	else if(n==1)
	        {
			if(j==1)
				m=k;
                        else if(j==2)
				m=31+k;
			else if(j==3)
				m=31+29+k;
			else if(j==4)
				m=31*2+29+k;
			else if(j==5)
				m=31*2+29+30+k;
			else if(j==6)
				m=31*3+29+30+k;
			else if(j==7)
				 m=31*3+29+30*2+k;
			else if(j==8)
				 m=31*4+29+30*2+k;
			else if(j==9)
				 m=31*5+29+30*2+k;
			else if(j==10)
				m=31*5+29+30*3+k;
			else if(j==11)
				m=31*6+29+30*3+k;
			else if(j==12)
				m=31*6+29+30*4+k;
			printf("%d",365-m+17);
		}
          else
	  {
                	  if(j==1) 
				  m=k;
                          else if(j==2) 
                                 m=31+k;
                          else if(j==3)
                                  m=31+29+k;
                          else if(j==4)
                                  m=31*2+29+k;
                          else if(j==5)
                                  m=31*2+29+30+k;
                          else if(j==6)
                                  m=31*3+29+30+k;
                          else if(j==7)
                                   m=31*3+29+30*2+k;
                          else if(j==8)
                                   m=31*4+29+30*2+k;
                          else if(j==9)
                                   m=31*5+29+30*2+k;
                          else if(j==10)
                                  m=31*5+29+30*3+k;
                          else if(j==11)
                                  m=31*6+29+30*3+k;
                          else if(j==12)
				  m=31*7+29+30*3+k;
                      int p;
		  p=365*(n-1)+365-m+17;
			  printf("%d",p);
	  }
}
