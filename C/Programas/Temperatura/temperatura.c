#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
#include <Windows.h>
#include <time.h>

/*
    2) Escreva um programa em C que leia um valor real que represente uma 
    temperatura em Farenheit. Converta o valor para Celsius e exiba as 
    seguintes mensagens de acordo com a temperatura convertida:

    - Temperatura abaixo de zero - Exibir "Clima congelante"
    - Temperatura entre 0 e 10 - Exibir "Clima muito frio"
    - Temperatura entre 10 e 19 - Exibir "Clima frio"
    - Temperatura entre 20 e 28 - Exibir "Clima normal"
    - Tempratura entre 29 e 40 - Exibir "Clima quente"
    - Temperatura maior que 41 - Exibir "Clima muito quente"
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

    clock_t inicio = clock();

    cabecario();

    float temp_F, temp_C;

    printf("Digite a temperatura em Farenheit: ");
    scanf("%f", &temp_F);

    printf("\n====================================\n\n");

    temp_C = (temp_F - 32) / 1.8;

    printf(cor_ciano "Temperatura atual em Celsius: %.1f" cor_branca, temp_C);

    printf("\n\n------------------------------------\n\n");

    if (temp_C < 0){
        printf(cor_ciano "Clima congelante" cor_branca);
    } else if ((temp_C >= 0) && (temp_C < 10)){
        printf(cor_ciano "Clima muito frio" cor_branca);
    } else if ((temp_C >= 10) && (temp_C < 20)){
        printf(cor_ciano "Clima frio" cor_branca);
    } else if ((temp_C >= 20) && (temp_C < 30)){
        printf(cor_amarela "Clima normal" cor_branca);
    } else if ((temp_C >= 30) && (temp_C < 40)){
        printf(cor_vermelha "Clima quente" cor_branca);
    } else if (temp_C >= 40){
        printf(cor_vermelha "Clima muito quente" cor_branca);
    }

    printf("\n\n====================================\n\n");

    clock_t fim = clock();
    double duracao = (double)(fim - inicio) / CLOCKS_PER_SEC;
    printf("Tempo total gasto: ");
    printf(cor_amarela "%lfs" cor_branca, duracao);

    printf("\n\n====================================\n\n");

    Sleep(2000);
    
    return 0;
}
