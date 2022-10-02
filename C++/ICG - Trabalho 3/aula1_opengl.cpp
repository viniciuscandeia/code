#include <stdlib.h>
#include <GL/glut.h>

GLint WINDOW_WIDTH  = 600,
      WINDOW_HEIGHT = 600;

void InitOpenGL(int *argc, char **argv){
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
    //To Do
}

void Inicializa(GLvoid) 
{
	// Define a cor de fundo da janela de visualização como branca
	glClearColor(1.0f, 1.0f, 1.0f, 1.0f);

    glMatrixMode(GL_PROJECTION);
    gluOrtho2D(0, WINDOW_WIDTH, 0, WINDOW_HEIGHT);
} 

void Desenha(GLvoid){

    // Limpa a janela de visualização com a cor  
	// de fundo definida previamente
	glClear(GL_COLOR_BUFFER_BIT);

	// Altera a cor do desenho para vermelho
	glColor3f(0.0f, 0.0f, 0.0f);

    glPointSize(5.f);

    glBegin(GL_POINTS);
        glVertex2f(200, 200);
        glVertex2f(400, 200);
        glVertex2f(400, 300);
        glVertex2f(200, 300);
        glVertex2f(200, 400);
        glVertex2f(400, 400);
    glEnd();
    

	glColor3f(1.0f, 0.0f, 0.0f);
    glLineWidth(3.0f);  // aumenta a espessura das linhas
    // glBegin(GL_LINE_LOOP);
    //     glVertex2f(200, 200);
    //     glVertex2f(400, 200);
    //     glVertex2f(400, 300);
    //     glVertex2f(200, 300);
    //     glVertex2f(200, 400);
    //     glVertex2f(400, 400);
    // glEnd();

    glBegin(GL_TRIANGLES);
        glVertex2f(200, 200);
        glVertex2f(400, 200);
        glVertex2f(400, 300);
        glVertex2f(200, 300);
        glVertex2f(200, 400);
        glVertex2f(400, 400);
    glEnd();

    // Executa os comandos OpenGL 
    glFlush();
}

int main(int argc, char *argv[])
{

    InitOpenGL(&argc, argv);

    glutDisplayFunc(Desenha);
    
    // glutReshapeFunc(AlteraTamanhoJanela);

    Inicializa();
    
    glutMainLoop();
    return 0;
}
