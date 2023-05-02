#include "../pilha.h"
#include <stdio.h>

int main() {
  int n, num;

  printf("Quantos numeros voce vai digitar? ");
  scanf("%d", &n);

  Pilha A = pilha(n);
  Pilha B = pilha(n);

  for (int index = 0; index < n; index++) {
    printf("Digite o %da numero: ", (index+1));
    scanf("%d", &num);

    if (vaziap(A)) {
      empilha(num, A);
    } else {
      while (!vaziap(A) && topo(A) < num)
      {
        empilha(desempliha(A), B);
      }

      empilha(num, A);

      while (!vaziap(B))
      {
        empilha(desempliha(B), A);
      }
      
    }

  }
  
  printf("Numeros ordenados: \n");
  while (!vaziap(A))
  {
    printf("%d, ", desempliha(A));
  }


  return 0;
}