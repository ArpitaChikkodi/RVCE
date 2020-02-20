#include<stdio.h>
int max(int a,int b) { return (a>b)?a:b; }
int knapsack(int W,int wt[],int val[],int n)
{
        int i,w,x[n], k[n+1][W+1],j;
        for(i=0;i<=n;i++)
        {
          for(w=0;w<=W;w++)
          {
                if(i==0 || w==0)
                    k[i][w] = 0;
                else if(wt[i-1] <= w)
                    k[i][w] = max(k[i-1][w] , k[i-1][w-wt[i-1]] + val[i-1]);   
                    k[i][w] = k[i-1][w];
          }
        }

        printf("\nProfit matrix");
        for(i=0;i<=n;i++)
        {
          if(i!=n)
                x[i] = 0;
          printf("\n");
          for(w=0;w<=W;w++)
                printf("%d\t",k[i][w]);
        }

        //selected items calculation
        i = n;
        w = W;
        while(i!=0 && w!=0)
        {
                if(k[i][w] != k[i-1][w])
                {
                        x[i]=1;
                        w = w - wt[i-1];
                }
                i--;
        }
 printf("\nSelected items\n");
        for(j=0;j<n;j++)
                printf("%d\t",wt[j]);

        printf("\n");

        for(j=1;j<=n;j++)
                printf("%d\t",x[j]);

        return k[n][W];
}

void main()
{
        int i,n,wt[20],val[20],W;
        printf("\nEnter number of items : ");
        scanf("%d",&n);

        printf("\nEnter value and weight of the elements ");
        for(i=0;i<n;i++)
                scanf("%d %d",&val[i],&wt[i]);

        printf("\nEnter capacity of knapsack : ");
        scanf("%d",&W);

        printf("\nTotal profit = %d\n",knapsack(W,wt,val,n));
}




