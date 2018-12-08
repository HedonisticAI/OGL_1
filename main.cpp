 #include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <GL/glut.h>
#include <dos.h>
#include <ctime>
#include <windows.h>
#include <math.h>

#define PI 3.14159265

int time_now = 100;
/*
    time_now>0 day
    time_now<0 night
*/

using namespace std;

void drawSun(int x, int y, int siz, int ap)//x,y- psotion now, size=rad, ap- колво итераций
{
    glBegin(GL_POLYGON);
        for(int i=0; i<ap; i++)
        {
            double ang = PI*2/ap*i;
            glVertex2d(siz * sin(ang) + x, siz * cos(ang) + y);
        }
    glEnd();
}

void display()
{
	glClear(GL_COLOR_BUFFER_BIT);
	glLineWidth(2);
	glColor3f(0.0, 0.0, 0.0);
	glLineWidth(1);

	if(time_now>0)
        glColor3f(0.0, 3.0, 0.0);//grass color param
    else
        glColor3f(0.0, 1.5, 0.0);

	glBegin(GL_QUADS);//grass
		glVertex2i(0,0);
		glVertex2i(0,500);
		glVertex2i(700,500);
		glVertex2i(700,0);
	glEnd();


	if(time_now>0)
        glColor3f(0.0, 1.0, 1.0);
    else
        glColor3f(0.0, 0.0, 0.2);

    glBegin(GL_QUADS);//sky
		glVertex2i(0,250);
		glVertex2i(0,500);
		glVertex2i(700,500);
		glVertex2i(700,250);
	glEnd();


	if(time_now>0)
        glColor3f(1.0, 1.0, 0.0);//sky color
    else
        glColor3f(1.0, 1.0, 1.0);//sky color

	drawSun((time_now>0)? 700*time_now/100 : 700*(time_now+100)/100, 375, 50, 128);


	if(time_now>0)//house color
        glColor3f(0.9, 0.9, 0.9);
    else
        glColor3f(0.5, 0.5, 0.5);

    glBegin(GL_QUADS);//House pace
		glVertex2i(175,125);
		glVertex2i(175,215);
		glVertex2i(255,215);
		glVertex2i(255,125);
	glEnd();


	if(time_now>0)
        glColor3f(0.9, 0.0, 0.0);//roof color
    else
        glColor3f(0.35, 0., 0.0);

    glBegin(GL_TRIANGLES);//roof plase
		glVertex2i(135,215);
		glVertex2i(295,215);
		glVertex2i(215,255);
	glEnd();

	glFlush();
}

void myfoo()
{
    time_now--;
    if(time_now<-100)
        time_now=100;

    Sleep(10);

    display();
}

void Reshape(int Width, int Height)
{
	if (Height == 0)
	{
		Height = 1;
	}

	glViewport(0, 0, (GLsizei)Width, (GLsizei)Height);

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0.0, (GLdouble)Width, 0.0, (GLdouble)Height);

	display();
}

void init()
{
   glClearColor(1.0, 1.0, 1.0, 1.0);
}

int main(int argc, char **argv)
{
	glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGB | GLUT_SINGLE);
	glutInitWindowPosition(500, 200);
	glutInitWindowSize(700, 500);
	glutCreateWindow( "Main window" );

	init();
    glutDisplayFunc(display);
 	glutReshapeFunc(Reshape);
 	glutIdleFunc(myfoo);

    printf("It's a test app.");
	glutMainLoop();
	return 0;
}
