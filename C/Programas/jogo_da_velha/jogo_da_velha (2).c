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

        Sleep(250);
        printf(cor_branca "------------------------------");
        Sleep(250);
        system("cls");
        printf(cor_verde "Iniciando dispositivo ");
        printf("(PRONTO) \n");
        printf("Atualizando pacotes ");
        printf("  (PRONTO) \n");
        printf(cor_branca "------------------------------");
        Sleep(250);
        system("cls");
        printf(cor_verde "Iniciando dispositivo ");
        printf("(PRONTO) \n");
        printf(cor_branca "------------------------------");
        Sleep(250);
        system("cls");
        printf(cor_branca "------------------------------");
        Sleep(250);
        system("cls");
        Sleep(250);

        srand((unsigned) time(NULL));
        for(int porc = 0; porc <= 100; porc++){
            system("cls");
            int valor = 0;
            valor = rand() % 15;
            porc += valor;
            printf(cor_vermelha "CARREGANDO OVNI ");
            if (porc <= 100){
                printf("(%d%%) \n", porc);
            }
            Sleep(100);
        }

        system("cls");
        rep += 1;
    }
    
    Sleep(200);

    printf(cor_branca "----------------------------------------------------------------\n\n");
    Sleep(200);
    int ovni = 0;
    if (ovni == 0){ //OVNI
        printf(cor_branca "    ,o888888o.  `8.`888b           ,8' b.             8  8 8888 \n");
        Sleep(100);
        system("cls");
        printf(cor_branca "----------------------------------------------------------------\n\n");
        printf(cor_verde "    ,o888888o.  `8.`888b           ,8' b.             8  8 8888 \n");
        printf(cor_branca " . 8888     `88. `8.`888b         ,8'  888o.          8  8 8888 \n");
        Sleep(100);
        system("cls");
        printf(cor_branca "----------------------------------------------------------------\n\n");
        printf(cor_verde "    ,o888888o.  `8.`888b           ,8' b.             8  8 8888 \n");
        printf(cor_verde " . 8888     `88. `8.`888b         ,8'  888o.          8  8 8888 \n");
        printf(cor_branca ",8 8888       `8b `8.`888b       ,8'   Y88888o.       8  8 8888 \n");
        Sleep(100);
        system("cls");
        printf(cor_branca "----------------------------------------------------------------\n\n");
        printf(cor_verde "    ,o888888o.  `8.`888b           ,8' b.             8  8 8888 \n");
        printf(cor_verde " . 8888     `88. `8.`888b         ,8'  888o.          8  8 8888 \n");
        printf(cor_verde ",8 8888       `8b `8.`888b       ,8'   Y88888o.       8  8 8888 \n");
        printf(cor_branca "88 8888        `8b `8.`888b     ,8'    .`Y888888o.    8  8 8888 \n");
        Sleep(100);
        system("cls");
        printf(cor_branca "----------------------------------------------------------------\n\n");
        printf(cor_verde "    ,o888888o.  `8.`888b           ,8' b.             8  8 8888 \n");
        printf(cor_verde " . 8888     `88. `8.`888b         ,8'  888o.          8  8 8888 \n");
        printf(cor_verde ",8 8888       `8b `8.`888b       ,8'   Y88888o.       8  8 8888 \n");
        printf(cor_verde "88 8888        `8b `8.`888b     ,8'    .`Y888888o.    8  8 8888 \n");
        printf(cor_branca "88 8888         88  `8.`888b   ,8'     8o. `Y888888o. 8  8 8888 \n");
        Sleep(100);
        system("cls");
        printf(cor_branca "----------------------------------------------------------------\n\n");
        printf(cor_verde "    ,o888888o.  `8.`888b           ,8' b.             8  8 8888 \n");
        printf(cor_verde " . 8888     `88. `8.`888b         ,8'  888o.          8  8 8888 \n");
        printf(cor_verde ",8 8888       `8b `8.`888b       ,8'   Y88888o.       8  8 8888 \n");
        printf(cor_verde "88 8888        `8b `8.`888b     ,8'    .`Y888888o.    8  8 8888 \n");
        printf(cor_verde "88 8888         88  `8.`888b   ,8'     8o. `Y888888o. 8  8 8888 \n");
        printf(cor_branca "88 8888         88   `8.`888b ,8'      8`Y8o. `Y88888o8  8 8888 \n");
        Sleep(100);
        system("cls");
        printf(cor_branca "----------------------------------------------------------------\n\n");
        printf(cor_verde "    ,o888888o.  `8.`888b           ,8' b.             8  8 8888 \n");
        printf(cor_verde " . 8888     `88. `8.`888b         ,8'  888o.          8  8 8888 \n");
        printf(cor_verde ",8 8888       `8b `8.`888b       ,8'   Y88888o.       8  8 8888 \n");
        printf(cor_verde "88 8888        `8b `8.`888b     ,8'    .`Y888888o.    8  8 8888 \n");
        printf(cor_verde "88 8888         88  `8.`888b   ,8'     8o. `Y888888o. 8  8 8888 \n");
        printf(cor_verde "88 8888         88   `8.`888b ,8'      8`Y8o. `Y88888o8  8 8888 \n");
        printf(cor_branca "88 8888        ,8P    `8.`888b8'       8   `Y8o. `Y8888  8 8888 \n");
        Sleep(100);
        system("cls");
        printf(cor_branca "----------------------------------------------------------------\n\n");
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
        printf(cor_branca "----------------------------------------------------------------\n\n");
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
        printf(cor_branca "----------------------------------------------------------------\n\n");
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
        printf(cor_branca "----------------------------------------------------------------\n\n");
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
    printf("----------------------------------------------------------------\n");
    Sleep(250);
    printf("Dev: ");
    Sleep(250);
    printf(cor_verde "Vinicius Candeia\n" cor_branca);
    Sleep(250);
    printf("----------------------------------------------------------------\n\n");
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

    printf(cor_branca "----------------------------------------------------------------\n\n");
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
    printf("----------------------------------------------------------------\n");
    printf("Dev: ");
    printf(cor_verde "Vinicius Candeia\n" cor_branca);
    printf("----------------------------------------------------------------\n\n");
}

int jogo_da_velha(void){

    setbuf(stdin, NULL);

    // Etapas:
    // Quem jogará primeiro? OK
    // Se for o usuário, o programa perguntará onde aquele deseja jogar OK
    // Se for o computador, o programa sorteará um valor OK
    // A próxima jogada depende de quem jogou antes
    // Uso do while para repetir as jogadas
    // Verificação se a jogada é válida
    // Verificação se formou a reta

    // Problemas:
    // Tentar inserir o 1 ou o 9 duas vezes, buga o código

    nome2();

    #define cor_preta     "\033[30m"
    #define cor_vermelha  "\033[31m"
    #define cor_verde     "\033[32m"
    #define cor_amarela   "\033[33m"
    #define cor_azul      "\033[34m"
    #define cor_magenta   "\033[35m"
    #define cor_ciano     "\033[36m"
    #define cor_branca    "\033[37m"

    printf(cor_amarela"Vamos jogar Jogo da Velha? \n" cor_branca);
    printf("-----------------------------------\n");
    Sleep(10);

    printf(cor_verde "O computador serah: O\n" cor_branca);
    printf(cor_vermelha "O usuario serah: X\n" cor_branca);
    printf("-----------------------------------\n");
    Sleep(10);

    srand((unsigned) time(NULL));
    int num_inicial = 1 + rand() % 2;

    printf("Quem irah comecar eh: ");
    Sleep(10);
    if (num_inicial == 1){
        printf(cor_vermelha "o usuario\n" cor_branca);
    } else {
        printf(cor_verde "o computador\n" cor_branca);
    }
    printf("-----------------------------------\n");
    Sleep(20);

    
    nome2();

    printf("  1 | 2 | 3 \n");
    printf(" ------------\n");
    printf("  4 | 5 | 6 \n");
    printf(" ------------\n");
    printf("  7 | 8 | 9 \n\n");

    int quadro[9] = {10, 20, 30, 40, 50, 60, 70, 80, 90};

    char jogo[9][1] = {'1', '2', '3', '4', '5', '6', '7', '8', '9'};
    
    printf("\n");

    int resposta_usu;

    if (num_inicial == 1){ // 1 rodada = usuario jogando
        printf("Em qual posicao voceh desejar jogar? ");
        scanf("%d", &resposta_usu);

        if (resposta_usu <= 0 || resposta_usu >= 10){
            while(resposta_usu <= 0 || resposta_usu >= 10){
                if (resposta_usu <= 0 || resposta_usu >= 10){
                    printf(cor_amarela "Desculpe, valor invalido!\n" cor_branca);
                    printf("Em qual posicao voceh desejar jogar? ");
                    scanf("%d", &resposta_usu);
                }
            }
        }

        quadro[resposta_usu - 1] = resposta_usu;
        jogo[resposta_usu - 1][0] = 'X';

    } else { // 1 rodada = pc jogando
        int resposta_cpu = 1 + rand() % 2;
        printf("O computador vai jogar na posicao: %d\n", resposta_cpu);

        quadro[resposta_cpu - 1] = resposta_cpu;
        jogo[resposta_cpu - 1][0] = 'O';
    }

    printf("\n  %c | %c | %c \n", jogo[0][0], jogo[1][0], jogo[2][0]);
    printf(" ------------\n");
    printf("  %c | %c | %c \n", jogo[3][0], jogo[4][0], jogo[5][0]);
    printf(" ------------\n");
    printf("  %c | %c | %c \n\n", jogo[6][0], jogo[7][0], jogo[8][0]);

    int voltas = 0;
    while (voltas <= 4){
        if (num_inicial == 1){ // o usuario ganhou a primeira rodada, vez do pc

            { // pc jogando
                int resposta_cpu = 1 + rand() % 9;

                if (resposta_cpu == quadro[resposta_cpu - 1]){
                    while (resposta_cpu == quadro[resposta_cpu - 1]){
                        resposta_cpu = 1 + rand() % 9;
                        jogo[resposta_cpu - 1][0] = 'O';
                    }
               }
                    
                printf("O computador vai jogar na posicao: %d\n", resposta_cpu);

                int contador = 0;
                for(int i = 0; i <= 8; i++){
                    contador += 1;
                    if (resposta_cpu == contador){
                        quadro[i] = resposta_cpu;
                        jogo[contador - 1][0] = 'O';
                        break;
                    } 
                }

                Sleep(2000);
                
                
                printf("\n  %c | %c | %c \n", jogo[0][0], jogo[1][0], jogo[2][0]);
                printf(" ------------\n");
                printf("  %c | %c | %c \n", jogo[3][0], jogo[4][0], jogo[5][0]);
                printf(" ------------\n");
                printf("  %c | %c | %c \n\n", jogo[6][0], jogo[7][0], jogo[8][0]);

                if (jogo[0][0] == 'O' && jogo[1][0] == 'O' && jogo[2][0] == 'O' ||
                    jogo[3][0] == 'O' && jogo[4][0] == 'O' && jogo[5][0] == 'O' ||
                    jogo[6][0] == 'O' && jogo[7][0] == 'O' && jogo[8][0] == 'O' ||
                    jogo[0][0] == 'O' && jogo[3][0] == 'O' && jogo[6][0] == 'O' ||
                    jogo[1][0] == 'O' && jogo[4][0] == 'O' && jogo[7][0] == 'O' ||
                    jogo[2][0] == 'O' && jogo[5][0] == 'O' && jogo[8][0] == 'O' ||
                    jogo[0][0] == 'O' && jogo[4][0] == 'O' && jogo[8][0] == 'O' ||
                    jogo[6][0] == 'O' && jogo[4][0] == 'O' && jogo[2][0] == 'O'){
                        printf("O PC ganhou!\n");
                        break;
                    }
            }

            { // usuario jogando
                printf("Em qual posicao voceh desejar jogar? ");
                scanf("%d", &resposta_usu);

                if (resposta_usu <= 0 || resposta_usu >= 10 || resposta_usu == quadro[resposta_usu - 1]){
                    while(resposta_usu <= 0 || resposta_usu >= 10 || resposta_usu == quadro[resposta_usu - 1]){
                        if (resposta_usu <= 0 || resposta_usu >= 10){
                            printf(cor_amarela "Desculpe, valor invalido!\n" cor_branca);
                            printf("Em qual posicao voceh desejar jogar? ");
                            scanf("%d", &resposta_usu);
                        } else if (resposta_usu == quadro[resposta_usu - 1]){
                            printf(cor_amarela "Desculpe, esta posicao ja estah ocupada!\n" cor_branca);
                            printf("Em qual posicao voceh desejar jogar? ");
                            scanf("%d", &resposta_usu);
                        }                        
                    }
                }

                quadro[resposta_usu - 1] = resposta_usu;
                jogo[resposta_usu - 1][0] = 'X';

                Sleep(2000);
                

                printf("\n  %c | %c | %c \n", jogo[0][0], jogo[1][0], jogo[2][0]);
                printf(" ------------\n");
                printf("  %c | %c | %c \n", jogo[3][0], jogo[4][0], jogo[5][0]);
                printf(" ------------\n");
                printf("  %c | %c | %c \n\n", jogo[6][0], jogo[7][0], jogo[8][0]);

                if (jogo[0][0] == 'X' && jogo[1][0] == 'X' && jogo[2][0] == 'X' ||
                    jogo[3][0] == 'X' && jogo[4][0] == 'X' && jogo[5][0] == 'X' ||
                    jogo[6][0] == 'X' && jogo[7][0] == 'X' && jogo[8][0] == 'X' ||
                    jogo[0][0] == 'X' && jogo[3][0] == 'X' && jogo[6][0] == 'X' ||
                    jogo[1][0] == 'X' && jogo[4][0] == 'X' && jogo[7][0] == 'X' ||
                    jogo[2][0] == 'X' && jogo[5][0] == 'X' && jogo[8][0] == 'X' ||
                    jogo[0][0] == 'X' && jogo[4][0] == 'X' && jogo[8][0] == 'X' ||
                    jogo[6][0] == 'X' && jogo[4][0] == 'X' && jogo[2][0] == 'X'){
                        printf("O usuario ganhou!\n");
                        break;
                    }

            }

        } else if (num_inicial == 2) { // o pc ganhou a primeira rodada, vez do usuario

            { // usuario jogando
                printf("Em qual posicao voceh desejar jogar? ");
                scanf("%d", &resposta_usu);

                if (resposta_usu < 1 || resposta_usu > 9 || resposta_usu == quadro[resposta_usu - 1]){
                    while(resposta_usu < 1 || resposta_usu > 9 || resposta_usu == quadro[resposta_usu - 1]){
                        if (resposta_usu < 1 || resposta_usu > 9){
                            printf(cor_amarela "Desculpe, valor invalido!\n" cor_branca);
                            printf("Em qual posicao voceh desejar jogar? ");
                            scanf("%d", &resposta_usu);
                        } else if (resposta_usu > 1 && resposta_usu < 9 && resposta_usu == quadro[resposta_usu - 1]){
                            printf(cor_amarela "Desculpe, esta posicao ja estah ocupada!\n" cor_branca);
                            printf("Em qual posicao voceh desejar jogar? ");
                            scanf("%d", &resposta_usu);
                        }                        
                    }
                }

                quadro[resposta_usu - 1] = resposta_usu;
                jogo[resposta_usu - 1][0] = 'X';
            
                Sleep(2000);
                
                
                printf("\n  %c | %c | %c \n", jogo[0][0], jogo[1][0], jogo[2][0]);
                printf(" ------------\n");
                printf("  %c | %c | %c \n", jogo[3][0], jogo[4][0], jogo[5][0]);
                printf(" ------------\n");
                printf("  %c | %c | %c \n\n", jogo[6][0], jogo[7][0], jogo[8][0]);

                if (jogo[0][0] == 'X' && jogo[1][0] == 'X' && jogo[2][0] == 'X' ||
                    jogo[3][0] == 'X' && jogo[4][0] == 'X' && jogo[5][0] == 'X' ||
                    jogo[6][0] == 'X' && jogo[7][0] == 'X' && jogo[8][0] == 'X' ||
                    jogo[0][0] == 'X' && jogo[3][0] == 'X' && jogo[6][0] == 'X' ||
                    jogo[1][0] == 'X' && jogo[4][0] == 'X' && jogo[7][0] == 'X' ||
                    jogo[2][0] == 'X' && jogo[5][0] == 'X' && jogo[8][0] == 'X' ||
                    jogo[0][0] == 'X' && jogo[4][0] == 'X' && jogo[8][0] == 'X' ||
                    jogo[6][0] == 'X' && jogo[4][0] == 'X' && jogo[2][0] == 'X'){
                        printf("O usuario ganhou!\n");
                        break;
                    }

            }

            { // pc jogando
                int resposta_cpu = 1 + rand() % 9;

                if (resposta_cpu == quadro[resposta_cpu - 1]){
                    while (resposta_cpu == quadro[resposta_cpu - 1]){
                        resposta_cpu = 1 + rand() % 9;
                        jogo[resposta_cpu - 1][0] = 'O';
                    }
               }

                printf("O computador vai jogar na posicao: %d\n", resposta_cpu);

                int contador = 0;
                for(int i = 0; i <= 8; i++){
                    contador += 1;
                    if (resposta_cpu == contador){
                        quadro[i] = resposta_cpu;
                        jogo[contador - 1][0] = 'O';
                        break;
                    } 
                }  

                Sleep(2000);

                
                printf("  %c | %c | %c \n", jogo[0][0], jogo[1][0], jogo[2][0]);
                printf(" ------------\n");
                printf("  %c | %c | %c \n", jogo[3][0], jogo[4][0], jogo[5][0]);
                printf(" ------------\n");
                printf("  %c | %c | %c \n\n", jogo[6][0], jogo[7][0], jogo[8][0]);

                if (jogo[0][0] == 'O' && jogo[1][0] == 'O' && jogo[2][0] == 'O' ||
                    jogo[3][0] == 'O' && jogo[4][0] == 'O' && jogo[5][0] == 'O' ||
                    jogo[6][0] == 'O' && jogo[7][0] == 'O' && jogo[8][0] == 'O' ||
                    jogo[0][0] == 'O' && jogo[3][0] == 'O' && jogo[6][0] == 'O' ||
                    jogo[1][0] == 'O' && jogo[4][0] == 'O' && jogo[7][0] == 'O' ||
                    jogo[2][0] == 'O' && jogo[5][0] == 'O' && jogo[8][0] == 'O' ||
                    jogo[0][0] == 'O' && jogo[4][0] == 'O' && jogo[8][0] == 'O' ||
                    jogo[6][0] == 'O' && jogo[4][0] == 'O' && jogo[2][0] == 'O' ){
                        printf("O PC ganhou!\n");
                        break;
                    }
            }

        voltas += 1;

        }
    }

    printf("\n\nFIM DO JOGO!\n");
}
    
int main(void){

    jogo_da_velha();
    
    return 0;
}