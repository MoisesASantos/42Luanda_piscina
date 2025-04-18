#include <stdio.h>

int soma(int n)
{
	if( n == 1)
		return 1;
	return  n + soma(n - 1);
}

int main(void)
{
	int i = 6;
	printf("%d\n", soma(i));
	return (0);
}
