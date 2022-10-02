/* 
    Aluno: Vinicius Candeia Pereira Vieira
    Matrícula: 20200009783
*/

// Questão
/*
    Faça um programa em C/C++ que simula uma corrida de lebres, usando threads e
    processos. O programa deverá receber 3 parâmetros na sua execução:
    - se usará processos ou threads;
    - quantas instâncias (lebres) serão criadas para a corrida;
    - e um valor inteiro, que representa o tamanho da pista da corrida em metros.

    Exemplo de execução:

        $ ./corrida -t 5 1000 (5 lebres/threads, pista de 1000m)
        lebre 0 saltou 30cm (total: 30)
        lebre 2 saltou 42cm (total: 42)
        ...
        lebre 2 saltou 31cm (total: 1002)
        lebre 2 venceu!

        $ ./corrida -p 10 500 (10 lebres/processos, pista de 500m)
        lebre 1 saltou 20cm (total: 20)
        lebre 0 saltou 43cm (total: 43)
        ...
        lebre 3 saltou 44cm (total: 520)
        lebre 3 venceu!

    Os processos / threads executarão a função que representa as lebres nessa
    corrida fictícia; a função que receberá dois parâmetros: um valor inteiro que
    identifique a lebre (seu índice) e um valor inteiro que represente a distância
    máxima do salto dessa lebre em cm. A função então simulará a corrida de uma
    lebre através de um loop onde cada iteração é um 'salto', que acontece a partir
    da geração de um valor aleatório entre 10 e o valor do salto máximo definido
    para aquela instância de "lebre" (considerando valores expressos em cm).

    Faça as lebres "correrem" nessa "pista" com o tamanho definido na execução do
    programa. Para cada vez que a função de cada processo/thread (lebre) executar
    a geração de valores aleatórios uma soma de todos os saltos deverá ser
    armazenada em uma variável com o quanto a lebre já percorreu da pista (uma
    variável int no escopo da função da lebre). A função permanece no loop,
    "saltando", até que o valor acumulado seja igual ou superior ao tamanho da
    pista.

    A cada "salto" (iteração realizada pela função associada ao processo ou a
    thread), deverá ser exibida uma mensagem contendo a distância do salto
    efetuado e qual distância total percorrida (dormindo 1s - função sleep - até
    que dê outro salto). A primeira 'lebre' (thread ou processo) que finalizar sua
    função (ou seja, tenha a variável que represente o quanto a lebre já percorreu
    com valor maior ou igual ao tamanho da pista) deverá exibir uma mensagem onde
    se declara vencedora e o programa deverá ser finalizado.
*/

// Alterações pariculares que fiz:
/* 
    1 : Tanto a função para as threads, como a função para os processos estão
        recebendo um único parâmetro
    2 : O parâmetro recebido é uma struct contendo 3 variáveis:
            1 ) O índice da lebre
            2 ) O salto máximo que a lebre pode dar
            3 ) O tamanho da pista -> como a lebre saberia se ganhou se não sabe
                                      onde termina a pista?
    3 : O salto e o tamanho da pista estão em centímetros.
*/

// Dúvidas que tive:
/*  
    1 : O salto máximo de cada coelho é algo fixo? Ou seria necessário
        gerar um valor aleatório?
        Fiz como valor fixo.
*/

#include "aditivos.h"

#include <locale.h>
#include <math.h>
#include <pthread.h>
#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <time.h>
#include <unistd.h>
#include <wchar.h>

bool threadFim = false;
bool processoFim = false;

// Como só é possível passar 1 valor no pthread_create, fiz uso de struct para
// passar todos os valores desejados.
typedef struct info
{
    int indice;
    int saltoMaximo;
    int tamanPista;
} infoValores;

void *funcaoThread(void *valor)
{

    // Cast para facilitar a nossa vida
    infoValores *vetor = (infoValores *)valor;
    int distPerc = 0;

    srand(time(NULL));

    // While verdadeiro até que a distância percorrida seja >= ao tamanho da pista,
    // mostrando o quando a lebre pulou e o total.
    while (true)
    {
        // Gerando o valor do solto e somando ao total já percorrido
        int salto = rand() % (vetor->saltoMaximo - 10) + 10;
        distPerc += salto;
        printf(cor_amarela "Lebre %d" cor_branca " | ", vetor->indice);
        printf(cor_azul "saltou %d" cor_branca " | ", salto);
        printf(cor_magenta "total %d\n\n" cor_branca, distPerc);

        // Condição de parada do while. (poderia ser colocado no próprio while).
        if (distPerc >= vetor->tamanPista)
        {
            break;
        }

        // Sleep que a questão pediu.
        sleep(1);
    }

    // Manipulação para retornar o valor sem aparecer warning.
    int *indice = malloc(sizeof(vetor->indice)); // Quando será liberado esse malloc?
    *indice = vetor->indice;

    // Liberando a memória da struct passada.
    free(valor);

    // Se alguma thread chegar nesse ponto, ela mudará o valor de threadFim para "true",
    // originalmente, como "false". Maneira encontrada para determinar qual a 1° thread
    // que finalizou.
    // Qualquer outra thread retornará o valor "-1", e no main, já foi colocado uma
    // condição para verificar isso.
    if (!(threadFim))
    {
        threadFim = true;
        return indice;
    }
    else
    {
        return NULL;
    }
}

int funcaoProcesso(void *valor)
{

    // Cast para facilitar a nossa vida
    infoValores *vetor = (infoValores *)valor;
    int distPerc = 0;

    // Como os processos foram criados ao mesmo tempo, a semente que ambos
    // compartilham é a mesma, já que o retorno de time é em segundos, por isso, 
    // utilizamos uma pequena modificação para mudar o valor da semente para cada
    // processo.
    srand(time(NULL) ^ (getpid()<<16));

    // While verdadeiro até que a distância percorrida seja >= ao tamanho da pista,
    // mostrando o quando a lebre pulou e o total.
    while (true)
    {

        // Gerando o valor do salto e somando ao total já percorrido.
        int salto = rand() % (vetor->saltoMaximo - 10) + 10;
        distPerc += salto;

        // Quis colocar cores diferentes para identificar mais facilmente cada lebre,
        // porque, ao executar os processos simultâneos, a saída da execução fica 
        // toda bagunçada.
        if (vetor->indice == 0)
        {
            printf(cor_amarela "");
        }
        else if (vetor->indice == 1)
        {
            printf(cor_azul "");
        }
        else if (vetor->indice == 2)
        {
            printf(cor_magenta "");
        }
        else
        {
            printf(cor_verde "");
        }

        printf(" Lebre %d | saltou %d | total %d\n\n" cor_branca, vetor->indice, salto, distPerc);

        // Condição de parada do while. (poderia ser colocado no próprio while).
        if (distPerc >= vetor->tamanPista)
        {
            break;
        }

        // Sleep que a questão pediu.
        sleep(1);
    }

    return vetor->indice;
}

int main(int quanArg, char *listaArg[])
{

    inicioCodigo();

    // For só para mostrar quais argumentos foram passados.
    for (int i = 1; i < quanArg; i++)
    {
        printf("%d | Parâmetro : " cor_verde "%s\n" cor_branca, i, listaArg[i]);
    }

    traco(1);

    /* Usando threads para realizar a corrida. */
    if (strcmp(listaArg[1], "-t") == 0)
    {
        printf("Método: " cor_ciano "THREADS\n\n" cor_branca);

        // Criando "número de lebres" threads.
        pthread_t thread[atoi(listaArg[2])];
        int flag;

        // For que irá passar os valores para um vetor da struct e que criará todas as threads.
        for (int i = 0; i < atoi(listaArg[2]); i++)
        {
            infoValores *vetor = malloc(sizeof(infoValores));
            vetor->indice = i;
            vetor->saltoMaximo = 20;
            vetor->tamanPista = atoi(listaArg[3]);

            flag = pthread_create(&thread[i], NULL, funcaoThread, (void *)vetor);
        }

        // For que pegará os retornos das threads.
        for (int i = 0; i < atoi(listaArg[2]); i++)
        {
            void *retorno;
            flag = pthread_join(thread[i], &retorno);
            int *valorRetorno = (int *)retorno;

            // Condição citada no processoThread, como apenas a 1° thread que terminou tem
            // um valor diferente de "-1", fica fácil identificar qual a lebre que ganhou.
            if (valorRetorno != NULL)
            {
                traco(0);
                printf("Lebre " cor_verde "%d" cor_branca " ganhou!", *valorRetorno);

                // Se já encontrou a lebre ganhadora, não precisa terminar o for.
                break;
            }
        }
    }

    /* Usando processos para realizar a corrida. */
    else if (strcmp(listaArg[1], "-p") == 0)
    {
        pid_t processoPID = getpid();
        int valorFork;
        int status;
        int retorno;

        printf("Método: " cor_ciano "-p\n\n" cor_branca);

        // For para criar todos os processos extras que simularão lebres.
        for (int i = 1; i <= atoi(listaArg[2]); i++)
        {
            // Processo: PAI
            if (processoPID == getpid())
            {
                valorFork = fork();

                // O fork retornará 0 no processo do filho.
                // O fork retornará o PID do filho no processo do pai.
                // É usando esse conhecimento que o filho será manipulado.
                if (valorFork == 0)
                {
                    infoValores *vetor = malloc(sizeof(infoValores));
                    vetor->indice = i - 1;
                    vetor->saltoMaximo = 20;
                    vetor->tamanPista = atoi(listaArg[3]);

                    retorno = funcaoProcesso((void *)vetor);
                    free(vetor);
                }
            }
        }

        // Método utilizado para retornar apenas o 1° processo que terminou.
        if (processoPID != getpid())
        {
            if (!(processoFim))
            {
                processoFim = true;
                return retorno;
            }
        }

        // O PAI vai esperar o 1° filho terminar e irá matar o restante.
        if (processoPID = getpid())
        {
            wait(&status);
            kill(1, SIGKILL);

            sleep(2);
            traco(0);

            int retornoFilho = WEXITSTATUS(status);
            printf("Lebre " cor_verde "%d" cor_branca " ganhou!", retornoFilho);
        }
    }

    /* Se o argumento passado não for "-t" ou "-p" */
    else if (strcmp(listaArg[1], "-t") != 0 && strcmp(listaArg[1], "-p") != 0){
        printf(cor_vermelha "Argumento inválido." cor_branca);
    }

    traco(2);
    return 0;
}