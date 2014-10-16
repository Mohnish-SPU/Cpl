/*
Author Mohnish

version 1.1

Program to read a file and replace a word with another specified in the command line 
with a flag to specify whether to do a case or case insensitive search.



*/
#include <stdio.h>
#include <string.h>

/*
#define INPUT "input.txt"
#define OUTPUT "output.txt"
*/

void findReplace( int flag, FILE *read, char *old_word, char *new_word, FILE *write);
char* replaceLine( char *old_word, char *new_word, char *line);
char* replaceLineCase( char *old_word, char *new_word, char *line);


char* replaceLine( char *old_word, char *new_word, char *line)
{
	
	
	char *occur, *line_final;
	int n, new, i;
	
	line_final = "";
	occur = strstr( line, old_word);
	
	n = strlen(old_word) - strlen(occur);
	
	strncat(line_final, line, n);
	strcat( line_final, new_word);
	
	new = strlen(old_word);
	
	for(i = 0; i < new ; i++)
	{
		occur = occur + 1;
	}
	if( strstr( occur, old_word) != NULL)
		replaceLine( old_word, new_word, occur);
	else
	{
		strcat(line_final, occur );
		return line_final;
	}
}


char* replaceLineCase( char *old_word, char *new_word, char *line)
{
	
	
	char *occur, *line_final;
	int n, new, i;
	
	line_final = "";
	occur = strcasestr( line, old_word);
	
	n = strlen(old_word) - strlen(occur);
	
	strncat(line_final, line, n);
	strcat( line_final, new_word);
	
	new = strlen(old_word);
	
	for(i = 0; i < new ; i++)
	{
		occur = occur + 1;
	}
	if( strcasestr( occur, old_word) != NULL)
		replaceLineCase( old_word, new_word, occur);
	else
	{
		strcat(line_final, occur );
		return line_final;
	}
}


void findReplace( int flag, FILE *read, char *old_word, char *new_word, FILE *write)
{
	char* line = NULL;
	size_t len = 0; 
	ssize_t read1;
	
	while ((read1 = getline(&line, &len, read)) != -1)
	{
		if( flag == 1)
		{
			if( strstr( line, old_word) != NULL)
			{
				line = replaceLine( old_word, new_word, line);
			}
			fprintf( write, "%s\n", line);
		}
		else
		{
			if( strcasestr( line, old_word) != NULL)
			{
				line = replaceLineCase( old_word, new_word, line);
			}
			fprintf( write, "%s\n", line);
		
		}
	}
}

int
main(
	int argc,
	char *argv[]
	)
{
	FILE *read = fopen( argv[2],"r");

	if( read == NULL ) 
	{
		printf("File to be read can't be opened \n");
		return 1;
	}

	FILE *write = fopen ( argv[5], "w");

	if( write == NULL ) 
	{
		printf("File to be written on can't be opened \n");
		return 2 ;
	}
	
	if( argc == 6)
	{
		if( strcmp(argv[1],"1"))
		{
			findReplace( 1, read, argv[3], argv[4], write);
		}
		else if( strcmp(argv[1],"0"))
		{
			findReplace( 0, read, argv[3], argv[4], write);
		}
		else
		{
			printf("Invalid first argument \n");
			return 4;
		}
	} 
	else
	{
		printf("Insufficient command line arguments \n");
		return 3;
	}
	fclose(read);
	fflush(write);
	fclose(write);

	return 0;
}	

