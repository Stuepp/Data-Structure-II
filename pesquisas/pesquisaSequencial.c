#include <stdio.h>

int pesquisaSequencial(int chave, int v[], int n){
    for(int i = 0; i < n-1; i++){
        if(v[i] == chave){
            return i;
        }
    }
    return -1;
}

int main()
{
    int v[] = {10,20,30,40,50,60,70,80};
    printf("\nPesquisa Sequencial: índice de 70: %d", pesquisaSequencial(70, v, 8));
    printf("\nPesquisa Sequencial: índice de 90: %d", pesquisaSequencial(90, v, 8));

    return 0;
}
