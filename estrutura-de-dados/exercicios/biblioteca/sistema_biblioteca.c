#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "./leitor.h"
#include "./livro.h"
#include "./types.h"

void menu();
void clear() {
  system("cls");
}

int main(void) {
  LIVRO lista_livro = NULL;
  LEITOR lista_leitor = NULL;
  int opt;

  printf("Sistema de biblioteca\n");

  while (true) {
    menu();
    scanf("%d", &opt);
    getchar();

    switch (opt) {
      case 1:
        lista_livro = cadastrar_livro(lista_livro);
        break;
      case 2:
        lista_livro = remover_livro(lista_livro);
        break;
      case 3:
        emprestar_livro(lista_livro, lista_leitor);
        break;
      case 4:
        devolver_livro(lista_leitor);
        break;
      case 5:
        lista_leitor = cadastrar_leitor(lista_leitor);
        break;
      case 6:
        exibir_livros(lista_livro);
        break;
      case 7:
        exibir_leitores(lista_leitor);
        break;
      case 0:
        printf("Encerrando...\n");
        return 0;
      default:
        printf("Opcao invalida!\n");
        break;
    }

    printf("\n\n");
  }

  return 0;
}

void menu() {
  printf("1 - Cadastrar livro\n2 - Remover livro\n3 - Emprestar livro\n4 - Devolver livro\n5 - Cadastrar leitor\n6 - Exibir livros\n7 - Exibir leitores\n0 - Sair\n");
}