#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(){
    srand(time(NULL));
    int *v, n = rand() % 11, saida;
    v = (int*) malloc(n * sizeof(int));

    for(int i = 0; i < n; i++){
        v[i] = rand() % 11;
        printf("%d ", v[i]);
    }
    int menor = v[0];
    for(int i = 0; i < n; i++){
        if(menor > v[i] && v[i] > 0)
            menor = v[i];
    }
    printf("\nmenor = %d", menor);
    printf("\n");
    for(int i = 0; i < n; i++){
        if(v[i] > 0 && (menor-1) > 0){
            if((menor - 1) == v[i]){
                int j = 0;
                while(((menor-j) > 0) && ((menor-j) == v[j])){
                    j++;
                }
                if((menor-j) > 0){
                    saida = menor-j;
                    break;
                }
            }else if((menor+1) == v[i]){
                int j = 0;
                while((menor+j) == v[j]){
                    j++;
                }
                saida = menor+j;
            }else{
                saida = menor - 1;
                break;
            }
        }
    }
    printf("saída: %d", saida);

    return 0;
}