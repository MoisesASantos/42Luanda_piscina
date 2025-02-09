unsigned int ft_strlcpy(char *dest, char *src, unsigned int size)
{
	int	i;
	int	len;

	i = 0;
	len = 0;
	while(src[len] != '\0')
		len++;
	if( size > 0)
	{
		while( i < size - 1 && src[i] != '\0')
		{	
			dest[i] = src[i];
			i++;
		}
		dest[i] = '\0';
	}
	return (len);
}
