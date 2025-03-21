#include <stdio.h>

int main(void)
{
	int i, indice;
	float maiorMedia, menorMedia, mediaTemp[12];
	char *month[] = {"Janeiro", "Fevereiro", "Março", "Abril", "Maio", "Junho", "Julho", "Agosto", "Setembro", "Outro", "Novembro", "Dezembro"};

	for(i = 0; i < 12; i++)
	{
		printf("Digite a média de temperatura %d: ", i + 1);
		scanf("%f", &mediaTemp[i]);
		printf("\n");
	}
	maiorMedia = mediaTemp[0];
	menorMedia = mediaTemp[0];
	i = 1;
	indice = 0;
	while(i < 12)
	{
		if(maiorMedia < mediaTemp[i])
		{
			maiorMedia = mediaTemp[i];
			indice = i;
		}
		i++;
	}
	printf("A maior média de temperatura foi de %.2f e ocorreu no mes %s\n", maiorMedia, month[indice]);
	i = 1;
        indice = 0;
        while(i < 12)
        {
                if(menorMedia > mediaTemp[i])
                {
                        menorMedia = mediaTemp[i];
                        indice = i;
                }
                i++;
        }
	printf("A menor média de temperatura foi de %.2f e ocorreu no mes %s\n", menorMedia, month[indice]);
	return (0);
}



