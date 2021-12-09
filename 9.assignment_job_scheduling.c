/*

ID : B171452
Code By Sandeep Payili on 19/10/2021

Problem Description : Assignment Problem (also called as Job Scheduling Algorithm)
	there are n people who need to be assigned to execute n jobs, one person per job.
	(That is, each person is assigned to exactly one job and each job is assigned to exactly one person.)
	 The cost that would accrue if the ith person is assigned to the j th job is a known quantity C[i, j ]
	 for each pair i, j = 1, 2, . . . , n. The problem is to find an assignment with the minimum total cost.

*/

//we can think of time also find less time to complete whole task

#include<stdio.h>
#include<stdlib.h>
#include <limits.h> // for INT_MAX and INT_MIN
void make_assignment(int **assignment, int *jobs_array, int start_index, int end_index, int *optimal_cost,int *res_jobs_array)
{
	if (start_index == end_index)
	{
		int current_cost=0;
		int i = 0;
		for (i = 0; i <= end_index; i++)
		{
			current_cost +=  assignment[i][jobs_array[i]];
		}
		if (current_cost <= *optimal_cost)
		{
			*optimal_cost = current_cost;
			// to update for which person which job is optimal 
			for(i=0;i<=end_index;i++)
			{
				res_jobs_array[i] = jobs_array[i];
			}
		}
	}
	int i = start_index;
	for (i = start_index; i <= end_index; i++)
	{
		int temp = jobs_array[i];
		jobs_array[i] = jobs_array[start_index];
		jobs_array[start_index] = temp;
		make_assignment(assignment, jobs_array, start_index + 1, end_index, optimal_cost,res_jobs_array);
		temp = jobs_array[i];
		jobs_array[i] = jobs_array[start_index];
		jobs_array[start_index] = temp;
	}
}
int main()
{
	int **assignment;
	int n, i, j;
	printf("Enter no. Of Persons | Jobs  :  ");
	scanf(" %d", &n);
	assignment = (int **)malloc(sizeof(int *));
	for (i = 0; i < n; i++)
	{
		assignment[i] = (int *)malloc(sizeof(int ));
	}
	printf("\nEnter People respective Job Cost \n\n");
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < n; j++)
		{
			printf("Enter Person %d Job %d  Cost :  ", i, j);
			scanf(" %d", &assignment[i][j]);
		}
	}
	int jobs_array[n];// assume index as person and value as job
	int res_jobs_array[n];// to print which person which job is optimal 
	// assume index as person and value as job
	for (i = 0; i < n; i++)
	{
		jobs_array[i] = i;
	}
	int optimal_cost = INT_MAX;
	int start_index = 0;
	int end_index = n - 1;
	make_assignment(assignment, jobs_array, start_index, end_index, &optimal_cost,res_jobs_array);
	printf("\n\n\t Assignment of Jobs to Persons for Optimal Cost  :  \n\n");
	for(i=0;i<n;i++)
	{
		printf("Assign Person %d to Job %d \n",i,res_jobs_array[i]);
	}
	printf("\n\nOptimal Cost :  %d\n\n",optimal_cost);
	return 0;
}

/*
OUTPUT :

Enter no. Of Persons | Jobs  :  4

Enter People respective Job Cost 

Enter Person 0 Job 0  Cost :  9
Enter Person 0 Job 1  Cost :  2
Enter Person 0 Job 2  Cost :  7
Enter Person 0 Job 3  Cost :  8
Enter Person 1 Job 0  Cost :  6
Enter Person 1 Job 1  Cost :  4
Enter Person 1 Job 2  Cost :  3
Enter Person 1 Job 3  Cost :  7
Enter Person 2 Job 0  Cost :  5
Enter Person 2 Job 1  Cost :  8
Enter Person 2 Job 2  Cost :  1
Enter Person 2 Job 3  Cost :  8
Enter Person 3 Job 0  Cost :  7
Enter Person 3 Job 1  Cost :  6
Enter Person 3 Job 2  Cost :  9
Enter Person 3 Job 3  Cost :  4


	 Assignment of Jobs to Persons for Optimal Cost  :  

Assign Person 0 to Job 1 
Assign Person 1 to Job 0 
Assign Person 2 to Job 2 
Assign Person 3 to Job 3 


Optimal Cost :  13

*/

/*

OUTPUT 2:


Enter no. Of Persons | Jobs  :  4

Enter People respective Job Cost 

Enter Person 0 Job 0  Cost :  82
Enter Person 0 Job 1  Cost :  83
Enter Person 0 Job 2  Cost :  69
Enter Person 0 Job 3  Cost :  92
Enter Person 1 Job 0  Cost :  77
Enter Person 1 Job 1  Cost :  37
Enter Person 1 Job 2  Cost :  49
Enter Person 1 Job 3  Cost :  92
Enter Person 2 Job 0  Cost :  11
Enter Person 2 Job 1  Cost :  69
Enter Person 2 Job 2  Cost :  5
Enter Person 2 Job 3  Cost :  86
Enter Person 3 Job 0  Cost :  8
Enter Person 3 Job 1  Cost :  9
Enter Person 3 Job 2  Cost :  98
Enter Person 3 Job 3  Cost :  23


	 Assignment of Jobs to Persons for Optimal Cost  :  

Assign Person 0 to Job 2 
Assign Person 1 to Job 1 
Assign Person 2 to Job 0 
Assign Person 3 to Job 3 


Optimal Cost :  140


*/