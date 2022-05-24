#include <stdio.h>

int pesquisaInterpolacao(int chave, int v[], int n){
    int ini = 0, meio, fim = n-1;
    while(ini <= fim){
        meio = ((fim - ini) * (chave - v[ini])) / (v[fim] - v[ini]);
        if(chave < v[meio]){
            fim = meio - 1;
        } else if(chave > v[meio]){
            ini = meio + 1;
        } else {
            return meio;
        }
    }
    return -1; // Índice impossível
}

int pesquisaSequencial(int chave, int v[], int n){
    for(int i = 0; i < n-1; i++){
        if(v[i] == chave){
            return i;
        }
    }
    return -1;
}

int pesquisaSequencialSentinela(int chave, int v[], int n){
    int i = 0;
    v[n] = chave; // A última posição do vetor possui o sentinela
    while(v[i] != chave){
        i++;
    }
    if(i < n) return i;
    return -1; // Índice invalido
}

int pesquisaBinaria(int chave, int v[], int n){
    int inicio = 0, meio, fim = n - 1;
    while(inicio <= fim){
        meio = (inicio + fim) / 2;
        if(chave < v[meio]){
            fim = meio - 1;
        } else if(chave > v[meio]){
            inicio = meio + 1;
        } else{
            return meio;
        }
    }
    return -1; // Índice impossível
}

int main()
{
    int v[] = {10,20,30,40,50,60,70,80};
    printf("\nPesquisa por Interpolação: índice de 70: %d", pesquisaInterpolacao(70, v, 8));
    printf("\nPesquisa por Interpolação: índice de 90: %d", pesquisaInterpolacao(90, v, 8));
    printf("\nPesquisa Sequencial: índice de 70: %d", pesquisaSequencial(70, v, 8));
    printf("\nPesquisa Sequencial: índice de 90: %d", pesquisaSequencial(90, v, 8));
    printf("\nPesquisa Sequencial com Sentinela: índice de 70: %d", pesquisaSequencialSentinela(70, v, 8));
    printf("\nPesquisa Sequencial com Sentinela: índice de 90: %d", pesquisaSequencialSentinela(90, v, 8));
    printf("\nPesquisa Binária: índice de 70: %d", pesquisaBinaria(70, v, 8));
    printf("\nPesquisa Binária: índice de 90: %d", pesquisaBinaria(90, v, 8));

    return 0;
}
