#include <stdio.h>
#include <stdlib.h>

/**
 * Faça um algoritmo que leia duas listas informadas pelo usuário, depois mostre-as na tela e deixe o usuário escolher um elemento de cada lista e troque-os. Não pode trocar apenas o conteúdo da célula, deve-se realizar a troca através da manipulação de ponteiros, trocando as células de posição.
*/

typedef struct Node {
    int value;
    struct Node* next;
} Node;

Node* createNode(int value) {
    Node* newNode = malloc(sizeof(struct Node));
    newNode->value = value;
    newNode->next = NULL;
    return newNode;
}

void insertNode(Node** head, int value) {
    Node* newNode = createNode(value);

    if (*head == NULL) {
        *head = newNode;
    } else {
        Node* current = *head;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = newNode;
    }
}

void printList(Node* head) {
    if (head == NULL) {
        printf("Lista vazia.\n");
        return;
    }

    Node* current = head;
    while (current != NULL) {
        printf("%d ", current->value);
        current = current->next;
    }
    printf("\n");
}

void swapNodes(Node** head1, Node** head2, int value1, int value2) {
    if (*head1 == NULL || *head2 == NULL) {
        printf("Pelo menos uma das listas está vazia.\n");
        return;
    }

    Node* node1 = NULL;
    Node* prev1 = NULL;
    Node* current1 = *head1;
    while (current1 != NULL && current1->value != value1) {
        prev1 = current1;
        current1 = current1->next;
    }
    node1 = current1; // final da lista

    Node* node2 = NULL;
    Node* prev2 = NULL;
    Node* current2 = *head2;
    while (current2 != NULL && current2->value != value2) {
        prev2 = current2;
        current2 = current2->next;
    }
    node2 = current2; // final da lista

    if (node1 == NULL || node2 == NULL) {
        printf("Pelo menos um dos elementos não foi encontrado nas listas.\n");
        return;
    }

    if (prev1 != NULL) { // lista tem mais de um elemento
        prev1->next = node2;
    } else {
        *head1 = node2;
    }

    if (prev2 != NULL) { // lista tem mais de um elemento
        prev2->next = node1;
    } else {
        *head2 = node1;
    }

    Node* temp = node1->next;
    node1->next = node2->next;
    node2->next = temp;
}

int main() {
    Node* list1 = NULL;
    Node* list2 = NULL;

    int n1, n2;
    printf("Digite a quantidade de elementos da lista 1: ");
    scanf("%d", &n1);

    for (int i = 0; i < n1; i++) {
        int value;
        printf("Digite o elemento %d da lista 1: ", i + 1);
        scanf("%d", &value);
        insertNode(&list1, value);
    }

    printf("\nDigite a quantidade de elementos da lista 2: ");
    scanf("%d", &n2);

    for (int i = 0; i < n2; i++) {
        int value;
        printf("Digite o elemento %d da lista 2: ", i + 1);
        scanf("%d", &value);
        insertNode(&list2, value);
    }

    printf("\nListas antes da troca:\n");
    printf("Lista 1: ");
    printList(list1);
    printf("Lista 2: ");
    printList(list2);

    int value1, value2;
    printf("\nDigite o valor a ser trocado na lista 1: ");
    scanf("%d", &value1);
    printf("Digite o valor a ser trocado na lista 2: ");
    scanf("%d", &value2);

    swapNodes(&list1, &list2, value1, value2);

    printf("\nListas depois da troca:\n");
    printf("Lista 1: ");
    printList(list1);
    printf("Lista 2: ");
    printList(list2);

    return 0;
}
