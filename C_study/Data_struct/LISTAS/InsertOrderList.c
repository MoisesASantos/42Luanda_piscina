#include <stdio.h>
#include <stdlib.h>

typedef struct no {
    int valor;
    struct no *proximo;
} No;

typedef struct {
    No *inicio;
    int tam;
} Lista;

void criarLista(Lista *lista) {
    lista->inicio = NULL;
    lista->tam = 0;
}


void    inserirOrdenado(Lista *lista, int num)
{
    No *aux, *novo = malloc(sizeof(No));

    if(novo)
    {
        novo->valor = num;
        if(lista->inicio == NULL)
        {
            novo->proximo = NULL;
            lista->inicio = novo;
        }
        else if (lista->inicio->valor > novo->valor)
        {
            novo->proximo = lista->inicio;
            lista->inicio = novo;
        }
        else
        {
            aux = lista->inicio;
            while(aux->proximo && aux->proximo->valor < novo->valor)
                aux = aux->proximo;
            novo->proximo = aux->proximo;
            aux->proximo = novo;
        }
        lista->tam++;
    }
    else
        printf("Erro ao alocar memória\n");
}

void imprimirLista(Lista *lista) {
    No *atual = lista->inicio;
    while (atual != NULL) {
        printf("%d ", atual->valor);
        atual = atual->proximo;
    }
    printf("\n");
}

int main() {
    Lista lista;
    criarLista(&lista);

    inserirOrdenado(&lista, 5);
    inserirOrdenado(&lista, 2);
    inserirOrdenado(&lista, 8);
    inserirOrdenado(&lista, 1);
    inserirOrdenado(&lista, 3);

    printf("Lista ordenada: ");
    imprimirLista(&lista);

    return 0;
}