#include <cstdlib>
#include <iostream>
#include <GL/glut.h>
#include <math.h>

void init();
void draw_test();

void incrementoHorizontal();
void decrementoHorizontal();
void incrementoVertical();
void decrementoVertical();

void mouse_test(GLint button, GLint action, GLint x, GLint y);
void mouse_test2(GLint x, GLint y);
void mouse_test3(GLint x, GLint y);

void keybord_test(GLubyte key, GLint x, GLint y);
void keybord_test2(GLint key, GLint x, GLint y);

GLint WINDOW_WIDTH = 500,
      WINDOW_HEIGHT = 500;

// armazena os vértices de um objeto
struct VERTEX
{
    int pos_V[3][1];
};

VERTEX translacaoPixel(VERTEX vertice);
VERTEX produtoMatrizes(VERTEX vertice, int caso);
VERTEX produtoMatrizesMeio(VERTEX vertice, int caso);
VERTEX escalaPixel(VERTEX vertice, VERTEX centro);

// armazena a descrição geométrica de um objeto
struct OBJECT
{
    VERTEX *vertices;
    int nrvertices;
};

int matrizTranslacao[3][3] = {{1, 0, 0}, {0, 1, 0}, {0, 0, 1}};

int matrizEscalaX[3][3] = {{1, 0, 0}, {0, 1, 0}, {0, 0, 1}};
int matrizEscalaY[3][3] = {{1, 0, 0}, {0, 1, 0}, {0, 0, 1}};

void incrementoHorizontal(int caso)
{
    int matrizTemp[3][3];
    int matrizAumentoX[3][3] = {{1, 0, 1}, {0, 1, 0}, {0, 0, 1}};

    int aux = 0;
    for (int linha = 0; linha < 3; linha++)
    {
        for (int coluna = 0; coluna < 3; coluna++)
        {
            aux = 0;
            for (int i = 0; i < 3; i++)
            {
                if (caso)
                    aux += matrizTranslacao[linha][i] * matrizAumentoX[i][coluna];
                else
                    aux += matrizEscalaX[linha][i] * matrizAumentoX[i][coluna];

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
}

void decrementoHorizontal(int caso)
{
    int matrizTemp[3][3];
    int matrizReducaoX[3][3] = {{1, 0, -1}, {0, 1, 0}, {0, 0, 1}};

    int aux = 0;
    for (int linha = 0; linha < 3; linha++)
    {
        for (int coluna = 0; coluna < 3; coluna++)
        {
            aux = 0;
            for (int i = 0; i < 3; i++)
            {
                if (caso)
                    aux += matrizTranslacao[linha][i] * matrizReducaoX[i][coluna];
                else
                    aux += matrizEscalaX[linha][i] * matrizReducaoX[i][coluna];

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
}

void incrementoVertical(int caso)
{
    int matrizTemp[3][3];
    int matrizAumentoY[3][3] = {{1, 0, 0}, {0, 1, 1}, {0, 0, 1}};

    int aux = 0;
    for (int linha = 0; linha < 3; linha++)
    {
        for (int coluna = 0; coluna < 3; coluna++)
        {
            aux = 0;
            for (int i = 0; i < 3; i++)
            {
                if (caso)
                    aux += matrizTranslacao[linha][i] * matrizAumentoY[i][coluna];
                else
                    aux += matrizEscalaY[linha][i] * matrizAumentoY[i][coluna];
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
}

void decrementoVertical(int caso)
{
    int matrizTemp[3][3];
    int matrizReducaoY[3][3] = {{1, 0, 0}, {0, 1, -1}, {0, 0, 1}};

    int aux = 0;
    for (int linha = 0; linha < 3; linha++)
    {
        for (int coluna = 0; coluna < 3; coluna++)
        {
            aux = 0;
            for (int i = 0; i < 3; i++)
            {
                if (caso)
                    aux += matrizTranslacao[linha][i] * matrizReducaoY[i][coluna];
                else
                    aux += matrizEscalaY[linha][i] * matrizReducaoY[i][coluna];
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

    return matrizTemp;
}

VERTEX produtoMatrizesMeio(VERTEX vertice, int caso)
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
                if (caso)
                {
                    if (linha == 0 && i == 2)
                        aux += vertice.pos_V[i][0] * (matrizEscalaX[linha][i] / 2);
                    else
                        aux += vertice.pos_V[i][0] * matrizEscalaX[linha][i];
                }
                else
                {
                    if (linha == 1 && i == 2)
                        aux += vertice.pos_V[i][0] * (matrizEscalaY[linha][i] / 2);
                    else
                        aux += vertice.pos_V[i][0] * matrizEscalaY[linha][i];
                }
            }

            matrizTemp.pos_V[linha][0] = aux;
        }
    }

    return matrizTemp;
}

VERTEX escalaPixel(VERTEX vertice, VERTEX centro)
{
    VERTEX matrizTemp;

    // Movendo o pixel para uma posição relativa à origem
    matrizTemp.pos_V[0][0] = vertice.pos_V[0][0] - centro.pos_V[0][0];
    matrizTemp.pos_V[1][0] = vertice.pos_V[1][0] - centro.pos_V[1][0];

    // Aplicação da escala
    if (matrizEscalaX[0][2] > 0)
    {
        if (vertice.pos_V[0][0] > centro.pos_V[0][0])
            matrizTemp = produtoMatrizes(matrizTemp, 1);
        if (vertice.pos_V[0][0] == centro.pos_V[0][0])
            matrizTemp = produtoMatrizesMeio(matrizTemp, 1);
    }

    if (matrizEscalaX[0][2] < 0)
    {
        if (vertice.pos_V[0][0] < centro.pos_V[0][0])
            matrizTemp = produtoMatrizes(matrizTemp, 1);
        if (vertice.pos_V[0][0] == centro.pos_V[0][0])
            matrizTemp = produtoMatrizesMeio(matrizTemp, 1);
    }

    if (matrizEscalaY[1][2] > 0)
    {
        if (vertice.pos_V[1][0] > centro.pos_V[1][0])
            matrizTemp = produtoMatrizes(matrizTemp, 0);
        if (vertice.pos_V[1][0] == centro.pos_V[1][0])
            matrizTemp = produtoMatrizesMeio(matrizTemp, 0);
    }

    if (matrizEscalaY[1][2] < 0)
    {
        if (vertice.pos_V[1][0] < centro.pos_V[1][0])
            matrizTemp = produtoMatrizes(matrizTemp, 0);
        if (vertice.pos_V[1][0] == centro.pos_V[1][0])
            matrizTemp = produtoMatrizesMeio(matrizTemp, 0);
    }

    // Movendo o pixxel para a posição original
    matrizTemp.pos_V[0][0] = matrizTemp.pos_V[0][0] + centro.pos_V[0][0];
    matrizTemp.pos_V[1][0] = matrizTemp.pos_V[1][0] + centro.pos_V[1][0];
    return matrizTemp;
}

OBJECT *object; // objeto global que será desenhado

OBJECT *create_object()
{
    OBJECT *obj = (OBJECT *)malloc(sizeof(OBJECT));
    obj->nrvertices = 5;
    obj->vertices = (VERTEX *)malloc(obj->nrvertices * sizeof(VERTEX));
    obj->vertices[0].pos_V[0][0] = 250;
    obj->vertices[0].pos_V[1][0] = 130;
    obj->vertices[0].pos_V[2][0] = 1;
    obj->vertices[1].pos_V[0][0] = 250;
    obj->vertices[1].pos_V[1][0] = 170;
    obj->vertices[1].pos_V[2][0] = 1;
    obj->vertices[2].pos_V[0][0] = 220;
    obj->vertices[2].pos_V[1][0] = 190;
    obj->vertices[2].pos_V[2][0] = 1;
    obj->vertices[3].pos_V[0][0] = 190;
    obj->vertices[3].pos_V[1][0] = 170;
    obj->vertices[3].pos_V[2][0] = 1;
    obj->vertices[4].pos_V[0][0] = 190;
    obj->vertices[4].pos_V[1][0] = 130;
    obj->vertices[4].pos_V[2][0] = 1;
    return obj;
}

VERTEX calculate_centroid(OBJECT *obj)
{
    VERTEX cent;
    cent.pos_V[0][0] = 0;
    cent.pos_V[1][0] = 0;
    cent.pos_V[2][0] = 1;
    for (int i = 0; i < obj->nrvertices; i++)
    {
        cent.pos_V[0][0] += obj->vertices[i].pos_V[0][0];
        cent.pos_V[1][0] += obj->vertices[i].pos_V[1][0];
    }
    cent.pos_V[0][0] /= obj->nrvertices;
    cent.pos_V[1][0] /= obj->nrvertices;
    return cent;
}

void init()
{
    glClearColor(1.0, 1.0, 1.0, 1.0);
    glMatrixMode(GL_PROJECTION);

    gluOrtho2D(0, WINDOW_WIDTH, 0, WINDOW_HEIGHT);
    object = create_object(); // cria o objeto
}

void draw_object(OBJECT *obj)
{
    VERTEX pontoTransladado;
    VERTEX pontoEscalado;
    VERTEX pontoCentral = translacaoPixel(calculate_centroid(obj));

    glBegin(GL_POLYGON); // desenha uma linha
    for (int i = 0; i < obj->nrvertices; i++)
    {
        pontoTransladado = translacaoPixel(obj->vertices[i]);
        pontoEscalado = escalaPixel(pontoTransladado, pontoCentral);
        glVertex2i(pontoEscalado.pos_V[0][0], pontoEscalado.pos_V[1][0]);
    }
    glEnd();
}

void draw_test()
{
    glClear(GL_COLOR_BUFFER_BIT); // desenha o fundo (limpa a janela)
    glMatrixMode(GL_MODELVIEW);   // garante que a matrix seja a ModelView
    glLoadIdentity();             // carrega a matrix identidade

    glColor3f(0.0, 0.0, 1.0); // altera o atributo de cor
    draw_object(object);      // desenha o objeto

    VERTEX cent = calculate_centroid(object); // calcula o centróide

    glFlush(); // processa as rotinas OpenGL o mais rápido possível
}

void mouse_test(GLint button, GLint action, GLint x, GLint y)
{
    switch (button)
    {
    case GLUT_LEFT_BUTTON:
    {
        std::cout << "Esquerda";
        break;
    }
    case GLUT_MIDDLE_BUTTON:
    {
        std::cout << "Meio";
        break;
    }
    case GLUT_RIGHT_BUTTON:
    {
        std::cout << "Direita";
        break;
    }
    default:
        break;
    }

    if (action == GLUT_DOWN)
        std::cout << " preciona";
    else // GLUT_UP
        std::cout << " libera";

    // x cresce da esquerda pra direita. O y cresce de cima para baixo
    std::cout << " em (x:" << x << ", y:" << y << ")";

    std::cout << "\n";
}

void mouse_test2(GLint x, GLint y)
{
    std::cout << "Movendo mouse sem clicar para posicao (x:" << x << ", y:" << y << ")\n";
}

void mouse_test3(GLint x, GLint y)
{
    std::cout << "Arrastando o mouse para posicao (x:" << x << ", y:" << y << ")\n";
}

// funcao para processar eventos de teclado
void keybord_test(GLubyte key, GLint x, GLint y)
{
    GLint m = glutGetModifiers();

    if (m == GLUT_ACTIVE_SHIFT)
        std::cout << "Shift ou Caps ";
    else if (m == GLUT_ACTIVE_CTRL)
        std::cout << "Control ";
    else if (m == GLUT_ACTIVE_ALT)
        std::cout << "Alt ";

    // VERIFICAR TABELA ASCII QUANDO O CTRL ESTIVER PRECIONADO COM ALGUMA
    // LETRA
    if (m == GLUT_ACTIVE_CTRL && (GLint)key == 4)
        exit(EXIT_SUCCESS);

    std::cout << "Tecla: " << (GLint)key << " (x:" << x << ", y:" << y << ")\n";

    // ESC = 27
    if (key == 27)
        glutReshapeWindow(WINDOW_WIDTH, WINDOW_HEIGHT);

    if (key == 119 || key == 87) // W
        incrementoVertical(0);
    if (key == 97 || key == 65) // A
        decrementoHorizontal(0);
    if (key == 115 || key == 83) // S
        decrementoVertical(0);
    if (key == 100 || key == 68) // D
        incrementoHorizontal(0);
    glutPostRedisplay();

    printf("\nESCALA X: \n");
    for (int linha = 0; linha < 3; linha++)
    {
        for (int coluna = 0; coluna < 3; coluna++)
        {
            printf("%d ", matrizEscalaX[linha][coluna]);
            if (coluna == 2)
                printf("\n");
        }
    }

    printf("\nESCALA Y: \n");
    for (int linha = 0; linha < 3; linha++)
    {
        for (int coluna = 0; coluna < 3; coluna++)
        {
            printf("%d ", matrizEscalaY[linha][coluna]);
            if (coluna == 2)
                printf("\n");
        }
    }
}

void keybord_test2(GLint key, GLint x, GLint y)
{
    // GLUT_KEY_F1 .. GLUT_KEY_F12
    // GLUT_KEY_UP, GLUT_KEY_DOWN, GLUT_KEY_LEFT, GLUT_KEY_RIGHT
    // GLUT_KEY_PAGE_DOWN, GLUT_KEY_HOME etc.

    std::cout << "\nTecla especial: " << key << " (x:" << x << ", y:" << y << ")\n";

    if (key == GLUT_KEY_F11)
        glutFullScreen();

    if (key == 100)
        decrementoHorizontal(1); // tecla para esquerda
    if (key == 102)
        incrementoHorizontal(1); // tecla para direita
    if (key == 103)
        decrementoVertical(1); // tecla para baixo
    if (key == 101)
        incrementoVertical(1); // tecla para cima

    printf("\nTRANSLACAO: \n");
    for (int linha = 0; linha < 3; linha++)
    {
        for (int coluna = 0; coluna < 3; coluna++)
        {
            printf("%d ", matrizTranslacao[linha][coluna]);
            if (coluna == 2)
                printf("\n");
        }
    }

    // printf("\nt_x_inc = %d", matrizTranslacao[0][2]);
    // printf("\nt_y_inc = %d", matrizTranslacao[1][2]);
    glutPostRedisplay();
}

int main(int argc, char *argv[])
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);

    GLint screen_width = glutGet(GLUT_SCREEN_WIDTH),
          screen_height = glutGet(GLUT_SCREEN_HEIGHT);

    glutInitWindowPosition((screen_width - WINDOW_WIDTH) / 2, (screen_height - WINDOW_WIDTH) / 2);
    glutInitWindowSize(WINDOW_WIDTH, WINDOW_WIDTH);
    glutCreateWindow("OpenGL - Transformacoes");

    init();
    glutDisplayFunc(draw_test);

    glutMouseFunc(mouse_test);

    glutKeyboardFunc(keybord_test);
    glutSpecialFunc(keybord_test2);

    glutMainLoop();

    return EXIT_SUCCESS;
}
