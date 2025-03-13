#include <stdio.h>

int main(void)
{
	int x;
	int y;
        for(x = 0, y = 0; x + y < 10; ++x)
        {
                y = getchar();
		y = y - '0';
        }
        return (0);
}

/*int main(void)
{
	float z;
	for(int x = 100; x > 65; x -= 5)
	{
		z = x * x;
		printf("O quadrado de %d é %.2f\n", x, z);
	}
	return (0);
}*/
