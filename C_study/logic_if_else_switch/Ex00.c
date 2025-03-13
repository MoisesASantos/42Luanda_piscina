#include <stdio.h>

int	main(void)
{
	char	sexo;
	int	idade;
	float	altura, peso;

	printf("Digite o seu sexo(M, F)");
	scanf("%c", &sexo);
	printf("Digite a sua idade");
	scanf("%d", &idade);
	printf("Digite a sua altura");
	scanf("%f", &altura);
	printf("Digite o seu peso");
	scanf("%f", &peso);
	printf("O seu sexo é %c\n", sexo);
	printf("A sua idade é %d anos\n", idade);
	printf("A sua altura é %.2f metros\n", altura);
	printf("O seu peso é %.1f kilogramas\n", peso);
	return (0);
}
