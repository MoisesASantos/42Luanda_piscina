#include <stdio.h>

int factorial(int n)
{
	if(n == 1 || n == 0)
		return 1;
	else{
		return n * factorial(n - 1);
	}
}

int main(void)
{
	int n = 3;
	printf("%d\n", factorial(n));
	return (0);
}
