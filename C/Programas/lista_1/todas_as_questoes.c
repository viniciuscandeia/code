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

void trocaValores(int *a, int *b){
    int aux;
    aux = *a;
    *a = *b;
    *b = aux;
}

void preenchedorDeArray(int array[], int valor){
    for(int i = 0; i < 10; i++){
        *(array + i) = valor;
    }
}

void frac(float num, int *inteiro, float *frac){
    *inteiro = num;
    *frac = num - *inteiro;
}

int main() { 

    system("cls");

    printf(cor_azul "================================================================\n\n");

    int magic = 111;
    int *ptrToMagic;

    printf("Magic: %p\n", &magic);
    printf("ptrToMagic: %p\n", ptrToMagic);

    printf("\n================================================================\n\n");

    ptrToMagic = &magic;

    printf("Magic: %p\n", &magic);
    printf("ptrToMagic: %p\n", ptrToMagic);

    printf("\n================================================================\n\n");

    printf("Valor: %d\n", magic);
    printf("Valor (ponteiro): %d\n", (*ptrToMagic));

    printf("\n================================================================\n\n");

    *ptrToMagic = 99999;

    printf("Valor: %d\n", magic);
    printf("Valor (ponteiro): %d\n", (*ptrToMagic));

    printf("\n================================================================\n" cor_branca);

    printf(cor_verde "\n================================================================\n\n");

    printf("PRIMEIRA QUESTAO\n\n");

    int inteiro = 10;
    float real = 9.9;
    char palavra = 'A';

    int *ptrInteiro = &inteiro;
    float *ptrReal = &real;
    char *ptrPalavra = &palavra;

    printf("Inteiro: %d\n", inteiro);
    printf("Inteiro (ponteiro): %d\n\n", (*ptrInteiro));

    printf("Real: %f\n", real);
    printf("Real (ponteiro): %f\n\n", (*ptrReal));

    printf("Palavra: %c\n", palavra);
    printf("Palavra (ponteiro): %c\n", (*ptrPalavra));

    printf("\n================================================================\n\n");

    *ptrInteiro = 1;
    *ptrReal = 1.0;
    *ptrPalavra = 'L';

    printf("Inteiro: %d\n", inteiro);
    printf("Inteiro (ponteiro): %d\n\n", (*ptrInteiro));

    printf("Real: %f\n", real);
    printf("Real (ponteiro): %f\n\n", (*ptrReal));

    printf("Palavra: %c\n", palavra);
    printf("Palavra (ponteiro): %c\n", (*ptrPalavra));

    printf("\n================================================================\n" cor_branca);

    printf(cor_amarela "\n================================================================\n\n");

    printf("SEGUNDA QUESTAO\n\n");

    float array[10];

    for(int i = 0; i < 10; i++){
        printf("array[%d]: %p\n", i, &array[i]);
    }

    printf("\n================================================================\n" cor_branca);

    printf(cor_vermelha "\n================================================================\n\n");

    printf("TERCEIRA QUESTAO\n\n");

    int valor_a = 9;
    int valor_b = 1;

    printf("Valor A: %d\n", valor_a);
    printf("Valor B: %d\n", valor_b);

    printf("\n================================================================\n\n");

    trocaValores(&valor_a, &valor_b);

    printf("Valor A: %d\n", valor_a);
    printf("Valor B: %d\n", valor_b);

    printf("\n================================================================\n" cor_branca);

    printf(cor_magenta "\n================================================================\n\n");

    printf("QUARTA QUESTAO\n\n");

    int array_teste[10];

    preenchedorDeArray(array_teste, 20);

    for(int i = 0; i < 10; i++){
        printf("preenchedorDeArray[%d] = %d\n", i, *(array_teste + i));
    }

    printf("\n================================================================\n" cor_branca);

    printf(cor_ciano "\n================================================================\n\n");

    printf("QUINTA QUESTAO\n\n");

    float fracionario = 9.34;
    int ptrInteiro_5;
    float ptrReal_5;

    frac(fracionario, &ptrInteiro_5, &ptrReal_5);

    printf("Fracionario: %f\n", fracionario);
    printf("Parcela inteira: %d\n", (ptrInteiro_5));
    printf("Parcela fracionaria: %f\n", (ptrReal_5));

    printf("\n================================================================\n" cor_branca);

    return 0;
}

