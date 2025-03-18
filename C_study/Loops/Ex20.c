#include <stdio.h>

int main(void) {
    int npessoas;
    int i = 0;

    // Solicita o número de pessoas
    printf("Digite o número de pessoas: ");
    scanf("%d", &npessoas);

    // Declaração dos arrays para armazenar os dados
    int idade[npessoas];
    int salario[npessoas];
    char sexo[npessoas];

    // Variáveis para cálculos
    int soma_salario = 0;
    int maior_idade, menor_idade;
    int mulheres_salario_ate_2000 = 0;

    // Loop para coletar os dados de cada pessoa
    for (i = 0; i < npessoas; i++) {
        printf("\nDigite os dados da pessoa %d:\n", i + 1);
        printf("Idade: ");
        scanf("%d", &idade[i]);
        printf("Salário: ");
        scanf("%d", &salario[i]);
        printf("Sexo (M/F): ");
        scanf(" %c", &sexo[i]);  // Espaço antes do %c para evitar problemas com o buffer

        // Soma os salários para calcular a média
        soma_salario += salario[i];

        // Verifica a maior e menor idade
        if (i == 0) {
            maior_idade = idade[i];
            menor_idade = idade[i];
        } else {
            if (idade[i] > maior_idade) {
                maior_idade = idade[i];
            }
            if (idade[i] < menor_idade) {
                menor_idade = idade[i];
            }
        }

        // Conta as mulheres com salário até R$2000,00
        if (sexo[i] == 'F' && salario[i] <= 2000) {
            mulheres_salario_ate_2000++;
        }
    }

    // Calcula a média de salário
    float media_salario = (float)soma_salario / npessoas;

    // Exibe os resultados
    printf("\nResultados:\n");
    printf("a) Média de salário do grupo: R$ %.2f\n", media_salario);
    printf("b) Maior idade: %d anos | Menor idade: %d anos\n", maior_idade, menor_idade);
    printf("c) Quantidade de mulheres com salário até R$2000,00: %d\n", mulheres_salario_ate_2000);

    return 0;
}
