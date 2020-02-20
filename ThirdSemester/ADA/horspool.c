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
		table[j]= m; //initially fill length of pattern
	
	for(j=0;j<=m-2;j++) //except last character
		table[pat[j]] = m-1-j;
}

int horspoolmatch(char text[],char pat[])
{
	int m,n,i,k;
	m = strlen(pat);
	n = strlen(text);
	i = m-1; //m-1 to n-1
	while(i<=n-1)
	{
		k=0;
		while(k<m && text[i-k]==pat[m-1-k])
			k++;
			
		if(k==m)
			return i-m+1;  //return position
		else
			i = i + table[text[i]]; //shift
	}
	return -1; //not found
}

void main()
{
	int i,n,pos;
	float t1,t2;
	struct timeval begin,end;
	FILE *fp;
	char text[1000],pat[50];
	fp = fopen("horstring.txt","a+");
	for(i=0;i<2;i++)
	{
		printf("\nEnter string : \n");
		gets(text);
		n = strlen(text);
		
		printf("\nEnter best case pattern to be matched : ");
		gets(pat);
		
		gettimeofday(&begin,NULL);
		shifttable(pat);
		pos = horspoolmatch(text,pat);
		gettimeofday(&end,NULL);
		
		if(pos==-1)
			printf("\nNot found!\n");
		else
			printf("\nFound at position %d\n",pos+1);
			
		t1 = end.tv_usec - begin.tv_usec;
		
		printf("\nEnter worst case pattern to be matched : ");
		gets(pat);
		
		gettimeofday(&begin,NULL);
		shifttable(pat);
		pos = horspoolmatch(text,pat);
		gettimeofday(&end,NULL);
		
		if(pos==-1)
			printf("\nNot found!\n");
		else
			printf("\nFound at position %d\n",pos+1);
			
		t2 = end.tv_usec - begin.tv_usec;
		//printf("\nTime taken is %1.2f",t1);
		
		fprintf(fp,"%d \t %1.2f \t %1.2f \n",n,t1,t2);
	}
	fclose(fp);
}
