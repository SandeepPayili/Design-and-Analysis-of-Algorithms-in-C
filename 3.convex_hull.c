/*

ID : B171452
Code By Sandeep Payili on 18/10/2021

Problem Description : Convex Hull Algorithm
	( find polygon(points) which covers all the points inside in it )
	(The Convex Hull of the polygon is the minimal convex set wrapping our polygon.)

*/

/*
	equation of straight line with given two points  (x1,y1) , (x2,y2) :  ax +by = c
	where a = (y2 - y1)    b = (x1-x2)     c = (x1y2 - x2y1)

*/
 
#include<stdio.h>
#include<stdlib.h>
#include <limits.h> // for INT_MAX and INT_MIN 
#include<math.h> // also we need to compile by including   -lm 
struct point {
	int x;
	int y;
};
int main()
{
	int n, i = 0, j = 0, k = 0;
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
	int left_side_points_count = 0;
	int right_side_points_count = 0;
	int a = 0, b = 0, c = 0;
	int distance = 0;
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < n  ; j++)
		{

			left_side_points_count = 0;
			right_side_points_count = 0;

			a = (points[j].y - points[i].y);
			b = (points[i].x - points[j].x);
			c = ( (points[i].x * points[j].y) - (points[j].x * points[i].y));
			for (k = 0; k < n; k++)
			{
				if (k != i && k != j && i != j)
				{
					distance = ((a * points[k].x) + (b * points[k].y) - c);
					if (distance > 0)
					{
						right_side_points_count ++;
					}
					else
					{
						left_side_points_count++;
					}
				}
			}
			if (right_side_points_count == n - 2 || left_side_points_count == n - 2 )
			{
				printf("  (%d,%d) , ", points[i].x, points[i].y); // output points may not be in clock / anti clock wise...
				break;//to break j loop
			}
		}
	}

	return 0;
}

/*

Time Complexity :

O( n^3)

approximately == O(n^3)

*/

/*
To check for correctness :
https://planetcalc.com/8576
*/