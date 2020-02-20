#include<stdio.h>
int n,p[10][10];
int min(int a,int b){ return (a<b)?a:b; }
void path()
{
	int i,j,k;
	for(k=0;k<n;k++)
		for(i=0;i<n;i++)
			for(j=0;j<n;j++)	
				if(i==j)
					p[i][j] = 0;
				else
					p[i][j] = min(p[i][j],p[i][k]+p[k][j]);
}

void main()
{
	int i,j;
	printf("\nEnter number of nodes: ");
	scanf("%d",&n);
	
	printf("\nEnter adjacency matrix : \n");
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)	
		{
			scanf("%d",&p[i][j]);
			if(p[i][j]==0 && i!=j)
				p[i][j]=999;
		}
	}
	path();
	
	printf("\nResulting matrix \n");
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{	
			printf("%d ",p[i][j]);
		}
		printf("\n");
	}
	
	//Path from each node
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			if(i!=j)
			{
				if(p[i][j]==999)
					printf("\nDistance of %d to %d is infinity",i+1,j+1);
				else
					printf("\nDistance of %d to %d is %d",i+1,j+1,p[i][j]);
			}
		}
	}
}
