#include <stdio.h>

int main(){ // desempenho -> N
    int v[] = {10,15,3,7};
    int k = 17;
    int n = 4;
    
    Dict* dict = cria();
    //int valor = get(dict,chave);
    //put(dict,chave,valor);

    for(int i = 0; i < n-1; i++){ // N
        put(dict,v[i],i);
    }
    
    for(int i = 0; i < n-1; i++){ // N -> sequencial
    int vj = k - v[i];

    int j = get(dict,vj); //  1 -> acesso direto

    if(j < n && v[j] == vj){

    }
    if(v[i] + v[j] == k){ // 1
        printf("%d %d\n", v[i], v[j]);
        printf("true\n");
        return 0;
    }
    }
    printf("false\n");
    return 0;
}
/*
 * Dado um vetor de números inteiros v de tamanho n e um número k, retorne verdadeiro
 * se a soma de qualquer par de números em v for igual a k.
 * Exemplo: dado v = [10,15,3,7] e k = 17, a saída deve ser true, pois 10 + 7 é 17
*/