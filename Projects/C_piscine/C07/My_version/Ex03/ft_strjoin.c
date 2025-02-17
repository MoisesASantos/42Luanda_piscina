#include <stdlib.h>

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while(str[i] != '\0')
	{
		i++;
	}
	return (i);
}

char *ft_strcat(char *dest, char *src)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while(dest[i] != '\0')
		i++;
	while(src[j] != '\0')
	{
		dest[i + j] = src[j];
		j++;
	}
	dest[i + j] = '\0';
	return (dest);
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	char	*result;
	int	i;
	int	totalen;

	if(size == 0)
	{
		result = malloc(1);
		result[0] = '\0';
		return (result);
	}
	i = 0;
	totalen = 0;
	while(i < size)
	{
		totalen += ft_strlen(strs[i]);
		i++;
	}
	totalen += (size - 1) * ft_len(sep);
	result = malloc(sizeof(char) * (totalen + 1));
	if(result == NULL)
		return (NULL);
	result[0] = '\0';
	i = 0;
	while(i < size)
	{
		ft_strcat(result, strs[i]);
		if( i < size - 1)
			ft_strcat(result, sep);
		i++;
	}
	result[i] = '\0';
	return (result);
}
