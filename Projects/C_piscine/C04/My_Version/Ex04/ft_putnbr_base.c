#include <unistd.h>

int	ft_base_valida(char *base)
{
	int	i;
	int	j;

	i = 0;
	if(base[0] == '\0' || base[1] == '\0')
		return (0);
	while(base[i])
	{
		if(base[i] == '-' || base[i] == '+')
			return (0);
		j = i + 1;
		while(base[j])
		{
			if(base[i] == base[j])
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

void	ft_putnbr_base(int nbr, char *base)
{
	long int		base_len;
	long int		num;

	base_len = 0;
	num = 0;
	if(!ft_base_valida(base))
		return ;
	while(base[base_len])
		base_len++;
	num =(long int)nbr;
	if(num < 0)
	{
		write(1, "-", 1);
		num = -num;
	}
	if(num >= base_len)
	{
		ft_putnbr_base(num / base_len, base);
	}
	write(1, &base[num % base_len], 1);
}
	
