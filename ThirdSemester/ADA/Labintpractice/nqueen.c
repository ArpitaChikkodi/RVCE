#include<stdio.h>
#include<math.h>
int x[30],count=0;

int place(int k)
{
	int i;
	for(i=1;i<k;i++) //i<k before this 
	{
		if(x[i]==x[k] || abs(i-k)==abs(x[i]-x[k]))       //column attack or both diagonal attacks
			return 0;
	}
	return 1;
}

void printsolution(int n)
{
	int i,j;
	count++; //number of solutions
	printf("\nSolution #%d\n",count);
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=n;j++)
		{
			if(x[i]==j)              //x[i]==j gives the position of queen 
				printf("1  ");
			else
				printf("0  ");
		}
		printf("\n");
	}		
}

void queen(int n)
{
	int k=1;
	x[k]=0;
	while(k!=0)
	{
		x[k]=x[k]+1;
		
		while(x[k]<=n && !place(k))
			x[k]=x[k]+1;
		if(x[k]<=n)
		{
			if(k==n)
				printsolution(n);
			else
			{
				k++; //next queen
				x[k]=0; //begin from 0th column again
			}
		}
		else
			k--; //else backtrack
	}
}

void main()
{
	int m,i,n;
	printf("\nEnter number of tests : ");
	scanf("%d",&m);
	for(i=0;i<m;i++)
	{
		printf("\nEnter number of queens : ");
		scanf("%d",&n);
		if(n==1)
			printf("\nTrivial solution!");
		else
		{
			queen(n);
			printf("\nTotal number of solutions are %d\n",count);
			count=0;
		}
	}
}
