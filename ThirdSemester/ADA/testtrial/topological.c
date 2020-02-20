#include<stdio.h>
void main()
{
	int indeg[10],a[10][10],flag[10];
	int i,j,k,n,count=0;
	
	printf("\nEnter number of vertices : ");
	scanf("%d",&n);
	
	printf("\nEnter adjacency matrix : ");
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			scanf("%d",&a[i][j]);
		}
	}
	
	for(i=0;i<n;i++) 
	{
		indeg[i] = 0;
		flag[i] = 0;
	}
	
	//calculate indegree row changes col is fixed
	for(i=0;i<n;i++) 
		for(j=0;j<n;j++)
			indeg[i] = indeg[i] + a[j][i]; //j,i
			
	printf("\nOrder is \t");	
	while(count<n)
	{
		for(k=0;k<n;k++)
		{
			if(indeg[k]==0 && flag[k]==0)
			{
				printf("%d  ",k+1);
				flag[k] = 1;
				
				for(i=0;i<n;i++)
					if(a[k][i] == 1)
					{ //row fix col changes
						indeg[i]--;
					}break;
			}
		}
		count++;
	}
}
