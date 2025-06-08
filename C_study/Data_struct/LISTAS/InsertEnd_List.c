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
        novo_proximo = *lista;
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

int main(void)
{
    return (0);
}