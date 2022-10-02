#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
#include <Windows.h>
#include <time.h>

/*
3) Durante uma crise hídrica em uma cidade fictícia, as pessoas começaram 
a construir reservatórios para armazenar água em suas propriedades. 
Faça um programa em linguagem C que auxilie os utilizadores do reservatório 
a controlarem seu consumo. Obtenha do teclado as dimensões de um
reservatório (altura, largura e comprimento, em centímetros) e o consumo 
médio diário dos utilizadores do reservatório (em litros/dia). 
Assuma que o reservatório esteja cheio, tenha formato cúbico e informe: 

(a) A capacidade total do reservatório, em litros; 

(b) A autonomia do reservatório, em dias; 

(c) A classificação do consumo, de acordo com a quantidade de dias de 
autonomia: 
Consumo elevado, se a autonomia for menor que 2 dias; 
Consumo moderado, se a autonomia estiver entre 2 e 7 dias; 
Consumo reduzido, se a autonomia maior que 7 dias. 

Obs.: Considere que cada litro equivale a 1000 cm3 ou 1 dm3.
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

    float larg, comp, alt, consumo, volume, autonomia;

    printf("Largura (cm): ");
    scanf("%f", &larg);
    printf("Comprimento (cm): ");
    scanf("%f", &comp);
    printf("Altura (cm): ");
    scanf("%f", &alt);
    printf("------------------------------------\n");
    printf("Consumo (litros/dia): ");
    scanf("%f", &consumo);

    printf("\n====================================\n\n");

    volume = (larg * comp * alt) / 1000;
    autonomia = volume / consumo;

    printf("Volume (litros): ");
    printf(cor_ciano "%.2f" cor_branca, volume);
    printf("\n------------------------------------\n");

    printf("Dias restantes com agua: ");
    printf(cor_verde "%.2f" cor_branca, autonomia);
    printf("\n------------------------------------\n");

    if (autonomia > 7){
        printf(cor_verde "Consumo reduzido" cor_branca);
    } else if ((autonomia >= 2) && (autonomia < 7)){
        printf(cor_amarela "Consumo moderado" cor_branca);
    } else if (autonomia < 2){
        printf(cor_vermelha "Consumo elevado" cor_branca);
    }

    printf("\n\n====================================\n\n");
    Sleep(2000);
    
    return 0;
}
