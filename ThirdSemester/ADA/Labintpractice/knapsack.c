#include<stdio.h>
int max(int a,int b){ return (a>b)?a:b; }

int knapsack(int W,int set[],int val[],int n)
{
	int i,w,x[n],k[n+1][W+1];
	
	for(i=0;i<=n;i++)
	{
		for(w=0;w<=W;w++)
		{
			if(i==0 || w==0)
				k[i][w]=0;
			else if(set[i-1]<=w)
				k[i][w] = max (k[i-1][w] , k[i-1][w-set[i-1]] + val[i-1]);
			else
				k[i][w] = k[i-1][w];
		}
	}
	
	//Print
	printf("\nProfit matrix \n");
	for(i=0;i<=n;i++)
	{	
		printf("\n");
		for(w=0;w<=W;w++)
			printf("%d\t",k[i][w]);
	}
	
	//Selection
	printf("\nSelected\n");
	i = n;
	w = W;
	while(i!=0 && w!=0)
	{
		if(k[i][w] != k[i-1][w])
		{
			x[i] = 1;  //Select and decrease weight
			w = w - set[i-1];
		}
		i--;           //***
	}
	
	//Printobjects
	printf("\nSelected objects are : \n");
	for(i=1;i<=n;i++)
		printf("%d\t",i);
	for(i=1;i<=n;i++)
	{
		if(x[i]==1)
			printf("1\t");
		else
			printf("0\t");
	}
	printf("\n");
	
	return k[n][W]; //max value
}

void main()
{
	int i,W,n,set[20],val[20];
	
	printf("\nEnter number of items : ");
	scanf("%d",&n);
	
	printf("\nEnter weight and profits of the elements : \n");
	for(i=0;i<n;i++)
		scanf("%d%d",&set[i],&val[i]);
	
	printf("\nEnter max capacity of knapsack : \n");
	scanf("%d",&W);
	
	printf("\nTotal profit is %d",knapsack(W,set,val,n));
}
