#include<Gl/glut.h>
//Program to create a pt, line, triangle and a rect
void init() {
	glutInitDisplayMode(GLUT_RGB);
	glutCreateWindow("Simple Window");
	glutInitWindowSize(640, 480);
	glutInitWindowPosition(1000, 200);
}	 
void display()
{
	glClearColor(0.0f, 0.0f, 0.0f, 0.0f);// Black and opaque
	glClear(GL_COLOR_BUFFER_BIT);
	// gluOrtho2D(0.0,100.0,0,100.0);
	
	glPointSize(10);
	glBegin(GL_POINTS);
	glColor3f(0.0f, 0.0f, 1.0f); // Blue
	glVertex2f(0.8f, 0.5f);
	glEnd();
	
	glBegin(GL_LINES);
	glColor3f(0.0f, 1.0f, 0.0f);//Green
	glVertex2f(0.5f, 0.4f);
	glVertex2f(-0.1f, 0.4f);
	//glVertex2f(10.0f, 10.0f);
	//glVertex2f(50.0f, 50.0f);
	glEnd();

	glBegin(GL_TRIANGLES);
	glColor3f(0.2f, 0.2f, 0.2f); // Dark Gray
	glVertex2f(0.1f, -0.6f);
	glVertex2f(0.7f, -0.6f);
	glVertex2f(0.4f, -0.1f);
	glEnd();

	glBegin(GL_QUADS);
	glColor3f(1.0f, 0.0f, 0.0f); // Red
	glVertex2f(-0.8f, 0.1f);     // Define vertices in counter-clockwise (CCW) order
	glVertex2f(-0.2f, 0.1f);     //  so that the normal (front-face) is facing you
	glVertex2f(-0.2f, 0.7f);
	glVertex2f(-0.8f, 0.7f);
	glEnd();

	glFlush();
}

int main(int argc, char** argv)
{
	glutInit(&argc, argv);			//Line A
	init();					//Line B
	glutDisplayFunc(display);
	glutMainLoop();

	return 0;
}
