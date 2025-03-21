#include <stdio.h>

int main(void)
{
	int i, num1[10], num2[10];

	for(i = 0; i < 10; i++)
	{
		printf("Digite o valor da posição %d: ", i);
		scanf("%d", &num1[i]);
		printf("\n");
	}
	for(i = 0; i < 10; i++)
	{	
		num2[i] = num1[i] * 2;
	}
	for(i = 0; i < 10; i++)
		printf("%2d ", num1[i]);
	printf("\n");
	for(i = 0; i < 10; i++)
		printf("%2d ", num2[i]);
	printf("\n");
	return (0);
}
