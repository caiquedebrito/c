#include <stdio.h>
#include <stdlib.h>

/**
 * Faça um algoritmo que implemente a função
celula *buscarOuInserir(int x, celula *point),
onde x é um inteiro e *point é um ponteiro para uma lista de inteiros.
Esta função deverá buscar o inteiro x na lista de inteiros cujo topo é
apontado por *point. Se encontrar x, deverá retornar um ponteiro
para o elemento que contém x, se não encontrar x, deverá inserir x na
última posição da lista e deverá retornar um ponteiro para o elemento
inserido.
*/

typedef struct celula {
  int valor;
  struct celula *prox;
} CELULA;

CELULA *buscarOuInserir(int x, CELULA **point) {
  if (*point == NULL) {
    CELULA* elemento = malloc(sizeof (struct celula));
    elemento->valor = x;
    elemento->prox = NULL;
    (*point) = elemento;
    return elemento;
  }

  CELULA* atual = (*point);
  while (atual->prox != NULL && atual->valor != x) {
    atual = atual->prox;
  }

  if (atual->valor == x) {
    return atual;
  }

  CELULA* elemento = malloc(sizeof (struct celula));
  elemento->valor = x;
  elemento->prox = NULL;
  atual->prox = elemento;
  return elemento;
}

void printList(CELULA* point) {
    if (point == NULL) {
        printf("Lista vazia.\n");
        return;
    }

    CELULA* current = point;
    while (current != NULL) {
        printf("%d ", current->valor);
        current = current->prox;
    }
    printf("\n");
}

int main(void) {
  CELULA *list = NULL;
  
  int n;
  printf("Digite a quantidade de elementos: ");
  scanf("%d", &n);

  for (int i = 0; i < n; i++) {
      int value;
      printf("Digite o elemento %d: ", i + 1);
      scanf("%d", &value);
      CELULA *elemento = buscarOuInserir(value, &list);
      printf("Elemento encontrado ou inserido: %d\n", elemento->valor);
  }

  printf("Lista:\n");
  printList(list);

  return 0;
}