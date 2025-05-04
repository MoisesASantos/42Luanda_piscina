#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void wwrite(char f[])
{
	FILE *file;
	char texto[500];

	file = fopen(f, "w");
	if(file)
	{
		printf("Digite um texto ou um carater para finalizar: ");
		scanf("%500[^\n]", texto);
		getchar();
		while(strlen(texto) > 1)
		{
			fputs(texto, file);
			scanf("%500[^\n]", texto);
			getchar();
			fputc('\n', file);
		}
		fclose(file);
	}
	else
		printf("\nErro ao abrir arquivo\n");
}



void rread(char f[])
{
	FILE *file;
	char texto[500];

	file = fopen(f, "r");
	if(file)
	{
		printf("\n\t Texto Lido\n");
		while(!feof(file))
		{
			if(fgets(texto, 499, file))
				printf("\n--> %s", texto);
		}
		fclose(file);
	}
	else
		printf("\nErro ao abrir arquivo!\n");
}

int main(void)
{
	char nome[] = "teste.txt";
	wwrite(nome);
	rread(nome);
	return (0);
}
