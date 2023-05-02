#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include "../pilha.h"

int main() {
  char frase[100];
  char frase_invertida[100];

  printf("Digite uma frase: ");
  fgets(frase, 100, stdin);

  frase[strcspn(frase, "\n")] = '\0';

  Pilha pilha_frase = pilha(100);

  int index_frase, index_frase_invertida = 0;

  for (index_frase = 0; frase[index_frase]; index_frase++) {
    if (isalpha(frase[index_frase])) {
      empilha(frase[index_frase], pilha_frase);      
    } else {
      while ( !vaziap(pilha_frase) ) {
        frase_invertida[index_frase_invertida++] = desempliha(pilha_frase);
      }

      frase_invertida[index_frase_invertida++] = ' ';
    }
  }

  while ( !vaziap(pilha_frase) ) {
    frase_invertida[index_frase_invertida++] = desempliha(pilha_frase);
  }

  frase_invertida[index_frase_invertida] = '\0';

  printf("%s\n", frase_invertida);
  
  return 0;
  
}