#include <stdio.h>

int main(void)
{
	int i;
	int j;

	for(i = 0; i < 10; i++)
	{
		for(j = 0; j < 20; j++)
		{
			printf("*");
		}
		printf("\n");
	}
	return (0);
}
