#include<stdio.h>
void main()
{
	int a,b,i,j,u,v,n,min,mincost=0,ne=1;
	int cost[10][10],visited[10]={0};
	
	printf("\nEnter number of vertices : ");
        scanf("%d",&n);

        printf("\nEnter adjacency matrix : \n");
        for(i=1;i<=n;i++)
        {
                for(j=1;j<=n;j++)
                {
                        scanf("%d",&cost[i][j]);
                        if(cost[i][j]==0)
                        	cost[i][j]=999;
                }
        }
        visited[1]=1;
        
        while(ne<n)
        {
        	for(i=1,min=999;i<=n;i++)
        	{
                for(j=1;j<=n;j++)
                {
                	if(cost[i][j]<min && visited[i]!=0)
                	{
                		min = cost[i][j];
                		a = u =i;
                		b=v=j;
					}
				}
			}
			
			if(visited[u]==0 || visited[v]==0)
			{
				printf("\nEdge %d(%d->%d) is cost %d",ne++,a,b,min);
				mincost+=min;
				visited[b]=1;
			}
			
			cost[a][b]=cost[b][a]=999;
			
		}
		
		printf("\nMincost is %d",mincost);
}
