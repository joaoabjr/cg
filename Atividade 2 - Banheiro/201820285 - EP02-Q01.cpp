#include <GL/glut.h>
#include <iostream>
#include <cmath>
#define PI 3.14159265359

//fun��o c�rculo, gerando um c�rculo de tamanho estabelecido de acordo com o m�vel
void circulo(int raio, int x, int y, int min = 0, int max = 360){
	float theta;
	for (int i = min; i < max; i++) {
		theta = i * PI / (max / 2);
		glVertex2f(x + raio * cos(theta), y + raio * sin(theta));
	}
}

void banheira(){
	//ret�ngulo externo
	glBegin(GL_LINE_LOOP);
	glVertex2d(10.0, 0.0);
	glVertex2d(140.0, 0.0);
	glVertex2d(140.0, 60.0);
	glVertex2d(10.0, 60.0);
	glEnd();

	//--------------------------------

	//ret�ngulo interno da banheira
	glBegin(GL_LINE_LOOP);
	glVertex2f(20, 50);
	glVertex2f(130, 50);
	glEnd();

	glBegin(GL_LINE_LOOP);
	glVertex2f(130, 50);
	glVertex2f(130, 10);
	glEnd();

	glBegin(GL_LINE_LOOP);
	glVertex2f(130, 10);
	glVertex2f(20, 10);
	glEnd();

	glBegin(GL_LINE_LOOP);
	glVertex2f(20, 10);
	glVertex2f(20, 50);
	glEnd();

	//ralo da banheira (c�rculo)
	glBegin(GL_POLYGON);
	circulo(2.1, 120, 27);
	glEnd();
}

void chuveiro(){
	//cria��o do ret�ngulo, posicionando 4 v�rtices
	glBegin(GL_LINE_LOOP);
	glVertex2d(180.0, 10.0);
	glVertex2d(250.0, 10.0);
	glVertex2d(250.0, 50.0);
	glVertex2d(180.0, 50.0);
	glEnd();

	//ret�ngulo interno
	glBegin(GL_LINE_LOOP);
	glVertex2d(170.0, 0.0);
	glVertex2d(260.0, 0.0);
	glVertex2d(260.0, 60.0);
	glVertex2d(170.0, 60.0);
	glEnd();

	//ralo do chuveiro (c�rculo)
	glBegin(GL_POLYGON);
	circulo(2.1, 215, 27);
	glEnd();

	//X
	glBegin(GL_LINES);
	glVertex2d(180.0, 50.0);
	glVertex2f(210, 30);
	glEnd();

	glBegin(GL_LINES);
	glVertex2d(250.0, 50.0);
	glVertex2f(220, 30);
	glEnd();

	glBegin(GL_LINES);
	glVertex2d(180.0, 10);
	glVertex2f(210, 25);
	glEnd();

	glBegin(GL_LINES);
	glVertex2d(250.0, 10);
	glVertex2f(220, 25);
	glEnd();
}

void espelho() {
	//ret�nglo b�sico
	glBegin(GL_LINE_LOOP);
	glVertex2f(10, 250); //v�rtice 1 -> esquerda inferior
	glVertex2f(80, 250); //v�rtice 2 -> direita inferior
	glVertex2f(80, 255); //v�rtice 3 -> direita superior
	glVertex2f(10, 255); //v�rtice 4 -> esquerda superior
	glEnd();
}

void pia() {
	//ret�ngulo externo da pia

	//linha X (parte superior da pia)
	glBegin(GL_LINES);
	glVertex2f(10, 240);
	glVertex2f(80, 240);
	glEnd();

	//linha Y (parte lateral direita da pia)
	glBegin(GL_LINES);
	glVertex2f(80, 240);
	glVertex2f(80, 200);
	glEnd();

	//linha X (parte inferior - base da pia)
	glBegin(GL_LINES);
	glVertex2f(10, 200);
	glVertex2f(80, 200);
	glEnd();

	//linha Y (parte lateral esquerda da pia)
	glBegin(GL_LINES);
	glVertex2f(10, 200);
	glVertex2f(10, 240);
	glEnd();

	//-----------------------------------------

	//retangulo interno

	//linha X (parte superior)
	glBegin(GL_LINES);
	glVertex2f(20, 230);
	glVertex2f(70, 230);
	glEnd();

	//linha Y (parte lateral direita)
	glBegin(GL_LINES);
	glVertex2f(70, 230);
	glVertex2f(70, 210);
	glEnd();

	//linha X (parte inferior - base)
	glBegin(GL_LINES);
	glVertex2f(20, 210);
	glVertex2f(70, 210);
	glEnd();

	//linha Y (parte lateral esquerda)
	glBegin(GL_LINES);
	glVertex2f(20, 230);
	glVertex2f(20, 210);
	glEnd();

	//torneirinha da pia
	glBegin(GL_LINES);
	//partes laterais da torneirinha
	glVertex2f(40, 238);
	glVertex2f(40, 233);

	glVertex2f(50, 238);
	glVertex2f(50, 233);

	//parte superior e inferior da torneirinha (base e topo)
	glVertex2f(50, 233);
	glVertex2f(40, 233);

	glVertex2f(40, 238);
	glVertex2f(50, 238);

	glEnd();

	//ralo da pia (chamando fun��o c�rculo)
	glBegin(GL_POLYGON);
	circulo(2.1, 45, 213);
	glEnd();
}

void vasoSanitario() {
	//criando um pol�gono de 6 v�rtices
	glBegin(GL_LINE_LOOP);
	glVertex2f(130, 220); //v�rtice 1 -> parte esquerda inferior
	glVertex2f(145, 220); //v�rtice 2 -> parte direita inferior //15
	glVertex2f(155, 250); //v�rtice 3 -> parte direita superior 1 //25
	glVertex2f(155, 255); //v�rtice 4 -> parte direita superior 2 //25
	glVertex2f(120, 255); //v�rtice 5 -> parte esquerda superior 2 //-10
	glVertex2f(120, 250); //v�rtice 6 -> parte esquerda superior 1 //-10
	glEnd();

	//parte de cima do vaso, representado por uma linha que "fecha" o ret�ngulo superior
	glBegin(GL_LINES);
	glVertex2f(120, 250);
	glVertex2f(155, 250);
	glEnd();
}

void armario() {
	glBegin(GL_LINE_LOOP);
	glVertex2f(220, 215);
	glVertex2f(260, 215);
	glVertex2f(260, 255);
	glVertex2f(220, 255);
	glEnd();
}

void desenha(void){
	//display chama todas as fun��es respons�veis por montar os m�veis do banheiro
	glClear(GL_COLOR_BUFFER_BIT);

	banheira();
	chuveiro();
	espelho();
	pia();
	vasoSanitario();
	armario();

	glFlush();
}

void inicializar(void){
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0, 260, 0, 260);
}

int main(int argc, char** argv)
{
	//fun��o main para iniciar o programa e chamar as fun��es necess�rias
	//para cria��o do banheiro mobiliado
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(500, 500);
	glutInitWindowPosition(700, 200);
	glutCreateWindow("EP02 - Joao Almeida");
	inicializar();
	glutDisplayFunc(desenha);
	glutMainLoop();
	return 0;
}