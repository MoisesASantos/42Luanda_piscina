#include <stdio.h>
#include <string.h>

typedef struct
{
    char type[100];
    char brand[50];
    char model[25];
    char energy;
    char description[500];
    int quant;
    int code;
} Electronico;

void printEle(Electronico e)
{
    printf("\tType: %s", e.type);
    printf("\tBrand: %s", e.brand);
    printf("\tModel: %s", e.model);
    printf("\tEnergy: %c\n", e.energy);
    printf("\tDescription: %s", e.description);
    printf("\tQuantity: %d\n", e.quant);
    printf("\tCode: %d\n", e.code);
}

Electronico readEle()
{
    Electronico e;
    printf("Write type: ");
    fgets(e.type, sizeof(e.type), stdin);
    e.type[strcspn(e.type, "\n")] = 0; // Remove newline

    printf("Write brand: ");
    fgets(e.brand, sizeof(e.brand), stdin);
    e.brand[strcspn(e.brand, "\n")] = 0; // Remove newline

    printf("Write model: ");
    fgets(e.model, sizeof(e.model), stdin);
    e.model[strcspn(e.model, "\n")] = 0; // Remove newline

    printf("Write energy: ");
    scanf(" %c", &e.energy); // Space before %c to consume any leftover newline
    getchar(); // Consume the newline character left by scanf

    printf("Write Description: ");
    fgets(e.description, sizeof(e.description), stdin);
    e.description[strcspn(e.description, "\n")] = 0; // Remove newline

    printf("Quant and code: ");
    scanf("%d%d", &e.quant, &e.code);

    return e; // Return the populated structure
}

int main(void)
{
    Electronico ele;
    ele = readEle();
    printEle(ele);
    return 0;
}
