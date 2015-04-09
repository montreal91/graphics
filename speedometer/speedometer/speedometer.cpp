
#include "speedometer.h"

ASpeedometer* ASpeedometer::current_instance;

ASpeedometer::ASpeedometer( int argc, char** argv ) {
    this->SIZE.width        = 800;
    this->SIZE.height       = 600;

    this->FILL_COLOR.red    = 0.40;
    this->FILL_COLOR.green  = 0.75;
    this->FILL_COLOR.blue   = 0.40;
    this->FILL_COLOR.alpha  = 0;

    this->POINT_COLOR.red   = 0.0;
    this->POINT_COLOR.green = 0.5;
    this->POINT_COLOR.blue  = 0.5;
    this->POINT_COLOR.alpha = 0;

    this->CreateWindow( argc, argv );
}

void
ASpeedometer::DrawCallback() {
    current_instance->Draw();
}

void
ASpeedometer::KeyboardCallback( unsigned char key, int x, int y ) {
    current_instance->HandleKeyboard( key, x, y );
}

void
ASpeedometer::SetUpCallback() {
    current_instance = this;
    ::glutKeyboardFunc( ASpeedometer::KeyboardCallback );
    ::glutDisplayFunc( ASpeedometer::DrawCallback );
}

void
ASpeedometer::Draw() const {
    glClear( GL_COLOR_BUFFER_BIT );

    this->DrawCircle();
    this->DrawSpeedPoints();
    this->DrawArrow();
    
    glFlush();
}

void
ASpeedometer::HandleKeyboard( unsigned char key, int x, int y ) {
    if( key == 'w' ){
        this->IncreasePhi();
        this->Draw();
    } else if( key=='s' ) {
        this->DecreasePhi();
        this->Draw();
    }
}

void
ASpeedometer::CreateWindow( int argc, char** argv ) const {
    glutInit( &argc, argv );
    glutInitDisplayMode( GLUT_SINGLE | GLUT_RGB );
    glutInitWindowSize( this->SIZE.width, this->SIZE.height );
    glutCreateWindow( this->TITLE.c_str() );
}

void
ASpeedometer::Init() const {
    glClearColor(
        this->FILL_COLOR.red,
        this->FILL_COLOR.green,
        this->FILL_COLOR.blue,
        this->FILL_COLOR.alpha
    );

    glMatrixMode( GL_PROJECTION );
    glLoadIdentity();
    gluOrtho2D( -this->SIZE.width, this->SIZE.width, -this->SIZE.height + 100, this->SIZE.height + 100 );

    glutMainLoop();
}

void
ASpeedometer::DrawCircle() const {
    glColor3f( this->POINT_COLOR.red, this->POINT_COLOR.green, this->POINT_COLOR.blue );
    glPointSize( this->POINT_SIZE );

    glBegin( GL_POINTS );

    for( double t= - this->PI/2; t<=this->PI/2; t += 0.001 ){
        APoint c_pixel( this->RADIUS * cos( t ), this->RADIUS * sin( t ) );
        c_pixel.Draw();
    }
    glEnd();
}

void
ASpeedometer::DrawArrow() const {
    APoint vertex = this->GetArrowEndPoint();

    glColor3f( 1, 0, 0 );
    glBegin( GL_LINES );

    glVertex2d( 0, 0 );
    glVertex2d( vertex.GetX(), vertex.GetY() );

    glEnd();
}

void
ASpeedometer::DrawSpeedPoints() const {
    for( double phi = - this->PI/2; phi <= this->PI/2; phi += ( this->PI / 12 ) ) {
        glBegin( GL_LINES );
            glVertex2d( ( this->RADIUS * 0.9 ) * cos( phi ), ( this->RADIUS * 0.9 ) * sin( phi ) );
            glVertex2d( this->RADIUS * cos( phi ), this->RADIUS * sin( phi ) );
        glEnd();
    }
}

APoint
ASpeedometer::GetArrowEndPoint() const {
    double coord_x = this->ARROW_LENGTH * cos( this->phi );
    double coord_y = this->ARROW_LENGTH * sin( this->phi );
    return APoint( coord_x, coord_y );
}

void
ASpeedometer::IncreasePhi() {
    this->phi += 0.01;
    if( this->phi >= this->PI / 2 ) {
        this->phi = this->PI;
    }
}

void
ASpeedometer::DecreasePhi() {
    this->phi -= 0.01;
    if( this->phi <= - this->PI / 2 ) {
        this->phi = - this->PI / 2;
    }
}
