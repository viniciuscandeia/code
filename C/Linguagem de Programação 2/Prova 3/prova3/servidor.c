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
int soma = 0;

/*
    1 : Faça um servidor que:
        - Exista garantia de entrega entre as informações e o estabelecimento de conexão.
        - Atender até 5 clientes simultâneos.
        - O servidor receberá do cliente um número inteiro e devolverá seu dobro.
        - Um monitor realizará a soma de todos os valores recebidos e exibirá no terminal do servidor.
        - Quando o servidor receber 0 (zero), ele deve ser finalizado.
*/

int somarRetornos(int valor){
    pthread_mutex_lock(&travaSoma);
    soma += valor;
    pthread_mutex_unlock(&travaSoma);
    return soma;
}

void *funcaoCliente(void *valor)
{
    int resultado;
    int numero;

    int meuClienteFuncao = (int)valor;

    while (true)
    {
        char buffer[TAMANHO_MENSAGEM];
        resultado = recv(meuClienteFuncao, buffer, TAMANHO_MENSAGEM, 0);

        numero = atoi(buffer);
        numero *= 2;
        char *mensagemServidor = (char *) malloc (sizeof(int) * numero);
        sprintf(mensagemServidor, "%d \n", numero);

        if (resultado > 0)
        {
            if (numero == 0)
            {
                contadorClientes -= 1;
                close(meuClienteFuncao);
                free(mensagemServidor);
                wprintf(corAmarela L"Programa finalizado!" corBranca);
                traco(2);
                exit(0);
            }

            wprintf(corAzul L"[C]" corBranca " >> %s", buffer);
        }

        wprintf(corMagenta L"[S]" corBranca " >> %s", mensagemServidor);

        resultado = write(meuClienteFuncao, mensagemServidor, strlen(mensagemServidor));

        wprintf(L"\n[Soma: " corVerde "%d" corBranca "]", somarRetornos(numero / 2));
        traco(2);

        free(mensagemServidor);
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