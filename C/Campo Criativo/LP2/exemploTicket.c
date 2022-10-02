#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
#include <locale.h>
#include <sys/types.h>
#include <time.h>
#include <unistd.h>
#include <wchar.h>

#include <pthread.h>
#include <stdatomic.h>

#include "aditivos.h"

#define QUANT_THREADS 5

int atual = 1;
int proximo = 1;
int vez[QUANT_THREADS] = {0, 0, 0, 0, 0};
int valorGlobal = 0;

void *funcaoThread(void *valor)
{
    long indice = (long)valor;

    while (true)
    {
        // | Protocolo de entrada
        vez[indice] = __sync_fetch_and_add(&atual, 1);
        while (vez[indice] != proximo)
            ;

        // * Seção crítica
        valorGlobal = (valorGlobal % QUANT_THREADS) + 1;
        wprintf(corCiano L"%ld " corBranca ": valorGlobal :" corVerde " %d \n" corBranca, indice, valorGlobal);
        sleep(1);

        if (valorGlobal % QUANT_THREADS == 0)
        {
            wprintf(L"\n");
        }

        // | Protocolo de saída
        __sync_fetch_and_add(&proximo, 1);
    }
}

int main()
{

    inicioCodigo();

    pthread_t threads[QUANT_THREADS];

    for (long i = 0; i < QUANT_THREADS; i++)
    {
        pthread_create(&threads[i], NULL, funcaoThread, (void *)i);
    }

    for (int i = 0; i < QUANT_THREADS; i++)
    {
        pthread_join(threads[i], NULL);
    }

    traco(2);
    return 0;
}