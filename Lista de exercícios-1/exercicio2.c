#include <stdio.h>
#include <stdlib.h>
#include <time.h>

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