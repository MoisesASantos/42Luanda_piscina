#include <unistd.h>

void	ft_print_comb2(void)
{
	char		comb[5];
	int	i;
	int	j;

	i = 0;
	while(i <= 98)
	{
		j = i + 1;
		while(j <= 99)
		{
			comb[0] = (i / 10) + '0';
			comb[1] = (i % 10) + '0';
			comb[2] = ' ';
			comb[3] = (j / 10) + '0';
			comb[4] = (j % 10) + '0';
			write(1, comb, 5);
			if(i != 98 || j != 99)
			{
				write(1, ", ", 1);
			}
			j++;
		}
		i++;
	}
}

int	main(void)
{
	ft_print_comb2();
	write(1, "\n", 1);
	return (0);
}
