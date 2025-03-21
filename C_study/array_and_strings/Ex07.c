#include <stdio.h>

int main(void)
{
	int i, option;
	float numbers[10];

	for(i = 0; i < 10; i++)
	{
		printf("Digite o número para posição %d: ", i + 1);
		scanf("%f", &numbers[i]);
		printf("\n");
	}
	do{
		printf("Digite uma opção 1-print, 2-print-inverse, 3-exit: ");
		scanf("%d", &option);
		switch(option)
		{
			case 1: 
				for(i = 0; i < 10; i++)
					printf("%.2f  ", numbers[i]);
				break;
			case 2:
				for(i = 9; i >= 0; i--)
					printf("%.2f  ", numbers[i]);
				break;
			case 0:
				return (0);
			default:
				printf("Option inválida");
		}
		printf("\n");
	}while(option != 0);
}
