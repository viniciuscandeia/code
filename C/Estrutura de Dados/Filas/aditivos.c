#include <stdio.h>
#include <wchar.h>
#include <locale.h>

#ifdef __unix__      
    #include <unistd.h>
    #include <stdlib.h>

#elif defined(_WIN32) || defined(WIN32) 
   #define OS_Windows
   #include <windows.h>

#endif

#include "aditivos.h"

/* Função para limpar o buffer */
void limparBuffer(void)
{
    scanf("%*[^\n]%*1[\n]");
}

/* Função para limpar a tela */
void limpatela(void)
{
    #ifdef OS_Windows
        system("cls");

    #else
        system("clear");

    #endif
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