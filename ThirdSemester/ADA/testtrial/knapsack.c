#include<stdio.h>
int max(int a,int b){ return (a>b)?a:b; }

int knapsack(int W,int set[],int val[],int n)
{
	int i,w,x[20],k[n+1][W+1];
	
	for(i=0;i<=n;i++)
	{
		for(w=0;w<=W;w++)
		{
			if(i==0 || w==0)
				k[i][w] = 0;
			else if(set[i-1] <= w)
				k[i][w] = max(k[i-1][w] , k[i-1][w-set[i-1]]+val[i-1]);
			else
				k[i][w] = k[i-1][w];
		}
	}
	
	//print
	printf("\nProfit matrix\n");
	for(i=0;i<=n;i++)
	{
		printf("\n");
		for(w=0;w<=W;w++)
		{
			printf("%d\t",k[i][w]);
		}
	}
	
	//Selection
	i = n;
	w = W;
	while(i!=0 && w!=0)
	{
		if(k[i][w] != k[i-1][w])
		{
			x[i] = 1;
			w = w-set[i-1];
		}
		i--; //**
	}
	
	printf("\nSelected objects \n");
	for(i=1;i<=n;i++)
		printf("%d\t",i);
	printf("\n");
	for(i=1;i<=n;i++)
	{
		if(x[i]==1)
			printf("1\t");
		else
			printf("0\t");
	}
	
		printf("\n");

	return k[n][W];
}

void main()
{
	int W,i,val[20],set[20],n;
	printf("\nEnter number of items : ");
	scanf("%d",&n);
	
	printf("\nEnter profits and weights of items : ");
	for(i=0;i<n;i++)
		scanf("%d%d",&val[i],&set[i]);
		
	printf("\nEnter max capacity : ");
	scanf("%d",&W);
	
	printf("\nTotal profit is %d",knapsack(W,set,val,n));
}
