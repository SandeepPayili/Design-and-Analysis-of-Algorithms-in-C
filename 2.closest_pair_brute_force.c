/*

ID : B171452
Code By Sandeep Payili on 18/10/2021

Problem Description : Closest Pair Algorithm (Brute Force)

*/
#include<stdio.h>
#include<stdlib.h>
#include <limits.h> // for INT_MAX and INT_MIN 
#include<math.h> // also we need to compile by including   -lm 
struct point
{
	int x;
	int y;
};
int main()
{
	int n, i = 0, j = 0;
	printf("\nEnter number of points you want to enter : ");
	scanf(" %d", &n);
	struct point points[n];
	for (i = 0; i < n; i++)
	{
		printf("\nEnter %d point x coordinate : ", i + 1);
		scanf(" %d", &points[i].x);
		printf("\nEnter %d point y coordinate : ", i + 1);
		scanf(" %d", &points[i].y);
	}
	int minimum_distance = INT_MAX;
	int distance = 0;
	int closest_point_index1 = 0;
	int closest_point_index2 = 0;
	for (i = 0; i < n; i++)
	{
		for (j = i + 1; j < n; ++j)
		{
			distance =  pow( pow(points[i].x - points[j].x, 2) +  pow((points[i].y - points[j].y), 2) , 0.5 );
			if (distance < minimum_distance)
			{
				minimum_distance = distance;
				closest_point_index1 = i;
				closest_point_index2 = j;
			}
		}
	}


	printf("\nGiven Points are  : ");
	for (i = 0; i < n; ++i)
	{
		printf("\n %d point : ( %d , %d )  \n", i + 1, points[i].x, points[i].y);
	}
	printf("\n\n ***********************     The Closest Points are  :  **********************\n");
	printf("  (%d,%d) and (%d,%d) \n", points[closest_point_index1].x, points[closest_point_index1].y, points[closest_point_index2].x, points[closest_point_index2].y);
	return 0;
}

/*

Time Complexity : 

O( n(n+1)/2 )

approximately == O(n^2) 

*/

/*

Values of INT_MAX and INT_MIN may vary
from compiler to compiler. Following are
typical values in a compiler where integers
are stored using 32 bits.

Value of INT_MAX is +2147483647.
Value of INT_MIN is -2147483648.

*/