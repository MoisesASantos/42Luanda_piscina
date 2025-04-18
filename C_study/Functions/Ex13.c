#include <stdio.h>

/*void binary(int n)
{
    int vetor[32];  // Suporta até 32 bits (para int normal)
    int i = 0;

    if (n == 0) {
        printf("0\n");
        return;
    }

    // Converte para binário (do final para o início)
    while (n > 0) {
        vetor[i] = n % 2;
        n = n / 2;
        i++;
    }

    // Imprime na ordem inversa
    for (int j = i - 1; j >= 0; j--) {
        printf("%d", vetor[j]);
    }
    printf("\n");
}*/

void binary(int n)
{
	int vetor[8];

	for(int i = 7; i >= 0; i--)
	{
		vetor[i] = n % 2;
		n = n / 2;
	}
	for(int i = 0; i < 8; i++)
		printf("%d", vetor[i]);
	printf("\n");
}


int main(void)
{
	int n = 4;
	binary(n);
	return (0);
}
