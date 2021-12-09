/*

ID : B171452
Code By Sandeep Payili on 27/10/2021

Problem Description : 0/1 Knapscak Problem Using Dynamic Programming by Tabulation (bottom-up manner)

*/
#include<stdio.h>
#include<stdlib.h>
int max(int a, int b)
{
	return (a > b) ? a : b;
}

void knapsack_tabulation2(int n, int *weights_array, int *values_array, int W, int **knapsack_array)
{
	int i = 0, j = 0;
	for (i = 0; i <= n; i++)
	{
		knapsack_array[i][0] = 0; // base condition  when weight is zero value(profit) is zero
	}
	for (j =  0; j <= W; j++)
	{
		knapsack_array[0][j] = 0; // base condition  when no. of items  is zero value(profit) is zero
	}
	for (i = 1; i <= n; i++) {
		for (j = 1; j <= W; j++)
		{
			if ( weights_array[i - 1] <= j)
			{

				knapsack_array[i][j] = max( values_array[i - 1] + knapsack_array[i - 1][j - weights_array[i - 1]], knapsack_array[i - 1][j] );
			} else
			{
				knapsack_array[i][j] = knapsack_array[i - 1][j];
			}
		}
	}
}

// build table in bottom up manner
void knapsack_tabulation(int n, int *weights_array, int *values_array, int W, int **knapsack_array)
{
	int i = 0, j = 0;
	for (i = 0; i <= n; i++) {
		for (j = 0; j <= W; j++)
		{
			if(i==0 || j ==0 ) // base condition for zero items or zero weight knapsack capacity
			{
				knapsack_array[i][j] = 0;
			}
			else if ( weights_array[i - 1] <= j)
			{

				knapsack_array[i][j] = max( values_array[i - 1] + knapsack_array[i - 1][j - weights_array[i - 1]], knapsack_array[i - 1][j] );
			}else
			{
				knapsack_array[i][j] = knapsack_array[i - 1][j];
			}
		}
	}
}

int main()
{
	int n;
	printf("Enter No. Of Items  : ");
	scanf(" %d", &n);
	int weights_array[n];
	int values_array[n];
	int i = 0, j = 0;
	for (i = 0; i < n; i++)
	{
		printf("Enter item %d Weight and Value respectively : ", i + 1);
		scanf(" %d %d", &weights_array[i], &values_array[i]);
	}
	int W; // knapsack capacity(maximum weight)
	printf("Enter Knapscak Capacity :   ");
	scanf(" %d", &W);
	int **knapsack_array;
	knapsack_array = (int **)malloc( (n + 1) * sizeof(int *)); // [0,n] indices
	for (i = 0; i <= n; i++)
	{
		knapsack_array[i] = (int *)malloc((W + 1) * sizeof(int));//[0,W] indices
		for (j = 0; j <= W; j++)
		{
			knapsack_array[i][j] = -1;
		}
	}

	knapsack_tabulation(n, weights_array, values_array, W, knapsack_array);
	printf("\nMaximum Value (Profit)   :  %d \n", knapsack_array[n][W]);
	/*
	for (i = 0; i <= n; i++)
	{
		for (j = 0; j <= W; j++)
		{
			printf("  %5d  ", knapsack_array[i][j]);
		}
		printf("\n" );
	}
	*/
	return 0;
}
/*

Complexity Analysis: 

    Time Complexity: O(N*W). 
    where ‘N’ is the number of weight element and ‘W’ is capacity.
    As for every weight element we traverse through all weight capacities 1<=w<=W.
    Auxiliary Space: O(N*W). 
    The use of 2-D array of size ‘N*W’.

*/