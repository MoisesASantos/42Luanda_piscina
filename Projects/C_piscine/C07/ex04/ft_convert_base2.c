/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mosantos <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 00:15:58 by mosantos          #+#    #+#             */
/*   Updated: 2024/11/04 00:16:05 by mosantos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	get_base_value(char c, char *base)
{
	int	i;

	i = 0;
	while (base[i])
	{
		if (base[i] == c)
			return (i);
		i++;
	}
	return (-1);
}

int	skip_whitespace_and_signs(char **str)
{
	int	sign;

	sign = 1;
	while (**str == ' ' || (**str >= 9 && **str <= 13))
		(*str)++;
	while (**str == '+' || **str == '-')
	{
		if (**str == '-')
			sign *= -1;
		(*str)++;
	}
	return (sign);
}

int	ft_atoi_base(char *str, char *base)
{
	int	result;
	int	sign;
	int	digit;
	int	base_len;

	result = 0;
	base_len = 0;
	while (base[base_len])
		base_len++;
	sign = skip_whitespace_and_signs(&str);
	while (*str)
	{
		digit = get_base_value(*str, base);
		if (digit == -1)
			break ;
		result = result * base_len + digit;
		str++;
	}
	return (result * sign);
}

char	*ft_convert_base2(int nbr, char *base,
		char *result, int size)
{
	int		base_len;
	int		i;
	long	n;

	base_len = 0;
	while (base[base_len])
		base_len++;
	result[size] = '\0';
	n = nbr;
	if (n < 0)
	{
		result[0] = '-';
		n = -n;
	}
	if (n == 0)
		result[0] = base[0];
	i = size - 1;
	while (n > 0)
	{
		result[i] = base[n % base_len];
		n /= base_len;
		i--;
	}
	return (result);
}
