#include<stdio.h>
#include<string.h>

int table[127];
void shift_table(char p[])
{
	int i,j,m;
	m=strlen(p);
	for (i=0;i<127;i++)
	  table[i]=m;
	for (j=0;j<m-1;j++)
	{
		table[p[j]]=m-1-j;
		printf("j %d	pat[j] %c	table[p[j]] %d\n",j,p[j],table[p[j]]);
	}
}

int horspool(char text[],char p[])
{
	int i,j,k,m,n;
	n=strlen(text);
	m=strlen(p);
	printf("\nLength of text=%d",n);
	printf("\n Length of pattern=%d",m);
	i=m-1;
	while(i<n)
	{
		k=0;
		while((k<m)&&(p[m-1-k]==text[i-k]))
		   k++;
		if(k==m)
		   return(i-m+1); else
		   i+=table[text[i]];
	}
	return -1;
}

void main() 
{
	char text[100],pat[100];
	int pos;

	printf("Enter the text in which pattern is to be searched:\n");
	gets(text);
	printf("Enter the pattern to be searched:\n");
	gets(pat);
	shift_table(pat);
	pos=horspool(text,pat);
	if(pos>=0)
	  printf("\n The desired pattern was found starting from position %d",pos+1); 
	else
	  printf("\n The pattern was not found in the given text!\n");

}
