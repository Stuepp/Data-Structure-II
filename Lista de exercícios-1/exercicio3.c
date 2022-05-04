#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/*
 * Dado um vetor de números inteiros v, encontre o primeiro inteiro positivo ausente no
 * vetor. Em outras palavras, deve ser retornado o menor inteiro positivo que não existe no
 * vetor. A matriz pode conter duplicados e números negativos também. O algoritmo deve
 * apresentar complexidade de tempo linear e de espaço constante (pode desconsiderar
 * o esforço para ordenação do vetor).
 * ○ Exemplo 1, dado v = [3,4,-1,1], a saída esperada é 2
 * ○ Exemplo 2, dado v = [1,2,0], a saída esperada é 3
 * falta descer para o menor possível exemplo  3 4 5 -> saida:  2 
*/

int main(){
    srand(time(NULL));
    int *v, n = rand() % 11, saida;
    v = (int*) malloc(n * sizeof(int));

    for(int i = 0; i < n; i++){
        v[i] = rand() % 11;
        printf("%d ", v[i]);
    }
    /*int v[] = {1,2,0};
    int n = sizeof(v);
    int saida;*/
    int menor = v[0];
    for(int i = 0; i < n; i++){
        if(menor > v[i] && v[i] > 0)
            menor = v[i];
    }
    printf("\nmenor = %d", menor);
    printf("\n");
    if((menor-1) > 0){
         printf("\nIO");
        int j = 1;
        while(((menor-j) > 0) && ((menor-j) == v[j])){
            j++;
        }
        if((menor-j) > 0){
            saida = menor-j;
        }
    }else{
        printf("\nOI");
        int j = 1;
        while((menor+j) == v[j]){
            printf("teste");
             j++;
        }
        printf("\nj:%i",j);
        saida = menor+j;
    }
    printf("\nsaída: %d", saida);

    return 0;
}
