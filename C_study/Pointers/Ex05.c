#include <stdio.h>

void limits(int *p, int size)
{
	int	min;
	int	max;
	int	i;

	if(size <= 0)
		return ;
	min = *p;
	max = *p;
	i = 1;
	while(i < size)
	{
		p++;
		if(min > *p)
			min = *p;
		if(max < *p)
			max = *p;
		i++;
	}
	printf("Min: %d e Max: %d \n", min, max);
}


int main() {
    int arr[] = {3, 1, 4, 1, 5, 9, 2, 6};
    limits(arr, sizeof(arr) / sizeof(arr[0]));
    return 0;
}
