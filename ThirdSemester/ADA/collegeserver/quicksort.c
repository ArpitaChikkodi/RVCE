#include<stdio.h>
//#include<sys/time.h>
#include<time.h>
int a[1000];
void quicksort(int l,int h)
{
        if(l<h)
        {
                int k = partition(l,h);
                quicksort(l,k-1);
                quicksort(k+1,h);
        }
}

int partition(int l,int h)
{
        int pivot,i,j,temp;
        pivot=a[l];
        i=l;
        j=h;
        while(i<=j)
        {
                while(a[i]<=pivot && i<=h)
                        i++;
                while(a[j]>pivot && j>=l)
                        j--;

                if(i<j)
                {
//                      printf(" \t Before %d  %d",a[i],a[j]);
                        temp=a[i];
                        a[i]=a[j];
                        a[j]=temp;
//                      printf(" \tAfter %d %d",a[i],a[j]);
                }

        else
        {
//      printf("\n Pivot before : %d %d",pivot,a[j]);
        temp=a[l];
        a[l]= a[j];
        a[j]=temp;
//      printf("\n Pivot after : %d %d",pivot,a[j]);
        }
}
        return j;
}

void main()
{
        int n,k,p,it;
        float t;
        struct timeval tbegin,tend;
        FILE *fp;
        fp = fopen("quick.txt","a+");
        printf("\nEnter number of iterations : ");
        scanf("%d",&it);
        for(k=0;k<it;k++)
        {
        printf("\nEnter size of array : ");
        scanf("%d",&n);
        srand(0);
//      printf("\nArray elements are : \n");
 for(p=0;p<n;p++)
        {
                a[p] = rand()%100;
                printf("\t%d",a[p]);
        }
        gettimeofday(&tbegin,NULL); 	//does not work on windows, so use GetLocalTime() or GetSystemTime()
        quicksort(0,n-1);
        gettimeofday(&tend,NULL);
        t = tend.tv_usec-tbegin.tv_usec;
        printf("\nSorted array : \n");
        for(p=0;p<n;p++)
              printf("\t%d",a[p]);
        printf("\n");
        printf("\nTime taken for %d elements to sort is : %f\n",n,t);
        fprintf(fp,"\n%d \t %1.2f",n,t);
        }
}


