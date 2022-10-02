#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
#include <locale.h>
#include <sys/types.h>
#include <time.h>
#include <unistd.h>
#include <wchar.h>

#include "aditivos.h"
#include <pthread.h>

int varGlobal;
int primeiraTrava;
int segundaTrava;

/*
 * -> Primeira implementação de trava (lock) a partir de pseudo-código de Andrews (contido nos slides).

 * -> Está implementação é problemática, pois seu protocolo de entrada não é executado de forma atômica, ou seja,
 *    podemos ter escalonamento durante o processo realizado por este protocolo, o que pode fazer com que mais de
 *    uma pthread/processo acessem a seção crítica.
*/

void *cs1(void *valor)
{
    while (true)
    {
        // | Só progride quando segundaTrava for diferente de 1 (true)
        while (segundaTrava)
            ;
        wprintf(corAmarela L"CS1" corBranca L" : na seção crítica! \n");

        // | Protocolo de entrada
        primeiraTrava = 1;

        varGlobal += 1;
        wprintf(L"\t\t varGlobal : " corAmarela "%d \n" corBranca, varGlobal);

        // | Protocolo de saída
        primeiraTrava = 0;
        wprintf(corAmarela L"CS1" corBranca L" : fora da seção crítica! \n");

        sleep(1);
    }
}

void *cs2(void *valor)
{
    while (true)
    {
        // | Só progride quando primeiraTrava for diferente de 1 (true)
        while (primeiraTrava)
            ;
        wprintf(corCiano L"CS2" corBranca L" : na seção crítica! \n");

        // | Protocolo de entrada
        segundaTrava = 1;

        varGlobal += 1;
        wprintf(L"\t\t varGlobal : " corCiano "%d \n" corBranca, varGlobal);

        // | Protocolo de saída
        segundaTrava = 0;
        wprintf(corCiano L"CS2" corBranca L" : fora da seção crítica! \n");

        sleep(1);
    }
}

int main()
{

    inicioCodigo();

    pthread_t thread1, thread2;
    pthread_create(&thread1, NULL, cs1, NULL);
    pthread_create(&thread2, NULL, cs2, NULL);

    sleep(20);

    // pthread_join(thread1, NULL);
    // pthread_join(thread2, NULL);

    traco(2);
    return 0;
}