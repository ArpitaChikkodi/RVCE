#include<stdio.h>
#include<string.h>
#include<sys/file.h>
#include<sys/time.h>
int table[127];

void shift_table(char p[])
{
        int i,m,j;
        m = strlen(p);
        for(i=0;i<127;i++)
                table[i]=m;

        for(j=0;j<=m-2;j++)           //except last character
                table[p[j]] = m-1-j;

}


int horspool_match(char text[],char p[])
{
        int i,k,m,n;
        n = strlen(text);
        m = strlen(p);

        i=m-1;
        while(i<n)
        {
                k=0;
                while((k<m) && (p[m-1-k] == text[i-k]))
                        k++;

                if(k==m)
                        return i-m+1;
                else
                {
                        i += table[text[i]];
                        //printf("\n i = %d",i);
                }
        }
        return -1;
}


void main()
{
        FILE *fp;
        int pos,i,n;
        char text[1500],pat[50];
        float t1,t2;
        struct timeval begin,end;
        fp = fopen("horspooltext.txt","a");
        for(i=0;i<5;i++)
        {


          printf("\nEnter text string : ");
          gets(text);


          n = strlen(text);
	   printf("\nLength of text is %d",n);
          printf("\nEnter pattern for best case : ");
          gets(pat);

          gettimeofday(&begin,0);
          shift_table(pat);
          pos = horspool_match(text,pat);
          if(pos >= 0)
                printf("\nPattern is found in given text starting from position %d",pos+1);
          else
                printf("\nGiven pattern does not match! or not found!");
          gettimeofday(&end,0);

          t1 = (end.tv_usec-begin.tv_usec);


          printf("\nEnter pattern for worst case : ");
          gets(pat);

          gettimeofday(&begin,0);
          shift_table(pat);
pos = horspool_match(text,pat);
          if(pos >= 0)
                printf("\nPattern is found in given text starting from position %d",pos+1);
          else
                printf("\nGiven pattern does not match! or not found!");
          gettimeofday(&end,0);

          t2 = (end.tv_usec-begin.tv_usec);

          printf("\nTime taken by the algorithm is %fms and %fms\n",t1,t2);
          fprintf(fp,"\n%d \t %1.2f \t %1.2f",n,t1,t2);


        }
        fclose(fp);
}         /*if(pos >= 0)
                printf("\nPattern is found in given text starting from position %d",pos+1);
          else
                printf("\nGiven pattern does not match! or not found!");*/


