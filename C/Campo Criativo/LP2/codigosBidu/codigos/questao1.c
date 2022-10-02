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

void *funcaoThread(void *valor)
{
    char letra = rand() % 25 + 65;

    return letra;
}

int main()
{

    inicioCodigo();

    pthread_t primeiraThread, segundaThread;
    pthread_t terceiraThread, quartaThread;

    char palavra[4];
    void *retornoThread;
    char retornoPrimeira;
    char retornoSegunda;
    char retornoTerceira;
    char retornoQuarta;

    srand(time(NULL));

    pthread_create(&primeiraThread, NULL, funcaoThread, NULL);
    pthread_create(&segundaThread, NULL, funcaoThread, NULL);
    pthread_create(&terceiraThread, NULL, funcaoThread, NULL);
    pthread_create(&quartaThread, NULL, funcaoThread, NULL);

    pthread_join(primeiraThread, retornoThread);

    wprintf(L"Retorno: %c", (char *)retornoThread);

    traco(2);
    return 0;
}
