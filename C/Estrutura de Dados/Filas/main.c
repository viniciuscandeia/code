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
} No;

void inserirFila(No **fila, int num)
{
    No *novo = malloc(sizeof(No));
    No *aux;
    if (novo)
    {
        novo->valor = num;
        // Inserção no final da fila, logo, não tem ninguém atrás dele.
        novo->proximo = NULL;
        if (*fila == NULL)
        {
            // Fila vazia
            *fila = novo;
        }
        else
        {
            // Fila não vazia
            aux = *fila;
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

No *removerFila(No **fila)
{
    No *remover = NULL;

    if (*fila == NULL)
    {
        wprintf(cor_amarela L"Fila vazia." cor_branca);
    }
    else
    {
        remover = *fila;
        *fila = remover->proximo;
    }

    return remover;
}

void imprimirFila(No *fila)
{

    while (fila)
    {
        wprintf(L"%d ", fila->valor);
        fila = fila->proximo;
    }
}

int main()
{

    inicioCodigo();

    No *fila = NULL;
    int opcao = 1;
    int num;

    while (opcao != 0)
    {

        inicioCodigo();

        wprintf(L"Valor: \n\n" cor_amarela " 1 " cor_branca "| Inserir \n" cor_amarela " 2 " cor_branca "| Remover \n" cor_amarela " 3 " cor_branca "| Mostrar \n" cor_amarela " 0 " cor_branca "| Sair\n\n"
                " >> ");
        wscanf(L"%d", &opcao);
        limparBuffer();

        switch (opcao)
        {
        case 1:
            traco(1);

            wprintf(L"Número: ");
            wscanf(L"%d", &num);
            inserirFila(&fila, num);

            break;
        case 2:
            traco(1);

            No *removido = removerFila(&fila);
            wprintf(L"Removido: %d", removido->valor);

            break;
        case 3:
            traco(1);

            imprimirFila(fila);

            break;

        case 0:
            break;

        default:
            wprintf(cor_vermelha L"Opção inválida!" cor_branca);
            break;
        }
    }

    traco(2);
    return 0;
}