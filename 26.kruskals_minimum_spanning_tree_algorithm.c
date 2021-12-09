/*

ID : B171452
Code By Sandeep Payili on 31/10/2021

Problem Description : Kruskal's Algorithm ( Minimum Spanning Tree Algorithm)

*/
#include<stdio.h>
#include<limits.h> // for INT_MAX
void Union(int u, int v, int *s) //weighted union
{
	// we will assign less children subset to more children subset
	// lesser subtree becomes sub tree for more elements tree
	if (s[u] < s[v]) // heighest roots will become root(here root are in negative so,condition is opposite)
	{
		s[u] = s[u] + s[v];
		s[v] = u;
	} else
	{
		s[v] = s[v] + s[u];
		s[u] = v;
	}
}
int find(int u, int *s) // to return head of passed disjoint set
{
	int x = u;
	while (s[x] > 0)
	{
		x = s[x];//find(s[x])
	}
	return x;
}
int main()
{
	int n;
	int i = 0, j = 0;
	printf("Enter no. of vertices  :  ");
	scanf(" %d", &n);
	if (n <= 0)
	{
		return 0;
	}
	int graph[n][n];

	printf("\n\t>>>> Enter -1 for vertices not having edge <<<<\n");
	printf("\nEnter  Graph (In Adjacency Matrix Representation)  :  \n\n");
	for (i = 0; i < n; i++)
	{
		for (j = i; j < n; j++)
		{
			if (i == j)
			{
				graph[i][j] = 0;
				continue;
			}
			printf("Enter cost of %d to %d  :  ", i, j);
			scanf(" %d", &graph[i][j]);
			if (graph[i][j] == -1)// no edge
			{
				graph[i][j]  = INT_MAX;
			}
			graph[j][i] = graph[i][j];// aij = aji since undirected graph matrix is symmetric
		}
	}

	int disjoint_set[n];// for detecting cycle
	for (i = 0; i < n; i++)
	{
		// initially all are disjoint sets only
		disjoint_set[i] = -1;//inital all elements are roots itself indicated as -1
	}

	int no_of_edges = 0;
	int edge_cost = INT_MAX;
	int cost_of_minimum_spanning_tree = 0;
	int x;
	int y;
	printf("\n\n    Edge      |      Weight  \n\n");

	while ( no_of_edges < n - 1)
	{
		edge_cost = INT_MAX;
		x = 0;
		y = 0;
		// checks minium cost in upper traingular matrix since matrix is symetric for unidrected graph
		for (i = 0; i < n; i++)
		{
			for (j = i + 1; j < n; j++)
			{
				if (graph[i][j] < edge_cost) // <= also works
				{
					edge_cost = graph[i][j];
					x = i;
					y = j;
				}
			}
		}
		if (find(x, disjoint_set) != find(y, disjoint_set)) // if their parents are not equal i.e., not forming cycle
		{
			// printf("\n\n edge : %d \n", no_of_edges);
			// printf(" %d  - %d    |     %d   \n",x,y,graph[i][i]);
			printf("   %d  - %d     |        %d   \n", x, y, edge_cost);
			cost_of_minimum_spanning_tree += edge_cost;
			graph[x][y] = INT_MAX; // not to enter again
			// graph[y][x] = INT_MAX; // since we will not check this condition ignoring
			Union(find(x, disjoint_set), find(y, disjoint_set), disjoint_set);
			no_of_edges++;
		} else
		{
			// we will skip edge since it is forming cycle and make it infinity not ot get this edge again
			graph[x][y]  = INT_MAX;
			// graph[y][x] = INT_MAX; // since we will not check this condition ignoring
		}
	}
	printf("\nCost of Minimum Spanning Tree  :  %d\n\n", cost_of_minimum_spanning_tree);
	return 0;
}

/*

Kruskal's Algorithm Complexity

The time complexity Of Kruskal's Algorithm is: O(E log E).

*/

/*

Time Complexity: O(ElogE) or O(ElogV)

*/

/*

Kruskal's Algorithm Applications

    1) In order to layout electrical wiring
    2) In computer network (LAN connection)

*/

/*

OUTPUT:

Enter no. of vertices  :  7

	>>>> Enter -1 for vertices not having edge <<<<

Enter  Graph (In Adjacency Matrix Representation)  :  

Enter cost of 0 to 1  :  1
Enter cost of 0 to 2  :  5
Enter cost of 0 to 3  :  -1
Enter cost of 0 to 4  :  -1
Enter cost of 0 to 5  :  -1
Enter cost of 0 to 6  :  -1
Enter cost of 1 to 2  :  4
Enter cost of 1 to 3  :  8
Enter cost of 1 to 4  :  7
Enter cost of 1 to 5  :  -1
Enter cost of 1 to 6  :  -1
Enter cost of 2 to 3  :  6
Enter cost of 2 to 4  :  -1
Enter cost of 2 to 5  :  2
Enter cost of 2 to 6  :  -1
Enter cost of 3 to 4  :  11
Enter cost of 3 to 5  :  9
Enter cost of 3 to 6  :  -1
Enter cost of 4 to 5  :  3
Enter cost of 4 to 6  :  10
Enter cost of 5 to 6  :  12


    Edge      |      Weight  

   0  - 1     |        1   
   2  - 5     |        2   
   4  - 5     |        3   
   1  - 2     |        4   
   2  - 3     |        6   
   4  - 6     |        10   

Cost of Minimum Spanning Tree  :  26

*/

/*
OUTPUT:

Enter no. of vertices  :  7

	>>>> Enter -1 for vertices not having edge <<<<

Enter  Graph (In Adjacency Matrix Representation)  :  

Enter cost of 0 to 1  :  2
Enter cost of 0 to 2  :  -1
Enter cost of 0 to 3  :  4
Enter cost of 0 to 4  :  -1
Enter cost of 0 to 5  :  5
Enter cost of 0 to 6  :  -1
Enter cost of 1 to 2  :  7
Enter cost of 1 to 3  :  1
Enter cost of 1 to 4  :  3
Enter cost of 1 to 5  :  8
Enter cost of 1 to 6  :  4
Enter cost of 2 to 3  :  -1
Enter cost of 2 to 4  :  10
Enter cost of 2 to 5  :  -1
Enter cost of 2 to 6  :  6
Enter cost of 3 to 4  :  2
Enter cost of 3 to 5  :  -1
Enter cost of 3 to 6  :  -1
Enter cost of 4 to 5  :  -1
Enter cost of 4 to 6  :  -1
Enter cost of 5 to 6  :  1


    Edge      |      Weight  

   5  - 6     |        1   
   1  - 3     |        1   
   3  - 4     |        2   
   0  - 1     |        2   
   1  - 6     |        4   
   2  - 6     |        6   

Cost of Minimum Spanning Tree  :  16


*/