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
			
			else if( set[i-1] <= w )
				k[i][w] = max(k[i-1][w] , k[i-1][w-set[i-1]]+val[i-1]);
			
			else
				k[i][w] = k[i-1][w];
		}
	}
	
	//print
	for(i=0;i<=n;i++)
	{
		printf("\n");
		for(w=0;w<=W;w++)
			printf("%d\t",k[i][w]);
	}
	
	//Selection of objects
	i = n;
	w = W;
	while(i!=0 && w!=0)
	{
		if(k[i][w] != k[i-1][w])
		{
			x[i] = 1;             //select ith object and decrease w by set[i-1]
			w = w - set[i-1];
		}
		i--; //imp
	}
	
	printf("\nSelected objects\n");
	//Print selected
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
	return k[n][W];   //return max value
}

void main()
{
	int i,n,W,set[20],val[20];
	printf("\nEnter number of items/objects : ");
	scanf("%d",&n);
	
	printf("\nEnter weights and profits of %d items\n",n);
	for(i=0;i<n;i++)
		scanf("%d %d",&set[i],&val[i]);
		
	printf("\nEnter max capacity of knapsack : ");
	scanf("%d",&W);
	
	printf("\nTotal profit is %d\n",knapsack(W,set,val,n));
}
