#include<stdio.h>
#include<stdlib.h>

void main()
{
	int a[10][10],indeg[10],flag[10];
	int count=0,i,j,k,n;
	
	printf("\nEnter number of vertices : ");
	scanf("%d",&n);
	
	for(i=0;i<n;i++)
	{
		printf("\nEnter %d row elements :",i+1);
		for(j=0;j<n;j++)
		{
			scanf("%d",&a[i][j]);
			if(i==j)
			{
				if(a[i][j]!=0)
				{
					printf("\nEnter acyclic graph!\n");
					exit(0);
				}
			}
		}
	}
	
	for(i=0;i<n;i++)
	{
		indeg[i]=0;
		flag[i]=0;
	}
	
	//Calculate indegree of each vertex where row is changing and column is fixed
	for(i=0;i<n;i++)
		for(j=0;j<n;j++)
			indeg[i]=indeg[i]+a[j][i]; //j,i
			
	printf("\nOrdering of vertices is : ");
	while(count<n)
	{
		for(k=0;k<n;k++)
		{
				if(indeg[k]==0 && flag[k]==0)
				{
					printf("%d  ",k+1);
					flag[k]=1;
				}
				
				//if no node's indegree is 0 
				for(i=0;i<n;i++)
				{
					if(a[i][k]==1)   
						indeg[k]--;
				}
				
		}
		count++;
	}

}
