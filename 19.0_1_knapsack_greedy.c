/*

ID : B171452
Code By Sandeep Payili on 28/10/2021

Problem Description : 0/1 knapsack Greedy Algorithm
(Knapsack problem is sometimes called as container loading problem)

(0-1 Knapsack cannot be solved by Greedy approach. Greedy approach does not ensure an optimal solution.)

*/

#include<stdio.h>
float knapsack_0_1_greedy(int n, int *weigths_array, int *values_array, int W, float *profit_by_weight_ratio_array, int *selected_items_array)
{
	float maximum_value = 0;
	int i = 0, j = 0;
	int current_knapsack_capacity = W;// we keep on reducing whhile we fill bag
	int maximum_ratio_index = 0; // assigning first one is maximum
	for (i = 0; i < n  && (current_knapsack_capacity > 0) ; i++) // loop until all items are over or knapsack capacity is over
	{
		for (j = 0; j < n; j++)
		{
			if (profit_by_weight_ratio_array[j] != -1 && (profit_by_weight_ratio_array[j] >= profit_by_weight_ratio_array[maximum_ratio_index] ))
			{
				maximum_ratio_index = j;
			}
		}
		if (weigths_array[maximum_ratio_index] <= current_knapsack_capacity)
		{
			maximum_value += values_array[maximum_ratio_index];
			profit_by_weight_ratio_array[maximum_ratio_index] = -1;

			current_knapsack_capacity -= weigths_array[maximum_ratio_index];

			selected_items_array[maximum_ratio_index] = 1;// since we selected maximum_ratio_index item
		}
		// printf("current_knapsack_capacity :-   %d \n", current_knapsack_capacity);
	}
	return maximum_value;
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

	// build profit/weight ratio array
	float profit_by_weight_ratio_array[n];
	for (i = 0; i < n; i++)
	{
		profit_by_weight_ratio_array[i] = ( (float)values_array[i] /  weigths_array[i] );
	}

	int selected_items_array[n]; // 0  for not selected
	for (i = 0; i < n; i++)
	{
		selected_items_array[i] = 0;
	}
	float maximum_value = knapsack_0_1_greedy(n, weigths_array, values_array, W, profit_by_weight_ratio_array, selected_items_array);
	printf("\nMaximum Value (Profit)   :  %f \n", maximum_value);
	printf("\nSelected Items ( 0 to %d  ) :  ", n - 1);
	for ( i = 0; i < n; i++)
	{
		if (selected_items_array[i] != 0)
		{
			printf(" %d  ", i);
		}
	}
	printf("\n\n");
	return 0;
}


// Division of two integers result in integer to get in float we explicitly typecast one of operand to float


// we can solve in another approach as sort the profit_by_weight_ratio_array and take the item with highest ratio and
// add them until we can't add the next item.


/*

This example shows the  Drawback of This Greedy Approach  since profit/weight is more for 1st item it is selected and remaining capacity is 
wasted in 0 1 knapsack greedy approach
However picking 2nd item is best solution this can be obtain in dynamic programming so we prefer dynamic programming way for 0/1 knapsack 
problem.


Enter Number of items :  2
Enter item 1 Weight and Value respectively : 1 2
Enter item 2 Weight and Value respectively : 100 100
Enter Knapscak Capacity :   100

Maximum Value (Profit)   :  2.000000 

Selected Items ( 0 to 1  ) :   0  

*/