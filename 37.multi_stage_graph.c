// source to sink
#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
int main()
{
	int stages;
	printf("Enter number of Stages  :  ");
	scanf(" %d",&stages);
	int n;
	int i=0,j=0,k=0;
	printf("Enter number of Vertices  : ");
	scanf( " %d",&n);
	int **multi_stage_graph;
	multi_stage_graph = (int **)malloc(n*sizeof(int *));
	for(i=0;i<n;i++)
	{
		*(multi_stage_graph + i) = (int *)malloc(n*sizeof(int));
	}
	printf("\nEnter Multi Stage Graph : \n");
	for(i=0;i<n;i++)
	{
		for(j=i+1;j<n;j++)
		{
			// assumption : edges will be between adjacent stages only  
			// for any i vertex it's next stage vertex will be from only i+1 th to n-1
			scanf(" %d",&multi_stage_graph[i][j]);
		}
	}
	int min = INT_MAX;
	// cost array
	int c[n];
	// destination array
	int d[n];
	c[n-1] = 0; // sink cost is zero
	d[n-1] = n-1; // destination is itself
	for(i=n-2;i>=0;i--)
	{
		c[i] = INT_MAX;
		min = INT_MAX;
		for(j=i+1;j<n;j++)
		{
			if(multi_stage_graph[i][j] != 0 && (multi_stage_graph[i][j] + c[j]) < min )
			{
  						min = multi_stage_graph[i][j] + c[j] ;
  						d[i] = j;
			}
		}
		c[i] = min;
	}
	/*
	for(i=0;i<n;i++)
	{
		printf(" %4d ",c[i]);
	}
	printf("\n");
	for(i=0;i<n;i++)
	{
		printf(" %4d ",d[i]);
	}
	*/
	// path array
	int p[stages];
	p[0] = 0;
	for(i=1;i<stages;i++)
	{
		p[i] = d[p[i-1]];
	}
	printf("\nMinimum Cost  :  %d\n",c[0]);
	printf("\nPath :  ");
	for(i=0;i<stages;i++)
	{
		printf(" %d ",p[i]);
	}
	printf("\n");
	return 0;
}

// O(n^2)