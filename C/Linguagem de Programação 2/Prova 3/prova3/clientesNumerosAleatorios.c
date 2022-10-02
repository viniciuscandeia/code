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

/*
    5 : Faça um servidor que:
        - Exista garantia de entrega entre as informações e o estabelecimento de conexão
        - Receba um número aleatório e envie outro número aleatório.
        - Esse processo irá se repetir até que saia o número 0.
        - Quando o servidor receber 0 (zero), ele deve ser finalizado.
*/

void funcaoCliente(int meuSocket)
{
    char buffer[TAMANHO_MENSAGEM];
    int numero;

    int resultado;

    while (true)
    {

        bzero(&buffer, sizeof(buffer));

        sleep(1);
        srand(time(NULL) ^ (getpid() << 16));
        int numero = rand() % 10;

        wprintf(corAzul L"[C]" corBranca " >> %d \n" corBranca, numero);
        sprintf(buffer, "%d", numero);
        resultado = write(meuSocket, buffer, strlen(buffer));

        if (strncmp("0", buffer, 1) == 0)
        {
            traco(1);
            wprintf(corAmarela L"Programa finalizado!" corBranca);
            traco(2);
            break;
        }

        bzero(&buffer, sizeof(buffer));
        resultado = recv(meuSocket, buffer, TAMANHO_MENSAGEM, 0);
        wprintf(corMagenta L"[S]" corBranca " >> %s ", buffer);

        traco(1);

    }
}

int main()
{

    inicioCodigo();

    int meuSocket;
    int portaServidor;
    int resultado;

    struct sockaddr_in informacaoServidor;

    // | Pegando a porta
    wprintf(L"Porta: >> " corAmarela);
    wscanf(L"%d", &portaServidor);
    // srand(time(NULL));
    // portaServidor = rand() % 10 + 7770;
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

    // | Definindo as características do socket
    informacaoServidor.sin_family = AF_INET;
    informacaoServidor.sin_addr.s_addr = inet_addr("127.0.0.1");
    informacaoServidor.sin_port = htons(portaServidor);

    // | Conexão ao servidor (Bind)
    resultado = connect(meuSocket, &informacaoServidor, sizeof(informacaoServidor));

    if (resultado == -1)
    {
        wprintf(corVermelha L"Não conectado!" corBranca);
        traco(2);
        exit(0);
    }

    wprintf(corVerde L"Conectado!" corBranca "\n");
    wprintf(L"Porta: " corAmarela "%d" corBranca "\n", portaServidor);
    traco(1);

    funcaoCliente(meuSocket);

    close(meuSocket);

    traco(2);
    return 0;
}