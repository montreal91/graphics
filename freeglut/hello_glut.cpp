#include "GL/freeglut.h"
// #include <iostream>

void MyDisplay(){
	glClear( GL_COLOR_BUFFER_BIT );
	glBegin( GL_POINTS );

	glVertex2f( 10, 0 );
	glVertex2f( 105, 130 );
	glVertex2f( 130, 130 );
	glEnd();
	glFlush();
}

void MyInit(){
	glClearColor( 1, 0, 0, 0 );
	glColor3f( 0, 0, 1 );
	glPointSize( 7 );

	glMatrixMode( GL_PROJECTION );
	glLoadIdentity();
	gluOrtho2D( 0, 640, 0, 640 );
}

int main( int argc, char** argv ){
	glutInit( &argc, argv );
	glutInitDisplayMode( GLUT_SINGLE | GLUT_RGB );
	glutInitWindowSize( 640, 640 );
	glutCreateWindow( "OpenGL example" );
	glutDisplayFunc( MyDisplay );
	MyInit();
	glutMainLoop();
	return 0;
}
