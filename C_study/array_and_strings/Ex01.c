#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int main(void)
{
	int i;
	int num[10];

	srand(time(NULL));

	for(i = 0; i < 10; i++)
		num[i] = 1 + rand() % 99;
	printf("\n");
	for(i = 0; i < 10; i++)
		printf("%d ", num[i]);
	printf("\n");
	return (0);
}
