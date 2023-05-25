#include <stdio.h>

void mergesort(int array[], int esquerda, int direita) {
  if (esquerda < direita) {
    // Encontra o meio
    int meio = (esquerda + direita) / 2;

    // Ordena a primeira e a segunda metade
    mergesort(array, esquerda, meio);
    mergesort(array, meio + 1, direita);

    // Junta as metades ordenadas
    merge(array, esquerda, meio, direita);
  }
}

void merge(int array[], int esquerda, int meio, int direita) {
  // Tamanho dos subarrays
  int n1 = meio - esquerda + 1;
  int n2 = direita - meio;

  // Cria arrays temporários para armazenar os elementos dos subarrays esquerdo e direito
  int L[n1], R[n2];

  // Copia os dados para os arrays temporários
  for (int i = 0; i < n1; i++) {
    L[i] = array[esquerda + i];
  }
  for (int j = 0; j < n2; j++) {
    R[j] = array[meio + 1 + j];
  }

  // Junta os arrays temporários de volta ao array principal
  int i = 0, j = 0, k = esquerda;

  while (i < n1 && j < n2) {
    if (L[i] <= R[j]) {
      array[k] = L[i];
      i++;
    } else {
      array[k] = R[j];
      j++;
    }
    k++;
  }

  // Copia os elementos restantes de L[], se houver
  while (i < n1) {
    array[k] = L[i];
    i++;
    k++;
  }

  // Copia os elementos restantes de R[], se houver
  while (j < n2) {
    array[k] = R[j];
    j++;
    k++;
  }
}

void printArray(int array[], int size) {
  for (int i = 0; i < size; i++) {
    printf("%d ", array[i]);
  }
  printf("\n");
}

int main(void) {
  int array[] = { 5, 4, 3, 2, 1 };
  mergesort(array, 0, 4);
  printArray(array, 5);

  return 0;
}