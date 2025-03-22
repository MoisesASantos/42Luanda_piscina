#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void)
{
	int i, j, array[4][4];
	srand(time(NULL));
	for(i = 0; i < 4; i++)
	{
		for(j = 0; j < 4; j++)
			array[i][j] = 1 + rand() % 10;
	}
	for(i = 0; i < 4; i++)
        {       
                for(j = 0; j < 4; j++)
                      printf("%2d ", array[i][j]);
		printf("\n");
        }
	printf("\n");
	for(i = 1; i < 4; i++)
        {
		for(j = 0; j < i; j++)
                	printf("%2d ", array[i][j]);
        }
	printf("\n");
	return (0);
}


