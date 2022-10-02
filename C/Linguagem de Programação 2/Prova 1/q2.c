/* 
ALUNO: Vinicius Candeia Pereira Vieira
MATRÍCULA: 20200009783 
*/

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
#include <signal.h>
#include <sys/wait.h>
#include <pthread.h>

double valorGlobal = 0;

/*
    (Questão 2 - 5 pontos) Faça um programa em C/C++ que siga as especificações
    abaixo:
    - declare uma variável valorGlobal do tipo double;
    - faça o programa criar um processo que gere um valor aleatório (entre 0 e 99)
    e faça este processo retornar o valor para o processo original, que estará
    bloqueado, aguardando.
    - o programa deverá então criar 10 threads, que executarão uma função que
    recebe como parâmetro valor inteiro que representa um índice único (de 0 a 9).
    - a função deverá verificar se seu identificador é par: caso positivo, a função
    deve realizar um laço de repetição que faça 50 incrementos (+1) na variável
    valorGlobal; caso o identificador não seja par, a função deve realizar um laço que
    faça 30 decrementos (-1) na variável valorGlobal. A cada iteração essa função deve
    exibir o identificador da thread e o novo valor da variável valorGlobal
    - depois dos laços, as threads cujo identificador for par devem dormir um tempo
    aleatório entre 1s e 4s; as threads cujo identificador for impar dormem um
    tempo fixo de 2s.
    - após o término de todas as threads, a thread principal deverá exibir o valor
    final da variável valorGlobal.

    Comente o código explicando o conceito de concorrência (e suas diferentes
    formas de realização nos SO mais facilmente encontrados). Explique quais
    são os elementos do Sistema Operacional e da arquitetura do computador
    envolvidos na execução do programa e como se comportam para que a lógica
    implementada seja executada de forma concorrente.
*/

/* 
    Concorrência é a capacidade dos processadores atuais rodarem diversos programas
    de maneira simultânea. Ou também pode trabalhar de maneira intercalada, com cada
    programa rodando por um tempo, depois o outro programa, ... .
*/

// Função que irá alterar o valor de valorGlobal, dependendo do seu identificador
void *funcao(void *valor)
{
    // Tentativa falha de fazer um cast de void* para int
    int num = *((int*)(&valor));

    // Se o identificador for par
    if ( num % 2 == 0)
    {
        // Incremento em 50 em valorGlobal
        for (int i = 1; i <= 50; i++)
        {
            valorGlobal += 1;
            wprintf(L"%d : %ld", *((int *) valor), valorGlobal);
        }
        int tempo = rand() % 4 + 1;
        sleep(tempo);
    }
    // Se o identificador for ímpar
    else
    {
        // Decremento em 30 em valorGlobal
        for (int i = 1; i <= 30; i++)
        {
            valorGlobal -= 1;
            wprintf(L"%d : %ld", *((int *) valor), valorGlobal);
        }
        sleep(2);
    }

    // Terminando a thread
    pthread_exit(NULL);
}

int main()
{

    inicioCodigo();

    // Definindo variáveis
    pid_t processoPID;
    pthread_t thread[10];
    int valorFork, flag;
    int status, retorno;

    srand(time(NULL));

    valorFork = fork();

    // PAI vai ficar esperando até o filho passar um valor aleatório
    if (valorFork != 0)
    {
        // Processo: PAI
        retorno = wait(&status);
        wprintf(L"Valor: " cor_ciano "%d" cor_branca, WEXITSTATUS(status));
    }
    // FILHO vai enviar um valor aleatório
    else
    {
        // Processo: FILHO
        srand(time(NULL));
        int valorGerado = rand() % 99;
        wprintf(L"\nvalorGerado: %d\n", valorGerado);
        return (valorGerado);
    }

    // Criando 10 threads
    for (long i = 0; i < 10; i++)
    {   
        // flag = pthread_create(thread[i], NULL, funcao, (void *)i);
    }

    wprintf(L"valorGlobal: " cor_verde "%lf" cor_branca, valorGlobal);

    traco(2);
    return 0;
}