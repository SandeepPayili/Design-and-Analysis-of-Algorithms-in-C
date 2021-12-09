/*

ID : B171452
Code By Sandeep Payili on 29/10/2021

Problem Description : Fractional  knapsack Greedy Algorithm
(Container loading problem with divisible items)

*/

#include<stdio.h>
float fractional_knapsack_greedy(int n, int *weigths_array, int *values_array, int W, float *profit_by_weight_ratio_array, float *selected_items_array)
{
	float maximum_value = 0;
	int i = 0, j = 0;
	int current_knapsack_capacity = W;// we keep on reducing while we fill bag
	int maximum_ratio_index = 0; // assigning first one is maximum
	for (i = 0; i < n  && (current_knapsack_capacity > 0) ; i++) // loop until all items are over or knapsack capacity is over
	{
		for (j = 0; j < n; j++)
		{
			// > or >= both will work
			if (profit_by_weight_ratio_array[j] != -1 && (profit_by_weight_ratio_array[j] > profit_by_weight_ratio_array[maximum_ratio_index] ))
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
		} else
		{
			maximum_value += (profit_by_weight_ratio_array[maximum_ratio_index] * current_knapsack_capacity);
			selected_items_array[maximum_ratio_index] = (float)current_knapsack_capacity / weigths_array[maximum_ratio_index];
			current_knapsack_capacity = 0;
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

	float selected_items_array[n]; // 0  for not selected
	for (i = 0; i < n; i++)
	{
		selected_items_array[i] = 0;
	}
	float maximum_value = fractional_knapsack_greedy(n, weigths_array, values_array, W, profit_by_weight_ratio_array, selected_items_array);
	printf("\nMaximum Value (Profit)   :  %f \n", maximum_value);
	printf("\nQuantity of Selected Items ( 0 to %d  ) :  ", n - 1);
	for ( i = 0; i < n; i++)
	{
		printf(" %f  ", selected_items_array[i]);
	}
	printf("\n\n");
	return 0;
}

//we can also verify that sum(xi,wi) = W
//where xi i ith element in selectd_items_array and wi is ith item weight

// Maximum profit = sum(xi,pi)
//where xi i ith element in selectd_items_array and pi is ith item profit

//Constraint :    sum(xi,wi) <= W
//Objective :     maximize (sum(xi,pi) )

/*

OUTPUT:-

Enter Number of items :  7
Enter item 1 Weight and Value respectively : 2 10
Enter item 2 Weight and Value respectively : 3 5
Enter item 3 Weight and Value respectively : 5 15
Enter item 4 Weight and Value respectively : 7 7
Enter item 5 Weight and Value respectively : 1 6
Enter item 6 Weight and Value respectively : 4 18
Enter item 7 Weight and Value respectively : 1 3
Enter Knapscak Capacity :   15

Maximum Value (Profit)   :  55.333332

Quantity of Selected Items ( 0 to 6  ) :   1.000000   0.666667   1.000000   0.000000   1.000000   1.000000   1.000000

*/

/*


Enter Number of items :  7
Enter item 1 Weight and Value respectively : 1 5
Enter item 2 Weight and Value respectively : 3 10
Enter item 3 Weight and Value respectively : 5 15
Enter item 4 Weight and Value respectively : 4 7
Enter item 5 Weight and Value respectively : 1 8
Enter item 6 Weight and Value respectively : 3 9
Enter item 7 Weight and Value respectively : 2 4
Enter Knapscak Capacity :   15

Maximum Value (Profit)   :  51.000000 

Quantity of Selected Items ( 0 to 6  ) :   1.000000   1.000000   1.000000   0.000000   1.000000   1.000000   1.000000  

*/