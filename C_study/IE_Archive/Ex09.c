#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void wwrite(char f[])
{
	FILE *file;
	char texto[500];

	file = fopen(f, "w");
	if(file)
	{
		printf("Digite um texto: ");
		scanf("%500[^\n]", texto);
		getchar();
		while(strlen(texto) > 1)
		{
			fprintf(file, "%s\n", texto);
			scanf("%500[^\n]", texto);
			getchar();
			fputc('\n', file);
		}
		fclose(file);
	}
	else
		printf("Erro ao abrir arquivo\n");
}

void rread(char f[])
{
	FILE *file;
	char texto[500];

	file = fopen(f, "r");
	if(file)
	{
		printf("\n\nTEXTO LIDO\n\n");
		while(fscanf(file, "%s", texto) != -1)
			printf("%s", texto);
		printf("\n");
		fclose(file);
	}
	else
		printf("Erro ao abrir arquivo\n");
}

int main(void)
{
	char nome[] = "teste.txt";
	wwrite(nome);
	rread(nome);
	return (0);
}
