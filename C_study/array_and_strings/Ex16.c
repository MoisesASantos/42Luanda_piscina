#include <stdio.h>

int main(void)
{
	int i, j, soma = 0;
	int colunas[4] = {0}, linhas[4] = {0}, diagonal[2] = {0};
	int array[4][4] = {16,3,2,13,5,10,11,8,9,6,7,12,4,15,14,1};
	 int found[17] = {0};
	 for (i = 0; i < 4; i++)
	 {
        	for (j = 0; j < 4; j++)
        	{
            		int num = array[i][j];
            		if (found[num] == 1)
			{
                		printf("Não é um quadrado mágico\n");
                		return 0;
			}
            		found[num] = 1;
		}
	 }
	for(i = 0; i < 4; i++)
	{
		soma = 0;
		for(j = 0; j < 4; j++)
			soma += array[i][j];
		linhas[i] = soma;
	}
	for(i = 0; i < 4; i++)
        {
                soma = 0;
                for(j = 0; j < 4; j++)
                        soma += array[j][i];
                colunas[i] = soma;
        }
	for(i = 0; i < 4; i++)
		diagonal[0] += array[i][i];
	for(i = 0; i < 4; i++)
		diagonal[1] = array[i][3 - i];
	int magic_sum = linhas[0];
	i = 0;
	while(i < 4)
	{
		if(colunas[i] != magic_sum || linhas[i] != magic_sum)
		{
			printf("Não é um quadrado mágico\n");
			return (0);
		}
		i++;
	}

	if(diagonal[1] != magic_sum || diagonal[0] != magic_sum)
	{	
		printf("Não é um quadrado mágico\n");
		return (0);
	}
	printf("É um quadrado mágico\n");
	return (0);
}	
