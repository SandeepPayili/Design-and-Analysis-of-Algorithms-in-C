/*

ID : B171452
Code By Sandeep Payili on 27/10/2021

Problem Description : 0/1 Knapscak Problem Using Dynamic Programming by Memoization

*/
#include<stdio.h>
#include<stdlib.h>
#include<string.h> //  for memset function
int max(int a, int b)
{
	return (a > b) ? a : b;
}
// for storing results of sub problem in array
int knapsack(int n, int *weights_array, int *values_array, int W, int **knapsack_array)
{
	if (n == 0  || W == 0 )
	{
		knapsack_array[n][W] = 0;
		return 0;
	}
	if (weights_array[n - 1] <= W)
	{
		knapsack_array[n][W] = max(values_array[n - 1] + knapsack(n - 1, weights_array, values_array, W - weights_array[n - 1], knapsack_array), knapsack(n - 1, weights_array, values_array, W, knapsack_array));
		return knapsack_array[n][W];
	} else
	{
		knapsack_array[n][W] = knapsack(n - 1, weights_array, values_array, W, knapsack_array);
		return knapsack_array[n][W];
	}
}
// for storing results of sub problem in array
void void_knapsack(int n, int *weights_array, int *values_array, int W, int **knapsack_array)
{
	if (n == 0  || W == 0 )
	{
		knapsack_array[n][W] = 0;
		return;
	}
	if (weights_array[n - 1] <= W)
	{
		void_knapsack(n - 1, weights_array, values_array, W - weights_array[n - 1], knapsack_array);
		knapsack_array[n][W] = ( values_array[n - 1] +  knapsack_array[n - 1][W - weights_array[n - 1]]);
		void_knapsack(n - 1, weights_array, values_array, W, knapsack_array);
		knapsack_array[n][W] = max(knapsack_array[n][W], knapsack_array[n - 1][W]);
	} else
	{
		void_knapsack(n - 1, weights_array, values_array, W, knapsack_array);
		knapsack_array[n][W] = knapsack_array[n - 1][W];
	}
}

int knapsack_memoization(int n, int *weights_array, int *values_array, int W, int **knapsack_array)
{
	if (n == 0  || W == 0 )
	{
		knapsack_array[n][W] = 0;
		return 0;
	}
	if (knapsack_array[n][W] != -1) // already calculated
	{
		return knapsack_array[n][W];
	}
	if (weights_array[n - 1] <= W)
	{
		knapsack_array[n][W] = max(values_array[n - 1] + knapsack_memoization(n - 1, weights_array, values_array, W - weights_array[n - 1], knapsack_array), knapsack_memoization(n - 1, weights_array, values_array, W, knapsack_array));
		return knapsack_array[n][W];
	} else
	{
		knapsack_array[n][W] = knapsack_memoization(n - 1, weights_array, values_array, W, knapsack_array);
		return knapsack_array[n][W];
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
	// memset(starting address of memory to be filled,value to be filled,number of bytes to be filled starting from address given);


	// int maximum_value = knapsack(n, weights_array, values_array, W, knapsack_array);
	// printf("\nMaximum Value (Profit)   :  %d \n", knapsack_array[n][W]);
	// printf("\nMaximum Value (Profit)   :  %d \n", maximum_value);
	// void_knapsack(n, weights_array, values_array, W, knapsack_array);
	// printf("\nMaximum Value (Profit)   :  %d \n", knapsack_array[n][W]);


	int maximum_value =  knapsack_memoization(n, weights_array, values_array, W, knapsack_array);
	// printf("\nMaximum Value (Profit)   :  %d \n", knapsack_array[n][W]);
	printf("\nMaximum Value (Profit)   :  %d \n", maximum_value);
	/*
	for (i = 0; i <= n; i++)
	{
		for (int j = 0; j <= W; j++)
		{
			printf(" %3d ", knapsack_array[i][j]);
		}
		printf("\n");
	}
	*/
	return 0;
}
/*
Complexity Analysis:

    Time Complexity: O(N*W).
    As redundant calculations of states are avoided.
    Auxiliary Space: O(N*W).
    The use of 2D array data structure for storing intermediate states
*/


/*

OUTPUT :

Enter No. Of Items  : 10
Enter item 1 Weight and Value respectively : 90 1001
Enter item 2 Weight and Value respectively : 123 1241
Enter item 3 Weight and Value respectively : 1241 1241
Enter item 4 Weight and Value respectively : 124 141
Enter item 5 Weight and Value respectively : 141 1241
Enter item 6 Weight and Value respectively : 1241 124141
Enter item 7 Weight and Value respectively : 1421 1405
Enter item 8 Weight and Value respectively : 96 367
Enter item 9 Weight and Value respectively : 27 2457
Enter item 10 Weight and Value respectively : 367 2568
Enter Knapscak Capacity :   347

Maximum Value (Profit)   :  5066

*/