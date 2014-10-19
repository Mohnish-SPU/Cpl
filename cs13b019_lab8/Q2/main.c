/*
	Author: Mohnish
	Version 1.0
	Automatic indentation of a c program
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

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

