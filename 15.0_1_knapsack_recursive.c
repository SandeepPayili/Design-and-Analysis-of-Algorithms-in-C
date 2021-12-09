/*

ID : B171452
Code By Sandeep Payili on 27/10/2021

Problem Description : 0/1 Knapscak Problem Using Recursion

*/

/*

Types  of Knapsack Problems:
1) 0/1 Knapsack
2) Fractional knapsack
3) Unbounded Knapsack (Repetition of items allowed)	

*/

/*
Recursion by Brute-Force algorithm OR Exhaustive Search.
Approach: A simple solution is to consider all subsets of items and calculate the total weight and value of all subsets. Consider the only subsets whose total weight is smaller than W. From all such subsets, pick the maximum value subset.
Optimal Sub-structure: To consider all subsets of items, there can be two cases for every item. 
    Case 1: The item is included in the optimal subset.
    Case 2: The item is not included in the optimal set.
If the weight of ‘nth’ item is greater than ‘W’, then the nth item cannot be included and Case 1 is the only possibility.
*/

/*

When do we say particular problem is having Dynamic Programming is :
1) There is a choice (we can take or leave)
2) Optimization (maximizes or minimizes)
3) Recursive Formula

*/
#include<stdio.h>
#include<stdlib.h>

int max(int a, int b)
{
	return (a > b) ? a : b;
}

// return maximum value(Profit)
int knapsack(int n, int *weigths_array, int *values_array, int W)
{
	if (n == 0 || W <= 0) // when number of iterms is zero
	{
		return 0;
	}
	if( weigths_array[n-1] <= W)// Choice is only when nth item is under feasible weight only 
	{
		return max((values_array[n - 1] + knapsack(n - 1, weigths_array, values_array, W - weigths_array[n - 1] )), knapsack(n - 1, weigths_array, values_array, W));
	}else
	{
		return knapsack(n-1,weigths_array,values_array,W);
	}
}
int main()
{
	int n;
	printf("Enter Number of items :  ");
	scanf(" %d", &n);
	int weigths_array[n];
	int values_array[n];
	int i = 0;
	for (i = 0; i < n; i++)
	{
		printf("Enter item %d Weight and Value respectively : ", i + 1);
		scanf(" %d %d", &weigths_array[i], &values_array[i]);
	}
	int W; // knapsack capacity(maximum weight)
	printf("Enter Knapscak Capacity :   ");
	scanf(" %d", &W);
	int maximum_value;
	maximum_value = knapsack(n, weigths_array, values_array, W); // results in maximum value of knapsack considering items right to left
	printf("\nMaximum Value (Profit)   :  %d \n", maximum_value);
	return 0;
}
/*
The time complexity of this naive recursive solution is exponential (2^n).  

Complexity Analysis: 

    Time Complexity: O(2^n). 
    As there are redundant subproblems.
    Auxiliary Space :O(1). 
    As no extra data structure has been used for storing values.
*/

/*
Since subproblems are evaluated again, this problem has Overlapping Sub-problems property.
So the 0-1 Knapsack problem has both properties (Overlapping Subproblems Property and Optimal Substructure Property) of a dynamic programming problem. 
*/


/*

OUTPUT : 

Enter Number of items :  4
Enter item 1 Weight and Value respectively : 3 2 
Enter item 2 Weight and Value respectively : 4 2
Enter item 3 Weight and Value respectively : 6 1
Enter item 4 Weight and Value respectively : 3 4
Enter Knapscak Capacity :   8

Maximum Value (Profit)   :  6 

*/