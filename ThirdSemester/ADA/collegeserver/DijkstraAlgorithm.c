#include<stdio.h>
void min(int g[10][10],int n,int sn)
{
        int cost[10][10],v[10],prev[10];
        int count,mindist,nextnode,i,j,dist[10];

        for(i=0;i<n;i++)
          for(j=0;j<n;j++)
                if(g[i][j] == 0)
                        cost[i][j] = 999;
                else
                        cost[i][j] = g[i][j];


        for(i=0;i<n;i++)
        {
                dist[i]=cost[sn][i];
                prev[i]=sn;
                v[i]=0;

        }

        dist[sn]=0;
        v[sn]=1;
        count=1;

        while(count < (n-1))
        {
                mindist = 999;
                for(i=0;i<n;i++)
                        if(dist[i]<mindist && !v[i])
                        {
                                mindist = dist[i];
                                nextnode = i;
                        }
 				
				v[nextnode]=1;
                for(i=0;i<n;i++)
                  if(!v[i] && (mindist+cost[nextnode][i]) < dist[i])          
                  	{
                                dist[i] = mindist + cost[nextnode][i];
                                prev[i] = nextnode;
                    }
                count++;
        }

        //Printing
        for(i=0;i<n;i++)
           if(i!=sn)
           {
                printf("\nDistance of node %d is %d",i,dist[i]);
                printf("\nPath is %d",i);
                j=i;
                do
                {
                        j = prev[j];
                        printf(" <- %d",j);
                }while(j!=sn);
            }
        printf("\n");
}

void main()
{
        int g[10][10],n,u,i,j;
        printf("\nEnter number of vertices : ");
        scanf("%d",&n);

        printf("\nEnter adjacency matrix \n");
        for(i=0;i<n;i++)
        {
                for(j=0;j<n;j++)
                {
                        scanf("%d",&g[i][j]);
                }
        }

        printf("\nEnter source : ");
        scanf("%d",&u);

        min(g,n,u);
}


