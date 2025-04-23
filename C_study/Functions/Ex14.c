#include <stdio.h>
#include <time.h>

int fiboR(int n)
{
	if( n == 1)
		return 0;
	if( n == 2)
		return 1;
	else
		return fiboR(n - 1) + fiboR(n - 2);
}

int fiboI(int n)
{
	int a = 0, b = 1, c, i = 0;
	if(n == 1)
		return 0;
	if(n == 2)
		return 1;
	else
	{
		while(i < n)
		{
			c = a + b;
			a = b;
			b = c;
			i++;
		}
		return c;
	}
}

int main(void)
{
	int n = 30;
	time_t tIni, tFim;

	tIni = time(NULL);
	printf("Fibonacci iterativo: %d\n", fiboI(n));
	tFim = time(NULL);
	printf("\tTempo em segundos: %f\n\n", difftime(tFim, tIni));
	
	tIni = time(NULL);
        printf("Fibonacci recursivo: %d\n", fiboI(n));
        tFim = time(NULL);
        printf("\tTempo em segundos: %f\n\n", difftime(tFim, tIni));

	return (0);
}
