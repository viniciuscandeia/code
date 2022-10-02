    #include <stdio.h>
    #include <stdlib.h>
    #include <stdbool.h>

    int main(void){

        int quant;
        int numero[2000];
        int cont = 0;
        int repetidos[1000];
        int contagem_repetidos = 0;
        int verificacao_repetidos = 0;
        int aux1;
        int aux2;
        int falhas = 0;

        scanf("%d", &quant);
        
        for(int i = 0; i < quant; i++){
            scanf("%d", &numero[i]);
        }
        
        for(int i = 0; i < quant; i++){
            for(int k = 0; k < contagem_repetidos; k++){
                if (numero[i] == repetidos[k]){
                    verificacao_repetidos = 1;
                }
            }
            if (verificacao_repetidos == 0){
                repetidos[contagem_repetidos] = numero[i];
                contagem_repetidos += 1;
            } else {
                verificacao_repetidos = 0; 
            }
        }

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

            falhas = 0;
        }

        for(int i = 0; i < contagem_repetidos; i++){
            for(int k = 0; k < quant; k++){
                if (repetidos[i] == numero[k]){
                    cont += 1;
                }
            }
            printf("%d aparece %d vez(es)\n", repetidos[i], cont);
            cont = 0;
        }

        return 0;
    }
