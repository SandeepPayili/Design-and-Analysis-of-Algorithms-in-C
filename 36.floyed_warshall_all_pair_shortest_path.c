#include<stdio.h>
int main()
{
	int n;
	printf("\nEnter N : ");
	scanf(" %d",&n);
	printf("\nEnter Directed Graph : ");
	int i=0,j=0;
	int path[n][n];
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			scanf(" %d",&path[i][j]);
		}
	}
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			if(path[i][j] == -1)
			{
				path[i][j]  = 9999;
			}
		}
	}

	int distance[n][n];
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)	
		{
			distance[i][j] = path[i][j];
		}
	}
	int  k =0;
	for(k=0;k<n;k++)
	{
		for(i=0;i<n;i++)
		{
			for(j=0;j<n;j++)
			{
				if( ( distance[i][k] + distance[k][j] )  < distance[i][j]  )
				{
					distance[i][j] = distance[i][k] + distance[k][j];
				}
			}
		}
	}
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			printf(" %d ",distance[i][j]);
		}
		printf("\n");
	}
	return 0;
}

/*
int graph[nV][nV] = {{0, 3, INF, 5},
             {2, 0, INF, 4},
             {INF, 1, 0, INF},
             {INF, INF, 2, 0}};
            */