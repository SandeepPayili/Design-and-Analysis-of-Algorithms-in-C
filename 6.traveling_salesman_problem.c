/*

ID : B171452
Code By Sandeep Payili on 19/10/2021

Problem Description : Traveling Salesman Problem
(problem of finding the shortest Hamiltonian circuit of the graph)
 (with assumption that graph is complete)
*/

/*

as first city is fixed we will permutate n-1 cities in (n-1)! ways and half of hamiltonian circuits are same.
so no. of unique hamiltonian circuits are : (n-1)!/2

*/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include <limits.h> // for INT_MAX and INT_MIN
void permute(int  **city_weights, char *cities, int left_index, int right_index, int *distance, int n, char * result_array)
{
	if (left_index == right_index)
	{
		int current_distance = 0, city1 = 0, city2 = 0;
		for (int i = 1; i < n; i++)
		{
			city1 = cities[i - 1] - 65 ;// subtracing 65 to convert alphabet to number to use it as index
			city2 = cities[i] - 65 ;
			current_distance += city_weights[city1][city2];

		}
		city1 = cities[n - 1] - 65 ;
		city2 = cities[0] - 65 ;
		current_distance += city_weights[city1][city2];
		if (current_distance <= *distance )
		{
			*distance = current_distance;
			for (int i = 0; i < n; i++)
			{
				result_array[i] = cities[i];
			}
			result_array[n] = cities[0];
			result_array[n + 1] = '\0';
		}
		// printf("\nCities : %s \n",cities);
	}
	for (int i = left_index; i <= right_index; i++)
	{
		int temp = cities[left_index];
		cities[left_index] = cities[i];
		cities[i] = temp;
		permute(city_weights, cities, left_index + 1, right_index, distance, n, result_array);
		temp = cities[left_index];
		cities[left_index] = cities[i];
		cities[i] = temp;
	}
}
int main()
{
	char n;
	printf("\nEnter No. of cities to travel by Sellsmen  : ");
	scanf(" %d", &n);
	int **city_weights = (int **)malloc(n * sizeof(int *));
	for (int i = 0; i < n; i++)
	{
		*(city_weights + i) = (int *)malloc(n * sizeof(int ));
	}
	printf("\nEnter the City Weights : \n\n");
	int i = 0, j = 0;
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < n; j++)
		{
			if (i == j)
			{
				city_weights[i][j] = 0; // same city weight is 0.
			} else
			{
				printf("Enter City Weight of %c to %c : ", i + 65, j + 65);
				scanf(" %d", &city_weights[i][j]);
			}
		}
	}
	printf("\n\n Given City Weights : \n\n");
	for (i = -1; i < n; i++)
	{
		// ( i != -1 ) ?   printf("\x1b[7;36m    %c  \x1b[0m", i + 65) : printf("    "); ;
		( i != -1 ) ?   printf("    %c  ", i + 65) : printf("    ");
	}
	char cities[n];
	for (i = 0; i < n; i++)
	{
		cities[i] = i + 65;
	}
	printf("\n");
	for (i = 0; i < n; i++)
	{
		// printf("\x1b[7;36m %c  \x1b[0m", i + 65);
		printf(" %c  ", i + 65);
		for (j = 0; j < n; j++)
		{
			printf(" %4d  ", city_weights[i][j]);
		}
		printf("\n");
	}
	char result_array[n + 2]; // +1 to store extra city to complete cycle,+1 to end string
	// also works for values lesser than n
	int left_index = 0, right_index = n - 1 ;
	int distance = INT_MAX;
	permute(city_weights, cities, left_index + 1, right_index, &distance, n, result_array); // to start with first city
	printf("\n\n The Minimum Distance person need to travel is : %d \n", distance);
	printf("\n The Path Person Should Choose Path   : %s\n", result_array);
	// permute(city_weights, cities, left_index, right_index, &distance, n, result_array); // to start with min cost city
	// printf("\n\n The Minimum Distance person need to travel is : %d \n", distance);
	// printf("\n The Path Person Should Choose Path   : %s\n", result_array);
	return 0;
}

/*

Time Complexity : 

O( (n-1)! )

approximately == O(n!) 

*/

/*
OUTPUT :


Enter No. of cities to travel by Sellsmen  : 3

Enter the City Weights : 

Enter City Weight of A to B : 10
Enter City Weight of A to C : 1
Enter City Weight of B to A : 20
Enter City Weight of B to C : 200
Enter City Weight of C to A : 100
Enter City Weight of C to B : 2


 Given City Weights : 

        A      B      C  
 A      0     10      1  
 B     20      0    200  
 C    100      2      0  


 The Minimum Distance person need to travel is : 23 

 The Path Person Should Choose Path   : ACBA

*/

/*
OUTPUT 2: 

Enter No. of cities to travel by Sellsmen  : 5

Enter the City Weights : 

Enter City Weight of A to B : 2
Enter City Weight of A to C : 5
Enter City Weight of A to D : 7
Enter City Weight of A to E : 1
Enter City Weight of B to A : 6
Enter City Weight of B to C : 3
Enter City Weight of B to D : 8
Enter City Weight of B to E : 2
Enter City Weight of C to A : 8
Enter City Weight of C to B : 7
Enter City Weight of C to D : 4
Enter City Weight of C to E : 7
Enter City Weight of D to A : 12
Enter City Weight of D to B : 4
Enter City Weight of D to C : 6
Enter City Weight of D to E : 5
Enter City Weight of E to A : 1
Enter City Weight of E to B : 3
Enter City Weight of E to C : 2
Enter City Weight of E to D : 8


 Given City Weights : 

        A      B      C      D      E  
 A      0      2      5      7      1  
 B      6      0      3      8      2  
 C      8      7      0      4      7  
 D     12      4      6      0      5  
 E      1      3      2      8      0  


 The Minimum Distance person need to travel is : 15 

 The Path Person Should Choose Path   : ABCDEA

*/