#include <stdio.h>
#include <ctype.h>
int main(int argc,char* argv[])
{
	char ch;
	if(argv[1][0]=='-')
	{
		if(argv[1][1]=='p')
			while((ch=getchar())!=EOF)
			printf("%c\n",ch);
			else if(argv[1][1]=='u')
				while((ch=getchar())!=EOF)
				printf("%c\n",toupper(ch));
			   else if(argv[1][1]=='l')
				   while((ch=getchar())!=EOF)
					printf("%c\n",tolower(ch));
	}
}
