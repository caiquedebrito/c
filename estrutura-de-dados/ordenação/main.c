#include "./printarray.h"
#include "./bubblesort.h"
#include "./selectionsort.h"
#include "./insertionsort.h"

/*
  a) S1 = {1, 4, 5, 8, 10, 12}
  b) S2 = {11, 9, 7, 5, 3, 1}
  c) S3 = {5, 7, 2, 8, 1, 6}
  d) S4 = {2, 4, 6, 8, 10, 12, 11, 9, 7, 5, 3, 1}
  e) S5 = {2, 4, 6, 8, 10, 12, 1, 3, 5, 7, 9, 11}
  f) S6 = {8, 9, 7, 9, 3, 2, 3, 8, 4, 6}
  g) S7 = {89, 79, 32, 38, 46, 26, 43, 38, 32, 79}.
*/

int main(void) {
  int S1[] = {89, 79, 32, 38, 46, 26, 43, 38, 32, 79};
  int n = sizeof(S1) / sizeof(int);

  // bubbleSort(S1, n);
  // selectionSort(S1, n);
  insertionSort(S1, n);

  printf("Vetor ordenado: ");
  for (int i = 0; i < n; i++) {
    printf("%d ", S1[i]);
  }

  return 0;
}