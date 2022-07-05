#include <stdlib.h>
#include <stdio.h>

enum coloracao { Vermelho, Preto };
typedef enum coloracao Cor;

typedef struct noRubroNegra {
    struct noRubroNegra* pai;
    struct noRubroNegra* esquerda;
    struct noRubroNegra* direita;
    Cor cor;
    int valor;
} noRubroNegra;

typedef struct arvoreRubroNegra {
    struct noRubroNegra* raiz;
    struct noRubroNegra* nulo; 
} arvoreRubroNegra;

noRubroNegra* criarNoRubroNegra(arvoreRubroNegra*, noRubroNegra*, int);
void balancear(arvoreRubroNegra*, noRubroNegra*);
void rotacionarEsquerda(arvoreRubroNegra*, noRubroNegra*);
void rotacionarDireita(arvoreRubroNegra*, noRubroNegra*);
arvoreRubroNegra* criar();
int vazia(arvoreRubroNegra*);
noRubroNegra* adicionar(arvoreRubroNegra*, int);
noRubroNegra* localizar(arvoreRubroNegra* arvore, int valor);