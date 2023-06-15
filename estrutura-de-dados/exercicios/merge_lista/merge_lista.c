#include <stdio.h>
#include <stdlib.h>

typedef struct no {
  int chave;
  struct no *prox;
} *LISTA;

void exibir(LISTA l) {
  LISTA atual = l;

  while (atual != NULL)
  {
    printf("Valor: %d\n", atual->chave);
    atual = atual->prox;
  }
  
}

LISTA criar_no(int chave) {
  LISTA novo_no = malloc(sizeof (struct no));
  novo_no->chave = chave;
  novo_no->prox = NULL;

  return novo_no;
}

LISTA inserir(int chave, LISTA lista) {

  LISTA no = criar_no(chave);

  if (lista == NULL) {
    return no;
  }

  LISTA atual = lista;

  while (atual->prox != NULL) {
    atual = atual->prox;
  }

  atual->prox = no;

  return lista;
}

LISTA buscar_ultimo(LISTA l) {
  LISTA atual = l;

  while (atual->prox != NULL) {
    atual = atual->prox;
  }

  return atual;
}

LISTA selection_sort(LISTA l) {
  if (l == NULL || l->prox == NULL) {
    return l;
  }

  for (LISTA i = l; i->prox != NULL; i = i->prox) {
    LISTA menor = i;

    for (LISTA j = i->prox; j != NULL; j = j->prox) {
      if (j->chave < menor->chave) {
        menor = j;
      }
    }

    int aux = i->chave;
    i->chave = menor->chave;
    menor->chave = aux;
  }

  return l;
}

LISTA intercalar(LISTA l1, LISTA l2) {
  LISTA l3;
  LISTA ultimo = buscar_ultimo(l1);

  ultimo->prox = l2;

  l3 = l1;

  return selection_sort(l3);
}

int main(void) {
  LISTA L1 = NULL;
  LISTA L2 = NULL;
  int res = 1;
  int valor;

  printf("Prencha a lista 1\n");
  while (1)
  {
    printf("Digite um valor do novo no: ");
    scanf("%d", &valor);

    L1 = inserir(valor, L1);

    printf("Deseja adicionar outro elemento na lista 1? (1 - Sim \\ 2 - Nao) ");
    scanf("%d", &res);

    if (res == 2) break;
  }
  
  printf("Prencha a lista 2\n");
  while (1)
  {
    printf("Digite um valor do novo no: ");
    scanf("%d", &valor);

    L2 = inserir(valor, L2);

    printf("Deseja adicionar outro elemento na lista 2? (1 - Sim \\ 2 - Nao) ");
    scanf("%d", &res);

    if (res == 2) break;
  }

  LISTA L3 = intercalar(L1, L2);

  exibir(L3);

  return 0;
}