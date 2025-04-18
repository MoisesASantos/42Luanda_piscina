#include <stdio.h>

int maior(int arr[], int tam, int indice)
{
	if(tam == 0)
		return arr[indice];
	else
	{
		if(arr[tam - 1] > arr[indice])
			return maior(arr, tam - 1, tam - 1);
		else
			return maior(arr, tam - 1, indice);
	}
}

int main(void)
{
	int arr[] = {1, 2, 8, 7, 3};
       	printf("%d\n", maior(arr, 5, 0));
	return (0);
}	
