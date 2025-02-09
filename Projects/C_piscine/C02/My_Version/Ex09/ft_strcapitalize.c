#include <unistd.h>

char	*ft_strcapitalize(char *str)
{
	int	i;
	int	inicial;

	i = 0;
	inicial = 1;
	while(str[i] != '\0')
	{
		if((str[i] >= 'a' && str[i] <= 'z') || (str[i] >= 'A' && str[i] <= 'Z'))
		{
			if(inicial && (str[i] >= 'a' && str[i] <= 'z'))
			{
				str[i] -= 32;
			}
			else if(!inicial && (str[i] >= 'A' && str[i] <= 'Z'))
			{
				str[i] += 32;
			}
			inicial = 0;
		}
		else if(str[i] >= '0' && str[i] <= '9')
		{
			inicial = 0;
		}
		else
			inicial = 1;
		write(1, &str[i], 1);
		i++;
	}
}

int	main(void)
{
	char	benga[100] = "oi, tudo bem? 42palavras quarenta-e-duas; cinquenta+e+um"; // Inicializa diretamente a string

	ft_strcapitalize(benga);
	write(1, "\n", 1);
	return (0);
}
