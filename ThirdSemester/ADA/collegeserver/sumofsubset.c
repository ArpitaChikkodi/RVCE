#include<stdio.h>
#include<stdlib.h>
#define TRUE 1
#define FALSE 0
int inc[50],w[50],sum,n,flag=0;

int promising(int i,int wt,int total)
{
        //printf("%d",wt);
        return (((wt+total)>=sum) && ((wt==sum) || (wt+w[i+1]<=sum)));

}

void sumset(int i,int wt,int total)
{

        int j;
        if(promising(i,wt,total))
        {
           if(wt==sum)
           {
                flag = 1;
                //Print solution
                printf("\n{ ");
                for(j=0;j<=i;j++)
                    if(inc[j])
                        printf("%d  ",w[j]);
                printf("}\n");
           }
           else
          {
                inc[i+1] = TRUE;
                sumset(i+1,wt+w[i+1],total-w[i+1]);
                inc[i+1] = FALSE;
                sumset(i+1,wt,total-w[i+1]);
          }
        }
}


void main()
{
        int i,j,n,temp,total=0,prev=-1;
        printf("\nEnter how many numbers : ");
        scanf("%d",&n);
        printf("\nEnter %d unique numbers in ascending order : ",n);
        for(i=0;i<n;i++)
        {
                p:scanf("%d",&w[i]);
                if(w[i]!=prev)
                        prev=w[i];
                else
                {
                        printf("\nEnter unique value : ");
                        goto p;
                }
                total+=w[i];
        }
        printf("\nEnter sum : ");
        scanf("%d",&sum);

        if(total<sum)
 		printf("\nSubset construction not possible for given sum!");
        else
        {
            for(i=0;i<n;i++)
                inc[i]=0;
            printf("\nSolution is ");
        }
        sumset(-1,0,total);
        if(!flag)
           printf("not possible!");
}


