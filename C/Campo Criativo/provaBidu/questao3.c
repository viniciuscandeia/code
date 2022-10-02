/*
    Nome: Vinicius Candeia Pereira Vieira
    Matrícula: 20200009783
 */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
#include <semaphore.h>
#include <time.h>
#include <wchar.h>
#include <stdbool.h>
#include <locale.h>
#include <math.h>

#include "aditivos.h"
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

#define QUANT_GERACOES 1024
#define TAMANHO_BUFFER 1024

char buffer[TAMANHO_BUFFER];
int inicio = 0, fim = 0;
int contadorRepeticao;
sem_t vazio, cheio;

// * Função para produzir os caracteres
void *produtor(void *p)
{
    char letraProduzida;
    int contador = 0;

    fim = 0;

    while (contador < QUANT_GERACOES)
    {
        // | Momento do Travamento
        sem_wait(&vazio);

        // # Seção crítica
        letraProduzida = rand() % 25 + 65;

        wprintf(corAmarela L"PROD : " corBranca "%c || %4d || %d\n", letraProduzida, fim, contadorRepeticao);
        wprintf(L"");
        buffer[fim] = letraProduzida;

        fim = fim + 1;

        usleep(50);

        // # Seção não crítica
        contador++;
    }

    // | Momento do Destravamento
    sem_post(&cheio);
}

// * Função para consumir as letras
void *consumidor(void *p)
{
    char letraConsumida;
    int contador = 0;

    inicio = 0;

    // ! Abrindo o arquivo, caso o arquivo já exista, vai abrir no modo "append".
    FILE *meuArquivo;
    if (contadorRepeticao == 0)
    {
        meuArquivo = fopen("letras.txt", "w");
    }
    else
    {
        meuArquivo = fopen("letras.txt", "a");
    }

    while (contador < QUANT_GERACOES)
    {
        // | Momento do Travamento
        sem_wait(&cheio);

        // # Seção crítica
        while (inicio != fim)
        {
            letraConsumida = buffer[inicio];

            inicio = inicio + 1;
            wprintf(corCiano L"CONS : " corBranca "%c || %4d || %d\n", letraConsumida, inicio, contadorRepeticao);

            fprintf(meuArquivo, "%c\n", letraConsumida);

            usleep(rand() % 60 + 30);

            // | Momento do Destravamento
            sem_post(&vazio);

            // # Seção não crítica
            contador++;
        }
    }

    contadorRepeticao += 1;

    // ! Fechando o arquivo
    fclose(meuArquivo);
}

int main(void)
{
    pthread_t _produtor, _consumidor;

    for (int i = 0; i < TAMANHO_BUFFER; i++)
        buffer[i] = '0';

    srand(time(NULL));

    // * Iniciando os semáforos com valores diferentes.
    sem_init(&vazio, 0, TAMANHO_BUFFER);
    sem_init(&cheio, 0, 0);

    pthread_create(&_produtor, NULL, produtor, NULL);
    pthread_create(&_consumidor, NULL, consumidor, NULL);

    // * Thread principal esperando gerar todas as letras.
    while (contadorRepeticao != 1)
        ;

    pthread_create(&_produtor, NULL, produtor, NULL);
    pthread_create(&_consumidor, NULL, consumidor, NULL);

    // * Thread principal esperando gerar todas as letras.
    while (contadorRepeticao != 2)
        ;

    pthread_create(&_produtor, NULL, produtor, NULL);
    pthread_create(&_consumidor, NULL, consumidor, NULL);

    // * Thread principal esperando gerar todas as letras.
    while (contadorRepeticao != 3)
        ;

    pthread_create(&_produtor, NULL, produtor, NULL);
    pthread_create(&_consumidor, NULL, consumidor, NULL);

    // * Thread principal esperando gerar todas as letras.
    while (contadorRepeticao != 4)
        ;

    sem_destroy(&vazio);
    sem_destroy(&cheio);

    return 0;
}