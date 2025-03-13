#include <stdio.h>

int main(void)
{
	char vogal;

	printf("Digite um caracter: ");
	scanf("%c", &vogal);
	if(vogal == 'a' || vogal == 'e' || vogal == 'i' || vogal == 'o' || vogal == 'u')
	       printf("O caracter é uma vogal\n");
	else
		printf("O caracter não é uma vogal\n");
	return (0);
}	
