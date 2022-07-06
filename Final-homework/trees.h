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

typedef struct noAVL {
    struct noAVL* pai;
    struct noAVL* esquerda;
    struct noAVL* direita;
    int valor;
} NoAVL;

typedef struct arvoreAVL {
    struct noAVL* raiz;
} ArvoreAVL;

//Rubro-negra
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
//AVL
ArvoreAVL* criarAVL();
NoAVL* AVLadicionar(ArvoreAVL* arvore, int valor);
void balanceamento(ArvoreAVL*, NoAVL* no);
int altura(NoAVL* no);
int fb(NoAVL* no);
NoAVL* rsd(ArvoreAVL*, NoAVL* no);
NoAVL* rse(ArvoreAVL*, NoAVL* no);
NoAVL* rdd(ArvoreAVL*, NoAVL* no);
NoAVL* rde(ArvoreAVL*, NoAVL* no);
void AVLpercorrerProfundidadeInOrder(NoAVL* no, void (*callback)(int));
void AVLpercorrerProfundidadePreOrder(NoAVL* no, void (*callback)(int));
void AVLpercorrerProfundidadePosOrder(NoAVL* no, void (callback)(int));
void visitarAVL(int valor);