#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include <pthread.h>
#include <semaphore.h>
#include <time.h>
#include <sys/wait.h>
#include <errno.h>
#include <string.h>

#define QTD_THREADS 4
#define QTD_EXECUCOES 5

int qtd_palavras_criadas = 0;
char palavra_criada[QTD_THREADS];

pthread_barrier_t barreira;

void* criar_letras(void* p){
    long index = (long)p;
    char letra;

    while(qtd_palavras_criadas < QTD_THREADS){
        letra = 65 + (rand() % 20);
        palavra_criada(index) = letra;
        pthread_barrier_wait(&barreira);

    }

    //printf("[%ld] - Palavrea Criada = %c",index,palavra_criada);

}

int main()
{
    pthread_t threads(QTD_THREADS);
    time_t tempo;

    pthread_t threads(QTD_THREADS);
        
    pthread_barrier_init(&barreira,NULL,QTD_THREADS + 1);

    for(long i = 0; i < QTD_THREADS ; i++){
        pthread_create(&threads[i],NULL,criar_letras, (void*)i);
    }

    for(int i = 0 ; i < QTD_THREADS ; i++){

        pthread_create(&threads[i],NULL,criar_letras,NULL);
    }
        
    while(qtd_palavras_criadas < QTD_EXECUCOES){
        pthread_barrier_wait(&barreira);
        int contador = 0;
        char a = 97, e = 101, i = 105, o = 111, u = 117;
            
        for(int j = 0 ; j < QTD_THREADS ; j++){
            if(strchrpalavra_criada[j] == "a"){
                contador++;
            }else if(palavra_criada[j] == "e"){
                contador++;
            }else if(palavra_criada[j] == "i"){
                contador++;
            }else if(palavra_criada[j] == "o"){
                contador++;
            }else if(palavra_criada[j] == "u"){
                contador++;
            }
            
        }
            
        printf("A quantidade de vogais da palavra %c é : %i \n",palavra_criada,contador);
            
        _sync_fetch_and_add(&qtd_palavras_criadas,1);
        }
        
    //pthread_barrier_wait(&barreira);
    //pthread_barrier_destroy(&barreira);
}