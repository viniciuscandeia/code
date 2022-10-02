#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
#include <Windows.h>
#include <time.h>

/*
    1) Escreva um programa em C que leia 4 valores inteiros e 
    apresente o maior e o menor valor lido.
*/

#define cor_preta     "\033[30m"
#define cor_vermelha  "\033[31m"
#define cor_verde     "\033[32m"
#define cor_amarela   "\033[33m"
#define cor_azul      "\033[34m"
#define cor_magenta   "\033[35m"
#define cor_ciano     "\033[36m"
#define cor_branca    "\033[37m"

int cabecario(void){

    system("cls");

    printf("\nDev: ");
    printf(cor_verde "Vinicius Candeia\n" cor_branca);
    printf("Matricula: ");
    printf(cor_verde "20200009783" cor_branca);
    printf("\n====================================\n\n");

    return 0;
}

int main(void){

    cabecario();

    int n1, n2, n3, n4, maior, menor;

    printf("Digite o 1 valor: ");
    scanf("%d", &n1);
    printf("Digite o 2 valor: ");
    scanf("%d", &n2);
    printf("Digite o 3 valor: ");
    scanf("%d", &n3);
    printf("Digite o 4 valor: ");
    scanf("%d", &n4);

    if ((n1 >= n2) && (n1 >= n3) && (n1 >= n4)){
        maior = n1;
    } else if ((n2 >= n1) && (n2 >= n3) && (n2 >= n4)) {
        maior = n2;
    } else if ((n3 >= n1) && (n3 >= n2) && (n3 >= n4)){
        maior = n3;
    } else if ((n4 >= n1) && (n4 >= n2) && (n4 >= n3)){
        maior = n4;
    }

    if ((n1 <= n2) && (n1 <= n3) && (n1 <= n4)){
        menor = n1;
    } else if ((n2 <= n1) && (n2 <= n3) && (n2 <= n4)) {
        menor = n2;
    } else if ((n3 <= n1) && (n3 <= n2) && (n3 <= n4)){
        menor = n3;
    } else if ((n4 <= n1) && (n4 <= n2) && (n4 <= n3)){
        menor = n4;
    }

    printf("\n====================================\n\n");
    printf("O maior valor foi: ");
    printf(cor_verde "%d" cor_branca, maior);
    printf("\nO menor valor foi: ");
    printf(cor_amarela "%d" cor_branca, menor);
    printf("\n\n====================================\n\n");

    Sleep(2000);
    
    return 0;
}
