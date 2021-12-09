/*

ID : B171452
Code By Sandeep Payili on 21/10/2021

Problem Description : Multiplying Large Numbers-Brute Force Method  (Only for Positive Integers)

(The number of digits of the result of multiplying two numbers must not be greater than the sum of the lengths of the two numbers.)
(The number to be multiplied is the "multiplicand",
and the number by which it is multiplied is the "multiplier". ...
The result of a multiplication is called a product. A product of integers is a multiple of each factor.
For example, 15 is the product of 3 and 5, and is both a multiple of 3 and a multiple of 5.)

*/
#include<stdio.h>
#include<stdlib.h>
int main()
{
	int multiplicand_n, multiplier_n;
	printf("Enter No. Of Digits of multiplicand  : ");
	scanf(" %d", &multiplicand_n);
	printf("Enter No. Of Digits of multiplier    : ");
	scanf(" %d", &multiplier_n);
	int multiplicand[multiplicand_n];
	int multiplier[multiplier_n];
	printf("Enter Multiplicand   (Digit by Digit)  : ");//only single digit for each input
	int i = 0, j = 0, k = 0;
	for (i = 0; i < multiplicand_n; i++)
	{
		scanf(" %d", &multiplicand[i]);
	}
	printf("Enter Multiplier     (Digit by Digit)  : ");//only single digit for each input
	for (i = 0; i < multiplier_n; i++)
	{
		scanf(" %d", &multiplier[i]);

	}

	/*
	int product[multiplicand_n+multiplier_n] = {0};
	error: variable-sized object may not be initialized
	*/

	int product[multiplicand_n + multiplier_n];
	for (int temp = 0; temp < multiplicand_n + multiplier_n; temp++)
	{
		product[temp] = 0;   // to avoid garbage values
	}
	int product_array_index = multiplicand_n + multiplier_n - 1;
	for (i =  multiplier_n  - 1; i >= 0; i--)
	{
		int temp = product_array_index;
		for (j =  multiplicand_n - 1 ; j >= 0 ; j--)
		{
			product[temp] += (multiplier[i] * multiplicand[j]);
			temp--;
		}
		product_array_index--;// just like placing X as in pen paper method
	}

	int carry = 0;//updating product array to each index of single digit only i.e., all carry's are calculated
	for (i = multiplicand_n + multiplier_n  - 1; i >= 0; i--)
	{
		product[i] +=  carry;
		carry = product[i] / 10;
		product[i] = (product[i] % 10);
	}
	// since leading zeros of any number is not so significant.
	int zero_count = 0;
	for (k = 0; k < multiplicand_n + multiplier_n  ; k++)
	{
		if (product[k] == 0)
		{
			zero_count++;
		}
		else
		{
			break; // upto first non zero digit
		}
	}

	// printing output
	printf("\nProduct of ");
	for (i = 0; i < multiplicand_n; i++)
	{
		printf("%d", multiplicand[i]);
	}
	printf("  *  ");
	for (i = 0; i < multiplier_n; i++)
	{
		printf("%d", multiplier[i]);
	}
	printf("  =  ");
	/*// with preceding zeros
	for (i = 0; i <  multiplicand_n + multiplier_n ; i++)
	{
		printf("%d", product[i]);
	}
	*/
	// without preceding zeros
	for (i = 0 + zero_count; i <  multiplicand_n + multiplier_n  ; i++)
	{
		printf("%d", product[i]);
	}
	printf("\n\n");
	return 0;
}
/*
it takes O(n^2) time.
*/

/* 

OUTPUT :

Enter No. Of Digits of multiplicand  : 7
Enter No. Of Digits of multiplier    : 3
Enter Multiplicand   (Digit by Digit)  : 7 6 5 4 3 2 1
Enter Multiplier     (Digit by Digit)  : 3 2 1

Product of 7654321  *  321  =  2457037041

*/

/*
OUTPUT 2:

Enter No. Of Digits of multiplicand  : 12
Enter No. Of Digits of multiplier    : 11
Enter Multiplicand   (Digit by Digit)  : 1 5 0 3 5 3 2 6 5 3 2 6
Enter Multiplier     (Digit by Digit)  : 2 2 0 5 5 6 5 3 3 5 1

Product of 150353265326  *  22055653351  =  3316139500221184007426

*/