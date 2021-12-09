/*

ID : B171452
Code By Sandeep Payili on 29/10/2021

Problem Description : Prim's Algorithm ( Minimum Spanning Tree Algorithm)

*/
#include<stdio.h>
#include<limits.h> // for INT_MAX
int main()
{
	int n;
	printf("Enter no. of vertices  :  ");
	scanf(" %d", &n);
	if (n <= 0)
	{
		return 0;
	}
	int graph[n][n];
	int i = 0, j = 0;

	int visited[n];
	for (i = 0; i < n; i++)
	{
		visited[i] = 0;
	}

	printf("\nEnter  Graph (In Adjacency Matrix Representation)  :  \n");
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < n; j++)
		{
			scanf(" %d"	, &graph[i][j]); // enter 0 for no edge and i == j
		}
	}

	int x;
	int y;
	int no_of_edges = 0;
	visited[0] = 1;  // starting form 0th vertex
	int edge_cost = INT_MAX;
	int cost_of_minimum_spanning_tree = 0;
	printf("\n  Edge      |     Weight\n\n");
	while (no_of_edges <  n - 1) // loop until n-1 edges
	{
		// find next min cost edge having one vertex visited and other not visited
		edge_cost = INT_MAX;
		x = 0; // will definetly update no need to reinitialize
		y = 0; // will definetly update no need to reinitialize
		for (i = 0; i < n; i++)
		{
			if (visited[i])
			{
				// for ith vertex find minimum edge to unvisited vertex
				for (j = 0; j < n; j++)
				{
					if (  visited[j] == 0  && graph[i][j] != 0 &&  graph[i][j] <= edge_cost )
					{
						edge_cost = graph[i][j];
						x = i;
						y = j;
					}
				}
			}
			// printf("%d >> %d - %d   |      %d\n",i,x,y,edge_cost);
		}
		cost_of_minimum_spanning_tree += edge_cost;
		visited[y] = 1; // for i to y we have edge i.e., y is visited
		// printf("   %d - %d    |      %d   \n", x, y, edge_cost);
		printf("   %d - %d    |      %d   \n", x, y, graph[x][y]);
		no_of_edges++;
	}
	printf("\nCost of Minimum Spanning Tree  :  %d\n\n", cost_of_minimum_spanning_tree);
	return 0;
}

/*

OUTPUT:

Enter no. of vertices  :  7

Enter  Graph (In Adjacency Matrix Representation)  :  
0 1 5 0 0 0 0
1 0 4 8 7 0 0
5 4 0 6 0 2 0
0 8 6 0 11 9 0
0 7 0 11 0 3 10
0 0 2 9 3 0 12
0 0 0 0 10 12 0

  Edge      |     Weight

   0 - 1    |      1   
   1 - 2    |      4   
   2 - 5    |      2   
   5 - 4    |      3   
   2 - 3    |      6   
   4 - 6    |      10   

Cost of Minimum Spanning Tree  :  26

*/

/*


Enter no. of vertices  :  7

Enter  Graph (In Adjacency Matrix Representation)  :  
0 2 0 4 0 5 0
2 0 7 1 3 8 4
0 7 0 0 10 0 6
4 1 0 0 2 0 0
0 3 10 2 0 0 0
5 8 0 0 0 0 1
0 4 6 0 0 1 0

  Edge      |     Weight

   0 - 1    |      2   
   1 - 3    |      1   
   3 - 4    |      2   
   1 - 6    |      4   
   6 - 5    |      1   
   6 - 2    |      6   

Cost of Minimum Spanning Tree  :  16

*/