#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
#include <Windows.h>
#include <time.h>

int nome(void){
    
    #define cor_preta     "\033[30m"
    #define cor_vermelha  "\033[31m"
    #define cor_verde     "\033[32m"
    #define cor_amarela   "\033[33m"
    #define cor_azul      "\033[34m"
    #define cor_magenta   "\033[35m"
    #define cor_ciano     "\033[36m"
    #define cor_branca    "\033[37m"

    clock_t inicio = clock();

    // printf(cor_branca "----------------------------------------------------------------\n");

    int rep = 0;

    system("cls");

    if (rep == 0){ //PREPARATIVOS
        printf(cor_verde "Iniciando dispositivo");
        Sleep(250);
        printf(".");
        Sleep(250);
        printf(".");
        Sleep(250);
        printf(".");
        Sleep(250);
        system("cls");
        printf("Iniciando dispositivo ");
        printf("(PRONTO) \n");

        printf("Atualizando pacotes");
        Sleep(100);
        printf(".");
        Sleep(100);
        printf(".");
        Sleep(100);
        printf(".");
        Sleep(100);
        system("cls");
        printf("Iniciando dispositivo ");
        printf("(PRONTO) \n");
        printf("Atualizando pacotes ");
        printf("  (PRONTO) \n");

        printf("Preparando servidor");
        Sleep(250);
        printf(".");
        Sleep(250);
        printf(".");
        Sleep(250);
        printf(".");
        Sleep(250);
        system("cls");
        printf("Iniciando dispositivo ");
        printf("(PRONTO) \n");
        printf("Atualizando pacotes ");
        printf("  (PRONTO) \n");
        printf("Preparando servidor ");
        printf("  (PRONTO) \n");

        Sleep(500);

        srand((unsigned) time(NULL));
        for(int porc = 0; porc <= 100; porc++){
            system("cls");
            int valor = 0;
            valor = rand() % 15;
            porc += valor;
            printf(cor_vermelha "CARREGANDO OVNI ");
            if (porc <= 100){
                printf("(%d%%)" cor_branca, porc);
            }
            Sleep(100);
        }

        system("cls");
        rep += 1;
    }
    
    Sleep(200);

    printf(cor_branca "================================================================\n\n");
    Sleep(200);
    int ovni = 0;
    if (ovni == 0){ //OVNI
        printf(cor_branca "    ,o888888o.  `8.`888b           ,8' b.             8  8 8888 \n");
        Sleep(100);
        system("cls");
        printf(cor_branca "================================================================\n\n");
        printf(cor_verde "    ,o888888o.  `8.`888b           ,8' b.             8  8 8888 \n");
        printf(cor_branca " . 8888     `88. `8.`888b         ,8'  888o.          8  8 8888 \n");
        Sleep(100);
        system("cls");
        printf(cor_branca "================================================================\n\n");
        printf(cor_verde "    ,o888888o.  `8.`888b           ,8' b.             8  8 8888 \n");
        printf(cor_verde " . 8888     `88. `8.`888b         ,8'  888o.          8  8 8888 \n");
        printf(cor_branca ",8 8888       `8b `8.`888b       ,8'   Y88888o.       8  8 8888 \n");
        Sleep(100);
        system("cls");
        printf(cor_branca "================================================================\n\n");
        printf(cor_verde "    ,o888888o.  `8.`888b           ,8' b.             8  8 8888 \n");
        printf(cor_verde " . 8888     `88. `8.`888b         ,8'  888o.          8  8 8888 \n");
        printf(cor_verde ",8 8888       `8b `8.`888b       ,8'   Y88888o.       8  8 8888 \n");
        printf(cor_branca "88 8888        `8b `8.`888b     ,8'    .`Y888888o.    8  8 8888 \n");
        Sleep(100);
        system("cls");
        printf(cor_branca "================================================================\n\n");
        printf(cor_verde "    ,o888888o.  `8.`888b           ,8' b.             8  8 8888 \n");
        printf(cor_verde " . 8888     `88. `8.`888b         ,8'  888o.          8  8 8888 \n");
        printf(cor_verde ",8 8888       `8b `8.`888b       ,8'   Y88888o.       8  8 8888 \n");
        printf(cor_verde "88 8888        `8b `8.`888b     ,8'    .`Y888888o.    8  8 8888 \n");
        printf(cor_branca "88 8888         88  `8.`888b   ,8'     8o. `Y888888o. 8  8 8888 \n");
        Sleep(100);
        system("cls");
        printf(cor_branca "================================================================\n\n");
        printf(cor_verde "    ,o888888o.  `8.`888b           ,8' b.             8  8 8888 \n");
        printf(cor_verde " . 8888     `88. `8.`888b         ,8'  888o.          8  8 8888 \n");
        printf(cor_verde ",8 8888       `8b `8.`888b       ,8'   Y88888o.       8  8 8888 \n");
        printf(cor_verde "88 8888        `8b `8.`888b     ,8'    .`Y888888o.    8  8 8888 \n");
        printf(cor_verde "88 8888         88  `8.`888b   ,8'     8o. `Y888888o. 8  8 8888 \n");
        printf(cor_branca "88 8888         88   `8.`888b ,8'      8`Y8o. `Y88888o8  8 8888 \n");
        Sleep(100);
        system("cls");
        printf(cor_branca "================================================================\n\n");
        printf(cor_verde "    ,o888888o.  `8.`888b           ,8' b.             8  8 8888 \n");
        printf(cor_verde " . 8888     `88. `8.`888b         ,8'  888o.          8  8 8888 \n");
        printf(cor_verde ",8 8888       `8b `8.`888b       ,8'   Y88888o.       8  8 8888 \n");
        printf(cor_verde "88 8888        `8b `8.`888b     ,8'    .`Y888888o.    8  8 8888 \n");
        printf(cor_verde "88 8888         88  `8.`888b   ,8'     8o. `Y888888o. 8  8 8888 \n");
        printf(cor_verde "88 8888         88   `8.`888b ,8'      8`Y8o. `Y88888o8  8 8888 \n");
        printf(cor_branca "88 8888        ,8P    `8.`888b8'       8   `Y8o. `Y8888  8 8888 \n");
        Sleep(100);
        system("cls");
        printf(cor_branca "================================================================\n\n");
        printf(cor_verde "    ,o888888o.  `8.`888b           ,8' b.             8  8 8888 \n");
        printf(cor_verde " . 8888     `88. `8.`888b         ,8'  888o.          8  8 8888 \n");
        printf(cor_verde ",8 8888       `8b `8.`888b       ,8'   Y88888o.       8  8 8888 \n");
        printf(cor_verde "88 8888        `8b `8.`888b     ,8'    .`Y888888o.    8  8 8888 \n");
        printf(cor_verde "88 8888         88  `8.`888b   ,8'     8o. `Y888888o. 8  8 8888 \n");
        printf(cor_verde "88 8888         88   `8.`888b ,8'      8`Y8o. `Y88888o8  8 8888 \n");
        printf(cor_verde "88 8888        ,8P    `8.`888b8'       8   `Y8o. `Y8888  8 8888 \n");
        printf(cor_branca "`8 8888       ,8P      `8.`888'        8      `Y8o. `Y8  8 8888 \n");
        Sleep(100);
        system("cls");
        printf(cor_branca "================================================================\n\n");
        printf(cor_verde "    ,o888888o.  `8.`888b           ,8' b.             8  8 8888 \n");
        printf(cor_verde " . 8888     `88. `8.`888b         ,8'  888o.          8  8 8888 \n");
        printf(cor_verde ",8 8888       `8b `8.`888b       ,8'   Y88888o.       8  8 8888 \n");
        printf(cor_verde "88 8888        `8b `8.`888b     ,8'    .`Y888888o.    8  8 8888 \n");
        printf(cor_verde "88 8888         88  `8.`888b   ,8'     8o. `Y888888o. 8  8 8888 \n");
        printf(cor_verde "88 8888         88   `8.`888b ,8'      8`Y8o. `Y88888o8  8 8888 \n");
        printf(cor_verde "88 8888        ,8P    `8.`888b8'       8   `Y8o. `Y8888  8 8888 \n");
        printf(cor_verde "`8 8888       ,8P      `8.`888'        8      `Y8o. `Y8  8 8888 \n");
        printf(cor_branca " ` 8888     ,88'        `8.`8'         8         `Y8o.`  8 8888 \n");
        Sleep(100);
        system("cls");
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
        printf(cor_branca "    `8888888P'           `8.`          8            `Yo  8 8888 \n\n");
        Sleep(100);
        system("cls");
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
    }

    Sleep(250);
    printf(cor_branca "================================================================\n");
    Sleep(250);
    printf("Dev: ");
    Sleep(250);
    printf(cor_verde "Vinicius Candeia\n" cor_branca);
    Sleep(250);
    printf(cor_branca "================================================================\n");

    clock_t fim = clock();
    double duracao = (double)(fim - inicio) / CLOCKS_PER_SEC;
    printf("Tempo: ");
    printf(cor_amarela "%.2lfs" cor_branca, duracao);
    printf(cor_branca "\n================================================================\n\n");
    Sleep(1000);
}

int nome2(void){

    system("cls");

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
    printf(cor_verde "Vinicius Candeia\n" cor_branca);
    printf(cor_branca "================================================================\n\n");
    Sleep(1000);

}

int main(void){

    nome2();

    int num;

    printf("Qual numero desejar saber a tabuada? ");
    scanf("%d", &num);

    printf(cor_branca "\n================================================================\n\n");

    for (int i = 1; i <= 10; i++){
        printf(cor_ciano "%2d" 
               cor_branca " x " 
               cor_amarela "%2d" 
               cor_branca " = " 
               cor_verde "%2d\n" cor_branca, num, i, num * i);
    }

    printf(cor_branca "\n================================================================\n\n");

    return 0;
}