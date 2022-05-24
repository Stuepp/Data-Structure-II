#include <stdio.h>

int pesquisaSequencialSentinela(int chave, int v[], int n){
    int i = 0;
    v[n] = chave; // A última posição do vetor possui o sentinela
    while(v[i] != chave){
        i++;
    }
    if(i < n) return i;
    return -1; // Índice invalido
}

int main()
{
    int v[] = {10,20,30,40,50,60,70,80};
    printf("\nPesquisa Sequencial com Sentinela: índice de 70: %d", pesquisaSequencialSentinela(70, v, 8));
    printf("\nPesquisa Sequencial com Sentinela: índice de 90: %d", pesquisaSequencialSentinela(90, v, 8));

    return 0;
}
