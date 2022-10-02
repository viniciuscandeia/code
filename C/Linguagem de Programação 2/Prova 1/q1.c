/*
ALUNO: Vinicius Candeia Pereira Vieira
MATRÍCULA: 20200009783
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
#include <locale.h>
#include <sys/types.h>
#include <time.h>
#include <unistd.h>
#include <wchar.h>

#include <pthread.h>
#include "aditivos.h"
#include <signal.h>

/*
    (Questão 1 - 5 pontos) Faça um programa em C/C++ que crie um arquivo de texto
    que funcionará como um dicionário contendo todas as strings com 4 caracteres
    alfabéticos maiúsculos (de "AAAA" a "ZZZZ"). Cada letra do alfabeto (de A a Z)
    deverá ter sua parte do dicionário gerada por um processo ou thread individual,
    (o programa deverá receber um parâmetro na sua execução que determine se threads
    ou processos serão usados) que gerará todas as strings iniciadas por uma letra
    (ex. processo/thread que gerará as strings começando com a letra 'C' gerará as
    strings de "CAAA" a "CZZZ"). A thread principal do processo original deverá
    aguardar a geração de todas as partes e gerar um arquivo de texto contendo o
    dicionário inteiro. Comente no código as diferenças do uso de processos e
    threads, do ponto de vista do consumo de recursos e do ponto de vista do uso
    das funções/API.
*/

// Ficou faltando criar a versão para executar com o fork

// Função para thread que recebe como parâmetro a 1° letra de cada string
void *funcaoThread(void *letra)
{

    // Cast de void* para *char
    char *carac = (char *)&letra;
    char nome[10];

    FILE *meuArquivo;
    // O nome de cada arquivo será a letra + ".txt"
    sprintf(nome, "%s.txt", carac);

    // Criando cada arquivo
    meuArquivo = fopen(nome, "w");

    // Se tiver algum problema em criar o arquivo
    if (meuArquivo == NULL)
    {
        wprintf(cor_vermelha L"Erro ao criar arquivo!" cor_branca);
        traco(2);
        exit(0);
    }

    // 3 for's para correr todas as combinações de letras
    for (char i = 'A'; i <= 'Z'; i++)
    {
        for (char j = 'A'; j <= 'Z'; j++)
        {
            for (char k = 'A'; k <= 'Z'; k++)
            {
                fprintf(meuArquivo, "%s%c%c%c\n", carac, i, j, k);
            }
        }
    }

    wprintf(L"Arquivo " cor_verde "%s" cor_branca " criado!\n", nome);

    // Fechando o arquivo
    fclose(meuArquivo);
    // Terminando a thread
    pthread_exit(NULL);
}

// Função para processo que recebe como parâmetro a 1° letra de cada string
void funcaoProcesso(char letra)
{

    FILE *meuArquivo;
    char nome[10];

    // O nome de cada arquivo será a letra + ".txt"
    sprintf(nome, "%c.txt", letra);

    // Criando cada arquivo
    meuArquivo = fopen(nome, "w");

    // Se tiver algum problema em criar o arquivo
    if (meuArquivo == NULL)
    {
        wprintf(cor_vermelha L"Erro ao criar arquivo!" cor_branca);
        traco(2);
        exit(0);
    }

    // 3 for's para correr todas as combinações de letras
    for (char i = 'A'; i <= 'Z'; i++)
    {
        for (char j = 'A'; j <= 'Z'; j++)
        {
            for (char k = 'A'; k <= 'Z'; k++)
            {
                fprintf(meuArquivo, "%c%c%c%c\n", letra, i, j, k);
            }
        }
    }

    wprintf(L"Arquivo " cor_verde "%s" cor_branca " criado!\n", nome);

    // Fechando o arquivo
    fclose(meuArquivo);
}

int main()
{
    // Função extra do usuário, apenas parte visual
    inicioCodigo();

    int resposta;
    wprintf(L"1 : " cor_amarela "Fork\n" cor_branca
             "2 : " cor_amarela "Thread\n" cor_branca
             " -> ");
    wscanf(L"%d", &resposta);
    limparBuffer();
    // While para garantir que a resposta será 1 ou 2
    if (resposta != 1 && resposta != 2)
    {
        while (true)
        {
            traco(1);
            wprintf(cor_vermelha L"Resposta inválida!\n\n" cor_branca);
            wprintf(L"1 : " cor_amarela "Fork\n" cor_branca
                     "2 : " cor_amarela "Thread\n" cor_branca
                     " -> ");
            wscanf(L"%d", &resposta);
            limparBuffer();
            if (resposta == 1 || resposta == 2)
            {
                break;
            }
        }
    }

    traco(1);

    // Usando fork
    if (resposta == 1)
    {
        pid_t processoPID = getpid();
        int valorFork;

        // Criando os 26 processos
        for (char i = 'A'; i <= 'Z'; i++)
        {
            if (processoPID == getpid())
            {
                // Processo: PAI
                valorFork = fork();
                if (valorFork == 0)
                {
                    // Processo: FILHO
                    funcaoProcesso(i);
                }
            }
        }

        // Terminando todos os processos filhos
        if (processoPID != getpid())
        {
            exit(0);
        }
    }

    // Usando thread
    if (resposta == 2)
    {

        // Criando thread com tamanho 26
        pthread_t thread[26];
        int flag;
        int numThread = 0;

        // O for vai passar a 1° letra do grupo
        for (char i = 'A'; i <= 'Z'; i++)
        {
            flag = pthread_create(&thread[numThread++], NULL, funcaoThread, (void *)i);
            // Esse sleep é só para mostrar, na ordem correta, a criação dos arquivos
            sleep(1);
        }
    }

    // Parte do código que junta todas as strings em um único ".txt"
    char nomeArquivo[10];
    char linha[10];
    char *linhaLida;
    FILE *meuArquivo;
    meuArquivo = fopen("dicionario.txt", "w");
    if (meuArquivo == NULL)
    {
        wprintf(cor_vermelha L"Erro ao criar arquivo!" cor_branca);
        traco(2);
        exit(0);
    }

    for (char i = 'A'; i <= 'Z'; i++)
    {
        sprintf(nomeArquivo, "%c.txt", i);
        FILE *meuArquivo2;
        meuArquivo2 = fopen(nomeArquivo, "r");
        while (!(feof(meuArquivo2)))
        {
            linhaLida = fgets(linha, 10, meuArquivo2);
            if (linhaLida)
            {
                fprintf(meuArquivo, "%s", linhaLida);
            }
        }

        fclose(meuArquivo2);
        remove(nomeArquivo);
    }

    fclose(meuArquivo);
    traco(1);

    wprintf(cor_verde L"Processo finalizado!" cor_branca);

    traco(2);
    return 0;
}