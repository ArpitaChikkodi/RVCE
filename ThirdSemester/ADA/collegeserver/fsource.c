#include<stdio.h>
void main()
{
	FILE *fp = fopen("fsource.c","r");
	while(fgetc(fp)!=EOF)
	{
		char c = fgetc(fp);
		putchar(c);
	}
	fclose(fp);
}
