#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
#include <unistd.h>

// armazena os vértices de um objeto
typedef struct vertex
{
    int pos_V[3][1];
} VERTEX;

int matrizMudanca[3][3] = {{1, 0, 0}, {0, 1, 0}, {0, 0, 1}};
int matrizAumentoX[3][3] = {{1, 0, 1}, {0, 1, 0}, {0, 0, 1}};
int matrizAumentoY[3][3] = {{1, 0, 0}, {0, 1, 1}, {0, 0, 1}};
int matrizReducaoX[3][3] = {{1, 0, -1}, {0, 1, 0}, {0, 0, 1}};
int matrizReducaoY[3][3] = {{1, 0, 0}, {0, 1, -1}, {0, 0, 1}};

void incrementoHorizontal()
{
    int matrizTemp[3][3];

    int aux = 0;
    for (int linha = 0; linha < 3; linha++)
    {
        for (int coluna = 0; coluna < 3; coluna++)
        {
            aux = 0;
            for (int i = 0; i < 3; i++)
            {
                aux += matrizMudanca[linha][i] * matrizAumentoX[i][coluna];
                matrizTemp[linha][coluna] = aux;
            }
        }
    }

    for (int linha = 0; linha < 3; linha++)
    {
        for (int coluna = 0; coluna < 3; coluna++)
        {
            matrizMudanca[linha][coluna] = matrizTemp[linha][coluna];
        }
    }

    printf("\n");

    mostrarMatriz();
}

void decrementoHorizontal()
{
    int matrizTemp[3][3];

    int aux = 0;
    for (int linha = 0; linha < 3; linha++)
    {
        for (int coluna = 0; coluna < 3; coluna++)
        {
            aux = 0;
            for (int i = 0; i < 3; i++)
            {
                aux += matrizMudanca[linha][i] * matrizReducaoX[i][coluna];
                matrizTemp[linha][coluna] = aux;
            }
        }
    }

    for (int linha = 0; linha < 3; linha++)
    {
        for (int coluna = 0; coluna < 3; coluna++)
        {
            matrizMudanca[linha][coluna] = matrizTemp[linha][coluna];
        }
    }

    printf("\n");
    mostrarMatriz();
}

void incrementoVertical()
{
    int matrizTemp[3][3];

    int aux = 0;
    for (int linha = 0; linha < 3; linha++)
    {
        for (int coluna = 0; coluna < 3; coluna++)
        {
            aux = 0;
            for (int i = 0; i < 3; i++)
            {
                aux += matrizMudanca[linha][i] * matrizAumentoY[i][coluna];
                matrizTemp[linha][coluna] = aux;
            }
        }
    }

    for (int linha = 0; linha < 3; linha++)
    {
        for (int coluna = 0; coluna < 3; coluna++)
        {
            matrizMudanca[linha][coluna] = matrizTemp[linha][coluna];
        }
    }

    printf("\n");
    mostrarMatriz();
}

void decrementoVertical()
{
    int matrizTemp[3][3];

    int aux = 0;
    for (int linha = 0; linha < 3; linha++)
    {
        for (int coluna = 0; coluna < 3; coluna++)
        {
            aux = 0;
            for (int i = 0; i < 3; i++)
            {
                aux += matrizMudanca[linha][i] * matrizReducaoY[i][coluna];
                matrizTemp[linha][coluna] = aux;
            }
        }
    }

    for (int linha = 0; linha < 3; linha++)
    {
        for (int coluna = 0; coluna < 3; coluna++)
        {
            matrizMudanca[linha][coluna] = matrizTemp[linha][coluna];
        }
    }

    printf("\n");
    mostrarMatriz();
}

void mostrarMatriz()
{
    for (int linha = 0; linha < 3; linha++)
    {
        for (int coluna = 0; coluna < 3; coluna++)
        {
            printf("%d ", matrizMudanca[linha][coluna]);
            if (coluna == 2)
                printf("\n");
        }
    }
    printf("\n");
}

VERTEX translacaoPixel(VERTEX vertice)
{
    VERTEX matrizTemp;

    int aux = 0;
    for (int linha = 0; linha < 3; linha++)
    {
        for (int coluna = 0; coluna < 3; coluna++)
        {
            aux = 0;
            for (int i = 0; i < 3; i++)
            {
                aux += vertice.pos_V[i][0] * matrizMudanca[linha][i];
                matrizTemp.pos_V[linha][0] = aux;
            }
        }
    }

    for (int linha = 0; linha < 3; linha++)
    {
        for (int coluna = 0; coluna < 1; coluna++)
        {
            printf("%d ", matrizTemp.pos_V[linha][coluna]);
            if (coluna == 0)
                printf("\n");
        }
    }

    return matrizTemp;

}

int main()
{

    VERTEX ponto, ponto2;
    ponto.pos_V[0][0] = 3;
    ponto.pos_V[1][0] = 5;
    ponto.pos_V[2][0] = 1;

    incrementoHorizontal();
    incrementoVertical();
    ponto2 = translacaoPixel(ponto);

    for (int i = 0; i < 3; i++)
    {
        printf("%d \n", ponto2.pos_V[i][0]);
    }

    return 0;
}