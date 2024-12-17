/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mosantos <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 18:05:32 by mosantos          #+#    #+#             */
/*   Updated: 2024/10/28 18:05:37 by mosantos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	check_base(char *base)
{
	int	i;
	int	j;

	i = 0;
	while (base[i])
		i++;
	if (i < 2)
		return (0);
	i = 0;
	while (base[i])
	{
		if (base[i] == '+' || base[i] == '-' || base[i] <= 32)
			return (0);
		j = i + 1;
		while (base[j] && base[i] != base[j])
			j++;
		if (base[j])
			return (0);
		i++;
	}
	return (i);
}

int	base_endereco(char c, char *base)
{
	int	i;

	i = 0;
	while (base[i] && base[i] != c)
		i++;
	if (base[i])
		return (i);
	return (-1);
}

void	espaco_sinal(char **str, int *sinal)
{
	while (**str == ' ' || (**str >= 9 && **str <= 13))
		(*str)++;
	while (**str == '+' || **str == '-')
	{
		if (**str == '-')
			*sinal *= -1;
		(*str)++;
	}
}

int	ft_atoi_base(char *str, char *base)
{
	int	resultado;
	int	sinal;
	int	digito;
	int	base_len;

	base_len = check_base(base);
	if (!base_len)
		return (0);
	resultado = 0;
	sinal = 1;
	espaco_sinal(&str, &sinal);
	digito = base_endereco(*str, base);
	while (*str && digito != -1)
	{
		resultado = resultado * base_len + digito;
		str++;
		digito = base_endereco(*str, base);
	}
	return (resultado * sinal);
}
