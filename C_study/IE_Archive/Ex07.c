#include <stdio.h>
#include <string.h>

void escrever(char f[]) {
    FILE *file = fopen(f, "w");
    char nome[100];
    int opcao, idade;
    float altura;
    if(file) {
        do{
            printf("Digite nome, idade e altura: ");
            scanf("%100[^\n]%d%f", nome, &idade, &altura);
            fprintf(file, "%s %d %.2f\n", nome, idade, altura);
            printf("\nDigite 1 para inserir outro registro. ");
            scanf("%d", &opcao);
            getchar();
        }while(opcao == 1);
        fclose(file);
    } else
        printf("\nERRO ao abrir arquivo!\n");
}
void ler(char f[]) {
    FILE *file = fopen(f, "r");
    char nome[100];
    int idade;
    float altura;
    if(file){
        printf("\tDados lidos do arquivo:\n");
        while(fscanf(file, "%s%d%f", nome, &idade, &altura) != -1)
            printf("\n\tNome: %s\n\tIdade: %d\n\tAltura: %.2f\n", nome, idade, altura);
        fclose(file);
    }
    else
        printf("\nERRO ao abrir arquivo!\n");
}
int main() {
    char nome[] = {"conto.txt"};
    escrever(nome);
    ler(nome);
    return 0;
}
