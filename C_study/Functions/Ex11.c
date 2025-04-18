#include <stdio.h>

void swap(int arr[], int start, int end)
{

	if(start >= end / 2)
		return ;
	int temp = arr[start];
	arr[start] = arr[end - 1 - start];
	arr[end - 1 - start] = temp;
	swap(arr, start + 1, end);
}

int main(void)
{
	int vetor[] = {1, 2, 3, 4, 5};
	int tam = 5;
	swap(vetor, 0, tam);
	for(int i = 0; i < tam; i++)
		printf("%d ", vetor[i]);
	printf("\n");
	return (0);
}
