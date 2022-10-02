#include <stdio.h>

int main(void){

    int vetor[20];
    int vetor_copia[20];

    scanf("%d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d", 
          &vetor[0], &vetor[1], &vetor[2], &vetor[3], &vetor[4],
          &vetor[5], &vetor[6], &vetor[7], &vetor[8], &vetor[9],
          &vetor[10], &vetor[11], &vetor[12], &vetor[13], &vetor[14],
          &vetor[15], &vetor[16], &vetor[17], &vetor[18], &vetor[19]);
    
    for(int i = 0; i <= 19; i++){
        vetor_copia[i] = vetor[19 - i];
    }

    for(int i = 0; i <= 19; i++){
        vetor[i] = vetor_copia[i];
    }
    
    for(int i = 0; i <= 19; i++){
        printf("N[%d] = %d\n", i, vetor[i]);
    }

    return 0;
}
