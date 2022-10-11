// HERIBERTO
// JACKSON
#include <cstdlib>
#include <iostream>
#include <GL/glut.h>
#include <math.h>

void init();
void draw_test();

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
    int x;
    int y;
};

// armazena a descrição geométrica de um objeto
struct OBJECT
{
    VERTEX *vertices;
    int nrvertices;
};

double tx = 0, ty = 0, sx = 1, sy = 1;

int angulo = 0;
int velocidade = 1;
double s = 0.0; // armazenar seno (da matriz de rotacao)
double c = 1.0; // armazenar cosseno (da matriz de rotacao)

OBJECT *object; // objeto global que será desenhado

OBJECT *create_object()
{
    OBJECT *obj = (OBJECT *)malloc(sizeof(OBJECT));
    obj->nrvertices = 5;
    obj->vertices = (VERTEX *)malloc(obj->nrvertices * sizeof(VERTEX));
    obj->vertices[0].x = 250;
    obj->vertices[0].y = 130;
    obj->vertices[1].x = 250;
    obj->vertices[1].y = 170;
    obj->vertices[2].x = 220;
    obj->vertices[2].y = 190;
    obj->vertices[3].x = 190;
    obj->vertices[3].y = 170;
    obj->vertices[4].x = 190;
    obj->vertices[4].y = 130;
    return obj;
}

VERTEX calculate_centroid(OBJECT *obj)
{
    int i;
    VERTEX cent;
    cent.x = 0;
    cent.y = 0;
    for (i = 0; i < obj->nrvertices; i++)
    {
        cent.x += obj->vertices[i].x;
        cent.y += obj->vertices[i].y;
    }
    cent.x /= obj->nrvertices;
    cent.y /= obj->nrvertices;
    return cent;
}

void init()
{
    glClearColor(1.0, 1.0, 1.0, 1.0);
    glMatrixMode(GL_PROJECTION);

    gluOrtho2D(0, WINDOW_WIDTH, 0, WINDOW_HEIGHT);
    object = create_object(); // cria o objeto
}

// FUNÇÃO QUE REALIZA A TRANSLAÇÃO E ESCALA DO OBJETO
void aplicaTransformacoes(VERTEX vertex, VERTEX centro, int *matrizFinal)
{

    double valorK = -sx * centro.x + centro.x + tx;
    double valorJ = -sy * centro.y + centro.y + ty;

    double valorM = centro.x - centro.x * c + centro.y * s;
    double valorN = centro.y - centro.y * c - centro.x * s;

    int matrizObjeto[3] = {vertex.x, vertex.y, 1};
    // int matrizObjeto[3] = {vertex.x - centro.x, vertex.y - centro.y, 1};
    double mT[3][3] = {sx, 0, valorK,
                       0, sy, valorJ,
                       0, 0, 1};

    double mR[3][3] = {c, -s, 0,
                       s, c, 0,
                       0, 0, 1};

    double matrizResultante[3][3] = {mT[0][0] * mR[0][0], mT[0][0] * mR[0][1], mT[0][2],
                                     mT[1][1] * mR[1][0], mT[1][1] * mR[1][1], mT[1][2],
                                     0, 0, 1};

    double matriz[3][3] = {sx * c, -sx * s, sx * (centro.x - centro.x * c + centro.y * s) - sx * centro.x + centro.x + tx,
                           sy * s, sy * c, sy * (centro.y - centro.y * c - centro.x * s) - sy * centro.y + centro.y + ty,
                           0, 0, 1};

    printf("\n");

    for (int j = 0; j < 3; j++)
    {
        for (int k = 0; k < 3; k++)
        {
            matrizFinal[j] += matrizObjeto[k] * matriz[j][k];
        }
    }

    // matrizFinal[0] += centro.x;
    // matrizFinal[1] += centro.y;
}

void moveOrigem(OBJECT *obj)
{
    VERTEX centro = calculate_centroid(obj);
    int i, j, k;

    for (i = 0; i < obj->nrvertices; i++)
    {
        obj->vertices[i].x -= centro.x;
        obj->vertices[i].y -= centro.y;
    }
}

void draw_object(OBJECT *obj)
{
    VERTEX centro = calculate_centroid(obj);
    int i, j, k;
    glBegin(GL_POLYGON); // Poligono preenchido
    for (i = 0; i < obj->nrvertices; i++)
    {
        int matrizFinal[3] = {0, 0, 0};
        aplicaTransformacoes(obj->vertices[i], centro, matrizFinal);
        glVertex2i(matrizFinal[0], matrizFinal[1]);
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
        if (action == GLUT_DOWN)
            angulo += velocidade;
        s = sin((angulo * M_PI) / 180);
        c = cos((angulo * M_PI) / 180);
        printf("\nA: %d || S: %f || C: %f || V: %d \n", angulo, s, c, velocidade);

        break;
    case GLUT_RIGHT_BUTTON:
        if (action == GLUT_DOWN)
            angulo += velocidade;
        s = sin((angulo * M_PI) / 180);
        c = cos((angulo * M_PI) / 180);
        printf("\nA: %d || S: %f || C: %f || V: %d \n", angulo, s, c, velocidade);
        break;
    default:
        break;
    }
    glutPostRedisplay();
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

    // Escala
    if (key == 119)
    {
        sy += 0.1; // tecla W
    }
    if (key == 115)
    {
        sy -= 0.1; // tecla S
    }
    if (key == 97)
    {
        sx -= 0.1; // tecla A
    }
    if (key == 100)
    {
        sx += 0.1; // tecla D
    }
    if (key == 61)
    {
        velocidade += 1;
        printf("\nA: %d || S: %f || C: %f || V: %d \n", angulo, s, c, velocidade);
    }
    if (key == 45)
    {
        velocidade -= 1;
        printf("\nA: %d || S: %f || C: %f || V: %d \n", angulo, s, c, velocidade);
    }
    if (key == 32)
    {
        moveOrigem(object);
    }

    glutPostRedisplay();

    // ESC = 27
    if (key == 27)
        glutReshapeWindow(WINDOW_WIDTH, WINDOW_HEIGHT);
}

void keybord_test2(GLint key, GLint x, GLint y)
{
    // GLUT_KEY_F1 .. GLUT_KEY_F12
    // GLUT_KEY_UP, GLUT_KEY_DOWN, GLUT_KEY_LEFT, GLUT_KEY_RIGHT
    // GLUT_KEY_PAGE_DOWN, GLUT_KEY_HOME etc.
    if (key == GLUT_KEY_F11)
        glutFullScreen();

    // Movimento
    if (key == 100)
    {
        tx--; // tecla para esquerda
    }
    if (key == 102)
    {
        tx++; // tecla para direita
    }
    if (key == 103)
    {
        ty--; // tecla para baixo
    }
    if (key == 101)
    {
        ty++; // tecla para cima
    }
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
    glutCreateWindow("OpenGL - Rotacoes");

    init();
    glutDisplayFunc(draw_test);

    glutMouseFunc(mouse_test);

    glutKeyboardFunc(keybord_test);
    glutSpecialFunc(keybord_test2);

    glutMainLoop();

    return EXIT_SUCCESS;
}
