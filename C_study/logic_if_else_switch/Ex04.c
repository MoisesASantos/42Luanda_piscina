#include <stdio.h>

int main(void)
{
	int a, b, c;

	printf("Digite os valores: ");
	scanf("%d%d%d", &a, &b, &c);
	if(a % 2 == 0 || a % 3 == 0 || a % 5 == 0)
	{
		printf("O valor de a é divisivel pelos referidos números\n");
	}
	else
		printf("O valor de a não é divisivel\n");
	if(b % 2 == 0 || b % 3 == 0 || b % 5 == 0)
        {
                printf("O valor de b é divisivel pelos referidos números\n");
        }
        else
                printf("O valor de b não é divisivel\n");
	if(c % 2 == 0 || c % 3 == 0 || c % 5 == 0)
        {
                printf("O valor de a é divisivel pelos referidos números\n");
        }
        else
                printf("O valor não é divisivel\n");
	return (0);
}




/*int main(void)
{
	int a, b, c, d, e, negativo, positivo;

	negativo = 0;
	positivo = 0;
	printf("Digite os respectivos valores: ");
	scanf("%d%d%d%d%d", &a, &b, &c, &d, &e);
	if(a > 0)
		positivo++;
	else
		negativo++;
	if(b > 0)
		positivo++;
	else
		negativo++;
	if(c > 0)
		positivo++;
	else
		negativo++;
	if(d > 0)
		positivo++;
	else
		negativo++;
	if(e > 0)
		positivo++;
	else
		negativo++;
	printf("Há %d números positivos\n", positivo);
	printf("Há %d números negativos\n", negativo);
	return (0);
}*/
