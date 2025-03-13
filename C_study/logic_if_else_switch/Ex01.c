#include <stdio.h>

int main(void)
{
	unsigned int i;
	int j;

	i = 1;

	for(j = 0; j < 4; j++)
	{
		i = i << 1;
		printf("deslocamento á esquerda %d: %d\n", j, i);
	}
	for(j = 0; j < 4; j++)
	{
		i = i >> 1;
		printf("deslocamento á direita %d: %d\n", j , i);
	}
	return (0);
}
