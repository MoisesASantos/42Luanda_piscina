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

void imprimir_pilha(No *topo)
{
  printf("INICIO DA PILHA\n");
  while(topo)
  {
      imprimir_pessoa(topo->p);
      topo = topo->proximo;
  }
  printf("\nFIM DE PILHA-------------\n");
}

No* empilhar(No *topo)
{
    No *novo = malloc(sizeof(No));
    if(novo)
    {
        novo->p = ler_pessoa();
        novo->proximo = topo;
        return novo;
    }
    else
    {
        printf("\n\t Erro ao alocar\n");
        return NULL;
    }
}

No* desempilhar(No **topo)
{
   if(*topo != NULL)
   {
       No *remover = *topo;
        *topo = remover->proximo;
        return remover;   
   } 
   else
   {
       printf("\n\t Pilha vazia\n");
   }
   return NULL;
}

int main(void)
{
    No *remover, *topo = NULL;
    int opcao;
    printf("\n\t 0 - Sair\n\t1 - Empilhar\n\t2 - Desempilhar\n\t3 - Imprimir\n");
    do{
        printf("Digite a opcao desejada: ");
        scanf("%d", &opcao);
        getchar();
        switch(opcao)
        {
            case 1:
                topo = empilhar(topo);
                break;
            case 2:
                remover = desempilhar(&topo);
                if(remover != NULL){
                    printf("\n Removido com sucesso \n");
                    imprimir_pessoa(remover->p);
                    free(remover);
                }
                else {
                    printf("\n sem nó a remover \n");
                }
                break;
            case 3:
                imprimir_pilha(topo);
                break;
            default:
                if(opcao != 0)
                    printf("Opção inválidan\n");
                break;
        }
    }while(opcao != 0);
    return 0;
}