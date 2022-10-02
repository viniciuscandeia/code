#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
#include <locale.h>
#include <sys/types.h>
#include <time.h>
#include <unistd.h>
#include <wchar.h>
#include <string.h>

#include "aditivos.h"

/*
    ! Usando seu TAD pilha, crie uma função para verificar se uma expressão
    ! composta apenas por chaves, colchetes e parênteses, representada por uma
    ! cadeia, está ou não balanceada. Por exemplo, as expressões "[{()()}{}]" e
    ! "{[([{}])]}" estão balanceadas, mas as expressões "{[(}])" e "{[)()(]}" não estão.
*/

typedef struct no
{
    char carac;
    struct no *proximo;
} No;

void adicionarPilha(No ***pilha, char carac)
{
    No *novo = malloc(sizeof(No));

    // Se a alocação for bem-sucedida
    if (novo)
    {
        novo->carac = carac;
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
    // A pilha não está vazia.
    // Expressão não balanceada.
    if (**pilha)
    {
        wprintf(cor_vermelha L"Expressão não balanceada." cor_branca);
    }

    // A pilha está vazia.
    else
    {
        wprintf(cor_verde L"Expressão balanceada." cor_branca);
    }
}

void removerPilha(No ***pilha)
{
    No *remover = NULL;

    // A fila não está vazia.
    if (**pilha)
    {
        remover = **pilha;
        **pilha = remover->proximo;
    }
}

void expressaoBalanceada(No **pilha, char expressao[30])
{
    for (int i = 0; i < strlen(expressao); i++)
    {
        if (*pilha)
        {
            if (expressao[i] == ')' && (*pilha)->carac == '(' ||
                expressao[i] == ']' && (*pilha)->carac == '[' ||
                expressao[i] == '}' && (*pilha)->carac == '{')
            {
                removerPilha(&pilha);
            }
            else
            {
                adicionarPilha(&pilha, expressao[i]);
            }
        }
        else
        {
            adicionarPilha(&pilha, expressao[i]);
        }
    }

    mostrarPilha(&pilha);
}

int main()
{

    inicioCodigo();

    No *pilha = NULL;

    char carac[10];
    wprintf(L"Expressão: ");
    wscanf(L"%s", &carac);

    expressaoBalanceada(&pilha, carac);

    traco(2);
    return 0;
}