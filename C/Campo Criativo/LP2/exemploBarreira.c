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

int contadorBarreira = 0;

pthread_barrier_t controleBarreira;

void *worker(void *valor)
{
    long indice = (long)valor;

    while (true)
    {

        // * Tarefa aqui

        sleep(1 + indice);
        wprintf(corCiano L"%d " corBranca ": chegou à barreira. \n", indice);

        int retornoBarreira = pthread_barrier_wait(&controleBarreira);

        if ((retornoBarreira != 0) && (retornoBarreira != PTHREAD_BARRIER_SERIAL_THREAD))
        {
            wprintf(corVermelha L"Erro na barreira. \n" corBranca);
            exit(0);
        }

        wprintf(corCiano L"%d " corBranca ": pulou à barreira. \n", indice);
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
        }

        wprintf(corAmarela L" >> Barreira cheia! Liberando! \n" corBranca);
    }

    return 0;
}

int main()
{

    inicioCodigo();

    int initBarreira = pthread_barrier_init(&controleBarreira, NULL, QUANT_THREADS);

    if (initBarreira != 0)
    {
        wprintf(corVermelha L"Erro ao iniciar barreira. \n" corBranca);
        exit(0);
    }

    pthread_t threads[QUANT_THREADS];

    for (long i = 0; i < QUANT_THREADS; i++)
    {
        pthread_create(&threads[i], NULL, funcaoThread, (void *)i);
    }

    sleep(30);

    traco(2);
    return 0;
}