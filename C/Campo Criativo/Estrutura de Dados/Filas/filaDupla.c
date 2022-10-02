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

// | FILA DUPLA

/*
    | FILA DUPLA - Já estou no inferno? Não??? E esse demônio aí??
        ! Uma fila que pode adicionar ou remover tanto no começo, como no final.
*/

typedef struct no
{
    int valor;
    struct no *proximo;
} No;

// & Função para adicionar elemento no começo da fila.
// Não precisa retornar nada.
void adicionarComeco(No **fila, int valor)
{
    No *novo = malloc(sizeof(No));
    No *aux = (*fila);

    // Alocação foi bem-sucedida.
    if (novo)
    {
        novo->proximo = NULL;
        novo->valor = valor;

        // Fila não vazia.
        if (*fila)
        {
            novo->proximo = (*fila);
            (*fila) = novo;
        }

        // Fila vazia.
        else
        {
            (*fila) = novo;
        }
    }

    // Alocação foi mal-sucedida.
    else
    {
        wprintf(cor_vermelha L"Erro ao alocar memória." cor_branca);
    }
}

// & Função para adicionar elemento no final da fila.
// Não precisa retornar nada.
void adicionarFinal(No **fila, int valor)
{
    No *novo = malloc(sizeof(No));
    No *aux = (*fila);

    // Alocação foi bem-sucedida.
    if (novo)
    {

        novo->valor = valor;
        novo->proximo = NULL;

        // Fila não vazia.
        if ((*fila))
        {
            while (aux->proximo)
            {
                aux = aux->proximo;
            }

            aux->proximo = novo;
        }

        // Fila vazia.
        else
        {
            (*fila) = novo;
        }
    }

    // Alocação foi mal-sucedida.
    else
    {
        wprintf(cor_vermelha L"Erro ao alocar memória!" cor_branca);
    }
}

// & Função para remover elemento do começo da fila.
// Retorno será o elemento removido.
No *removerComeco(No **fila)
{
    No *remover = NULL;

    // Fila não vazia.
    if (*fila)
    {
        remover = (*fila);
        (*fila) = remover->proximo;
    }

    // Fila vazia.
    else
    {
        wprintf(cor_amarela L"Fila vazia." cor_branca);
    }

    return remover;
}

// & Função para remover elemento do final da fila.
// Retorno será o elemento removid.
No *removerFinal(No **fila)
{
    No *remover = NULL;
    No *aux = *fila;

    // Fila não vazia.
    if (*fila)
    {
        while (aux->proximo->proximo)
        {
            aux = aux->proximo;
        }

        remover = aux->proximo;
        aux->proximo = NULL;
    }

    // Fila vazia.
    else
    {
        wprintf(cor_amarela L"Fila vazia." cor_branca);
    }

    return remover;
}

// & Função para mostrar a fila.
// Não precisa retornar nada.
void mostrarFila(No *fila)
{
    No *aux = (fila);

    // Fila não vazia.
    if (fila)
    {
        wprintf(cor_ciano L"Início" cor_branca " >> ");
        while (aux)
        {
            wprintf(cor_ciano L"%d" cor_branca, aux->valor);

            if (aux->proximo)
            {
                wprintf(L", ");
            }
            aux = aux->proximo;
        }
    }

    // Fila vazia.
    else
    {
        wprintf(cor_amarela L"Fila vazia." cor_branca);
    }
}

int main()
{

    inicioCodigo();

    No *fila = NULL;
    No *remover;

    int opcao = 1;
    int num;

    while (opcao != 0)
    {

        inicioCodigo();

        wprintf(cor_amarela L" 1 " cor_branca L"| Inserir no começo da fila\n");
        wprintf(cor_amarela L" 2 " cor_branca L"| Inserir no final  da fila\n");
        wprintf(cor_amarela L" 3 " cor_branca L"| Remover no começo da fila\n");
        wprintf(cor_amarela L" 4 " cor_branca L"| Remover no final  da fila\n");
        wprintf(cor_amarela L" 5 " cor_branca L"| Imprimir fila\n");
        wprintf(cor_amarela L" 0 " cor_branca L"| Sair\n\n");
        wprintf(cor_amarela L" -> " cor_branca);
        wscanf(L"%d", &opcao);

        switch (opcao)
        {
        case 1:

            traco(1);

            wprintf(L"Número: ");
            wscanf(L"%d", &num);

            // Como a fila será alterada dentro da função, é preciso passar o endereço dela.
            adicionarComeco(&fila, num);

            traco(1);
            sleep(1);
            break;

        case 2:

            traco(1);

            wprintf(L"Número: ");
            wscanf(L"%d", &num);

            // Como a fila será alterada dentro da função, é preciso passar o endereço dela.
            adicionarFinal(&fila, num);

            traco(1);
            sleep(1);
            break;

        case 3:

            traco(1);

            // Como a fila será alterada dentro da função, é preciso passar o endereço dela.
            remover = removerComeco(&fila);

            // Se o elemento removido for != NULL
            if (remover)
            {
                wprintf(L"Removido: " cor_vermelha "%d" cor_branca, remover->valor);
            }

            traco(2);
            sleep(1);
            break;

        case 4:

            traco(1);

            // Como a fila será alterada dentro da função, é preciso passar o endereço dela.
            remover = removerFinal(&fila);

            // Se o elemento removido for != NULL
            if (remover)
            {
                wprintf(L"Removido: " cor_vermelha "%d" cor_branca, remover->valor);
            }

            traco(2);
            sleep(1);
            break;

        case 5:

            traco(1);

            // Como não será alterado nada da fila, não é preciso passar o endereço dela.
            mostrarFila(fila);

            traco(2);
            sleep(3);
            break;

        default:
            if (opcao != 0)
            {
                traco(1);
                wprintf(cor_vermelha L"Opção inválida!" cor_branca);
                traco(2);
                sleep(1);
            }
            break;
        }
    }

    traco(1);
    return 0;
}