 #include<stdio.h>
#include<stdlib.h>
#include<limits.h>
// matrix chain multiplication 
int mcm(int *mat_dim,int i,int j,int **dp)
{
	if(i>=j)
	{
		dp[i][j] = 0;
		return 0;
	}
	if(dp[i][j] != -1)
	{
		return dp[i][j];
	} 

	int min = INT_MAX;
	for(int k=i;k<j;k++)
	{
		int multiplications = mcm(mat_dim,i,k,dp) + mcm(mat_dim,k+1,j,dp) + (mat_dim[i-1] * mat_dim[k] * mat_dim[j] ) ;
		if ( multiplications < min )
		{
			min = multiplications;
		}
	}
	dp[i][j] = min;
	return min;
}
int main()
{

	int n;
	int i=0,j=0;
	printf("Enter number of Matrices : ");
	scanf(" %d",&n);
	int mat_dim[n+1]; // to store n matrices dimensions
	printf("Enter Dimensions  : ");
	for(i=0;i<=n;i++)
	{
		scanf(" %d",&mat_dim[i]);
	}

	int **dp; // only upper traingular matrix will be neccessary and used
	dp = (int **)malloc((n+1) * sizeof(int *));
	for(i=0;i<=n;i++)
	{
		*(dp+i) = (int *)malloc((n+1)*sizeof(int));
	}
	for(i=0;i<=n;i++)
	{
		for(j=0;j<=n;j++)
		{
			dp[i][j] = -1;
		}
	}
	printf("\n\nMinimum Number of Multiplications   :    %d \n\n",mcm(mat_dim,1,n,dp));
}