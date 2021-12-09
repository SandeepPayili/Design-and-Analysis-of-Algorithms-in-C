/*

ID : B171452
Code By Sandeep Payili on 01/11/2021

Problem Description : Optimal Merge Pattern/Tree

(Merge a set of sorted files of different length into a single sorted file.
We need to find an optimal solution, where the resultant file will be generated in minimum time.)

*/
#include<stdio.h>
void heapify_percolate_up_recursive(int *a,int i)
{
	int parent_node;
	if(i>0) // 0 index has no parent node
	{
		parent_node = (i - 1)/2;  // to get parent node by formula
		if( a[i] < a[parent_node] )
		{
			int temp = a[i];
			a[i] = a[parent_node];
			a[parent_node] = temp;
		}
		heapify_percolate_up_recursive(a,parent_node);
	}
}
void heapify(int *a, int start_index, int end_index) // heapify start_index node
{
	int left_child_index = (2 * start_index) + 1;
	int right_child_index = (2 * start_index) + 2;
	int min_index = -1;
	if (right_child_index <= end_index)
	{
		if ( a[left_child_index]  < a[right_child_index])
		{
			min_index = left_child_index;
		}
		else
		{
			min_index = right_child_index;
		}
	}
	else if (left_child_index <= end_index)
	{
		min_index = left_child_index;
	}
	if ( min_index != -1 && a[min_index] < a[start_index])
	{
		int temp = a[start_index];
		a[start_index] = a[min_index];
		a[min_index] = temp;
		heapify(a, min_index, end_index);
	}
}
void build_heap(int *array_sizes, int n)
{
	int i = 0;
	for (i = (n/2) - 1; i >= 0; i--)// heapify each non-leaf node 
	{
		heapify(array_sizes, i, n - 1);
	}
}

int  min_heap_delete(int *a, int n)
{
	if ( n <= 0 )
	{
		return -1;
	}
	int start_index = 0;
	int end_index = n - 1;
	int to_return = a[start_index];
	a[start_index] = a[end_index];
	heapify(a, start_index, end_index); // heapfiy start_index node
	return to_return;
}
int optimal_merge_pattern(int *array_sizes, int n)
{
	int min_computations = 0;
	while (n > 2)
	{
		int x =  min_heap_delete(array_sizes, n-- ); //n-- one item is deleted
		int y =  min_heap_delete(array_sizes, n-- ); // min_heap_delete() function deletes and again heapify
		min_computations += (x+y); // adding computations to result i.e., Total Time is one file of size m and other n takes O(m+n)
		array_sizes[n++] = x + y ; // since n is no of elements
		// build_heap(array_sizes, n);// 
		heapify_percolate_up_recursive(array_sizes,n-1);
	}

	if (n == 1) //only one file(array)
	{
		min_computations += array_sizes[0];
		return min_computations;
	}
	if (n == 2) // only two files(array)
	{
		min_computations += (array_sizes[0] + array_sizes[1]);
		return min_computations;	
	}
}
int main()
{
	int n;
	printf("Enter Number of Array's(files) To Merge :  ");
	scanf(" %d", &n);
	int array_sizes[n];
	int i = 0;
	printf("Enter Array(files) Sizes :  ");
	for (i = 0; i < n; i++)
	{
		scanf(" %d", &array_sizes[i]);
	}

	build_heap(array_sizes, n);

	printf("\nAfter Converting Array To Min Heap  :  ");
	for (i = 0; i < n; i++)
	{
		printf(" %d ", array_sizes[i]);
	}
	printf("\n");

	int min_computations = optimal_merge_pattern(array_sizes, n);
	printf("\nMinimum Computations =  %d\n\n", min_computations);
	return 0;
}

/* 
	Time Complexity : O(nlogn)

			logn + logn   = 2logn // deleting two elements
			logn // adding result of added elements
			= 3logn
	this process continues until n-1 levels so,
			(n-1) * 3logn = O(nlogn)

			 n + nlogn  // O(n)  for build_Heap
			 = O(nlogn)

*/

/*

OUTPUT:

Enter Number of Array's(files) To Merge :  4
Enter Array(files) Sizes :  10 5 3 2

After Converting Array To Min Heap  :   2  5  3  10 

Minimum Computations =  35

*/

/*

OUTPUT:

Enter Number of Array's(files) To Merge :  6
Enter Array(files) Sizes :  10 8 5 6 4 3

After Converting Array To Min Heap  :   3  4  5  6  8  10 

Minimum Computations =  90

*/