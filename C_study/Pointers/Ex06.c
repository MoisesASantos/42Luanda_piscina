#include <stdio.h>

void	troca(float *a, float *b)
{
	float temp;

	printf("O valor de a = %.2f\n O valor de b = %.2f\n", *a, *b);
	temp = *a;
	*a = *b;
	*b = temp;
	printf("O valor de a = %.2f\n O valor de b = %.2f\n", *a, *b);
}

int main(void)
{
	float a = 3.50;
	float b = 4.50;
	troca(&a, &b);
	return (0);
}
