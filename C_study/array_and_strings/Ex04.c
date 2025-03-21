#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int main(void)
{
	int i, j, temp, N[20], N2[20];
	srand(time(NULL));
	for(i = 0; i < 20; i++)
		N[i] = 1 + rand() % 10;
	for(j = 0; j < 20; j++)
	{
		N2[j] = N[j];
	}
	i = 0;
	j = 20;
	while(i < 10)
	{
		temp = N2[i];
	       	N2[i] = N2[j - 1];
		N2[j - 1] = temp;
		i++;
		j--;
	}	
	for(i = 0; i < 20; i++)
		printf("%d ", N[i]);
	printf("\n");
	for(i = 0; i < 20; i++)
		printf("%d ", N2[i]);
	printf("\n");
	return (0);
}



