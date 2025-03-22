#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void)
{
	int i, j, m, n, array[5][4], transp[4][5];
	srand(time(NULL));
	for(i = 0; i < 5; i++)
	{
		for(j = 0; j < 4; j++)
			array[i][j] = 1 + rand() % 10;
	}
	for(i = 0; i < 5; i++)
        {       
                for(j = 0; j < 4; j++)
                      printf("%2d ", array[i][j]);
		printf("\n");
        }
	printf("\n");
	m = 0;
	n = 0;
	for(i = 0; i < 5; i++)
	{	
		for(j = 0; j < 4; j++)
		{
			transp[j][i] = array[i][j];
		}	
	}
	for(i = 0; i < 4; i++)
        {
                for(j = 0; j < 5; j++)
                      printf("%2d ", transp[i][j]);
                printf("\n");
        }
	printf("\n");
	return (0);
}
