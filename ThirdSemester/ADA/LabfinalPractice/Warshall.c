#include<stdio.h>
void main()
{

	int p[10][10],i,j,k,n;
	
	printf("\nEnter number of vertices : ");
	scanf("%d",&n);
	
	printf("\nEnter adjacency matrix : \n");
	for(i=0;i<n;i++)
		for(j=0;j<n;j++)
			scanf("%d",&p[i][j]);
			
	
	for(k=0;k<n;k++)
		for(i=0;i<n;i++)
			for(j=0;j<n;j++)
				if(p[i][j] == 0 && p[i][k] == 1 && p[k][j] == 1)
					p[i][j] = 1;
					
	printf("\nTransitive closure\n");
	for(i=0;i<n;i++)
	{
		printf("\n");
		for(j=0;j<n;j++)
			printf("%d\t",p[i][j]);
	}
}
