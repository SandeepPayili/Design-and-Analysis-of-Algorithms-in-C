/*

ID : B171452
Code By Sandeep Payili on 28/10/2021

Problem Description : Greedy Algorithms

*/

/*

 Techniques for  Optimization Problems :
	1 Greedy Method
	2) Dynamic Programming 
	3) Branch and Bound

Optimization :- finding optimal solution from feasible solutions.

*/


/*

Greedy Algorithms :-

A greedy algorithm is a simple, intuitive algorithm that is used in optimization problems.
The algorithm makes the optimal choice at each step as it attempts to find the overall optimal way to solve the entire problem. 
Greedy algorithms are quite successful in some problems, such as Huffman encoding which is used to compress data, or Dijkstra's
algorithm, which is used to find the shortest path through a graph. 

However, in many problems, a greedy strategy does not produce an optimal solution. 

If both of the properties below are true, a greedy algorithm can be used to solve the problem.

   1) Greedy choice property: A global (overall) optimal solution can be reached by choosing the optimal choice at each step.
   2) Optimal substructure: A problem has an optimal substructure if an optimal solution to the entire problem contains the optimal 
   solutions to the sub-problems.

In other words, greedy algorithms work on problems for which it is true that, at every step, there is a choice that is optimal 
for the problem up to that step, and after the last step, the algorithm produces the optimal solution of the complete problem.

To make a greedy algorithm, identify an optimal substructure or subproblem in the problem. Then, determine what the solution will 
include (for example, the largest sum, the shortest path, etc.). Create some sort of iterative way to go through all of the 
subproblems and build a solution.


Limitations of Greedy Algorithms :

	Sometimes greedy algorithms fail to find the globally optimal solution because they do not consider all the data. The choice 
	made by a greedy algorithm may depend on choices it has made so far, but it is not aware of future choices it could make.


	In problems where greedy algorithms fail, dynamic programming might be a better approach

Applications:-
	1) Dijkstra's Algorithm : 
		Dijkstra's algorithm is used to find the shortest path between nodes in a graph.
	2) Huffman Coding :
		Huffman encoding is another example of an algorithm where a greedy approach is successful. The Huffman algorithm analyzes a 
		message and depending on the frequencies of the characters used in the message, it assigns a variable-length encoding for 
		each symbol. A more commonly used symbol will have a shorter encoding while a rare symbol will have a longer encoding. 


*/


/*

Greedy Method :

We choose local best which may not be global best
Procedure is fixed and it is optimal procedure
but result may not be optimal at the end if we take all combinations and see best results.

*/