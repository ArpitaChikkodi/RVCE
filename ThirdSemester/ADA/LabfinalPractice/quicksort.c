#include<stdio.h>
#include<time.h>
//#include<sys/time.h>
int a[500];
int partition(int l,int h)
{
	int temp,i,j,pivot;
	pivot = a[l];
	i = l;
	j = h;
	while(i<=j)
	{
		while(a[i]<=pivot && i<=h)
			i++;
		while(a[j]>pivot && j>=l)
			j--;
		if(i<j)
		{
			temp = a[i];
			a[i] = a[j];
			a[j] = temp;
		}
		else
		{
			
			temp = a[l];
			a[l] = a[j];
			a[j] = temp;
		}
	}
	return j;
}
void quicksort(int l,int h)
{
	if(l<h)
	{
		int j = partition(l,h);
		quicksort(l,j-1);
		quicksort(j+1,h);
	}
}

void main()
{
	int p,q,n,m;
	FILE *fp;
	float t1;
	struct timeval begin,end;
	fp = fopen("quick.txt","a+");
	printf("\nEnter number of iterations : \n");
	scanf("%d",&m);
	for(q=0;q<m;q++)
	{
	
	printf("\nEnter number of elements : \n");
	scanf("%d",&n);
	srand(time(0));
	for(p=0;p<n;p++)
	{
		a[p] = rand()%100;
		printf("%d,",a[p]);
	}
	
	gettimeofday(&begin,NULL);
	quicksort(0,n-1);
	gettimeofday(&end,NULL);
	printf("\nAfter sorting : ");
	for(p=0;p<n;p++)
	{
		printf("%d,",a[p]);
	}
	t1 = end.tv_usec - begin.tv_usec;
	printf("\nTime taken is %1.2f",t1);
	fprintf(fp,"%d \t %1.2f \n",n,t1);
	}
	fclose(fp);
}
