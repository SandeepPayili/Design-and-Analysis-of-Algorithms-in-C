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
        if (i < j)// swapping i and j index value only if they are unsorted
        {
            temp = points[j];
            points[j] = points[i];
            points[i] = temp;
        }
    }
    // swapping pivot and j index value
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
    // pow() function syntax :  double pow(double x, double y);
    double distance =  pow( pow(a.x - b.x, 2) +  pow((a.y - b.y), 2) , 0.5 );
    return distance;
}
double brute_force_closest_pair(struct point *points, int start_index, int end_index, struct point *closest_point_1, struct point *closest_point_2)
{
    int i = start_index, j = 0;
    // DBL_MAX or approximately 1.8 × 10308 (if your double is an IEEE 754 64-bit double).
    double minimum_distance = DBL_MAX; // it will update definetly since no_of_points will be definetly >=2
    for (i = start_index; i <= end_index; i++)
    {
        for (j = i + 1; j <= end_index; ++j)
        {
            double distance =  pow( pow(points[i].x - points[j].x, 2) +  pow((points[i].y - points[j].y), 2) , 0.5 );
            // printf("\n  i = %d     j =  %d     Distance : %d \n", i, j, distance);
            if (distance < minimum_distance)
            {
                minimum_distance = distance;
                closest_point_1->x = points[i].x;
                closest_point_1->y = points[i].y;
                closest_point_2->x = points[j].x;
                closest_point_2->y = points[j].y;
            }
        }
    }
    // printf("\nBrute FOrce MInium Distance   : %d\n", minimum_distance);
    return minimum_distance;
}

/*

double strip_minimum(struct point *strip, int end_index, double d, struct point *closest_point_1, struct point *closest_point_2)
{
    double strip_minimum_distance = d;
    quick_sort_y_coordinate(strip, 0, end_index); //O( n log n )
    for (int i = 0; i < end_index; i++)
    {
            //since minimum distance form each half is calculated checking for points either sides of strip(vertical line)
            //one point from one side and other from other side
            // so we can only look for adjacent points
            if ( abs(strip[i].y - strip[i+1].y) < strip_minimum_distance )// // since sorted Y coordinate
            {
                if (   euclidian_distance(strip[i], strip[i+1])  < strip_minimum_distance)
                {
                    strip_minimum_distance = euclidian_distance(strip[i], strip[i+1]);
                    closest_point_1->x = strip[i].x;
                    closest_point_1->y = strip[i].y;
                    closest_point_2->x = strip[i+1].x;
                    closest_point_2->y = strip[i+1].y;
                }
            }
    }
    return strip_minimum_distance;
} 
*/

/*
double strip_minimum(struct point *strip, int end_index, double d, struct point *closest_point_1, struct point *closest_point_2)
{
    double strip_minimum_distance = d;
    // sorting points based on y coordinates.
    quick_sort_y_coordinate(strip, 0, end_index); //O( n log n )

    // O(n^2)  
    for (int i = 0; i <= end_index; i++)
    {
        for (int j = i + 1; j <= end_index; j++)
        {
            // if ( abs(strip[i].y - strip[j].y) < d )
            if ( abs(strip[i].y - strip[j].y) < strip_minimum_distance )
            {
                if (   euclidian_distance(strip[i], strip[j])  < strip_minimum_distance)
                {
                    strip_minimum_distance = euclidian_distance(strip[i], strip[j]);
                    closest_point_1->x = strip[i].x;
                    closest_point_1->y = strip[i].y;
                    closest_point_2->x = strip[j].x;
                    closest_point_2->y = strip[j].y;
                }
            }
        }
    }
    return strip_minimum_distance;
}
*/

//we compare the points which are within the strip of width 2d.
double strip_minimum(struct point *strip, int end_index, double d, struct point *closest_point_1, struct point *closest_point_2)
{
    double strip_minimum_distance = d;
    // sorting points based on y coordinates.
    // this is because to make inner for lop run for 7 times irresptive of no of points
    // i.e., for any point its  closest point will definetly lie in next 7 points only if that that pair has to be closest pair.
    quick_sort_y_coordinate(strip, 0, end_index); //O( n log n )

    // Pick all points one by one and try the next points 
    // till the difference between y's is smaller than d.
    // inner loop runs atmost 7 items  so O(7n) == O(n)
    for (int i = 0; i <= end_index; i++)
    {
        for (int j = i + 1; j <= end_index  && (abs(strip[i].y - strip[j].y) < strip_minimum_distance); j++)
        {
                if (   euclidian_distance(strip[i], strip[j])  < strip_minimum_distance)
                {
                    strip_minimum_distance = euclidian_distance(strip[i], strip[j]);
                    closest_point_1->x = strip[i].x;
                    closest_point_1->y = strip[i].y;
                    closest_point_2->x = strip[j].x;
                    closest_point_2->y = strip[j].y;
                }
        }
    }
    return strip_minimum_distance;
}
double closest_pair_divide_and_conquer(struct point *points, int start_index, int end_index, struct point *closest_point_1, struct point *closest_point_2,  int no_of_points)
{
    if (end_index - start_index <= 3 )//base case of 4 four points
    {
        double minimum_distance = brute_force_closest_pair(points, start_index, end_index, closest_point_1, closest_point_2);
        return  minimum_distance;
    }

    int middle_point_index = (start_index + end_index) / 2;

    double dl  = closest_pair_divide_and_conquer(points, start_index, middle_point_index,  closest_point_1, closest_point_2, no_of_points);
    // store left half closest points since dynamic vairables will change to other half closest points
    struct point left_closest_point1 = *closest_point_1;
    struct point left_closest_point2 = *closest_point_2 ;
    double left_minimum_distane = euclidian_distance(left_closest_point1, left_closest_point2);

    double dr = closest_pair_divide_and_conquer(points, middle_point_index + 1, end_index,  closest_point_1, closest_point_2, no_of_points);
    struct point right_closest_point1 = *closest_point_1;
    struct point right_closest_point2 = *closest_point_2 ;
    double right_minimum_distane = euclidian_distance(right_closest_point1, right_closest_point2);

    // upddate closest points considering both halves
    if ( left_minimum_distane < right_minimum_distane )
    {
        *closest_point_1 = left_closest_point1;
        *closest_point_2 = left_closest_point2;
    } else
    {
        *closest_point_1 = right_closest_point1;
        *closest_point_2 = right_closest_point2;
    }

    // minimum distance of both halves
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
    // in strip array points x coordinate distance of any pair of points will not exceed 2*d (strip width)

    // always strip array start index  will be 0
    double variable_strip_minium = strip_minimum(strip, strip_array_size - 1, d,  closest_point_1, closest_point_2);
    return min(d, variable_strip_minium); // min function need not be checked since strip_minimum is calclulated by considering d.
    // i.e., strip_minimum function will return atmost value d but not greater than d value.
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
    double minimum_distance = DBL_MAX;

    // to remember two closest points
    struct point  *closest_point_1;
    struct point  *closest_point_2;
    closest_point_1 = (struct point *)malloc(sizeof(struct point));
    closest_point_2 = (struct point *)malloc(sizeof(struct point));

    // sorting points based on x coordinates.
    // this is because to  divide problem into roughly equal halves
    quick_sort_x_coordinate(points, 0, no_of_points - 1); //O( n log n )


    printf("\nGiven Points are  : \n");
    for (i = 0; i < no_of_points; ++i)
    {
        printf("\n %d point : ( %lf , %lf )  \n", i + 1, points[i].x, points[i].y);
    }

    int start_index = 0;
    int end_index = no_of_points - 1;
    minimum_distance =  closest_pair_divide_and_conquer(points, start_index, end_index, closest_point_1, closest_point_2, no_of_points);

    printf("\n\nMinimum Distance  :   %lf\n", minimum_distance);
    printf("\nThe Closest Points are  : ");
    printf("  (%lf,%lf) and (%lf,%lf) \n\n", closest_point_1->x, closest_point_1->y, closest_point_2->x, closest_point_2->y);
    return 0;
}


/*

Time Complexity :

Let Time complexity of above algorithm be T(n).
Let us assume that we use a O(nLogn) sorting algorithm.
The above algorithm divides all points in two sets and recursively calls for two sets.
After dividing, it finds the strip in O(n) time, sorts the strip in O(nLogn) time and 
finally finds the closest points in strip in O(n) time. So T(n) can expressed as follows 

T(n) = 2T(n/2) + O(n) + O(nLogn) + O(n) 
T(n) = 2T(n/2) + O(nLogn) 
T(n) = T(n x Logn x Logn) // by Masters Theorem


*/

/*



If T(n) = time for solving closest pair problem and sorting points w.r.t Y coordinates
T(n) = 2T(n/2) +O(n) 
T(n) = O(n x Logn)

(since sorting Y coordinate takes only O(n) by merge sort )
(By taking two separate points arrays sorted with respect to x and y respectively.)

*/
