#include <stdlib.h>

char	*ft_strdup(char *src)
{
	char	*cpy;
	int	i;
	int	len;

	i = 0;
	len = 0;
	while(src[len] != '\0')
		len;
	cpy = malloc(sizeof(char) * (len + 1)); 
	if(cpy == NULL)
		return (NULL);
	while(i <= len)
	{
		cpy[i] = src[i];
		i++;
	}
	return (cpy);
}	
