#include<stdio.h>
#include<stdlib.h>
int nCk(int n, int k, int **dp)
{
	if (dp[n][k] != -1)
	{
		return dp[n][k];
	}

	if (n == k || k == 0)
	{
		dp[n][k] = 1;
		return 1;
	}

	dp[n][k] = nCk(n - 1, k - 1, dp) + nCk(n - 1, k, dp);
	return dp[n][k];
}
int main()
{
	int n, k;
	int i = 0, j = 0;
	printf("Enter n and k  (to compute n choose k ):  ");
	scanf(" %d %d", &n, &k);

	int **dp;// index 0 is ignored
	dp = (int **)malloc( (n+1) * sizeof(int *));
	for (i = 0; i <= n; i++)
	{
		*(dp + i) = (int *)malloc( (k+1) * sizeof(int));
	}

	for (i = 0; i <= n; i++)
	{
		for (j = 0; j <= k; j++)
		{
			dp[i][j] = -1;
		}
	}
	printf("\n %d Choose %d  :  %d\n", n, k, nCk(n, k, dp));
	/*
	for(i=0;i<=n;i++)
	{
		for(j=0;j<=k;j++)
		{
			printf(" %10d ",dp[i][j]);
		}
		printf("\n");
	}*/
	return 0;
}                                                                                                           