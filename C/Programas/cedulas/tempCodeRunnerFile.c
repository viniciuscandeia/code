#include <stdio.h>

int main(void){

    int dinheiro;
    int dinheiro_copia;
    int div100;
    int div50;
    int div20;
    int div10;
    int div5;
    int div2;
    int div1;

    scanf("%d", &dinheiro);

    dinheiro_copia = dinheiro;

    if (dinheiro_copia >= 100){
        div100 = dinheiro_copia / 100;
        dinheiro_copia = dinheiro_copia - div100 * 100;
    } else{
        div100 = 0;
    }

    if (dinheiro_copia >= 50){
        div50 = dinheiro_copia / 50;
        dinheiro_copia = dinheiro_copia - div50 * 50;
    } else{
        div50 = 0;
    }   
    
    if (dinheiro_copia >= 20){
        div20 = dinheiro_copia / 20;
        dinheiro_copia = dinheiro_copia - div20 * 20;
    } else{
        div20 = 0;
    }   

    if (dinheiro_copia >= 10){
        div10 = dinheiro_copia / 10;
        dinheiro_copia = dinheiro_copia - div10 * 10;
    } else{
        div10 = 0;
    }   

    if (dinheiro_copia >= 5){
        div5 = dinheiro_copia / 5;
        dinheiro_copia = dinheiro_copia - div5 * 5;
    } else{
        div5 = 0;
    }   

    if (dinheiro_copia >= 2){
        div2 = dinheiro_copia / 2;
        dinheiro_copia = dinheiro_copia - div2 * 2;
    } else{
        div2 = 0;
    }

    if (dinheiro_copia > 0){
        div1 = dinheiro_copia / 1;
        dinheiro_copia = dinheiro_copia - div1 * 1;
    } else{
        div1 = 0;
    }

    printf("%d\n", dinheiro);
    printf("%d nota(s) de R$ 100,00\n", div100);
    printf("%d nota(s) de R$ 50,00\n", div50);
    printf("%d nota(s) de R$ 20,00\n", div20);
    printf("%d nota(s) de R$ 10,00\n", div10);
    printf("%d nota(s) de R$ 5,00\n", div5);
    printf("%d nota(s) de R$ 2,00\n", div2);
    printf("%d nota(s) de R$ 1,00\n", div1);

    return 0;
}


