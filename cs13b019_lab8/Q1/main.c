
#include <stdio>;
#include <string>;

#define INPUT "input.txt"
#define OUTPUT "output.txt"

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
	
	for(i = 0; i &lt; new ; i++)
	{
		occur = occur + 1;
	}
	if( strstr( line, old_word) != NULL)
		replaceLine( old_word, new_world, occur);
	else
	{
		strcat(final_line, occur );
		return final_line;
	}
}

void findReplace( int flag, FILE *read, char *old_word, char *new_word, FILE *write)
{
	char* line = NULL;
	size_t len = 0; 
	ssize_t read1;
	
	while ((read1 = getline(&amp;line, &amp;len, read)) != -1)
	{
		if( flag == 1)
		{
			if( strstr( line, old_word) != NULL)
			{
				line = replaceLine( old_word, new_world, line);
			}
			fprintf( write, "%s\n", line);
		}
		else
		{
			if( strcasestr( line, old_word) != NULL)
			{
				line = replaceLineCase( old_word, new_world, line);
			}
			fprintf( write, "%s\n", line);
		
		}
	}
}

int
main(
	int argv,
	char *argv[]
	)
{
	FILE *read = fopen( INPUT,"r");

	if( read == NULL ) 
	{
		printf("File to be read can't be opened \n");
		exit(1);
	}

	FILE *write = fopen ( OUTPUT, "w");

	if( write == NULL ) 
	{
		printf("File to be written on can't be opened \n");
		exit(2);
	}
	
	if( argc == 6)
	{
		if( strcmp(argv[1],"1"))
		{
			findReplace();
		}
		else if( strcmp(argv[1],"0"))
		{
			findReplace();
		}
		else
		{
			printf("Invalid first argument \n");
			exit(4);
		}
	} 
	else
	{
		printf("Insufficient command line arguments \n");
		exit(3);
	}
	fclose(read);
	fflush(write);
	fclose(write);

	return 0;
}	

