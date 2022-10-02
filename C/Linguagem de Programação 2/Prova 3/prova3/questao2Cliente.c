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
    (Questão 2 - 5 pontos) Faça um programa em C/C++ que implemente um servidor
    que atenda os requisitos listados a seguir.

    1) Receba até 5 conexões simultâneas de clientes na porta 8600 TCP;

    2) Cada cliente recebe uma string de boas vindas ao se conectar ao
    servidor (ex. string “WELCOME”);

    3) O servidor tratará strings enviadas pelos clientes como comandos, e
    retornára o resultado como descrito a seguir. Os seguintes comandos
    devem ser suportados:

        a) BCKWRD <STRING>\n fará o servidor retornar o contrário
        da <string> recebida pelos clientes (ex. Caso receba “ABCD”
        deverá retornar “DCBA”);

        b) RNDNUM\n o servidor irá gerar e retornar um valor aleatório
        entre 0 e 1000;

        c) FINISH\n fará o servidor finalizar a conexão com o cliente;

        d) Comandos não reconhecidos deverão fazer o servidor retornar
        "ERROR" para os clientes.

    Comente o código explicando a diferença entre os papéis de cliente e servidor,
    ressaltando quais chamadas feitas no código são necessárias no contexto
    específico do protocolo TCP. Teste o servidor com múltiplos clientes, usando
    instâncias de telnet ou nc (netcat).
*/

void funcaoCliente(int meuSocket)
{
    char buffer[TAMANHO_MENSAGEM];
    bzero(&buffer, sizeof(buffer));

    int resultado;

    resultado = recv(meuSocket, buffer, TAMANHO_MENSAGEM, 0);
    wprintf(corMagenta L"[S]" corBranca " >> %s \n", buffer);

    while (true)
    {

        bzero(&buffer, sizeof(buffer));

        wprintf(corVerde L"[C]" corBranca " >> Comando : BCKWRD <STRING> \n" corBranca);
        wprintf(corVerde L"[C]" corBranca " >> Comando : RNDNUM \n" corBranca);
        wprintf(corVerde L"[C]" corBranca " >> Comando : FINISH \n\n" corBranca);
        wprintf(corAzul L"[C]" corBranca " >> Comando : " corBranca);
        limparBuffer();
        wscanf(L" %80[^\n]", buffer);
        limparBuffer();
        
        sprintf(buffer, "%s", buffer);
        resultado = write(meuSocket, buffer, strlen(buffer));

        if (strncmp("FINISH", buffer, 6) == 0){
            break;
        }

        bzero(&buffer, sizeof(buffer));
        resultado = recv(meuSocket, buffer, TAMANHO_MENSAGEM, 0);
        wprintf(corMagenta L"[S]" corBranca " >> %s ", buffer);

        traco(1);

        sleep(1);
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