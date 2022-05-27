#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 10

int compara(const void * a, const void * b){
    return ( *(int*)a - *(int*)b );
}

int pesquisaInterpolacao(int chave, int v[], int n, int* comparacoes){
    *comparacoes = 0;
    int ini = 0, meio, fim = n-1;
    while(ini <= fim){
        *comparacoes += 1;
        meio = ini + ((fim - ini) * (chave - v[ini])) / (v[fim] - v[ini]);
        if(chave < v[meio]){
            fim = meio - 1;
            *comparacoes += 1;
        } else if(chave > v[meio]){
            ini = meio + 1;
            *comparacoes += 2;
        } else {
            return meio;
            *comparacoes += 2;
        }
    }
    return -1; // Índice impossível
}

int pesquisaSequencial(int chave, int v[], int n, int* comparacoes){ 
    *comparacoes = 0;
    for(int i = 0; i < n-1; i++){
        if(v[i] == chave){
            return i;
        }
        *comparacoes += 1;
    }
    return -1;
}

int pesquisaSequencialSentinela(int chave, int v[], int n, int* comparacoes){ 
    *comparacoes = 1;
    int i = 0;
    v[n] = chave; // A última posição do vetor possui o sentinela
    while(v[i] != chave){
        i++;
        *comparacoes += 1;
    }
    if(i < n) return i;
    return -1; // Índice invalido
}

int pesquisaBinaria(int chave, int v[], int n, int* comparacoes){ 
    *comparacoes = 0;
    int inicio = 0, meio, fim = n - 1;
    while(inicio <= fim){
        *comparacoes += 1;
        meio = (inicio + fim) / 2;
        if(chave < v[meio]){
            fim = meio - 1;
            *comparacoes += 1;
        } else if(chave > v[meio]){
            inicio = meio + 1;
            *comparacoes += 2;
        } else{
            return meio;
            *comparacoes += 2;
        }
    }
    return -1; // Índice impossível
}

int main()
{
    srand(time(0)); // Use current time as seed for random generator

    // vetores
    int v[SIZE][SIZE];
    for(int i = 0; i < SIZE; i++){
        for(int j = 0; j < SIZE; j++){
            v[i][j] = rand();
        }
        qsort(v, SIZE, sizeof(int), compara);
        for(int j = 0; j < SIZE; j++){
            printf("%d ", v[i][j]);
        }
        printf("\n");
    }
    printf("\n");
    // chaves
    int keys[SIZE];
    int lower = 0, upper = SIZE-1;
    for(int i = 0; i < SIZE; i++){
        int vnum = (rand() % (upper - lower + 1)) + lower;
        keys[i] = v[i][vnum];
        printf("%d\n", keys[i]);
    }
    printf("\n comparações\n");
    // comparações
    int comparacao, comparacoes[SIZE];
    int* ncomparacao = &comparacao;
    int tempV[SIZE];
    for(int i = 0; i < SIZE; i++){
        for(int j = 0; j < SIZE; j++){
            tempV[j] = v[i][j];
        }
        pesquisaInterpolacao(keys[i], tempV, SIZE, ncomparacao);
        comparacoes[i] = *ncomparacao;
        printf("%d ", comparacoes[i]);
    }

    return 0;
}
/*
    // 70 existe, 90 não existe
    pesquisaInterpolacao(70, v, 8, ncomparacoes);
    printf("\n\nNumero de comparacoes da pesquisa por interpolacao (caso de succeso): %d", *ncomparacoes);
    //printf("\nPesquisa por Interpolação: índice de 90: %d", pesquisaInterpolacao(90, v, 8)); //dando problema
    pesquisaSequencial(70, v, 8, ncomparacoes);
    printf("\n\nNumero de comparacoes da pesquisa sequencial (caso de succeso): %d", *ncomparacoes);
    pesquisaSequencial(90, v, 8, ncomparacoes);
    printf("\nNumero de comparacoes da pesquisa sequencial (caso de fracasso): %d", *ncomparacoes);

    pesquisaSequencialSentinela(70, v, 8, ncomparacoes);
    printf("\n\nNumero de comparacoes da pesquisa sequencial com sentinela (caso de suscesso): %d", *ncomparacoes);
    pesquisaSequencialSentinela(90, v, 8, ncomparacoes);
    printf("\nNumero de comparacoes da pesquisa sequencial com sentinela (caso de fracasso): %d", *ncomparacoes);

    pesquisaBinaria(70, v, 8, ncomparacoes);
    printf("\n\nNumero de comparacoes da pesquisa binaria (caso de suscesso): %d", *ncomparacoes);
    pesquisaBinaria(90, v, 8, ncomparacoes);
    printf("\nNumero de comparacoes da pesquisa binaria (caso de fracasso): %d", *ncomparacoes);
*/
