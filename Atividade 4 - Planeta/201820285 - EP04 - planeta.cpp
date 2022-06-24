#include <GL/glut.h>
#include <stdlib.h>

int year, day, mYear, mDay = 0;

void init(void)
{
    glClearColor(0.0, 0.0, 0.0, 0.0);
    glShadeModel(GL_FLAT);
}

void display(void)
{
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(1.0, 1.0, 1.0);
    glPushMatrix();

    //Criação do Sol
    glutWireSphere(1.0, 20, 16);

    //Criação da Terra
    glRotatef((GLfloat)year, 0.0, 1.0, 0.0);
    glTranslatef(2.0, 0.0, 0.0);
    glRotatef((GLfloat)day, 0.0, 1.0, 0.0);
    glutWireSphere(0.2, 10, 8);

    //Adicionando uma nova esfera no sistema solar: Lua
    glRotatef((GLfloat)mYear, 0.0, 1.0, 0.0);
    glTranslatef(0.5, 0.0, 0.0);
    glRotatef((GLfloat)mDay, 0.0, 1.0, 0.0);
    glutWireSphere(0.1, 5, 4);

    glPopMatrix();
    glutSwapBuffers();
}

void reshape(int w, int h)
{
    glViewport(0, 0, (GLsizei)w, (GLsizei)h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(60.0, (GLfloat)w / (GLfloat)h, 1.0, 20.0);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    gluLookAt(0.0, 0.0, 5.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);
}

void keyboard(unsigned char key, int x, int y){
    switch (key){
    case 'd': //Terra realiza o movimento de translação (próprio eixo) -> sentido horário
        day = (day + 10) % 360;
        mYear = (mYear - 10) % 360;
        glutPostRedisplay();
        break;
    case 'D': //Terra realiza o movimento de translação (próprio eixo) -> sentido anti-horário
        day = (day - 10) % 360;
        mYear = (mYear + 10) % 360;
        glutPostRedisplay();
        break;
    case 'y': //Movimento de rotação da Terra e Lua em relação ao Sol (não realiza translação) -> sentido horário
        year = (year + 5) % 360;
        mDay = (mDay - 5) % 360;
        glutPostRedisplay();
        break;
    case 'Y': //Movimento de rotação da Terra e Lua em relação ao Sol (não realiza translação) -> sentido anti-horário
        year = (year - 5) % 360;
        mDay = (mDay + 5) % 360;
        glutPostRedisplay();
        break;
    case 'f': //Movimento de translação e rotação de todas esferas em relação ao Sol
        mYear = (mYear + 5) % 360;
        mDay = (mDay - 5) % 360;
        day = (day + 5) % 360;
        year = (year + 5) % 360;
        glutPostRedisplay();
        break;
    case 'x': //Lua faz movimento de rotação e translação em relação a Terra
        mYear = (mYear - 5) % 360;
        mDay = (mDay - 10) % 360;
        glutPostRedisplay();
        break;
    case 27:
        exit(0);
        break;
    default:
        break;
    }
}

int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(820, 820);
    glutInitWindowPosition(600, 100);
    glutCreateWindow("201820285 - Joao Almeida");
    init();
    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    glutKeyboardFunc(keyboard);
    glutMainLoop();
    return 0;
}