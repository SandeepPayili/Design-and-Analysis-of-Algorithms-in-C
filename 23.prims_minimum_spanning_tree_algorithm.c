/*

ID : B171452
Code By Sandeep Payili on 29/10/2021

Problem Description : Prim's Algorithm ( Minimum Spanning Tree Algorithm)

( Prim's algorithm is a minimum spanning tree algorithm that takes a graph as input and
finds the subset of the edges of that graph which form a tree that includes every vertex
has the minimum sum of weights among all the trees that can be formed from the graph )

( It falls under a class of algorithms called greedy algorithms
that find the local optimum in the hopes of finding a global optimum. )

*/
#include<stdio.h>
#include<limits.h> // for INT_MAX
int main()
{
	int n;//number of vertices
	printf("Enter no. of vertices  :  ");
	scanf(" %d", &n);
	if (n <= 0) // there should be atleast one vertex
	{
		return 0;
	}
	// create a 2d array of size nxn for adjacency matrix to represent graph
	int graph[n][n];
	// to store it's parent (to store ith index edge starting vertex )  i.e., there is an edge between i and parent[i]
	int parent[n];  // for ith index edge  from which vertex is stored in parent[i]
	// to store cost of edges (parent array edges )
	int cost[n];	// leaving one cost value of starting vertex remaining indicates costs of n-1 edges

	// to mark visited vertices
	int visited[n];

	int i = 0, j = 0;
	printf("\nEnter  Graph (In Adjacency Matrix Representation)  :  \n");
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < n; j++)
		{
			scanf(" %d", &graph[i][j]); // enter 0 for no edge and i == j 
		}
	}

	// initial setup for parent,cost,visited arrays.
	for (i = 0; i < n; i++)
	{
		parent[i] = -1; // -1 for not having starting vetex in that edge
		cost[i] = INT_MAX; // cost : INT_MAX as infinity for vertices not having edge.
		visited[i] = 0; // 0 for not visited,1 for visited
	}

	cost[0] = 0; // to start with 0th vertex we make cost lowest among all of them
	parent[0] = -1; // starting vertex has no parent to form edge


	// Main Logic
	int current_min_cost_vertex_index = 0; // variable to store index of current minium cost among unvisited vertices
	for (i = 0; i < n; i++) // to visit all vertices
	{
		int current_min_value = INT_MAX; // to find minimum cost among unvisited vertices
		for (j = 0; j < n; j++) // to find current minimum vertex which is not visited already
		{
			if (visited[j] == 0 &&  cost[j] <= current_min_value)
			{
				current_min_value = cost[j];
				current_min_cost_vertex_index = j; // it will definetly update since if condition will satisfy atleast once
			}
		}

		// mark as visited after finding current less cost vertex
		visited[current_min_cost_vertex_index] = 1;

		for (j = 0; j < n; j++) // update cost and parent  for connections of current minimum cost vertex
		{
			if (graph[current_min_cost_vertex_index][j] != 0 && graph[current_min_cost_vertex_index][j] <= cost[j] && visited[j] == 0 )
			{
				cost[j] = graph[current_min_cost_vertex_index][j];
				parent[j] = current_min_cost_vertex_index;
			}
		}
	}

	// printing  edges and their weights
	int cost_of_minimum_spanning_tree = 0;
	printf("\nPrim's Minimum Spanning Tree :  \n");
	for (i = 1; i < n; i++) // i==0 has no parent and no cost to travel
	{
		printf(" Edge :  %d   -  %d   Weight :  %d \n", parent[i], i, cost[i]);
		cost_of_minimum_spanning_tree += cost[i] ; // cost[0] = 0
	}
	printf("\nCost of Minimum Spanning Tree  :  %d\n\n",cost_of_minimum_spanning_tree);
	return 0;
}
// If we run prims algorithm on non connected graph it will only find minimum Spanning Tree for one Component only

/*
Prim's Algorithm Complexity :-

The time complexity of Prim's algorithm is O(E log V).

*/

/*	
	Time Complexity:
		(n-1) * (e)
		n*e = n^2
		O(n^2)
	It can be reduced to  
		(n-1) * log(e)
		O(E log V)   or O(n log n) by using heap or black tree
*/

/*

Prim's Algorithm Application

    1) Laying cables of electrical wiring
    2) In network designed
    3) To make protocols in network cycles

*/

/*

Prim’s Algorithm Time Complexity-

	Worst case time complexity of Prim’s Algorithm is-

    	O(ElogV) using binary heap
    	O(E + VlogV) using Fibonacci heap

*/


/*

OUTPUT:-


Enter no. of vertices  :  7

Enter  Graph (In Adjacency Matrix Representation)  :  
0 1 5 0 0 0 0
1 0 4 8 7 0 0 
5 4 0 6 0 2 0
0 8 6 0 11 9 0
0 7 0 11 0 3 10
0 0 2 9 3 0 12
0 0 0 0 10 12 0

Prim's Minimum Spanning Tree :  
 Edge :  0   -  1   Weight :  1 
 Edge :  1   -  2   Weight :  4 
 Edge :  2   -  3   Weight :  6 
 Edge :  5   -  4   Weight :  3 
 Edge :  2   -  5   Weight :  2 
 Edge :  4   -  6   Weight :  10 

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

Prim's Minimum Spanning Tree :  
 Edge :  0   -  1   Weight :  2 
 Edge :  6   -  2   Weight :  6 
 Edge :  1   -  3   Weight :  1 
 Edge :  3   -  4   Weight :  2 
 Edge :  6   -  5   Weight :  1 
 Edge :  1   -  6   Weight :  4 

Cost of Minimum Spanning Tree  :  16


*/