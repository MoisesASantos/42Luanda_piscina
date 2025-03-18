#include <stdio.h>

int main(void)
{
	int x;
	int y;

	do{
		printf("Digite as cordenadas X e Y: ");
		scanf("%d%d", &x, &y);
		if(x > 0 && y > 0)
			printf("Primeiro\n");
		if(x < 0 && y > 0)
			printf("Segundo\n");
		if( x < 0 && y < 0)
			printf("Terceiro\n");
		if(x > 0 && y < 0)
			printf("Quarto\n");
	}while(x != 0 && y != 0);
	return (0);
}
