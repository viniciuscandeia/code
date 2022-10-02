#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <Windows.h>

#define cor_preta     "\033[30m"
#define cor_vermelha  "\033[31m"
#define cor_verde     "\033[32m"
#define cor_amarela   "\033[33m"
#define cor_azul      "\033[34m"
#define cor_magenta   "\033[35m"
#define cor_ciano     "\033[36m"
#define cor_branca    "\033[37m"
 
#include <stdio.h>

int main() { 

    system("cls");

    int lista[11] = {8, 260, 8, 260, 260, 10, 10};
    int aux1;
    int aux2;
    int menor = 0;
    int lista_ordenada[5];
    int falhas = 0;

    int repeticao = 0;

    printf("Original: ");
    for(int i = 0; i < 7; i++){
        printf("%d ", lista[i]);
    }
    printf("\n");

    printf("\n===================================================\n\n");

    while (true){

        for(int i = 0; i < 7; i++){
            if (i - 1 < 7){
                if (lista[i] > lista[i + 1]){
                    aux1 = lista[i];
                    aux2 = lista[i + 1];
                    printf("\naux1 = %d\n", aux1);
                    printf("aux2 = %d\n\n", aux2);
    
                    if (i < 7 - 1){
                        lista[i] = aux2;
                        lista[i + 1] = aux1;
                    } 

                    printf("lista[i] = %d\n", lista[i]);
                    printf("lista[i + 1] = %d\n", lista[i + 1]);

                    printf("\n===================================================\n\n");
                    break;
                } else {
                    falhas += 1;
                    printf("%d falhou\n", falhas);
                }
            }
        }

        if (falhas == 6){
            break;
        }

        for(int i = 0; i < 7; i++){
            printf("%d ", lista[i]);
        }
        printf("\n");

        repeticao += 1;

        if (repeticao == 30){
            break;
        }

        falhas = 0;

    }

    for(int i = 0; i < 7; i++){
            printf("%d ", lista[i]);
    }
    printf("\n");

    return 0;
}

