#include <unistd.h>

void	ft_print_combn(int n)
{
	char	comb[10];
	int		i;

	i = 0;
	if(n <= 0 || n >= 10)
		return ;
	while( i < n)
	{
		comb[i] = '0' + i;
		i++;
	}
	while(1)
	{
		write(1, comb, n);
		if( comb[0] == '9' - n + 1)
			break ;
		write(1, ", ", 2);
		i = n - 1;
		while( i >= 0)
		{
			if(comb[i] < '9' - (n - 1 - i))
			{
				comb[i]++;
				while(++i < n)
				{
					comb[i] = comb[i - 1] + 1;
				}
				break ;
			}
			i--;
		}
	}
}

int main(void)
{
	ft_print_combn(2);
	write(1, "\n", 1);
	return (0);
}
