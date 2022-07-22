#include <stdlib.h>
#include <stdio.h>

typedef struct no {
    struct no* pai;
    struct no* esquerda;
    struct no* direita;
    int valor;
} No;

typedef struct arvore {
    struct no* raiz;
} Arvore;

void balanceamento(Arvore*, No*);
int altura(No*);
int fb(No*);
No* rsd(Arvore*, No*);
No* rse(Arvore*, No*);
No* rdd(Arvore*, No*);
No* rde(Arvore*, No*);


// váriavel para contagem das operações de balanceamento
int contador = 0;


Arvore* criar() {
    Arvore *arvore = malloc(sizeof(Arvore));
    arvore->raiz = NULL;

    return arvore;
}

int vazia(Arvore* arvore) {
    return arvore->raiz == NULL;
}

No* adicionarNo(No* no, int valor) {

    contador++;

    if (valor > no->valor) {
        if (no->direita == NULL) {
            //printf("Adicionando %d dir %d\n",valor, no->valor);
            No* novo = malloc(sizeof(No));
            novo->valor = valor;
            novo->pai = no;
            novo->direita = NULL;
            novo->esquerda = NULL;

            no->direita = novo;

            return novo;
        } else {
            return adicionarNo(no->direita, valor);
        }
    } else {
        if (no->esquerda == NULL) {
            //printf("Adicionando %d esq %d\n",valor, no->valor);
            No* novo = malloc(sizeof(No));
			novo->valor = valor;
            novo->pai = no;
            novo->direita = NULL;
            novo->esquerda = NULL;

            no->esquerda = novo;

            return novo;
        } else {
            return adicionarNo(no->esquerda, valor);
        }
    }
}

No* adicionar(Arvore* arvore, int valor) {
    if (arvore->raiz == NULL) {
        //printf("Adicionando %d\n",valor);
        No* novo = malloc(sizeof(No));
        novo->valor = valor;
        novo->pai = NULL;
        novo->direita = NULL;
        novo->esquerda = NULL;

        arvore->raiz = novo;


        contador++;

        return novo;
    } else {
        No* no = adicionarNo(arvore->raiz, valor);
        balanceamento(arvore, no);

        return no;
    }
}

void balanceamento(Arvore* arvore, No* no) {
    while (no != NULL) {
        int fator = fb(no);

        if (fator > 1) { //árvore mais pesada para esquerda
            //rotação para a direita
            if (fb(no->esquerda) > 0) {
                //printf("RSD(%d)\n",no->valor);
                rsd(arvore, no); //rotação simples a direita, pois o FB do filho tem sinal igual
            } else {
                //printf("RDD(%d)\n",no->valor);
                rdd(arvore, no); //rotação dupla a direita, pois o FB do filho tem sinal diferente
            }
        } else if (fator < -1) { //árvore mais pesada para a direita
            //rotação para a esquerda
            if (fb(no->direita) < 0) {
                //printf("RSE(%d)\n",no->valor);
                rse(arvore, no); //rotação simples a esquerda, pois o FB do filho tem sinal igual
            } else {
                //printf("RDE(%d)\n",no->valor);
                rde(arvore, no); //rotação dupla a esquerda, pois o FB do filho tem sinal diferente
            }
        }

        no = no->pai;
    }
}

int altura(No* no){


    contador++;

    int esquerda = 0,direita = 0;

    if (no->esquerda != NULL) {
        esquerda = altura(no->esquerda) + 1;
    }

    if (no->direita != NULL) {
        direita = altura(no->direita) + 1;
    }

    return esquerda > direita ? esquerda : direita; //max(esquerda,direita)
}

int fb(No* no) {

    contador++;

    int esquerda = 0,direita = 0;

    if (no->esquerda != NULL) {
        esquerda = altura(no->esquerda) + 1;
    }

    if (no->direita != NULL) {
        direita = altura(no->direita) + 1;
    }

    return esquerda - direita;
}

No* rse(Arvore* arvore, No* no) {


    contador++;

    No* pai = no->pai;
    No* direita = no->direita;

    no->direita = direita->esquerda;
    no->pai = direita;

    direita->esquerda = no;
    direita->pai = pai;

    if (no->direita != NULL)
        no->direita->pai = no;

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

No* rsd(Arvore* arvore, No* no) {

    contador++;

    No* pai = no->pai;
    No* esquerda = no->esquerda;

    no->esquerda = esquerda->direita;
    no->pai = esquerda;

    esquerda->direita = no;
    esquerda->pai = pai;

    if (no->esquerda != NULL)
        no->esquerda->pai = no;

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

No* rde(Arvore* arvore, No* no) {

    no->direita = rsd(arvore, no->direita);
    return rse(arvore, no);
}

No* rdd(Arvore* arvore, No* no) {

    no->esquerda = rse(arvore, no->esquerda);
    return rsd(arvore, no);
}




int main() {


    FILE *arq;
    int **entrada;
    int tam[10] = {1,101,201,301,401,501,601,701,801,901};

    entrada = malloc(sizeof(int*)*10);

    for(int i=0;i < 10;i++){
        entrada[i] = malloc(sizeof(int)*tam[i]);
    }

    if ((arq = fopen("limpo_n.txt", "r")) == NULL){  //limpo_n (n ordenada) limpo_o (Ordenado)
        printf( "ARQUIVO NAO PODE SER ABERTO \n");
        system("pause");
    }   
    else{
        for(int k=0; k<10;k++){
            int i=0;
            int tamanho = tam[k];
            while(tamanho !=0){
                fscanf(arq, "%d", &entrada[k][i]);
                tamanho--;
                i++; 
                
            }

        }
    }
    printf("%i",entrada[0][0]);
    int fclose(FILE *arq); // ja temos tudo carregado


    FILE *pont_arq; 
    pont_arq = fopen("resultados_a.txt", "a+");
    
    for(int j=0;j<10;j++){
        Arvore* a = criar();
        contador =0;
        for(int k=0;k<tam[j];k++){
            adicionar(a, entrada[j][k]);//
        }
        
        //salvando 
        fprintf(pont_arq, "%d\n", contador);
        printf("\nNúmero de operações: %d\n", contador);

    }
    
    fclose(pont_arq);


 
}
