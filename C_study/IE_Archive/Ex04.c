#include <stdio.h>

void wwrite(char f[])
{
	FILE *file;
	char letra;

	file = fopen(f, "w");
	if(file)
	{
		printf("\nDigite um texto e pressione Enter: ");
		scanf("%c", &letra);
		while(letra != '\n')
		{
			fputc(letra, file);
			scanf("%c", &letra);
		}
		fclose(file);
	}
	else
		printf("\nErro ao abrir o arquivo\n");
}

void rreed(char f[])
{
	FILE *file;
	char letra;

	file = fopen(f, "r");
	if(file)
	{
		printf("\n\tTexto lido do arquivo\n");
		while(!feof(file))//feof verifica se estamos no final do arquivo.
		{
			letra = fgetc(file);
			printf("%c", letra);
		}
		fclose(file);
	}
	else
		printf("\nErro ao abrir arquivo\n");
}

int main(void)
{

	char nome[] = {"teste.txt"};
	wwrite(nome);
	rreed(nome);
	printf("\n");
	return (0);
}
