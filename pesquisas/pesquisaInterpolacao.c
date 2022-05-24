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

int main()
{
    int v[] = {10,20,30,40,50,60,70,80};
    printf("\níndice de 70: %d", pesquisaInterpolacao(70, v, 8));

    return 0;
}
