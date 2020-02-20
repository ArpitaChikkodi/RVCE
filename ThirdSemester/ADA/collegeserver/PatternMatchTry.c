
#include<stdio.h>
#include<sys/file.h>
#include<string.h>
#include<sys/time.h>
char str[500],pat[10];
FILE *f1;
int m,n;
int string_pattern()
{
        int i,j;

        m = strlen(pat);

        for(i=0;i<=(n-m);i++)
        {
                j=0;
                while(j<m && pat[j]==str[i+j])
                {
                        j++;
                        if(j==m)
                           return i;
                }
        }
        return -1;
}
void main()
{

        int pos,iter,k,sl,p;
        float t1,t2;
        struct timeval begin,end;
        f1 = fopen("patternfile2.txt","w");
        printf("\nString pattern matching\n");

        for(k=0;k<2;k++)
        {
         printf("\nEnter string length : \n");
         scanf("%d",&sl);
                for(p=0;p<sl;p++)
                {
  str[p]=rand()%100;
                }

        n = strlen(str);
        printf("\nEnter pattern for best case : ");
        gets(pat);

        gettimeofday(&begin,0);		//does not work on windows, so use GetLocalTime() or GetSystemTime()
        pos = string_pattern();
        gettimeofday(&end,0);

       t1 = (end.tv_usec-begin.tv_usec);

        printf("\nEnter pattern for worst case : ");
        gets(pat);

        gettimeofday(&begin,0);
        pos = string_pattern();
        gettimeofday(&end,0);

        t2 = (end.tv_usec-begin.tv_usec);
 printf("\nTime taken by the algorithm is %fms and %fms\n",t1,t2);
        fprintf(f1,"\n%d \t %1.2f \t %1.2f",n,t1,t2);

        }
        fclose(f1);
}

/*
gnuplot
plot "patterntext.txt" using 1:2 with linespoints, "patterntext.txt" using 1:3 $
*/



