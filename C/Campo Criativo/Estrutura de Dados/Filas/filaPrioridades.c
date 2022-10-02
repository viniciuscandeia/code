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

// | Fila COM PRIORIDADES

/*
    | FILA COM PRIORIDADES - Como é?
        ! Se aparece um idoso em um banco, ele terá prioridade de atendimento.
        ! O mesmo acontece aqui, usamos algum critério, por exemplo, a idade, para
        ! identificar se uma pessoa deverá ser travada com prioridade ou não.

        Situações envolvendo uma fila com prioridades:
            & Em uma fila vazia, qualquer pessoa que apareça será a 1° da fila, independente da idade.
            & Em uma fila não vazia, temos:

                # Caso 1: apenas pessoas com menos de 60 anos.
                    Se um idoso chegar, ele irá para o começo da fila.
                    Se uma pessoa, com menos de 60 anos, chegar, irá para o final da fila.

                # Caso 2: pelo menos, 1 idoso na fila.
                    Se um idoso chegar, ele será o último da fila de idosos.
                    Se uma pessoa, com menos de 60 anos, chegar, irá para o final da fila.
 */

typedef struct no
{
    int valor;
    struct no *proximo;

} No;

void adicionarElemento(No **fila, int valor)
{
    No *novo = malloc(sizeof(No));
    No *aux = *fila;

    // Alocação de memória bem-sucedida.
    if (novo)
    {
        novo->proximo = NULL;
        novo->valor = valor;

        // Fila não vazia.
        if (*fila)
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

    // Alocação de memória mal-sucedida.
    else
    {
        wprintf(cor_vermelha L"Erro ao alocar memória!" cor_branca);
    }
}

// & Criando uma função para adicionar elementos com prioridades
// Não é preciso retornar nada.
// Simulação de uma fila de banco, com prioridade de 60 anos ou mais.
void adicionarElementoPrioridades(No **fila, int num)
{
    No *novo = malloc(sizeof(No));
    No *aux;

    // Alocação de memória bem-sucedido.
    if (novo)
    {
        novo->proximo = NULL;
        novo->valor = num;

        // Fila não vazia.
        if (*fila)
        {

            // O novo elemento faz parte da fila de prioridade
            if (num >= 60)
            {
                // Já tem, pelo menos, 1 na fila de prioridade
                if ((*fila)->valor >= 60)
                {
                    aux = *fila;

                    // Ficará procurando qual o último elemento com valor >= 60
                    while (aux->proximo && aux->proximo->valor >= 60)
                    {
                        aux = aux->proximo;
                    }

                    // Como aux tem o último elemento com valor >= 60, aux.proximo pegará o próximo elemento
                    // Ou seja, o 1° elemento da fila normal.
                    // O novo elemento será colocado entre o aux e o aux.proximo.
                    novo->proximo = aux->proximo;

                    // O próximo depois do antigo último elemento com valor >= 60 será o novo elemento
                    aux->proximo = novo;
                }

                // Não tem ninguém na fila de prioridade
                else
                {
                    // O próximo depois do novo elemento será o 1° da fila normal
                    novo->proximo = *fila;

                    // O 1° da fila será o novo elemento
                    *fila = novo;
                }
            }

            // O novo elemento não faz parte da fila de prioridade
            else
            {
                novo->proximo = NULL;

                aux = *fila;
                while (aux->proximo)
                {
                    aux = aux->proximo;
                }
                aux->proximo = novo;
            }
        }

        // Fila vazia.
        else
        {
            *fila = novo;
        }
    }
    else
    {
        wprintf(cor_vermelha L"Erro na alocação de memória!" cor_branca);
    }
}

No *removerElemento(No **fila)
{
    No *remover = NULL;

    // Fila não vazia.
    if (*fila)
    {
        remover = *fila;
        (*fila) = remover->proximo;
    }

    return remover;
}

void mostrarFila(No *fila)
{
    // Fila não vazia.
    if (fila)
    {
        No *aux = fila;

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

    int opcao = 1;
    int num;

    while (opcao != 0)
    {

        inicioCodigo();

        wprintf(cor_amarela L" 1 " cor_branca L"| Inserir na fila\n");
        wprintf(cor_amarela L" 2 " cor_branca L"| Remover na fila\n");
        wprintf(cor_amarela L" 3 " cor_branca L"| Imprimir fila\n");
        wprintf(cor_amarela L" 4 " cor_branca L"| Inserir na fila com prioridades\n");
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
            adicionarElemento(&fila, num);

            traco(1);
            sleep(1);
            break;

        case 2:

            traco(1);

            // Como a fila será alterada dentro da função, é preciso passar o endereço dela.
            No *remover = removerElemento(&fila);

            // Se o elemento removido for != NULL
            if (remover)
            {
                wprintf(L"Removido: " cor_vermelha "%d" cor_branca, remover->valor);
            }

            traco(2);
            sleep(1);
            break;

        case 3:

            traco(1);

            // Como não será alterado nada da fila, não é preciso passar o endereço dela.
            mostrarFila(fila);

            traco(2);
            sleep(3);
            break;

        case 4:

            traco(1);

            wprintf(L"Número: ");
            wscanf(L"%d", &num);

            // Como a fila será alterada dentro da função, é preciso passar o endereço dela.
            adicionarElementoPrioridades(&fila, num);

            traco(1);
            sleep(1);
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