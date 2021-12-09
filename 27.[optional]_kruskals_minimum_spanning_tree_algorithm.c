#include<limits.h>
#include<stdio.h>
int find(int u,int *s)
{
	while(s[u] > 0)
	{
		u = s[u];
	}
	return u;
}
void perform_union(int u,int v,int *s)
{
	if(s[u] < s[v])
	{
		s[u] += s[v];
		s[v] = u;
	}else
	{
		s[v] += s[u];
		s[u] = v;
	}
}
int main()
{
	int n;
	printf("Enter N : ");
	scanf(" %d",&n);
	int disjoint_set[n];
	int i=0,j=0;
	for(i=0;i<n;i++)
	{
		disjoint_set[i] = -1;
	}
	int graph[n][n];
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			scanf("%d",&graph[i][j]);
		}
	}
	printf("\n");
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			printf(" %d ",graph[i][j]);
		}
		printf("\n");
	}
	int no_of_edges = 0;
	int minimum_spanning_tree = 0;
	int edge_cost = INT_MAX;
	int x =0;
	int y=0;
	while(no_of_edges < n-1)
	{
		edge_cost = INT_MAX;
		x = 0;
		y = 0;
		for(i=0;i<n;i++)
		{
			for(j=0;j<n;j++)
			{	
				if(graph[i][j] !=0 && graph[i][j] <= edge_cost)
				{
					edge_cost = graph[i][j];
					x  = i;
					y  = j;
				}
			}	
		}
		//printf("\nedge cost : %d",edge_cost);
		if(  find(x,disjoint_set)  != find(y,disjoint_set)  )
		{
			printf(" %d   -   %d   = %d\n",x,y,graph[x][y]);
			perform_union(find(x,disjoint_set),find(y,disjoint_set),disjoint_set);
			minimum_spanning_tree += edge_cost;
			no_of_edges++;
			graph[x][y] = 0;
			graph[y][x] = 0;
		}else
		{
			//graph[x][y] = INT_MAX;
			graph[x][y] = 0;
			graph[y][x] = 0;
		}
	}
	printf("\nMinimum Spanning Tree Cost   :   %d\n",minimum_spanning_tree);
	return 0;
}


/*
n=7

0 28 0 0 0 10 0
28 0 16 0 0 0 14
0 16 0 12 0 0 0
0 0 12 0 22 0 18
0 0 0 22 0 25 24
10 0 0 0 25 0 0
0 14 0 18 24 0 0

0  -  5   =  10
5  -  4   =  25
4  -  3   =  22
3  -  2   =  12
2  -  1   =  16
1  -  6   =  14

Minimum Spanning Tree :  99


*/

/*
n=7

0 6 0 0 0 5 0
6 0 6 0 0 0 13
0 6 0 6 0 0 0
0 0 6 0 8 0 10 
0 0 0 8 0 2 6
5 0 0 0 2 0 0
0 13 0 10 6 0 0


Minimum Spanning Tree Cost   :   31

*/