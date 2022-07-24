#include <stdio.h>
#include <time.h>

int main(){
    FILE *f;
    //ptr = fopen("\\Final-homework\\chaves-aleatorias.txt", "w");
    srand(time(NULL));
    int r;

    for(int i = 0; i < 10; i++){
        r = rand();
        printf("\n%i",r);
        //fwrite(r,, sizeof(int), f);
    }
    
    return 0;
}