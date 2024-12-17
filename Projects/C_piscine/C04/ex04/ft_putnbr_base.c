/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mosantos <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 14:04:28 by mosantos          #+#    #+#             */
/*   Updated: 2024/10/28 14:04:37 by mosantos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int	base_valida(char *base)
{
	int	i;
	int	j;

	i = 0;
	if (base[0] == '\0' || base[1] == '\0')
		return (0);
	while (base[i])
	{
		if (base[i] == '+' || base[i] == '-')
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

void	ft_putnbr_base(int nbr, char *base)
{
	long int	base_len;
	long int	num;

	base_len = 0;
	if (!base_valida(base))
		return ;
	while (base[base_len])
	{
		base_len++;
	}
	num = (long int)nbr;
	if (num < 0)
	{
		ft_putchar('-');
		num = -num;
	}
	if (num >= base_len)
		ft_putnbr_base(num / base_len, base);
	ft_putchar(base[num % base_len]);
}
