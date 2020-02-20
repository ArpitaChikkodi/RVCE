#include<stdio.h>
void main()
{
	int cost[10][10],visited[10]={0},ne=1;
	int i,j,a,b,u,v,n,s,min,mincost=0;
	
	printf("\nEnter number of vertices : ");
	scanf("%d",&n);
	
	printf("\nEnter adjacency matrix : ");
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=n;j++)
		{
			scanf("%d",&cost[i][j]);
			if(cost[i][j] == 0)
				cost[i][j] = 999;
		}
	}
	
	printf("\nEnter source : ");
	scanf("%d",&s);

	visited[s] = 1;
	
	while(ne<n)
	{
		for(i=1,min=999;i<=n;i++)
		{
			for(j=1;j<=n;j++)
			{
				if(cost[i][j]<min && visited[i]!=0)
				{
					min = cost[i][j];
					a=u=i;
					b=v=j;
				}
			}
		}
		
		if(visited[u]==0 || visited[v]==0)
		{
			printf("\nEdge %d(%d,%d) cost is %d",ne++,a,b,min);
			mincost += min;
			visited[b] = 1; //b
		}
		cost[a][b]=cost[b][a]=999; //after adding it should not be considered again so make it 999
	}
	printf("\nTotal minimum cost is %d",mincost);
}


/*
0 3 1 6 0 0
3 0 5 0 3 0
1 5 0 5 6 4
6 0 5 0 0 2
0 3 6 0 0 6
0 0 4 2 6 0

cost = 13
*/
