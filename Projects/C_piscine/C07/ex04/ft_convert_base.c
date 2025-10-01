/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mosantos <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 17:48:26 by mosantos          #+#    #+#             */
/*   Updated: 2024/11/04 00:13:17 by mosantos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		ft_strlen(char *str);
int		ft_atoi_base(char *str, char *base);
char	*ft_convert_base2(int nbr, char *base, char *result, int size);

int	check_base(char *base)
{
	int	i;
	int	j;

	i = 0;
	if (ft_strlen(base) <= 1)
		return (0);
	while (base[i])
	{
		if (base[i] == '+' || base[i] == '-' || base[i] <= 32)
			return (0);
		j = i + 1;
		while (base[j])
		{
			if (base[i] == base[j])
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

char	*ft_convert_base(char *nbr, char *base_from, char *base_to)
{
	int		num;
	int		base_to_len;
	int		size;
	char	*result;

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

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}
