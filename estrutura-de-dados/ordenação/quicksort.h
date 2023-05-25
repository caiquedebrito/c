#include <stdio.h>

// função para trocar a posição dos elementos
void swap(int *a, int *b) {
  int t = *a;
  *a = *b;
  *b = t;
}

// função para selecionar o pivô
int partition(int array[], int low, int high) {
  
  // seleciona o pivô como o elemento mais à direita
  int pivot = array[high];
  
  // aponta para o maior elemento
  int i = (low - 1);

  // traverse each element of the array
  // compare them with the pivot
  for (int j = low; j < high; j++) {
    if (array[j] <= pivot) {
        
      // if element smaller than pivot is found
      // swap it with the greater element pointed by i
      i++;
      
      // swap element at i with element at j
      swap(&array[i], &array[j]);
    }
  }

  // swap the pivot element with the greater element at i
  swap(&array[i + 1], &array[high]);
  
  // return the partition point
  return (i + 1);
}

void quickSort(int array[], int low, int high) {
  if (low < high) {
    
    // find the pivot element such that
    // elements smaller than pivot are on left of pivot
    // elements greater than pivot are on right of pivot
    int pi = partition(array, low, high);
    
    // chamada recursiva para os elementos à esquerda do pivô
    quickSort(array, low, pi - 1);
    
    // chamada recursiva para os elementos à direita do pivô
    quickSort(array, pi + 1, high);
  }
}

void printArray(int array[], int size) {
  for (int i = 0; i < size; ++i) {
    printf("%d  ", array[i]);
  }
  printf("\n");
}

int main() {
  int data[] = {8, 7, 2, 1, 0, 9, 6};
  
  int n = sizeof(data) / sizeof(data[0]);
  
  printf("Array desordenado\n");
  printArray(data, n);
  
  quickSort(data, 0, n - 1);
  
  printf("Array ordenado: \n");
  printArray(data, n);
}