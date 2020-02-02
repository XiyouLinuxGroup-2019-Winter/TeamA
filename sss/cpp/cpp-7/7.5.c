#include <stdio.h>
int main()
{
	char ch;
	int n=0;
	while((ch=getchar())!='#')
	{
		switch (ch)
		{
			case '.' :{
					
					  putchar('!');
					  n++;
				          break;
				  }
		        case '!' : {
					   putchar('!');
					   putchar('!');
					   n++;
					   break;
				   }
			default: putchar(ch);
		}
		
	}
	printf("%d",n);
}

					   
		         
