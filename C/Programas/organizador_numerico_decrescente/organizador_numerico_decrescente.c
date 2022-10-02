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

    int lista[14] = {7, 4, 5, 2, 1, 3, 0, 8, 6, 9, 11, 14, 23, -1};
    int aux1;
    int aux2;
    int menor = 0;
    int lista_ordenada[5];
    int falhas = 0;

    int repeticao = 0;

    for(int i = 0; i < 14; i++){
        printf("%d ", lista[i]);
    }

    printf("\n\n");

    while (true){

        for(int i = 0; i < 14; i++){
            if (i - 1 < 14){
                if (lista[i] < lista[i + 1]){

                    aux1 = lista[i];
                    aux2 = lista[i + 1];

                    lista[i] = aux2;
                    lista[i + 1] = aux1;

                    break;

                } else {
                    falhas += 1;
                }
            }
        }

        if (falhas == 13){
            break;
        }

        for(int i = 0; i < 14; i++){
            printf("%d ", lista[i]);
        }

        printf("\n");

        repeticao += 1;

        if (repeticao == 500){
            break;
        }

        falhas = 0;
    }

    return 0;
}

