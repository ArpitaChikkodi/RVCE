
#include<stdio.h>
//#include<conio.h>
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

        int pos,iter,k;
        float t1,t2;
        struct timeval begin,end;
        f1 = fopen("patternfile2.txt","w");
        printf("\nString pattern matching\n");

//        printf("\nEnter number of iterations : ");
//p:    scanf("%d",&iter);

//      if(iter<=0)
//      goto p;
//      scanf("%s",&str);


        for(k=0;k<2;k++)
        {
         printf("\nEnter string : \n");
        gets(str);

        n = strlen(str);
        printf("\nEnter pattern for best case : ");
        gets(pat);

        gettimeofday(&begin,0);
        pos = string_pattern();
        gettimeofday(&end,0);
 // if(pos!=-1)
        //        printf("\n%s is found at position %d\n",pat,pos);
        //else
          //      printf("\n%s is not found in the given string %s\n",pat,str);
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


