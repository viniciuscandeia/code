/*
    Nome: Vinicius Candeia Pereira Vieira
    Matrícula: 20200009783

*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include <pthread.h>
#include <semaphore.h>
#include <time.h>
#include <sys/wait.h>

#include <string.h>
#include "aditivos.h"

/*
    (Questão 2 - 5,0 pontos) Faça um programa em C que 4 threads geram uma letra
    aleatória (caractere), e as depositam em uma palavra (string) na thread; então,
    a thread principal (função  main), depois de aguardar cada uma das threads
    depositar sua letra, deve exibir a string gerada. Posteriormente esta string
    deverá ser consumida, caractere por caractere, por uma thread consumidora (5a
    thread criada além da main). Esta thread receberá a string e contará quantas
    vogais nela constam, exibindo o valor. O processo deverá se repetir 5 vezes;
    finalmente, o programa deverá exibir o total de vogais de todas as palavras
    geradas e encerrar. Use barreiras (pthread.h) e semáforos (semaphore.h) e
    comente como suas funções foram utilizadas.
*/

#define QTD_THREADS 4
#define QTD_EXECUCOES 5

int quantidadePalavras = 0;
char palavraCriada[QTD_THREADS];

pthread_barrier_t barreira;

void *funcaoThread(void *valor)
{
    char letra = rand() % 25 + 65;
    pthread_exit((void *)letra);
}

int main()
{
    pthread_t threads[QTD_THREADS];
    srand(time(NULL));

    pthread_barrier_init(&barreira, NULL, QTD_THREADS + 1);

    while (quantidadePalavras < QTD_EXECUCOES)
    {

        for (long i = 0; i < QTD_THREADS; i++)
        {
            pthread_create(&threads[i], NULL, funcaoThread, NULL);
        }

        for (int i = 0; i < QTD_THREADS; i++)
        {
            void *retornoThread;
            pthread_join(threads[i], retornoThread);
            char *retorno = (char *)retornoThread;

            palavraCriada[i] = (char)retorno;
        }

        pthread_barrier_wait(&barreira);
        int contador = 0;

        for (int j = 0; j < QTD_THREADS; j++)
        {
            if (palavraCriada[j] == 'a')
            {
                contador++;
            }
            else if (palavraCriada[j] == 'e')
            {
                contador += 1;
            }
            else if (palavraCriada[j] == 'i')
            {
                contador++;
            }
            else if (palavraCriada[j] == 'o')
            {
                contador++;
            }
            else if (palavraCriada[j] == 'u')
            {
                contador++;
            }
        }

        wprintf(L"Total de vogais em " corAmarela "%s " corBranca ": " corCiano "%d \n", palavraCriada, contador);

        __sync_fetch_and_add(&quantidadePalavras, 1);
    }

    // pthread_barrier_wait(&barreira);
    pthread_barrier_destroy(&barreira);
}