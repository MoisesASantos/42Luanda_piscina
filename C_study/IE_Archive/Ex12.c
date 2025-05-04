#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
	char nome[50];
	int dia, mes, ano;
}Contato;

void wwrite(char arq[])
{
	Contato c;
	FILE *file;

	file = fopen(arq, "ab");
	if(file)
	{
		printf("\nDigite o nome e a data de nascimento: ");
		scanf("%49[^\n]%d%d%d", c.nome, &c.dia, &c.mes, &c.ano);
		fwrite(&c, sizeof(Contato), 1, file);
		fclose(file);
	}
	else
		printf("\nErro ao abrir arquivo\n");
}

int main(void)
{
	char arquivo[] = "agenda.dat";
	wwrite(arquivo);
	return (0);
}


