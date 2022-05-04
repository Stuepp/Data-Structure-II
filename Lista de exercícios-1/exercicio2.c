#include <stdio.h>
#include <stdlib.h>
#include <time.h>
/*
 *Dado um vetor de números inteiros v, retorne um novo vetor de forma que cada
 * elemento no índice i seja o produto de todos os números na matriz original, com
 * exceção de i.
 * ○ Exemplo 1: dado v = [1,2,3,4,5], a saída esperada é [120,60,40,30,24]
 * ○ Exemplo 2: dado v = [3,2,1], a saída esperada é [2,3,6]
 * ok
 */
int main(){
    srand(time(NULL));
    int *v, *w, n = rand() % 11, mult=1;
    v = (int*) malloc(n * sizeof(int));
    w = (int*) malloc(n * sizeof(int));

    for(int i = 0; i < n; i++){
        v[i] = rand() % 6;
        printf("%d ", v[i]);
    }
    printf("\n");
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(j != i)
                mult *= v[j];
        }
        w[i] = mult;
        mult = 1;
        printf("%d ", w[i]);
    }
    return 0;
}