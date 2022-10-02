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
#include "aditivos.h"

#define QUANT_THREADS 5

pthread_mutex_t travaMutex = PTHREAD_MUTEX_INITIALIZER;

int valorGlobal;

void *primeiraFuncao(void *valor)
{
    long indice = (long)valor;

    while (true)
    {
        // | Protocolo de entrada
        pthread_mutex_lock(&travaMutex);

        valorGlobal += 1;
        wprintf(corCiano L"%d" corBranca " : valor : %d \n", indice, valorGlobal);

        // sleep(1);

        // | Protocolo de saída
        pthread_mutex_unlock(&travaMutex);
    }
}

int main()
{

    inicioCodigo();

    valorGlobal = 0;

    pthread_t threads[QUANT_THREADS];

    for (long i = 0; i < QUANT_THREADS; i++)
    {
        pthread_create(&threads[i], NULL, primeiraFuncao, (void *)i);
    }

    sleep(20);

    pthread_mutex_destroy(&travaMutex);

    traco(2);
    return 0;
}
