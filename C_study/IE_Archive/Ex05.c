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

int main(void)
{
	char nome[] = {"teste.txt"};
	wwrite(nome);
	return (0);
}
