#include <stdio.h>

int main(void)
{
	int	moeda = 1;
	int	i;
	unsigned long total = 0UL;
	

	for( i = 1; i <= 64; i++)
	{
		total += moeda;
		moeda *= 2;
	}
	printf("O total é de %lu graus\n", total);
	return (0);
}
