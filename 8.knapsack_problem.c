/*

ID : B171452
Code By Sandeep Payili on 19/10/2021

Problem Description : Knapsack Problem By Exhaustive Search(Brute Force)
	(The knapsack problem is a problem in combinatorial optimization: Given a set of items, each with a weight and a value,
		determine the number of each item to include in a collection so that the total weight is less than or
	 	equal to a given limit and the total value is as large as possible.)

*/

 /*
 
 As the name suggests, the “fractional knapsack” is the one in which we can take objects in fractions, 
 i.e, in decimals (in floating points) whereas
  the “0/1 knapsack” is the one in which we can take objects in whole numbers (in interger value)
 
 */
#include<stdio.h>
#include <limits.h> // for INT_MAX and INT_MIN 
#include<math.h> // also we need to compile by including   -lm 
int main()
{
	int n;
	printf("Enter No. of Items :  ");
	scanf(" %d", &n);
	int weights[n];
	int values[n];//costs or profit
	printf("\nEnter Weights  :  \n\n");
	int i, j;
	for (i = 0; i < n; i++)
	{
		printf("Enter Item %d Weight : ", i);
		scanf(" %d", &weights[i]);
	}
	printf("\nEnter Values  :  \n\n");
	for (i = 0; i < n; i++)
	{
		printf("Enter Item %d value : ", i);
		scanf(" %d", &values[i]);
	}
	int W;//knapsack Capacity / Total Weight it can HOLD
	printf("\n\nEnter knapsack Capacity :  ");
	scanf(" %d", &W);

	//base case
	if (W == 0 || n == 0)
	{
		return 0;
	}
	int max_weight = INT_MIN;
	int max_value = INT_MIN;
	int current_max_weight;
	int current_max_value;
	int max_profitable_items_combination = 0;
	//main logic
	for (i = 1; i < pow(2, n); i++) // starting from 1 since omiting empty subset
	{
		current_max_weight = 0;
		current_max_value = 0;
		// i as bit masking
		for (j = 0; j < n; j++)
		{
			if (  (i & (1 << j)) != 0 )
			{
				// printf(" i== %d  j ==  %d   \t"  ,i,j );
				current_max_weight += weights[j];
				current_max_value += values[j];
			}
		}
		// printf("\n i = %d  current_max_value : %d\n",i,current_max_value);
		// checking knapsack for each sub set to make more profit
		if (  current_max_weight <= W  && current_max_value  >  max_value )
		{
			max_weight = current_max_weight;
			max_value = current_max_value;
			max_profitable_items_combination = i;
		}
	}
	printf("\n\nMaximum Profitable Weight of Knapsack is :  %d\n", max_weight);
	printf(  "\nMaximum Profitable Value of Knapsack is :  %d\n", max_value);
	printf(  "\nMaximum Profitable Combination of Knapsack is by Selecting Items ( 0 to %d ) :  \n",n-1);
	for (j = 0; j < n; j++)
	{
		if ( (max_profitable_items_combination & (1 << j)) != 0 )
		{
			printf("Item :   %d   Weight :  %d   Value : %d   \n", j, weights[j], values[j]);
		}
	}
	printf("\n\n");
	return 0;
}

/*

OUTPUT :
Enter No. of Items :  10

Enter Weights  :  

Enter Item 0 Weight : 90
Enter Item 1 Weight : 123
Enter Item 2 Weight : 1241
Enter Item 3 Weight : 124
Enter Item 4 Weight : 141
Enter Item 5 Weight : 1241
Enter Item 6 Weight : 1421
Enter Item 7 Weight : 96
Enter Item 8 Weight : 27
Enter Item 9 Weight : 367

Enter Values  :  

Enter Item 0 value : 1001
Enter Item 1 value : 1241
Enter Item 2 value : 1241
Enter Item 3 value : 141
Enter Item 4 value : 1241
Enter Item 5 value : 124141
Enter Item 6 value : 1405
Enter Item 7 value : 367
Enter Item 8 value : 2457
Enter Item 9 value : 2568


Enter knapsack Capacity :  347


Maximum Profitable Weight of Knapsack is :  336

Maximum Profitable Value of Knapsack is :  5066

Maximum Profitable Combination of Knapsack is by Selecting Items ( 0 to 9 ) :  
Item :   0   Weight :  90   Value : 1001   
Item :   1   Weight :  123   Value : 1241   
Item :   7   Weight :  96   Value : 367   
Item :   8   Weight :  27   Value : 2457   

*/