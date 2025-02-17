#include <unistd.h>

int	ft_strlen(char *str)
{
	int	i;
	while(str[i] != '\0')
	{
		i++;
	}
	return (i);
}

int	get_base_value(char c, char *base)
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

int	check_sign_and_spaces(char **str)

int	check_base(char	*base)
{
	int	i;
	int	j;

	i = 0;
	if(ft_strlen(base) <= 1)
		return (0);
	while(base[i] != '\0')
	{
		if(base[i] == '-' || base[i] == '+')
			return (0);
		j = i + 1;
		while(base[j] != '\0')
		{
			if(base[i] == base[j])
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}
