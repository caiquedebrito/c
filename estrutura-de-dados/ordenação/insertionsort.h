#include <stdio.h>
// #include "./printarray.h"

void insertionSort(int arr[], int n) {
    int i, j, key;
    int comparation_count = 0, swap_count = 0;

    for (i = 1; i < n; i++) {
        key = arr[i];
        j = i - 1;

        // Move os elementos maiores para a direita
        // comparation_count++;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
            swap_count++;
            comparation_count++;
        }

        // Insere o elemento na posição correta
        arr[j + 1] = key;
        printf("%da passo: Numero de comparacoes: %d, Numero de trocas: %d\n", (i), comparation_count, swap_count);
        printArray(arr, n);	
    }

      printf("Numero de comparacoes: %d\nNumero de trocas: %d\n", comparation_count, swap_count);
}
