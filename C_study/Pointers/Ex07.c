#include <stdio.h>

void	print(int arr[10])
{
	int	i  = 0;
	int 	*p = arr;

	while( i < 10)
	{
		printf("Posição %d = %d | Endereço = %p\n", i, arr[i], (void *)(p + i));
		i++;
	}
}

int	main(void)
{
	int arr[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
	print(arr);
	return (0);
}
