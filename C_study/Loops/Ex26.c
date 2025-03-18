#include <stdio.h>

int main(void)
{
	int i;
	int j;
	int k;

	for(i = 1; i < 10; i+=2)
	{
		k = 0;
		for(j = i + 6; k < 3; j--)
		{
			printf("I = %d J = %d\n", i, j);
			k++;
		}
		printf("\n");
	}
	return (0);
}
