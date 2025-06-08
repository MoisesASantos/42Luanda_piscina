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


int main(void)
{
    return (0);
}

