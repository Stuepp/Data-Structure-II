ArvoreB* cria_arvore_binaria(int ordem){ // cria uma árvore binária com uma ordem predefinida
    ArvoreB* a = malloc(sizeof(ArvoreB));
    a->ordem = ordem;
    a->raiz = criaNo(a);

    return a;
}
No* cria_no(ArvoreB* arvore){ // cria uma árvore binária com uma ordem predefinida (continuação)
    int max = arvore->ordem * 2;
    No* no = malloc(sizeof(No));

    no->pai = NULL;

    no->chaves = malloc(sizeof(int) * (max + 1));
    no->filhos = malloc(sizeof(No) * (max + 2));
    no->total = 0;

    for(int i = 0; i < max + 2;i++){
        no->filhos[i] = NULL;
    }
    return no;
}
void percorre_arvore(No* no, void(visita)(int chave)){ // percorre uma árvore a partir de um nó
    if(no != NULL){
        for(int i = 0; i < no->total;i++){
            percorre_arvore(no->filhos[i], visita);
        }
        percorre_arvore(no->filhos[no->total], visita);
    }
}
int localiza_chave(ArvoreB* arvore, int chave){ // localzia uma chave em uma árvore
    No *no = arvore->raiz;

    while(no != NULL){
        int i = pesquisa_binaria(no, chave)/

        if(i < no->total && no->chaves[i] == chave){
            return 1; // encontrou
        } else{
            no = no->filhos[i];
        }
    }

    return 0; // não encontrou
}
int pesquisa_binaria(No* no, int chave){ // localiza uma chave em uma árvore (continuação)
    int inicio = 0, fim = no->total - 1, meio;
    while(inicio <= fim){
        mio = (inicio + fim) / 2;
        if(no->chaves[meio] == chave){
            return meio; // encontrou
        } else if(no->chaves[meio] > chave){
            fim = meio - 1;
        } else{
            inicio = meio + 1;
        }
    }
    return inicio; // não encontrou
}
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