#include <stdio.h>

char	ft_strcpy(char *dest, char *src)
{
	while(*src)
	{
		*dest = *src;
		dest++;
		src++;
	}
	*dest = '\0';
	return (*dest);
}

int main(void)
{
	char nome[10] = "Adolfo";
	char sob[10] = "Santos";
	ft_strcpy(nome, sob);
	printf("%s\n", nome);
	printf("%s\n", sob);
	return (0);
}
