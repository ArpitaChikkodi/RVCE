#include<stdio.h>
#include<sys/time.h>
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
			temp =a[i];
			a[i]=a[j];
			a[j]=temp;
			
		}	
		else
		{
			temp=a[l];
			a[l]=a[j];
			a[j]=temp;
		}
	}	
	return j;
}

void main()
{
	int n,p,k,it;
	float t;
	FILE *fp;
	struct timeval begin,end;
	fp = fopen("quick.txt","a+");
	printf("\nEnter number of iterations : ");
	scanf("%d",&it);
	
	for(k=0;k<it;k++)
	{
		printf("\nEnter number of elements : \n");
		scanf("%d",&n);
		srand(-1);
		
		for(p=0;p<n;p++)
		{
			a[p]=rand()%1000;
			printf("%d\t",a[p]);
		}
		
		gettimeofday(&begin,NULL);
		quicksort(0,n-1);
		gettimeofday(&end,NULL);
		printf("\nSorted elements are : \n");
		for(p=0;p<n;p++)
			printf("%d\t",a[p]);
		t = end.tv_usec-begin.tv_usec;
		printf("\nTime taken to sort is %1.3f",t);
		fprintf(fp,"%d \t %1.3f \n",n,t);
	}
	fclose(fp);
}
