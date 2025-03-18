#include <stdio.h>

int main(void)
{
	float chico = 1.50;
	float ze = 1.10;
	unsigned long count = 0UL;

	while(chico >= ze)
	{
		chico = chico + 0.02;
		ze = ze + 0.03;
		count++;
	}
	printf("São preciso %lu anos para Zé ser maior que o chico\n", count);
	return (0);
}
