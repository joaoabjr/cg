/*
 * Copyright (c) 1993-1997, Silicon Graphics, Inc.
 * ALL RIGHTS RESERVED
 * Permission to use, copy, modify, and distribute this software for
 * any purpose and without fee is hereby granted, provided that the above
 * copyright notice appear in all copies and that both the copyright notice
 * and this permission notice appear in supporting documentation, and that
 * the name of Silicon Graphics, Inc. not be used in advertising
 * or publicity pertaining to distribution of the software without specific,
 * written prior permission.
 *
 * THE MATERIAL EMBODIED ON THIS SOFTWARE IS PROVIDED TO YOU "AS-IS"
 * AND WITHOUT WARRANTY OF ANY KIND, EXPRESS, IMPLIED OR OTHERWISE,
 * INCLUDING WITHOUT LIMITATION, ANY WARRANTY OF MERCHANTABILITY OR
 * FITNESS FOR A PARTICULAR PURPOSE.  IN NO EVENT SHALL SILICON
 * GRAPHICS, INC.  BE LIABLE TO YOU OR ANYONE ELSE FOR ANY DIRECT,
 * SPECIAL, INCIDENTAL, INDIRECT OR CONSEQUENTIAL DAMAGES OF ANY
 * KIND, OR ANY DAMAGES WHATSOEVER, INCLUDING WITHOUT LIMITATION,
 * LOSS OF PROFIT, LOSS OF USE, SAVINGS OR REVENUE, OR THE CLAIMS OF
 * THIRD PARTIES, WHETHER OR NOT SILICON GRAPHICS, INC.  HAS BEEN
 * ADVISED OF THE POSSIBILITY OF SUCH LOSS, HOWEVER CAUSED AND ON
 * ANY THEORY OF LIABILITY, ARISING OUT OF OR IN CONNECTION WITH THE
 * POSSESSION, USE OR PERFORMANCE OF THIS SOFTWARE.
 *
 * US Government Users Restricted Rights
 * Use, duplication, or disclosure by the Government is subject to
 * restrictions set forth in FAR 52.227.19(c)(2) or subparagraph
 * (c)(1)(ii) of the Rights in Technical Data and Computer Software
 * clause at DFARS 252.227-7013 and/or in similar or successor
 * clauses in the FAR or the DOD or NASA FAR Supplement.
 * Unpublished-- rights reserved under the copyright laws of the
 * United States.  Contractor/manufacturer is Silicon Graphics,
 * Inc., 2011 N.  Shoreline Blvd., Mountain View, CA 94039-7311.
 *
 * OpenGL(R) is a registered trademark of Silicon Graphics, Inc.
 */

 /*
  *  clip.c
  *  This program demonstrates arbitrary clipping planes.
  * 
  *  Alterações feitas por João Almeida Barbosa Júnior para disciplina de Computação Gráfica (Prof. Ana Paula)
  */
#include <GL/glut.h>
#include <stdlib.h>

int ang;

void init(void)
{
    glClearColor(0.0, 0.0, 0.0, 0.0);
    glShadeModel(GL_FLAT);
}

void display(void)
{
    GLdouble eqn[4] = { 0.0, 1.0, 0.0, 0.0 };
    GLdouble eqn2[4] = { 1.0, 0.0, 0.0, 0.0 };

    glClear(GL_COLOR_BUFFER_BIT);

    glColor3f(1.0, 1.0, 1.0);
    glPushMatrix();
    glTranslatef(0.0, 0.0, -5.0);

    /*    clip lower half -- y < 0          */
    glClipPlane(GL_CLIP_PLANE0, eqn);
    glEnable(GL_CLIP_PLANE0);

    /*    clip left half -- x < 0           */
    glClipPlane(GL_CLIP_PLANE1, eqn2);
    glEnable(GL_CLIP_PLANE1);

    glRotatef(90.0, 1.0, 0.0, 0.0);
    glutWireSphere(1.0, 20, 16);
    glPopMatrix();

    glFlush();
}

void reshape(int w, int h)
{
    glViewport(0, 0, (GLsizei)w, (GLsizei)h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(60.0, (GLfloat)w / (GLfloat)h, 1.0, 20.0);
    glMatrixMode(GL_MODELVIEW);
}

void stencil() {
    // ESSA FUNÇÃO SERÁ CHAMADA TODA VEZ QUE O DESENHO FOR REDIMENSIONADO!
    // Utilização do Stencil Buffer
    glEnable(GL_STENCIL_TEST);

    // Limpeza do Stencil Buffer
    glClearStencil(0);
    glClear(GL_STENCIL_BUFFER_BIT);

    // Init do Stencil Buffer
    // Define que o valor 1 será "operado" com o valor do stencil
    GLint ref = 1;
    GLuint valorDesenha = 1;

    // Define o teste a ser feito entre o valor do 
    // stencil e o valor de "Referencia". 
    // Se o teste for verdadeiro então NovoValor será
    // usado para operar sobre o valor corrente do Stencil
    //    GL_ALWAYS = o teste é sempre verdadeiro
    //    GL_EQUAL = o teste é verdadeiro se Referencia == Stencil 
    //    GL_LEQUAL = o teste é verdadeiro se  Referencia <=  Stencil
    //    GL_NOTQUAL = o teste é verdadeiro se  Referencia s!=  Stencil
    glStencilFunc(GL_ALWAYS, ref, valorDesenha);

    // Define como o NovoValor é colocado no Stencil:
    //    GL_REPLACE -> Valor atual do stencil será trocado pelo novo valor de variável
    //    GL_KEEP -> valor atual do Stencil Buffer será mantido
    glStencilOp(GL_REPLACE, GL_REPLACE, GL_REPLACE);

    // Define uma área de desenha com coordenadas
    // lógicas (0,0)->(10,10)

    // Ativa matriz de projeção (necessário para usar a gluOrtho2D)
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0, 10, 0, 10); // define coordenadas lógicas de desenho

    // Volta para a matrix de transformações geométricas
    glMatrixMode(GL_MODELVIEW);

    // Desenha um cubo no formato wireframe
    glutWireCube(50.0);

}

void desenhaStencil() {
    // Se o conteúdo do Stencil for == 1,
    // então desenha na tela e na área do buffer

    glStencilFunc(GL_EQUAL, 1, 1);
    glStencilOp(GL_KEEP, GL_KEEP, GL_KEEP);

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0, 10, 0, 10);
    
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    glDisable(GL_DEPTH_TEST); // Desabilita o ZBuffer

    glColor3f(1, 0, 0);
    glRectf(2.0f, 4.7f, 8.0f, 5.3f);

}

void semStencil() { //fora do stencil
    // ... mantendo o stencil como ele estava
    glStencilOp(GL_KEEP, GL_KEEP, GL_KEEP);

    // *****************************
    // Faz o desenho 3D
    // *****************************
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glPushMatrix();
    glTranslatef(1.0f, 0.0f, 0.0f);
    glRotatef(ang, 0, 1, 0);
    glColor3f(0.5f, 0.3f, 0.0f);

    glNormal3f(0, 0, 1);
    glVertex3f(-1.0f, -1.0f, 1.0f);
    glVertex3f(1.0f, -1.0f, 1.0f);
    glVertex3f(1.0f, 1.0f, 1.0f);
    glVertex3f(-1.0f, 1.0f, 1.0f);
    glPopMatrix();

    glLoadIdentity();
    glPushMatrix();
    glTranslatef(-1.0f, 0.0f, -5.0f);
    glRotatef(45, 0, 1, 0);
    glColor3f(0.5f, 0.3f, 0.0f);

    glNormal3f(0, 0, 1);
    glVertex3f(-1.0f, -1.0f, 1.0f);
    glVertex3f(1.0f, -1.0f, 1.0f);
    glVertex3f(1.0f, 1.0f, 1.0f);
    glVertex3f(-1.0f, 1.0f, 1.0f);

    glPopMatrix();

    ang = ang + 2;
}

void keyboard(unsigned char key, int x, int y)
{
    switch (key) {
    case 27:
        exit(0);
        break;
    }
}

int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB | GLUT_STENCIL);
    glutInitWindowSize(500, 500);
    glutInitWindowPosition(100, 100);
    glutCreateWindow(argv[0]);
    init();
    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    glutKeyboardFunc(keyboard);
    glutMainLoop();
    return 0;
}