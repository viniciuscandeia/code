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

int varGlobal = 0;
int trava = 0;

/*
 * -> Primeira implementação de trava (lock) a partir de pseudo-código de Andrews (contido nos slides).

 * -> Está implementação é problemática, pois seu protocolo de entrada não é executado de forma atômica, ou seja,
 *    podemos ter escalonamento durante o processo realizado por este protocolo, o que pode fazer com que mais de
 *    uma pthread/processo acessem a seção crítica.
*/

void *cs(void *valor)
{
    long indice = (long)valor;
    while (true)
    {
        // | Só progride quando trava for diferente de 1 (true)
        // | Vai testar se o valor de trava é diferente de 1, se for, ele vai definir o valor para 1

        // | Protocolo de entrada
        while (__sync_lock_test_and_set(&trava, 1))
            ;

        varGlobal += 1;
        wprintf(corAmarela L"[%2ld]" corBranca L" : alterou o valor para : " corAmarela L"%2d \n", indice, varGlobal);

        // | Protocolo de saída
        trava = 0;

        sleep(1);
    }
}

int main()
{

    inicioCodigo();

    pthread_t thread1, thread2;
    pthread_create(&thread1, NULL, cs, (void *)1);
    pthread_create(&thread2, NULL, cs, (void *)2);

    sleep(20);

    // pthread_join(thread1, NULL);
    // pthread_join(thread2, NULL);

    traco(2);
    return 0;
}