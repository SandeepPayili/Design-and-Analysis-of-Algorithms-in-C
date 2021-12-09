/*

ID : B171452
Code By Sandeep Payili on 26/10/2021

Problem Description : Introduction to Dynamic Programming(Memoization and Tabulation)

*/

/*

Dynamic Programming is mainly an optimization over plain recursion.
Wherever we see a recursive solution that has repeated calls for same inputs, we can optimize it using Dynamic Programming.
The idea is to simply store the results of subproblems, so that we do not have to re-compute them when needed later.
This simple optimization reduces time complexities from exponential to polynomial.

Greedy is an algorithmic paradigm that builds up a solution piece by piece,
always choosing the next piece that offers the most obvious and immediate benefit.
So the problems where choosing locally optimal also leads to global solution are best fit for Greedy.
Examples of Greedy Algorithms

    Prim's Minimal Spanning Tree Algorithm.
    Travelling Salesman Problem.
    Graph – Map Coloring.
    Kruskal's Minimal Spanning Tree Algorithm.
    Dijkstra's Minimal Spanning Tree Algorithm.
    Graph – Vertex Cover.
    Knapsack Problem.
    Job Scheduling Problem.


Dynamic Programming and Greedy Programming are mean for optimization.
(Optimization problems are to find minimum or maximum results)


In Greedy Programming Procedure is Known and we assume that procedure is optimal and it follows optimal result.

Dynamic Programming Follows Principle of Optimality.

Principle of Optimality  :-  A problem can be solved by taking sequence of decisions to get optimal solutions.

Dynamic Programming Will be solved by recursive formula.Generate all possible solutions and pick best one.It is more time consuming
compared to Greedy Approach.

Dynamic Programming can be solved in two ways.
1) Memoization   (Top Down  Approach)   (Recursion)
2) Tabulation     (Bottom Up Approach)   (Loops)


Recursive Code + Memoization   === Dynamic Programming


Three Ways to solve Problem:-
1)Recursion
2)Memoization
3)Tabulation


*/


// fibonacci(5) will make 15 function calls
// T(n) = 2 T(n-1) + 1  ( considering T(n-2) approximately equal to T(n-1))
// O(2^n)  // By Master's Theorem for decreasing function
int fibonacci_recursion(int n) // fibonacci defined only for positive numbers
{
    if (n == 0 || n == 1)
    {
        return n;
    }
    return fibonacci_recursion(n - 2) + fibonacci_recursion(n - 1);
}



//we store the results of computed funciton calls to not to call again.
// fibonacci(5) will make 6 function calls
// fibonacci(n) = n + 1 funciton calls
// O(n)
void fibonacci_dp_memoization(int n, int *fibonacci_array)
{
    if (n == 0 || n == 1)
    {
        fibonacci_array[n] = n;
    }
    else
    {
        if (fibonacci_array[n] == -1)
        {
            fibonacci_dp_memoization(n - 2, fibonacci_array);
            fibonacci_dp_memoization(n - 1, fibonacci_array);
            fibonacci_array[n] =  fibonacci_array[n - 2]  + fibonacci_array[n - 1];
        }
    }
}
int fibonacci_dp_memoization2(int n, int *fibonacci_array)
{
    if (n == 0 || n == 1)
    {
        fibonacci_array[n] = n;
        return n;
    }
    else
    {
        if (fibonacci_array[n] == -1)
        {
            fibonacci_array[n] =  fibonacci_dp_memoization2(n - 2, fibonacci_array) + fibonacci_dp_memoization2(n - 1, fibonacci_array);
        }
    }
    return fibonacci_array[n];
}
void fibonacci_dp_tabulation(int n, int *fibonacci_array)
{
    fibonacci_array[0] = 0;
    fibonacci_array[1] = 1;
    for (int i = 2; i <= n; i++)
    {
        fibonacci_array[i] = fibonacci_array[i - 2] + fibonacci_array[i - 1];
    }
}


#include<stdio.h>
int main()
{
    int n;
    printf("Enter  n  :  ");
    scanf(" %d", &n);
    // printf("\n  %d  Fibonacci Term is  : %d \n", n,fibonacci_recursion(n));
    int fibonacci_array[n + 1];
    for (int i = 0; i <= n; i++)
    {
        fibonacci_array[i] = -1;
    }
    // fibonacci_dp_memoization(n,fibonacci_array);
    // fibonacci_dp_memoization2(n,fibonacci_array);
    // printf("\n  %d  Fibonacci Term is  : %d \n", n,fibonacci_dp_memoization2(n,fibonacci_array));
    fibonacci_dp_tabulation(n, fibonacci_array);
    printf("\n  %d  Fibonacci Term is  : %d \n", n, fibonacci_array[n]);
    return 0;
}

// we observed that complexity changed from 2^n to  n  i.e., exponential to polynomial by Dynamic Programming.