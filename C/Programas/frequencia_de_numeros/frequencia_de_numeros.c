#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
#include <Windows.h>
#include <time.h>

int main(void){

    system("cls");

    int quant;
    int numero[2000];
    int cont = 0;
    int c;
    int repetidos[1000];
    int contagem_repetidos = 0;
    int verificacao_repetidos = 0;
    int aux1;
    int aux2;
    int menor = 0;
    int falhas = 0;

    printf("\n================== QUANTIDADE ======================\n\n");

    printf("Quantidade: ");
    scanf("%d", &quant);

    printf("\n==================== NUMEROS =======================\n\n");
    
    for(int i = 0; i < quant; i++){
        printf("Numero: ");
        scanf("%d", &numero[i]);
    }

    printf("\n========== SELECAO DE NUMEROS REPETIDOS ============\n\n");
    
    for(int i = 0; i < quant; i++){
        for(int k = 0; k < contagem_repetidos; k++){
            if (numero[i] == repetidos[k]){
                verificacao_repetidos = 1; // o numero[i] ja ta nos repetidos
            }
        }
        if (verificacao_repetidos == 0){
            repetidos[contagem_repetidos] = numero[i];
            contagem_repetidos += 1;
        } else {
            verificacao_repetidos = 0; 
            continue;
        }
    }

    printf("\n=============== RESULTADO PRELIMINAR ===============\n\n");

    for(int i = 0; i < contagem_repetidos; i++){
        for(int k = 0; k < quant; k++){
            if (repetidos[i] == numero[k]){
                cont += 1;
            }
        }
        printf("%3d aparece %d vez(es)\n", repetidos[i], cont);
        cont = 0;
    }

    printf("\nContagem repetidos: %d\n", contagem_repetidos);

    printf("\n============== ORGANIZACAO CRESCENTE ===============\n\n");

    while (true){
        for(int i = 0; i < contagem_repetidos; i++){
            if (i - 1 < contagem_repetidos){
                if (repetidos[i] > repetidos[i + 1]){
                    aux1 = repetidos[i];
                    aux2 = repetidos[i + 1];

                    if (i < contagem_repetidos - 1){
                        repetidos[i] = aux2;
                        repetidos[i + 1] = aux1;
                    }
                    
                    break;
                } else {
                    falhas += 1;
                }
            }
        }

        if (falhas == contagem_repetidos - 1){
            break;
        }

        for(int i = 0; i < contagem_repetidos; i++){
            printf("%d ", repetidos[i]);
        }
        printf("\n");

        falhas = 0;
    }

    for(int i = 0; i < contagem_repetidos; i++){
        printf("%d ", repetidos[i]);
    }
    printf("\n");

    printf("\n================== RESULTADO FINAL =================\n\n");

    for(int i = 0; i < contagem_repetidos; i++){
        for(int k = 0; k < quant; k++){
            if (repetidos[i] == numero[k]){
                cont += 1;
            }
        }
        printf("%3d aparece %d vez(es)\n", repetidos[i], cont);
        cont = 0;
    }

    printf("\nContagem repetidos: %d\n", contagem_repetidos);

    printf("\n================== FIM DO PROGRAMA ================\n\n");

    // printf("\n===================================================\n\n");

    return 0;
}
