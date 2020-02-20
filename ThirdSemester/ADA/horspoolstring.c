#include<stdio.h>
#include<string.h>
void main()
{
	int shift_table[126];
	char text[100],pat[25];
	int n,i,k,j,m,flag=0;

	printf("Enter the text : ");
	gets(text);
	printf("%s",text);
	n=strlen(text);
	printf("Enter the pattern : ");
	gets(pat);
	m=strlen(pat);
	
	for(i=0;i<126;i++)
		shift_table[i]=m;


	for(j=0;j<m-2;j++)
	{
			shift_table[pat[j]]=m-1-j;
			printf("\nj - %d	pat[j] is %c 	shift_table[] - %d",j,pat[j],shift_table[pat[j]]);
	}
	i=m-1;
	while(i<=n-1)
	{
		k=0;
		while(k<=m-1 && pat[m-1-k]==text[i-k])
			k++;
		if(k==m)
		{
			printf("The position of the pattern is %d\n",i-m+2);
			flag=1;
			break;
		}
		else
			i=i+shift_table[text[i]];
	}
	if(!flag)
	printf("Pattern is not found in the given text ");
}
