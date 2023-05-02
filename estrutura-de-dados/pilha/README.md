# PILHA - FUNDAMENTOS

Pilha é uma lista em que todas as operações de inserção, remoção e acesso são feitas num mesmo extremo, denominado topo.

Quando um item é inserido numa pilha, ele é colocado em seu topo e, em qualquer instante, apenas o item no topo da pilha pode ser removido Devido a essa política de a acesso, os itens são removidos da pilha na ordem inversa àquela em foram inseridos, ou seja, o último a entrara é o primeiro a sair. Por isso, pilhas são também denomindas listas **LIFO (Last-In/First-Out)**.

A principal propriedade de uma pilha é a sua capacidade de **inverter a ordem** de uma sequência. Essa propriedade é útil em várias aplicações em computação.

## Operações em pilhas

Uma pilha P suporta as seguintes operações:

- pilha(m): cria e devolve uma pilha vazia P, com capacidade máxima m;
- vaziap(P): devolve 1 (verdade) se P está vaiza; senão, devolve 0 (falso);
- cheiap(P): devolve 1 (verdade) se P está cheia; senão, devolve 0 (falso);
- empilha(x, P): insere o item x no topo da pilha P;
- desempilha(P): remove e devolve o item existente no topo da pilha P;
- topo(P): acessa e devolve o item existente no topo da pilha P;
- destroip(&P): destrói a pilha P.