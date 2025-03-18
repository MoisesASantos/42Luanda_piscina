#include <stdio.h>

int main(void)
{
	int x;
	int y;

	printf("Digite os valores de X e Y: ");
	scanf("%d%d", &x, &y);
	for(int j = 1; j <= y; j++)
	{
		printf("%d ", j);
		if(j % x == 0)
			printf("\n");
	}
	printf("\n");
	return (0);
}
