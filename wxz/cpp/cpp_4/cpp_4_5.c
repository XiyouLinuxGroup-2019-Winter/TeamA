#include <stdio.h>
#include <string.h>
int main()
{
	char name[10];
	char surname[10];
	scanf("%s %s",name,surname);
	
	int namelen=strlen(name);
	int surnamelen=strlen(surname);
	printf("%s %s\n",name,surname);
	printf("%*d%*d\n",namelen,namelen,surnamelen,surnamelen);

	printf("%s %s\n",name,surname);
	printf("%-*d %-*d\n",namelen,namelen,surnamelen,surnamelen);
}
