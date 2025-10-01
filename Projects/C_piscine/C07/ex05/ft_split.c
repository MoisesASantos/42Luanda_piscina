/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mosantos <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/03 23:49:49 by mosantos          #+#    #+#             */
/*   Updated: 2024/11/03 23:59:08 by mosantos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

static int	is_separator(char c, char *charset)
{
	while (*charset)
	{
		if (c == *charset)
			return (1);
		charset++;
	}
	return (0);
}

static int	count_words(char *str, char *charset)
{
	int	count;
	int	i;

	i = 0;
	count = 0;
	while (str[i])
	{
		while (str[i] && is_separator(str[i], charset))
			i++;
		if (str[i])
			count++;
		while (str[i] && !is_separator(str[i], charset))
			i++;
	}
	return (count);
}

static int	word_len(char *str, char *charset)
{
	int	len;

	len = 0;
	while (str[len] && !is_separator(str[len], charset))
		len++;
	return (len);
}

static char	*create_word(char *str, char *charset)
{
	char		*word;
	int			len;
	int			i;

	i = 0;
	len = word_len(str, charset);
	word = (char *)malloc(sizeof(char) * (len + 1));
	while (i < len)
	{
		word[i] = str[i];
		i++;
	}
	word[i] = '\0';
	return (word);
}

char	**ft_split(char *str, char *charset)
{
	char		**result;
	int			i;

	result = (char **)malloc(sizeof(char *)
			* (count_words(str, charset) + 1));
	i = 0;
	while (*str)
	{
		while (*str && is_separator(*str, charset))
			str++;
		if (*str)
		{
			result[i] = create_word(str, charset);
			i++;
			while (*str && !is_separator(*str, charset))
				str++;
		}
	}
	result[i] = 0;
	return (result);
}
