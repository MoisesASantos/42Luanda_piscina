#include <stdio.h>

int main(void)
{
	int multi;
	int n;
	int result;

	multi = 7;
	for(n = 1; n <= 9999; n++)
	{
		result = 0;
		result = multi * n;
		printf("%d\n", result);
		fflush(stdout);
	}
	return (0);
}
