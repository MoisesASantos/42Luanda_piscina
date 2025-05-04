#include <stdio.h>
#include <string.h>
#include <ctype.h>

char *dic[][40] = { 
	"atlas", "um livro de mapas", 
	"carro", "um veículo motorizado", 
	"telefone", "um dispositivo de comunicação", 
	"avião", "uma máquina voadora",
	"",""};

int main(void)
{
	char word[80], ch;
	char **p;
	do{
		puts("\nInsere a palavra: ");
		fgets(word, 80, stdin);
		int len = strlen(word);
		if(word[len - 1] == '\n')
			word[len - 1] = 0;

		p = (char **)dic;

		do{
			if(!strcmp(*p, word))
			{
				puts("significado:");
				puts(*(p + 1));
				break ;
			}
			if(!strcmp(*p, word))
				break ;
			p = p + 2;
		}while(*p);

		if(!*p)
			puts("A palavra não está no dicionário");
		printf("outra? (y/n): ");
		ch = getchar();
	}while(toupper(ch) != 'N');
	return (0);
}
