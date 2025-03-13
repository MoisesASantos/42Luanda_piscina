#include <stdio.h>

int main(void)
{
	int opcao;

	printf("Digite a respectiva opção: ");
	scanf("%d", &opcao);
	switch(opcao)
	{
		case 1:
			printf("Janeiro\n");
			break ;
		case 2:
			printf("Fevereiro\n");
			break ;
		case 3:
			printf("Março\n");
			break ;
		case 4:
			printf("Abril\n");
			break ;
		default:
			printf("Não foi encontrado nenhum month\n");
	}
	return (0);
}
