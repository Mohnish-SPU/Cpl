/*
Author Mohnish

version 1.5

Program to read a file and replace a word with another specified in the command line 
with a flag to specify whether to do a case or case insensitive search.



*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void findReplace( int flag, FILE *read, char *old_word, char *new_word, FILE *write);
char* replaceLine( char *old_word, char *new_word, char *line, char *line_final);
char* replaceLineCase( char *old_word, char *new_word, char *line, char* line_final);
int nof(char* old_word,char* line);

int nof(char* old_word,char* line)
{
	int new,i;
	
	char* occur = strcasestr(line,old_word);
	if(strcasestr(line,old_word) != NULL)
	{	
		new = strlen(old_word);
	
		for(i = 0; i < new ; i++)
		{
			occur = occur + 1;
		}
		return (1 + nof(old_word,occur));
	}
	else 
		return 0;
}


char* replaceLine( char *old_word, char *new_word, char *line, char *line_final)
{

	line_final = (char*)realloc( line_final, strlen(line) + strlen(new_word) - strlen(old_word) + 1);
	char *occur; 
	int n, new, i;
	
	
	
	occur = strstr( line, old_word);
	
	n = strlen(line) - strlen(occur);
	strncat(line_final, line, n);
	strcat( line_final, new_word);

	new = strlen(old_word);
	
	for(i = 0; i < new ; i++)
	{
		occur = occur + 1;
	}
	if( strstr(occur,old_word) != NULL)
		replaceLine(old_word,new_word,occur, line_final);
	else
	{
		strcat(line_final, occur );
		return line_final;
	}
}

char* replaceLineCase( char *old_word, char *new_word, char *line, char* line_final)
{
	
	line_final = (char*)realloc( line_final, strlen(line) + strlen(new_word) - strlen(old_word) + 1);
	
	char *occur;
	int n, new, i;

	occur = strcasestr( line, old_word);
	
	n = strlen(line) - strlen(occur);
	
	strncat(line_final, line, n);
	strcat( line_final, new_word);
	
	new = strlen(old_word);
	
	for(i = 0; i < new ; i++)
	{
		occur = occur + 1;
	}
	if( strcasestr( occur, old_word) != NULL)
		replaceLineCase( old_word, new_word, occur,line_final);
	else
	{
		strcat(line_final, occur );
		return line_final;
	}
}


void findReplace( int flag, FILE *read, char *old_word, char *new_word, FILE *write)
{
	char* line = NULL;
	char *line_final;
	size_t len = 0; 
	ssize_t read1;
	int nofwrd;
	while ((read1 = getline(&line, &len, read)) != -1)
	{	
		nofwrd = nof(old_word,line);
		line_final = (char*)malloc(strlen(line) + 1000000);
		if( flag == 1)
		{
			if( strstr( line, old_word) != NULL)
			{
				replaceLine( old_word, new_word, line, line_final);
				fprintf( write, "%s", line_final);
			}
			else
			{
				fprintf( write, "%s", line);
			}
		}
		else
		{
			
			if( strcasestr( line, old_word) != NULL)
			{
				replaceLineCase( old_word, new_word, line, line_final);
				fprintf( write, "%s", line_final);
			}
			else
			{
				fprintf( write, "%s", line);
			}
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

	FILE *write = fopen( argv[5], "w");

	if( write == NULL ) 
	{
		printf("File to be written on can't be opened \n");
		return 2 ;
	}
	
	if( argc == 6)
	{
		if( strcmp(argv[1],"1") == 0)
		{
			
			findReplace( 1, read, argv[3], argv[4], write);
		}
		else if( strcmp(argv[1],"0") == 0)
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

