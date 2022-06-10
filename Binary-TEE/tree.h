typedef struct cell node;
struct cell{
    int vertice;
    node* father;
    node* left;
    node* right;
};

typedef struct tree;
struct tree{
    struct node* root;
} Tree;

typedef struct element {
    node* indice;
    struct element* ancestor;
} Element;

typedef struct pilha{
    Element* top;
} Pilha;


Pilha* createPilha(Pilha* p, node* indice);