#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	int *x;
	
	x = malloc(sizeof(int));
	if(x == NULL)
		return 1;
	*x = 50;
	printf("%d\n", *x);	
	return (0);
}
