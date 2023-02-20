#include<GL/glut.h>

//Program to create an empty Widdow
void init() {
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);	//used for choosing buffering options and choice of color mode
	//GLUT_SINGLE for a window display that means one buffer for will used for one color we can use subsequent two or three buffer 
	//mode to increase the number of colors, we used GLUT_RGB meaning we will use Red, Green and Blue colors as our primary colors.

	glutInitWindowSize(640, 480);//used to define the size of the window to be created

	glutInitWindowPosition(1000, 200);//used to define the start point of the window on the screen (It start from a top left the corner, 
	//that is 1000 pixels left, and 200 pixels below)

	glutCreateWindow("Simple Window");//to create the window on the screen, also we can pass a string argument with it which display that 
	//string on the top of the newly created window.
}

void display()
{
	glClearColor(1.0, 1.0, 1.0, 0.0);//accepts 4 parameters, for each Red, Green, Blue, and Alpha value. It accepts these three colors 
	//only because we defined in Line C that we will use only this one and we passed a value (float) between 0 and 1 for defining its 
	//composition and the resulting color will be the color of the background, Alpha value is used to determine the resulting of 
    //two overlapping colors. where a = 0 is transparent object, a = 1 is opaque object

	//But simply using glClearColor() won�t change the background color, surely it will set the background but it won�t be visible; 
	//unless we use glClear(GL_COLOR_BUFFER_BIT)

	glClear(GL_COLOR_BUFFER_BIT);//will activate the color process from the graphics processor and assigned color will display on the window.
	//gluOrtho2D(0.0,100.0,0,100.0); //takes four floats as parameters and they are Xmin, Xmax, Ymin ,and Ymax which define the coordinate system within the window
	
	glFlush();//flush down everything to the screen

}

int main(int argc, char** argv)
{
	glutInit(&argc, argv); //it initializes the OpenGL utility toolkit (GLUT), hence it must be done at the beginning and it is one of must do step.
	init();					//called the user-defined function to init()
	glutDisplayFunc(display);//it takes a name of the function as its parameter and it displays it on the screen
	glutMainLoop();//a must function as it is responsible to hold the display on screen or else the program will end without human eye noticing a thing

	return 0;
}
