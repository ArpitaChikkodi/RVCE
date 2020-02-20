#include<stdio.h>
#include<string.h>
#include<time.h>
//#include<sys/time.h>

char text[1000],pat[20];

int stringmatch()
{
	int m,n,k,i;
	m = strlen(pat);
	n = strlen(text);
	for(i=0;i<=n-m;i++)
	{
		k = 0;
		while(k<m && text[i+k]==pat[k])
		{
			k++;
			if(k==m)
				return i;
		}
	}
	return 1;
}
void main()
{
	int n,j,pos;
	float t1,t2;
	struct timeval begin,end;
	FILE *fp;
	fp = fopen("string.txt","a+");
	for(j=0;j<2;j++)
	{
		printf("\nEnter text : \n");
		gets(text);
		
		printf("\nEnter pattern : \n");
		gets(pat);
		
		n = strlen(text);
		
		gettimeofday(&begin,NULL);
		pos = stringmatch();
		gettimeofday(&end,NULL);
		
		t1 = end.tv_usec - begin.tv_usec;
		
		if(pos == -1)
			printf("\nNot found!");
		else
			printf("\nFound at position %d",pos+1);
			
		fprintf(fp,"%d \t %1.2f \n"); 
	}
	fclose(fp);
}
