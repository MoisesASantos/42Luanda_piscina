#include <stdio.h>

/*int main(void)
{
	int matriz[4];
	int i, maior, menor;

	i = 1;
	printf("digite o valores de a, b, e c: ");
	scanf("%d%d%d", &matriz[0], &matriz[1], &matriz[2]);
	menor = matriz[0];
        maior = matriz[0];
	while(i < 3)
	{
		if(matriz[i] > maior)
			maior = matriz[i];
		else if(matriz[i] < menor)
		       menor = matriz[i];
		i++;
	}	
	printf("O maior valor é %d\n", maior);
	printf("O menor valor é %d\n", menor);
	return (0);
}*/

int main(void)
{
	int a, b, c, maior, menor;

	printf("Digite o valores de a, b, c\n");
	scanf("%d%d%d", &a, &b, &c);
	maior = a;
	menor = a;
	
	if(b > maior)
		maior = b;
	if(c > maior)
		maior = c;
	if(b < menor)
		menor = b;
	if( c < menor)
		menor = c;
	printf("O maior valor é %d\n", maior);
	printf("O menor valor é %d\n", menor);
	return (0);
}	
