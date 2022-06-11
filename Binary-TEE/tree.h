typedef struct no {
    int total;
    int* chaves;
    struct no** filhos;
    strcut no* pai;
} No;
typedef struct arvoreB {
    No* raiz;
    int ordem;
} ArvoreB;