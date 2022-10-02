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

int atual = 1;
int proximo = 1;
int valorGlobal = 0;
int vez[QUANT_THREADS] = {0, 0, 0, 0, 0};

pthread_mutex_t numeroMutex = PTHREAD_MUTEX_INITIALIZER;
pthread_mutex_t condicaoMutex = PTHREAD_MUTEX_INITIALIZER;
pthread_mutex_t condicaoCond = PTHREAD_MUTEX_INITIALIZER;

void *funcaoThread(void *valor)
{
    long indice = (long)valor;

    while (true)
    {

        pthread_mutex_lock(&numeroMutex);
        atual += 1;
        vez[indice] = atual;
        pthread_mutex_unlock(&numeroMutex);

        // * Seção crítica
        // pthread_mutex_lock(&condicaoMutex);
        if ((vez[indice] % atual) == 0)
        {
            pthread_cond_signal(&condicaoCond);
        }
        else
        {
            pthread_cond_wait(&condicaoCond, &condicaoMutex);
        }

        valorGlobal += 1;

        wprintf(corCiano L"%d" corBranca " : valorGlobal :" corVerde " %d \n" corBranca, indice, valorGlobal);
        sleep(1);

        if (valorGlobal % QUANT_THREADS == 0)
        {
            wprintf(L"\n");
        }

        pthread_mutex_unlock(&condicaoMutex);
    }
}

int main()
{

    inicioCodigo();

    pthread_t threads[QUANT_THREADS];

    for (int i = 0; i < QUANT_THREADS; i++)
    {
        vez[i] = 0;
    }

    for (long i = 0; i < QUANT_THREADS; i++)
    {
        pthread_create(&threads[i], NULL, funcaoThread, (void *)i);
    }

    sleep(20);

    traco(2);
    return 0;
}