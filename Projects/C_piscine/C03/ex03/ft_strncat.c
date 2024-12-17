/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mosantos <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/26 20:43:08 by mosantos          #+#    #+#             */
/*   Updated: 2024/10/26 20:43:16 by mosantos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strncat(char *dest, char *src, unsigned int nb)
{
	char			*ptr;
	unsigned int	i;

	ptr = dest;
	while (*ptr != '\0')
		ptr++;
	i = 0;
	while (src[i] != '\0' && i < nb)
	{
		*ptr = src[i];
		ptr++;
		i++;
	}
	*ptr = '\0';
	return (dest);
}
