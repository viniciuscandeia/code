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

// * Visão por cima
/*
    socket :    Cria um socket - precisa especificiar o protocolo (UDP ou TCP).
    bind :      Associa o socket criado a uma identificação, constituída por enderenço IP da máquina
                onde reside o servidor e número de porta associado à aplicação.
    close :     Fecha o socket.
    listen :    Habilita o socket a aceitar pedidos de conexão, tornando-o um socket de servidor (TCP)
    accept :    Recebe um pedido de conexão por parte da aplicação cliente (bloqueante).
    connect :   Cria a conexão entre o socket do cliente com o socket do servidor cujo endereço está especificado
                nos parâmetros. A conexão fica bloqueada até o socket obter uma resposta do servidor.
    read :      Ler dados de um socket TCP.
    recvfrom :  Ler dados de um socket UDP.
    write :     Envia dados a um socket TCP.
    sendto :    Envia dados a um socket UDP.
 */


// # Troca de mensagens simples.

#define TAMANHO_MENSAGEM 100

int main()
{

    inicioCodigo();

    int meuSocket;
    int portaServidor;
    int resultadoConexao;
    char hostServidor[TAMANHO_MENSAGEM];
    struct sockaddr_in enderecoServidor;
    struct sockaddr_in enderecoCliente;
    char mensagemServidor[TAMANHO_MENSAGEM];
    char mensagemRecebida[TAMANHO_MENSAGEM];

    // | Pegando o endereço e a porta
    wprintf(L"Endereço: >> " corAmarela);
    wscanf(L"%s", &hostServidor);
    hostServidor[0] = '\0';
    strcpy(hostServidor, "127.0.0.1");
    traco(1);
    wprintf(L"Porta: >> " corAmarela);
    wscanf(L"%d", &portaServidor);
    portaServidor = 7777;
    traco(1);

    // | Criando o socket (TCP) / (UDP)
    meuSocket = socket(PF_INET, SOCK_STREAM, 0);
    // meuSocket = socket(PF_INET, SOCK_DGRAM, 0);

    if (meuSocket == -1)
    {
        wprintf(corVermelha L"Socket não criado!" corBranca);
        traco(2);
        exit(0);
    }

    // | Limpar memória da struct
    bzero(&enderecoServidor, sizeof(enderecoServidor));

    // | Definindo as características do socket
    enderecoServidor.sin_family = AF_INET;
    enderecoServidor.sin_port = htons(portaServidor);
    inet_aton(hostServidor, &enderecoServidor.sin_addr);

    // | Conexão ao servidor
    resultadoConexao = connect(meuSocket, &enderecoServidor, sizeof(enderecoServidor));

    if (resultadoConexao == 0)
    {
        wprintf(corVerde L"Conectado!" corBranca "\n");
        wprintf(L"Endereço: " corAmarela "%s" corBranca "\n", hostServidor);
        wprintf(L"Porta: " corAmarela "%d" corBranca "\n", portaServidor);
        traco(1);
    }
    else
    {
        wprintf(corVermelha L"Não conectado!" corBranca);
        traco(2);
        exit(0);
    }

    // | Troca de inforamações
    while (true)
    {
        wprintf(corMagenta L"[S]" corBranca " >> ");
        wscanf(L" %80[^\n]" corBranca, &mensagemServidor);

        if (strcmp(mensagemServidor, "exit") == 0){
            close(meuSocket);
            traco(1);
            wprintf(corAmarela L"Fechando Socket!" corBranca);
            traco(2);
            exit(0);
        }

        sprintf(mensagemServidor, "%s \n", mensagemServidor);

        sendto(meuSocket, (void *)mensagemServidor, strlen(mensagemServidor), 0, (struct sockaddr_in *) &enderecoServidor, sizeof(enderecoServidor));
        recvfrom(meuSocket, &mensagemRecebida, TAMANHO_MENSAGEM, 0, &enderecoCliente, sizeof(enderecoCliente));

        wprintf(corAzul L"[C]" corBranca " >> %s", mensagemRecebida);

        traco(2);
    }

    traco(2);
    return 0;
}