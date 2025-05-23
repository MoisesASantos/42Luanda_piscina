
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct no{
   int valor;
   struct no *proximo;
}No;

void inserir_com_prioridade(No **fila, int num){
    No *aux, *novo = malloc(sizeof(No));
    if(novo){
        novo->valor = num;
        novo->proximo = NULL;
        if(*fila == NULL) // a fila está vazia?
            *fila = novo;
        else{
            if(num > 59){ // é prioridade?
                if((*fila)->valor < 60){ // é a primeira prioridade?
                    novo->proximo = *fila; // insere no início da fila
                    *fila = novo;
                }
                else{
                    aux = *fila;
                    while(aux->proximo && aux->proximo->valor > 59)
                        aux = aux->proximo;
                    novo->proximo = aux->proximo; // insere depois da última prioridade
                    aux->proximo = novo;
                }
            }
            else{ // não é prioridade, então insere no final
                aux = *fila;
                while(aux->proximo)
                    aux = aux->proximo;
                aux->proximo = novo;
            }
        }
    }
    else
        printf("\nErro ao alocar memoria.\n");
}

No* remover_da_fila(No **fila)
{
    No *remover = NULL;
    if(*fila != NULL)
    {
        remover = *fila;
        *fila = remover->proximo;
    }
    else
        printf("\tFila vazia!\n");
    return remover;
}

void imprimir(No *fila){
    printf("\t------- FILA --------\n\t");
    while(fila){
        printf("%d ", fila->valor);
        fila = fila->proximo;
    }
    printf("\n\t------- FIM FILA --------\n");
}

int main(){
    No *r, *fila = NULL;
    int opcao, valor;
    do{
        printf("\t0 - Sair\n\t1 - Inserir\n\t2 - Remover\n\t3 - Imprimir\n");
        scanf("%d", &opcao);
        switch(opcao){
        case 1:
            printf("Digite um valor: ");
            scanf("%d", &valor);
            inserir_com_prioridade(&fila, valor);
            break;
        case 2:
            r = remover_da_fila(&fila);
            if(r){
                printf("Removido: %d\n", r->valor);
                free(r);
            }
            break;
        case 3:
            imprimir(fila);
            break;
        default:
            if(opcao != 0)
                printf("\nOpcao invaluda!\n");
        }
    }while(opcao != 0);
    return 0;
}


