# CAPÍTULO 3 - FILA

## FUNDAMENTOS

Fila é uma lista em que as inserções são feitas num extremo, denominado final, e as remoções são feitas no extremo oposto, denominado início.

Quando um novo item é inserido numa fila, ele é colocado em seu final e, em qualquer instante, apenas o item no início da fila pode ser removido. Devido a essa política de acesso, os itens de uma fila são removidos na mesma ordem em que foram inseridos, ou seja, o primeiro a entrar é o primeiro a sair. Por isso, as filas também são denominadas listas **FIFO (Fisrt-In/First-Out)**.

A principal propriedade de uma fila é a sua capacidade de manter a ordem de uma sequência.

## Operações em pilhas

Uma fila F suporta as seguintes operações:

- fila(m): cria e devolve uma fila vazia F, com capacidade máxima m;
- vaziaf(F): devolve 1 (verdade) se F está vaiza; senão, devolve 0 (falso);
- cheiaf(F): devolve 1 (verdade) se F está cheia; senão, devolve 0 (falso);
- enfileira(x, F): insere o item x no final da fila F;
- desenfileira(F): remove e devolve o item existente no início da fila F;
- destroif(&F): destrói a fila F.