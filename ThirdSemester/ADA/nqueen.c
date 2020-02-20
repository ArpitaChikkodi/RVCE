#include<stdio.h>
#include<math.h>
int x[30],count=0;
int place(int k)
{
	int i;
	for (i=1;i<k;i++) {
		if((x[i]==x[k])||((abs(x[i]-x[k])==abs(i-k))))
		   return 0;
	}
	return 1;
}
void print_sol(int n) 
{
	int i,j;
	count++;
	printf("\n\nSolution #%d:\n",count);
	for (i=1;i<=n;i++) {
		for (j=1;j<=n;j++) {
			if(x[i]==j)
			    printf("1\t"); else
			    printf("0\t");
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
	
		while((x[k]<=n)&&!place(k))
		   x[k]++;
	
		if(x[k]<=n)
		{
			if(k==n)
			    print_sol(n); 
			else
			{
				k++;
				x[k]=0;
			}
		}
		else
		   k--;
	}
}
void main()
{
	int i,n,m;
	printf("\nEnter the number of Tests : \n");
	scanf("%d",&m);
	for(i=0;i<m;i++)
	{
		printf("Enter the number of Queens : \n");
		scanf("%d",&n);
		if(n==1)
			printf("\nTrivial solution");
		else
		{
			queen(n);
			printf("\nTotal solutions=%d",count);
			count=0;
		}
	}
}
