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

    char texto[] = "A";
    int valor;
    int repeticao = 1;
    int resultado_div, contador = 0;
    
    printf("Digite um valor ( > 0): ");
    scanf("%d", &valor);
    printf(cor_branca "----------------------------------------------------------------\n");
    printf("Desejar ver os valores:"
            cor_ciano "\n( P ) Pares" cor_branca
            cor_amarela "\n( I ) Impares" cor_branca);
    printf("\nSua opcao: ");
    scanf("%s", &texto[0]);

    if (texto[0] != 'P' && texto[0] != 'p' && texto[0] != 'I' && texto[0] != 'i'){
        printf(cor_vermelha "\nRESPOSTA INVALIDA!\n" cor_branca);
        Sleep(1000);
        nome2();
        printf("Valor digitado: " cor_amarela "%d" cor_branca, valor);
        printf("\n----------------------------------------------------------------\n");
        while (repeticao == 1){ // caso a condição seja verdadeira o while irá repetir seu conteúdo 
            printf("Desejar ver os valores:"
                    cor_ciano "\n( P ) Pares" cor_branca
                    cor_amarela "\n( I ) Impares" cor_branca);
            printf("\nSua opcao: ");
            scanf("%s", &texto[0]);
            if ((texto[0] == 'P') || (texto[0] == 'p') ||
                (texto[0] == 'I') || (texto[0] == 'i')){ // condição para sair do while
                    repeticao = 0; // repeticao_l receberá o valor 0
            } else {  // caso a condição não seja verdadeira
                printf(cor_vermelha "\nESCOLHA INVALIDA!\n" cor_branca); // mostrando "ESCOLHA INVALIDA" em vermelho
                Sleep(1000); // sleep de 1 segundo
                nome2();
                printf("Numero escolhido: %d", valor);
                printf(cor_branca "\n----------------------------------------------------------------\n");
            }
        }
    }

    printf(cor_branca "\n================================================================\n");
    
    if (texto[0] == 'P' || texto[0] == 'p'){
        resultado_div = valor / 2;
        printf("\nOs numeros sao: ");
        for(int i = 0; i <= valor; i++){
            if (i % 2 == 0){
                contador += 1;
                printf(cor_verde "%d" cor_branca, i);
                if (contador < resultado_div){
                    printf(", ");
                } else if (contador == resultado_div){
                    printf(" e ");
                }
            }
        }
        printf(".");
    }

    if (texto[0] == 'I' || texto[0] == 'i'){
        resultado_div = valor / 2;
        printf("\nOs numeros sao: ");
        for(int i = 0; i <= valor; i++){
            if (i % 2 == 1){
                contador += 1;
                printf(cor_verde "%d" cor_branca, i);
                if (contador < resultado_div){
                    printf(", ");
                } else if (contador == resultado_div){
                    printf(" e ");
                }
            }
        }
        printf(".");
    }

    printf(cor_branca "\n\n================================================================\n\n");

    return 0;
}