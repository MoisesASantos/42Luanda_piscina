#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int main(void)
{
	int i, j, total, numbr[5][7];
	srand(time(NULL));
	for(i = 0; i < 5; i++)
	{	
		for(j = 0; j < 7; j++)
			numbr[i][j] = 1 + rand() % 10;
	}
	total = 0;
	for( i = 0; i < 5; i++)
		for(j = 0; j < 7; j++)
			total += numbr[i][j];
	for(i = 0; i < 5; i++)
	{
		for(j = 0; j < 7; j++)
			printf("%2d ", numbr[i][j]);
		printf("\n");
	}
	printf("%d\n", total);
	return (0);
}
