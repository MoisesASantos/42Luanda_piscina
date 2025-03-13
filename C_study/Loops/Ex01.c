#include <stdio.h>
#include <graph.h>
#include <string.h>

void converge(int line, char *message);

int main(void)
{
	converge(10, "Isto é um teste de converge().");
	return (0);
}

void converge(int line, char *message)
{
	int i, j;

	for(i = 1, j = strlen(message); i < j; j--)
	{
		_settextposition(line, i);
		printf("%c", message[i - 1]);
		_settextposition(line, j);
		printf("%c", message[j - 1]);
	}
}
