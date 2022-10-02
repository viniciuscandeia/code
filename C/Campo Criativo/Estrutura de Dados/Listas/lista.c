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
    | LISTA ENCADEADA - Como entender?
        ! De maneira direta: é uma fila sem restições.
        Por exemplo:
            Só é possível adicionar em uma fila no final
            Só é possível remover em uma fila pelo começo

        ! Em uma lista, a manipulação é livre.
        ! Pode tanto inserir, como remover de qualquer lugar.

        É possível fazer algo do tipo:
            * Lista: a, b, c, d, e
            Quero adicionar 9 no meio da lista:
            * Lista: a, b, 9, c, d, e
            Ou talvez no final:
            * Lista: a, b, c, d, e, 9
            Quem sabe no começo:
            * Lista: 9. a, b, c, d, e

        ! Você que decide como será manipulado.
 */

typedef struct no
{
    int valor;
    struct no *proximo;
} No;

// Inserir no início
void inserirInicio(No **lista, int valor)
{
    No *novo = malloc(sizeof(No));

    if (novo)
    {
        novo->valor = valor;
        novo->proximo = *lista;

        *lista = novo;
    }

    else
    {
        wprintf(cor_vermelha L"Erro ao alocar Nó!" cor_branca);
    }
}

// Inserir no meio
void inserirMeio(No **lista, int valor, int anterior)
{
    No *novo = malloc(sizeof(No));
    No *aux = *lista;

    if (novo)
    {
        novo->valor = valor;

        if ((*lista) == NULL)
        {
            // Lista vazia
            novo->proximo = NULL;
            *lista = novo;
        }
        else
        {
            // Lista não vazia

            // Ele irá procurar o nó com valor "anterior"
            while (aux->proximo && aux->valor != anterior)
            {
                aux = aux->proximo;
            }

            // O próximo do novo nó será o nó depois do nó com valor "anterior"
            novo->proximo = aux->proximo;
            // O próximo nó depois do nó com valor "anterior" será o novo nó
            aux->proximo = novo;
        }
    }
    else
    {
        wprintf(cor_vermelha L"Erro ao alocar Nó!" cor_branca);
    }
}

// Inserir no final
void inserirFinal(No **lista, int valor)
{
    No *novo = malloc(sizeof(No));
    No *aux = *lista;

    if (novo)
    {
        novo->proximo = NULL;
        novo->valor = valor;

        if (*lista == NULL)
        {
            // Lista vazia
            *lista = novo;
        }
        else
        {
            // Lista não vazia
            while (aux->proximo)
            {
                aux = aux->proximo;
            }

            aux->proximo = novo;
        }
    }
    else
    {
        wprintf(cor_vermelha L"Erro ao alocar Nó!" cor_branca);
    }
}

// Remover no início
No *removerInicio(No **lista)
{
    No *remover = NULL;
    No *aux = *lista;

    if (*lista)
    {
        // Lista não vazia

        // Pegando o 1° da lista
        remover = *lista;

        // Pegando o 2° da lista
        aux = aux->proximo;

        // O 2° passará a ser o 1°
        *lista = aux;
    }
    else
    {
        // Lista vazia
        wprintf(cor_amarela L"Fila vazia." cor_branca);
    }

    return remover;
}

// Remover no meio
No *removerMeio(No **lista, int valor)
{
    No *remover = NULL;
    No *aux = *lista;
    No *aux2 = NULL;

    if (*lista)
    {
        // Lista não vazia

        while (aux->proximo && aux->valor != valor)
        {
            // Se o valor do próximo for igual ao "valor"
            if (aux->proximo->valor == valor)
            {
                aux2 = aux;
            }

            aux = aux->proximo;
        }

        // Encontrou o valor
        if (aux->valor == valor)
        {
            remover = aux;
            aux2->proximo = aux->proximo;
        }

        // A lista acabou e não encontrou o valor
        else if (aux->proximo == NULL)
        {
            wprintf(cor_amarela L"Valor não encontrado na lista." cor_branca);
        }
    }
    else
    {
        // Lista vazia
        wprintf(cor_amarela L"Fila vazia." cor_branca);
    }

    return remover;
}

// Remover no final
No *removerFinal(No **lista)
{
    No *remover = NULL;
    No *aux = *lista;
    No *aux2 = *lista;

    if (*lista)
    {
        // Lista não vazia

        while (aux->proximo)
        {

            // Se o próximo depois do próximo do nó for NULL,
            // então o nó atual será o penúltimo
            if (aux->proximo->proximo == NULL)
            {
                aux2 = aux;
            }

            aux = aux->proximo;
        }

        aux2->proximo = NULL;

        remover = aux;
    }
    else
    {
        // Lista vazia
        wprintf(cor_amarela L"Fila vazia." cor_branca);
    }

    return remover;
}

// Imprimir fila
void imprimirLista(No *lista)
{
    No *aux = lista;

    traco(1);

    if (lista)
    {
        // Fila não vazia

        wprintf(cor_ciano L"Início" cor_branca L" -> ");
        while (aux)
        {
            wprintf(L"%d", aux->valor);

            if (aux->proximo)
            {
                wprintf(L", ");
            }

            aux = aux->proximo;
        }
    }
    else
    {
        // Fila vazia
        wprintf(cor_amarela L"Fila vazia." cor_branca);
    }

    traco(2);
}

int main()
{

    // inicioCodigo();

    int opcao = 1;
    int num;
    int pos;
    No *lista = NULL;
    No *removido = NULL;

    while (opcao != 0)
    {

        inicioCodigo();

        wprintf(cor_amarela L" 1 " cor_branca L"| Inserir no início\n");
        wprintf(cor_amarela L" 2 " cor_branca L"| Inserir no meio\n");
        wprintf(cor_amarela L" 3 " cor_branca L"| Inserir no fim\n");
        wprintf(cor_amarela L" 4 " cor_branca L"| Remover no início\n");
        wprintf(cor_amarela L" 5 " cor_branca L"| Remover no meio\n");
        wprintf(cor_amarela L" 6 " cor_branca L"| Remover no fim\n");
        wprintf(cor_amarela L" 7 " cor_branca L"| Imprimir lista\n");
        wprintf(cor_amarela L" 0 " cor_branca L"| Sair\n\n");
        wprintf(cor_amarela L" -> " cor_branca);
        wscanf(L"%d", &opcao);

        switch (opcao)
        {

        // Inserir no início
        case 1:
            traco(1);

            wprintf(L"Número: ");
            limparBuffer();
            wscanf(L"%d", &num);
            limparBuffer();

            inserirInicio(&lista, num);

            traco(1);
            usleep(100000);

            break;

        // Inserir no meio
        case 2:
            traco(1);

            wprintf(L"Número" cor_amarela " -> " cor_branca);
            wscanf(L"%d", &num);

            imprimirLista(lista);

            wprintf(L"Posição" cor_amarela " -> " cor_branca);
            wscanf(L"%d", &pos);

            inserirMeio(&lista, num, pos);

            traco(1);
            usleep(500000);

            break;

        // Inserir no fim
        case 3:
            traco(1);

            wprintf(L"Número: ");
            wscanf(L"%d", &num);

            inserirFinal(&lista, num);

            traco(1);
            usleep(500000);

            break;

        // Remover no início
        case 4:
            traco(1);

            removido = removerInicio(&lista);

            if (removido)
            {
                wprintf(L"Removido: " cor_vermelha "%d" cor_branca, removido->valor);
            }

            traco(2);
            usleep(500000);

            break;

        // Remover no meio
        case 5:
            imprimirLista(lista);

            wprintf(L"Número: ");
            wscanf(L"%d", &num);

            traco(1);

            removido = removerMeio(&lista, num);

            if (removido)
            {
                wprintf(L"Removido: " cor_vermelha "%d" cor_branca, removido->valor);
            }

            traco(2);
            usleep(500000);

            break;

        // Remover no fim
        case 6:
            traco(1);

            removido = removerFinal(&lista);

            if (removido)
            {
                wprintf(L"Removido: " cor_vermelha "%d" cor_branca, removido->valor);
            }

            traco(2);
            usleep(500000);

            break;

        // Imprimir lista
        case 7:

            imprimirLista(lista);
            sleep_us(2000000);

            break;
        default:
            if (opcao != 0)
            {
                wprintf(cor_vermelha L"Opção inválida!" cor_branca);
            }
            break;
        }
    }

    traco(1);
    return 0;
}