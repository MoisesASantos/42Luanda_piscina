#include <stdio.h>

int main(void)
{
	int A = 2;
	int *B = &A;
	int **C = &B;
	int ***D = &C;
	printf("O valor de A = %d\n", A);
	printf("O valor de A = %d\n", *B * 2);
	printf("O valor de A = %d\n", **C * 3);
	printf("O valor de A = %d\n", ***D * 4);
	return (0);
}
