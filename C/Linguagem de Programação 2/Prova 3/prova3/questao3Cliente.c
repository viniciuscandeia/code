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

        wprintf(corAzul L"[C]" corBranca " >> Palavra : " corBranca);
        limparBuffer();
        wscanf(L" %80[^\n]", buffer);
        limparBuffer();
        
        sprintf(buffer, "%s", buffer);
        resultado = write(meuSocket, buffer, strlen(buffer));

        if (strncmp("BYEBYE", buffer, 6) == 0){
            break;
        }

        if (strncmp("SHUTDOWN", buffer, 8) == 0)
        {
            exit(0);
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