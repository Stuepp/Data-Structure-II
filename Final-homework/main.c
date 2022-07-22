#include <stdio.h>
#include "trees.h"


int main() {
    // Rubro negra
    printf("Rubro negra:\n");
    ArvoreRubroNegra* a = criar();

    adicionar(a,7);
    adicionar(a,6);
    adicionar(a,5);
    adicionar(a,4);
    adicionar(a,3);
    adicionar(a,2);
    adicionar(a,1);

    printf("In-order: ");
    percorrerProfundidadeInOrder(a, a->raiz,visitar);
    printf("\nPre-order:");
    percorrerProfundidadePreOrder(a, a->raiz, visitar);
    printf("\nPos-order:");
    percorrerProfundidadePosOrder(a, a->raiz, visitar);
    printf("\n");

    // ALV
    printf("AVL:\n");
    ArvoreAVL* b = criarAVL();

    for (int i = 1; i <= 7; i++) {
        AVLadicionar(b,i);
    }

    printf("In-order: ");
    AVLpercorrerProfundidadeInOrder(b->raiz,visitarAVL);
    printf("\nPre-order:");
    AVLpercorrerProfundidadePreOrder(b->raiz,visitarAVL);
    printf("\nPos-order:");
    AVLpercorrerProfundidadePosOrder(b->raiz,visitarAVL);
    // B


    //
    return 0;
}