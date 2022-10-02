/*
    Disciplina: Linguagem de Programação II
    Professor: Carlos Eduardo
    Aluno: Vinicius Candeia Pereira Vieira
    Matrícula: 20200009783
*/

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

/*
    (Questão 2 - 4 pontos) Faça um programa em C/C++ que possa ser usado como
    cliente do servidor implementado na questão anterior. Comente o código
    explicando a diferença entre os papéis de cliente e servidor, ressaltando quais
    chamadas feitas no código são necessárias no contexto específico do protocolo TCP.
*/

/*
    Servidor : É a máquina na qual foi configurada em uma rede, em um endereço e porta, para oferecer algum tipo de serviço. 
               No caso específico da questão 1, o servidor ficava responsável por receber pedidos do cliente, realizar algumas 
               operações e devolver o que foi solicitado pelo cliente. 
    Cliente  : Já o cliente, é a máquina que se conecta do outro lado, por meio do endereço e da porta, que foi configurada 
               para utilizar o serviço que é oferecido pelo servidor.
*/

// Função que vai controlar o que o socket do cliente fará.
void funcaoCliente(int meuSocket)
{
    char buffer[TAMANHO_MENSAGEM];
    bzero(&buffer, sizeof(buffer));

    int resultado;

    // Recebendo a mensagem de boas vindas
    resultado = recv(meuSocket, buffer, TAMANHO_MENSAGEM, 0);
    wprintf(corMagenta L"[S]" corBranca " >> %s \n", buffer);

    // Um loop verdadeiro que será executado até o socket do cliente se fechar ou até o servidor desligar.
    while (true)
    {

        bzero(&buffer, sizeof(buffer));

        // Mostrando os comandos disponíveis
        wprintf(corVerde L"[C]" corBranca " >> Comando : RNDNUM \n" corBranca);
        wprintf(corVerde L"[C]" corBranca " >> Comando : CRTIME \n" corBranca);
        wprintf(corVerde L"[C]" corBranca " >> Comando : FINISH \n" corBranca);
        wprintf(corVerde L"[C]" corBranca " >> Comando : SHTDWN \n\n" corBranca);

        // Pegando qual comando o cliente quer.
        wprintf(corAzul L"[C]" corBranca " >> Comando : " corBranca);
        limparBuffer();
        wscanf(L" %80[^\n]", buffer);
        limparBuffer();
        
        // Enviando ao servidor o comando do cliente.
        sprintf(buffer, "%s", buffer);
        resultado = write(meuSocket, buffer, strlen(buffer));

        // Condições de parada do cliente.
        if (strncmp("FINISH", buffer, 6) == 0){
            
            break;
        }

        if (strncmp("SHTDWN", buffer, 6) == 0)
        {
            break;
        }

        // Recebendo o retorno do comando enviado.
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
    // É utilizado o "SOCK_STREAM" para protocolos TCP
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

    // Função responsável por controlar o socket do cliente.
    funcaoCliente(meuSocket);

    // Fechando o socket.
    close(meuSocket);

    traco(1);
    return 0;
}