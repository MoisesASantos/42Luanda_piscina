#include <stdio.h>

int main(void)
{
	int option;
	int a;
	int b;
	int result;

	printf("1-Somar\n");
	printf("2-Subtrair\n");
	printf("3-Multiplicar\n");
	printf("4-Dividir\n");
	printf("0-Sair\n");
	do{	
		printf("Digite a sua opção: ");
        	scanf("%d", &option);
		switch(option){
			case 1:
				printf("Digite o primeiro e segundo valor: ");
				scanf("%d%d", &a, &b);
				result = a + b;
				printf("%d + %d = %d\n", a, b, result);
				break;
			case 2:
				printf("Digite o primeiro e segundo valor: ");
                                scanf("%d%d", &a, &b);
                                result = a - b;
                                printf("%d - %d = %d\n", a, b, result);
                                break;
			case 3:
				printf("Digite o primeiro e segundo valor: ");
                                scanf("%d%d", &a, &b);
                                result = a * b;
                                printf("%d * %d = %d\n", a, b, result);
                                break;
			case 4:
				printf("Digite o primeiro e segundo valor: ");
                                scanf("%d%d", &a, &b);
				while(b <= 0){
					printf("Digite um valor positivo para o dividendo: ");
					scanf("%d", &b);
				}
				result = a / b;
                                printf("%d / %d = %.2f\n", a, b,(float)result);
                                break;
			case 0:
                                return (0);
			default:
				printf("Opção não existe, digite outra");
			}
	}while(option != 0);
	return (0);
}
