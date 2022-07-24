#include <stdio.h>
#include <time.h>
#include "trees.h"

//AVLpercorrerProfundidadeInOrder(b->raiz, visitarAVL);
//percorrerProfundidadeInOrder(a, a->raiz,visitar);
int main() {
    srand(time(NULL));
    int r;
    // Rubro negra
    printf("\n - RUBRO NEGRA -");
    int contadorRN = 0;
    int *p_contadorRN = &contadorRN;
    ArvoreRubroNegra* a = criar(p_contadorRN);
    contadorRN=0;
    // melhor caso
    for(int i = 0; i <= 1000; i++){
        adicionar(a,i,p_contadorRN);
    }
    printf("\n- MELHOR CASO - Rubro Negra: %i", contadorRN);
    vazia(a);
    contadorRN=0;
    // caso médio
    for(int i = 0; i <= 1000; i++){
        r = rand();
        adicionar(a,r,p_contadorRN);
    }
    printf("\n- CASO MEDIO - Rubro Negra: %i", contadorRN);
    vazia(a);
    contadorRN=0;
    // pior caso
    for(int i = 1000; i >= 0; i--){
        adicionar(a,i,p_contadorRN);
    }
    printf("\n- PIOR CASO - Rubro Negra: %i", contadorRN);
    vazia(a);
    contadorRN=0;
    // ALV
    printf("\n - AVL -");
    ArvoreAVL* b = criarAVL();
    int contadorAVL = 0;
    int *p_contadorAVL = &contadorAVL;

    // melhor caso
    for(int i = 0; i <= 1000; i++){
        AVLadicionar(b,i, p_contadorAVL);
    }
    printf("\n- MELHOR CASO - AVL: %i", *p_contadorAVL);
    contadorAVL=0;
    vaziaAVL(b);
    // caso médio
    for (int i = 1; i <= 1000; i++) {
        r = rand();
        AVLadicionar(b,r, p_contadorAVL);
    }
    printf("\n- CASO MEDIO - AVL: %i", *p_contadorAVL);
    contadorAVL = 0;
    vaziaAVL(b);
    // pior caso
    for(int i = 1000; i >= 0; i--){
        AVLadicionar(b,i,p_contadorAVL);
    }
    printf("\n- PIOR CASO - AVL: %i", *p_contadorAVL);
    vaziaAVL(b);
    contadorAVL = 0;
    // B


    //
    return 0;
}