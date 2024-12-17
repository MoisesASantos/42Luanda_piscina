/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mosantos <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/26 18:49:56 by mosantos          #+#    #+#             */
/*   Updated: 2024/10/26 19:06:59 by mosantos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strcapitalize(char *str)
{
	int	i;
	int	inicial;

	i = 0;
	inicial = 1;
	while (str[i] != '\0')
	{
		if ((str[i] >= 'a' && str[i] <= 'z')
			|| (str[i] >= 'A' && str[i] <= 'Z'))
		{
			if (inicial && (str[i] >= 'a' && str[i] <= 'z'))
				str[i] -= 32;
			else if (!inicial && (str[i] >= 'A' && str[i] <= 'Z'))
				str[i] += 32;
			inicial = 0;
		}
		else if (str[i] >= '0' && str[i] <= '9')
			inicial = 0;
		else
			inicial = 1;
		i++;
	}
	return (str);
}
