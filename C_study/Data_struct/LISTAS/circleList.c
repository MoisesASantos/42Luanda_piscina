#include <stdio.h>
#include <stdlib.h>

typedef struct no {
    int valor;
    struct no *proximo;
} No;

typedef struct {
    No *inicio;
    No *fim;
    int tam;
} Lista;

void criarLista(Lista *lista) {
    lista->inicio = NULL;
    lista->fim = NULL;
    lista->tam = 0;
}

void inserir_inicio(No **lista, int num)
{
    No *novo = malloc(sizeof(No));
    if(novo){
        novo->valor = num;
        novo->proximo = lista->inicio;
        lista->inicio = novo;
        if(lista->fim == NULL)
            lista->fim = novo;
        lista->fim->proximo = lista->inicio;
        lista->tam++;
    }
    else
        printf("\tErro ao alocar memoria!\n");
}

void inserir_final(No **list, int num)
{
    No *aux, *novo = malloc(sizeof(No));
    if(novo)
    {
        novo->valor = num;
        if(*lista == NULL)
        {
            *lista = novo;
            lista->fim = novo;
            lista->fim->proximo = lista->inicio;
        }
        else
        {
            lista->fim->proximo = novo;
            lista->fim = novo;
            lista->fim->proximo = lista->inicio;
        }
        lista->tam++;
    }
    else
        printf("\tErro ao alocar memoria!\n");
}

void inserir_meio(No **lista, int valor, int pos)
{
    No *aux, *novo = malloc(sizeof(No));
    if(novo)
    {
        novo->valor = valor;
        if(*lista == NULL)
        {
            novo->proximo = NULL;
            novo->anterior = NULL;
            *lista = novo;
        }
        else{
            aux = *lista;
            while(aux->valor != pos && aux->proximo)
                aux = aux->proximo;
            novo->proximo = aux->proximo;
            if(aux->proximo)
                aux->proximo->anterior = novo;
            novo->anterior = aux;
            aux->proximo = novo;
        }
    }
    else
        printf("\tErro ao alocar memoria!\n");
}


void inserir_ordenado(No **lista, int num){
    No *aux, *novo = malloc(sizeof(No));
    if(novo){
        novo->valor = num;
        // a lista está vazia?
        if(*lista == NULL){
            inserir_inicio(lista, num);
        } // é o menor?
        else if(novo->valor < (*lista)->valor){
            inserir_inicio(lista, num);
        }
        else{
            aux = lista->inicio;
            while(aux->proximo != lista->inicio && novo->valor > aux->proximo->valor)
                aux = aux->proximo;
            if(aux->proximo == lista->inicio)
                inserir_final(lista, num);
            else
            {
                novo->proximo = aux->proximo;
                aux->proximo = novo;
                lista->tam++;
            }
        }
    }
    else
        printf("Erro ao alocar memoria!\n");
}

No* remover(Lista *lista, int num){
    No *aux, *remover = NULL;
    if(lista->inicio){
        if(lista->inicio == lista->fim && lista->inicio->valor == num){
            remover = lista->inicio;
            lista->inicio = NULL;
            lista->fim = NULL;
            lista->tam--;
        }
        else if(lista->inicio->valor == num){
            remover = lista->inicio;
            lista->inicio = remover->proximo;
            lista->fim->proximo = lista->inicio;
            lista->tam--;
        }
        else{
            aux = lista->inicio;
            while(aux->proximo != lista->inicio && aux->proximo->valor != num)
                aux = aux->proximo;
            if(aux->proximo->valor == num){
                if(lista->fim == aux->proximo){
                    remover = aux->proximo;
                    aux->proximo = remover->proximo;
                    lista->fim = aux;
                }
                else{
                    remover = aux->proximo;
                    aux->proximo = remover->proximo;
                }
                lista->tam--;
            }
        }
    }
    return remover;
}

No* buscar(Lista *lista, int num)
{
    No *aux, *no = NULL;
    aux = lista->inicio;
    while(aux && aux->valor != num)
        aux = aux->proximo;
    if(aux)
        no = aux;
    return no;
}


No* ultimo(No **lista){
    No *aux = *lista;
    while(aux->proximo)
        aux = aux->proximo;
    return aux;
}

void imprimirContrario(No *no){
    printf("\n\tLista: ");
    while(no){
        printf("%d ", no->valor);
        no = no->anterior;
    }
    printf("\n\n");
}


void imprimirLista(Lista *lista) {
    No *atual = lista->inicio;
    while (atual != NULL) {
        printf("%d ", atual->valor);
        atual = atual->proximo;
    }
    printf("\n");
}

int main(){
    int opcao, valor, anterior;
    No *removido, *lista = NULL;
    do{
        printf("\n\t0 - Sair\n\t1 - InserirI\n\t2 - inserirF\n\t3 - InserirM\n\t4 - InserirO\n\t5 - Remover\n\t6 - Imprimir\n\t7 - Buscar\n\t8 - ImprimirC\n");
        scanf("%d", &opcao);
        switch(opcao){
        case 1:
            printf("Digite um valor: ");
            scanf("%d", &valor);
            inserir_no_inicio(&lista, valor);
            break;
        case 2:
            printf("Digite um valor: ");
            scanf("%d", &valor);
            inserir_no_fim(&lista, valor);
            break;
        case 3:
            printf("Digite um valor e o valor de referencia: ");
            scanf("%d%d", &valor, &anterior);
            inserir_no_meio(&lista, valor, anterior);
            break;
        case 4:
            printf("Digite um valor: ");
            scanf("%d", &valor);
            inserir_ordenado(&lista, valor);
            break;
        case 5:
            printf("Digite um valor a ser removido: ");
            scanf("%d", &valor);
            removido = remover(&lista, valor);
            if(removido){
                printf("Elemento a ser removido: %d\n", removido->valor);
                free(removido);
            }
            else
                printf("Elemento inexistente!\n");
            break;
        case 6:
            imprimir(lista);
            break;
        case 7:
            printf("Digite um valor a ser buscado: ");
            scanf("%d", &valor);
            removido = buscar(&lista, valor);
            if(removido)
                printf("Elemento encontrado: %d\n", removido->valor);
            else
                printf("Elemento nao encontrado!\n");
            break;
        case 8:
            imprimirContrario(ultimo(&lista));
            break;
        default:
            if(opcao != 0)
                printf("Opcao invalida!\n");
        }
    }while(opcao != 0);
    return 0;
}