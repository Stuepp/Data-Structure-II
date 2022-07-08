#include <stdio.h>
#include "trees.h"

ArvoreAVL* criarAVL() {
    ArvoreAVL *arvore = malloc(sizeof(ArvoreAVL));
    arvore->raiz = NULL;
  
    return arvore;
}

int vaziaAVL(ArvoreAVL* arvore) {
    return arvore->raiz == NULL;
}

NoAVL* adicionarNoAVL(NoAVL* no, int valor) {
    if (valor > no->valor) {
        if (no->direita == NULL) {
            printf("Adicionando %d\n",valor);
            NoAVL* novo = malloc(sizeof(NoAVL));
            novo->valor = valor;
            novo->pai = no;
            novo->esquerda = NULL;
            novo->direita = NULL;

            no->direita = novo;
				
            return novo;
        } else {
            return adicionarNoAVL(no->direita, valor);
        }
    } else {
        if (no->esquerda == NULL) {
            printf("Adicionando %d\n",valor);
            NoAVL* novo = malloc(sizeof(NoAVL));
			novo->valor = valor;
            novo->pai = no;
            novo->esquerda = NULL;
            novo->direita = NULL;
			
            no->esquerda = novo;
			
            return novo;
        } else {
            return adicionarNoAVL(no->esquerda, valor);
        }
    }
}

NoAVL* AVLadicionar(ArvoreAVL* arvore, int valor) {
    if (arvore->raiz == NULL) {
        printf("Adicionando %d\n",valor);
        NoAVL* novo = malloc(sizeof(NoAVL));
        novo->valor = valor;
        novo->esquerda = NULL;
        novo->direita = NULL;
        
        arvore->raiz = novo;
			
        return novo;
    } else {
        NoAVL* no = adicionarNoAVL(arvore->raiz, valor);
        balanceamento(arvore, no);
        
        return no;
    }
}

void remover(ArvoreAVL* arvore, NoAVL* no) {
    if (no->esquerda != NULL) {
        remover(arvore, no->esquerda); 
    }
  
    if (no->direita != NULL) {
        remover(arvore, no->direita);
    }
  
    if (no->pai == NULL) {
        arvore->raiz = NULL;
    } else {
        if (no->pai->esquerda == no) {
            no->pai->esquerda = NULL;
        } else {
            no->pai->direita = NULL;
        }
    }

    free(no);
}

NoAVL* localizarAVL(NoAVL* no, int valor) {
    if (no->valor == valor) {
        return no;
    } else {
        if (valor < no->valor) {
            if (no->esquerda != NULL) {
                return localizarAVL(no->esquerda, valor);
            }
        } else {
            if (no->direita != NULL) {
                return localizarAVL(no->direita, valor);
            }
        }
    }

    return NULL;
}

void AVLpercorrerProfundidadeInOrder(NoAVL* no, void (*callback)(int)) {
    if (no != NULL) {
        AVLpercorrerProfundidadeInOrder(no->esquerda,callback);
        callback(no->valor);
        AVLpercorrerProfundidadeInOrder(no->direita,callback);
    }
}

void AVLpercorrerProfundidadePreOrder(NoAVL* no, void (*callback)(int)) {
    if (no != NULL) {
        callback(no->valor);
        AVLpercorrerProfundidadePreOrder(no->esquerda,callback);
        AVLpercorrerProfundidadePreOrder(no->direita,callback);
    }
}

void AVLpercorrerProfundidadePosOrder(NoAVL* no, void (callback)(int)) {
    if (no != NULL) {
        AVLpercorrerProfundidadePosOrder(no->esquerda,callback);
        AVLpercorrerProfundidadePosOrder(no->direita,callback);
        callback(no->valor);
    }
}

void visitarAVL(int valor){
    printf("%d ", valor);
}

void balanceamento(ArvoreAVL* arvore, NoAVL* no) {
    while (no != NULL) {
        int fator = fb(no);

        if (fator > 1) { //árvore mais pesada para esquerda
            //rotação para a direita
            if (fb(no->esquerda) > 0) {
                printf("RSD(%d)\n",no->valor);
                rsd(arvore, no); //rotação simples a direita, pois o FB do filho tem sinal igual
            } else {
                printf("RDD(%d)\n",no->valor);
                rdd(arvore, no); //rotação dupla a direita, pois o FB do filho tem sinal diferente
            }
        } else if (fator < -1) { //árvore mais pesada para a direita
            //rotação para a esquerda
            if (fb(no->direita) < 0) {
                printf("RSE(%d)\n",no->valor);
                rse(arvore, no); //rotação simples a esquerda, pois o FB do filho tem sinal igual
            } else {
                printf("RDE(%d)\n",no->valor);
                rde(arvore, no); //rotação dupla a esquerda, pois o FB do filho tem sinal diferente
            }
        }

        no = no->pai; 
    }
}

int altura(NoAVL* no){
    int esquerda = 0,direita = 0;

    if (no->esquerda != NULL) {
        esquerda = altura(no->esquerda) + 1;
    }

    if (no->direita != NULL) {
        direita = altura(no->direita) + 1;
    }
  
    return esquerda > direita ? esquerda : direita; //max(esquerda,direita)
}

int fb(NoAVL* no) {
    int esquerda = 0,direita = 0;
  
    if (no->esquerda != NULL) {
        esquerda = altura(no->esquerda) + 1;
    }

    if (no->direita != NULL) {
        direita = altura(no->direita) + 1;
    }
  
    return esquerda - direita;
}

NoAVL* rse(ArvoreAVL* arvore, NoAVL* no) {
    NoAVL* pai = no->pai;
    NoAVL* direita = no->direita;
  
    no->direita = direita->esquerda;
    no->pai = direita;

    direita->esquerda = no;
    direita->pai = pai;

    if (pai == NULL) {
        arvore->raiz = direita;
    } else {
        if (pai->esquerda == no) {
            pai->esquerda = direita;
        } else {
            pai->direita = direita;
        }
    }

    return direita;
}

NoAVL* rsd(ArvoreAVL* arvore, NoAVL* no) {
    NoAVL* pai = no->pai;
    NoAVL* esquerda = no->esquerda;
  
    no->esquerda = esquerda->direita;
    no->pai = esquerda;
  
    esquerda->direita = no;
    esquerda->pai = pai;

    if (pai == NULL) {
        arvore->raiz = esquerda;
    } else {
        if (pai->esquerda == no) {
            pai->esquerda = esquerda;
        } else {
            pai->direita = esquerda;
        }
    }

    return esquerda;
}

NoAVL* rde(ArvoreAVL* arvore, NoAVL* no) {
    no->direita = rsd(arvore, no->direita);
    return rse(arvore, no);
}

NoAVL* rdd(ArvoreAVL* arvore, NoAVL* no) {
    no->esquerda = rse(arvore, no->esquerda);
    return rsd(arvore, no);
}