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
        wprintf(corVermelha L"Erro ao alocar Nó!" corBranca);
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
        wprintf(corVermelha L"Erro ao alocar Nó!" corBranca);
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
        wprintf(corVermelha L"Erro ao alocar Nó!" corBranca);
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
        wprintf(corAmarela L"Fila vazia." corBranca);
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
            wprintf(corAmarela L"Valor não encontrado na lista." corBranca);
        }
    }
    else
    {
        // Lista vazia
        wprintf(corAmarela L"Fila vazia." corBranca);
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
        wprintf(corAmarela L"Fila vazia." corBranca);
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

        wprintf(corCiano L"Início" corBranca L" -> ");
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
        wprintf(corAmarela L"Fila vazia." corBranca);
    }

    traco(2);
}

// Contar elementos da lista
int contarElementos(No ***lista)
{
    No *aux = **lista;
    int total = 0;
    if (**lista)
    {
        while (aux)
        {
            aux = aux->proximo;
            total += 1;
        }
    }
    return total;
}

// Organizar lista: trocando posicoes
void bublleSort(No **lista)
{
    No *auxAtual = *lista;
    No *auxConta = *lista;
    int total = 0;

    int quantidade = contarElementos(&lista);
    if (quantidade > 1)
    {
        auxAtual = *lista;

        while (true)
        {
            auxConta = (*lista);
            total = 0;

            while (auxConta->proximo)
            {
                if (auxConta->valor > auxConta->proximo->valor)
                    total += 1;
                auxConta = auxConta->proximo;
            }

            if (total == 0)
                break;
            else
            {
                No *aux1 = NULL;
                No *aux2 = NULL;
                No *aux3 = *lista;
                auxAtual = *lista;
                No *auxAnterior = NULL;

                while (true)
                {
                    aux1 = aux3;
                    aux2 = aux1->proximo;

                    if (aux2 == NULL)
                        break;

                    if (aux2->valor < aux1->valor)
                    {
                        aux1->proximo = aux2->proximo;
                        aux2->proximo = aux1;
                        if (auxAtual == (*lista))
                        {
                            *lista = aux2;
                            auxAtual = aux2->proximo;
                            auxAnterior = *lista;
                        }
                        else
                        {
                            auxAnterior = (*lista);
                            while (auxAnterior->proximo != auxAtual)
                                auxAnterior = auxAnterior->proximo;
                            auxAnterior->proximo = aux2;
                        }
                    }

                    else
                    {
                        auxAnterior = *(lista);
                        if (auxAtual != (*lista))
                        {
                            auxAnterior = (*lista);
                            while (auxAnterior->proximo != auxAtual)
                                auxAnterior = auxAnterior->proximo;
                        }
                        auxAtual = aux2;
                        aux3 = aux2;
                    }
                }
            }
        }
    }
}

int main()
{

    // inicioCodigo();

    int opcao = 1;
    int num;
    int pos;
    No *lista = NULL;
    No *removido = NULL;

    int quantidade;

    while (opcao != 0)
    {

        inicioCodigo();

        wprintf(corAmarela L" 1 " corBranca L"| Inserir no início\n");
        wprintf(corAmarela L" 2 " corBranca L"| Inserir no meio\n");
        wprintf(corAmarela L" 3 " corBranca L"| Inserir no fim\n");
        wprintf(corAmarela L" 4 " corBranca L"| Remover no início\n");
        wprintf(corAmarela L" 5 " corBranca L"| Remover no meio\n");
        wprintf(corAmarela L" 6 " corBranca L"| Remover no fim\n");
        wprintf(corAmarela L" 7 " corBranca L"| Imprimir lista\n");
        wprintf(corAmarela L" 8 " corBranca L"| Bublle Sort\n");
        wprintf(corAmarela L" 0 " corBranca L"| Sair\n\n");
        wprintf(corAmarela L" -> " corBranca);
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
            sleep(1);

            break;

        // Inserir no meio
        case 2:
            traco(1);

            wprintf(L"Número" corAmarela " -> " corBranca);
            wscanf(L"%d", &num);

            imprimirLista(lista);

            wprintf(L"Posição" corAmarela " -> " corBranca);
            wscanf(L"%d", &pos);

            inserirMeio(&lista, num, pos);

            traco(1);
            sleep(1);

            break;

        // Inserir no fim
        case 3:
            traco(1);

            wprintf(L"Número: ");
            wscanf(L"%d", &num);

            inserirFinal(&lista, num);

            traco(1);
            sleep(1);

            break;

        // Remover no início
        case 4:
            traco(1);

            removido = removerInicio(&lista);

            if (removido)
            {
                wprintf(L"Removido: " corVermelha "%d" corBranca, removido->valor);
            }

            traco(1);
            sleep(2);

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
                wprintf(L"Removido: " corVermelha "%d" corBranca, removido->valor);
            }

            traco(2);
            sleep(1);

            break;

        // Remover no fim
        case 6:
            traco(1);

            removido = removerFinal(&lista);

            if (removido)
            {
                wprintf(L"Removido: " corVermelha "%d" corBranca, removido->valor);
            }

            traco(2);
            sleep(1);

            break;

        // Imprimir lista
        case 7:

            imprimirLista(lista);
            sleep(3);

            break;

        // Bubble Sort
        case 8:

            bublleSort(&lista);
            // sleep(5);
            break;

        default:
            if (opcao != 0)
            {
                wprintf(corVermelha L"Opção inválida!" corBranca);
            }
            break;
        }
    }

    traco(1);
    return 0;
}