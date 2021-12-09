/*

ID : B171452
Code By Sandeep Payili on 17/10/2021

Problem Description : Pattern/String Matching
(The Naive String Matching Algorithm)

*/
#include<stdio.h>
#include<string.h>
#define MAX_STRING_SIZE 100
int string_matching(char *string1,char *string2)
{
	int flag;
	int i = 0, j = 0, k = 0;
	int string1_length = strlen(string1);
	int string2_length = strlen(string2);
	for (i = 0; i < (string1_length - string2_length + 1) ; i++ )
	{
		flag = 1; // assuming  match found
		for (j = i, k = 0; k < string2_length; k++,j++) // assuming string2 is non empty string
		{
			if (string1[j] != string2[k])
			{
				flag = 0;
			}
		}
		if (flag == 1)
		{
			return 1; // retrun 1 as match found
		}
	}
	return 0;//  0 for match not found
}
int main()
{
	char string1[MAX_STRING_SIZE];
	char string2[MAX_STRING_SIZE];
	printf("Enter  String  1  :  ");
	scanf(" %[^\n]s", string1);
	printf("Enter String   2  :  ");
	scanf(" %[^\n]s", string2);
	int string1_length = strlen(string1);
	int string2_length = strlen(string2);
	int i = 0, j = 0;
	int flag_count = 0;
	for (i = 0; i < (string1_length - string2_length + 1 ); i++)
	{
		flag_count = 0; // assuming match not found
		for (j = i; j < (i + string2_length ); j++)
		{
			if (string1[j] == string2[j - i]) // ascii values will be compared so it is case sensitive
			{
				flag_count ++;
			}
		}
		if (flag_count == string2_length)
		{
			printf("\nGiven Pattern/String Match Found \n");
			return 0;
		}
	}
	printf("\nGiven Pattern/String Match Not Found\n");

	/*

	//function driver
	if (string_matching(string1, string2))
	{
		printf("\nGiven Pattern/String Match Found \n");
	}
	else
	{
		printf("\nGiven Pattern/String Match Not Found\n");
	}

	*/
	return 0;
}

/*

Time Complexity : 
O( (string1_length - string2_length +1 ) * string2_length )
approximately == O(string1_length * string2_length) 

*/