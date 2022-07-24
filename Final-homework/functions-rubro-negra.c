#include <stdio.h>
#include "trees.h"

ArvoreRubroNegra* criar(int *contador) {
    ArvoreRubroNegra *arvore = malloc(sizeof(ArvoreRubroNegra));
    arvore->nulo = NULL;
    arvore->raiz = NULL;

    arvore->nulo = criarNo(arvore, NULL, 0, contador);
    arvore->nulo->cor = Preto;

    return arvore;
}

int vazia(ArvoreRubroNegra* arvore) {
    return arvore->raiz == NULL;
}

NoRubroNegra* criarNo(ArvoreRubroNegra* arvore, NoRubroNegra* pai, int valor, int* contador) {
    *contador+=1;
    NoRubroNegra* no = malloc(sizeof(NoRubroNegra));

    no->pai = pai;    
    no->valor = valor;
    no->direita = arvore->nulo;
    no->esquerda = arvore->nulo;

    return no;
}

NoRubroNegra* adicionarNo(ArvoreRubroNegra* arvore, NoRubroNegra* no, int valor, int* contador) {
    *contador+=1;
    if (valor > no->valor) {
        if (no->direita == arvore->nulo) {
            no->direita = criarNo(arvore, no, valor, contador);     
            no->direita->cor = Vermelho;       
        		
            return no->direita;
        } else {
            return adicionarNo(arvore, no->direita, valor, contador);
        }
    } else {
        if (no->esquerda == arvore->nulo) {
            no->esquerda = criarNo(arvore, no, valor, contador);
            no->esquerda->cor = Vermelho;
            
            return no->esquerda;
        } else {
            return adicionarNo(arvore, no->esquerda, valor, contador);
        }
    }
}

NoRubroNegra* adicionar(ArvoreRubroNegra* arvore, int valor, int* contador) {
    *contador+=1;
    if (vazia(arvore)) {
        arvore->raiz = criarNo(arvore, arvore->nulo, valor, contador);
        arvore->raiz->cor = Preto;
        	
        return arvore->raiz;
    } else {
        NoRubroNegra* no = adicionarNo(arvore, arvore->raiz, valor, contador);
        balancear(arvore, no, contador);
        
        return no;
    }
}

NoRubroNegra* localizar(ArvoreRubroNegra* arvore, int valor) {
    if (!vazia(arvore)) {
        NoRubroNegra* no = arvore->raiz;

        while (no != arvore->nulo) {
            if (no->valor == valor) {
                return no;
            } else {
                no = valor < no->valor ? no->esquerda : no->direita;
            }
        }
    }

    return NULL;
}

void percorrerProfundidadeInOrder(ArvoreRubroNegra* arvore, NoRubroNegra* no, void (*callback)(int)) {
    if (no != arvore->nulo) {
        percorrerProfundidadeInOrder(arvore, no->esquerda,callback);
        callback(no->valor);
        percorrerProfundidadeInOrder(arvore, no->direita,callback);
    }
}

void percorrerProfundidadePreOrder(ArvoreRubroNegra* arvore, NoRubroNegra* no, void (*callback)(int)) {
    if (no != arvore->nulo) {
        callback(no->valor);
        percorrerProfundidadePreOrder(arvore, no->esquerda,callback);
        percorrerProfundidadePreOrder(arvore, no->direita,callback);
    }
}

void percorrerProfundidadePosOrder(ArvoreRubroNegra* arvore, NoRubroNegra* no, void (callback)(int)) {
    if (no != arvore->nulo) {
        percorrerProfundidadePosOrder(arvore, no->esquerda,callback);
        percorrerProfundidadePosOrder(arvore, no->direita,callback);
        callback(no->valor);
    }
}

void visitar(int valor){ // desenvolver
    printf("%d ", valor);
}

void balancear(ArvoreRubroNegra* arvore, NoRubroNegra* no, int* contador) {
    *contador+=1;
    while (no->pai->cor == Vermelho) {
        if (no->pai == no->pai->pai->esquerda) {
            NoRubroNegra *tio = no->pai->pai->direita;
            
            if (tio->cor == Vermelho) {
                tio->cor = Preto; //Caso 1
                no->pai->cor = Preto; 

                no->pai->pai->cor = Vermelho; //Caso 1
                no = no->pai->pai; //Caso 1
            } else {
                if (no == no->pai->direita) {
                    no = no->pai; //Caso 2
                    rotacionarEsquerda(arvore, no, contador); //Caso 2
                } else {
                    no->pai->cor = Preto; 
                    no->pai->pai->cor = Vermelho; //Caso 3
                    rotacionarDireita(arvore, no->pai->pai, contador); //Caso 3
                }
            }
        } else {
            NoRubroNegra *tio = no->pai->pai->esquerda;
            
            if (tio->cor == Vermelho) {
                tio->cor = Preto; //Caso 1
                no->pai->cor = Preto; 

                no->pai->pai->cor = Vermelho; //Caso 1
                no = no->pai->pai; //Caso 1
            } else {
                if (no == no->pai->esquerda) {
                    no = no->pai; //Caso 2
                    rotacionarDireita(arvore, no, contador); //Caso 2
                } else {
                    no->pai->cor = Preto; 
                    no->pai->pai->cor = Vermelho; //Caso 3
                    rotacionarEsquerda(arvore, no->pai->pai, contador); //Caso 3
                }
            }
        }
    }
    arvore->raiz->cor = Preto; //Conserta possível quebra regra 2
}

void rotacionarEsquerda(ArvoreRubroNegra* arvore, NoRubroNegra* no, int* contador) {
    *contador+=1;
    NoRubroNegra* direita = no->direita;
    no->direita = direita->esquerda; 

    if (direita->esquerda != arvore->nulo) {
        direita->esquerda->pai = no;
    }

    direita->pai = no->pai;
    
    if (no->pai == arvore->nulo) {
        arvore->raiz = direita;
    } else if (no == no->pai->esquerda) {
        no->pai->esquerda = direita;
    } else {
        no->pai->direita = direita;
    }

    direita->esquerda = no;
    no->pai = direita;
}

void rotacionarDireita(ArvoreRubroNegra* arvore, NoRubroNegra* no, int* contador) {
    *contador+=1;
    NoRubroNegra* esquerda = no->esquerda;
    no->esquerda = esquerda->direita;
    
    if (esquerda->direita != arvore->nulo) {
        esquerda->direita->pai = no;
    }
    
    esquerda->pai = no->pai;
    
    if (no->pai == arvore->nulo) {
        arvore->raiz = esquerda;
    } else if (no == no->pai->esquerda) {
        no->pai->esquerda = esquerda;
    } else {
        no->pai->direita = esquerda;
    }
    
    esquerda->direita = no;
    no->pai = esquerda;
}