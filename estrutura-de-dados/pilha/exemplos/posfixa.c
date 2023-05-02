#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "./pilha/pilha.h"

int prio(char o) {
  switch (o)
  {
    case '(': return 0;
    case '+':
    case '-': return 1;
    case '*': 
    case '/': return 2;
  }

  return -1;
}

char *posfixa(char *infixa) {
  static char pos[256];
  int j = 0;

  Pilha P = pilha(256);

  for (int i = 0; infixa[i]; i++) {
    if ( infixa[i] == '(' ) empilha('(', P);
    else if ( isdigit(infixa[i]) || infixa[i] == '.') pos[j++] = infixa[i];
    else if ( strchr("+*-/", infixa[i]) ) {
      pos[j++] = ' ';
      while ( !vaziap(P) && prio(topo(P)) >= prio(infixa[i]) ) {
        pos[j++] = desempliha(P);
      }

      empilha(infixa[i], P);
    }
    else if ( infixa[i] == ')' ) {
      while ( topo(P) != '(' ) {
        pos[j++] = desempliha(P);
      }

      desempliha(P);
    }
  }

  while ( !vaziap(P) ) {
    pos[j++] = desempliha(P);
  }

  pos[j] = '\0';
  destroip(&P);
  return pos;
}


float valor(char *e) {
  Pilha P = pilha(256);

  for (int i = 0; e[i]; i++) {
    if ( isdigit(e[i]) ) {
      empilha(atof(e+i), P);
      while ( isdigit(e[i+1]) || e[i+1] == '.' ) i++;
    } else if ( strchr("+*-/", e[i]) ) {
      float y = desempliha(P);
      float x = desempliha(P);

      switch (e[i]) {
        case '+': empilha(x+y, P); break;
        case '-': empilha(x-y, P); break;
        case '*': empilha(x*y, P); break;
        case '/': empilha(x/y, P); break;
      }
    }
  }

  float z = desempliha(P);
  destroip(&P);
  return z;
}

int main() {
  char infixa[256];
  char pos[256];

  printf("Infixa? ");
  gets(infixa);

  printf("Posfixa: %s\n", posfixa(infixa));

  printf("Resultado: %f", valor(posfixa(infixa)));

  return 0;
}