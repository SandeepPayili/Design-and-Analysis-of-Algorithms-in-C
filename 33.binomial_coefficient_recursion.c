#include<stdio.h>
#include<stdlib.h>
int nCk(int n,int k)
{
	if(n==k || k==0)
	{
		return 1;
	}
	return nCk(n-1,k-1) + nCk(n-1,k);
}
int main()
{
	int n,k;
	printf("Enter n and k  (to compute n choose k ):  ");
	scanf(" %d %d",&n,&k);
	printf("\n %d Choose %d  :  %d\n",n,k,nCk(n,k));
	return 0;
}