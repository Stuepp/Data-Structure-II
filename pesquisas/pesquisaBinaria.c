#include <stdio.h>

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
    printf("\nPesquisa Binária: índice de 70: %d", pesquisaBinaria(70, v, 8));
    printf("\nPesquisa Binária: índice de 90: %d", pesquisaBinaria(90, v, 8));

    return 0;
}
