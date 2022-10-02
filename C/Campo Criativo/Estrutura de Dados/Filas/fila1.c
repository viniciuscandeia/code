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
    | FILA - Uma explicação rápida de como funciona:
        ! Fila é igual fila de um banco, por exemplo. O 1° que chega, é o 1° a sair.
        Se você chega em uma fila com 2 pessoas, você será o 3° a sair.

        Inicialmente, a fila está vazia:
        ! fila == NULL
        Aí você chega, a fila não está mais vazia:
        ! fila != NULL, pois fila = voce
        E como você sabe que só tem você na fila, não terá ninguém atrás de você:
        ! voce -> proximo = NULL
        Se chegar outra pessoa (digamos, Alok), ela ficará atrás de você:
        ! voce -> proximo = Alok
        E como ele é o último da fila:
        ! Alok -> proximo = NULL
        Mas aí chega Bidu na fila, Alok deixa de ser o último:
        ! Alok -> proximo = Bidu
        E Bidu passa a ser o último:
        ! Bidu -> proximo = NULL

        Como sabemos quem vem atrás de cada pessoa, podemos fazer algo assim:
        * pessoa = voce -> proximo -> proximo
                  (você)   (Alok)     (Bidu)
        Podemos interpretar isso como:
            & Quem está atrás de você? Alok
            & Quem está atrás de Alok? Bidu

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

void inserirFila(No **fila, int num)
{
    No *novo = malloc(sizeof(No));
    No *aux;

    if (novo)
    {
        // Como ele será o último a ser adicionado, não terá ninguém depois dele.
        novo->proximo = NULL;
        novo->valor = num;

        if (*fila == NULL) // Fila vazia
        {
            *fila = novo;
        }
        else // Fila não vazia
        {
            // aux recebe o 1° da fila
            aux = *fila;
            // Enquanto o próximo depois de aux for diferente de NULL
            while (aux->proximo)
            {
                // aux irá receber o próximo
                aux = aux->proximo;
            }

            // Nesse momento, aux chegou ao final da fila
            // O próximo depois de aux será o novo nó
            aux->proximo = novo;
        }
    }
    else
    {
        wprintf(cor_vermelha L"Erro ao alocar Nó!" cor_branca);
    }
}

void inserirFilaPrioridade(No **fila, int num)
{
    No *novo = malloc(sizeof(No));
    No *aux;

    if (novo)
    {
        novo->proximo = NULL;
        novo->valor = num;

        if (*fila == NULL)
        {
            // Fila vazia
            *fila = novo;
        }
        else
        {
            // Fila não vazia

            // O novo nó faz parte da fila de prioridade
            if (num >= 60)
            {
                // Já tem, pelo menos, 1 na fila de prioridade
                if ((*fila)->valor >= 60)
                {
                    aux = *fila;

                    // Ficará procurando qual o último nó com valor >= 60
                    while (aux->proximo && aux->proximo->valor >= 60){
                        aux = aux->proximo;
                    }

                    // Como aux tem o último nó com valor >= 60, aux.proximo pegará o próximo nó
                    // Ou seja, o 1° nó da fila normal.
                    // O novo nó será colocado entre o aux e o aux.proximo.
                    novo->proximo = aux->proximo;

                    // O próximo depois do antigo último nó com valor >= 60 será o novo nó
                    aux->proximo = novo;
                }

                // Não tem ninguém na fila de prioridade
                else
                {
                    // O próximo depois do novo nó será o 1° da fila normal
                    novo->proximo = *fila;

                    // O 1° da fila será o novo nó
                    *fila = novo;
                }
            }

            // O novo nó não faz parte da fila de prioridade
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
        // remover recebe o 1° da fila
        remover = *fila;
        // o conteúdo de *fila recebe o 2° da fila
        *fila = remover->proximo;
    }

    return remover;
}

void imprimirFila(No *fila)
{
    // Se fila == NULL (fila vaiza), aux -> NULL
    // Se fila != NULL (fila não vazia), aux -> (!=) NULL, ou seja, o 1° da fila
    No *aux = fila;

    traco(1);

    // Comparando para saber se a fila original está vaiza.
    if (aux == NULL)
    {
        wprintf(cor_amarela L"Fila vazia." cor_branca);
    }
    else
    {
        wprintf(cor_ciano L"Início " cor_branca ">> ");
        while (fila)
        {
            wprintf(cor_ciano L"%d" cor_branca, fila->valor);
            if (fila->proximo != NULL)
            {
                wprintf(L", ");
            }
            fila = fila->proximo;
        }
    }

    traco(2);
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

        wprintf(L"Valor: \n\n" cor_amarela " 1 " cor_branca "| Inserir \n" cor_amarela " 2 " cor_branca "| Remover \n" cor_amarela " 3 " cor_branca "| Mostrar \n" cor_amarela " 4 " cor_branca "| Inserir com Prioridade\n" cor_amarela " 0 " cor_branca "| Sair\n\n"
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

            sleep_us(300000);
            break;
        case 2:
            traco(1);

            No *removido = removerFila(&fila);
            if (removido)
            {
                wprintf(L"Removido: " cor_vermelha "%d" cor_branca, removido->valor);
            }

            traco(2);

            sleep_us(1000000);
            break;
        case 3:

            imprimirFila(fila);

            sleep_us(2000000);
            break;

        case 4:
            traco(1);

            wprintf(L"Número: ");
            wscanf(L"%d", &num);
            inserirFilaPrioridade(&fila, num);

            sleep_us(300000);
            break;

        default:
            if (opcao != 0)
            {
                wprintf(cor_vermelha L"Opção inválida!" cor_branca);
            }
            break;
        }
    }

    traco(2);
    return 0;
}

typedef struct fila
{
    No *primeiro;
    No *fim;
    int tamanho;
} Fila;

void criaFila(Fila *fila)
{
    fila->primeiro = NULL;
    fila->fim = NULL;
    fila->tamanho = 0;
}

void inserirFila2(Fila *fila, int num)
{
    No *aux = malloc(sizeof(No));

    if (aux)
    {
        aux->proximo = NULL;
        aux->valor = num;

        // Se a fila estiver vaiza, ou seja, se o 1° for nulo
        if (fila->primeiro == NULL)
        {
            fila->primeiro = aux;
            fila->fim = aux;
        }
        else
        {
            // O novo nó será o próximo depois do último nó
            fila->fim->proximo = aux;
            // Já que o último deixou de ser último, é preciso mudar qual é o último
            fila->fim = aux;
        }

        fila->tamanho += 1;
    }
    else
    {
        wprintf(cor_vermelha L"Erro ao alocar memória!" cor_branca);
    }
}

No *removerFila2(Fila *fila)
{
    No *aux = NULL;

    if (fila->primeiro == NULL)
    {
        wprintf(cor_amarela L"Fila vaiza!" cor_branca);
    }
    else
    {
        // aux receberá o 1° da fila
        aux = fila->primeiro;
        // O 1° da fila será o próximo de aux
        // Se aux recebeu o 1°, o próximo dele será o 2°
        fila->primeiro = aux->proximo;
        fila->tamanho -= 1;
    }

    return aux;
}

void imprimirFila2(Fila *fila)
{
    traco(1);

    No *aux = fila->primeiro;

    if (aux == NULL)
    {
        wprintf(cor_amarela L"Lista vazia!" cor_branca);
    }
    else
    {
        wprintf(cor_ciano L"Início" cor_branca " >> ");
        while (aux)
        {
            wprintf(cor_ciano L"%d" cor_branca, aux->valor);
            if (aux->proximo != NULL)
            {
                wprintf(L", ");
            }
            aux = aux->proximo;
        }
    }

    traco(2);
}

/*
int main()
{

    inicioCodigo();

    Fila fila;
    criaFila(&fila);

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
            inserirFila2(&fila, num);

            sleep_us(300000);
            break;
        case 2:
            traco(1);

            No *removido = removerFila2(&fila);
            if (removido)
            {
                wprintf(L"Removido: " cor_vermelha "%d" cor_branca, removido->valor);
            }

            traco(2);

            sleep_us(1000000);
            break;
        case 3:

            imprimirFila2(&fila);

            sleep_us(2000000);
            break;

        case 0:
            break;

        default:
            if (opcao != 0)
            {
                wprintf(cor_vermelha L"Opção inválida!" cor_branca);
            }
            break;
        }
    }

    traco(2);
    return 0;
}
 */
