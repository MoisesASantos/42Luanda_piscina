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

typedef struct{
    No *topo;
    int tam;
}Pilha;

Pessoa ler_pessoa()
{
    Pessoa p;

    printf("Digite o seu nome, dia, mes e ano: ");
    scanf("%49[^\n]%d%d%d", p.nome, &p.data.dia, &p.data.mes, &p.data.ano);
    return p;
}

void criar_pilha(Pilha *p){
    p->topo = NULL;
    p->tam = 0;
}

void imprimir_pessoa(Pessoa p)
{
    printf("\nNome: %s", p.nome);
    printf("\nData de nascimento: %d/%d/%d", p.data.dia, p.data.mes, p.data.ano);
}

void imprimir_pilha(Pilha *p){
    No *aux = p->topo;
    printf("\n----------- PILHA Tam: %d --------------\n", p->tam);
    while(aux){
        imprimir_pessoa(aux->p);
        aux = aux->proximo;
    }
    printf("\n--------- FIM PILHA ------------\n");
}

void empilhar(Pilha *p){
    No *novo = malloc(sizeof(No));
    if(novo){
        novo->p = ler_pessoa();
        novo->proximo = p->topo; // novo nó aponta para o topo atual
        p->topo = novo; // o topo passa a ser o novo nó
        p->tam++;
    }
    else
        printf("\nErro ao alocar memoria...\n");
}

No* desempilhar(Pilha *p){
    if(p->topo){
        No *remover = p->topo; // remover aponta para o topo
        p->topo = remover->proximo; // o topo passa a ser o próximo de remover
        p->tam--;
        return remover;
    }
    else
        printf("\nPilha vazia!\n");
    return NULL;
}

int main(){
    No *remover;
    Pilha p;
    int opcao;
    criar_pilha(&p);
    do{
        printf("\n0 - Sair\n1 - Empilhar\n2 - Desempilhar\n3 - Imprimir\n");
        scanf("%d", &opcao);
        getchar();
        switch(opcao){
        case 1:
            empilhar(&p);
            break;
        case 2:
            remover = desempilhar(&p);
            if(remover){
                printf("\nElemento removido com sucesso!\n");
                imprimir_pessoa(remover->p);
                free(remover);
            }
            else
                printf("\nSem no a remover.\n");
            break;
        case 3:
            imprimir_pilha(&p);
            break;
        default:
            if(opcao != 0)
                printf("\nOpcao invalida!!!\n");
        }
    }while(opcao != 0);
    return 0;
}