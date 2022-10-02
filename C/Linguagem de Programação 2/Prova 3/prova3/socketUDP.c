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

// # Troca de mensagens simples.

#define TAMANHO_MENSAGEM 100

int main()
{

    inicioCodigo();

    int meuSocket;
    int minhaResposta;
    int portaServidor;
    int resultado;
    int tamanhoEndereco;
    int tamanhoLeitura;
    struct sockaddr_in enderecoServidor;
    struct sockaddr_in enderecoCliente;
    struct sockaddr_in enderecoResposta;
    char mensagemServidor[TAMANHO_MENSAGEM];
    char mensagemRecebida[TAMANHO_MENSAGEM];

    char dia[3], mes[3], ano[5];
    time_t agora = time(NULL);
    struct tm *t = localtime(&agora);
    sprintf(dia, "%02d", t->tm_mday, sizeof(dia));
    sprintf(mes, "%02d", t->tm_mon + 1, sizeof(mes));
    sprintf(ano, "%04d", t->tm_year + 1900, sizeof(ano));

    // | Pegando o endereço e a porta
    wprintf(L"Porta: >> " corAmarela);
    wscanf(L"%d", &portaServidor);
    srand(time(NULL));
    portaServidor = rand() % 10 + 7770;
    wprintf(L"Porta: " corAmarela "%d" corBranca "\n", portaServidor);
    traco(1);

    // | Criando o socket (TCP) / (UDP)
    // meuSocket = socket(PF_INET, SOCK_STREAM, 0);
    meuSocket = socket(PF_INET, SOCK_DGRAM, 0);

    if (meuSocket == -1) 
    {
        wprintf(corVermelha L"Socket não criado!" corBranca);
        traco(2);
        exit(0);
    }

    // | Limpar memória da struct
    bzero(&enderecoServidor, sizeof(enderecoServidor));


    // nc -u localhost (portaServidor)
    // | Definindo as características do socket
    enderecoServidor.sin_family = AF_INET;
    enderecoServidor.sin_addr.s_addr = htonl(INADDR_ANY);
    enderecoServidor.sin_port = htons(portaServidor);

    // | Conexão ao servidor (Bind)
    resultado = bind(meuSocket, &enderecoServidor, sizeof(enderecoServidor));

    if (resultado == -1)
    {
        wprintf(corVermelha L"Não conectado!" corBranca);
        traco(2);
        exit(0);
    }

    tamanhoEndereco = sizeof(enderecoCliente);

    // | Troca de informações
    while (true)
    {
        tamanhoLeitura = recvfrom(meuSocket, (char *) mensagemRecebida, TAMANHO_MENSAGEM, MSG_WAITALL, (struct sockaddr *) &enderecoCliente, &tamanhoEndereco);
        mensagemRecebida[tamanhoLeitura + 1] = "\0";
        wprintf(corAzul L"[C]" corBranca " >> %s", mensagemRecebida);

        if (strncmp("exit", mensagemRecebida, 4) == 0)
        {
            close(meuSocket);
            traco(1);
            wprintf(corAmarela L"Fechando Socket!" corBranca);
            traco(2);
            exit(0);
        }

        // nc -l -u -p (portaServidor + 1)
        enderecoResposta.sin_family = AF_INET;
        enderecoResposta.sin_addr.s_addr = htonl(INADDR_ANY);
        enderecoResposta.sin_port = htons(portaServidor + 1);

        sprintf(mensagemServidor, "%s / %s / %s", dia, mes, ano);

        minhaResposta = socket(AF_INET, SOCK_DGRAM, 0);
        sendto(minhaResposta, mensagemServidor, strlen(mensagemServidor), 0, (struct sockaddr *) &enderecoResposta, sizeof(enderecoResposta));

    }

    traco(2);
    return 0;
}