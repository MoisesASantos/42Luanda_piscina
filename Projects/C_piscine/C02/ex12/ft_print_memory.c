/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_memory.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mosantos <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 17:00:00 by mosantos          #+#    #+#             */
/*   Updated: 2024/11/04 00:34:00 by mosantos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	print_hex(unsigned long n, int len)
{
	char	*hex;

	hex = "0123456789abcdef";
	if (len > 1)
		print_hex(n >> 4, len - 1);
	write(1, &hex[n & 15], 1);
}

void	print_ascii(unsigned char *p, unsigned int size, unsigned int offset)
{
	unsigned int	i;

	i = 0;
	while (i < 16 && offset + i < size)
	{
		if (p[i] >= 32 && p[i] <= 126)
			write(1, &p[i], 1);
		else
			write(1, ".", 1);
		i++;
	}
	write(1, "\n", 1);
}

void	print_hex_content(unsigned char *p, unsigned int size,
		unsigned int offset)
{
	unsigned int	i;

	i = 0;
	while (i < 16)
	{
		if (offset + i < size)
			print_hex(p[i], 2);
		else
			write(1, "  ", 2);
		if (i % 2)
			write(1, " ", 1);
		i++;
	}
}

void	print_line(void *addr, unsigned int size, unsigned int offset)
{
	unsigned char	*p;

	p = (unsigned char *)addr + offset;
	print_hex((unsigned long)p, 16);
	write(1, ": ", 2);
	print_hex_content(p, size, offset);
	print_ascii(p, size, offset);
}

void	*ft_print_memory(void *addr, unsigned int size)
{
	unsigned int	offset;

	if (size == 0)
		return (addr);
	offset = 0;
	while (offset < size)
	{
		print_line(addr, size, offset);
		offset += 16;
	}
	return (addr);
}
