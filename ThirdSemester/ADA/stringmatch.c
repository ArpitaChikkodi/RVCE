#include<stdio.h>
#include<time.h>
#include<string.h>
char str[1000],pat[10];

int string_match()
{
	int n,m,k,i;
	n = strlen(str);
	m = strlen(pat);
	for(i=0;i<=(n-m);i++)
	{
		k=0;
		while(k<m && str[i+k]==pat[k])
		{
			k++;
			if(k==m)
				return i;
		}
	}
	return -1;
}

void main()
{
	int n,pos,k;
	float t1,t2;
	struct timeval begin,end;
	FILE *fp;
	fp = fopen("string.txt","a+");
	for(k=0;k<2;k++)
	{
		printf("\nEnter string : ");
		gets(str);
		n = strlen(str);
		
		printf("\nEnter pattern for best case : ");
		gets(pat);
		
		gettimeofday(&begin,NULL);
		pos = string_match();
		gettimeofday(&end,NULL);
		
		if(pos == -1)
			printf("\nNot found!\n");
		else
			printf("\nFound at position %d \n",pos+1);
			
		t1 = end.tv_usec - begin.tv_usec;
		
		printf("\nEnter pattern for worst case : ");
		gets(pat);
		
		gettimeofday(&begin,NULL);
		pos = string_match();
		gettimeofday(&end,NULL);
		
		if(pos == -1)
			printf("\nNot found!\n");
		else
			printf("\nFound at position %d \n",pos+1);
		
		t2 = end.tv_usec-begin.tv_usec;
		printf("\nTime taken by %d length is %1.2f and %1.2f\n",n,t1,t2);
		fprintf(fp,"%d \t %1.2f \t %1.2f \n",n,t1,t2);
	}
	fclose(fp);
}
