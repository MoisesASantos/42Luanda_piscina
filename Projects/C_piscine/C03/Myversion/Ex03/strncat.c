char *ft_strncat(char *dest, char *src, unsigned int nb)
{
	int	i;
	int	len;

	i = 0;
	len = 0;
	while(dest[len] != '\0')
		len++;
	while(src[i] != '\0' && i < nb)
	{
		dest[len + i] = src[i];
		i++;
	}
	dest[len + i] = '\0';
	return (dest);
}
