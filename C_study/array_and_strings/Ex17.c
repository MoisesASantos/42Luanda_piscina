#include <stdio.h>

#define JOGADOR_X 'X'
#define JOGADOR_O 'O'
#define VAZIO ' '

void inicializar(char game[3][3]) {
    for(int i = 0; i < 3; i++) {
        for(int j = 0; j < 3; j++) {
            game[i][j] = VAZIO;
        }
    }
}

void imprimir(char game[3][3]) {
    printf("\n   0   1   2\n");  // Cabeçalho das colunas
    for(int i = 0; i < 3; i++) {
        printf("%d ", i);  // Número da linha
        for(int j = 0; j < 3; j++) {
            printf(" %c ", game[i][j]);
            if(j < 2) printf("|");
        }
        printf("\n");
        if(i < 2) printf("  ---+---+---\n");
    }
    printf("\n");
}

void jogadas(char game[3][3], char jogador) {
    int i, j;
    
    while(1) {
        printf("Jogador %c, escolha a posição (linha coluna): ", jogador);
        if(scanf("%d%d", &i, &j) != 2) {
            printf("Entrada inválida. Digite dois números entre 0 e 2.\n");
            while(getchar() != '\n');  // Limpa o buffer de entrada
            continue;
        }
        
        if(i < 0 || i > 2 || j < 0 || j > 2) {
            printf("Posição inválida. Use valores entre 0 e 2.\n");
            continue;
        }
        
        if(game[i][j] != VAZIO) {
            printf("Posição já ocupada. Escolha outra.\n");
            continue;
        }
        
        break;
    }
    
    game[i][j] = jogador;
}

int verificar_vencedor(char game[3][3], char jogador) {
    // Verificar linhas e colunas
    for(int i = 0; i < 3; i++) {
        if((game[i][0] == jogador && game[i][1] == jogador && game[i][2] == jogador) ||
           (game[0][i] == jogador && game[1][i] == jogador && game[2][i] == jogador)) {
            return 1;
        }
    }
    // Verificar diagonais
    if((game[0][0] == jogador && game[1][1] == jogador && game[2][2] == jogador) ||
       (game[0][2] == jogador && game[1][1] == jogador && game[2][0] == jogador)) {
        return 1;
    }
    return 0;
}

int verificar_empate(char game[3][3]) {
    for(int i = 0; i < 3; i++) {
        for(int j = 0; j < 3; j++) {
            if(game[i][j] == VAZIO) {
                return 0;
            }
        }
    }
    return 1;
}

int main(void) {
    char game[3][3];
    char jogador_atual = JOGADOR_X;
    int continuar = 1;
    
    printf("Bem-vindo ao Jogo da Velha!\n");
    printf("Jogador 1: X\nJogador 2: O\n\n");
    
    while(continuar) {
        inicializar(game);
        jogador_atual = JOGADOR_X;
        
        while(1) {
            imprimir(game);
            jogadas(game, jogador_atual);
            
            if(verificar_vencedor(game, jogador_atual)) {
                imprimir(game);
                printf("Parabéns! Jogador %c venceu!\n", jogador_atual);
                break;
            }
            
            if(verificar_empate(game)) {
                imprimir(game);
                printf("Empate! O jogo terminou sem vencedor.\n");
                break;
            }
            
            jogador_atual = (jogador_atual == JOGADOR_X) ? JOGADOR_O : JOGADOR_X;
        }
        
        printf("\nDeseja jogar novamente? (1-Sim, 0-Não): ");
        scanf("%d", &continuar);
    }
    
    printf("Obrigado por jogar!\n");
    return 0;
}
