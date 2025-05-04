#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct{
	char nome[50];
	int dia, mes, ano;
}Contato;

void print(Contato **c, int quant)
{

	int i;

	printf("\n\tLista de Contatos:\n");
	printf("\t-----------------------------\n");
	for(i = 0; i < quant; i++)
	{
		printf("t%d = %2d/%2d/%4d\t%s\n", i+1, c[i]->dia, c[i]->mes, c[i]->ano, c[i]->nome);
	}
	printf("\t-----------------------------\n");
}

int cadastrar_contato(Contato **c, int quant, int tam)
{

	if(quant < tam)
	{
		Contato *novo;

		novo = malloc(sizeof(Contato));
		printf("Digite o nome de contato: ");
		scanf("%50[^\n]", novo->nome);
		getchar();
		printf("\nDigite data de niver DD/MM/AAAA: ");
		scanf("%d%d%d", &novo->dia, &novo->mes, &novo->ano);
		getchar();
		c[quant] = novo;
		return (1);
	}
	else
	{
		printf("\n\t Erro ao cadastra\n");
		return (0);
	}
}

void alterar_contato(Contato **c, int quant)
{
	int id;

	print(c, quant);
	printf("\n\t Digite o codigo do contato que queres alterar: ");
	scanf("%d", &id);
	getchar();
	id--;
	if(id >= 0 && id < quant)
	{
		Contato *novo;
                novo = malloc(sizeof(Contato));
                printf("Digite o nome de contato: ");
                scanf("%50[^\n]", novo->nome);
                getchar();
                printf("\nDigite data de niver DD/MM/AAAA: ");
                scanf("%d%d%d", &novo->dia, &novo->mes, &novo->ano);
                getchar();
                c[id] = novo;
	}
}

void salvar_contato(Contato **c, int quant, char arq[])
{
	FILE *file;
	int i;

	file = fopen(arq, "w");
	if(file)
	{
		fprintf(file, "%d\n", quant);
		for(i = 0; i < quant; i++)
		{
			fputs(c[i]->nome, file);
			fputc('\n', file);
			fprintf(file, "%d %d %d\n", c[i]->dia, c[i]->mes, c[i]->ano);
		}
		fclose(file);
	}
	else
		printf("\n\tNão foi possivel abrir arquivo\n");
}

void ler_contato(Contato **c, char arq[])
{
	FILE *file;
	int quant = 0, i;
	Contato *novo;

	file = fopen(arq, "r");
	novo = malloc(sizeof(Contato));
	if(file)
	{
		fscanf(file, "%d\n", &quant);
		for(i = 0; i < quant; i++)
		{
			fscanf(file, "%50[^\n]", &novo->nome);
			fscanf(file, "%d %d %d\n", &novo->dia, &novo->mes, &novo->ano);
			c[i] = novo;
			novo = malloc(sizeof(Contato));
		}
		fclose(file);
	}
	else
		printf("\nErro ao abrir arquivo\n");
	return quant;
}

int main(void)
{
	Contato *agenda[50];
	char nome[] = "agenda.txt";
	int opcao, tam = 50, quant = 0;
	do{
		printf("\n\t 0 - Sair\n\t1 - Cadastrar\n\t2 - Alterar\n\t 3 - Imprimir\n\t4 - Salvar\n\t5 - Ler Arquivo\n");
		scanf("%d", &opcao);
		getchar();
		switch(opcao)
		{
			case 1:
				quant += cadastrar_contato(agenda, quant, tam);
				break;
			case 2:
				alterar_contato(agenda, quant);
				break;
			case 3:
				print(agenda, quant);
				break;
			case 4:
				salvar_contato(agenda, quant, nome);
				break;
			case 5:
				ler_arquivo(agenda, nome);
				break;
			default:
				if(opcao != 0)
					printf("Opção inválidan\n");
				break;
		}
	}while(opcao != 0);
	return (0);
}
