#include <stdlib.h>
#include <stdio.h>

/**
 * Faça uma algoritmo que implemente uma função que leia uma sequência de NÚMEROS informados pelo usuário, salve-os numa lista duplamente encadeada, ordene-os usando um dos algoritmos de ordenação visto em sala e mostre-os em ordem crescente.
*/

typedef struct node {
  int value;
  struct node *next;
  struct node *prev;
} *NODE;

typedef struct dlinked_list {
  struct node *start;
} *DLINKED_LIST;

DLINKED_LIST init() {
  DLINKED_LIST dlinked_list = malloc(sizeof (struct dlinked_list));

  dlinked_list->start = malloc(sizeof (struct node));
  dlinked_list->start = NULL;

  return dlinked_list;
}

NODE create_node() {
  NODE new_node = malloc(sizeof (struct node));
  new_node->next = NULL;
  new_node->prev = NULL;

  return new_node;
}

DLINKED_LIST insert(int value, DLINKED_LIST dlinked_list) {
  NODE new_node = create_node();
  new_node->value = value;

  NODE actual = dlinked_list->start;

  if (actual == NULL) {
    dlinked_list->start = new_node;
    return dlinked_list;
  }

  while (actual->next != NULL) {
    actual = actual->next;
  }

  actual->next = new_node;
  new_node->prev = actual;

  return dlinked_list;
}

void show(DLINKED_LIST dlinked_list) {
  NODE actual = dlinked_list->start;

  while (actual != NULL) {
    printf("%d\n", actual->value);
    actual = actual->next;
  }
}

DLINKED_LIST bubble_sort(DLINKED_LIST list) {
    if (list->start == NULL || list->start->next == NULL) {
        return list;  // Lista vazia ou com apenas um elemento, não há necessidade de ordenação
    }
    
    int swapped;
    NODE current;
    NODE last = NULL;
    
    do {
        swapped = 0;
        current = list->start;
        
        while (current->next != last) {
            if (current->value > current->next->value) {
                // Troca os valores dos nós adjacentes
                int temp = current->value;
                current->value = current->next->value;
                current->next->value = temp;
                swapped = 1;
            }
            
            current = current->next;
        }
        
        last = current;  // O último nó visitado na iteração anterior é o novo último nó
    } while (swapped);

    return list;
}



int main(void) {
  int value, flag = 1;
  DLINKED_LIST dlinked_list = init();

  while (flag) {
    printf("Digite o valor do no: ");
    scanf("%d", &value);

    insert(value, dlinked_list);

    printf("Deseja adicionar outro no? (1 - Sim / 0 - Nao)");
    scanf("%d", &flag);
  }


  dlinked_list = bubble_sort(dlinked_list);
  printf("Lista duplamente encadeada ordenada crescentemente\n");
  show(dlinked_list);

  return 0;
}