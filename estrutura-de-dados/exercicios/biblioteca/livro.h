#include "types.h"

typedef struct livro {
  char titulo[50];
  boolean disponivel;
  struct fila *fila_espera;
  struct livro *proximo;
  struct livro *anterior;
} *LIVRO;

typedef struct copia {
  struct livro *original;
  struct copia *prox;
} *COPIA;

typedef struct fila {
  struct leitor *primeiro;
  struct leitor *ultimo;
} *FILA_ESPERA;

void enfileirar(LEITOR leitor, FILA_ESPERA fila_espera);
LEITOR desenfileirar(FILA_ESPERA fila_espera);

void exibir_livros(LIVRO lista_livro) {
  LIVRO copia = lista_livro;
  int index = 0;
  printf("Livros cadastrados!\n");

  if (copia == NULL) {
    printf("Ainda nao ha livros cadastrados!\n");
    return;
  }
  
  while (copia != NULL) {
    index++;
    printf("%i - %s\n", index, copia->titulo);

    copia = copia->proximo;
  }
}

LIVRO criar_livro() {
  LIVRO novo_livro;
  novo_livro = malloc(sizeof (struct livro));
  novo_livro->disponivel = true;
  novo_livro->anterior = NULL;
  novo_livro->proximo = NULL;

  novo_livro->fila_espera = malloc(sizeof (struct fila));
  novo_livro->fila_espera->primeiro = NULL;
  novo_livro->fila_espera->ultimo = NULL;

  printf("Digite o nome do novo livro: ");
  fgets(novo_livro->titulo, 50, stdin);
  novo_livro->titulo[strcspn(novo_livro->titulo, "\n")] = '\0';

  return novo_livro;
}

LIVRO cadastrar_livro(LIVRO lista_livro) {
  LIVRO novo_livro = criar_livro();

  if (lista_livro != NULL) {
    LIVRO copia = lista_livro;

    while (copia->proximo != NULL) { copia = copia->proximo; }

    copia->proximo = novo_livro;
    novo_livro->anterior = copia;

    return lista_livro;
  }
  
  return novo_livro;
}

LIVRO buscar_livro(char titulo[50], LIVRO lista_livro) {
  LIVRO atual = lista_livro;

  while (atual != NULL && strcmp(atual->titulo, titulo) != 0) {
    atual = atual->proximo;
  } 

  return atual;
}

COPIA buscar_copia(char titulo[50], COPIA lista_livro) {
  COPIA atual = lista_livro;

  while (atual != NULL && strcmp(atual->original->titulo, titulo) != 0) {
    atual = atual->prox;
  } 

  return atual;
}

LIVRO remover_livro(LIVRO lista_livro) {
  char titulo[50];
  printf("Digite o titulo do livro a ser removido: ");
  fgets(titulo, 50, stdin);
  titulo[strcspn(titulo, "\n")] = '\0';

  LIVRO atual = buscar_livro(titulo, lista_livro);

  if (atual == NULL) {
    return lista_livro;
  }

  if (atual->anterior != NULL) {
    atual->anterior->proximo = atual->proximo;
  }

  if (atual->proximo != NULL) {
    atual->proximo->anterior = atual->anterior;
  }

  if (atual == lista_livro) {
    lista_livro = lista_livro->proximo;
  }

  free(atual);

  return lista_livro;
}

void remover_copia(COPIA copia, COPIA lista_copia) {
  if (copia == lista_copia) {

    lista_copia = NULL;
    return;
  }

  COPIA atual = lista_copia;
  while (atual != NULL && atual->prox != copia) {
    atual = atual->prox;
  }

  atual->prox = copia->prox;
}

COPIA criar_copia(LIVRO original) {
  COPIA copia = malloc(sizeof (struct copia));
  copia->original = original;
  copia->prox = NULL;

  return copia;
}

void pegar_livro(LEITOR leitor, LIVRO livro) {
  // adicionar na lista de livros do leitor
  COPIA copia = criar_copia(livro);

  if (leitor->lista_livros != NULL) {
    COPIA atual = leitor->lista_livros;

    while (atual->prox != NULL) {
      atual = atual->prox;
    }

    atual->prox = copia;
    return;
  } 

  leitor->lista_livros = copia;
}

void emprestar_livro(LIVRO lista_livro, LEITOR lista_leitor) {
  char titulo_livro[50];
  char nome_leitor[50];

  printf("Digite o nome do leitor: ");
  fgets(nome_leitor, 50, stdin);
  nome_leitor[strcspn(nome_leitor, "\n")] = '\0';

  LEITOR leitor = buscar_leitor(nome_leitor, lista_leitor);
  if (leitor == NULL) {
    printf("Leitor nao encontrado!\n");
    return;
  }

  printf("Digite o nome do livro que deseja emprestado: ");
  fgets(titulo_livro, 50, stdin);
  titulo_livro[strcspn(titulo_livro, "\n")] = '\0';

  LIVRO livro = buscar_livro(titulo_livro, lista_livro);

  if (livro == NULL) {
    printf("Livro nao encontrado!\n");
    return;
  }

  if (livro->disponivel == false) {
    printf("Livro indisponivel!\n");
    enfileirar(leitor, livro->fila_espera);
    printf("%s adicionado na lista de espera!\n", leitor->nome);
    return;
  }

  pegar_livro(leitor, livro);
  livro->disponivel = false;
  printf("Livro emprestado a %s\n", leitor->nome);
}

void devolver_livro(LEITOR lista_leitor) {
  char nome_leitor[50];
  printf("Digite o nome do leitor: ");
  fgets(nome_leitor, 50, stdin);
  nome_leitor[strcspn(nome_leitor, "\n")] = '\0';

  LEITOR leitor = buscar_leitor(nome_leitor, lista_leitor);

  if (leitor == NULL) { printf("Leitor nao encontrado!\n"); return; }

  char titulo[50];
  printf("Digite o titulo do livro que deseja devolver: ");
  fgets(titulo, 50, stdin);
  titulo[strcspn(titulo, "\n")] = '\0';

  COPIA copia = buscar_copia(titulo, leitor->lista_livros);
  if (copia == NULL) { printf("Livro nao encontrado!\n"); return; }

  LIVRO original = copia->original;
  original->disponivel = true;

  // remover livro emprestado da lista de livros do leitor
  remover_copia(copia, leitor->lista_livros);

  if (original->fila_espera->primeiro == NULL) {
    // free(copia);
    return;
  }

  // emprestar o livro ao próximo leitor da fila de espera
  LEITOR prox_leitor = desenfileirar(original->fila_espera);
  pegar_livro(prox_leitor, original);
  original->disponivel = false;
  printf("Livro emprestado a %s.\n", prox_leitor->nome);
}

// LEITOR adicionar_fila_espera(LEITOR leitor, LEITOR fila_espera) {
//   if (fila_espera != NULL) {
//     LEITOR atual = fila_espera;
//     while (atual->proximo != NULL) {
//       atual = atual->proximo;
//     }

//     atual->proximo = leitor;
//   } else {
//     fila_espera = leitor;
//   }

//   return fila_espera;
// }

void enfileirar(LEITOR leitor, FILA_ESPERA fila_espera) {
  if (fila_espera->primeiro == NULL) {
    fila_espera->primeiro = leitor;
    fila_espera->ultimo = leitor;
    return;
  }

  fila_espera->ultimo->proximo = leitor;
  fila_espera->ultimo = leitor;
}

LEITOR desenfileirar(FILA_ESPERA fila_espera) {
  LEITOR leitor = fila_espera->primeiro;
  fila_espera->primeiro = leitor->proximo;

  if (fila_espera->primeiro == NULL) {
    fila_espera->ultimo = NULL;
  }

  return leitor;
}