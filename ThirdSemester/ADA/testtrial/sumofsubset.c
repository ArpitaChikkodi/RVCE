#include<stdio.h>
#define TRUE 1
#define FALSE 0
int inc[50],w[50],sum,n,flag = 0;

int promising(int i,int weight,int total)
{
	return ((weight+total>=sum) && ((weight==sum) || (weight+w[i+1]<=sum)));
}

void sumset(int i,int weight,int total)
{
	int j;
	if(promising(i,weight,total))
	{
		if(weight==sum)
		{
			printf("\n{ ");
			flag =1;
			for(j=0;j<=i;j++)
				if(inc[j])
					printf(" %d ",w[j]);
			printf("} \n");
		}
		else
		{
			inc[i+1] = TRUE;
			sumset(i+1,weight+w[i+1],total-w[i+1]);
			inc[i+1] = FALSE;
			sumset(i+1,weight,total-w[i+1]);
		}
	}
}

void main()
{
	int total,i;
	printf("\nEnter number of elements : ");
	scanf("%d",&n);
	
	printf("\nEnter %d elements in ascending order : ",n);
	for(i=0;i<n;i++)
	{
		scanf("%d",&w[i]);
		total+=w[i];
	}		
	
	printf("\nEnter sum : ");
	scanf("%d",&sum);
	
	if(total<sum)
		printf("\nSolution not possible!\n");
	else
	{
		for(i=0;i<n;i++)
			inc[i] = 0;
		printf("\nSolution is ");
		sumset(-1,0,total);
	}
	if(!flag)
		printf("not possible!\n");
}
