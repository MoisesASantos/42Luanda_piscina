#include <stdio.h>
#include <string.h>

int main(void)
{
	char str[80];

	fgets(str, 80, stdin);
	int len = strlen(str);
	if(str[len - 1] == '\n')
		str[len - 1] = 0;
	printf("o comprimento é %ld\n", strlen(str));
	return (0);
}
