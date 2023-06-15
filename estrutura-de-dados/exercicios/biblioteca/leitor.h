#include "types.h"

typedef struct leitor {
  char nome[50];
  struct leitor *proximo;
  struct copia *lista_livros;
} *LEITOR;

LEITOR criar_leitor() {
  LEITOR novo_leitor;
  novo_leitor = malloc(sizeof(struct leitor));
  novo_leitor->proximo = NULL;
  novo_leitor->lista_livros = NULL;

  printf("Digite o nome do leitor: ");
  fgets(novo_leitor->nome, 50, stdin);
  novo_leitor->nome[strcspn(novo_leitor->nome, "\n")] = '\0';

  return novo_leitor;
}

LEITOR cadastrar_leitor(LEITOR lista_leitor) {
  LEITOR novo_leitor = criar_leitor();

  if (lista_leitor != NULL) {
    LEITOR copia = lista_leitor;

    while (copia->proximo != NULL) { copia = copia->proximo; }

    copia->proximo = novo_leitor;

    return lista_leitor;
  }

  return novo_leitor;
}

LEITOR buscar_leitor(char nome[50], LEITOR lista_leitor) {
  LEITOR atual = lista_leitor;

  while (atual != NULL && strcmp(atual->nome, nome) != 0) {
    atual = atual->proximo;
  } 

  return atual;
}

void exibir_leitores(LEITOR lista_leitor) {
  LEITOR atual = lista_leitor;
  printf("Leitores\n");
  while (atual != NULL) {
    printf(" - %s\n", atual->nome);
    atual = atual->proximo;
  }
}