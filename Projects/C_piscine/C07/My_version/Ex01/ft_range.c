#include <stdlib.h>

int	*ft_range(int min, int max)
{
	int	*matriz;
	int	i;
	int	size;

	i = 0;
	size = 0;
	if(min >= max)
		return (NULL);
	size = max - min;
	matriz = malloc(sizeof(int) * size);
	if(matriz == NULL)
		return NULL;
	while(i < size)
	{
		matriz[i] = min + i;
		i++;
	}
	return (matriz);
}
