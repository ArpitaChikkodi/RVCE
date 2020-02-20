#include<stdio.h>
int min(int g[10][10],int n,int sn)  //sn is source node
{
	int cost[10][10],dist[10],prev[10],v[10];
	int count,i,j,mindist,nextnode;
	
	for(i=0;i<n;i++)
		for(j=0;j<n;j++)
			if(g[i][j]==0)
				cost[i][j]=999;  //infinity
			else
				cost[i][j] = g[i][j];
				
	for(i=0;i<n;i++)
	{
		dist[i] = cost[sn][i];  //initial cost from source to all other nodes
		v[i]=0;          //visited is 0 for all
		prev[i] = sn;       //initial previous of all nodes is source node
	}
	
	dist[sn]=0;  //source to source is 0
	v[sn]=1;     //visited source
	count=1;		//so count=1
	
	while(count<n-1)
	{
		mindist = 999; //initial mindist is 999 or infinity
		
		for(i=0;i<n;i++)
			if(!v[i] && dist[i]<mindist)
			{
				mindist = dist[i];
				nextnode = i;	      //select it as nextnode
			}	
			
		v[nextnode] =1;       //make it visited
		
		//any other path? if so take it as dist and make it previous 
		for(i=0;i<n;i++)
			if(!v[i] && (mindist+cost[nextnode][i])<dist[i] )
			{
				dist[i] = mindist + cost[nextnode][i];
				prev[i] = nextnode;
			}
			
		count++;   //increment count
	}
	
	//Print solution
	
	for(i=0;i<n;i++)
		if(i!=sn)  //not source node
		{
			printf("\nDistance of %d is %d",i,dist[i]);
			printf("\nPath is %d",i);
			j=i;
			do
			{
				j= prev[j];
				printf("<-%d",j);
			}while(j!=sn);
			
		}
		printf("\n");
	
}

void main()
{
	int g[10][10],n,u,i,j ;
	printf("\nEnter number of nodes: ");
	scanf("%d",&n);
	
	printf("\nEnter adjacency matrix : \n");
	for(i=0;i<n;i++)
			for(j=0;j<n;j++)
				scanf("%d",&g[i][j]);

	printf("\nEnter source node: ");
	scanf("%d",&u);
	
	min(g,n,u);
}
