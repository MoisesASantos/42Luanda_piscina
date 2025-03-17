#include <stdio.h>

int main(void)
{
	int senha;
	int senha_digit;
	int i;

	senha = 123456;
	i = 0;
	do{
		printf("Digite a senha: ");
		scanf("%d", &senha_digit);
		if(senha == senha_digit)
		{
			printf("Acesso permitido\n");
		}
		else
		{
			printf("Senha Invalida\n");
			i++;
		}
		if( i == 3)
		{
			printf("Máximo de tentativas tentada, vc foi bloqueado\n");
			return (0);
		}
	}while(senha != senha_digit);
	return (0);
}
