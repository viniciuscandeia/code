#include <stdio.h>
#include <wchar.h>
#include <locale.h>
#include <time.h>

#include "aditivos.h"

/* Função para limpar o buffer */
void limparBuffer(void)
{
    scanf("%*[^\n]%*1[\n]");
}

/* Função para limpar a tela */
void limpatela(void)
{
    sleep(1);
    printf("\e[1;1H\e[2J");
}

/* Traço para separar as partes da execução */
void traco(int valor)
{
    // Começo do código
    if (valor == 0)
    {
        wprintf(cor_azul L">-" cor_branca);
        for (int i = 0; i < 13; i++)
        {
            if (i % 2 == 0)
            {
                wprintf(cor_vermelha L"<>" cor_branca);
            }
            else
            {
                wprintf(cor_azul L"<>" cor_branca);
            }
            wprintf(cor_branca L"-" cor_branca);
        }
        wprintf(cor_azul L"<\n\n" cor_branca);
    }

    // Após um scanf
    if (valor == 1)
    {
        wprintf(cor_azul L"\n>-" cor_branca);
        for (int i = 0; i < 13; i++)
        {
            if (i % 2 == 0)
            {
                wprintf(cor_vermelha L"<>" cor_branca);
            }
            else
            {
                wprintf(cor_azul L"<>" cor_branca);
            }
            wprintf(cor_branca L"-" cor_branca);
        }
        wprintf(cor_azul L"<\n\n" cor_branca);
    }

    // Resto do código
    if (valor != 0 && valor != 1)
    {
        wprintf(cor_azul L"\n\n>-" cor_branca);
        for (int i = 0; i < 13; i++)
        {
            if (i % 2 == 0)
            {
                wprintf(cor_vermelha L"<>" cor_branca);
            }
            else
            {
                wprintf(cor_azul L"<>" cor_branca);
            }
            wprintf(cor_branca L"-" cor_branca);
        }
        wprintf(cor_azul L"<\n\n" cor_branca);
    }
}

void inicioCodigo(void)
{
    setlocale(LC_CTYPE, "");
    setlocale(LC_NUMERIC, NULL);

    limpatela();
    traco(0);

}