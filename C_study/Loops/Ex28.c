#include <stdio.h>

int main(void)
{
	int nota1;
	int nota2;
	int media;
	int option;

	do{
		do{
			printf("Digite a primeira nota: ");
			scanf("%d", &nota1);
		}while(nota1 < 0 || nota1 > 10);
		do{
                        printf("Digite a segunda nota: ");
                        scanf("%d", &nota2);
                }while(nota2 < 0 || nota2 > 10);
		printf("A media semestral é de %d valores\n", media = (nota1 + nota2) / 2);
		do{
			printf("novo calculo? (1-sim 2-nao): ");
			scanf("%d", &option);
		}while (option < 1 || option > 2);
	}while(option != 2);
	return (0);
}	
