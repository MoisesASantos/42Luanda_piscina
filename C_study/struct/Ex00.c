#include <stdio.h>

int main(void)
{
	struct {
		int a;
		int b;
	} x, y;

	x.a = 10;
	y = x;
	printf("%d\n", y.a);
	return (0);
}
