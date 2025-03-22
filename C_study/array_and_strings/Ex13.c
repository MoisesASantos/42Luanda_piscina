#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void)
{
	int i, j, array[5][5];
	srand(time(NULL));
	for(i = 0; i < 5; i++)
	{
		for(j = 0; j < 5; j++)
			array[i][j] = 1 + rand() % 10;
	}
	for(i = 0; i < 5; i++)
        {       
                for(j = 0; j < 5; j++)
                      printf("%2d ", array[i][j]);
		printf("\n");
        }
	printf("\n");
	j = 5;
	for(i = 0; i < 5; i++)
	{	
		--j;
		printf("%2d ", array[i][j]);
	}
	printf("\n");
	return (0);
}

