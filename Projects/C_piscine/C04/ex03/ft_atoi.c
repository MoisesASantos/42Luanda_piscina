/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mosantos <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 13:52:55 by mosantos          #+#    #+#             */
/*   Updated: 2024/10/28 13:58:51 by mosantos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	e_espaco(char c)
{
	return (c == ' ' || (c >= 9 && c <= 13));
}

int	e_sinal(char c)
{
	return (c == '+' || c == '-');
}

int	e_digito(char c)
{
	return (c >= '0' && c <= '9');
}

int	ft_atoi(char *str)
{
	int	sinal;
	int	resultado;

	sinal = 1;
	resultado = 0;
	while (e_espaco(*str))
		str++;
	while (e_sinal(*str))
	{
		if (*str == '-')
			sinal = -sinal;
		str++;
	}
	while (e_digito(*str))
	{
		resultado = resultado * 10 + (*str - '0');
		str++;
	}
	return (resultado * sinal);
}
