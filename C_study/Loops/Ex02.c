#include <stdio.h>
#include <string.h>

int main(void)
{
	char str[20];

	int x;

	for( x = 0; x < 3 && strcmp(str, "senha"); ++x)
	{
		printf("Digite a senha por favor: ");
		scanf("%s", str);
	}
	if(x == 3)
		return (0);
}
