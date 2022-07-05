#include <stdio.h>
#include "trees.h"


int main() {
    arvoreRubroNegra* a = criar();

    adicionar(a,7);
    adicionar(a,6);
    adicionar(a,5);
    adicionar(a,4);
    adicionar(a,3);
    adicionar(a,2);
    adicionar(a,1);

    printf("In-order: ");
    percorrerProfundidadeInOrder(a, a->raiz,visitar);
    printf("\n");
}