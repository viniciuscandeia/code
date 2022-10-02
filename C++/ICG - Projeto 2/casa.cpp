#include <stdlib.h>
#include <GL/glut.h>
#include <iostream>

using namespace std;

GLint WINDOW_WIDTH = 601,
      WINDOW_HEIGHT = 601;

void InitOpenGL(int *argc, char **argv)
{
    glutInit(argc, argv);

    // Define do modo de operação da GLUT
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);

    GLint screen_width = glutGet(GLUT_SCREEN_WIDTH),
          screen_height = glutGet(GLUT_SCREEN_HEIGHT);

    // Especifica a posição inicial da janela GLUT
    // glutInitWindowPosition(5, 5);
    glutInitWindowPosition((screen_width - WINDOW_WIDTH) / 2, (screen_height - WINDOW_WIDTH) / 2);

    // Especifica o tamanho inicial em pixels da janela GLUT
    glutInitWindowSize(WINDOW_WIDTH, WINDOW_HEIGHT);

    // Cria a janela passando como argumento o título da mesma
    glutCreateWindow("Meu primeiro app com OpenGL");
}

// Função callback chamada quando o tamanho da janela é alterado
void AlteraTamanhoJanela(GLsizei w, GLsizei h)
{
    // To Do
}

void Desenha(GLvoid)
{

    // Limpa a janela de visualização com a cor
    // de fundo definida previamente
    glClear(GL_COLOR_BUFFER_BIT);

    // Altera a cor do desenho para vermelho
    glColor3f(0.0f, 0.0f, 0.0f);

    glPointSize(5.f);

    glLineWidth(3.0f); // aumenta a espessura das linhas

    // Casa - PINTURA
    glColor3f(0.9f, 0.9f, 0.9f);
    glBegin(GL_POLYGON);
    glVertex2f(46, 400 - 183);
    glVertex2f(429, 400 - 182);
    glVertex2f(429, 400 - 364);
    glVertex2f(46, 400 - 364);
    glEnd();

    glBegin(GL_TRIANGLES);
    glVertex2f(141, 400 - 183);
    glVertex2f(231, 400 - 67);
    glVertex2f(319, 400 - 182);
    glEnd();

    // Telhado - PINTURA
    glColor3f(0.8f, 0.0f, 0.0f);
    glBegin(GL_POLYGON);
    glVertex2f(15, 400 - 182);
    glVertex2f(52, 400 - 80);
    glVertex2f(220, 400 - 80);
    glVertex2f(141, 400 - 182);
    glEnd();

    glBegin(GL_POLYGON);
    glVertex2f(421, 400 - 80);
    glVertex2f(241, 400 - 80);
    glVertex2f(319, 400 - 182);
    glVertex2f(458, 400 - 182);
    glEnd();

    // Telhado - traçado
    glColor3f(0.0f, 0.0f, 0.0f);
    glBegin(GL_LINE_LOOP);
    glVertex2f(15, 400 - 182);
    glVertex2f(52, 400 - 80);
    glVertex2f(220, 400 - 80);
    glVertex2f(141, 400 - 182);
    glEnd();

    glBegin(GL_LINE_LOOP);
    glVertex2f(421, 400 - 80);
    glVertex2f(241, 400 - 80);
    glVertex2f(319, 400 - 182);
    glVertex2f(458, 400 - 182);
    glEnd();

    glBegin(GL_LINES);

    glVertex2f(60, 400 - 183);
    glVertex2f(89, 400 - 79);

    glVertex2f(103, 400 - 183);
    glVertex2f(127, 400 - 79);

    glVertex2f(151, 400 - 170);
    glVertex2f(169, 400 - 79);

    glVertex2f(297, 400 - 79);
    glVertex2f(303, 400 - 162);

    glVertex2f(334, 400 - 79);
    glVertex2f(350, 400 - 183);

    glVertex2f(379, 400 - 79);
    glVertex2f(400, 400 - 183);

    glVertex2f(40, 400 - 115);
    glVertex2f(79, 400 - 115);

    glVertex2f(66, 400 - 160);
    glVertex2f(108, 400 - 160);

    glVertex2f(123, 400 - 95);
    glVertex2f(166, 400 - 95);

    glVertex2f(157, 400 - 143);
    glVertex2f(172, 400 - 143);

    glVertex2f(277, 400 - 127);
    glVertex2f(300, 400 - 127);

    glVertex2f(303, 400 - 160);
    glVertex2f(347, 400 - 160);

    glVertex2f(339, 400 - 112);
    glVertex2f(385, 400 - 112);

    glVertex2f(395, 400 - 160);
    glVertex2f(449, 400 - 160);

    glEnd();

    glBegin(GL_LINE_LOOP);
    glVertex2f(46, 400 - 183);
    glVertex2f(141, 400 - 183);
    glVertex2f(231, 400 - 67);
    glVertex2f(319, 400 - 182);
    glVertex2f(429, 400 - 182);
    glVertex2f(429, 400 - 364);
    glVertex2f(46, 400 - 364);
    glEnd();

    // Janela 1 - PINTURA
    glColor3f(0.4f, 0.0f, 0.0f);
    glBegin(GL_QUADS);
    glVertex2f(71, 400 - 222);
    glVertex2f(71, 400 - 341);
    glVertex2f(125, 400 - 341);
    glVertex2f(125, 400 - 222);
    glEnd();

    glColor3f(0.0f, 0.7f, 0.8f);
    glBegin(GL_QUADS);
    glVertex2f(78, 400 - 230);
    glVertex2f(78, 400 - 334);
    glVertex2f(117, 400 - 334);
    glVertex2f(117, 400 - 230);
    glEnd();

    // Janela 1 - traçado
    glColor3f(0.0f, 0.0f, 0.0f);
    glBegin(GL_LINE_LOOP);
    glVertex2f(71, 400 - 222);
    glVertex2f(71, 400 - 341);
    glVertex2f(125, 400 - 341);
    glVertex2f(125, 400 - 222);
    glEnd();

    glBegin(GL_LINE_LOOP);
    glVertex2f(78, 400 - 230);
    glVertex2f(78, 400 - 334);
    glVertex2f(117, 400 - 334);
    glVertex2f(117, 400 - 230);
    glEnd();

    glBegin(GL_LINES);
    glVertex2f(98, 400 - 230);
    glVertex2f(98, 400 - 334);
    glVertex2f(78, 400 - 285);
    glVertex2f(117, 400 - 285);
    glEnd();

    // Janela 2 - PINTURA
    glColor3f(0.4f, 0.0f, 0.0f);
    glBegin(GL_QUADS);
    glVertex2f(340, 400 - 222);
    glVertex2f(340, 400 - 341);
    glVertex2f(396, 400 - 341);
    glVertex2f(396, 400 - 222);
    glEnd();

    glColor3f(0.0f, 0.7f, 0.8f);
    glBegin(GL_QUADS);
    glVertex2f(348, 400 - 230);
    glVertex2f(348, 400 - 334);
    glVertex2f(388, 400 - 334);
    glVertex2f(388, 400 - 230);
    glEnd();

    // Janela 2 - traçado
    glColor3f(0.0f, 0.0f, 0.0f);
    glBegin(GL_LINE_LOOP);
    glVertex2f(340, 400 - 222);
    glVertex2f(340, 400 - 341);
    glVertex2f(396, 400 - 341);
    glVertex2f(396, 400 - 222);
    glEnd();

    glBegin(GL_LINE_LOOP);
    glVertex2f(348, 400 - 230);
    glVertex2f(348, 400 - 334);
    glVertex2f(388, 400 - 334);
    glVertex2f(388, 400 - 230);
    glEnd();

    glBegin(GL_LINES);
    glVertex2f(368, 400 - 230);
    glVertex2f(368, 400 - 334);
    glVertex2f(348, 400 - 285);
    glVertex2f(388, 400 - 285);
    glEnd();

    // Janela 3 - PINTURA
    glColor3f(0.4f, 0.0f, 0.0f);
    glBegin(GL_QUADS);
    glVertex2f(215, 400 - 110);
    glVertex2f(215, 400 - 190);
    glVertex2f(249, 400 - 190);
    glVertex2f(249, 400 - 110);
    glEnd();

    glColor3f(0.0f, 0.7f, 0.8f);
    glBegin(GL_QUADS);
    glVertex2f(220, 400 - 116);
    glVertex2f(220, 400 - 185);
    glVertex2f(244, 400 - 185);
    glVertex2f(244, 400 - 116);
    glEnd();

    // Janela 3 - traçado
    glColor3f(0.0f, 0.0f, 0.0f);
    glBegin(GL_LINE_LOOP);
    glVertex2f(215, 400 - 110);
    glVertex2f(215, 400 - 190);
    glVertex2f(249, 400 - 190);
    glVertex2f(249, 400 - 110);
    glEnd();

    glBegin(GL_LINE_LOOP);
    glVertex2f(220, 400 - 116);
    glVertex2f(220, 400 - 185);
    glVertex2f(244, 400 - 185);
    glVertex2f(244, 400 - 116);
    glEnd();

    glBegin(GL_LINES);
    glVertex2f(232, 400 - 116);
    glVertex2f(232, 400 - 185);
    glVertex2f(220, 400 - 150);
    glVertex2f(244, 400 - 150);
    glEnd();

    // Porta - PINTURA
    glColor3f(0.4f, 0.1f, 0.1f);
    glBegin(GL_QUADS);
    glVertex2f(202, 400 - 233);
    glVertex2f(202, 400 - 364);
    glVertex2f(266, 400 - 364);
    glVertex2f(266, 400 - 233);
    glEnd();

    glColor3f(0.7f, 0.1f, 0.1f);
    glBegin(GL_QUADS);
    glVertex2f(213, 400 - 244);
    glVertex2f(213, 400 - 364);
    glVertex2f(255, 400 - 364);
    glVertex2f(255, 400 - 244);
    glEnd();

    // Porta - traçado
    glColor3f(0.0f, 0.0f, 0.0f);
    glBegin(GL_LINE_LOOP);
    glVertex2f(202, 400 - 233);
    glVertex2f(202, 400 - 364);
    glVertex2f(266, 400 - 364);
    glVertex2f(266, 400 - 233);
    glEnd();

    glBegin(GL_LINE_LOOP);
    glVertex2f(207, 400 - 238);
    glVertex2f(207, 400 - 364);
    glVertex2f(261, 400 - 364);
    glVertex2f(261, 400 - 238);
    glEnd();

    glBegin(GL_LINE_LOOP);
    glVertex2f(213, 400 - 244);
    glVertex2f(213, 400 - 364);
    glVertex2f(255, 400 - 364);
    glVertex2f(255, 400 - 244);
    glEnd();

    glBegin(GL_LINES);
    glVertex2f(227, 400 - 244);
    glVertex2f(227, 400 - 364);

    glVertex2f(241, 400 - 244);
    glVertex2f(241, 400 - 364);

    glVertex2f(213, 400 - 278);
    glVertex2f(255, 400 - 278);

    glVertex2f(213, 400 - 301);
    glVertex2f(255, 400 - 301);

    glVertex2f(213, 400 - 323);
    glVertex2f(255, 400 - 323);

    glVertex2f(213, 400 - 344);
    glVertex2f(255, 400 - 344);
    glEnd();

    glColor3f(0.0f, 0.7f, 0.7f);
    glBegin(GL_QUADS);
    glVertex2f(222, 400 - 265);
    glVertex2f(222, 400 - 291);
    glVertex2f(246, 400 - 291);
    glVertex2f(246, 400 - 265);
    glEnd();

    glColor3f(0.0f, 0.0f, 0.0f);
    glBegin(GL_LINE_LOOP);
    glVertex2f(222, 400 - 265);
    glVertex2f(222, 400 - 291);
    glVertex2f(246, 400 - 291);
    glVertex2f(246, 400 - 265);
    glEnd();

    // Arco
    glColor3f(0.0f, 0.0f, 0.0f);
    glBegin(GL_LINE_LOOP);
    glVertex2f(148, 400 - 364);
    glVertex2f(148, 400 - 204);
    glVertex2f(314, 400 - 204);
    glVertex2f(314, 400 - 364);
    glEnd();

    glBegin(GL_LINES);
    glVertex2f(148, 400 - 214);
    glVertex2f(314, 400 - 214);

    glVertex2f(166, 400 - 204);
    glVertex2f(166, 400 - 214);

    glVertex2f(188, 400 - 204);
    glVertex2f(188, 400 - 214);

    glVertex2f(210, 400 - 204);
    glVertex2f(210, 400 - 214);

    glVertex2f(230, 400 - 204);
    glVertex2f(230, 400 - 214);

    glVertex2f(249, 400 - 204);
    glVertex2f(249, 400 - 214);

    glVertex2f(270, 400 - 204);
    glVertex2f(270, 400 - 214);

    glVertex2f(290, 400 - 204);
    glVertex2f(290, 400 - 214);

    glEnd();

    // Executa os comandos OpenGL
    glFlush();
}

void Inicializa(GLvoid)
{
    // Define a cor de fundo da janela de visualização como branca
    glClearColor(1.0f, 1.0f, 1.0f, 1.0f);

    glMatrixMode(GL_PROJECTION);
    gluOrtho2D(0, WINDOW_WIDTH, 0, WINDOW_HEIGHT);
}

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

    // ESC = 27255
    if (key == 27)
        glutReshapeWindow(WINDOW_WIDTH, WINDOW_HEIGHT);

    if (key == 32)
    {
        glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
        glutPostRedisplay();
    }
    else
    {
        glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
        glutPostRedisplay();
    }
}

void keybord_test2(GLint key, GLint x, GLint y)
{
    // GLUT_KEY_F1 .. GLUT_KEY_F12
    // GLUT_KEY_UP, GLUT_KEY_DOWN, GLUT_KEY_LEFT, GLUT_KEY_RIGHT
    // GLUT_KEY_PAGE_DOWN, GLUT_KEY_HOME etc.

    std::cout << "Tecla especial: " << key << " (x:" << x << ", y:" << y << ")\n";

    glClearColor(0.3f, 0.3f, 0.3f, 1.0f);
    glutPostRedisplay();

    if (key == GLUT_KEY_F11)
        glutFullScreen();
}

int main(int argc, char *argv[])
{

    InitOpenGL(&argc, argv);

    Inicializa();
    glutDisplayFunc(Desenha);

    // glutReshapeFunc(AlteraTamanhoJanela);

    glutKeyboardFunc(keybord_test);
    glutSpecialFunc(keybord_test2);

    glutMainLoop();
    return 0;
}
