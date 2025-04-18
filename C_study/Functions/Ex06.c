#include <stdio.h>

int	ft_recursive_power(int nb, int power)
{
	if (power < 0)
		return (0);
	if (power == 0)
		return (1);
	return (nb * ft_recursive_power(nb, power - 1));
}

int main(void)
{
	int n = 3;
	int x = 3;
	printf("%d\n", ft_recursive_power(n, x));
	return (0);
}
