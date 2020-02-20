#include <stdio.h>
#define TRUE 1
#define FALSE 0
int inc[50], w[50], sum, n;

void sumset(int, int, int);
int promising(int i, int weight, int total)
{
	return (((weight + total) >= sum) && ((weight == sum) || (weight + w[i + 1] <= sum)));
}

void sumset(int i, int weight, int total)
{
	int j;
	if (promising(i, weight, total))
	{
		if (weight == sum)
		{
			printf("\n{  ");
			for (j = 0; j <= i; j++)
				if (inc[j])
					printf("%d  ", w[j]);
			printf("}\n");
		}
		else
		{
			inc[i + 1] = TRUE;
			sumset(i + 1, weight + w[i + 1], total - w[i + 1]);
			inc[i + 1] = FALSE;
			sumset(i + 1, weight, total - w[i + 1]);
		}
	}
}
void main()
{
	int i, j, n, temp, total = 0;
	printf("\n Enter how many numbers:\n");
	scanf("%d", &n);
	printf("\n Enter %d numbers to the set in ascending order:\n", n);
	for (i = 0; i < n; i++)
	{
		scanf("%d", &w[i]);
		total += w[i];
	}

	printf("\n The given %d numbers in ascending order:\n", n);
	for (i = 0; i < n; i++)
		printf("%d \t", w[i]);

	printf("\n Input the sum value to create sub set:\n");
	scanf("%d", &sum);

	if (total < sum)
		printf("\n Subset construction is not possible");
	else
	{
		for (i = 0; i < n; i++)
			inc[i] = 0;
		printf("\n The solution using backtracking is:\n");
		sumset(-1, 0, total);
	}
}
