
#include <stdio.h>
#include <stdlib.h>

void evaluate(int board[][], int rowNo, int size,int* count);

bool setInvalid(int flag, int rowNo, int colNo, int board[][], int size);
/*
 *For the setInvalid() function
 *flag == 1 to set values
 *flag == -1 to remove inv insertions made by the previous function call
 *
 */


int main()
{
	
	return 0;
}

void evaluate(int board[][], int rowNo, int size, int* count)
{

	int i;
	for(i = 0;i < size;i++)
	{
		if(board[rowNo][i] == 0)
		{
			setInvalid( 1 ,rowNo, i, board, size);
			if(rowNo < (size - 1))
			{
				evaluate(board, rowNo + 1, size, count);
				setInvalid( -1, rowNo, i, board, size);			
			}
			else
			{
				*count = *count + 1;
				return;
			}
		}
		else if(board[rowNo][i] == 1)
		{
			if(rowNo < (size - 1))
				evaluate(board, rowNo + 1, size, count);
			else
			{
				*count = *count + 1;
				return;
			}
		}
	}
}

void setInvalid(int flag, int rowNo, int colNo, int board[][], int size) // 4 * N - 1 operations
{

	board[rowNo][colNo] += flag;
	int i;
	for(i = 1;( i + rowNo) < size; i++)
		board[rowNo + i][colNo] += -flag;
	
	for(i = 1;(rowNo - i) >= 0; i++)
		board[rowNo - i][colNo] += -flag;	

	for(i = 1;( i + colNo) < size; i++)
		board[rowNo][i + colNo] += -flag;	

	for(i = 1;( colNo - i) >= 0; i++)
		board[rowNo][colNo - i] += -flag;
	
	for(i = 1;((rowNo + i) < size && (colNo + i) < size); i++) 
		board[rowNo + i][colNo + i] += -flag;
	
	for(i = 1;((rowNo + i) < size && (colNo - i) >= 0); i++) 
		board[rowNo + i][colNo - i] += -flag;
	
	for(i = 1;((rowNo - i) >= 0 && (colNo - i) >= 0); i++) 
		board[rowNo - i][colNo - i] += -flag;

	for(i = 1;((colNo + i) < size && (rowNo - i) >= 0); i++) 
		board[rowNo - i][colNo + i] += -flag;
}

