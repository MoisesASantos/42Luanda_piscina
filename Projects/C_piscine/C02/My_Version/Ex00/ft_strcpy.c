#include <unistd.h>

void	*ft_strcpy(char *dest, char *src)
{
	int	i;

	i = 0;
	while(src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

int	main(int argc, char **argv)
{
	char	dest[100];


	if(argc = 2)
	{
		ft_strcpy(dest, argv[1]);
		write(1, &dest, 6);
	}
	write(1, "\n", 1);
	return (0);
}
