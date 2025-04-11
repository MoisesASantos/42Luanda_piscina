#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

void palinword(char *str)
{
	int i;
	int len;
	char *src;

	i = 0;
	len = strlen(str);
	src = malloc(sizeof(char) * len + 1);
	if(src == NULL)
		return;
	while(i < len)
	{
		src[i] = str[len - 1 - i];
		i++;
	}
	src[len] = '\0';
	i = 0;
	while(i < len)
	{
		if(tolower(str[i]) != tolower(src[i]))
		{
			printf("falso\n");
			free(src);
			return;
		}
		i++;
	}
	printf("verdadeiro\n");
	free(src);
}

int main(void)
{
	char palavras[25] = "Ana";

	palinword(palavras);
	return (0);
}
