# include <stdio.h>
# include <stdlib.h>
 
# define FNAME "no12.txt"
# define FARGS "no12.dat"
# define STR " .':~*=&%#"
 
int main(void)
{
	FILE * fp , * ft;
	int ar[20][30] ;
	char st[20][31] ;
 
	if (!(fp = fopen(FNAME, "r")))
	{
		fprintf(stderr , "Can't open file %s.\n" ,FNAME) ; 
		exit(EXIT_FAILURE);
	}
 
	if (!(ft = fopen(FARGS , "w")))
	{
		fprintf(stderr , "Can't open file %s.\n" ,FARGS);
		exit(EXIT_FAILURE);
	}
 
	
	 	for (int i = 0 ; i < 20 ; i++)	
		for (int j = 0 ; j < 30 ; j++)
	 						 									while (fscanf(fp ,"%d" , &ar[i][j]) != 1)
	 													fscanf(fp ,"%*c");
	
	 													 	 													 		for (int j ,i = 0 ; i < 20 ; i++)
	 													 			{
	 													 					for ( j = 0 ; j < 30 ; j++)
	 													 								st[i][j] = *(STR + ar[i][j]);
	 													 										st[i][j] = '\0' ;
	 													 												fprintf(ft ,"%s\n" ,st[i] );
	 													 													}
	 													 														
	 													 															if (fclose(fp) || fclose(ft))	
	 													 																{
	 													 																		fprintf(stderr , "Clossing error .\n");
	 													 																				exit(EXIT_FAILURE);
	 													 																					}
	 													 																						
	 													 																							return 0 ;
	 													 																						}
