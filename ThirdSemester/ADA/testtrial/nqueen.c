#include<stdio.h>
#include<math.h>
int x[30],count=0;
int place(int k)
{
	int i;
	for(i=1;i<k;i++)
	{
		if(x[i]==x[k] || abs(i-k)==abs(x[i]-x[k]))
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
			if(x[i]==j)
				printf("1\t");
			else
				printf("0\t");
		}
		printf("\n");
	}
}

void queen(int n)
{
	int k = 1;
	x[k] = 0;
	while(k!=0)
	{
		x[k] = x[k] + 1;
		while(x[k] <= n && !place(k))
			x[k] = x[k] + 1;
			
		if(x[k] <= n)
		{
			if(k==n)
				printsolution(n);
			else
				{
					k++;
					x[k] = 0;
				}
		}
		else
			k--;
	}
}
void main()
{
	int n;
	printf("\nEnter number of queens : ");
	scanf("%d",&n);
	
	queen(n);
	printf("\nTotal number of solutions = %d\n",count);
}
