#include <stdio.h>
#include <string.h>

typedef struct{
	char nome[80];
	int  idade;
	char sexo;
} pessoa;

int main(void)
{
	pessoa pessoa2;
	printf("Digite o seu nome: ");
	fgets(pessoa2.nome, 80, stdin);
	size_t len = strlen(pessoa2.nome);
	if(len > 0 && pessoa2.nome[len - 1] == '\n')
		pessoa2.nome[len - 1] = '\0';
	printf("Digite a sua idade: ");
        scanf("%d", &pessoa2.idade);
	getchar();
	printf("Digite o seu sexo: ");
        pessoa2.sexo = getchar();
	printf("\n\nO seu nome é %s\n", pessoa2.nome);
	printf("A sua idade é %d\n", pessoa2.idade);
	if(pessoa2.sexo == 'M')
		printf("O seu sexo é masculino\n");
	else
		printf("O seu sexo é femenino\n");
	return (0);
}
