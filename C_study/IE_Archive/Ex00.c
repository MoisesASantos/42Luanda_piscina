#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv)
{
	FILE *fp;
	char ch;

	if(argc != 2)
	{
		printf("voce esqueceu de digitar o nome do arquivo\n");
		exit (1);
	}
	if((fp = fopen(argv[1], "w")) == NULL)
	{
		printf("O arquivo não pode ser aberto\n");
		exit(1);
	}
	do{
		ch = getchar();
		fputc(ch, fp);
	}while(ch != '$');
	fclose(fp);
	return (0);
}
