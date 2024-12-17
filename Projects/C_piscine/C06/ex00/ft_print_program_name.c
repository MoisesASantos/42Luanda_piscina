/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_program_name.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mosantos <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 10:42:45 by mosantos          #+#    #+#             */
/*   Updated: 2024/10/30 10:42:54 by mosantos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	str_size(char *str)
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
	int	size;

	if (argc != 1)
		return (0);
	size = str_size(argv[0]);
	write(1, argv[0], size);
	write(1, "\n", 1);
	return (0);
}
