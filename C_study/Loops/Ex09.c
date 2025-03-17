#include <stdio.h>

int main(void)
{
	int N;
	int result;

	result = 0;
	do{
		printf("Digite um valor para N: ");
		scanf("%d", &N);
	}while(N < 0);
	for(int i = 1; i <= N; i++)
	{
		if(i % 2 == 0)
		{
			result = i * i;
			printf("%d\n", result);
		}
	}
	return (0);
}	
