#include <Windows.h>
#include <gl/GL.h>
#include <gl/GLU.h>

#include <GL/freeglut.h>
//#include <GL/glut.h>

#include "Escena.h"
#include "Test1.h"
#include <iostream>
#include <ctime>

using namespace std;

// Freeglut parameters
// Flag telling us to keep processing events
// bool continue_in_main_loop= true; //(**)
// Viewing frustum parameters
GLdouble xRight = 10, xLeft = -xRight, yTop = 250, yBot = -30, N = 1, F = 2000;

// Camera parameters
GLdouble eyeX = 1000.0, eyeY = 100, eyeZ = 1500.0;
GLdouble lookX = 0.0, lookY = 10, lookZ = 0.0;
GLdouble upX = 0, upY = 1, upZ = 0;


Escena* escena;
Test1 test1;
int contEscena;
GLfloat angX, angY, angZ;

int WIDTH = 500, HEIGHT = 500;

void dibujaEjes(){

	glLineWidth(1.5f);
	// Drawing axes
	glBegin(GL_LINES);
	glColor3f(1.0, 0.0, 0.0);
	glVertex3f(0, 0, 0);
	glVertex3f(200, 0, 0);

	glColor3f(0.0, 1.0, 0.0);
	glVertex3f(0, 0, 0);
	glVertex3f(0, 200, 0);

	glColor3f(0.0, 0.0, 1.0);
	glVertex3f(0, 0, 0);
	glVertex3f(0, 0, 200);
	glEnd();

}


void rotaEscena(){
	// Rotating the scene
	glRotatef(angX, 1.0f, 0.0f, 0.0f);
	glRotatef(angY, 0.0f, 1.0f, 0.0f);
	glRotatef(angZ, 0.0f, 0.0f, 1.0f);

}
void buildSceneObjects() {	 
	//escena = new Escena(4000);
	angX = 0.0f;
	angY = 0.0f;
	angZ = 0.0f;
	contEscena = 0;
}

void initGL() {	 		 
	glClearColor(0.6f,0.7f,0.8f,1.0);
      
	glEnable(GL_COLOR_MATERIAL);
	glMaterialf(GL_FRONT, GL_SHININESS, 0.9f);
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_NORMALIZE);

	//Define el modelo de sombreado: GL_FLAT / GL_SMOOTH (suave)
	glShadeModel(GL_SMOOTH); // Shading by default

	

	buildSceneObjects();

	//Activa el modelo de iluminación /disable
	glEnable(GL_LIGHTING);  

	//Enciende una luz particular /disable
	glEnable(GL_LIGHT0);

	//Definir componentes difusa, especular y ambiente
    GLfloat d[]={0.7f,0.5f,0.5f,1.0f};
    glLightfv(GL_LIGHT0, GL_DIFFUSE, d);//Luz que vuelve a irradiar la superficie en todas las direcciones.
    GLfloat a[]={0.3f,0.3f,0.3f,1.0f};
    glLightfv(GL_LIGHT0, GL_AMBIENT, a);//Luz que alcanza una superficie aunque no esté expuesta a la fuente de luz.
	GLfloat s[]={1.0f,1.0f,1.0f,1.0f};
    glLightfv(GL_LIGHT0, GL_SPECULAR, s);//Luz que refleja la superficie.
	GLfloat p[]={25.0f, 25.0f, 25.0f, 1.0f};	 
	glLightfv(GL_LIGHT0, GL_POSITION, p);//Define la posicion de una fuente de luz. ultimo parámetro: 1 local, 0 direccional
	
	// Camera set up
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	gluLookAt(eyeX, eyeY, eyeZ, lookX, lookY, lookZ, upX, upY, upZ);

	// Frustum set up
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glFrustum(xLeft, xRight, yBot, yTop, N, F);
	//glOrtho(xLeft, xRight, yBot, yTop, N, F);

	// Viewport set up
	glViewport(0, 0, WIDTH, HEIGHT);

	//NO ESTÁ EN EL ESQUELETO
	//GLfloat amb[] = { 0.0, 0.0, 0.0, 1.0 };
	//glLightModelfv(GL_LIGHT_MODEL_AMBIENT, amb);

	//LUCES SECUNDARIAS
	/**
    GLfloat d[]={0.2f,0.7f,0.2f,1.0f};
    glLightfv(GL_LIGHT0, GL_DIFFUSE, d);
	GLfloat a[] = { 0.1f, 0.4f, 0.1f, 1.0f };
    glLightfv(GL_LIGHT0, GL_AMBIENT, a);
	GLfloat s[] = { 1.0f, 1.0f, 1.0f, 1.0f };
	glLightfv(GL_LIGHT0, GL_SPECULAR, s);
	GLfloat p[]={25.0f, 25.0f, 25.0f, 1.0f};	
	glLightfv(GL_LIGHT0, GL_POSITION, p);

	GLfloat dir[] = { -1.0, -1.0, -1.0 };
	glLightfv(GL_LIGHT0, GL_SPOT_DIRECTION, dir);
	*/
 }

void display(void) {
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);  

	glMatrixMode(GL_MODELVIEW);	 

	//Esto es por si la cámara se mueve, ajusta la posicion de la luz
	GLfloat p[] = { 25.0f, 25.0f, 25.0f, 1.0f };
	glLightfv(GL_LIGHT0, GL_POSITION, p);

	glPushMatrix();
	
	rotaEscena();

	dibujaEjes();
	switch (contEscena)
	{
	case 0: test1.draw(); break;
	default:
		break;

	}
	//escena->dibuja();
		
	glPopMatrix();
 
	glFlush();
	glutSwapBuffers();

	glutPostRedisplay();
}

void resize(int newWidth, int newHeight) {
	WIDTH = newWidth;
	HEIGHT = newHeight;
	GLdouble RatioViewPort = (float)WIDTH / (float)HEIGHT;
	glViewport(0, 0, WIDTH, HEIGHT);

	GLdouble SVAWidth = xRight - xLeft;
	GLdouble SVAHeight = yTop - yBot;
	GLdouble SVARatio = SVAWidth / SVAHeight;
	if (SVARatio >= RatioViewPort) {
		GLdouble newHeight = SVAWidth / RatioViewPort;
		GLdouble yMiddle = (yBot + yTop) / 2.0;
		yTop = yMiddle + newHeight / 2.0;
		yBot = yMiddle - newHeight / 2.0;
	}
	else {
		GLdouble newWidth = SVAHeight*RatioViewPort;
		GLdouble xMiddle = (xLeft + xRight) / 2.0;
		xRight = xMiddle + newWidth / 2.0;
		xLeft = xMiddle - newWidth / 2.0;
	}

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(xLeft, xRight, yBot, yTop, N, F);
}

void key(unsigned char key, int x, int y){
	bool need_redisplay = true;
	switch (key) {
		case 27:  /* Escape key */
			//continue_in_main_loop = false; // (**)
			//Freeglut's sentence for stopping glut's main loop (*)
			glutLeaveMainLoop (); 
			break;		 
		case 'f': angX+= 5.0f; break;
		case 'z': angX -= 5.0f; break; break;
		case 'v':  angY += 5.0f; break; break;
		case 'x':  angY -= 5.0f; break; break;
		case 'd':  angZ += 5.0f; break; break;
		case 'c': angZ -= 5.0f;  break;
	//	case 'q': escena->moverCoche(ArribaIz); break;
		//case 'w': escena->moverCoche(ArribaDe); break;
		//case 'a': escena->moverCoche(AbajoIz); break;
		//case 's': escena->moverCoche(AbajoDe); break;
		//case 't': escena->cambiarModo(); break;

		case '3': contEscena++; contEscena %= 5; break;//Rota la cámara alrededor del ejeX

		//case 'h': glEnable(GL_LIGHT0); break;
		//case 'n': glDisable(GL_LIGHT0); break;
		/*default:
			need_redisplay = false;
			break;*/
	}

	if (need_redisplay)
		glutPostRedisplay();
}

int main(int argc, char *argv[]){
	cout<< "Starting console..." << endl;
	srand(static_cast <unsigned> (time(0)));

	int my_window; // my window's identifier

	// Initialization
	glutInitWindowSize(500, 500);
	glutInitWindowPosition (0, 0);
	//glutInitWindowPosition (140, 140);
	glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);
	glutInit(&argc, argv);

	// Window construction
	my_window = glutCreateWindow("Thomas :)");
    
	// Callback registration
	glutReshapeFunc(resize);
	glutKeyboardFunc(key);
	glutDisplayFunc(display);

	// OpenGL basic setting
	initGL();

	// Freeglut's main loop can be stopped executing (**)
	// while (continue_in_main_loop) glutMainLoopEvent();

	// Classic glut's main loop can be stopped after X-closing the window,
	// using the following freeglut's setting (*)
	glutSetOption (GLUT_ACTION_ON_WINDOW_CLOSE, GLUT_ACTION_CONTINUE_EXECUTION) ;
    
	// Classic glut's main loop can be stopped in freeglut using (*)
	glutMainLoop(); 
  
	// We would never reach this point using classic glut
	system("PAUSE"); 

	delete escena;
	escena = nullptr;

	return 0;
}
