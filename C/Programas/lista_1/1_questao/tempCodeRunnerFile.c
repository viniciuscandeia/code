#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
#include <Windows.h>
#include <time.h>

/*
    1) Escreva um programa em C que receba um valor n (int) de entrada e, em seguida:
    - Aloque espaço dinamicamente memoria para criar um vetor de caracteres 
    (char) de n elementos e verifique se o espaço foi alocado com sucesso;
    - preencha o vetor criado com n caracteres digitados pelo usuario; 
    - exiba o vetor preenchido na tela
    - libere o espaço de memoria alocado
*/

int nome2(void){

    system("cls");

    time_t t = time(NULL);
    struct tm tm = *localtime(&t);

    #define cor_preta     "\033[30m"
    #define cor_vermelha  "\033[31m"
    #define cor_verde     "\033[32m"
    #define cor_amarela   "\033[33m"
    #define cor_azul      "\033[34m"
    #define cor_magenta   "\033[35m"
    #define cor_ciano     "\033[36m"
    #define cor_branca    "\033[37m"

    printf(cor_branca "================================================================\n\n");
    printf(cor_verde "    ,o888888o.  `8.`888b           ,8' b.             8  8 8888 \n");
    printf(cor_verde " . 8888     `88. `8.`888b         ,8'  888o.          8  8 8888 \n");
    printf(cor_verde ",8 8888       `8b `8.`888b       ,8'   Y88888o.       8  8 8888 \n");
    printf(cor_verde "88 8888        `8b `8.`888b     ,8'    .`Y888888o.    8  8 8888 \n");
    printf(cor_verde "88 8888         88  `8.`888b   ,8'     8o. `Y888888o. 8  8 8888 \n");
    printf(cor_verde "88 8888         88   `8.`888b ,8'      8`Y8o. `Y88888o8  8 8888 \n");
    printf(cor_verde "88 8888        ,8P    `8.`888b8'       8   `Y8o. `Y8888  8 8888 \n");
    printf(cor_verde "`8 8888       ,8P      `8.`888'        8      `Y8o. `Y8  8 8888 \n");
    printf(cor_verde " ` 8888     ,88'        `8.`8'         8         `Y8o.`  8 8888 \n");
    printf(cor_verde "    `8888888P'           `8.`          8            `Yo  8 8888 \n\n" cor_branca);
    printf(cor_branca "================================================================\n");
    printf("Dev: ");
    printf(cor_verde " Vinicius Candeia\n" cor_branca);
    printf("Hora: ");
    if (tm.tm_min < 10){
        printf(cor_verde "%2d:0%d\n" cor_branca, tm.tm_hour, tm.tm_min);    
    } else {
        printf(cor_verde "%2d:%2d\n" cor_branca, tm.tm_hour, tm.tm_min);    
    }
    printf("Data: ");
    printf(cor_verde "%d/%d/%d\n" cor_branca, tm.tm_mday, tm.tm_mon + 1, tm.tm_year + 1900);
    printf(cor_branca "================================================================\n\n");
    Sleep(1000);

}

int main(void){

    nome2();

    int n;
    char *conjunto;

    printf("Tamanho: ");
    scanf("%d", &n);

    printf(cor_branca "\n================================================================\n\n");

    conjunto = (char *) malloc((n + 1) * sizeof(char));

    for(int i = 0; i < n; i++){
        printf("Endereco: %p\n", (conjunto + i));
    }

    printf(cor_branca "\n================================================================\n\n");

    printf("Palavra: ");
    scanf("%s", conjunto);

    printf(cor_branca "\n================================================================\n\n");

    printf("Palavra: %s", conjunto);

    printf(cor_branca "\n================================================================\n\n");

    free(conjunto);

    return 0;
}


