#include <stdio.h>

int main(void)
{
	int i;
	int valor = 9;
	int divisores;

	do{
		valor++;
		divisores = 0;
		for(i = 1; i <= 10; i++)
		{
			if(valor % i == 0)
				divisores++;
		}
	}while(divisores != 10);
	printf("O menor número divisel por todos valores entre 1 e 10 é %d\n", valor);
	return (0);
}
