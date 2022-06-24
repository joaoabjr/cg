#include <GL/glut.h>
#include <stdio.h>
GLfloat horzangle = -45.0, vertangle = 30.0, distance = -3.0;

void Porta() {
    glBegin(GL_POLYGON);
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex3f(0.2f, 0.0f, 0.41f);
    glVertex3f(0.3f, 0.0f, 0.41f);
    glVertex3f(0.3f, 0.15f, 0.41f);
    glVertex3f(0.2f, 0.15f, 0.41f);
    glEnd();
}

void Telhado() {
    glBegin(GL_QUAD_STRIP);
    glColor3f(1.0f, 0.0f, 0.0f);
    glVertex3f(0.0f, 0.2f, 0.0f);
    glVertex3f(0.0f, 0.2f, 0.4f);
    glVertex3f(0.2f, 0.3f, 0.0f);
    glVertex3f(0.2f, 0.3f, 0.4f);
    glVertex3f(0.4f, 0.2f, 0.0f);
    glVertex3f(0.4f, 0.2f, 0.4f);
    glEnd();
}

void ParedeJanela() {
    //Construção da janela
    //Direita
    glBegin(GL_POLYGON);
    glColor3f(1.0f, 1.0f, 1.0f);
    glVertex3f(0.4f, 0.0f, 0.0f);
    glVertex3f(0.4f, 0.2f, 0.0f);
    glVertex3f(0.4f, 0.2f, 0.15f);
    glVertex3f(0.4f, 0.0f, 0.15f);
    glEnd();

    //Inferior
    glBegin(GL_POLYGON);
    glColor3f(1.0f, 1.0f, 1.0f);
    glVertex3f(0.4f, 0.0f, 0.15f);
    glVertex3f(0.4f, 0.1f, 0.15f);
    glVertex3f(0.4f, 0.1f, 0.4f);
    glVertex3f(0.4f, 0.0f, 0.4f);
    glEnd();

    //Superior
    glBegin(GL_POLYGON);
    glColor3f(1.0f, 1.0f, 1.0f);
    glVertex3f(0.4f, 0.15f, 0.15f);
    glVertex3f(0.4f, 0.2f, 0.15f);
    glVertex3f(0.4f, 0.2f, 0.4f);
    glVertex3f(0.4f, 0.15f, 0.4f);
    glEnd();

    //Esquerda
    glBegin(GL_POLYGON);
    glColor3f(1.0f, 1.0f, 1.0f);
    glVertex3f(0.4f, 0.0f, 0.4f);
    glVertex3f(0.4f, 0.0f, 0.2f);
    glVertex3f(0.4f, 0.2f, 0.2f);
    glVertex3f(0.4f, 0.2f, 0.4f);
    glEnd();
}

//Display do programa
void Desenha(void) {
    //Configurações iniciais para o programa rodar, alterando a perspectiva da visão, o modo de visão e a rotação da nossa casinha

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    //Configurações de rotação e translação da casinha
    glTranslatef(0.0f, 0.0f, distance);
    glTranslatef(0.0f, 0.0f, -3.0f);
    glRotatef(vertangle, 1.0f, 0.0f, 0.0f);
    glRotatef(horzangle, 0.0f, 1.0f, 0.0f);

    // CULLING: ao habilitar o CULL_FACE, conseguimos perceber que as paredes de trás não são visíveis 
    // Determinandoo que quando tiver um polígono na frente, não veremos o polígono atrás.
    glEnable(GL_CULL_FACE);
    glCullFace(GL_FRONT);

    //Fornece os valores para limpeza do buffer de cor no modo RGBA
    glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    //Primeira parede 
    glBegin(GL_POLYGON);
    glColor3f(1.0f, 1.0f, 0.0f);
    glVertex3f(0.0f, 0.0f, 0.0f);
    glVertex3f(0.0f, 0.2f, 0.0f);
    glVertex3f(0.2f, 0.3f, 0.0f);
    glVertex3f(0.4f, 0.2f, 0.0f);
    glVertex3f(0.4f, 0.0f, 0.0f);
    glEnd();

    //Segunda parede 
    glBegin(GL_QUADS);
    glColor3f(0.0f, 1.0f, 0.0f);
    glVertex3f(0.0f, 0.0f, 0.0f);
    glVertex3f(0.0f, 0.0f, 0.4f);
    glVertex3f(0.0f, 0.2f, 0.4f);
    glVertex3f(0.0f, 0.2f, 0.0f);
    glEnd();

    //Terceira Parede 
    glBegin(GL_POLYGON);
    glColor3f(0.0f, 0.0f, 1.0f);
    glVertex3f(0.0f, 0.0f, 0.4f);
    glVertex3f(0.0f, 0.2f, 0.4f);
    glVertex3f(0.2f, 0.3f, 0.4f);
    glVertex3f(0.4f, 0.2f, 0.4f);
    glVertex3f(0.4f, 0.0f, 0.4f);
    glEnd();

    //CONSTRUÇÃO DE UMA PAREDE PARA MOSTRAR O BACK FACE CULLING
    glBegin(GL_POLYGON);
    glColor3f(1.0f, 1.0f, 0.0f);
    glVertex3f(0.0f, 0.0f, 0.4f);
    glVertex3f(0.0f, 0.2f, 0.4f);
    glVertex3f(0.2f, 0.3f, 0.4f);
    glVertex3f(0.4f, 0.2f, 0.4f);
    glVertex3f(0.4f, 0.0f, 0.4f);
    glEnd();

    //Porta da casinha 
    Porta();

    //Construção da quarta parede incluindo a janela nela
    ParedeJanela();

    //Telhado 
    Telhado();

    glFlush();
    glutSwapBuffers();
}

void AlteraTamanho(GLsizei width, GLsizei height) {
    glViewport(0, 0, width, height);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(30.0, width / height, 1.0, 10.0);
}

//Funções de teclas do teclado
void LeftKey(void) {
    horzangle -= 10;
    Desenha();
}

void RightKey(void) {
    horzangle += 10;
    Desenha();
}

void UpKey(void) {
    vertangle -= 10;
    Desenha();
}

void DownKey(void) {
    vertangle += 10;
    Desenha();
}

void mouse(int button, int state, int x, int y) {
    if (button == GLUT_LEFT_BUTTON) {
        if (state == GLUT_UP) {
            LeftKey();
        }
    }

    if (button == GLUT_RIGHT_BUTTON) {
        if (state == GLUT_UP) {
            RightKey();
        }
    }
    glutPostRedisplay();
}

//case do depth field não funcionou :(
void teclado(int key, int x, int y) {
    switch (key) {
    case GLUT_KEY_UP:
        UpKey();
        break;
    case GLUT_KEY_DOWN:
        DownKey();
        break;
    case GLUT_KEY_LEFT:
        LeftKey();
        break;
    case GLUT_KEY_RIGHT:
        RightKey();
        break;
    case 'x':
        glEnable(GL_CULL_FACE);
        break;
    case 'X':
        glDisable(GL_CULL_FACE);
        break;
    }
    glutPostRedisplay();
}

void main(int argc, char* argv[]) {
    glutInit(&argc, argv);
    //Configurações iniciais de display e janela
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_DEPTH | GLUT_RGBA);
    glutInitWindowSize(800, 800);
    glutInitWindowPosition(600, 150);
    glutCreateWindow("201820285 - Joao Almeida");

    //Caso seja necessário alterar o tamanho da janela em tempo real
    glutReshapeFunc(AlteraTamanho);
    //Funções do teclado e do mouse
    glutSpecialFunc(teclado);
    glutMouseFunc(mouse);
    //Função desenha
    glutDisplayFunc(Desenha);
    glutMainLoop();
}