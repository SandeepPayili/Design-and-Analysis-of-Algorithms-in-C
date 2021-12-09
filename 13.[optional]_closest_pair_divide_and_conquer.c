/*

ID : B171452
Code By Sandeep Payili on 24/10/2021

Problem Description : Closest Pair of Points using Divide and Conquer algorithm

T(n) = T(n x Logn x Logn) Approach

*/
#include<stdio.h>
#include<stdlib.h>
#include<limits.h> // for INT_MAX and INT_MIN 
#include<math.h> // also we need to compile by including   -lm 
#include<float.h> // for DBL_MAX
struct point {
	double x;
	double y;
};

double min(double a, double b)
{
	return ( a < b) ? a : b;
}
void quick_sort_x_coordinate(struct point *points, int start_index, int end_index)
{
	if (start_index >= end_index)
	{
		return;
	}
	double pivot  = points[start_index].x;
	int i = start_index;
	int j = end_index;
	struct point temp;
	while (i < j)
	{
		while (pivot >=  points[i].x && i < end_index)
		{
			i++;
		}
		while ( pivot < points[j].x && j > start_index)
		{
			j--;
		}
		if (i < j)
		{
			temp = points[j];
			points[j] = points[i];
			points[i] = temp;
		}
	}
	temp = points[j];
	points[j] = points[start_index];
	points[start_index] = temp;
	quick_sort_x_coordinate(points, start_index, j - 1);
	quick_sort_x_coordinate(points, j + 1, end_index);
}
void quick_sort_y_coordinate(struct point *strip, int start_index, int end_index)
{
	if (start_index >= end_index)
	{
		return;
	}
	double pivot  = strip[start_index].y;
	int i = start_index;
	int j = end_index;
	struct point temp;
	while (i < j)
	{
		while (pivot >=  strip[i].y && i < end_index)
		{
			i++;
		}
		while ( pivot < strip[j].y && j > start_index)
		{
			j--;
		}
		if (i < j)
		{
			temp = strip[j];
			strip[j] = strip[i];
			strip[i] = temp;
		}
	}
	temp = strip[j];
	strip[j] = strip[start_index];
	strip[start_index] = temp;
	quick_sort_y_coordinate(strip, start_index, j - 1);
	quick_sort_y_coordinate(strip, j + 1, end_index);
}
double euclidian_distance(struct point a, struct point b)
{
	double distance =  pow( pow(a.x - b.x, 2) +  pow((a.y - b.y), 2) , 0.5 );
	return distance;
}
void brute_force_closest_pair(struct point *points, int start_index, int end_index, struct point *closest_point_1, struct point *closest_point_2, double *minimum_distance)
{
	int i = start_index, j = 0;
	for (i = start_index; i <= end_index; i++)
	{
		for (j = i + 1; j <= end_index; ++j)
		{
			double distance =  pow( pow(points[i].x - points[j].x, 2) +  pow((points[i].y - points[j].y), 2) , 0.5 );
			if (distance < *minimum_distance)
			{
				*minimum_distance = distance;
				closest_point_1->x = points[i].x;
				closest_point_1->y = points[i].y;
				closest_point_2->x = points[j].x;
				closest_point_2->y = points[j].y;
			}
		}
	}
}

/*
void strip_minimum(struct point *strip, int end_index, double d, struct point *closest_point_1, struct point *closest_point_2,double *minimum_distance)
{
	double strip_minimum_distance = d;
	quick_sort_y_coordinate(strip, 0, end_index); //O( n log n )
	for (int i = 0; i < end_index; i++)
	{
			if ( abs(strip[i].y - strip[i+1].y) < strip_minimum_distance)// // since sorted Y coordinate
			{
				if (   euclidian_distance(strip[i], strip[i+1])  < strip_minimum_distance)
				{
					strip_minimum_distance = euclidian_distance(strip[i], strip[i+1]);
					*minimum_distance = strip_minimum_distance;
					closest_point_1->x = strip[i].x;
					closest_point_1->y = strip[i].y;
					closest_point_2->x = strip[i+1].x;
					closest_point_2->y = strip[i+1].y;
				}
			}
	}
}
*/

void strip_minimum(struct point *strip, int end_index, double d, struct point *closest_point_1, struct point *closest_point_2, double *minimum_distance)
{
	double strip_minimum_distance = d;
	quick_sort_y_coordinate(strip, 0, end_index); //O( n log n )
	for (int i = 0; i <= end_index; i++)
	{
		for (int j = i + 1; j <= end_index && (abs(strip[i].y - strip[j].y) < strip_minimum_distance); j++)
		{
				if (   euclidian_distance(strip[i], strip[j])  < strip_minimum_distance)
				{
					strip_minimum_distance = euclidian_distance(strip[i], strip[j]);
					*minimum_distance = strip_minimum_distance;
					closest_point_1->x = strip[i].x;
					closest_point_1->y = strip[i].y;
					closest_point_2->x = strip[j].x;
					closest_point_2->y = strip[j].y;
				}
		}
	}
}
void closest_pair_divide_and_conquer(struct point *points, int start_index, int end_index, struct point *closest_point_1, struct point *closest_point_2,  int no_of_points, double *minimum_distance)
{
	if (end_index - start_index <= 3 )//base case of 4 four points
	{
		brute_force_closest_pair(points, start_index, end_index, closest_point_1, closest_point_2, minimum_distance);
		return;
	}
	int middle_point_index = (start_index + end_index) / 2;
	closest_pair_divide_and_conquer(points, start_index, middle_point_index,  closest_point_1, closest_point_2, no_of_points, minimum_distance);

	double dl  =  *minimum_distance;
	closest_pair_divide_and_conquer(points, middle_point_index + 1, end_index,  closest_point_1, closest_point_2, no_of_points, minimum_distance);
	double dr =  *minimum_distance;
	double d = min(dl, dr);
	struct point strip[no_of_points];
	int strip_array_size = 0;
	for (int i = 0; i < no_of_points; i++)
	{
		if ( abs(points[i].x - points[middle_point_index].x )  < d )// middle point in strip is trivial
		{
			strip[strip_array_size] = points[i];
			strip_array_size++;
		}
	}
	strip_minimum(strip, strip_array_size - 1, d,  closest_point_1, closest_point_2, minimum_distance);
}
int main()
{
	int no_of_points, i = 0, j = 0;
	printf("\nEnter number of points you want to enter : ");
	scanf(" %d", &no_of_points);
	struct point points[no_of_points];
	for (i = 0; i < no_of_points; i++)
	{
		printf("\nEnter %d point x coordinate : ", i + 1);
		scanf(" %lf", &points[i].x);
		printf("\nEnter %d point y coordinate : ", i + 1);
		scanf(" %lf", &points[i].y);
	}

	// to remember minimum distance
	double *minimum_distance ;
	minimum_distance = (double *)malloc(sizeof(double));
	*minimum_distance = DBL_MAX;

	// to remember two closest points
	struct point  *closest_point_1;
	struct point  *closest_point_2;
	closest_point_1 = (struct point *)malloc(sizeof(struct point));
	closest_point_2 = (struct point *)malloc(sizeof(struct point));

	// sorting points based on x coordinates.
	quick_sort_x_coordinate(points, 0, no_of_points - 1); //O( n log n )


	printf("\nGiven Points are  : \n");
	for (i = 0; i < no_of_points; ++i)
	{
		printf("\n %d point : ( %lf , %lf )  \n", i + 1, points[i].x, points[i].y);
	}

	int start_index = 0;
	int end_index = no_of_points - 1;
	closest_pair_divide_and_conquer(points, start_index, end_index, closest_point_1, closest_point_2, no_of_points, minimum_distance);

	printf("\n\nMinimum Distance  :   %lf\n", *minimum_distance);
	printf("\nThe Closest Points are  :  ");
	printf("  (%lf,%lf) and (%lf,%lf) \n", closest_point_1->x, closest_point_1->y, closest_point_2->x, closest_point_2->y);
	return 0;
}
/*

OUTPUT : 


Enter number of points you want to enter : 10

Enter 1 point x coordinate : -100

Enter 1 point y coordinate : 13

Enter 2 point x coordinate : 12

Enter 2 point y coordinate : 15

Enter 3 point x coordinate : 15151

Enter 3 point y coordinate : 134

Enter 4 point x coordinate : 213

Enter 4 point y coordinate : 123

Enter 5 point x coordinate : 123

Enter 5 point y coordinate : 51

Enter 6 point x coordinate : 913

Enter 6 point y coordinate : 123

Enter 7 point x coordinate : 52

Enter 7 point y coordinate : 13

Enter 8 point x coordinate : 1315

Enter 8 point y coordinate : 123

Enter 9 point x coordinate : 156

Enter 9 point y coordinate : 74

Enter 10 point x coordinate : 23

Enter 10 point y coordinate : 52

Given Points are  : 

 1 point : ( -100.000000 , 13.000000 )  

 2 point : ( 12.000000 , 15.000000 )  

 3 point : ( 23.000000 , 52.000000 )  

 4 point : ( 52.000000 , 13.000000 )  

 5 point : ( 123.000000 , 51.000000 )  

 6 point : ( 156.000000 , 74.000000 )  

 7 point : ( 213.000000 , 123.000000 )  

 8 point : ( 913.000000 , 123.000000 )  

 9 point : ( 1315.000000 , 123.000000 )  

 10 point : ( 15151.000000 , 134.000000 )  


Minimum Distance  :   38.600518

The Closest Points are  :    (12.000000,15.000000) and (23.000000,52.000000) 

*/