/*
	Author: Mohnish
	Version 1.0
	Automatic indentation of a c program
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define TAB "\t"

char *clearFile(FILE *read, FILE *write); //Removes all tab spaces and newline chars in given txt file
void indentLine(char *line, FILE *write);//Adds tabs and newline

char *clearFile(FILE *read, FILE *write)
{
	char* line = NULL;
	char* inter;
	char* line_final = (char*)malloc(1);
	line_final[0] = '\0';
	int lenstr = 0;
	
	size_t len = 0; 
	ssize_t read1;
	int i, j = 0;
	while ((read1 = getline(&line, &len, read)) != -1)
	{
		
		if(line[0] != '#')
		{
			inter = (char*)malloc(strlen(line));
			int i = 0;
			int j = 0;
			while(line[i] != '\n')
			{
				if(line[i] != '\t')
				{
					inter[j] = line[i];
					j++;
				}	
				i++;
			}
			
			inter[j] = '\0';
			lenstr = strlen(line_final);
			line_final = (char*)realloc(line_final,lenstr+strlen(inter)+1);
			line_final = strcat(line_final, inter);
		}
		else
		{
			
			fprintf(write,"%s",line);
		}
	}
	return line_final;
}

void indentLine(char* line, FILE *write)
{
	int i, j, flag = 0;
	i = 0;
	int tabCount = 0;
	while(line[i] != '\0')
	{
		if(line[i] == '(')
			flag = 1;
		if(line[i] == '"')
			flag = 1;
		
		if(flag == 0)
		{
			if(line[i] == '{')
			{	
				fprintf(write,"\n");
				for(j = 0;j < tabCount;j++)
				{
					fprintf(write,"\t");	
				}
				fprintf(write,"{\n");
				tabCount += 1;
				for(j = 0;j < tabCount;j++)
				{
					fprintf(write,"\t");	
				}
			}
			else if(line[i] == '}')
			{
				fprintf(write,"\n");
				tabCount -= 1;
				for(j = 0;j < tabCount;j++)
				{
					fprintf(write,"\t");	
				}
				
				fprintf(write,"}");
				if(line[i+1] != '}')
					fprintf(write,"\n");
				for(j = 0;j < tabCount;j++)
				{
					fprintf(write,"\t");	
				}
				
			}
			else if(line[i] == ';')
			{
				if(line[i+1] != '}')
					fprintf(write,";\n");
				for(j = 0;j < tabCount;j++)
				{
					fprintf(write,"\t");	
				}
				
			}else
			{
				fprintf(write,"%c",line[i]);
			}
			i++;
		}
		else
			{
				fprintf(write,"%c",line[i]);
				i++;
			}
		if(flag == 1 && line[i] == ')')
		{
			flag = 0;
		}
		if(flag == 1 && line[i] == '"')
		{
			flag = 0;
		}
	
	}
}

int
main(
	int argc,
	char *argv[]
	)
{
	
	FILE *read = fopen( argv[1],"r");

	if( read == NULL ) 
	{
		printf("File to be read can't be opened \n");
		return 1;
	}

	FILE *write = fopen( argv[2], "w");

	if( write == NULL ) 
	{
		printf("File to be written on can't be opened \n");
		return 2 ;
	}
	
	if( argc == 3)
	{
		
		char* line = clearFile(read, write);
		//fflush(write);
		//fclose(write);
		indentLine(line, write);	
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

