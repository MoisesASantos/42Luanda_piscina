#include <stdio.h>

int main(void)
{
	int i;
	int N;
	int A;

	A = 0;
	printf("Digite o valor de N maior que zero: ");
	scanf("%d", &N);
	while(N <= 0)
	{
		printf("Digite o valor de N maior que zero: ");
        	scanf("%d", &N);
	}
	for(i = 1; i <= N; i++)
	{
		A += i;
	}
	printf("O valor de A é A = %d\n", A);
	return (0);
}
