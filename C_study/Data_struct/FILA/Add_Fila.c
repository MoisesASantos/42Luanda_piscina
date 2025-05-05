#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct no{
   int valor;
   struct no *proximo;
}No;

void inserir_na_fila(No **fila, int valor)
{
    No *aux, *novo = malloc(sizeof(No));
    if(novo){
        novo->valor = valor;
        novo->proximo = NULL;
        if(*fila== NULL)
            *fila = novo;
        else{
            aux = *fila;
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
   No *fila = NULL;
    return (0);
}