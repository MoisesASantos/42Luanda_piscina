#include <stdio.h>

int main(void)
{
	int opcao;
	float valor_original;
	float valor_real;
	float valor_dolar;

	printf("Digite 1 para real ou Digite 2 para Dólar: ");
	scanf("%d", &opcao);
	if(opcao == 1)
	{
		printf("Digite o valor em real: ");
		scanf("%f", &valor_original);
		valor_dolar = valor_original / 5.30;
		printf("O valor do real em dólar são %.2f\n", valor_dolar);
	}
	if(opcao == 2)
	{
		printf("Digite o valor em dolar: ");
                scanf("%f", &valor_original);   
                valor_real = valor_original * 5.30;
                printf("O valor do real em dólar são %.2f\n", valor_real);
	}
	return (0);
}

