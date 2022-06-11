#include <stdio.h>
#include <stdlib.h>
#include "tree.h"

#define SIZE 9 // tamanho do vetor

int main(){
    // exercício 1: Implemente uma árvore AVL e adicione os nós de modo que a árvore apresente a 
    // respectiva topologia abaixo. 4, 2, 8, 1, 3, 6, 9, 5, 7
    // exercício 2: Implemente a operação de remoção de nós em uma árvore AVL e valide removendo o 
    // nó 6 do exercício anterior.
    
    int array[SIZE] = {4, 2, 8, 1, 3, 6, 9, 5, 7};
    node* tree = NULL;
    for(int i = 0; i < SIZE; i++){
        tree = ordered_insert(tree, array[i]);
    }
    //printf("%d", tree->vertice);
    show_tree(tree);

    return 0;
}