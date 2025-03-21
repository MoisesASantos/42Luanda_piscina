#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void)
{
	int i, j, num1[25], num2[25], num3[25];
	srand(time(NULL));
	for(i = 0; i < 25; i++)
	{
		num1[i] = rand() % 10;
		num2[i] = rand() % 10;
		num3[i] = num1[i] + num2[i];
	}
	for(i = 0; i < 25; i++)
		printf("%2d ", num1[i]);	
	printf("\n");
	for(i = 0; i < 25; i++)
		printf("%2d ", num2[i]);
	printf("\n");
	for(i = 0; i < 25; i++)
		printf("%2d ", num3[i]);
	printf("\n");
	return (0);
}
