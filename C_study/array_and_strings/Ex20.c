#include <stdio.h>
#include <string.h>
#include <ctype.h> // Para tolower() e isalnum()

void frase_palindroma(const char *str)
{
    int inicio = 0;
    int fim = strlen(str) - 1;
    
    while(fim > inicio)
    {
        // Pula caracteres não-alfanuméricos pelo início
        while(inicio < fim && !isalnum(str[inicio]))
            inicio++;
        
        // Pula caracteres não-alfanuméricos pelo fim
        while(inicio < fim && !isalnum(str[fim]))
            fim--;
        
        // Compara os caracteres (case-insensitive)
        if(tolower(str[inicio]) != tolower(str[fim]))
        {
            printf("Falso\n");
            return;
        }
        
        inicio++;
        fim--;
    }
    
    printf("Verdadeiro\n");
}


int main(void)
{
	char palavras[25] = "A grama é amarga ";
	frase_palindroma(palavras);
	return (0);
}
