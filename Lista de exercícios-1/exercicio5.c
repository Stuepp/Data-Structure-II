#include <stdio.h>
/*
 * Considere uma escadaria com n degraus e você pode subir 1 ou 2 degraus por vez.
 * Dado n, retorne o número de maneiras únicas de subir a escada.
 * ○ Exemplo, dado n = 4, existem 5 maneiras exclusivas
 * ■ [1,1,1,1], [2,1,1], [1,2,1], [1,1,2], [2, 2]
*/

int main(){
    int n=4;

    for(int i = 0; i < n; i++){
        printf("1 ");
    }
    printf("\n");
    if(n-2 > 0){
        for(int i = 0; i < n-1; i++){
            for(int j = 0; j < n; j++){
                if(j == i){
                    printf("2 ");
                    j++;
                }else{
                    printf("1 ");
                }
            }
            printf("\n");
        }
    }
    if(n%2 == 0){
        for(int i = 0; i < n/2; i++){
           printf("2 ");
        }        
    }

    return 0;
}