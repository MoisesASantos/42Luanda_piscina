#include <stdlib.h>

int	is_charset(char c, char *charset)
{
	int	i;

	i = 0;
	while(charset[i] != '\0')
	{
		if( c == charset[i])
			return (1);
		i++;
	}
	return (0);
}

int	count_word(char *str, char *charset)
{
	int	i;
	int	count;
	int	in_word;

	i = 0;
	count = 0;
	in_word = 0;
	while(str[i] != '\0')
	{
		if(is_charset(str[i], charset))
		{
			in_word = 0;
		}
		else if(!in_word)
		{
			in_word = 1;
			count++;
		}
		i++;
	}
	return (count);
}

char	*get_next_word(char **str, char *charset)
{
	char	*word;
	char	*start;
	int		lenght;
	int		i;

	while(**str && is_charset(**str, charset))
		(*str)++;
	start = *str;
	while(**str && !is_charset(**str, charset))
		(*str)++;
	lenght = *str - start;
	word = malloc((lenght + 1) * sizeof(char));
	if(word == NULL)
		return (NULL);
	i = 0;
	while(i < lenght)
	{
		word[i] = start[i];
		i++;
	}
	word[lenght] = '\0';
	return (word);
}

char	**ft_split(char *str, char *charset)
{
	char	**result;
	int		word_count;
	int		i;

	word_count = count_word(str, charset);

	result = malloc(sizeof(char *) * (word_count + 1));
	if(result == NULL)
		return (NULL);
	i = 0;
	while(i < word_count)
	{
		result[i] = get_next_word(&str, charset);
		i++;
	}
	result[i] = NULL;
	return (result);
}
