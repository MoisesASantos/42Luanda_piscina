#include <stdio.h>

int main(void)
{
	int valor;
	int negativos = 0;
	int positivos = 0;

	do{
		printf("Digite um valor: ");
		scanf("%d", &valor);
		if(valor < 0)
			negativos++;
		else if(valor > 0)
			positivos++;
	}while(valor != 0);
	printf("Positivos: %d\n", positivos);
	printf("Negativos: %d\n", negativos);
	return (0);
}
