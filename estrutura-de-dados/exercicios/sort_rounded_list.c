#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * Faça um algoritmo que implemente uma função que leia uma sequência de NOMES informados pelo usuário, salve-os numa lista simplesmente encadeada circular, ordene-os usando um dos algoritmos de ordenação visto em sala e mostre-os em ordem decrescente.
*/

typedef struct Node {
    char name[50];
    struct Node* next;
} Node;

typedef struct List {
    Node* head;
} List;

List* createList() {
    List* list = malloc(sizeof(List));
    list->head = NULL;
    return list;
}

void insertNode(List* list, const char* name) {
    Node* newNode = malloc(sizeof(Node));
    strcpy(newNode->name, name);
    newNode->next = NULL;

    if (list->head == NULL) {
        list->head = newNode;
        newNode->next = newNode;  // Lista circular, aponta para si mesmo
    } else {
        Node* current = list->head;
        while (current->next != list->head) {
            current = current->next;
        }
        current->next = newNode;
        newNode->next = list->head;
    }
}

void printList(List* list) {
    if (list->head == NULL) {
        printf("Lista vazia.\n");
        return;
    }

    Node* current = list->head;
    do {
        printf("%s\n", current->name);
        current = current->next;
    } while (current != list->head);
}

void sortList(List* list) {
    if (list->head == NULL || list->head->next == list->head) {
        return;  // Lista vazia ou com apenas um elemento, não há necessidade de ordenação
    }

    int swapped;
    Node* current;
    Node* head = list->head;

    do {
        swapped = 0;
        current = list->head;

        while (current->next != head) {
            if (strcmp(current->name, current->next->name) < 0) {
                // Troca os valores dos nós adjacentes
                char temp[50];
                strcpy(temp, current->name);
                strcpy(current->name, current->next->name);
                strcpy(current->next->name, temp);
                swapped = 1;
            }

            current = current->next;
        }

    } while (swapped);
}

int main() {
    List* list = createList();

    int n;
    printf("Digite a quantidade de nomes: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        char name[50];
        printf("Digite o nome %d: ", i + 1);
        scanf("%s", name);
        insertNode(list, name);
    }

    printf("Lista original:\n");
    printList(list);

    sortList(list);

    printf("\nLista ordenada em ordem decrescente:\n");
    printList(list);

    return 0;
}
