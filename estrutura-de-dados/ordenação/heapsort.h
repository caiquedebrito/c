#include <stdio.h>

// Função para trocar a posição dos elementos
void swap(int *a, int *b) {
  int temp = *a;
  *a = *b;
  *b = temp;
}

void heapify(int arr[], int n, int i) {
  // Encontrar o maior entre o nó raiz, filho esquerdo e filho direito
  int largest = i;
  int left = 2 * i + 1;
  int right = 2 * i + 2;

  // Se o filho esquerdo for maior que o nó raiz
  if (left < n && arr[left] > arr[largest])
    largest = left;

  // Se o filho direito for maior que o nó raiz
  if (right < n && arr[right] > arr[largest])
    largest = right;

  // Trocar e continuar se o nó raiz não for o maior
  if (largest != i) {
    swap(&arr[i], &arr[largest]);
    heapify(arr, n, largest);
  }
}

void heapSort(int arr[], int n) {
  // Construir heap (reorganizar array)
  for (int i = n / 2 - 1; i >= 0; i--)
    heapify(arr, n, i);

  // Heap sort
  for (int i = n - 1; i >= 0; i--) {
    swap(&arr[0], &arr[i]);

    heapify(arr, i, 0);
  }
}

void printArray(int arr[], int n) {
  for (int i = 0; i < n; ++i)
    printf("%d ", arr[i]);
  printf("\n");
}