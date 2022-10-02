#include <stdio.h>
#include <math.h>
#include <string.h>

int main(void){

    int quant;
    char frase[1000];
    char frase_mudada[1000];
    char frase_mudada_copia[1000];
    int truncado;
    int c;

    scanf("%d", &quant);
    while ( (c = getchar()) != '\n' && c != EOF ) { }

    frase[0] = '\0';
    frase_mudada[0] = '\0';

    for(int i = 0; i < quant; i++){
        fgets(frase, 1000, stdin);

        frase[strcspn(frase, "\n")] = 0;
        frase[strlen(frase)] = '\0';

        strcpy(frase_mudada, frase);
        
        for(int j = 0; j < strlen(frase); j++){
            if (frase[j] > 64 && frase[j] < 91 || frase[j] > 96 && frase[j] < 123){
                frase_mudada[j] = frase[j] + 3;
            } else{
                frase_mudada[j] = frase[j];
            }
        }

        frase_mudada[strlen(frase_mudada)] = '\0';

        strcpy(frase_mudada_copia, frase_mudada);

        for(int j = 0; j < strlen(frase_mudada); j++){
            frase_mudada[j] = frase_mudada_copia[strlen(frase_mudada_copia) - j - 1];
        }

        frase_mudada_copia[0] = '\0';

        strcpy(frase_mudada_copia, frase_mudada);

        truncado = trunc(strlen(frase_mudada) / 2);

        for(int j = truncado; j < strlen(frase_mudada); j++){
            frase_mudada[j] = frase_mudada_copia[j] - 1;
        }

        printf("%s\n", frase_mudada);

    }

    return 0;
}
