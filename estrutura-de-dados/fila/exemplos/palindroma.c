#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include "../fila.h"
#include "../../pilha/pilha.h"

int main(void) {
  char frase[256];
  Fila F = fila(256);
  Pilha P = pilha(256);

  printf("Frase? ");
  fgets(frase, 256, stdin);

  // remoção do caractere \n  
  int pos = strcspn(frase, "\n");
  if (pos < strlen(frase)) {
    frase[pos] = '\0';
  }

  for (int i = 0; frase[i]; i++) {
    if ( isalpha(frase[i]) ) {
      enfileiraf(frase[i], F);
      empilha(frase[i], P);
    }
  }

  while ( !vaziaf(F) && desenfileira(F) == desempliha(P) );

  if ( vaziaf(F) ) {
    puts("A frase e palindroma");
  } else {
    puts("A frase nao e palindroma");
  }

  destroif(&F);
  destroip(&P);

  return 0;
}