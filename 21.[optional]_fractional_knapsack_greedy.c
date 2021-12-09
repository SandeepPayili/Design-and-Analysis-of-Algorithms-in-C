#include<stdio.h>
struct item
{
	float weight;
	float value;
	float ratio;
};
int main()
{
	int n;
	printf("Enter N : ");
	scanf(" %d",&n);
	struct item items[n];
	int i=0,j=0;
	printf("\nEnter Weights and Values :  \n");
	for(i=0;i<n;i++)
	{
		scanf(" %f  %f",&items[i].weight,&items[i].value);
	}
	int W;
	printf("\nEnter Capacity : ");
	scanf(" %d",&W);
	for(i=0;i<n;i++)
	{
		items[i].ratio = (float)items[i].value / items[i].weight;
	}

	// printf("\n");
	// for(i=0;i<n;i++)
	// {
	// 	printf(" %f  %f    %f ",items[i].weight,items[i].value,items[i].ratio);
	// }
	for(i=0;i<n;i++)
	{
		for(j=0;j<n-1;j++)
		{
			if(items[j+1].ratio > items[j].ratio)
			{
				struct item temp = items[j];
				items[j] = items[j+1];
				items[j+1] = temp;
			}
		}
	}
	// printf("\n\n\n");
	// for(i=0;i<n;i++)
	// {
	// 	printf(" %f  %f    %f ",items[i].weight,items[i].value,items[i].ratio);
	// }
	float max_profit = 0;
	for(i=0;i<n;i++)
	{
		if(items[i].weight <= W)
		{
			W -= items[i].weight;
			max_profit += items[i].value; 
		}else
		{
			max_profit += (items[i].ratio * W); 
			W = 0;
			break;
		}
		printf("\nprofit : %f\n",max_profit);
	}
	printf("\nMaximum Profit  = %f\n",max_profit);
}