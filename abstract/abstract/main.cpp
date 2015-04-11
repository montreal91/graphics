#include <iostream>
#include "point.h"
#include "vector.h"

using namespace std;

void MyDisplay(){
    glClear( GL_COLOR_BUFFER_BIT );

    AbsGeomObject *pt = new APoint( 100, 100 );

    APoint start( 200, 100 );
    APoint end( 400, 100 );

    AbsGeomObject *vc = new AVector( start, end );

    pt->DrawObject();
    vc->DrawObject();
    glFlush();
}

void MyInit(){
    glClearColor( 1, 1, 1, 0 );
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
    glutCreateWindow( "Abstract" );
    glutDisplayFunc( MyDisplay );
    MyInit();

    glutMainLoop();
    return 0;
}
