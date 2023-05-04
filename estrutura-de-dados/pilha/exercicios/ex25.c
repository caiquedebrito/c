#include <stdio.h>
#include <string.h>
#include "../pilha.h"

/*
  Enunciado: Usando pilha, crie uma função para verificar se uma expressão composta apenas
  por chaves, colchetes e parênteses, representada por uma cadeia, está ou não balanceada.
*/

#define MAX_LEN 256
#define true 1
#define false 0


/**
 * Retorna o tipo do delimitador
 * 
 * @param c caracterer a ser analisado
 * 
 * @return 1 caso c seja um parêntese
 * @return 2 caso c seja uma chave
 * @return 3 caso c seja um colchete
 * @return -1 para demais caractere
*/
int tipo(char c) {
  switch (c)
  {
  case '(':
  case ')':
    return 1;
  case '{':
  case '}':
    return 2;
  case '[':
  case ']':
    return 3;
  default:
    return -1;
  }
}

int balanceada(char cadeia[MAX_LEN]) {
  const char* abertura = "({[";
  const char* fechamento = ")}]";

  Pilha P = pilha(MAX_LEN);

  for (int i = 0; cadeia[i]; i++) {
    if ( strchr(abertura, cadeia[i]) ) {
      empilha(cadeia[i], P);

    } else if ( strchr(fechamento, cadeia[i]) ) {
      if (vaziap(P)) {
        return false;
      }

      char t = topo(P);
      if (tipo(t) != tipo(cadeia[i])) {
        return false;
      }

      desempliha(P);
    }
  }

  return true;
}

int main() {

  char expressao[MAX_LEN];
  printf("Digite uma expressão composta: ");
  fgets(expressao, MAX_LEN, stdin);

  int pos = strcspn(expressao, "\n");
  if (pos < strlen(expressao)) {
    expressao[pos] = '\0';
  }

  if (balanceada(expressao)) {
    printf("Esta balanceada!");
  } else {
    printf("Nao esta balanceada!");
  }

  return 0;
}