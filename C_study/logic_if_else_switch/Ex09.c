#include <stdio.h>

int main(void)
{
    int a, b, c;

    // Solicita os valores dos lados
    printf("Digite os três lados do triângulo: ");
    scanf("%d%d%d", &a, &b, &c);

    // Verifica a condição de existência do triângulo
    if (a + b > c && a + c > b && b + c > a)
    {
        printf("Os lados formam um triângulo.\n");

        // Classifica o triângulo quanto aos lados
        if (a == b && b == c)
            printf("Triângulo equilátero.\n");
        else if (a == b || a == c || b == c)
            printf("Triângulo isósceles.\n");
        else
            printf("Triângulo escaleno.\n");
    }
    else
    {
        printf("Os lados NÃO formam um triângulo.\n");
    }

    return 0;
}
