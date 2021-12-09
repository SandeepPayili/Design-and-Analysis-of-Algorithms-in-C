/*

ID : B171452
Code By Sandeep Payili on 19/10/2021

Problem Description : Print Power Set of Given Numeric Array By Bit Masking

*/
#include<stdio.h>
#include<math.h> // also we need to compile by including   -lm 
void print_all_subsets(int *a, int n)
{
	int i = 1; 
	int j;
	for (i = 1; i < pow(2, n); i++) // starting from 1 since omiting empty subset
	{
		// i as bit masking
		for(j=0;j<n;j++)
		{
			// brackets must for & because of precedence order.
			if( (i & (1<<j)) != 0 )  // here non zero means pow(2,j)
			{
				printf("%d ",a[j]);
			}
		}
		printf("\n");
	}
}
int main()
{
	int n;
	printf("Enter No. of Elements : ");
	scanf(" %d", &n);
	int a[n];
	int i = 0;
	for (i = 0; i < n; i++)
	{
		scanf(" %d", &a[i]);
	}
	printf("\nPower Set  :  \n\n");
	print_all_subsets(a, n);
	printf("\n");
	return 0;
}

/*

Time Complexity: O(N * 2^N)
Auxiliary Space: O(1) 

*/

/*

OUTPUT :

Enter No. of Elements : 4
1 2 3 4

Power Set  :  

1 
2 
1 2 
3 
1 3 
2 3 
1 2 3 
4 
1 4 
2 4 
1 2 4 
3 4 
1 3 4 
2 3 4 
1 2 3 4 

*/