
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
#include <semaphore.h>
#include <time.h>

/*
    (Questão 3 - 2,0 pontos) Faça um programa em C/C++ que implemente uma solução
    para o problema do buffer compartilhado. Com um buffer compartilhado de 1024
    chars, o Programa deverá implementar duas funções:

        - produtor() - gera um caractere alfanumérico aleatório e o deposita
        no buffer; exibe o valor e a posição no buffer na tela;	dorme 50ms;
        repete;

        - consumidor() - captura um dos valores disponíveis no buffer
        compartilhado e armazena em um arquivo; dorme um tempo aleatório
        entre 30ms e 90ms; repete;

    A função produtor deverá ser realizada por uma thread, assim como a função
    consumidor.

    Use semáforos (biblioteca semaphore.h) para sincronizar o acesso ao buffer
    compartilhado, de forma que todos os caracteres gerados pelos produtores sejam
    consumidos uma vez, evitando qualquer problema ao ler ou escrever no buffer.
    Quando o buffer for consumido 4 vezes (ou seja, quando os produtores tiverem
    gerado 4096 caracteres e estes forem consumidos) finalize o programa, salvando
    o conteúdo do arquivo. Comente o código explicando o uso dos semáforos.

    Referências para manipulação de arquivos em C:

    https://www.inf.pucrs.br/~pinho/LaproI/Arquivos/Arquivos.htm (português)
    http://www.csc.villanova.edu/~mdamian/C/c-files.htm (inglês)
*/

#define QUANT_THREADS 10
#define TAMANHO_BUFFER 1024

char buffer[TAMANHO_BUFFER];
int inicio = 0, fim = 0;
int contadorRepeticao;
sem_t vazio, cheio;

void *produtor(void *p)
{
    char valorProdutor;
    int contador = 0;

    while (contador < QUANT_THREADS)
    {
        sem_wait(&vazio);
        valorProdutor = rand() % 25 + 65;
        contadorRepeticao += 1;

        printf("[PROD] %c\n", valorProdutor);
        buffer[fim] = valorProdutor;

        fim = (fim + 1) % TAMANHO_BUFFER;

        usleep(50);
        sem_post(&cheio);

        contador++;
    }
}

void *consumidor(void *p)
{
    int valor_cons;
    int contador = 0;

    while (contador < QUANT_THREADS)
    {
        sem_wait(&cheio);
        valor_cons = buffer[inicio];
        inicio = (inicio + 1) % TAMANHO_BUFFER;
        printf("[CONS] %d\n", valor_cons);
        sleep(2);
        sem_post(&vazio);
        contador++;
    }
}

int main(void)
{
    pthread_t _produtor, _consumidor;

    for (char i = 0; i < TAMANHO_BUFFER; i++)
        buffer[i] = '0';

    srand(time(NULL));

    sem_init(&vazio, 0, TAMANHO_BUFFER);
    sem_init(&cheio, 0, 0);

    pthread_create(&_prod, NULL, produtor, NULL);
    pthread_create(&_cons, NULL, consumidor, NULL);

    while (contadorRepeticao != 4096)
        ;

    sem_destroy(&vazio);
    sem_destroy(&cheio);

    return 0;
}