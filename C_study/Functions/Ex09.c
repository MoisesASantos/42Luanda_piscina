#include <stdio.h>

/*int	matriz(int arr[], int n)
{
	if(n == 1)
		return arr[0];
	int maior = matriz(arr, n - 1);
	return arr[n - 1] > maior ? arr[n - 1] : maior;
}*/

int matriz_div(int arr[], int start, int end)
{
	if(start == end)
		return arr[start];
	int middle = (start + end) / 2;
	int max_left = matriz_div(arr, start, middle);
	int max_right = matriz_div(arr, middle + 1, end);
	return max_left > max_right? max_left : max_right;
}

int matriz(int arr[], int n)
{
	if(n == 0)
		return -1;
	return matriz_div(arr, 0, n - 1);
}

int main(void)
{
	int arr[] = {1, 2, 2, 0, 3};
	printf("%d\n", matriz(arr, 5));
	return (0);
}
