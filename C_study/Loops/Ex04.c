#include <stdio.h>

int main(void)
{
	int i;
	int j;
	int result;

	j = 1;
	result = 0;
	do{
		printf("Digite um valor entre 1 e 10: ");
		scanf("%d", &i);
		if(i >= 1 && i <= 10)
		{
			while( j <= 10)
			{
				printf(" %d * %d = %d\n", i, j, result = i * j);
				j++;
			}
		}
	}while(j < 11);
	return (0);
}
