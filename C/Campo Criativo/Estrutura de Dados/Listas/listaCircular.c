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

// | LISTA CIRCULAR

typedef struct no
{
    int valor;
    bool representaUltimo;
    struct no *proximo;
} No;

// | Função para adicionar elemento no começo da lista.
// Não precisa retornar nada.
void adicionarComeco(No **lista, int valor)
{
    No *novo = malloc(sizeof(No));
    No *aux = (*lista);

    // Alocação bem-sucedida.
    if (novo)
    {
        novo->valor = valor;
        novo->proximo = (*lista);
        novo->representaUltimo = false;

        // Lista não vazia.
        if (*lista)
        {
            novo->proximo = (*lista);

            while (aux->representaUltimo == false && aux->proximo)
            {
                aux->representaUltimo = false;
                aux = aux->proximo;
            }

            aux->proximo = novo;
            aux->representaUltimo = true;

            (*lista) = novo;
        }

        // Lista vazia.
        else
        {
            novo->representaUltimo = true;
            (*lista) = novo;
        }
    }

    // Alocação malsucedida.
    else
    {
        wprintf(cor_vermelha L"Erro ao alocar memória." cor_branca);
    }
}

// | Função para adiiconar no meio da lista.
// Não precisa retornar nada.
void adicionarMeio(No **lista, int valor, int parametro)
{
    No *novo = malloc(sizeof(No));
    No *aux = (*lista);

    // Alocação bem-sucedida.
    if (novo)
    {

        novo->valor = valor;
        novo->proximo = (*lista);
        novo->representaUltimo = false;

        // Lista não vazia.
        if (*lista)
        {
            while (true)
            {
                if (!(aux->representaUltimo) && aux->valor == parametro)
                {
                    break;
                }
                else if (aux->representaUltimo)
                {
                    break;
                }
                else
                {
                    aux = aux->proximo;
                }
            }

            if (!(aux->representaUltimo) && aux->valor == parametro)
            {
                novo->proximo = aux->proximo;
                aux->proximo = novo;
            }
            else
            {
                novo->proximo = (*lista);
                novo->representaUltimo = true;

                aux->representaUltimo = false;
                aux->proximo = novo;
            }
        }

        // Lista vazia.
        else
        {
            novo->representaUltimo = true;
            (*lista) = novo;
        }
    }

    // Alocação malsucedida.
    else
    {
        wprintf(cor_vermelha L"Erro ao alocar memória." cor_branca);
    }
}

// | Função para adicionar elemento no final da lista.
// Não precisa retornar nada.
void adicionarFinal(No **lista, int valor)
{
    No *novo = malloc(sizeof(No));
    No *aux = (*lista);

    // Alocação bem-sucedida.
    if (novo)
    {
        novo->valor = valor;
        novo->representaUltimo = true;
        novo->proximo = (*lista);

        // Lista não vazia.
        if (*lista)
        {
            while (true)
            {
                if (aux->representaUltimo)
                {
                    break;
                }
                else
                {
                    aux = aux->proximo;
                }
            }

            aux->representaUltimo = false;
            aux->proximo = novo;
            novo->proximo = (*lista);
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

// | Função para remover elemento do começo da lista.
// Retorno será o elemento removido.
No *removerComeco(No **lista)
{
    No *remover = NULL;
    No *aux = (*lista);

    // Lista não vazia.
    if (*lista)
    {
        remover = (*lista);

        while (true)
        {
            if (aux->representaUltimo)
            {
                break;
            }
            else
            {
                aux = aux->proximo;
            }
        }

        if ((*lista)->representaUltimo)
        {
            (*lista) = NULL;
        }
        else
        {
            aux->proximo = remover->proximo;
            (*lista) = remover->proximo;
        }
    }

    // Lista vazia.
    else
    {
        wprintf(cor_amarela L"Lista vazia." cor_branca);
    }

    return remover;
}

// | Função para remover elemento do meio da lista.
// Retorno será o elemento removido.
No *removerMeio(No **lista, int parametro)
{
    No *remover = NULL;
    No *aux = (*lista);
    No *aux2 = (*lista);

    // Lista não vazia.
    if (*lista)
    {
        while (true)
        {
            if (!(aux->representaUltimo) && aux->valor == parametro)
            {
                remover = aux;
                if (aux2 == aux)
                {
                    (*lista) = aux->proximo;
                }
                else
                {
                    aux2->proximo = aux->proximo;
                }
                break;
            }
            else if (aux->representaUltimo && aux->valor == parametro)
            {
                remover = aux;
                if (aux == (*lista))
                {
                    (*lista) = NULL;
                }
                else
                {
                    aux2->representaUltimo = true;
                    aux2->proximo = (*lista);
                }
                break;
            }
            else if (aux->representaUltimo && aux->valor != parametro)
            {
                break;
            }
            else
            {
                if (aux->proximo->valor == parametro)
                {
                    aux2 = aux;
                }
                aux = aux->proximo;
            }
        }
    }

    // Lista vazia.
    else
    {
        wprintf(cor_amarela L"Lista vazia." cor_branca);
    }

    return remover;
}

// | Função para remover elemento do final da lista.
// Retorno será o elemento removido.
No *removerFinal(No **lista)
{
    No *remover = NULL;
    No *aux = (*lista);
    No *aux2 = (*lista);

    // Lista não vazia.
    if ((*lista))
    {
        while (true)
        {

            if (aux->representaUltimo)
            {
                remover = aux;

                while (!(aux2->proximo->representaUltimo))
                {
                    aux2 = aux2->proximo;
                }

                if (aux2->representaUltimo)
                {
                    (*lista) = NULL;
                }
                else
                {
                    aux2->representaUltimo = true;
                    aux2->proximo = (*lista);
                }

                break;
            }
            else
            {
                aux = aux->proximo;
            }
        }
    }

    // Lista vazia.
    else
    {
        wprintf(cor_amarela L"Lista vazia." cor_branca);
    }

    return remover;
}

// | Função para mostrar a lista.
// Não precisa retornar nada.
void mostrarLista(No *lista)
{
    No *aux = lista;

    // Lista não vazia.
    if (lista)
    {
        wprintf(cor_ciano L"Início" cor_branca " >> ");

        do
        {
            wprintf(cor_ciano L"%d" cor_branca, aux->valor);

            if (aux->representaUltimo)
            {
                break;
            }
            else
            {
                if (aux->proximo)
                {
                    wprintf(L", ");
                }
                aux = aux->proximo;
            }

        } while (true);
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