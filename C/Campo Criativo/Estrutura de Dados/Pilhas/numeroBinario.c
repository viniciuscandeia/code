#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
#include <locale.h>
#include <sys/types.h>
#include <time.h>
#include <unistd.h>
#include <wchar.h>

#include "aditivos.h"

/*
    & Crie um programa que pede ao usuário valores inteiros e exibe seu
    & correspondente em binário.
 */

typedef struct no
{
    int valorBinario;
    struct no *proximo;
} No;

void adicionarPilha(No ***pilha, int numBinario)
{
    No *novo = malloc(sizeof(No));

    // Se a alocação for bem-sucedida
    if (novo)
    {
        novo->valorBinario = numBinario;
        novo->proximo = NULL;

        // A pilha não está vazia.
        if (**pilha)
        {
            novo->proximo = (**pilha);
            **pilha = novo;
        }

        // A pilha está vazia.
        else
        {
            **pilha = novo;
        }
    }

    // Se a alocação for mal-sucedida
    else
    {
        wprintf(cor_vermelha L"Erro ao alocar memória." cor_branca);
    }
}

void mostrarPilha(No ***pilha)
{
    wprintf(L"Binário: ");
    while (**pilha)
    {
        wprintf(cor_ciano L"%d" cor_branca, (**pilha)->valorBinario);
        (**pilha) = (**pilha)->proximo;
    }
}

int numeroBinario(No **pilha, int numDecimal)
{
    int restoDivisao;
    int resultadoDivisao;

    while (numDecimal != 0)
    {
        wprintf(L"%4d | %4d\n", numDecimal, 2);
        wprintf(L"      -------\n");

        restoDivisao = numDecimal % 2;

        adicionarPilha(&pilha, restoDivisao);

        resultadoDivisao = floor(numDecimal / 2);
        numDecimal = resultadoDivisao;

        wprintf(L"%4d   %4d", restoDivisao, resultadoDivisao);
        traco(2);
    }

    if (numDecimal == 1){
        adicionarPilha(&pilha, numDecimal);
    }

    mostrarPilha(&pilha);

    return 0;
}

int main()
{

    inicioCodigo();

    int num;
    wprintf(L"Número: ");
    wscanf(L"%d", &num);

    No *pilha = NULL;

    traco(1);

    int resultadoBinario = numeroBinario(&pilha, num);

    traco(2);
    return 0;
}