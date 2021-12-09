/*

ID : B171452
Code By Sandeep Payili on 31/10/2021

Problem Description : Disjoint Set Data Structure – Union Find Algorithm
(A disjoint-set data structure, also called a union–find data structure or merge–find set)

*/

//It is a data structure that contains a collection of disjoint or non-overlapping sets. 
//The disjoint set means that when the set is partitioned into the disjoint subsets

/*

What is Disjoint-set data structure?

    1) Represents a mathematics concept Set.
    2) A disjoint-set data structure, also called a union–find data structure or merge–find set.
    3) A disjoint-set data structure that keeps track of a set of elements partitioned into a number of disjoint or non-overlapping subsets.
    4) It provides near-constant-time operations to add new sets, to merge existing sets, and to determine whether elements are in the same set.
    5) Plays a key role in Kruskal’s algorithm for finding the minimum spanning tree of a graph.
    6) This can also be used to detect cycle in the graph.

How Disjoint Set is constructed:

    1) A disjoint-set forest consists of a number of elements each of which stores an id, a parent pointer
    2) The parent pointers of elements are arranged to form one or more trees, each representing a set.
    3) If an element’s parent pointer points to no other element, 
       then the element is the root of a tree and is the representative member of its set.
    4) A set may consist of only a single element. However, if the element has a parent, 
       the element is part of whatever set is identified by following the chain of parents upwards 
       until a representative element (one without a parent) is reached at the root of the tree.

Disjoint Set Operations:

	MakeSet(X): This operation makes a new set by creating a new element with a parent pointer to itself. 
	            The parent pointer to itself indicates that the element is the representative member of its own set. 
	            The MakeSet operation has O(1) time complexity.

	Find(X):    follows the chain of parent pointers from x upwards through the tree until an element is reached whose parent is itself. 
	            This element is the root of the tree and is the representative member of the set to which x belongs, and may be x itself.

	Union(x,y): Uses Find to determine the roots of the trees x and y belong to. If the roots are distinct, the trees are combined by 
	            attaching the root of one to the root of the other. If this is done naively, such as by always making x a child of y, 
	            the height of the trees can grow as O(n).


Applications using Disjoint sets:

    1) Represents network connectivity.
    2) Image Processing.
    3) In game algorithms.
    4) Kruskal’s minimum spanning tree.
    5) Find cycle in undirected graphs.

*/

//We can optimize this algorithm by doing “Union by rank and path compression” 
//Weighted Union and Collapsing Find are more time efficient

#include<stdio.h>
//weighted union or Union by rank
// Union can be done in brute force way also
void Union(int u,int v,int *s)
{
	if(s[u] < s[v]) // heighest weight will become root(here root are in negative so,condition is opposite)
	{
		s[u] = s[u] + s[v]; 
		s[v] = u;
	}else
	{
		s[v] = s[v] + s[u];
		s[u] = v;
	}
}
//brute force way of find operation
//by Path Compression or Collapsing find we can reduce Time Complexity
int find(int u,int *s)
{
	int x = u;
	while(s[x] > 0)
	{
		x = s[x];// recursive call find(s[x])
	}
	return x;
}
int main()
{
	int n,i;
	printf("Enter no. of Universal Set Elements : ");
	scanf(" %d",&n);
	int univeral_set[n];//we take incides as universal elements
	for(i=0;i<n;i++)
	{
		// indicate negative number for head of set
		// more precisely indice head of set with negatve of total number of nodes of that set
		univeral_set[i] = -1;//element is itself one of disjoint set
	}
	int operation;
	int ele;
	int x,y;// to store head of sets to do union
	do{
		printf("\n1.Find(head of disjoint subset)   2.Union(of two disjoint sets)    3.Print Sets   4.Exit\n");
		scanf(" %d",&operation);
		switch(operation)
		{
			case 1 : printf("Enter element for which you want to find root : ");
					 scanf(" %d",&ele);
					 int result = find(ele,univeral_set);
					 printf("\nParent of %d is : %d\n",ele,result);
					 break;
			case 2 : 
					 printf("Enter head of sets  to do union :  ");// as vertices of edge
					 scanf(" %d %d",&x,&y);
					 Union(x,y,univeral_set);// x and y are roots of two different disjoint subsets
					 break;
			case 3  : 
					 // number of negative numbers represent that many disjoint sets in universal set
					 printf("\nCurrent Disjoint SubSets   :  ");
					 for(i=0;i<n;i++)
					 {	
					 	printf(" %d ",univeral_set[i]);
					 }
					 printf("\n");
					 break;
			case 4 : break;
		}
	}while(operation!= 4);
	return 0;
}

/* Time Complexity :

	 1) Brute Force Approach : 
	 		  		
	 		  		O( e * v )  

				Find  : O( n )
				Union : O( n )
	 		
	 			// e = since process all edges and 
	 			// v = find or union wrost case in a skewed tree.
	 
	 2) By Optimization (Union By Rank and Path Compression ) i.e., (Weighted Union and Collapsing Find)
		
				Find  : O(log n )
				Union : O(log n )
					
*/	

/*

OUTPUT:


Enter no. of Universal Set Elements : 11

1.Find(head of disjoint subset)   2.Union(of two disjoint sets)    3.Print Sets   4.Exit
3

Current Disjoint SubSets   :   -1  -1  -1  -1  -1  -1  -1  -1  -1  -1  -1 

1.Find(head of disjoint subset)   2.Union(of two disjoint sets)    3.Print Sets   4.Exit
2
Enter head of sets  to do union :  5 3

1.Find(head of disjoint subset)   2.Union(of two disjoint sets)    3.Print Sets   4.Exit
2
Enter head of sets  to do union :  9 3

1.Find(head of disjoint subset)   2.Union(of two disjoint sets)    3.Print Sets   4.Exit
3

Current Disjoint SubSets   :   -1  -1  -1  -3  -1  3  -1  -1  -1  3  -1 

1.Find(head of disjoint subset)   2.Union(of two disjoint sets)    3.Print Sets   4.Exit
2
Enter head of sets  to do union :  7 4

1.Find(head of disjoint subset)   2.Union(of two disjoint sets)    3.Print Sets   4.Exit
2
Enter head of sets  to do union :  8 4

1.Find(head of disjoint subset)   2.Union(of two disjoint sets)    3.Print Sets   4.Exit
2
Enter head of sets  to do union :  10 4

1.Find(head of disjoint subset)   2.Union(of two disjoint sets)    3.Print Sets   4.Exit
3

Current Disjoint SubSets   :   -1  -1  -1  -3  -4  3  -1  4  4  3  4 

1.Find(head of disjoint subset)   2.Union(of two disjoint sets)    3.Print Sets   4.Exit
2
Enter head of sets  to do union :  3 4

1.Find(head of disjoint subset)   2.Union(of two disjoint sets)    3.Print Sets   4.Exit
3

Current Disjoint SubSets   :   -1  -1  -1  4  -7  3  -1  4  4  3  4 

1.Find(head of disjoint subset)   2.Union(of two disjoint sets)    3.Print Sets   4.Exit
4

*/