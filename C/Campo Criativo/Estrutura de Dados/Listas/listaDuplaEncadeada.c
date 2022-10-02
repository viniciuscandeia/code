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

typedef struct no
{
    int valor;
    struct no *proximo;
    struct no *anterior;
} No;

// & Função para adicionar no começo da lista.
// Não precisa retornar nada.
void adicionarComeco(No **lista, int valor)
{
    No *novo = malloc(sizeof(No));
    No *aux = *lista;

    // Alocação bem-sucedida.
    if (novo)
    {
        novo->valor = valor;
        novo->anterior = NULL;
        novo->proximo = NULL;

        // Lista não vazia.
        if (*lista)
        {
            novo->proximo = (*lista);
            (*lista)->anterior = novo;
            (*lista) = novo;
        }

        // Lista vazia.
        else
        {
            (*lista) = novo;
        }
    }

    // Alocação malsucedida.
    else
    {
        wprintf(cor_vermelha L"Erro ao alocar memória." cor_branca);
    }
}

// & Função para adicionar no final da lista.
// Não precisa retornar nada.
void adicionarFinal(No **lista, int valor)
{
    No *novo = malloc(sizeof(No));

    // Alocação bem-sucedida.
    if (novo)
    {
        novo->valor = valor;
        novo->proximo = NULL;
        novo->anterior = NULL;

        // Lista não vazia.
        if (*lista)
        {
            No *aux = (*lista);
            while (aux->proximo)
            {
                aux = aux->proximo;
            }

            novo->anterior = aux;
            aux->proximo = novo;
        }

        // Lista vazia.
        else
        {
            (*lista) = novo;
        }
    }

    // Alocação malsucedida.
    else
    {
    }
}

// & Função para adicionar no meio da lista.
// Não precisa retornar nada.
void adicionarMeio(No **lista, int valor, int parametro)
{
    No *novo = malloc(sizeof(No));
    No *aux = (*lista);

    // Alocação bem-sucedida.
    if (novo)
    {
        novo->valor = valor;
        novo->proximo = NULL;
        novo->anterior = NULL;

        // Lista não vazia.
        if ((*lista))
        {
            while (aux->proximo && aux->valor != parametro)
            {
                aux = aux->proximo;
            }

            if (aux->proximo)
            {
                novo->proximo = aux->proximo;
                novo->anterior = aux;
                aux->proximo->anterior = novo;
                aux->proximo = novo;
            }

            else
            {
                novo->anterior = aux;
                aux->proximo = novo;
            }
        }

        // Lista vazia.
        else
        {
            (*lista) = novo;
        }
    }

    // Alocação malsucedida.
    else
    {
        wprintf(cor_vermelha L"Erro ao alocar memória." cor_branca);
    }
}

// & Função para remover no começo da lista.
// Retorno do elemento que será removido.
No *removerComeco(No **lista)
{
    No *remover = NULL;
    No *aux = (*lista);

    // Lista não vazia.
    if (*lista)
    {
        remover = (*lista);

        if (aux->proximo)
        {
            aux = aux->proximo;
            aux->anterior = NULL;
        }
        else
        {
            aux = NULL;
        }

        (*lista) = aux;
    }

    // Lista vazia.
    else
    {
        wprintf(cor_amarela L"Lista vazia." cor_branca);
    }

    return remover;
}

// & Função para remover no meio da lista.
// Retorno do elemento que será removido.
No *removerMeio(No **lista, int parametro)
{
    No *remover = NULL;
    No *aux = (*lista);
    No *aux2 = NULL;

    // Lista não vazia.
    if ((*lista))
    {
        while (aux->proximo && aux->valor != parametro)
        {
            aux = aux->proximo;
        }

        if (aux->valor == parametro)
        {
            remover = aux;

            aux->anterior->proximo = aux->proximo;
            aux->proximo->anterior = aux->anterior;
        }

        else
        {
            wprintf(cor_amarela L"Valor não encontrado." cor_branca);
        }
    }

    // Lista vazia.
    else
    {
        wprintf(cor_amarela L"Lista vazia." cor_branca);
    }

    return remover;
}

// & Função para remover no final da lista.
// Retorno do elemento que será removido.
No *removerFinal(No **lista)
{
    No *remover = NULL;
    No *aux = (*lista);
    No *aux2 = NULL;

    // Lista não vazia.
    if ((*lista))
    {
        while (aux->proximo)
        {
            aux = aux->proximo;
        }

        remover = aux;

        if (aux->anterior)
        {
            aux->anterior->proximo = NULL;
        }
        else
        {
            (*lista) = NULL;
        }
    }

    // Lista vazia.
    else
    {
        wprintf(cor_amarela L"Lista vazia." cor_branca);
    }

    return remover;
}

// & Função para mostrar a lista.
// Não precisa retornar nada.
void mostrarLista(No *lista)
{
    No *aux = lista;

    // Lista não vazia.
    if (lista)
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

    // Lista vazia.
    else
    {
        wprintf(cor_amarela L"Lista vazia." cor_branca);
    }
}

int main()
{

    inicioCodigo();

    No *lista = NULL;
    No *remover = NULL;

    int opcao = 1;
    int num;
    int pos;

    while (opcao != 0)
    {

        inicioCodigo();

        wprintf(cor_amarela L" 1 " cor_branca L"| Adicionar : COMEÇO \n");
        wprintf(cor_amarela L" 2 " cor_branca L"| Adicionar :   MEIO \n");
        wprintf(cor_amarela L" 3 " cor_branca L"| Adicionar :    FIM \n");
        wprintf(cor_amarela L" 4 " cor_branca L"| Remover   : COMEÇO \n");
        wprintf(cor_amarela L" 5 " cor_branca L"| Remover   :   MEIO \n");
        wprintf(cor_amarela L" 6 " cor_branca L"| Remover   :    FIM \n");
        wprintf(cor_amarela L" 7 " cor_branca L"| Imprimir lista\n");
        wprintf(cor_amarela L" 0 " cor_branca L"| Sair\n\n");
        wprintf(cor_amarela L" -> " cor_branca);
        wscanf(L"%d", &opcao);

        switch (opcao)
        {
        case 1:

            traco(1);

            wprintf(L"Número: ");
            wscanf(L"%d", &num);

            // Como a lista será alterada dentro da função, é preciso passar o endereço dela.
            adicionarComeco(&lista, num);

            traco(1);
            usleep(200000);
            break;

        case 2:

            traco(1);

            wprintf(L"Número: ");
            wscanf(L"%d", &num);

            traco(1);

            mostrarLista(lista);

            traco(2);

            wprintf(L"Posição: ");
            wscanf(L"%d", &pos);

            // Como a lista será alterada dentro da função, é preciso passar o endereço dela.
            adicionarMeio(&lista, num, pos);

            traco(1);
            usleep(200000);
            break;

        case 3:

            traco(1);

            wprintf(L"Número: ");
            wscanf(L"%d", &num);

            // Como a lista será alterada dentro da função, é preciso passar o endereço dela.
            adicionarFinal(&lista, num);

            traco(1);
            usleep(200000);
            break;

        case 4:

            traco(1);

            // Como a lista será alterada dentro da função, é preciso passar o endereço dela.
            remover = removerComeco(&lista);

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

            mostrarLista(lista);

            traco(2);

            wprintf(L"Posição: ");
            wscanf(L"%d", &pos);

            traco(1);

            // Como a lista será alterada dentro da função, é preciso passar o endereço dela.
            remover = removerMeio(&lista, pos);

            // Se o elemento removido for != NULL
            if (remover)
            {
                wprintf(L"Removido: " cor_vermelha "%d" cor_branca, remover->valor);
            }

            traco(2);
            sleep(1);
            break;

        case 6:

            traco(1);

            // Como a lista será alterada dentro da função, é preciso passar o endereço dela.
            remover = removerFinal(&lista);

            // Se o elemento removido for != NULL
            if (remover)
            {
                wprintf(L"Removido: " cor_vermelha "%d" cor_branca, remover->valor);
            }

            traco(2);
            sleep(1);
            break;

        case 7:

            traco(1);

            // Como não será alterado nada da lista, não é preciso passar o endereço dela.
            mostrarLista(lista);

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