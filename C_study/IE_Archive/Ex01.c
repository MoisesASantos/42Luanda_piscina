#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv)
{
	FILE *fp;
	char ch;

	if(argc != 2)
	{
		printf("Voce não digitou o nome do programa\n");
		exit(1);
	}
	if((fp = fopen(argv[1], "r")) == NULL)
	{
		printf("O arquivo não pode ser aberto.\n");
		exit(1);
	}
	ch = fgetc(fp);
	while(ch != EOF)
	{
		putchar(ch);
		ch = fgetc(fp);
	}
	fclose(fp);
	return (0);
}
