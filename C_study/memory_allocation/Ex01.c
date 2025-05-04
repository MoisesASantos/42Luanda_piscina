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
	printf("\n");
	return (0);
}
