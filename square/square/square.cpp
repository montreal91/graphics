
#include "square.h"

ASquare* ASquare::current_instance;
const bool ASquare::CLOCKWISE             = true;
const bool ASquare::COUNTER_CLOCKWISE     = false;

ASquare::ASquare( int argc, char** argv ){
    this->SIZE.width        = 800;
    this->SIZE.height       = 600;

    this->FILL_COLOR.red    = 0.75;
    this->FILL_COLOR.green  = 0.75;
    this->FILL_COLOR.blue   = 0.75;
    this->FILL_COLOR.alpha  = 0;

    this->FILL_COLOR.red    = 0.05;
    this->FILL_COLOR.green  = 0.25;
    this->FILL_COLOR.blue   = 0.15;
    this->POINT_COLOR.alpha = 0;

    this->CreateWindow( argc, argv );

    this->center = APoint( 100, 300 );
    this->psi   = 0;
    this->phi   = 0;
}

ASquare::~ASquare(){
}

void 
ASquare::DrawCallback() {
    current_instance->Draw();
}

void
ASquare::KeyboardCallback( unsigned char key, int x, int y ) {
    current_instance->HandleKeyboard( key, x, y );
}


void
ASquare::SetUpCallback(){
    current_instance = this;
    ::glutDisplayFunc( ASquare::DrawCallback );
    ::glutKeyboardFunc( ASquare::KeyboardCallback );
}

void
ASquare::Draw() const{
    glClear( GL_COLOR_BUFFER_BIT );
    this->DrawSquare();
    this->DrawCenter();
    glFlush();
}

void
ASquare::CreateWindow(int argc, char** argv) const{
    glutInit( &argc, argv );
    glutInitDisplayMode( GLUT_SINGLE | GLUT_RGB );
    glutInitWindowSize( this->SIZE.width, this->SIZE.height );
    glutCreateWindow( this->TITLE.c_str() );
}

void
ASquare::Init() const{
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
ASquare::DrawCenter() const {
    glColor3f( 1, 0, 0 );
    glBegin( GL_POINTS );
        glVertex2d( this->center.GetX(), this->center.GetY() );
    glEnd();
}

void
ASquare::DrawSquare() const {
    std::vector<APoint> vertices;
    for ( int i=0; i<4; i++ ) {
        double coord_x = this->diagon * cos( this->phi + this->PI * i / 2 ) + this->center.GetX();
        double coord_y = this->diagon * sin( this->phi + this->PI * i / 2 ) + this->center.GetY();
        vertices.push_back( APoint( coord_x, coord_y ) );
    }
    glColor3f( 0, 0, 0 );
    for( int i=0; i<4; i++ ) {
        glBegin( GL_POLYGON );
        if ( i == 3 ){
            glVertex2d( this->center.GetX(), this->center.GetY() );
            glVertex2d( vertices.at( i ).GetX(), vertices.at( i ).GetY() );
            glVertex2d( vertices.at( 0 ).GetX(), vertices.at( 0 ).GetY() );
        } else {
                glVertex2d( this->center.GetX(), this->center.GetY() );
                glVertex2d( vertices.at( i ).GetX(), vertices.at( i ).GetY() );
                glVertex2d( vertices.at( i+1 ).GetX(), vertices.at( i+1 ).GetY() );
            }
        glEnd();
        }
}

void
ASquare::IncreaseCenterX() {
    double coord_x = this->center.GetX();
    coord_x += this->DX;
    this->center.SetX( coord_x );
    this->psi = 0;
}

void
ASquare::DecreaseCenterX() {
    double coord_x = this->center.GetX();
    coord_x -= this->DX;
    this->center.SetX( coord_x );
    this->psi = 0;
}

void
ASquare::HandleKeyboard( unsigned char key, int x, int y ) {
    if ( key == 'a' ) {
        this->DecreaseCenterX();
        this->Rotate( COUNTER_CLOCKWISE );
        this->Draw();
    } else if ( key == 'd' ) {
        this->IncreaseCenterX();
        this->Rotate( CLOCKWISE );
        this->Draw();
    }
    if ( key == 'w' ) {
        this->Revolve( COUNTER_CLOCKWISE );
        this->Rotate( COUNTER_CLOCKWISE );
        this->Draw();
    } else if ( key == 's' ) {
        this->Revolve( CLOCKWISE );
        this->Rotate( CLOCKWISE );
        this->Draw();
    }
}

void
ASquare::UpdateOrbitCenter() const {
    double coord_x = this->center.GetX() - this->MAJOR_RADIUS;
    double coord_y = this->center.GetY();
    this->orbit_center.SetX( coord_x );
    this->orbit_center.SetY( coord_y );
}

void
ASquare::Revolve( bool clockwise ) {
    if ( this->psi == 0 ) {
        this->UpdateOrbitCenter();
    }
    if ( clockwise ) {
        this->psi -= this->D_PSI;
    } else { 
        this->psi += this->D_PSI;
    }
    double coord_x = this->MAJOR_RADIUS * cos( this->psi ) + this->orbit_center.GetX();
    double coord_y = this->MINOR_RADIUS * sin( this->psi ) + this->orbit_center.GetY();
    this->center.SetX( coord_x );
    this->center.SetY( coord_y );
}

void
ASquare::Rotate( bool clockwise ) {
    if ( clockwise ) {
        this->phi -= this->D_PHI;
        if ( this->phi < 0 ) {
            this->phi = this->PI * 2 + this->phi;
        }
    } else {
        this->phi += this->D_PHI;
        if ( this->phi > this->PI * 2 ) {
            this->phi -= ( this->PI * 2 );
        }
    }
}
