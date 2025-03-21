#include <stdio.h>
#include <string.h>

#define MAX 100
#define LEN 80

char text[MAX][LEN];

int main(void)
{
	register int t, i, j;

	printf("Digite uma linha vazia para sair.\n");
	for(t = 0; t < MAX; t++)
	{
		printf("%d: ", t);
		fgets(text[t], LEN, stdin);
		 if (text[t][strlen(text[t]) - 1] == '\n')
            text[t][strlen(text[t]) - 1] = '\0';
		if(!*text[t])
		{
			break;
		}
	}
	for(i = 0; i < t; i++)
	{
		for(j = 0; text[i][j]; j++)
			putchar(text[i][j]);
		putchar('\n');
	}
	return (0);
}
