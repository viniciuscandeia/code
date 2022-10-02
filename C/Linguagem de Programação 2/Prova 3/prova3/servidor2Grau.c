#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
#include <locale.h>
#include <sys/types.h>
#include <time.h>
#include <wchar.h>
#include <string.h>

#include "aditivos.h"

// * Bibliotecas Linux
#include <unistd.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netdb.h>
#include <netinet/in.h>
#include <pthread.h>
#include <arpa/inet.h>

#define QUANTIDADE_CLIENTES 5
#define TAMANHO_MENSAGEM 100

pthread_mutex_t travaSoma = PTHREAD_MUTEX_INITIALIZER;

int contadorClientes = 0;

/*
    3 : Faça um servidor que:
        - Receba os valores de A, B e C e devolva as raízes reais de uma Equação do 2° Grau.
        - Quando o servidor receber "exit", ele deve ser finalizado.
*/

void *funcaoCliente(void *valor)
{
    int resultado;
    int numero = (int)valor - 4;

    int numeroA;
    int numeroB;
    int numeroC;

    int delta;
    float x1, x2, x;

    int meuClienteFuncao = (int)valor;

    while (true)
    {
        char buffer[TAMANHO_MENSAGEM];

        bzero(&buffer, sizeof(buffer));

        // & Recebendo A
        resultado = recv(meuClienteFuncao, buffer, TAMANHO_MENSAGEM, 0);
        numeroA = atoi(buffer);

        if (resultado > 0)
        {
            if (strncmp("exit", buffer, 4) == 0)
            {
                close(meuClienteFuncao);
                wprintf(corAmarela L"Programa finalizado!" corBranca);
                traco(2);
                exit(0);
            }

            wprintf(corAzul L"[C]" corBranca " : A : " corAzul "%d \n", numeroA);
        }

        // & Recebendo B
        resultado = recv(meuClienteFuncao, buffer, TAMANHO_MENSAGEM, 0);
        numeroB = atoi(buffer);

        if (resultado > 0)
        {
            if (strncmp("exit", buffer, 4) == 0)
            {
                close(meuClienteFuncao);
                wprintf(corAmarela L"Programa finalizado!" corBranca);
                traco(2);
                exit(0);
            }

            wprintf(corAzul L"[C]" corBranca " : B : " corAzul "%d \n", numeroB);
        }

        // & Recebendo C
        resultado = recv(meuClienteFuncao, buffer, TAMANHO_MENSAGEM, 0);
        numeroC = atoi(buffer);

        if (resultado > 0)
        {
            if (strncmp("exit", buffer, 4) == 0)
            {
                close(meuClienteFuncao);
                wprintf(corAmarela L"Programa finalizado!" corBranca);
                traco(2);
                exit(0);
            }

            wprintf(corAzul L"[C]" corBranca " : C : " corAzul "%d \n", numeroC);
        }

        char mensagemServidor[TAMANHO_MENSAGEM];
        sprintf(mensagemServidor, "(%d)x2 +- (%d)x +- (%d) = 0 \n", numeroA, numeroB, numeroC);
        wprintf(corVerde L"\n[S]" corBranca " >> %s", mensagemServidor);
        // resultado = write(meuClienteFuncao, mensagemServidor, strlen(mensagemServidor));

        mensagemServidor[0] = '\0';
        sprintf(mensagemServidor, "DELTA = (%d)2 - 4 * (%d) * (%d) \n", numeroB, numeroA, numeroC);
        wprintf(corVerde L"[S]" corBranca " >> %s", mensagemServidor);
        // resultado = write(meuClienteFuncao, mensagemServidor, strlen(mensagemServidor));

        delta = (float) pow(numeroB, 2) - 4 * numeroA * numeroC;
        mensagemServidor[0] = '\0';
        sprintf(mensagemServidor, "DELTA = (%d) \n", delta);
        wprintf(corVerde L"[S]" corBranca " >> %s", mensagemServidor);
        // resultado = write(meuClienteFuncao, mensagemServidor, strlen(mensagemServidor));

        if (delta > 0)
        {
            x1 = (float) (-(numeroB) + sqrt(delta)) / (2 * numeroA);
            x2 = (float) (-(numeroB)-sqrt(delta)) / (2 * numeroA);

            mensagemServidor[0] = '\0';
            sprintf(mensagemServidor, "X1 = (- (%d) + sqrt(%d)) / (2 * (%d)) \n", numeroB, delta, numeroA);
            wprintf(corVerde L"[S]" corBranca " >> %s", mensagemServidor);

            mensagemServidor[0] = '\0';
            sprintf(mensagemServidor, "X1 = (%f) \n", x1);
            wprintf(corVerde L"[S]" corBranca " >> %s", mensagemServidor);

            mensagemServidor[0] = '\0';
            sprintf(mensagemServidor, "X2 = (- (%d) - sqrt(%d)) / (2 * (%d)) \n", numeroB, delta, numeroA);
            wprintf(corVerde L"[S]" corBranca " >> %s", mensagemServidor);

            mensagemServidor[0] = '\0';
            sprintf(mensagemServidor, "X2 = (%f) \n \n", x2);
            wprintf(corVerde L"[S]" corBranca " >> %s", mensagemServidor);

            mensagemServidor[0] = '\0';
            sprintf(mensagemServidor, "X1 = (%f) || X2 = (%f) \n", x1, x2);
            wprintf(corMagenta L"[S]" corBranca " >> %s", mensagemServidor);
            resultado = write(meuClienteFuncao, mensagemServidor, strlen(mensagemServidor));
        }
        else if (delta == 0)
        {
            x = (float) (-(numeroB) + sqrt(delta)) / (2 * numeroA);

            mensagemServidor[0] = '\0';
            sprintf(mensagemServidor, "X = (- (%d) + sqrt(%d)) / (2 * (%d)) \n", numeroB, delta, numeroA);
            wprintf(corVerde L"[S]" corBranca " >> %s", mensagemServidor);

            mensagemServidor[0] = '\0';
            sprintf(mensagemServidor, "X = (%f) \n \n", x);
            wprintf(corVerde L"[S]" corBranca " >> %s", mensagemServidor);

            mensagemServidor[0] = '\0';
            sprintf(mensagemServidor, "X = (%d) \n", x);
            wprintf(corMagenta L"[S]" corBranca " >> %s", mensagemServidor);
            resultado = write(meuClienteFuncao, mensagemServidor, strlen(mensagemServidor));
        }
        else
        {
            mensagemServidor[0] = '\0';
            sprintf(mensagemServidor, "X = não pertence aos REAIS. \n", x);
            wprintf(corMagenta L"\n[S]" corBranca " >> %s", mensagemServidor);
            resultado = write(meuClienteFuncao, mensagemServidor, strlen(mensagemServidor));
        }

        // resultado = write(meuClienteFuncao, mensagemServidor, strlen(mensagemServidor));

        // wprintf(L"\n[(%d)x2 +- (%d)x +- (%d) = 0 : " corVerde "%s" corBranca ", " corVerde "%d" corBranca "]", numero, pessoas[numero].nome, pessoas[numero].idade);
        traco(1);

        mensagemServidor[0] = '\0';
    }
}

int main()
{

    inicioCodigo();

    int meuSocket;
    int meuCliente[QUANTIDADE_CLIENTES];
    int portaServidor;
    int resultado;
    int tamanhoCliente[QUANTIDADE_CLIENTES];
    int indexCliente = 0;

    struct sockaddr_in informacaoCliente[QUANTIDADE_CLIENTES];
    struct sockaddr_in informacaoServidor;

    char mensagemServidor[TAMANHO_MENSAGEM];
    char mensagemRecebida[TAMANHO_MENSAGEM];

    pthread_t pthreadCliente[QUANTIDADE_CLIENTES];

    // | Pegando a porta
    wprintf(L"Porta: >> " corAmarela);
    wscanf(L"%d", &portaServidor);
    srand(time(NULL));
    portaServidor = rand() % 10 + 7770;
    traco(1);

    // | Criando o socket (TCP)
    meuSocket = socket(PF_INET, SOCK_STREAM, 0);

    if (meuSocket == -1)
    {
        wprintf(corVermelha L"Socket não criado!" corBranca);
        traco(2);
        exit(0);
    }

    // | Limpar memória da struct
    bzero(&informacaoServidor, sizeof(informacaoServidor));
    for (int i = 0; i < QUANTIDADE_CLIENTES; i++)
    {
        bzero(&informacaoCliente[i], sizeof(informacaoCliente[i]));
    }

    // | Definindo as características do socket
    informacaoServidor.sin_family = AF_INET;
    informacaoServidor.sin_addr.s_addr = htonl(INADDR_ANY);
    informacaoServidor.sin_port = htons(portaServidor);

    // | Conexão ao servidor (Bind)
    resultado = bind(meuSocket, &informacaoServidor, sizeof(informacaoServidor));

    if (resultado == -1)
    {
        wprintf(corVermelha L"Não conectado!" corBranca);
        traco(2);
        exit(0);
    }

    wprintf(corVerde L"Aguardando!" corBranca "\n");
    wprintf(L"Porta: " corAmarela "%d" corBranca "\n", portaServidor);
    traco(1);

    // | Listen
    resultado = listen(meuSocket, QUANTIDADE_CLIENTES);

    if (resultado == -1)
    {
        wprintf(corVermelha L"listen() falhou!" corBranca);
        traco(2);
        exit(0);
    }

    wprintf(L"... \n");

    // | Accept
    while (meuCliente[indexCliente] = accept(meuSocket,
                                             (struct sockaddr *)&informacaoCliente[indexCliente],
                                             &tamanhoCliente[indexCliente]))
    {
        wprintf(corVerde L"Conectado!" corBranca "\n");
        char *enderecoIPCliente = inet_ntoa(informacaoCliente[contadorClientes].sin_addr);
        wprintf(L"Endereço: " corAmarela "%s" corBranca, enderecoIPCliente);
        traco(2);

        pthread_create(&pthreadCliente[indexCliente], NULL, funcaoCliente, (void *)meuCliente[indexCliente]);

        if (meuCliente[contadorClientes] == -1)
        {
            wprintf(corVermelha L"accept() falhou!" corBranca);
            traco(2);
            exit(0);
        }

        indexCliente += 1;
        contadorClientes += 1;
        indexCliente = indexCliente % 10;

        wprintf(L"Conectados: " corAmarela "%d" corBranca, indexCliente);
        traco(2);
    }

    traco(2);
    return 0;
}