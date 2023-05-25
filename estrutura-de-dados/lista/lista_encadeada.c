#include <stdio.h>
#include <stdlib.h>

typedef struct reg {
    int conteudo;
    struct reg *prox;
} celula;

celula *inserir(int x, celula *p) {
    // Criação de um novo elemento
    celula *nova;
    nova = malloc(sizeof(celula));
    nova->conteudo = x;
    nova->prox = NULL;
    
    // Inseri nova no inicioda lista
    if (p != NULL) nova->prox = p;
    p = nova;
    
    return p;
}

void imprimir(celula *lista) {
    if (lista != NULL) {
        printf("%d\n", lista->conteudo);
        imprimir(lista->prox);
    }
}

celula *inserir_final(int x, celula *p) {
    celula *novo, *topo = p;
    
    novo = malloc(sizeof(celula));
    novo->conteudo = x;
    novo->prox = NULL;
    
    if (p != NULL) {
       // Acessar o último elemento
       for (p; p->prox != NULL; p = p->prox);
       p->prox = novo;
    } else topo = novo;
    
    return topo;
}

celula *buscar(int x, celula *lista) {
    celula *p;
    p = lista;
    
    while(p != NULL && p->conteudo != x)
        p = p->prox;
        
    return p;
}

celula *buscar_recursivo(int x, celula *lista) {
    if (lista == NULL) return NULL;
    
    if (lista->conteudo == x) return lista;
    
    return buscar_recursivo(x, lista->prox);
}

celula *buscar_remover(int x, celula *lista) {
    celula *p, *q;
    
    p = lista;
    
    if (p->conteudo == x) {
        q = lista;
        p = lista->prox;
        free(q);
        return p;
    }
    
    q = lista->prox;
    
    while (q != NULL && q->conteudo != x) {
        p = q;
        q = q->prox;
    }
    
    if (q != NULL) {
        p->prox = q->prox;
        free(q);
    }
    
    return lista;
}

int main()
{
    int resp, resp2 = 1;
    printf("Lista Simplesmente Encadeada\n");
    celula *topo, *buscado;
    
    for (int i = 0; i < 10; i++) {
        printf("Digite o próximo elemento da lista: ");
        scanf("%d", &resp);
        topo = inserir_final(resp, topo);
    }
    printf("Fim da insercao\n");
    
    while (resp2) {
        printf("Digite o elemento que deseja remover da lista: ");
        scanf("%d", &resp);
        
        topo = buscar_remover(resp, topo);
        
        imprimir(topo);
        
        printf("Deseja repetir a busca? 1 - Sim, 0 - Nao\n");
        scanf("%d", &resp2);
    }

    return 0;
}
