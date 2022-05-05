/*
 * Considere uma escadaria com n degraus e você pode subir 1 ou 2 degraus por vez.
 * Dado n, retorne o número de maneiras únicas de subir a escada.
 * ○ Exemplo, dado n = 4, existem 5 maneiras exclusivas
 * ■ [1,1,1,1], [2,1,1], [1,2,1], [1,1,2], [2, 2]
 * 
 * 
 * códdigo incompleto / não funcionando atualizar com o moodle
*/
#include <stdio.h>

int degrau(int n){
    if(n <= 1)
        return n;

    int retorno = 0;
    for(int i = 1; i <= 2 && i <= n; i++){
        retorno += degrau(n - i);
    }
    return retorno;
}

int main(){
    int n = 4;
    
    printf("%d\n", degrau(n));

    return 0;
}