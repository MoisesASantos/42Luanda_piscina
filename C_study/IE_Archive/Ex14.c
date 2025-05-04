#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct {
    char nome[50];
    int dia, mes, ano;
} Contato;

void print(Contato **c, int quant) {
    int i;

    printf("\n\tLista de Contatos:\n");
    printf("\t-----------------------------\n");
    for (i = 0; i < quant; i++) {
        printf("\t%d = %02d/%02d/%04d\t%s\n", i + 1, c[i]->dia, c[i]->mes, c[i]->ano, c[i]->nome);
    }
    printf("\t-----------------------------\n");
}

int cadastrar_contato(Contato **c, int quant, int tam) {
    if (quant < tam) {
        Contato *novo = malloc(sizeof(Contato));
        if (novo == NULL) {
            perror("Erro ao alocar memória");
            return 0;
        }
        printf("Digite o nome de contato: ");
        scanf(" %49[^\n]%*c", novo->nome); // Limita o tamanho da string e consome o newline
        printf("\nDigite data de niver DD/MM/AAAA: ");
        scanf("%d%d%d%*c", &novo->dia, &novo->mes, &novo->ano); // Consome o newline
        c[quant] = novo;
        return 1;
    } else {
        printf("\n\t Erro ao cadastrar\n");
        return 0;
    }
}

void alterar_contato(Contato **c, int quant) {
    int id;

    print(c, quant);
    printf("\n\t Digite o codigo do contato que queres alterar: ");
    scanf("%d", &id);
    getchar();
    id--;
    if (id >= 0 && id < quant) {
        Contato *novo = malloc(sizeof(Contato));
        if (novo == NULL) {
            perror("Erro ao alocar memória");
            return;
        }
        printf("Digite o nome de contato: ");
        scanf(" %49[^\n]%*c", novo->nome);
        printf("\nDigite data de niver DD/MM/AAAA: ");
        scanf("%d%d%d%*c", &novo->dia, &novo->mes, &novo->ano);

        free(c[id]); // Libera a memória do contato anterior
        c[id] = novo;
    } else {
        printf("\n\tID de contato inválido.\n");
    }
}

void salvar_contato(Contato **c, int quant, char arq[]) {
    FILE *file;
    int i;

    file = fopen(arq, "w");
    if (file) {
        fprintf(file, "%d\n", quant);
        for (i = 0; i < quant; i++) {
            fprintf(file, "%s\n", c[i]->nome); // Use fprintf para escrever a string com newline
            fprintf(file, "%d %d %d\n", c[i]->dia, c[i]->mes, c[i]->ano);
        }
        fclose(file);
    } else {
        printf("\n\tNão foi possivel abrir arquivo\n");
    }
}

int ler_contato(Contato **c, char arq[]) {
    FILE *file;
    int quant = 0, i;

    file = fopen(arq, "r");
    if (file) {
        fscanf(file, "%d\n", &quant);
        for (i = 0; i < quant; i++) {
            Contato *novo = malloc(sizeof(Contato)); // Aloca memória *dentro* do loop
            if (novo == NULL) {
                perror("Erro ao alocar memória");
                fclose(file);
                return quant; // Ou um código de erro apropriado
            }

            if (fscanf(file, " %49[^\n]%*c", novo->nome) != 1) { // Lê o nome corretamente
                free(novo);
                break; // Ou lida com o erro de leitura
            }
            if (fscanf(file, "%d %d %d%*c", &novo->dia, &novo->mes, &novo->ano) != 3) { // Lê a data corretamente
                free(novo);
                break; // Ou lida com o erro de leitura
            }
            c[i] = novo; // Atribui o *novo* contato ao array
        }
        fclose(file);
    } else {
        printf("\nErro ao abrir arquivo\n");
    }
    return quant;
}

void salvarB(char arq[], Contato **c, int quant) {
    FILE *file = fopen(arq, "wb");
    int i;

    if (file) {
        for (i = 0; i < quant; i++) {
            fwrite(c[i], sizeof(Contato), 1, file);
        }
        fclose(file);
    } else {
        printf("\nErro ao abrir arquivo!\n");
    }
}

int lerB(char arq[], Contato **c) {
    int quant = 0;
    FILE *file = fopen(arq, "rb");

    if (file) {
        while (1) {
            Contato *novo = malloc(sizeof(Contato));
            if (novo == NULL) {
                perror("Erro ao alocar memória");
                fclose(file);
                return quant;
            }
            size_t bytesRead = fread(novo, sizeof(Contato), 1, file);
            if (bytesRead == 1) {
                c[quant] = novo;
                quant++;
            } else {
                free(novo); // Libera a memória alocada se a leitura falhar
                break;
            }
        }
        fclose(file);
    } else {
        printf("\nErro ao abrir arquivo\n");
    }
    return quant;
}

void alterarB(char arq[]) {
    FILE *file = fopen(arq, "rb+");
    Contato c;
    int id, i = 1;
    if (file) {
        printf("\tLista de contatos:\n");
        printf("\t----------------------------\n");
        while (fread(&c, sizeof(Contato), 1, file)) {
            printf("\t%d = %02d/%02d/%04d\t%s\n", i, c.dia, c.mes, c.ano, c.nome);
            i++;
        }
        printf("\t----------------------------\n");
        printf("\n\tDigite o indice do contato que deseja alterar:\n\n");
        scanf("%d", &id);
        getchar();
        id--;
        if (id >= 0 && id < i - 1) {
            printf("\tDigite nome e data de nascimento (dd mm aaaa): ");
            scanf(" %49[^\n]%*c%d%d%d%*c", c.nome, &c.dia, &c.mes, &c.ano); // Consome o newline
            fseek(file, id * sizeof(Contato), SEEK_SET);
            fwrite(&c, sizeof(Contato), 1, file);
            printf("\n\tContato alterado com sucesso!\n");
        } else {
            printf("\n\tIndice inválido!\n");
        }
        fclose(file);
    } else
        printf("\nErro ao abrir arquivo!\n");
}

int main(void) {
    Contato *agenda[50];
    char nome[] = "agenda.txt";
    char arquivoB[] = "agenda.dat";
    int opcao, tam = 50, quant = 0;

    do {
        printf("\n\t 0 - Sair\n\t 1 - Cadastrar\n\t 2 - Alterar (Lista)\n\t 3 - Imprimir (Lista)\n\t 4 - Salvar (Texto)\n\t 5 - Ler (Texto)\n\t 6 - Salvar (Binario)\n\t 7 - Ler (Binario)\n\t 8 - Alterar (Binario)\n");
        printf("\t Escolha uma opção: ");
        scanf("%d", &opcao);
        getchar(); // Consume newline

        switch (opcao) {
            case 0:
                break;
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
                quant = ler_contato(agenda, nome);
                break;
            case 6:
                salvarB(arquivoB, agenda, quant);
                break;
            case 7:
                quant = lerB(arquivoB, agenda);
                break;
            case 8:
                alterarB(arquivoB);
                break;
            default:
                printf("Opção inválida\n");
                break;
        }
    } while (opcao != 0);

    // Liberar a memória alocada
    for (int i = 0; i < quant; i++) {
        free(agenda[i]);
    }

    return 0;
}
