#include <stdio.h>

void imprimir(int n)
{
	if(n == 0)
		printf("%d \n", n);
	else{
		imprimir(n - 1);
		printf("%d \n", n);
	}
}

int main(void)
{
	int n = 15;
	imprimir(n);
	return (0);
}		
