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

/*

*/

void contar(){

    FILE *arquivo_Original;
    { // Abrindo arquivo e verificando se abriu corretamente
        arquivo_Original = fopen("ano_todo.txt", "r");
        if (arquivo_Original == NULL){
            printf("================================================================\n\n" cor_branca);
            printf(cor_vermelha "O arquivo nao foi aberto!\n\n" cor_branca);
            printf("================================================================\n\n" cor_branca);
            Sleep(1000);
            exit(0);
        }
    }

    FILE *arquivo_segundos;
        { // Abrindo arquivo e verificando se abriu corretamente
        arquivo_segundos = fopen("C:/Users/vinic/OneDrive/Área de Trabalho/Programação/C/Programas/arquivos_entrando_dados/criando_modelo_de_documento/ano_todo_segundos.txt", "w");
        if (arquivo_segundos == NULL){
            printf("================================================================\n\n" cor_branca);
            printf(cor_amarela "O arquivo nao foi aberto!\n\n" cor_branca);
            printf("================================================================\n\n" cor_branca);
            Sleep(1000);
            exit(0);
        }
    }

    char linha[1000];
    int contador = 1;
    int contador_ciclos = 0;
    char numero[100];
    int valor = 0;
    long long soma = 0;
    int contar_linhas = 0;
    int contar_linhas_2 = 0;

    while(fgets(linha, 1000, arquivo_Original) != NULL){
        fflush(stdin);
        linha[strlen(linha) - 1] = '\0';
        if (contador == 5 + (6 * contador_ciclos)){
            for(int i = 17; i <= strlen(linha); i++){
                numero[i - 17] = linha[i];
            }
            fprintf(arquivo_segundos, "%s\n", numero);
            // printf("Linha [%d]: %s\n", contador, numero);
            // Sleep(1);
        }

        contador += 1;
        if (contador % 6 == 0){
            contador_ciclos += 1;
        }
    }

    fclose(arquivo_Original);
    fclose(arquivo_segundos);

    { // Abrindo arquivo e verificando se abriu corretamente
        arquivo_segundos = fopen("C:/Users/vinic/OneDrive/Área de Trabalho/Programação/C/Programas/arquivos_entrando_dados/criando_modelo_de_documento/ano_todo_segundos.txt", "r");
        if (arquivo_segundos == NULL){
            printf("================================================================\n\n" cor_branca);
            printf(cor_vermelha "O arquivo nao foi aberto!\n\n" cor_branca);
            printf("================================================================\n\n" cor_branca);
            Sleep(1000);
            exit(0);
        }
    }

    while(fgets(linha, 1000, arquivo_segundos) != NULL){
        contar_linhas += 1;
    }

    fclose(arquivo_segundos);
    { // Abrindo arquivo e verificando se abriu corretamente
        arquivo_segundos = fopen("C:/Users/vinic/OneDrive/Área de Trabalho/Programação/C/Programas/arquivos_entrando_dados/criando_modelo_de_documento/ano_todo_segundos.txt", "r");
        if (arquivo_segundos == NULL){
            printf("================================================================\n\n" cor_branca);
            printf(cor_vermelha "O arquivo nao foi aberto!\n\n" cor_branca);
            printf("================================================================\n\n" cor_branca);
            Sleep(1000);
            exit(0);
        }
    }

    FILE *arquivo_segundos_total;
    { // Abrindo arquivo e verificando se abriu corretamente
        arquivo_segundos_total = fopen("ano_todo_segundos_total.txt", "w");
        if (arquivo_segundos_total == NULL){
            printf("================================================================\n\n" cor_branca);
            printf(cor_vermelha "O arquivo nao foi aberto!\n\n" cor_branca);
            printf("================================================================\n\n" cor_branca);
            Sleep(1000);
            exit(0);
        }
    }
    
    printf(cor_branca "\n================================================================\n\n" cor_branca);
    fflush(stdin);

    while(true){
        if (contar_linhas_2 < contar_linhas){
            fscanf(arquivo_segundos, "%d", &valor);
            fflush(stdin);
            //printf("%10lld + %7d = ", soma, valor);
            soma += valor;
            // printf("%10lld\n", soma);
        } else {
            break;
        }
        contar_linhas_2 += 1;
    }

    fprintf(arquivo_segundos_total, "%lld\n", soma);

    fclose(arquivo_segundos);
    fclose(arquivo_segundos_total);

}

void clear_keyboard_buffer(void)
{
    int c = 0;
    while ((c = getchar()) != '\n' && c != EOF) {}
    return;
}

int main() {

    system("cls");

    printf(cor_branca "================================================================\n\n" cor_branca);

    contar();

    printf(cor_branca "\n================================================================\n\n" cor_branca);

    return 0;
}
