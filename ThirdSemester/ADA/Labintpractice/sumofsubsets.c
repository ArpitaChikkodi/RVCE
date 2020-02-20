#include<stdio.h>
#define TRUE 1
#define FALSE 0
int inc[50],w[50],sum,n;
int promising(int i,int weight,int total)
{
	return (((weight+total) >= sum) && ((weight == sum) || (weight + w[i+1] <= sum)));
}

int sumset(int i,int weight,int total)
{
	int j;
	if(promising(i,weight,total))
	{
		if(weight==sum)
		{
			printf("\n{  ");
			for(j=0;j<=i;j++)          //j<=i
				if(inc[j]) 					//if inc[j] is true then print w[j]
					printf("%d  ",w[j]);
			printf("}\n");
		}
		else 
		{
			inc[i+1] = TRUE;           //check inc[i+1]
			sumset(i+1,weight+w[i+1],total-w[i+1]);
			inc[i+1]=FALSE;
			sumset(i+1,weight,total-w[i+1]);
		}
	}
}

void main()
{
	int total=0,i;
	printf("\nEnter number of elements : ");
	scanf("%d",&n);
	
	printf("\nEnter %d numbers : \n",n);
	for(i=0;i<n;i++)
	{
		scanf("%d",&w[i]);
		total += w[i];
	}
	
	printf("\nEnter sum : ");
	scanf("%d",&sum);
	
	if(total<sum)
		printf("\nSolution is not possible!");
	else
	{
		for(i=0;i<n;i++)
			inc[i]=0;
		printf("\nSolution is : ");
		sumset(-1,0,total);
	}
		
}
