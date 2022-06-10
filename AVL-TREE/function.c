#include <stdio.h>
#include "tree.h"

node* ordered_insert(node* tree,node* cell){
    cell->left = NULL;
    cell->right = NULL;
    if(tree != NULL){
        if(cell->vertice < tree->vertice){
            tree->left = insert(tree->left, cell);
        }
        if(cell->vertice > tree->vertice){
            tree->right = insert(tree->right, cell);
        }
    }else{
        cell->father = NULL;
        cell->left = NULL;
        cell->right = NULL;
        return cell;
    }
}

int height(node* cell){
    int left = 0, right = 0;
    
    if(cell->left != NULL){
        left = height(cell->left) + 1;
    }
    if(cell -> right != NULL){
        right = height(cell->right) + 1;
    }

    return left > right ? left : right; // if left > right then left else then right
}

int balanced_factor(node* cell){
    int left = 0, right = 0;

    if(cell->left != NULL){
        left = height(cell->left) + 1;
    }
    if(cell->right != NULL){
        right = height(cell->right) + 1;
    }

    return left - right; // returns the diff between left and right so we can get where it's "weight" is going
}

node* simple_left_rotation(node* cell){
    node* father = cell->father;
    node* right = cell->right;

    cell->right = right->left;
    cell->father = right;

    right->left = cell;
    right->father = father;

    return right;
}

node* simple_right_rotation(node* cell){
    node* father = cell->father;
    node* left = cell->left;

    cell->left = left->right;
    cell->father = left;

    left->right =cell;
    left->father = father;

    return left;
}

node* double_left_rotation(node* cell){
    cell->right = simple_right_rotation(cell->right);
    return simple_left_rotation(cell);
}

node* double_right_rotation(node* cell){
    cell->left = simple_left_rotation(cell->left);
    return simple_right_rotation(cell);
}

void show_tree(node* cell){ // a fazer...
    if(cell != NULL){
        printf("\n%d", cell->vertice);
        printf("\n%d", cell->left->vertice);
        printf("\n%d", cell->right->vertice);

    }else{
        printf("\nEmpty TREE! or end of tree");
    }
}

void percorrer_iterativo(node* cell){
    Pilha* p = criarPilha();
    push(p, cell);

    while(p->top != NULL){
        node* cell = pop(p);

        printf("%d", cell->vertice);

        if(cell->right){
            push(p, no->right);
        }
        if(cell->left){
            push(p, cell->left);
        }
    }
}

Pilha* createPilha(Pilha* p, node* indice){
    Pilha* p = malloc(sizeof(Pilha));
    p->top = NULL;
}

void push(Pilha* p, node* indice){
    Element* e = malloc(sizeof(Element));
    e->indice = indice;
    e->ancestor = p->top;

    p->top = e;
}

node* pop(Pilha* p){
    node* value = p->top->ancestor;

    if(p->top != NULL){ // Pilha não estar vazia
        p->top = p->top->ancestor;
    }

    return value;
}