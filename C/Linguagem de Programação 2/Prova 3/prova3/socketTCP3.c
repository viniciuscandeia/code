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

#define TAMANHO_MENSAGEM 100

int main()
{

    inicioCodigo();

    int meuSocket;
    int meuCliente;
    int portaServidor;
    int resultado;
    int *tamanhoCliente;
    struct sockaddr_in informacaoCliente;
    struct sockaddr_in informacaoServidor;
    char mensagemServidor[TAMANHO_MENSAGEM];
    char mensagemRecebida[TAMANHO_MENSAGEM];

    // | Pegando o endereço e a porta
    wprintf(L"Porta: >> " corAmarela);
    wscanf(L"%d", &portaServidor);
    srand(time(NULL));
    portaServidor = rand() % 10 + 7770;
    traco(1);

    // | Criando o socket (TCP) / (UDP)
    meuSocket = socket(PF_INET, SOCK_STREAM, 0);

    if (meuSocket == -1)
    {
        wprintf(corVermelha L"Socket não criado!" corBranca);
        traco(2);
        exit(0);
    }

    // | Limpar memória da struct
    bzero(&informacaoServidor, sizeof(informacaoServidor));
    bzero(&informacaoCliente, sizeof(informacaoCliente));

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
    resultado = listen(meuSocket, 5);

    if (resultado == -1)
    {
        wprintf(corVermelha L"listen() falhou!" corBranca);
        traco(2);
        exit(0);
    }

    wprintf(L"... \n");

    // | Accept
    meuCliente = accept(meuSocket, (struct sockaddr *)&informacaoCliente, &tamanhoCliente);

    if (meuCliente == -1)
    {
        wprintf(corVermelha L"accept() falhou!" corBranca);
        traco(2);
        exit(0);
    }

    wprintf(corVerde L"Conectado!" corBranca "\n");
    char *enderecoIPCliente = inet_ntoa(informacaoCliente.sin_addr);
    wprintf(L"Endereço: " corAmarela "%s" corBranca, enderecoIPCliente);
    traco(2);

    char *mensagemInicial = "Bem-Vindo! \n";
    write(meuCliente, mensagemInicial, strlen(mensagemInicial));

    // | Troca de informações
    while (true)
    {
        char *mensagemConversa = " >> ";
        write(meuCliente, mensagemConversa, strlen(mensagemConversa));

        char buffer[TAMANHO_MENSAGEM];
        resultado = recv(meuCliente, buffer, TAMANHO_MENSAGEM, 0);

        if (resultado > 0){
            wprintf(corAzul L"[C]" corBranca " >> %s", buffer);
        }

        wprintf(corMagenta L"[S]" corBranca " >> ");
        wscanf(L" %80[^\n]" corBranca, &mensagemServidor);

        if (strcmp(mensagemServidor, "exit") == 0)
        {
            close(meuCliente);
            traco(1);
            wprintf(corAmarela L"Fechando Cliente!" corBranca);
            traco(2);
            exit(0);
        }

        sprintf(mensagemServidor, "%s \n", mensagemServidor);

        resultado = write(meuCliente, mensagemServidor, strlen(mensagemServidor));

        traco(1);
    }

    traco(2);
    return 0;
}