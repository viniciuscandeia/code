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
#include <semaphore.h>

#define QUANTIDADE_CLIENTES 8
#define TAMANHO_MENSAGEM 100

int contadorClientes = 0;

/*
    (Questão 1 - 10 pontos) Faça um programa em C/C++ que crie um servidor TCP que
    atenda os requisitos listados a seguir.

        1) Trate até 8 conexões simultâneas de clientes na porta 9900;

        2) Cada novo cliente deve receber uma string de boas vindas ao se conectar ao
        servidor (“WELCOME”);

        3) O servidor tratará strings enviadas pelos clientes como comandos, e
        retornára o resultado para eles de acordo com os comandos, como descrito a
        seguir. Os seguintes comandos devem ser suportados:

            a) "RNDNUM\n" - o servidor irá gerar e retornar um valor aleatório
                entre 0 e 1000;

            b) "CRTIME\n" - o servidor retornará a data e hora corrente;

            c) "FINISH\n" - o servidor finaliza a conexão do cliente;

            d) "SHTDWN\n" - o servidor é finalizado (fim do programa);

        4) O servidor deverá armazenar todas as solicitações realizadas pelos clientes
        em um arquivo de texto chamado "log.txt". O acesso de escrita e leitura a esse
        arquivo deverá ser feito através de um monitor.

    A saída do seu programa deve ser bem planejada, de forma a mostrar o que está
    acontecendo em cada momento relevante. Teste o servidor com múltiplos clientes,
    usando instâncias de telnet ou nc (netcat).
*/


// Monitor que será usado para controlar a manipulação do arquivo.
typedef struct monitor
{
    sem_t mutex;
} Monitor;

Monitor monitorArquivo;

// Função que vai criar ou adicionar ao arquivo "log.txt" o que o cliente mandou.
void funcaoArquivo(char *mensagem, int tamanhoMensagem)
{
    // Protocolo de entrada
    // sem_wait(&monitorArquivo.mutex);

    // Se o arquivo "log.txt" já existir, ele será aberto no modo "append"
    // Se o arquivo "log.txt" não existir, ele será aberto no modo "write"
    FILE *meuArquivo;
    if (meuArquivo = fopen("log.txt", "r")){
        fclose(meuArquivo);
        meuArquivo = fopen("log.txt", "a");
    } else {
        meuArquivo = fopen("log.txt", "w");
    }

    // Adicionando ao arquivo o comando que o cliente mandou.
    fprintf(meuArquivo, "%s", mensagem);

    // Fechando o arquivo.
    fclose(meuArquivo);

    // Protocolo de saída
    // sem_post(&monitorArquivo.mutex);
}

// Função responsável por controlar, de maneira independente, o que cada cliente manda e recebe.
void *funcaoCliente(void *valor)
{
    int resultado;
    int numero;

    int meuClienteFuncao = (int)valor;

    // Enviando ao usuário uma mensagem de boas vindas.
    char *mensagemInicial = "Bem-Vindo! \n";
    resultado = write(meuClienteFuncao, mensagemInicial, strlen(mensagemInicial));

    while (true)
    {

        char buffer[TAMANHO_MENSAGEM];
        bzero(&buffer, sizeof(buffer));

        // Recebendo o comando
        resultado = recv(meuClienteFuncao, buffer, TAMANHO_MENSAGEM, 0);
        wprintf(corAzul L"[C]" corBranca " >> Comando : " corAzul "%s \n", buffer);

        char mensagemServidor[TAMANHO_MENSAGEM];
        bzero(&mensagemServidor, strlen(mensagemServidor));

        //      - "RNDNUM", o servidor retorna um valor entre 0 e 1000;
        if (strncmp("RNDNUM", buffer, 6) == 0)
        {
            srand(time(NULL) ^ (getpid() << 16));
            numero = rand() % 1000;
            sprintf(mensagemServidor, "%d \n", numero);
        }

        //      - "CRTIME", o servidor retorna a hora e a data da execução;
        else if (strncmp("CRTIME", buffer, 6) == 0)
        {
            struct tm *ponteiro;
            time_t segundos;

            time(&segundos);
            ponteiro = localtime(&segundos);

            sprintf(mensagemServidor, "%d:%d || %d / %d / %d \n", ponteiro->tm_hour, ponteiro->tm_min, ponteiro->tm_mday, ponteiro->tm_mon + 1, ponteiro->tm_year + 1900);
        }

        //      - "FINISH", o socket dedicado ao cliente é fechado;
        else if (strncmp("FINISH", buffer, 6) == 0)
        {
            traco(1);
            close(meuClienteFuncao);
            break;
        }

        //      - "SHTDWN", o servidor é desligado
        else if (strncmp("SHTDWN", buffer, 6) == 0)
        {
            exit(0);
        }

        //      - Se colocar algo diferente, é retornado a mensagem "ERROR";
        else
        {
            sprintf(mensagemServidor, "ERROR \n");
        }

        // Enviando ao usuário
        resultado = write(meuClienteFuncao, mensagemServidor, strlen(mensagemServidor));

        // Colocando no arquivo o comando enviado pelo usuário.
        funcaoArquivo(&buffer, strlen(buffer));

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

    pthread_t pthreadCliente[QUANTIDADE_CLIENTES];

    // | Pegando a porta
    // Poderia ser algo fixo ou aleatório
    wprintf(L"Porta: >> " corAmarela);
    wscanf(L"%d", &portaServidor);
    // srand(time(NULL));
    // portaServidor = rand() % 10 + 9900;
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

        // Uma thread para cada cliente conectado.
        pthread_create(&pthreadCliente[indexCliente], NULL, funcaoCliente, (void *)meuCliente[indexCliente]);

        if (meuCliente[contadorClientes] == -1)
        {
            wprintf(corVermelha L"accept() falhou!" corBranca);
            traco(2);
            exit(0);
        }

        // Controlando a quantidade de clientes.
        indexCliente += 1;
        contadorClientes += 1;
        indexCliente = indexCliente % QUANTIDADE_CLIENTES;

        wprintf(L"Conectados: " corAmarela "%d" corBranca, indexCliente);
        traco(2);
    }

    traco(2);
    return 0;
}