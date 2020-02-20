#include<stdio.h>
#include<string.h>
//#include<sys/time.h>
#include<time.h>
int table[127];

void shifttable(char pat[])
{
	int m,j;
	m = strlen(pat);
	
	for(j=0;j<127;j++)
		table[j] = m;
	for(j=0;j<=m-2;j++)
		table[pat[j]] = m-1-j;
}

int horspool(char text[],char pat[])
{
	int i,k,m,n;
	n = strlen(text);
	m = strlen(pat);
	i = m-1;
	while(i<=n-1)
	{
		k = 0;
		while(k<m && text[i-k]==pat[m-1-k])
			k++;
		if(k==m)
			return i-m+1;
		else
			i = i + table[text[i]];
	}
	return -1;
}

void main()
{
	int n,j,pos;
	float t1,t2;
	struct timeval begin,end;
	FILE *fp;
	char text[1000],pat[20];
	fp = fopen("horspoolstring.txt","a+");
	for(j=0;j<2;j++)
	{
		printf("\nEnter text : \n");
		gets(text);
		
		printf("\nEnter pattern : \n");
		gets(pat);
		
		n = strlen(text);
		
		gettimeofday(&begin,NULL);
		shifttable(pat);
		pos = horspool(text,pat);
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
