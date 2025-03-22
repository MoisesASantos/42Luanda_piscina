#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void)
{
	int i, j, soma, matriz[5][10];
	int linhas[5];
	int colunas[10];
	srand(time(NULL));
	for(i = 0; i < 5; i++)
	{
		for(j = 0; j < 10; j++)
			matriz[i][j] = 1 + rand() % 10;
	}
	for(i = 0; i < 5; i++)
	{
		soma = 0;
		for(j = 0; j < 10; j++)
			soma += matriz[i][j];
		linhas[i] = soma;
	}
	for(i = 0; i < 10; i++)
        {
                soma = 0;
                for(j = 0; j < 5; j++)
                        soma += matriz[j][i];
                colunas[i] = soma;
        }
	for(i = 0; i < 5; i++)
        {
		for(j = 0; j < 10; j++)
                	printf("%d ", matriz[i][j]);
		printf("\n");
        }
        printf("\n");
	for(i = 0; i < 5; i++)
	{
		printf("A soma da linha %d é %d\n", i + 1, linhas[i]);
	}
	printf("\n");
	for(i = 0; i < 10; i++)
        {
                printf("A soma da coluna %d é %d\n", i + 1, colunas[i]);
        }
	printf("\n");
	return (0);
}
			
