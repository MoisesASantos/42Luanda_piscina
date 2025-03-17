#include <stdio.h>

#define NUM_ALUNOS 45

int main(void)
{
    int idade_alunos[NUM_ALUNOS]; 
    float altura_alunos[NUM_ALUNOS];
    int i;

    for (i = 0; i < NUM_ALUNOS; i++) {
        printf("Digite a idade do aluno %d: ", i + 1);
        scanf("%d", &idade_alunos[i]);
        printf("Digite a altura do aluno %d (em metros): ", i + 1);
        scanf("%f", &altura_alunos[i]);
    }

    float altura_total = 0; 
    int idade_total = 0; 
    int count1 = 0; 
    int count2 = 0;

    for (i = 0; i < NUM_ALUNOS; i++) {
        if (idade_alunos[i] > 20) {
            altura_total += altura_alunos[i];
            count1++;
        }

        if (altura_alunos[i] < 1.70) {
            idade_total += idade_alunos[i];
            count2++;
        }
    }
    float altura_media = (count1 > 0) ? altura_total / count1 : 0;
    float idade_media = (count2 > 0) ? (float)idade_total / count2 : 0;

    printf("\nResultados:\n");
    printf("a) Altura média dos alunos com mais de 20 anos: %.2f metros\n", altura_media);
    printf("b) Idade média dos alunos com menos de 1,70m: %.2f anos\n", idade_media);

    return 0;
}
