#include <stdio.h>
#include <stdlib.h>
#include "functions.h"

int main()
{
    int arr[20] = {25, 17, 31, 13, 2, 19, 8, 14, 7, 1, 22, 10, 3, 12, 9, 5, 6, 16, 11, 4};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("Vetor desordenado:\n");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }

    quicksort(arr, 0, n - 1);

    printf("\nVetor ordenado:\n");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }

    return 0;
}