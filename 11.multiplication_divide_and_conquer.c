/*

ID : B171452
Code By Sandeep Payili on 22/10/2021

Problem Description : Multiplying Large Numbers - Divide and Conquer Method  (Only for Positive Integers)
(The Karatsuba algorithm)

*/

/*
LLONG_MIN	 Minimum value for a variable of type long long.		   		-9,223,372,036,854,775,807 - 1
LLONG_MAX	 Maximum value for a variable of type long long.	        	9,223,372,036,854,775,807
ULLONG_MAX	 Maximum value for a variable of type unsigned long long.		18,446,744,073,709,551,615 (0xffffffffffffffff)

*/

/*
	 a = a1a0   b = b1b0
	 n = max(no_of_digits(a),no_of_digits(b))
	 c = a ∗ b = c210^(n) + c110^(n/2) + c0,
	 c2 = a1 ∗ b1
	 c0 = a0 ∗ b0
	 c1 = (a1 + a0) ∗ (b1 + b0) − (c2 + c0)
	
	 M(n) = 3M(n/2)      for n > 1,    M(1) = 1.
	 M(n) = 3^log2 n = n^log2 3 ≈ n^1.585.             //a^logb c = c^logb a

 */
#include<stdio.h>
#include<limits.h>
#include<math.h> // also we need to compile by including   -lm 
unsigned long long int max(unsigned long long int a, unsigned long long int b)
{
	return (a > b) ? a : b ;
}
unsigned long long int max_no_of_digits(unsigned long long int a, unsigned long long int b)
{
	unsigned long long int number = max(a, b);
	unsigned long long int no_of_digits = 0;
	while (number != 0)
	{
		no_of_digits++;
		number = number / 10;
	}
	return no_of_digits;
}
unsigned long long int split_right_half(unsigned long long int number, unsigned long long int n)
{
	return number % (unsigned long long int)pow(10, n); // since pow returns double
}
unsigned long long int split_left_half(unsigned long long int number, int n)
{
	return number / (unsigned long long int)pow(10, n); // since pow returns double
}
unsigned long long int multiply(unsigned long long int a, unsigned long long int b)
{
	if (a < 10 || b < 10 )
	{
		return a * b;
	}
	unsigned long long int no_of_digits = max_no_of_digits(a, b);
	unsigned long long int a0 = split_right_half(a, no_of_digits / 2);
	unsigned long long int a1 = split_left_half(a, no_of_digits / 2);
	unsigned long long int b0 = split_right_half(b, no_of_digits / 2);
	unsigned long long int b1 = split_left_half(b, no_of_digits / 2);
	unsigned long long int c2  = multiply(a1, b1);
	unsigned long long int c0 = multiply(a0, b0);
	// unsigned long long int c1 = multiply(a0,b1) + multiply(a1,b0); // this takes one extra multiplication so we optimise it
	unsigned long long int c1 = multiply( (a0 + a1), (b0 + b1) ) - (c0 + c2);
	unsigned long long int temp_power = ((no_of_digits / 2) + (no_of_digits / 2));
	// unsigned long long int temp_power = (no_of_digits); // causes problem when no_of_digits is odd
	// ex:-  when no_of_digits = 9; ( no_of_digits/2 = 4 +  no_of_digits/2  = 4  == 8 but no_of_digits = 9)
	return ( c2 * (unsigned long long int)pow(10, temp_power)) + ( c1 * (unsigned long long int)pow(10, no_of_digits / 2) ) + ( c0);
}

int main()
{
	// printf("%llu\n",LLONG_MAX);  //9223372036854775807   >> 19 digits
	// printf("%llu\n",ULLONG_MAX); //18446744073709551615  >> 20 digits
	unsigned long long int multiplicand;
	unsigned long long int multiplier;
	printf("Enter Multiplicand   : ");
	scanf(" %llu", &multiplicand);
	printf("Enter Multiplier     : ");
	scanf(" %llu", &multiplier);
	// printf("\n%llu\n", multiplicand * multiplier);
	/*#Python Code to check Correctness
	if( 18446744073709551615 < n1*n2):
		print(" limit exceeded ")
	else:
		print("limit not exceeded ")
	*/
	printf("\n%llu  *  %llu  ==  %llu\n\n", multiplicand, multiplier, multiply(multiplicand, multiplier));
	 // may return 0 or negative number or some wrong result for overflow condition
	return 0;
}
