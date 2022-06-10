/*
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
*/