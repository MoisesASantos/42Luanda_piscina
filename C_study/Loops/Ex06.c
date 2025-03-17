#include <stdio.h>

int main(void)
{
	int i;
	int total;
	int count;

	count = 0;
	total = 0;
	for(i = 1; i <= 1000; i+=2)
	{
		if(i % 2 != 0)
		{
			total += i;
		}
		count++;
	}
	printf("O total da soma de números ímpares entre 1 a 1000 é %d e o count é %d\n", total, count);
	return (0);
}
