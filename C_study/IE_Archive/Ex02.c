#include <stdio.h>

int main(void)
{
	FILE *file;
	char letra;

	file = fopen("teste.txt", "w");
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
		printf("\n\t--> Erro ao abrir arquivo!\n");
	return (0);
}
