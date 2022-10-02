#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
#include <time.h>

#define TAM_PALAVRA 6

char palavra[TAM_PALAVRA];

pthread_barrier_t barreira;

int contador = 0;

void checa_palindromo(char* str, int str_size) {
    int i, j;
    printf("PALAVRA: %s\n", str);
    for (i = 0, j = str_size - 1; i < j; i++, j--) {
        if (str[i] != str[j]) {
            printf("Nao eh palindromo\n");
            return;
        }
    }
    printf("Eh palindromo\n");
}

void* gera_letra(void* p) {
    long idx = (long) p;

    while (contador < 10) {
        palavra[idx] = (rand() % 26) + 'a';
        sleep(1);
        pthread_barrier_wait(&barreira);

    }
}

int main (void) {
   
    pthread_t threads[TAM_PALAVRA];

    pthread_barrier_init(&barreira, NULL, TAM_PALAVRA + 1);

    for (long i = 0; i < TAM_PALAVRA; i++) {
        pthread_create(&threads[i], NULL, gera_letra, (void*) i);
    }

    while (contador < 10) {
        pthread_barrier_wait(&barreira);
        checa_palindromo(palavra, TAM_PALAVRA);
        contador++;
    }

    for (int i = 0; i < TAM_PALAVRA; i++) {
        pthread_join(threads[i], NULL);
    }

    printf("%s\n", palavra);

    return 0;
}