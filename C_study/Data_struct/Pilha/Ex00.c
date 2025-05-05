#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    int dia, mes, ano;
}Data;

typedef struct
{
    char nome[50];
    Data data;
}Pessoa;

typedef struct no{
    Pessoa p;
    struct no *proximo;
}No;

Pessoa ler_pessoa()
{
    Pessoa p;

    printf("Digite o seu nome, dia, mes e ano: ");
    scanf("%49[^\n]%d%d%d", p.nome, &p.data.dia, &p.data.mes, &p.data.ano);
    return p;
}

void imprimir_pessoa(Pessoa p)
{
    printf("\nNome: %s", p.nome);
    printf("\nData de nascimento: %d/%d/%d", p.data.dia, p.data.mes, p.data.ano);
}


No *empilhar(No *topo)
{
    No *novo = malloc(sizeof(No));
    if(novo)
    {
        novo->p = ler_pessoa();
        novo->proximo = topo;
        return topo;
    }
    else
    {
        printf("\n\t Erro ao alocar\n");
        return NULL;
    }
}

int main(void)
{
    No *topo = NULL;
    int opcao;
    printf("\n\t 0 - Sair\n\t1 - Empilhar\n\t2 - Desempilhar\n\t3 - Imprimir\n");
    do{
        printf("Digite a opcao desejada: ");
        scanf("%d", &opcao);
        switch(opcao)
        {
            case 1:
                topo = empilhar(topo);
                break;
            case 2:
                break;
            case 3:
                //imprimir_pessoa(topo);
                break;
            default:
                if(opcao != 0)
                    printf("Opção inválidan\n");
                break;
        }
    }while(opcao != 0);
    return 0;
}