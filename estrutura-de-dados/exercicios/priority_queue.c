#include <stdio.h>
#include <stdlib.h>

#define MAX 50

typedef struct pessoa {
  int prdd;
  char nome[MAX];
  struct pessoa *ant;
  struct pessoa *prox;
} *PESSOA;

PESSOA enfileirar(int prdd, PESSOA fila) {
  PESSOA novo = malloc(sizeof (struct pessoa));
  novo->prdd = prdd;
  printf("Digite o nome do elemento: ");
  scanf("%s", novo->nome);

  if (fila == NULL) {
    novo->ant = NULL;
    novo->prox = NULL;
    return novo;
  }

  PESSOA atual = fila;
  while (atual->prox != NULL && atual->prox->prdd < prdd) {
    atual = atual->prox;
  }

  if (atual == fila) {
    novo->ant = NULL;
    novo->prox = atual;
    atual->ant = novo;
    return novo;
  }

  if (atual->prox != NULL) {
    atual->prox->ant = novo;
  }

  novo->prox = atual->prox;
  atual->prox = novo;
  novo->ant = atual;


  return fila;
}

PESSOA desenfileirar(PESSOA fila) {
  if (fila == NULL) {
    printf("Fila vazia!\n");
    return fila;
  }

  fila = fila->prox;
  fila->ant = NULL;
  return fila;
}

void buscar(PESSOA fila) {}

void imprimir(PESSOA fila) {
  PESSOA atual = fila;

  while (atual != NULL) {
    printf("Prioridade: %d - Conteudo%s\n", atual->prdd, atual->nome);
    atual = atual->prox;
  }
}

int main(void) {
  PESSOA fila = NULL;
  int res;
  int prdd;


  while (1) {
    printf("1- Enfileirar novo elemento na lista\n");
    printf("2 - Desenfileirar elemento da lista\n");
    printf("3 - Sair\n");
    scanf("%d", &res);
    
    switch (res)
    {
    case 1:
      // adicionar novo elemento
      printf("Digite a prioridade do elemento: ");
      scanf("%d", &prdd);

      if (prdd < 0) { printf("Prioridade invalida! Digite um valor maior ou igual a zero\n"); } 
      else {
        // 
        fila = enfileirar(prdd, fila);
      }
      break;
    case 2:
      // remover primeiro elemento
      printf("Desenfileirando elemento...\n");
      fila = desenfileirar(fila);

      break;
    case 3:
      printf("Encerrando...\n");
      return 0;
    default:
      printf("Opcao invalida\n");
      break;
    }

    imprimir(fila);
  }

  return 0;
}