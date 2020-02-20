#include<stdio.h>
int min(int a,int b){ return (a<b)?a:b; }
void main()
{

	int p[10][10],i,j,k,n;
	
	printf("\nEnter number of vertices : ");
	scanf("%d",&n);
	
	printf("\nEnter adjacency matrix : \n");
	for(i=0;i<n;i++)
		for(j=0;j<n;j++)
		{
			scanf("%d",&p[i][j]);
			if(p[i][j]==0 && i!=j)
				p[i][j] = 999;
		}
	
	//main
	for(k=0;k<n;k++)
		for(i=0;i<n;i++)
			for(j=0;j<n;j++)
			{
				if(p[i][j]==0 && i==j)
						p[i][j] = 0;
				else 
					p[i][j] = min(p[i][j],p[i][k]+p[k][j]);
			}
			
			
	printf("\nTransitive closure\n");
	for(i=0;i<n;i++)
	{
		printf("\n");
		for(j=0;j<n;j++)
			printf("%d\t",p[i][j]);
	}
	
	//Path
	for(i=0;i<n;i++)
			for(j=0;j<n;j++)
				if(i!=j)
				{
					if(p[i][j]==999)
						printf("\n %d--%d is infinite!\n",i+1,j+1);
					else
						printf("\n %d--%d is %d\n",i+1,j+1,p[i][j]);
				}
}
