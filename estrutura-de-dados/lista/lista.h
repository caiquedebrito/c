#include <stdlib.h>
#include <stdio.h>

#define fmt "%d"
typedef int Item;
typedef struct no {
  Item item;
  struct no *prox;
} *Lista;

Lista no(Item x, Lista p) {
  Lista n = malloc(sizeof(struct no));
  n->item = x;
  n->prox = p;
  return n;
}

void exibe(Lista L) {
  while ( L != NULL )
  {
    printf(fmt, L->item);
    L = L->prox;
  }
}

void anexa(Lista *A, Lista B) {
  if ( B == NULL ) return;
  while ( *A != NULL ) A = &(*A)->prox;
  *A = B;
}

void destroi(Lista *L) {
  while ( *L != NULL )
  {
    Lista n = *L;
    *L = n->prox;
    free(n);
  }
}

int tamanho(Lista L) {
  if ( L == NULL ) return 0;
  return 1 + tamanho(L->prox);
}

int pertence(Item x, Lista L) {
  if ( L == NULL ) return 0;
  if ( x == L->item ) return 1;
  return pertence(x, L->prox);
}

Lista clone(Lista L) {
  if ( L == NULL ) return NULL;
  return no(L->item, clone(L->prox));
}