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

void *funcaoCliente(void *valor)
{
    int resultado;
    int numero;

    int meuClienteFuncao = (int)valor;

    char *mensagemInicial = "Bem-Vindo! \n";
    resultado = write(meuClienteFuncao, mensagemInicial, strlen(mensagemInicial));

    while (true)
    {
        char buffer[TAMANHO_MENSAGEM];

        bzero(&buffer, sizeof(buffer));

        // & Recebendo o comando
        resultado = recv(meuClienteFuncao, buffer, TAMANHO_MENSAGEM, 0);
        wprintf(corAzul L"[C]" corBranca " >> Comando : " corAzul "%s \n", buffer);

        char mensagemServidor[TAMANHO_MENSAGEM];
        bzero(&mensagemServidor, strlen(mensagemServidor));

        if (strncmp("BCKWRD", buffer, 6) == 0)
        {
            for (int i = 7; i < strlen(buffer); i++){
                mensagemServidor[strlen(mensagemServidor)] = buffer[strlen(buffer)- 1 - strlen(mensagemServidor)];
            }
            sprintf(mensagemServidor, "%s \n", mensagemServidor);
            wprintf(L"%s \n", mensagemServidor);
        }
        else if (strncmp("RNDNUM", buffer, 6) == 0)
        {
            srand(time(NULL) ^ (getpid() << 16));
            numero = rand() % 1000;
            sprintf(mensagemServidor, "%d \n", numero);
        }
        else if (strncmp("FINISH", buffer, 6) == 0)
        {
            exit(0);
        }
        else
        {
            sprintf(mensagemServidor, "ERROR \n");
        }

        resultado = write(meuClienteFuncao, mensagemServidor, strlen(mensagemServidor));

        if (resultado > 0)
        {
            wprintf(corVerde L"[S]" corBranca " >> %s", mensagemServidor);
        }

        traco(1);
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