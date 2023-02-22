#include <gl/glut.h>
#include<iostream>
using namespace std;
int rx, ry;
int xCenter, yCenter;
void myinit(void)
{
    glClearColor(0.2, 0.7, 0.6, 0.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0.0, 640.0, 0.0, 480.0);
}

void setPixel(GLint x, GLint y)
{
    glBegin(GL_POINTS);
    glVertex2i(x, y);
    glEnd();
}


void ellipseMidPoint(int xCenter, int yCenter, int rx, int ry)
{
    //plotting for 1st region of 1st quardant and the slope will be < -1
     //----------------------Region-1------------------------//
    float x = 0;
    float y = ry;//(0,ry) ---
    float p1 = ry * ry - (rx * rx) * ry + (rx * rx) * (0.25);
    //slope
    float dx = 2 * (ry * ry) * x;
    float dy = 2 * (rx * rx) * y;
    while (dx < dy)
    {
        //plot (x,y)
        setPixel(xCenter + x, yCenter + y);
        setPixel(xCenter - x, yCenter + y);
        setPixel(xCenter + x, yCenter - y);
        setPixel(xCenter - x, yCenter - y);
        if (p1 < 0)
        {
            x = x + 1;
            dx = 2 * (ry * ry) * x;
            p1 = p1 + dx + (ry * ry);
        }
        else
        {
            x = x + 1;
            y = y - 1;
            dx = 2 * (ry * ry) * x;
            dy = 2 * (rx * rx) * y;
            p1 = p1 + dx - dy + (ry * ry);
        }
    }
    //ploting for 2nd region of 1st quardant and the slope will be > -1
     //----------------------Region-2------------------------//
    float p2 = (ry * ry) * (x + 0.5) * (x + 0.5) + (rx * rx) * (y - 1) * (y - 1) - (rx * rx) * (ry * ry);

    while (y > 0)
    {
        //plot (x,y)
        setPixel(xCenter + x, yCenter + y);
        setPixel(xCenter - x, yCenter + y);
        setPixel(xCenter + x, yCenter - y);
        setPixel(xCenter - x, yCenter - y);     //glEnd();
        if (p2 > 0)
        {
            x = x;
            y = y - 1;
            dy = 2 * (rx * rx) * y;
            //dy = 2 * rx * rx *y;
            p2 = p2 - dy + (rx * rx);
        }
        else
        {
            x = x + 1;
            y = y - 1;
            dy = dy - 2 * (rx * rx);
            dx = dx + 2 * (ry * ry);
            p2 = p2 + dx -
                dy + (rx * rx);
        }
    }

}
void display()
{
    glClearColor(1.0f, 1.0f, 1.0f, 0.0f);// White and opaque
    glClear(GL_COLOR_BUFFER_BIT);     
    glColor3f(0.0, 0.0, 1.0);          // blue foreground
    glPointSize(2.0);               // size of points (in pixel)

    //establish a coordinate system for the image

    ellipseMidPoint(300, 400, 200, 50);

    ellipseMidPoint(300, 100, 100, 25);

    glBegin(GL_LINES);
    glColor3f(0.0f, 0.0f, 1.0f);//Blue
    glVertex2f(100.0, 400.0);
    glVertex2f(200.0, 100.0);
    //glVertex2f(-0.1f, 0.4f);
    glEnd();

    glBegin(GL_LINES);
    glColor3f(0.0f, 0.0f, 1.0f);//Blue
    glVertex2f(500.0, 400.0);
    glVertex2f(400.0, 100.0);
    glEnd();

    glBegin(GL_LINES);
    glColor3f(0.0f, 0.0f, 1.0f);//Blue
    glVertex2f(140.0, 280.0);
    glVertex2f(460.0, 280.0);
    glEnd();

   
    glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);

    glBegin(GL_TRIANGLES);
    glColor3f(0.0f, 1.0f, 0.0f); 
    glVertex2f(160.0, 220.0);
    glVertex2f(200.0, 280.0);
    glVertex2f(253.33, 220.0);
    glEnd();

    glBegin(GL_TRIANGLES);
    glColor3f(0.0f, 1.0f, 0.0f); 
    glVertex2f(253.33, 220.0);
    glVertex2f(300.0, 280.0);
    glVertex2f(346.66, 220.0);
    glEnd();

    glBegin(GL_TRIANGLES);
    glColor3f(0.0f, 1.0f, 0.0f); 
    glVertex2f(346.66, 220.0);
    glVertex2f(395.0, 280.0);
    glVertex2f(440.0, 220.0);
    glEnd();
    
    glBegin(GL_LINES);
    glColor3f(0.0f, 0.0f, 1.0f);//Blue
    glVertex2f(160.0, 220.0);
    glVertex2f(440.0, 220.0);
    glEnd();


    glFlush(); // send all output to the display
}

int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitWindowSize(640, 480); // set the size of the window
    glutInitWindowPosition(10, 10); // the position of the top-left of window
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutCreateWindow("Lab_eval_Ques2");
    myinit();
    glutDisplayFunc(display); 
    glutMainLoop(); 

}
