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
} NoRubroNegra;

typedef struct arvoreRubroNegra {
    struct noRubroNegra* raiz;
    struct noRubroNegra* nulo; 
} ArvoreRubroNegra;

NoRubroNegra* criarNo(ArvoreRubroNegra*, NoRubroNegra*, int);
void balancear(ArvoreRubroNegra*, NoRubroNegra*);
void rotacionarEsquerda(ArvoreRubroNegra*, NoRubroNegra*);
void rotacionarDireita(ArvoreRubroNegra*, NoRubroNegra*);
ArvoreRubroNegra* criar();
int vazia(ArvoreRubroNegra*);
NoRubroNegra* adicionar(ArvoreRubroNegra*, int);
NoRubroNegra* localizar(ArvoreRubroNegra* arvore, int valor);
void percorrerProfundidadeInOrder(ArvoreRubroNegra* arvore, NoRubroNegra* no, void (*callback)(int));
void percorrerProfundidadePreOrder(ArvoreRubroNegra* arvore, NoRubroNegra* no, void (*callback)(int));
void percorrerProfundidadePosOrder(ArvoreRubroNegra* arvore, NoRubroNegra* no, void (callback)(int));
void visitar(int valor);