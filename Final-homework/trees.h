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
NoRubroNegra* criarNo(ArvoreRubroNegra*, NoRubroNegra*, int valor, int* contador);
void balancear(ArvoreRubroNegra*, NoRubroNegra*, int* contador);
void rotacionarEsquerda(ArvoreRubroNegra*, NoRubroNegra*, int* contador);
void rotacionarDireita(ArvoreRubroNegra*, NoRubroNegra*, int* contador);
ArvoreRubroNegra* criar(int* contador);
int vazia(ArvoreRubroNegra*);
NoRubroNegra* adicionar(ArvoreRubroNegra*, int valor, int* contador);
NoRubroNegra* localizar(ArvoreRubroNegra* arvore, int valor);
void percorrerProfundidadeInOrder(ArvoreRubroNegra* arvore, NoRubroNegra* no, void (*callback)(int));
void percorrerProfundidadePreOrder(ArvoreRubroNegra* arvore, NoRubroNegra* no, void (*callback)(int));
void percorrerProfundidadePosOrder(ArvoreRubroNegra* arvore, NoRubroNegra* no, void (callback)(int));
void visitar(int valor);
//AVL
ArvoreAVL* criarAVL();
NoAVL* AVLadicionar(ArvoreAVL* arvore, int valor, int* contador);
void balanceamento(ArvoreAVL*, NoAVL* no, int* contador);
int altura(NoAVL* no);
int fb(NoAVL* no, int*contador);
NoAVL* rsd(ArvoreAVL*, NoAVL* no, int* contador);
NoAVL* rse(ArvoreAVL*, NoAVL* no, int* contador);
NoAVL* rdd(ArvoreAVL*, NoAVL* no, int* contador);
NoAVL* rde(ArvoreAVL*, NoAVL* no, int* contador);
void AVLpercorrerProfundidadeInOrder(NoAVL* no, void (*callback)(int));
void AVLpercorrerProfundidadePreOrder(NoAVL* no, void (*callback)(int));
void AVLpercorrerProfundidadePosOrder(NoAVL* no, void (callback)(int));
void visitarAVL(int valor);
int vaziaAVL(ArvoreAVL* arvore);