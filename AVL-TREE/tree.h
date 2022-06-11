#include <stdio.h>
#include <stdlib.h>

typedef struct cell node;
struct cell{
    int vertice;
    node* father;
    node* left;
    node* right;
};

node* ordered_insert(node* tree, int value); // insert in an ordered way the values in the tree
int height(node* cell);  // returns the height of the tree
int balanced_factor(node* cell);  // returns the diff between left and right so we can get where it's "weight" is going
node* simple_left_rotation(node* cell);
node* simple_right_rotation(node* cell);
node* double_left_rotation(node* cell);
node* double_right_rotation(node* cell);
void show_tree(node* cell);