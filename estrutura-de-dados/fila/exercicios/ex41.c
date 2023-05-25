#include <stdio.h>
#include "../fila.h"

int main(void) {
  Fila F = fila(5);
  enfileiraf(1, F);
  enfileiraf(2, F);
  enfileiraf(3, F);
  enfileiraf(desenfileira(F), F);
  enfileiraf(desenfileira(F), F);
  printf("%d\n", desenfileira(F));

  return 0;
}