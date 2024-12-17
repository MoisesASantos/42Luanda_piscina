/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_params.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mosantos <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 11:07:52 by mosantos          #+#    #+#             */
/*   Updated: 2024/10/30 11:08:06 by mosantos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	str_comp(char *str)
{
	int	comp;

	comp = 0;
	while (str[comp] != '\0')
	{
		comp++;
	}
	return (comp);
}

int	main(int argc, char *argv[])
{
	int	i;

	i = 1;
	while (i < argc)
	{
		write(1, argv[i], str_comp(argv[i]));
		write(1, "\n", 1);
		i++;
	}
	return (0);
}
