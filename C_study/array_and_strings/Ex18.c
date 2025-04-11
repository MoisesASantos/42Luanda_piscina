#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
	char palavras[20] = "bom dia alunos";
	char *pt;

	pt = strtok(palavras, " ");
	while(pt)
	{
		printf("token: %s\n", pt);
		pt = strtok(NULL, " ");
	}
	return (0);
}
