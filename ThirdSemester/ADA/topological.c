#include<stdio.h>

void main()
{
	int i,j,k,a[10][10],indeg[10],flag[10];
	int count=0,n;
	
	printf("\nEnter number of vertices : ");
	scanf("%d",&n);
	
	printf("\nEnter adjacency matrix : \n");
	for(i=0;i<n;i++)
	{
		indeg[i] = 0;
		flag[i] = 0;
		for(j=0;j<n;j++)
			scanf("%d",&a[i][j]);		
	}
	
	//Calculate indegree of every node where row in changing and col is constant
	for(i=0;i<n;i++)
		for(j=0;j<n;j++)
			indeg[i] = indeg[i] + a[j][i]; //j,i
			
	printf("\nOrdering is \t : ");
	while(count<n)
	{
		for(k=0;k<n;k++)
		{
			//printf("\nK is %d\n",k+1);
			if(indeg[k]==0 && !flag[k])
			{
				printf(" %d ",k+1);
				flag[k] = 1;
		
			
			//if no nodes indegree is zero
			for(i=0;i<n;i++)
				if(a[k][i] == 1)
				{
					//printf("\ni,k = %d,%d\n",i,k);
					indeg[i]--;
				}
				break;
			
			}
		}
		count++;
	}
}
