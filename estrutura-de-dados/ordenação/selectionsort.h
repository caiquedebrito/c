#include <stdio.h>
// #include "./printarray.h"

void selectionSort(int arr[], int n) {
    int i, j, minIndex, temp;

    int comparation_count = 0, swap_count = 0;

    for (i = 0; i < n-1; i++) {
        minIndex = i;

        for (j = i+1; j < n; j++) {
            comparation_count++;

            if (arr[j] < arr[minIndex])
                minIndex = j;
        }

        // Troca o elemento mínimo com o primeiro elemento não ordenado
        if (minIndex != i) { // Se são diferentes é porque os itens estão desordenados
            temp = arr[minIndex];
            arr[minIndex] = arr[i];
            arr[i] = temp;

            swap_count++;
        }

        printf("%da passo: Numero de comparacoes: %d, Numero de trocas: %d\n", (i+1), comparation_count, swap_count);
        printArray(arr, n);
    }

     printf("Numero de comparacoes: %d\nNumero de trocas: %d\n", comparation_count, swap_count);

}
