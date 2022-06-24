#include <GL/glut.h>
#include <stdlib.h>

int shoulder, elbow, hand, dedo1, pontaDedo1, dedo2, pontaDedo2 = 0;

float luzAmbiente[] = { 0.2f, 0.2f, 0.2f, 1.0f };
float luzDifusa[] = { 0.7f, 0.7f, 0.7f, 1.0f };
float luzEspecular[] = { 1.0f, 1.0f, 1.0f, 1.0f };
float posicaoLuz[] = { 0.0f, 50.0f, 50.0f, 1.0f };

void init(void)
{
	glClearColor(0.0, 0.0, 0.0, 0.0);

	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);

	glColorMaterial(GL_FRONT_AND_BACK, GL_DIFFUSE);
	glEnable(GL_COLOR_MATERIAL);

	glShadeModel(GL_SMOOTH);
	glEnable(GL_DEPTH_TEST);
}

void iluminacao() {
	// Ativa o uso da luz ambiente 
	glLightModelfv(GL_LIGHT_MODEL_AMBIENT, luzAmbiente);

	// Define os parâmetros da luz de número 0
	glLightfv(GL_LIGHT0, GL_AMBIENT, luzAmbiente);
	glLightfv(GL_LIGHT0, GL_DIFFUSE, luzDifusa);
	glLightfv(GL_LIGHT0, GL_SPECULAR, luzEspecular);
	glLightfv(GL_LIGHT0, GL_POSITION, posicaoLuz);

}

void display(void) {
	glClear(GL_COLOR_BUFFER_BIT);
	glPushMatrix();

	//Chama função de iluminação
	iluminacao();

	//Cabeça
	glTranslatef(1.0, 0.0, 0.0);
	glPushMatrix();
	glScalef(1.2, 1.5, 1.0);
	glutSolidCube(1.0);
	glPopMatrix();

	//Corpo
	glTranslatef(-1, -3.2, 0.0);
	glTranslatef(1.0, 0.0, 0.0);
	glPushMatrix();
	glScalef(3.0, 5, 1.0);
	glutSolidCube(1.0);
	glPopMatrix();

	//Ombro
	glTranslatef(1.5, 1.5, 0.0);
	glRotatef((GLfloat)shoulder, 0.0, 0.0, 1.0);
	glTranslatef(1.0, 0.0, 0.0);
	glPushMatrix();
	glScalef(2.0, 0.4, 1.0);
	glutSolidCube(1.0);
	glPopMatrix();

	//Cotovelo
	glTranslatef(1.0, 0.0, 0.0);
	glRotatef((GLfloat)elbow, 0.0, 0.0, 1.0);
	glTranslatef(1.0, 0.0, 0.0);
	glPushMatrix();
	glScalef(2.0, 0.4, 1.0);
	glutSolidCube(1.0);
	glPopMatrix();

	//Mão
	glTranslatef(1, 0.0, 0.0);
	glRotatef((GLfloat)hand, 0, 0, 1.0);
	glTranslatef(0.2, 0.0, 0.0);
	glPushMatrix();
	glScalef(0.4, 0.4, 0.5);
	glutSolidCube(1.0);
	glPopMatrix();

	//Dedo 1
	glPushMatrix();
	glTranslatef(0.2, 0.1, 0.0);
	glRotatef((GLfloat)dedo1, 0, 0, 1.0);
	glTranslatef(0.2, 0, 0.0);
	glPushMatrix();
	glScalef(0.4, 0.1, 0.1);
	glutSolidCube(1.0);
	glPopMatrix();

	//Ponta do dedo 1
	glTranslatef(0.2, 0, 0.0);
	glRotatef((GLfloat)pontaDedo1, 0, 0, 1.0);
	glTranslatef(0.2, 0, 0.0);
	glPushMatrix();
	glScalef(0.4, 0.1, 0.1);
	glutSolidCube(1.0);
	glPopMatrix();

	glPopMatrix();

	//Dedo 2
	glTranslatef(0.2, -0.1, 0.0);
	glRotatef((GLfloat)dedo2, 0, 0, 1.0);
	glTranslatef(0.2, 0, 0.0);
	glPushMatrix();
	glScalef(0.4, 0.1, 0.1);
	glutSolidCube(1.0);
	glPopMatrix();

	//Ponta do dedo 2
	glTranslatef(0.2, 0, 0.0);
	glRotatef((GLfloat)pontaDedo2, 0, 0, 1.0);
	glTranslatef(0.2, 0, 0.0);
	glPushMatrix();
	glScalef(0.4, 0.1, 0.1);
	glutSolidCube(1.0);
	glPopMatrix();

	glPopMatrix();

	glutSwapBuffers();
}

void reshape(int w, int h)
{
	glViewport(0, 0, (GLsizei)w, (GLsizei)h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(120.0, (GLfloat)w / (GLfloat)h, 1.0, 20.0);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	glTranslatef(0.0, 0.0, -5.0);
}

void keyboard(unsigned char key, int x, int y) {
	switch (key) {
	case 's': //Braço -> sentido horário
		shoulder = (shoulder - 5) % 360;
		glutPostRedisplay();
		break;
	case 'S': //Braço -> sentido anti-horário
		shoulder = (shoulder + 5) % 360;
		glutPostRedisplay();
		break;
	case 'e': //Antebraço -> sentido horário
		elbow = (elbow - 5) % 360;
		glutPostRedisplay();
		break;
	case 'E': //Antebraço -> sentido anti-horário
		elbow = (elbow + 5) % 360;
		glutPostRedisplay();
		break;
	case 'a': //Mão -> sentido horário
		hand = (hand - 5) % 360;
		glutPostRedisplay();
		break;
	case 'A': //Mão -> sentido anti-horário
		hand = (hand + 5) % 360;
		glutPostRedisplay();
		break;
	case 'q': //Dedo 2 -> sentido horário
		dedo2 = (dedo2 - 5) % 360;
		glutPostRedisplay();
		break;
	case 'Q': //Dedo 2 -> sentido anti-horário
		dedo2 = (dedo2 + 5) % 360;
		glutPostRedisplay();
		break;
	case 'd': //Ponta do dedo 1 -> sentido horário
		pontaDedo2 = (pontaDedo2 - 5) % 360;
		glutPostRedisplay();
		break;
	case 'D': //Ponta do dedo 1 -> sentido anti-horário
		pontaDedo2 = (pontaDedo2 + 5) % 360;
		glutPostRedisplay();
		break;
	case 'f': //Dedo 1 -> sentido horário
		dedo1 = (dedo1 - 5) % 360;
		glutPostRedisplay();
		break;
	case 'F': //Dedo 1 -> sentido anti-horário
		dedo1 = (dedo1 + 5) % 360;
		glutPostRedisplay();
		break;
	case 'w': //Ponta do dedo 1 -> sentido horário
		pontaDedo1 = (pontaDedo1 - 5) % 360;
		glutPostRedisplay();
		break;
	case 'W': //Ponta do dedo 1 -> sentido anti-horário
		pontaDedo1 = (pontaDedo1 + 5) % 360;
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
	glutInitWindowSize(520, 520);
	glutInitWindowPosition(700, 280);
	glutCreateWindow("201820285 - Joao Almeida");
	init();
	glutDisplayFunc(display);
	glutReshapeFunc(reshape);
	glutKeyboardFunc(keyboard);
	glutMainLoop();
	return 0;
}
