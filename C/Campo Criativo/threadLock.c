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

// Utilizando travas de threads.

/*
    int pthread_mutex_init(pthread_mutex_t *restringir mutex, const pthread_mutexattr_t *restringir attr)
        Retorno:
            Bem-sucedido: 0
            Falha:       -1

    int pthread_mutex_lock(pthread_mutex_t *mutex)
        Exemplo:
                pthread_mutex_t lock;
                MAIN: pthread_mutex_lock(&lock);
        Retorno:
            Bem-sucedido: 0
            Falha:       -1

    int pthread_mutex_unlock(pthread_mutex_t *mutex)
        Exemplo:
                pthread_mutex_t lock;
                MAIN: pthread_mutex_unlock(&lock);
        Retorno:
            Bem-sucedido: 0
            Falha:       -1
*/

/* Código 1 */

pthread_mutex_t trava = PTHREAD_MUTEX_INITIALIZER;

void mostraSituacao(int valorTrava, char modo)
{

    if (modo == 't')
    {
        if (valorTrava == 0)
        {
            wprintf(cor_branca " >> " cor_verde L"Travado!\n\n" cor_branca);
        }
        else
        {
            wprintf(cor_branca " >> " cor_vermelha L"Não travou!\n\n" cor_branca);
        }
    }
    else if (modo == 'd')
    {
        if (valorTrava == 0)
        {
            wprintf(cor_branca "\n >> " cor_verde L"Destravado!\n" cor_branca);
        }
        else
        {
            wprintf(cor_branca " >> " cor_vermelha L"Não destravou!\n" cor_branca);
        }
    }
}

void *funcao(void *valor)
{

    long num = (long)valor;
    int contador = 1;

    while (true)
    {

        if (num == 1)
        {
            wprintf(cor_verde L"");
        }
        else if (num == 2)
        {
            wprintf(cor_amarela L"");
        }
        else if (num == 3)
        {
            wprintf(cor_azul L"");
        }
        srand(time(NULL));
        wprintf(L"%ld : %d : %ld\n" cor_branca, num, contador, (rand() % 5));

        sleep(1);

        if (contador >= 5)
        {
            break;
        }

        contador += 1;
    }

    int valorTrava = pthread_mutex_unlock(&trava);
    mostraSituacao(valorTrava, 'd');

    pthread_exit(NULL);
}

/*
int main()
{

    inicioCodigo();

    pthread_t thread[3];

    for (int i = 1; i <= 3; i++)
    {

        int valorTrava = pthread_mutex_lock(&trava);
        mostraSituacao(valorTrava, 't');

        int flag = pthread_create(&thread[i - 1], NULL, funcao, (void *)i);

        if (flag != 0)
        {
            wprintf(cor_vermelha L"Erro ao criar thread!" cor_branca);
        }
    }

    for (int i = 1; i <= 3; i++)
    {
        void *retorno;
        int flag = pthread_join(thread[i - 1], &retorno);
    }

    traco(1);
    return 0;
}
 */

/* Código 2 */

pthread_mutex_t travaThread1 = PTHREAD_MUTEX_INITIALIZER;

int valorGlobal = 0;

void *funcaoThread1(void *valor)
{
    int array[5];
    int valorSomado = 0;
    srand(time(NULL));

    wprintf(cor_amarela L"%2d\n" cor_branca, valorSomado);
    for (int i = 0; i < 6; i++)
    {
        array[i] = (rand() % 8 + 1);

        valorSomado += array[i];
        wprintf(cor_amarela L"%2d" cor_branca, valorSomado);

        for (int j = 0; j <= i; j++)
        {
            if (j == 0)
            {
                wprintf(L" = ");
            }
            wprintf(cor_verde L"%d" cor_branca, array[j]);
            if (j + 1 <= i)
            {
                wprintf(L" + ");
            }
        }
        wprintf(L"\n");
    }

    valorGlobal = valorSomado;

    sleep(10);

    int valorTrava = pthread_mutex_unlock(&travaThread1);
    mostraSituacao(valorTrava, 'd');

}

void *funcaoThread2(void *valor)
{
    traco(2);
    for (int i = valorGlobal; i >= 0; i--)
    {
        wprintf(L"%2d ", i);
        if (i % 5 == 0)
        {
            wprintf(L"\n");
        }
    }
    traco(1);
}

int main()
{

    inicioCodigo();

    pthread_t thread[2];
    void *retorno;
    int flag;

    int valorTrava = pthread_mutex_lock(&travaThread1);
    mostraSituacao(valorTrava, 't');

    flag = pthread_create(&thread[0], NULL, funcaoThread1, NULL);
    flag = pthread_join(thread[0], &retorno);

    flag = pthread_create(&thread[1], NULL, funcaoThread2, NULL);
    flag = pthread_join(thread[1], &retorno);

    sleep(10);

    traco(2);
    return 0;
}