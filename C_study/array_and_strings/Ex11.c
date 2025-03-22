#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void)
{
	int i, j;
	int A[3][3], B[3][3], C[3][3];
	srand(time(NULL));
	for(i = 0; i < 3; i++)
	{
		for(j = 0; j < 3; j++)
		{
			A[i][j] = 1 + rand() % 10;
			B[i][j] = 2 + rand() % 10;
		}
	}
	for(i = 0; i < 3; i++)
	{
		for(j = 0; j < 3; j++)
		{
			C[i][j] = A[i][j] + B[i][j];
		}
	}
	for(i = 0; i < 3; i++)
	{
		for(j = 0; j < 3; j++)
			printf("%2d ", A[i][j]);
		printf("\n");
	}
	printf("\n");
	for(i = 0; i < 3; i++)
        {
                for(j = 0; j < 3; j++)
                        printf("%2d ", B[i][j]);
                printf("\n");
        }
	printf("\n");
	for(i = 0; i < 3; i++)
        {
                for(j = 0; j < 3; j++)
                        printf("%2d ", C[i][j]);
                printf("\n");
        }
	return (0);
}
