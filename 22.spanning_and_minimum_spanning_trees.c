/*

ID : B171452
Code By Sandeep Payili on 29/10/2021

Problem Description : Spanning and Minimum Spanning Trees

*/

/*

Spanning tree:-

	A spanning tree is a sub-graph of an undirected connected graph, 
	which includes all the vertices of the graph with a minimum possible number of edges. (without having any cycles)
	If a vertex is missed, then it is not a spanning tree.
	
	The edges may or may not have weights assigned to them.
	
	Cayley's formula :-
	The total number of spanning trees with n vertices that can be created from a complete graph is equal to n^(n-2).
	
	If we have n = 4, the maximum number of possible spanning trees is equal to 4^(4-2) = 16. 
	Thus, 16 spanning trees can be formed from a complete graph with 4 vertices.

	The number t(G) of spanning trees of a connected graph
	1) If G is itself a tree, then t(G) = 1.
	2) When G is the cycle graph Cn with n vertices, then t(G) = n.
	3) For a complete graph with n vertices, Cayley's formula gives the number of spanning trees as n^(n − 2).
	4) If G is the complete bipartite graph K p , q  then t ( G ) = p ^(q − 1) *  q^(p − 1) .

	Spanning Tree Applications :- 

    1) Computer Network Routing Protocol
    2) Cluster Analysis
    3) Civil Network Planning


Minimum Spanning Tree :-

	A minimum spanning tree is a spanning tree in which the sum of the weight of the edges is as minimum as possible.

	The minimum spanning tree from a graph is found using the following algorithms:

	1)  Prim's Algorithm
    2)	Kruskal's Algorithm

	Minimum Spanning tree Applications :-

    1) To find paths in the map
    2) To design networks like telecommunication networks, water supply networks, and electrical grids.


A graph that is not connected will not contain a spanning tree.

Generally these Spanning Trees have n-1 edges (n = no. of vertices)

no. of Spanning Trees =   ( eC(n-1) - no. of cycles) from these trees one tree will be Minimum Spanning tree
So for a given graph can have more than one spanning trees but has a unique minimum spanning tree.

Best way to solve this Minimum Spanning Tree Problem is by Using Greedy Method

*/



/*

Count Number of Spanning Trees :- (Kirchoff's Matrix-Tree Theorem)
	
	1) Make a Matrix (m)
		no. of rows = no. of columns =  number of vertices.

		for i != j ,  

					if i & j are adjacent vertices
						then m[i][j] = -1
					else
						m[i][j] = 0
		for i == j	,
					m[i][j]  = degree of vertex

	2) Delete any one row and any one column find determinant.

>> Determinant gives the number of spanning trees for given graph	

*/