#include <stdio.h>  

int vetorArrumado(int v[], int n) {
  int j = n / 2;

  int totalMaiores = 0;
  int menores[j];
  int maiores[n - j];

  for (int i = 0; i < j; i++) {
    if (v[i] > v[j]) {
      return -1; // Não está arrumado
    } else {
      for (int k = 0; k < i; k++) {
        if (menores[k] > v[i]) {
          return -1; // Não está arrumado
        }

      }

      menores[i] = v[i];
    }
  }

  for (int i = j+1; i < n -1; i++) {
    if (v[j] > v[i]) {
      return -1; // Não está arrumado
    } else {
      for (int k = 0; k < totalMaiores; k++) {
        if (maiores[k] > v[i]) {
          return -1; // Não está arrumado
        }
      }

      maiores[totalMaiores++] = v[i];

    }
  }

  return j; // Está arrumado
}

int main() {
  int v[] = {1, 3, 3, 4, 4, 5, 7, 8};
  int n = sizeof(v) / sizeof(v[0]);

  int resultado = vetorArrumado(v, n);

  if (resultado == -1) {
    printf("O vetor nao esta arrumado.\n");
  } else {
    printf("O vetor esta arrumado.\n");
  }

  return 0;
}