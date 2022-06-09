#include <stdio.h>
#include "tree.h"

node* ordered_insert(node* tree,node* cell, int vertice){
    if(tree != NULL){
        if(vertice < tree->vertice){
            tree = insert(tree->left, cell, vertice);
        }
        if(vertice > tree->vertice){
            tree = insert(tree->right, cell, vertice);
        }
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