#include <stdio.h>

int matriz(int arr[], int n) {
    if (n == 0)
        return 0;
    return arr[n - 1] + matriz(arr, n - 1);
}

int main(void) {
    int arr[5] = {1, 2, 3, 4, 5};
    printf("%d\n", matriz(arr, 5));
    return 0;
}
