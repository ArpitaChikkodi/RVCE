#include<stdio.h>
void min(int g[10][10],int n,int sn)
{
	int cost[10][10],dist[10],prev[10],v[10];
	int count,i,j,nextnode,mindist;
	
	for(i=0;i<n;i++)
		for(j=0;j<n;j++)
			if(g[i][j]==0)
				cost[i][j] = 999;
			else
				cost[i][j] = g[i][j];
				
	for(i=0;i<n;i++)
	{
		dist[i] = cost[sn][i];        //initial dist is from source to all
		v[i] = 0;              //all nodes are unvisited
		prev[i] = sn;           //previous of all nodes is source initially
	}
	
	dist[sn] = 0;       //dist of source to source is 0
	v[sn] = 1;        //visited source
	count = 1;  //so count
	
	while(count<n-1)  //1 already visited
	{
		mindist = 999;             //initially set mindist as 999 or inifinity
		
		for(i=0;i<n;i++)
			if( !v[i] && dist[i]<mindist )
			{
				mindist = dist[i];      //take it as mindist
				nextnode = i;          //and select it as nextnode
			}
			
		v[nextnode] = 1;      //visit nextnode
		
		//search for better path
		for(i=0;i<n;i++)
			if( !v[i] && (mindist+cost[nextnode][i] < dist[i]))
			{
				dist[i] = mindist + cost[nextnode][i];         //change if better path exists
				prev[i] = nextnode;           //consider nextnode as prev
			}
			
		count++;           //increment count
	}
	
	//print solution
	for(i=0;i<n;i++)
		if(i!=sn) //i not source
		{
			printf("\nDistance of %d is %d ",i,dist[i]);
			printf("\nPath is %d",i);
			j = i;
			do
			{
				j = prev[j];
				printf("<-%d",j);
				
			}while(j!=sn);   //j not source
		}
		printf("\n");
}

void main()
{
	int g[10][10],i,j,n,u;
	printf("\nEnter number of nodes : ");
	scanf("%d",&n);
	
	printf("\nEnter adjacency matrix : ");
	for(i=0;i<n;i++)
		for(j=0;j<n;j++)
			scanf("%d",&g[i][j]);
			
	printf("\nEnter source node : ");
	scanf("%d",&u);
	
	min(g,n,u);
}
