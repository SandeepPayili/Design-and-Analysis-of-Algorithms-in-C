#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>


bool issafe(int **board,int row,int col,int n)
{
	int i=0,j=0;
	// same row left side
	for(j=0;j<col;j++)
	{
		if(board[row][j])
		{
			return false;
		}
	}
	// upper left diagonal
	for(i=row,j=col;i>=0 && j>=0 ;i--,j--)
	{
		if(board[i][j])
		{
			return false;
		}
	}

	// lower left diagonal
	for(i=row,j=col;i<n && j>=0 ;i++,j--)
	{
		if(board[i][j])
		{
			return false;
		}
	}
	return true;
}


bool N_Queen(int **board,int col,int n)
{
	if(col >= n)
	{
		return true;
	}
	int i=0;
	for(i=0;i<n;i++)
	{
		if(issafe(board,i,col,n))
		{
			board[i][col] = 1;
			if(N_Queen(board,col+1,n))
			{
				return true;
			}
			board[i][col] = 0; //BACK TRACK
		}
	}
	return false;
}
int main()
{
	int n;
	int i=0,j=0,k=0;
	printf("Enter N :  ");
	scanf(" %d",&n);
	int **board;
	board = (int **)malloc(n*sizeof(int *));
	for(i=0;i<n;i++)
	{
		*(board+i) = (int *)malloc(n*sizeof(int));
	}	
	// filling board
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)	
		{
			board[i][j] = 0;
		}
	}
	if(N_Queen(board,0,n) == false)
	{
		printf("\n\n Solution Does Not Exist .... \n\n");
	}
	else
	{
		// print board
		for(i=0;i<n;i++)
		{
			for(j=0;j<n;j++)
			{
				printf(" %d ",board[i][j]);
			}
			printf("\n");
		}
	}
	return 0;
}
// O(n^n)