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

int entrada[QUANT_THREADS];
int saida[QUANT_THREADS];

int arrive[QUANT_THREADS];
int proceed[QUANT_THREADS];

void *worker(void *valor)
{
    long indice = (long)valor;

    while (true)
    {
        saida[indice] = pow(entrada[indice], 2);
        wprintf(corCiano L"%d " corBranca ": de : %d : para : %d \n", indice, entrada[indice], saida[indice]);

        sleep(rand() % 3);
        wprintf(corCiano L"%d " corBranca ": Tarefa finalizada pela thread. \n", indice);

        arrive[indice] = 1;

        while (proceed[indice] != 1)
            usleep(3000);

        proceed[indice] = 0;
        wprintf(corCiano L"%d " corBranca ": saiu da barreira. \n", indice);
    }

    return 0;
}

void *coordinator(void *valor)
{
    long indice = (long)valor;

    while (true)
    {
        for (int i = 0; i < QUANT_THREADS; i++)
        {
            while (arrive[i] == 0)
                usleep(3000);
            arrive[i] = 0;
        }

        wprintf(corAmarela L" >> Barreira cheia! Liberando! \n" corBranca);

        for (int i = 0; i < QUANT_THREADS; i++)
        {
            proceed[i] = 1;
        }
    }

    return 0;
}

int main()
{

    inicioCodigo();

    pthread_t threads[QUANT_THREADS];
    pthread_t coord;

    srand(time(NULL));

    for (int i = 0; i < QUANT_THREADS; i++)
    {
        entrada[i] = rand() % 100;
    }

    pthread_create(&coord, NULL, coordinator, NULL);

    for (long i = 0; i < QUANT_THREADS; i++)
    {
        pthread_create(&threads[i], NULL, worker, (void *)i);
    }

    sleep(45);

    traco(2);
    return 0;
}