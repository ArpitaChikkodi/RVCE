#include<stdio.h>
#include<sys/time.h>
#include<sys/file.h>
#include<string.h>
char str[1000],pat[20];

int string_match()
{
	int i,k,m,n;
	m = strlen(pat);
	n = strlen(str);
	for(i=0;i<=(n-m);i++)
	{
		k=0;
		while(k<m && str[i+k]==pat[k])
		{
			k++;
			if(k==m)
			{
				printf("\ni value is %d",i);
				return i;
			}
		}
	}	
	return -1;
}

void main()
{
	int k,pos,n;
	float t1,t2;
	FILE *fp;
	struct timeval begin,end;
	fp = fopen("string1.txt","a+");
	for(k=0;k<2;k++)
	{
		printf("\nEnter string or text : \n");
		gets(str);
		n = strlen(str);
		printf("\nEnter best case pattern to search : ");
		gets(pat);
		
		gettimeofday(&begin,NULL);
		pos  = string_match();
		gettimeofday(&end,NULL);
		t1 = end.tv_usec-begin.tv_usec;
		if(pos==-1)
			printf("\nNot found!");
		else
			printf("\nfound at %d",pos+1);
		
		printf("\nEnter worst case pattern to search : ");
		gets(pat);
		
		gettimeofday(&begin,NULL);
		pos2 = string_match();
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
