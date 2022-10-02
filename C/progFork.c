#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
#include <locale.h>
#include <sys/types.h>
#include <time.h>
#include <unistd.h>
#include <wchar.h>

int main(){

        printf("\n");

        int numero, processoPID;
        printf("Número: ");
        scanf("%d", &numero);

        processoPID = getpid();

        for(int i = 1; i <= numero - 1; i++){
                if (processoPID == getpid()){
                        // Processo PAI
                        fork();
                } else {
                        // Processo FILHO
                }
        }

        while(1);

        return 0;
}
