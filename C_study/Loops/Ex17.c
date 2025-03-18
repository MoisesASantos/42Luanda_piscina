#include <stdio.h>

int main(void)
{
	int number1;
	int number2;
	int result;
	int i;

	printf("Digite o primeiro número: ");
	scanf("%d", &number1);
	printf("Digite o segunto número: ");
	scanf("%d", &number2);
	result = 0;
	for(i = 1; i <= number2; i++)
	{
		result += number1;
	}
	printf("O resultado de %d * %d = %d\n", number1, number2, result);
	return (0);
}
