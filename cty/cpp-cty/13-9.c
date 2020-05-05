# include <stdio.h>
# include <stdlib.h>
# include <string.h>
 
# define MAX 41
 
int main(void)
{
	FILE * fp ;
	char words[MAX] ;
	long num = 0 ;
 
	if ((fp = fopen("wordy" , "a+")) == NULL)
	{
		fprintf(stderr , "Can't open \"wordy\" file.\n");
		exit(EXIT_FAILURE);
	}
 
	
		while (fscanf(fp , "%ld %s \n" , &num , words) > 0) ;
		 
		 	puts("Enter words to add to the file; press the #");
		 		puts("key at the beginning of a line to terminate.");
		 			while ((fscanf(stdin , "%40s" , words)) == 1 && (words[0] != '#'))
		 					fprintf(fp , "%ld %s\n" , ++num , words); 		 					 
		 					 	puts("File contents:");
		 					 		rewind(fp);
		 					 			while (fscanf(fp , "%ld %s\n" , &num , words) == 2)
		 					 					fprintf(stdout , "%ld %s\n" , num , words);
		 					 						puts("Done!");
		 					 							if (fclose(fp) != 0)
		 					 									fprintf(stderr , "Error closing file.\n");
		 					 									 
		 					 									 	return 0 ;
		}
