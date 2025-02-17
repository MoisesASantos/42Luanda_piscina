#include <stdlib.h>

int	ft_strlen(char *str);
int	get_base_value(char c, char *str);
int	check_base(char *str);

int	ft_atoi_base(char *str, char *base)
{
	int	i;
	int	sinal;
	int	result;
	int	base_len;
	int	digito;

	if(!check_base(base))
		return (0);
	base_len = 0;
	base_len = ft_strlen(base);
	i = 0;
	sinal = 1;
	result = 0;
	while(str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
		i++;
	while(str[i] == '-' || str[i] == '+')
	{
		if(str[i] == '-')
		{
			sinal = -sinal;
		}
		i++;
	}
	digito = get_base_value(str[i], base);
	while(digito != -1)
	{
		result = result * base_len + digito;
		i++;
		digito = get_base_value(str[i], base);
	}
	return (result * sinal);
}

int	ft_convert_base2(int nbr, char *base, char *resul, int size)
{
	int	i;
	long	n;
	int	base_len;

	base_len = 0;
	while(base[base_len] != '\0')
		base_len++;
	result[0] = '\0';
	n = nbr;
	if(n < 0)
	{
		result[0] = '-';
		n = -n;
	}
	if(n == 0)
	{
		result[0] = base[0];
	}
	i = size - 1;
	while(n > 0)
	{
		result[i] = base[n % base_len];
		n /= base_len;
		i--;
	}
	return (result);
}

char *ft_convert_base(char *nbr, char *base_from, char *base_to)
{
    int num;
    int base_to_len;
    int size;
    char *result;

    if (!check_base(base_from) || !check_base(base_to))
        return (NULL);
    num = ft_atoi_base(nbr, base_from);
    base_to_len = ft_strlen(base_to);
    size = 1;
    if (num < 0)
        size = 2;
    while (num / base_to_len != 0)
    {
        num /= base_to_len;
        size++;
    }
    result = malloc(size + 1);
    if (!result)
        return (NULL);
    return (ft_convert_base2(ft_atoi_base(nbr, base_from),
            base_to, result, size));
}
