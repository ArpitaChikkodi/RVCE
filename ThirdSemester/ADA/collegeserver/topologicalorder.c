#include<stdio.h>
#include<stdlib.h>
int main()
{
        int a[10][10],indeg[10],flag[10];
        int count=0,n,i,j,k;
        printf("\nEnter number of vertices : ");
        scanf("%d",&n);

        for(i=0;i<n;i++)
        {
                printf("\nEnter %d row elements : ",i+1);
                for(j=0;j<n;j++)
                {
                        scanf("%d",&a[i][j]);
                        if(i==j)
                        {
                                if(a[i][j]!=0)
                                {
                                        printf("\nThe graph has loops!Enter acyclic graph!\n");
                                        exit(0);
                                }
                        }
                }
        }

        for(i=0;i<n;i++)
        {
                indeg[i]=0;
                flag[i]=0;
                for(j=0;j<n;j++)
                {
                        if(i!=j && a[i][j]==a[j][i] && a[i][j]==1)
                        {
                                printf("\nGraph has loops!Enter acyclic graph!\n");
                                exit(0);
                        }
                }
        }

 //column is fixed row is changing
        for(i=0;i<n;i++)
              for(j=0;j<n;j++)
                    indeg[i]=indeg[i]+a[j][i];


        printf("\nOrdering of vertices is : \n");
        while(count<n)
        {
                for(k=0;k<n;k++)
                {
                        if(indeg[k]==0 && flag[k]==0)
                        {
                                printf("%d  ",k+1);
                                flag[k]=1;
                        }

                        for(i=0;i<n;i++)
                        {
                                if(a[i][k]==1)
                                {
                                        indeg[k]--;
				   				}
                        }
                }
                count++;
        }
        return 0;
}



