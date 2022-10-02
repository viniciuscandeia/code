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
    (Questão 3 - 4 pontos + 1) Faça um programa em C/C++ que atue como um servidor de
    verificação de palíndromos. O servidor deverá aceitar e tratar até 6 conexões
    simultâneas de clientes; ao receber uma nova conexão, o servidor deverá dedicar
    uma thread a ela, para sua correta manipulação. O servidor enviará uma string
    de boas vindas para cada nova conexão (“BEMVINDO”), e deverá exibir o endereço
    do novo cliente conectado no terminal local. Os clientes poderão enviar uma
    quantidade arbitrária de strings com até 10 caracteres para o servidor, que
    deverá responder com “PALINDROMO=TRUE” caso a stringc ontenha um palíndromo e
    com “PALINDROMO=FALSE” caso a string não contenha um palíndromo.

    Palíndromos são frases ou palavras que podem ser lidas, indiferentemente, da
    esquerda para a direita, conforme o sentido habitual da leitura, ou da direita
    para a esquerda, sem que haja mudança da sua significação (exemplos depalíndromos
    com 6 letras: “AAAAAA”, “ABAABA”, “ABCCBA”, “MUSSUM”). Caso o cliente insira a
    string “BYEBYE” sua conexão deverá ser finalizada. O servidor  deverá tratar
    conexões indefinidamente, até que algum cliente insira a string “SHUTDOWN”, aí
    então o servidor deverá serfinalizado.A implementação deverá ser feita em C/C++
    utilizando a biblioteca Pthreads ou as threads STD (C++11) e  biblioteca sockets.h
    (ou winsock.h). A saída do seu programa deve ser bem planejada, de forma a mostrar
    o que está acontecendo em cada momento relevante. Para testes do servidor, usar
    netcat (nc) ou telnet para o lado do cliente.
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
        char bufferTemp[TAMANHO_MENSAGEM];

        bzero(&buffer, sizeof(buffer));
        bzero(&bufferTemp, sizeof(bufferTemp));

        // & Recebendo a palavra
        resultado = recv(meuClienteFuncao, buffer, TAMANHO_MENSAGEM, 0);
        wprintf(corAzul L"[C]" corBranca " >> Palavra : " corAzul "%s \n", buffer);

        for (int i = 0; i < strlen(buffer); i++){
            if (buffer[i] == ' '){
                continue;
            }
            bufferTemp[strlen(bufferTemp)] = buffer[i];
        }

        char mensagemServidor[TAMANHO_MENSAGEM];
        bzero(&mensagemServidor, strlen(mensagemServidor));

        for (int i = 0; i < strlen(bufferTemp); i++)
        {
            mensagemServidor[strlen(mensagemServidor)] = bufferTemp[strlen(bufferTemp) - 1 - i];
        }

        if (strncmp(bufferTemp, mensagemServidor, strlen(bufferTemp)) == 0){
            sprintf(mensagemServidor, "Palíndromo : TRUE \n");
        }
        else {
            sprintf(mensagemServidor, "Palíndromo : FALSE \n");
        }
        wprintf(L"%s \n", mensagemServidor);

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