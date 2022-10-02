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

void *funcao(void *valor){
    wprintf(L"oi");
    sleep(3);
}

int main()
{

    inicioCodigo();

    pthread_t t1;
    pthread_create(&t1, NULL, funcao, NULL);
    pthread_join(t1, NULL);

    traco(2);
    return 0;
}
