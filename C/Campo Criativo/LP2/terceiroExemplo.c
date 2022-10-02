#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
#include <locale.h>
#include <sys/types.h>
#include <time.h>
#include <wchar.h>

#include <unistd.h>
#include <pthread.h>

#include "aditivos.h"

int primeiroValor = 0;
int segundoValor = 0;
int ultimo = 1;

int valorGlobal = 0;

void *cs1(void *valor)
{
    while (true)
    {
        ultimo = 1;
        primeiroValor = 1;
        // | Protocolo de entrada
        while (segundoValor == 1 && ultimo == 1)
            ;

        valorGlobal += 1;
        wprintf(corAmarela L"[CS1]" corBranca L" : alterou o valor para : " corAmarela L"%2d \n", valorGlobal);
        sleep(1);

        // | Protocolo de saída
        primeiroValor = 0;
    }
}

void *cs2(void *valor)
{
    while (true)
    {
        ultimo = 2;
        segundoValor = 1;
        // | Protocolo de entrada
        while (primeiroValor == 1 && ultimo == 2)
            ;

        valorGlobal += 1;
        wprintf(corCiano L"[CS2]" corBranca L" : alterou o valor para : " corCiano L"%2d \n", valorGlobal);
        sleep(1);

        // | Protocolo de saída
        segundoValor = 0;
    }
}

int main()
{

    inicioCodigo();

    pthread_t primeiraThread, segundaThread;
    pthread_create(&primeiraThread, NULL, cs1, NULL);
    pthread_create(&segundaThread, NULL, cs2, NULL);

    sleep(20);

    traco(1);
    return 0;
}