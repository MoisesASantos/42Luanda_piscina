#include <stdlib.h>
#include "ft_strs_stock.h"

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

char	*ft_strdup(char *str)
{
	char	*cpy;
	int		i;
	
	i = 0;
	cpy = malloc(sizeof(char) * (ft_strlen(str) + 1));
	if(cpy == NULL)
		return (NULL);
	while(str[i] != '\0')
	{
		cpy[i] = str[i];
		i++;
	}
	cpy[i] = '\0';
       return (cpy);
}       

struct s_stock_str *ft_strs_to_tab(int ac, char **av)
{
	t_stock_str	*tab;
	int	i;

	i = 0;
	tab = malloc(sizeof(t_stock_str) * (ac + 1));
	if(tab == NULL)
		return (NULL);
	while(i < ac)
	{
		tab[i].size = ft_strlen(av[i]);
		tab[i].str = av[i];
		tab[i].copy = ft_strdup(av[i]);
		if(!tab[i].copy)
		{
			while(i > 0)
				free(tab[--i].copy)
			free(tab);
			return (NULL);
		}
		i++;
	}
	tab[i].str = 0;
	return (tab);
}
