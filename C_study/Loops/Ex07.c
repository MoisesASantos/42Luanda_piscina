#include <stdio.h>

int main(void)
{
	int nota1;
	int nota2;
	int media;

	do{
		printf("Digite a primeira nota: ");
		scanf("%d", &nota1);
	}while(nota1 < 0 || nota1 > 10);
	do{
		printf("Digite a segunda nota: ");
		scanf("%d", &nota2);
	}while(nota2 < 0 || nota2 > 10);
	if(nota1 && nota2)
	{
		media = (nota1 + nota2) / 2;
		printf("A media do aluno é %d\n", media);
	}
	return (0);
}
