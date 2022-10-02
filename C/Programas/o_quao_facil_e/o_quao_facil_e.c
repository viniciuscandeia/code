#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
#include <Windows.h>
#include <time.h>

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

    int contador = 0;
    char frase[50];
    int posicao_espacos[1000];
    int contador_espacos = 0;
    int tamanho_palavras[1000];
    int contador_palavras = 0;
    int soma = 0;
    float media = 0;
    
    printf("Frase: ");
    fgets(frase, 1000, stdin);

    printf("\nFrase digitada: %s", frase);

    printf("\nTamanho frase: %d\n", strlen(frase));

    printf("\n====================================================\n\n");

    for(int i = 0; i < strlen(frase); i++){
        if (frase[i] == ' ') {
            posicao_espacos[contador_espacos] = i;
            if (contador_espacos == 0){
                tamanho_palavras[0] = i;
                contador_palavras += 1;
            } else {
                tamanho_palavras[contador_palavras] = posicao_espacos[contador_espacos] - posicao_espacos[contador_espacos - 1] - 1;
                contador_palavras += 1;
            }
            contador_espacos += 1;
        }
        if (frase[i] == '\n'){
            if (contador_espacos == 0){
                tamanho_palavras[contador_palavras] = i;
            } else {
                posicao_espacos[contador_espacos] = i;
                tamanho_palavras[contador_palavras] = posicao_espacos[contador_espacos] - posicao_espacos[contador_espacos - 1] - 1;
                contador_palavras += 1;
            }
            contador_espacos += 1;
        }
    }

    printf("\n====================================================\n\n");

    printf("Posicao dos espacos: ");
    for(int i = 0; i < contador_espacos; i++){
        printf("%d ", posicao_espacos[i]);
    }

    printf("\n");

    printf("Tamanho das palavras: ");
    for(int i = 0; i < contador_palavras; i++){
        printf("%d ", tamanho_palavras[i]);
        soma += tamanho_palavras[i];
    }

    media = soma / contador_palavras;

    printf("\n\nValor frase: ");

    if (media <= 3){
        printf("250\n");
    } else if (media > 3 && media < 6){
        printf("500\n");
    } else if (media >= 6){
        printf("1000");
    }

    printf("\nQuantidade de espacos: %d", contador_espacos);
    printf("\nQuantidade de palavras: %d\n", contador_palavras);

    printf("\n====================================================\n\n");

    return 0;
}