#include <stdio.h>

int main(void)
{
	int i = 3;
	int n;

	printf("Digite um number maior que 1: ");
	scanf("%d", &n);
	while(n <= 1)
	{
		printf("Digite um number maior que 1: ");
        	scanf("%d", &n);
	}
	if(n == 2)
	{
		printf("O number é primo\n");
		return (0);
	}
	if (n > 2 && n % 2 == 0)
	{
        	printf("O número não é primo.\n");
        	return (0);
    	}
	while( i * i <= n)
	{
		if(n % i == 0)
		{
			printf("O número não é primo\n");
			return (0);
		}
		i+=2;
	}
        printf("O número é primo\n");
i	return (0);
}
