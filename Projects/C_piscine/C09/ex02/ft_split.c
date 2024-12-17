/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mosantos <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 16:55:55 by mosantos          #+#    #+#             */
/*   Updated: 2024/11/05 17:05:11 by mosantos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

static int	is_charset(char c, char *charset)
{
	while (*charset)
	{
		if (c == *charset)
			return (1);
		charset++;
	}
	return (0);
}

static int	count_palavras(char *str, char *charset)
{
	int	count;
	int	i;

	count = 0;
	i = 0;
	while (str[i])
	{
		while (str[i] && is_charset(str[i], charset))
			i++;
		if (str[i])
			count++;
		while (str[i] && !is_charset(str[i], charset))
			i++;
	}
	return (count);
}

static char	*alocar_palavra(char *inicio, char *fim)
{
	char	*palavra;
	int		len;
	int		i;

	len = fim - inicio;
	palavra = (char *)malloc(sizeof(char) * (len + 1));
	if (!palavra)
		return (NULL);
	i = 0;
	while (inicio < fim)
	{
		palavra[i] = *inicio;
		inicio++;
		i++;
	}
	palavra[i] = '\0';
	return (palavra);
}

static char	*obter_proxima_palavra(char **str, char *charset)
{
	char	*inicio;
	char	*fim;

	while (**str && is_charset(**str, charset))
		(*str)++;
	inicio = *str;
	while (**str && !is_charset(**str, charset))
		(*str)++;
	fim = *str;
	if (inicio == fim)
		return (NULL);
	return (alocar_palavra(inicio, fim));
}

char	**ft_split(char *str, char *charset)
{
	char	**resultado;
	int		contagem_palavras;
	int		i;

	contagem_palavras = count_palavras(str, charset);
	resultado = (char **)malloc(sizeof(char *) * (contagem_palavras + 1));
	if (!resultado)
		return (NULL);
	i = 0;
	while (i < contagem_palavras)
	{
		resultado[i] = obter_proxima_palavra(&str, charset);
		if (!resultado[i])
		{
			while (i > 0)
				free(resultado[--i]);
			free(resultado);
			return (NULL);
		}
		i++;
	}
	resultado[i] = NULL;
	return (resultado);
}
