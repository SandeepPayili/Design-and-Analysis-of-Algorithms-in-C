 #include<stdio.h>
#include<stdlib.h>
#include<limits.h>
// matrix chain multiplication 
int mcm(int *mat_dim,int i,int j)
{
	if(i>=j)
	{
		return 0; 
	}
	int min = INT_MAX;
	for(int k=i;k<j;k++)
	{
		int multiplications = mcm(mat_dim,i,k) + mcm(mat_dim,k+1,j) + (mat_dim[i-1] * mat_dim[k] * mat_dim[j] ) ;
		if ( multiplications < min )
		{
			min = multiplications;
		}

	}
	return min;
}
int main()
{

	int n;
	int i=0;
	printf("Enter number of Matrices : ");
	scanf(" %d",&n);
	int mat_dim[n+1]; // to store n matrices dimensions
	printf("Enter Dimensions  : ");
	for(i=0;i<=n;i++)
	{
		scanf(" %d",&mat_dim[i]);
	}
	
	printf("\n\nMinimum Number of Multiplications   :    %d \n\n",mcm(mat_dim,1,n));
}