#include <stdio.h>

int main(void)
{
	int total;
	int i;
	int dinheiro;
	double total_real;

	total = 1;
	dinheiro = 1;
	for(i = 2; i <= 30; i++)
	{
		dinheiro *= 2;
		total += dinheiro;
	}
	total_real = total / 100.00;
	printf("O total de dinheiro acomulado é %.2f\n", total_real);
	return (0);
}
