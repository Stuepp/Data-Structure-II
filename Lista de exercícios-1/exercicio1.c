#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(){
    srand(time(NULL));
    int *v, n = 7, k= rand() % 101, soma = 0; // n é o tamanho do vetor
    v = (int*)malloc(n * sizeof(n));
    printf("k = %d\n", k);
    // verificar se a soma dos pares de v é igual a k
    for(int i = 0; i <= sizeof(v); i++){
        v[i] = rand() % 20;
        printf("%d ", v[i]);
        if(v[i]%2 == 0)
            soma+= v[i];
    }
    printf("\nsoma: %d\n", soma);
    if(soma == k)
        printf("true\n");
    return 0;
}