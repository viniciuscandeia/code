#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>

#define QTD_THREADS 5

float saldo_cliente = 0;

int number = 1, next = 1;
int turn[QTD_THREADS];

void* modifica_saldo(void *p) {
    long idx = (long)p;

    turn[idx] = __sync_fetch_and_add(&number,1);
	
	while(!(turn[idx] == next)) usleep(50);
	
    int valor = rand() % 1000;
    saldo_cliente += valor;
    printf("Thread %ld: saldo atualizado para %.2f\n", idx, saldo_cliente);
	puts("..");
	__sync_fetch_and_add(&next, 1);
    return 0;
}

int main(void) {
    pthread_t threads[QTD_THREADS];

    for (long i = 0; i < QTD_THREADS; i++) {
        pthread_create(&threads[i], NULL, modifica_saldo, (void *)i);
    }

    for (int i = 0; i < QTD_THREADS; i++) {
        pthread_join(threads[i], NULL);
    }

    return 0;

}
