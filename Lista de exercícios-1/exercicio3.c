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
