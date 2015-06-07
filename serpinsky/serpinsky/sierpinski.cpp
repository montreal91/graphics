#include "sierpinski.h"

Sierpinski* Sierpinski::current_instance;

Sierpinski::Sierpinski() {
}

Sierpinski::Sierpinski( int argc, char** argv ) {
    this->SIZE.width        = 800;
    this->SIZE.height       = 600;

    this->FILL_COLOR.red    = 0.75;
    this->FILL_COLOR.green  = 0.75;
    this->FILL_COLOR.blue   = 0.75;
    this->FILL_COLOR.alpha  = 0;

    this->POINT_COLOR.red   = 0.15;
    this->POINT_COLOR.green = 0.15;
    this->POINT_COLOR.blue  = 0.15;
    this->POINT_COLOR.alpha = 0;

    this->LEFT.coord_x      = 100;
    this->LEFT.coord_y      = 10;

    this->RIGHT.coord_x     = 700;
    this->RIGHT.coord_y     = 10;

    this->TOP.coord_x       = 400;
    this->TOP.coord_y       = 520;

    this->CreateWindow( argc, argv );
}

Sierpinski::~Sierpinski() {
}

void
Sierpinski::SetUpCallback() {
    current_instance = this;
    ::glutDisplayFunc( Sierpinski::DrawCallback );
}

void
Sierpinski::Init() const {
    glClearColor(
        this->FILL_COLOR.red,
        this->FILL_COLOR.green,
        this->FILL_COLOR.blue,
        this->FILL_COLOR.alpha
    );
    glColor3f( this->POINT_COLOR.red, this->POINT_COLOR.green, this->FILL_COLOR.blue );
    glPointSize( this->POINT_SIZE );

    glMatrixMode( GL_PROJECTION );
    glLoadIdentity();
    gluOrtho2D( 0, this->SIZE.width, 0, this->SIZE.height );

    glutMainLoop();
}

void
Sierpinski::Draw() const {
    glClear( GL_COLOR_BUFFER_BIT );
    glBegin( GL_POINTS );

    this->DrawBasicTriangle();
    this->DrawGasket();

    glEnd();
    glFlush();
}

void
Sierpinski::CreateWindow( int argc, char** argv ) const {
    glutInit( &argc, argv );
    glutInitDisplayMode( GLUT_SINGLE | GLUT_RGB );
    glutInitWindowSize( this->SIZE.width, this->SIZE.height );
    glutCreateWindow( this->TITLE.c_str() );

}

void
Sierpinski::DrawBasicTriangle() const {
    glVertex2f( this->LEFT.coord_x, this->LEFT.coord_y );
    glVertex2f( this->RIGHT.coord_x, this->RIGHT.coord_y );
    glVertex2f( this->TOP.coord_x, this->TOP.coord_y );
}

void
Sierpinski::DrawGasket() const {
    Point2 current_point = this->LEFT;

    for( int i = 0; i < this->ITERATIONS; i++ ){
        Point2 vertex   = this->GetRandomVertex();
        vertex          = this->GetMiddle( vertex, current_point );
        glVertex2f( vertex.coord_x, vertex.coord_y );
        current_point   = vertex;
    }
}


Point2
Sierpinski::GetMiddle( const Point2& start, const Point2& finish ) const {
    float coord_x   = ( start.coord_x + finish.coord_x ) / 2;
    float coord_y   = ( start.coord_y + finish.coord_y ) / 2;
    Point2 middle;
    middle.coord_x  = coord_x;
    middle.coord_y  = coord_y;
    return middle;
}

Point2
Sierpinski::GetRandomVertex() const {
    int toss = rand() % 3;
    if ( toss == 0 ) {
        return this->LEFT;
    } else if ( toss == 1 ) {
        return this->RIGHT;
    } else if ( toss == 2 ) {
        return this->TOP;
    } else {
        throw -1;
    }
}
