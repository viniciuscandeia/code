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

int matrizTranslacao[3][3] = {{1, 0, 0}, {0, 1, 0}, {0, 0, 1}};

int matrizEscalaX[3][3] = {{1, 0, 0}, {0, 0, 0}, {0, 0, 0}};
int matrizEscalaY[3][3] = {{0, 0, 0}, {0, 1, 0}, {0, 0, 0}};

void incrementoHorizontal(int caso)
{
    int matrizTemp[3][3];
    int t_matrizAumentoX[3][3] = {{1, 0, 1}, {0, 1, 0}, {0, 0, 1}};
    int e_matrizAumentoX[3][3] = {{1, 0, 0}, {0, 0, 0}, {1, 0, 0}};

    matrizEscalaX[0][2] = 1;

    int aux = 0;
    for (int linha = 0; linha < 3; linha++)
    {
        for (int coluna = 0; coluna < 3; coluna++)
        {
            aux = 0;
            for (int i = 0; i < 3; i++)
            {
                if (caso)
                    aux += matrizTranslacao[linha][i] * t_matrizAumentoX[i][coluna];

                else
                    aux += matrizEscalaX[linha][i] * e_matrizAumentoX[i][coluna];

                matrizTemp[linha][coluna] = aux;
            }
        }
    }

    for (int linha = 0; linha < 3; linha++)
    {
        for (int coluna = 0; coluna < 3; coluna++)
        {
            if (caso)
                matrizTranslacao[linha][coluna] = matrizTemp[linha][coluna];
            else
                matrizEscalaX[linha][coluna] = matrizTemp[linha][coluna];
        }
    }

    matrizEscalaX[0][2] = 0;
}

void decrementoHorizontal(int caso)
{
    int matrizTemp[3][3];
    int t_matrizReducaoX[3][3] = {{1, 0, -1}, {0, 1, 0}, {0, 0, 1}};
    int e_matrizReducaoX[3][3] = {{1, 0, 0}, {0, 0, 0}, {-1, 0, 0}};

    matrizEscalaX[0][2] = 1;

    int aux = 0;
    for (int linha = 0; linha < 3; linha++)
    {
        for (int coluna = 0; coluna < 3; coluna++)
        {
            aux = 0;
            for (int i = 0; i < 3; i++)
            {
                if (caso)
                    aux += matrizTranslacao[linha][i] * t_matrizReducaoX[i][coluna];
                else
                    aux += matrizEscalaX[linha][i] * e_matrizReducaoX[i][coluna];

                matrizTemp[linha][coluna] = aux;
            }
        }
    }

    for (int linha = 0; linha < 3; linha++)
    {
        for (int coluna = 0; coluna < 3; coluna++)
        {
            if (caso)
                matrizTranslacao[linha][coluna] = matrizTemp[linha][coluna];
            else
                matrizEscalaX[linha][coluna] = matrizTemp[linha][coluna];
        }
    }

    matrizEscalaX[0][2] = 0;
}

void incrementoVertical(int caso)
{
    int matrizTemp[3][3];
    int t_matrizAumentoY[3][3] = {{1, 0, 0}, {0, 1, 1}, {0, 0, 1}};
    int e_matrizAumentoY[3][3] = {{0, 1, 0}, {0, 1, 0}, {0, 0, 0}};

    matrizEscalaY[1][0] = 1;

    int aux = 0;
    for (int linha = 0; linha < 3; linha++)
    {
        for (int coluna = 0; coluna < 3; coluna++)
        {
            aux = 0;
            for (int i = 0; i < 3; i++)
            {
                if (caso)
                    aux += matrizTranslacao[linha][i] * t_matrizAumentoY[i][coluna];
                else
                    aux += matrizEscalaY[linha][i] * e_matrizAumentoY[i][coluna];
                matrizTemp[linha][coluna] = aux;
            }
        }
    }

    for (int linha = 0; linha < 3; linha++)
    {
        for (int coluna = 0; coluna < 3; coluna++)
        {
            if (caso)
                matrizTranslacao[linha][coluna] = matrizTemp[linha][coluna];
            else
                matrizEscalaY[linha][coluna] = matrizTemp[linha][coluna];
        }
    }

    matrizEscalaY[1][0] = 0;
}

void decrementoVertical(int caso)
{
    int matrizTemp[3][3];
    int t_matrizReducaoY[3][3] = {{1, 0, 0}, {0, 1, -1}, {0, 0, 1}};
    int e_matrizReducaoY[3][3] = {{0, -1, 0}, {0, 1, 0}, {0, 0, 0}};

    matrizEscalaY[1][0] = 1;

    int aux = 0;
    for (int linha = 0; linha < 3; linha++)
    {
        for (int coluna = 0; coluna < 3; coluna++)
        {
            aux = 0;
            for (int i = 0; i < 3; i++)
            {
                if (caso)
                    aux += matrizTranslacao[linha][i] * t_matrizReducaoY[i][coluna];
                else
                    aux += matrizEscalaY[linha][i] * e_matrizReducaoY[i][coluna];
                matrizTemp[linha][coluna] = aux;
            }
        }
    }

    for (int linha = 0; linha < 3; linha++)
    {
        for (int coluna = 0; coluna < 3; coluna++)
        {
            if (caso)
                matrizTranslacao[linha][coluna] = matrizTemp[linha][coluna];
            else
                matrizEscalaY[linha][coluna] = matrizTemp[linha][coluna];
        }
    }

    matrizEscalaY[1][0] = 0;
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
                aux += vertice.pos_V[i][0] * matrizTranslacao[linha][i];
                matrizTemp.pos_V[linha][0] = aux;
            }
        }
    }

    return matrizTemp;
}

VERTEX produtoMatrizes(VERTEX vertice, int caso)
{
    VERTEX matrizTemp;

    matrizEscalaX[1][1] = 1;
    matrizEscalaY[0][0] = 1;

    int aux = 0;
    for (int linha = 0; linha < 3; linha++)
    {
        for (int coluna = 0; coluna < 3; coluna++)
        {
            aux = 0;
            for (int i = 0; i < 3; i++)
            {
                if (caso)
                    aux += vertice.pos_V[i][0] * matrizEscalaX[linha][i];
                else
                    aux += vertice.pos_V[i][0] * matrizEscalaY[linha][i];
                matrizTemp.pos_V[linha][0] = aux;
            }
        }
    }

    matrizEscalaX[1][1] = 0;
    matrizEscalaY[0][0] = 0;

    return matrizTemp;
}

VERTEX escalaPixel(VERTEX vertice, VERTEX centro)
{
    VERTEX matrizTemp;

    if (matrizEscalaX[0][2] > 0) // Crescimento para direita
    {
        if (vertice.pos_V[0][0] >= centro.pos_V[0][0])
            matrizTemp = produtoMatrizes(vertice, 1);
    }

    if (matrizEscalaX[0][2] < 0) // Crescimento para esquerda
    {
        if (vertice.pos_V[0][0] <= centro.pos_V[0][0])
            matrizTemp = produtoMatrizes(vertice, 1);
    }

    if (matrizEscalaY[1][2] > 0) // Crescimento para cima
    {
        if (vertice.pos_V[1][0] >= centro.pos_V[1][0])
            matrizTemp = produtoMatrizes(vertice, 0);
    }

    if (matrizEscalaY[1][2] < 0) // Crescimento para baixo
    {
        if (vertice.pos_V[1][0] <= centro.pos_V[1][0])
            matrizTemp = produtoMatrizes(vertice, 0);
    }

    return matrizTemp;
}

void mostrarMatriz()
{
    for (int linha = 0; linha < 3; linha++)
    {
        for (int coluna = 0; coluna < 3; coluna++)
        {
            printf("%d ", matrizTranslacao[linha][coluna]);
            if (coluna == 2)
                printf("\n");
        }
    }
    printf("\n");
}

void mostrarMatrizX()
{
    for (int linha = 0; linha < 3; linha++)
    {
        for (int coluna = 0; coluna < 3; coluna++)
        {
            printf("%d ", matrizEscalaX[linha][coluna]);
            if (coluna == 2)
                printf("\n");
        }
    }
    printf("\n");
}

int main()
{

    VERTEX ponto, ponto2;
    ponto.pos_V[0][0] = 3;
    ponto.pos_V[1][0] = 5;
    ponto.pos_V[2][0] = 1;

    incrementoHorizontal(1);
    incrementoVertical(1);
    ponto2 = translacaoPixel(ponto);

    for (int i = 0; i < 3; i++)
    {
        printf("%d \n", ponto2.pos_V[i][0]);
    }

    mostrarMatrizX();

    incrementoHorizontal(0);
    incrementoHorizontal(0);
    incrementoVertical(0);
    incrementoVertical(0);

    mostrarMatrizX();

    ponto2 = produtoMatrizes(ponto2, 1);
    ponto2 = produtoMatrizes(ponto2, 0);

    for (int i = 0; i < 3; i++)
    {
        printf("%d \n", ponto2.pos_V[i][0]);
    }

    return 0;
}