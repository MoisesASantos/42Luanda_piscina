int	check_base(char *base)
{
	int	i;
	int	j;

	if(base[0] == '\0'  || base[1] == '\0')
		return (0);
	while(base[i])
	{
		if(base[i] == '-' || base[i] == '+' || base[i] <= 32)
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

int	check_endereco(char c, char *base)
{
	int	i;

	i = 0;
	while(base[i] != '\0')
	{
		if(base[i] == c)
			return (i);
		i++;
	}
	return (-1);
}

int	ft_atoi_base(char *str, char *base)
{
	int	i;
	int	result;
	int	sinal;
	int	digito;
	int	base_len;

	i = 0;
	sinal = 1;
	result = 0;
	base_len = 0;
	if(!check_base(base))
		return ;
	while(base[base_len])
		base_len++;
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
	digito = check_endereco(str[i], base);
	while(digito != -1)
	{
		result = result * base_len + digito;
		digito = check_endereco(str[i], base);
		i++;
	}
	return (result * sinal);
}
