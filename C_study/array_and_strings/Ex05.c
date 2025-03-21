#include <stdio.h>

int main(void)
{
    int quant[5], i, count = 0;
    int indice[5];
    float valorUni[5];
    float valorTotalCada[5];
    float totalVendas = 0.00;
    float comissao;
    float valorMaior;
    float valorobj[5];

    // Entrada de dados
    for(i = 0; i < 5; i++)
    {
        printf("Digite o valor unitário do produto %d: ", i + 1);
        scanf("%f", &valorUni[i]);
        printf("Digite a quantidade vendida do produto %d: ", i + 1);
        scanf("%d", &quant[i]);
        printf("\n");
    }

    // Cálculo do valor total de vendas de cada produto e do total geral
    for(i = 0; i < 5; i++)
    {
        valorTotalCada[i] = valorUni[i] * quant[i];
        totalVendas += valorTotalCada[i]; 
    }

    // Cálculo da comissão
    comissao = totalVendas * 0.05;

    // Exibição dos resultados
    for(i = 0; i < 5; i++)
    {
        printf("A quantidade vendida do produto %d é de %d\n", i + 1, quant[i]);
        printf("O valor unitário do produto %d é de %.2f reais\n", i + 1, valorUni[i]);
        printf("O valor total de vendas do produto %d é de %.2f reais\n", i + 1, valorTotalCada[i]);
        printf("\n");
    }
    printf("O valor total das vendas é de %.2f reais\n", totalVendas);
    printf("O valor da comissão é de %.2f reais\n", comissao);

    // Determinação do(s) objeto(s) mais vendido(s)
    valorMaior = valorTotalCada[0];
    indice[0] = 0;
    valorobj[0] = valorUni[0];
    count = 1;

    for(i = 1; i < 5; i++)
    {
        if(valorTotalCada[i] > valorMaior)
        {
            valorMaior = valorTotalCada[i];
            indice[0] = i;
            valorobj[0] = valorUni[i];
            count = 1;
        }
        else if(valorTotalCada[i] == valorMaior)
        {
            indice[count] = i;
            valorobj[count] = valorUni[i];
            count++;
        }
    }

    // Exibição do(s) objeto(s) mais vendido(s)
    if(count > 1)
    {
        printf("Houve empate nos objetos mais vendidos:\n");
        for(i = 0; i < count; i++)
        {
            printf("O valor do objeto mais vendido é de %.2f reais e está na posição %d\n", valorobj[i], indice[i] + 1);
        }
    }
    else
    {
        printf("O valor do objeto mais vendido é de %.2f reais e está na posição %d\n", valorobj[0], indice[0] + 1);
    }

    return 0;
}
