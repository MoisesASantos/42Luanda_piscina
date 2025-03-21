#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int main(void)
{
	int i, j, temp, numb[100];
	srand(time(NULL));
	for(i = 0; i < 100; i++)
		numb[i] = 1 + rand() % 10;
	for(i = 0; i < 100; i++)
		printf("%d ", numb[i]);
	printf("\n");
	i = 0;
	while(i < 100)
	{
		j  = i + 1;
		while(j < 100)
		{
			if(numb[i] > numb[j])
			{
				temp = numb[i];
				numb[i] = numb[j];
				numb[j] = temp;
			}
			j++;
		}
		i++;
	}
	for(i = 0; i < 100; i++)
                printf("%d ", numb[i]);
        printf("\n");
	return (0);
}
