/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_combn.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mosantos <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 13:08:19 by mosantos          #+#    #+#             */
/*   Updated: 2024/10/31 13:08:24 by mosantos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	print(int *comb, int n)
{
	char	c;
	int		i;

	i = 0;
	while (i < n)
	{
		c = comb[i] + '0';
		write(1, &c, 1);
		i++;
	}
	if (comb[0] != 10 - n)
	{
		write(1, ", ", 2);
	}
}

void	combina(int *comb, int n, int inicio, int depth)
{
	int	i;

	i = inicio;
	if (depth == n)
	{
		print(comb, n);
		return ;
	}
	while (i <= 10 - n + depth)
	{
		comb[depth] = i;
		combina(comb, n, i + 1, depth + 1);
		i++;
	}
}

void	ft_print_combn(int n)
{
	int	comb[10];
	int	idx;

	if (n <= 0 || n >= 10)
	{
		return ;
	}
	idx = 0;
	combina(comb, n, idx, idx);
}
