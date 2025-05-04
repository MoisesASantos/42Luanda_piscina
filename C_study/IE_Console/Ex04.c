#include <stdio.h>

int main(void)
{
	unsigned num;

	for(num = 0; num < 255; num++)
	{
		printf("%o\n", num);
		printf("%x\n", num);
		printf("%X\n", num);
	}
	return (0);
}
