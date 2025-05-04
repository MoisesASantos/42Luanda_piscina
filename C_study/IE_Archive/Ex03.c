#include <stdio.h>

int main(void)
{
	FILE *file;
	char letra;

	file = fopen("teste.txt", "w+");
	if(file)
	{
		printf("\nDigite um texto e pressione Enter: ");
		scanf("%c", &letra);
		while(letra != '\n')
		{
			fputc(letra, file);
			scanf("%c", &letra);
		}
		rewind(file);//Manda o programa para o inicio do arquivo.
		printf("\n\tTexto lido do arquivo\n");
		while(!feof(file))//feof verifica se estamos no final do arquivo.
		{
			letra = fgetc(file);
			printf("%c", letra);
		}
		fclose(file);
	}
	else
		printf("\n\t--> Erro ao abrir arquivo!\n");
	printf("\n");
	return (0);
}
