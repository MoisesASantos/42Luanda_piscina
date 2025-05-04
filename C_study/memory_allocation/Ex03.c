#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void)
{
	int tam, *vet;
	srand(time(NULL));

	printf("Digite o tamanho do vetor: ");
	scanf("%d", &tam);
	vet = malloc(tam * sizeof(int));
	if(vet == NULL)
		return (1);
	for(int i = 0; i < tam; i++)
		*(vet + i) = rand() % 100;
	for(int i = 0; i < tam; i++)
		printf("%d ", *(vet + i));
	printf("\n\nDigite o tamanho do vetor: ");
        scanf("%d", &tam);
	vet = realloc(vet, tam);
	//for(int i = 0; i < tam; i++)
                //*(vet + i) = rand() % 100;
	printf("\nVetor realocado\n");
        for(int i = 0; i < tam; i++)
                printf("%d ", *(vet + i));
	free(vet);
	printf("\n");
	return (0);
}
