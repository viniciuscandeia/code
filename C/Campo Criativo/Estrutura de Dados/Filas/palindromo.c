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
#include <ctype.h>

#include "aditivos.h"

/*
    ! Usando seus TADs fila e pilha, implemente um
    ! programa em que o usuário digita cadeias e ele diz,
    ! para cada cadeia, se ela é palíndroma ou não
*/

typedef struct no
{
    char caracter;
    struct no *proximo;
} No;

void adicionarElemento(No ***fila, char caracter)
{
    No *novo = malloc(sizeof(No));

    // A alocação foi bem-sucedida.
    if (novo)
    {
        novo->caracter = caracter;
        novo->proximo = NULL;

        // A fila não está vazia.
        if (**fila)
        {
            No *aux = **fila;

            while (aux->proximo)
            {
                aux = aux->proximo;
            }

            aux->proximo = novo;
        }

        // A fila está vazia.
        else
        {
            **fila = novo;
        }
    }

    // A alocação foi mal-sucedida.
    else
    {
        wprintf(cor_vermelha L"Erro ao alocar memória." cor_branca);
    }
}

No *removerElemento(No ***fila)
{
    No *remover = NULL;

    // A fila não está vazia.
    if (**fila)
    {
        remover = **fila;
        (**fila) = remover->proximo;
    }

    // A fila está vazia.
    else
    {
        wprintf(cor_amarela L"Fila vazia." cor_branca);
    }

    return remover;
}

void mostrarFila(No ****fila)
{
    No *aux = ***fila;

    // A fila não está vazia.
    if (***fila)
    {
        wprintf(cor_ciano L"Início" cor_branca " >> ");
        while (aux)
        {
            wprintf(cor_ciano L"%c" cor_branca, aux->caracter);

            if (aux->proximo)
            {
                wprintf(L", ");
            }

            aux = aux->proximo;
        }
    }

    // A fila está vazia.
    else
    {
        wprintf(cor_amarela L"Fila vazia." cor_branca);
    }
}

void mostrarFila2(No ***fila)
{

    if (**fila)
    {
        wprintf(cor_vermelha L"Não palíndromo" cor_branca);

        traco(2);

        mostrarFila(&fila);
    }
    else
    {
        wprintf(cor_verde L"Palíndromo" cor_branca);
    }
}

void expressaoPalindroma(No **fila, char expressao[20])
{
    int numEspacos = 0;
    for (int i = 0; i < strlen(expressao); i++)
    {
        if (expressao[i] == ' ' || expressao[i] == ',' || expressao[i] == '!')
        {
            numEspacos += 1;
        }
    }

    int numTotal = strlen(expressao) - numEspacos;
    char *expressaoCopia = malloc(sizeof(char) * numTotal);

    numEspacos = 0;

    for (int i = 0; i < strlen(expressao); i++)
    {
        if (expressao[i] != ' ' && expressao[i] != ',' && expressao[i] != '!')
        {
            expressaoCopia[numEspacos] = expressao[i];
            numEspacos += 1;
        }
    }

    for (int i = 0; i < strlen(expressaoCopia); i++)
    {
        if (toupper(expressaoCopia[i]) != toupper(expressaoCopia[strlen(expressaoCopia) - 1 - i]))
        {
            adicionarElemento(&fila, expressaoCopia[i]);
        }
    }

    mostrarFila2(&fila);

    free(expressaoCopia);
}

int main()
{

    inicioCodigo();

    No *fila = NULL;

    char frase[30];
    wprintf(cor_vermelha L"NÃO COLOQUE LETRAS ACENTUADAS.\n" cor_branca);
    wprintf(L"Frase: ");
    wscanf(L" %80[^\n]", frase);

    traco(1);

    expressaoPalindroma(&fila, frase);

    free(fila);

    traco(2);
    return 0;
}