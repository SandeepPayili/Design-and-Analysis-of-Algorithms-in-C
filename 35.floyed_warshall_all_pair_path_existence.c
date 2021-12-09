#include<stdio.h>
#include<stdlib.h>
void floyed_warshall(int n, int **path)
{
	int k = 0, i = 0, j = 0;
	for (k = 0; k < n; k++)
	{
		for (i = 0; i < n; i++)
		{
			for (j = 0; j < n; j++)
			{
				path[i][j] = ( path[i][j]	|| path[i][k] && path[k][j]);
			}
		}
	}
}
int main()
{
	int n;
	int i = 0, j = 0;
	printf("Enter number of Vertices : ");
	scanf(" %d", &n);
	int **path;
	path =  (int **)malloc(n * sizeof(int *));
	for (i = 0; i < n; i++)
	{
		*(path + i) = (int *)malloc(n * sizeof(int));
	}
	printf("Enter Directed Graph : \n");
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < n; j++)
		{
			// directed Graph
			scanf(" %d", &path[i][j]); // 0 or 1 for path
		}
	}

	floyed_warshall(n, path);

	for (i = 0; i < n; i++)
	{
		for (j = 0; j < n; j++)
		{
			printf("%5d", path[i][j]);
		}
		printf("\n");
	}
	return 0;
}

// O(n^3)