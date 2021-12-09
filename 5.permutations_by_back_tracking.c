/*

ID : B171452
Code By Sandeep Payili on 19/10/2021

Problem Description : Permutations By Back Tracking
(It is based on the ideas of divide-and-conquer, swapping and backtracking.)

*/
#include<stdio.h>
#include<string.h>
void permute(char *string,int left_index,int right_index)
{
	if(left_index == right_index)
	{
		printf(" %s ", string);
	}
	for(int i=left_index;i<=right_index;i++)
	{
		int temp = string[left_index];
		string[left_index] = string[i];
		string[i] = temp;
		permute(string,left_index+1,right_index);
		temp = string[left_index];
		string[left_index] = string[i];
		string[i] = temp;
	}
}
int main()
{
	char string[100];
	printf("\nEnter String : ");
	scanf(" %[^\n]s",string);
	int left_index=0,right_index = strlen(string) - 1 ;
	permute(string,left_index,right_index);
	printf("\n\n");
	return 0;
}
