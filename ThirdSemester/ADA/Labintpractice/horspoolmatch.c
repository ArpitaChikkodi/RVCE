#include<stdio.h>
#include<string.h>
#include<sys/time.h>
int table[127];

void shifttable(char pat[])
{
	int m,j;
	m=strlen(pat);
	
	for(j=0;j<127;j++)
		table[j]=m;          //initially store length of pattern
		
	for(j=0;j<=m-2;j++)      //except last chracter calculate shift values for all
		table[pat[j]] = m-1-j;         //ascii value
}

int horspoolmatch(char text[],char pat[])
{
	int i,k,m,n;
	n = strlen(text);
	m = strlen(pat);
	i = m-1;
	while(i<=n-1)
	{
		k=0;
		while(k<m && text[i-k]==pat[m-1-k])
			k++;
		
		if(k==m)
			return i-m+1;
			
		else
			i = i+table[text[i]];
	}
	return -1;
}

void main()
{
	int k,pos,n;
	float t1,t2;
	FILE *fp;
	struct timeval begin,end;
	char text[1000],pat[20];
	fp = fopen("stringhorspool.txt","a+");
	for(k=0;k<2;k++)
	{
		printf("\nEnter string or text : \n");
		gets(text);
		n = strlen(text);
		printf("\nEnter best case pattern to search : ");
		gets(pat);
		
		gettimeofday(&begin,NULL);
		shifttable(pat);
		pos  = horspoolmatch(text,pat);
		gettimeofday(&end,NULL);
		t1 = end.tv_usec-begin.tv_usec;
		if(pos==-1)
			printf("\nNot found!");
		else
			printf("\nfound at %d",pos+1);
		
		printf("\nEnter worst case pattern to search : ");
		gets(pat);
		
		gettimeofday(&begin,NULL);
		shifttable(pat);
		pos  = horspoolmatch(text,pat);
		gettimeofday(&end,NULL);
		t2 = end.tv_usec-begin.tv_usec;
		
		if(pos==-1)
			printf("\nNot found!");
		else
			printf("\nfound at %d",pos+1);
			
		printf("\n%d \t %f \t %f\n",n,t1,t2);
		fprintf(fp,"%d \t %f \t %f\n",n,t1,t2);
	}
	fclose(fp);
}
