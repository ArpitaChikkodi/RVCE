#include<stdio.h>
#include<math.h>
int x[30],count=0; //count for solutions, x[] is to remember queen's place

int place(int k)
{
	int i;
	for(i=1;i<k;i++) //i<k check before this kth queen 
	{
		if( x[i]==x[k] || abs(i-k)==abs(x[i]-x[k])) // col and diagonal attack
			return 0;
	}
	
	return 1; 
}

void printsolution(int n)
{
	int i,j;
	count++;
	printf("\nSolution #%d\n",count);
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=n;j++)
		{
			if(x[i] == j)
				printf(" 1 ");
			else
				printf(" 0 ");
		}
		printf("\n");
	}
}

void queen(int n)
{
	int k = 1; //select 1st queen
	x[k] = 0; //do not place
	while(k!=0)   //while queen exists
	{
		x[k] = x[k] + 1; //inc col
		while( x[k]<=n && !place(k) )
			x[k] = x[k] + 1;
			
		if(x[k]<=n)
		{
			if(k==n)      //all queen places?
				printsolution(n);
			else
			{
				k++;   //next queen
				x[k] = 0;  //start again with next queen from 1st col
			}
		}
		else
			k--; //else backtrack
	}
}

void main()
{
	int m,n,i;
	printf("\nEnter number of tests : ");
	scanf("%d",&m);
	
	for(i=0;i<m;i++)
	{
		printf("\nEnter number of queens to place : ");
		scanf("%d",&n);
		
		if(n==1)
			printf("\nTrivial solution!\n");
		else
		{
			queen(n);
			printf("\nTotal number of solutions : %d",count);
			count = 0;
		}
	}
}
