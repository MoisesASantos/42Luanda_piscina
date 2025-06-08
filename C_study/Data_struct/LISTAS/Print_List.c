#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct no{
    int valor;
    struct no *proximo;
}No;

void inserir_inicio(No **lista, int valor)
{
    No *novo = malloc(sizeof(No));
    if(novo){
        novo->valor = valor;
        novo->proximo = *lista;
        *lista = novo;
    }
    else
        printf("\tErro ao alocar memoria!\n");
}

void inserir_final(No **list, int num)
{
    No *novo = malloc(sizeof(No));
    if(novo)
    {
        novo->valor = num;
        novo->proximo = NULL;
        if(*list == NULL)
            *list = novo;
        else{
            No *aux = *list;
            while(aux->proximo != NULL)
                aux = aux->proximo;
            aux->proximo = novo;
        }
    }
    else
        printf("\tErro ao alocar memoria!\n");
}

void inserir_meio(No **lista, int valor, int pos)
{
    No *novo = malloc(sizeof(No));
    if(novo)
    {
        novo->valor = valor;
        if(*lista == NULL)
        {
            novo->proximo = NULL;
            *lista = novo;
        }
        else
        {
            No *aux = *lista;
            for(int i = 0; i < pos - 1 && aux->proximo != NULL; i++)
                aux = aux->proximo;
            novo->proximo = aux->proximo;
            aux->proximo = novo;
        }
    }
    else
        printf("\tErro ao alocar memoria!\n");
}

void imprimir(No *lista)
{
    No *aux = lista;
    printf("\t------- LISTA --------\n\t");
    while(aux){
        printf("%d ", aux->valor);
        aux = aux->proximo;
    }
    printf("\n\t------- FIM LISTA --------\n");
}

int main(void)
{
    No *lista = NULL;
    int num, pos;
    int opcao;
    do{
        printf("\t0 - Sair\n\t1 - Inserir no inicio\n\t2 - Inserir no final\n\t3 - Inserir no meio\n\t4 - Imprimir lista\n");
        printf("Digite o valor da opcao desejada:\n");
        scanf("%d", &opcao);
        switch(opcao)
        {
            case 1:
                printf("Digite um valor: ");
                scanf("%d", &num);
                inserir_inicio(&lista, num);
                break;
            case 2:
                printf("Digite um valor: ");
                scanf("%d", &num);
                inserir_final(&lista, num);
                break;
            case 3:
                printf("Digite um valor: ");
                scanf("%d", &num);
                printf("Digite a posicao: ");
                scanf("%d", &pos);
                inserir_meio(&lista, num, pos);
                break;
            case 4:
                imprimir(lista);
                break;
            default:
                if(opcao != 0)
                    printf("\nOpcao invalida!\n");
                break;
        }
    }while(opcao != 0);
    return (0);
}