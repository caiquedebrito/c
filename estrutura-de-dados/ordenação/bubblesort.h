#include <stdio.h>
// #include "./printarray.h"

void bubbleSort(int arr[], int n) {
  int i, j, temp;

  int comparation_count = 0, swap_count = 0;

  for (i = 0; i < n-1; i++) {
    for (j = 0; j < n-i-1; j++) {
      comparation_count++;
      if (arr[j] > arr[j+1]) {
        // printf("Troca\n");
        // Troca os elementos adjacentes se estiverem fora de ordem
        temp = arr[j];
        arr[j] = arr[j+1];
        arr[j+1] = temp;

        swap_count++;
      }
    }
    printf("%da passo: Numero de comparacoes: %d, Numero de trocas: %d\n", (i+1), comparation_count, swap_count);
    printArray(arr, n);
  } 

  printf("Numero de comparacoes: %d\nNumero de trocas: %d\n", comparation_count, swap_count);
}
