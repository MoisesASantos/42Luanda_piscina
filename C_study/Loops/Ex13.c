#include <stdio.h>

int main(void)
{
    int tempo;
    float massa;
    float limite;

    printf("Digite a sua massa: ");
    scanf("%f", &massa);

    tempo = 0;
    limite = 0.05;

    // Loop enquanto a massa for maior ou igual ao limite
    while (massa >= limite) {
        tempo += 50; // Incrementa o tempo antes de reduzir a massa
        massa /= 2; // Reduz a massa pela metade
    }

    printf("O tempo necessário é %d segundos para a massa ser menor que 0.05\n", tempo);
    return 0;
}
