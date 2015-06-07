
#include "vector.h"

AVector* AVector::current_instance;

AVector::AVector( int argc, char** argv ){
    this->SIZE.width        = 800;
    this->SIZE.height       = 600;

    this->FILL_COLOR.red    = 0.05;
    this->FILL_COLOR.green  = 0.15;
    this->FILL_COLOR.blue   = 0.25;
    this->FILL_COLOR.alpha  = 0;

    this->POINT_COLOR.red   = 1;
    this->POINT_COLOR.green = 1;
    this->POINT_COLOR.blue  = 1;
    this->POINT_COLOR.alpha = 0;

    this->CreateWindow( argc, argv );

    this->start             = APoint( 200, 300 );
    this->length            = 300;
    this->phi               = this->PI / 4;
}

AVector::~AVector(){
}

void
AVector::DrawCallback() {
    current_instance->Draw();
}

void
AVector::KeyboardCallback( unsigned char key, int x, int y ) {
    current_instance->HandleKeyboard( key, x, y );
}

void
AVector::SetUpCallback() {
    current_instance = this;
    ::glutDisplayFunc( AVector::DrawCallback );
    ::glutKeyboardFunc( AVector::KeyboardCallback );
}

void
AVector::Draw() const {
    glClear( GL_COLOR_BUFFER_BIT );

    this->DrawVector();
    glFlush();
}

void
AVector::CreateWindow( int argc, char** argv ) const {
    glutInit( &argc, argv );
    glutInitDisplayMode( GLUT_SINGLE | GLUT_RGB );
    glutInitWindowSize( this->SIZE.width, this->SIZE.height );
    glutCreateWindow( this->TITLE.c_str() );
}

void
AVector::Init() const {
    glClearColor(
        this->FILL_COLOR.red,
        this->FILL_COLOR.green,
        this->FILL_COLOR.blue,
        this->FILL_COLOR.alpha
    );
    glColor3f( this->POINT_COLOR.red, this->POINT_COLOR.green, this->POINT_COLOR.blue );
    glPointSize( this->POINT_SIZE );

    glMatrixMode( GL_PROJECTION );
    glLoadIdentity();
    gluOrtho2D( 0, this->SIZE.width, 0, this->SIZE.height );

    glutMainLoop();
}

void
AVector::HandleKeyboard( unsigned char key, int x, int y ) {
    if ( key == 'f' ) {
        this->DecreaseLength();
        this->Draw();
    } else if ( key == 'r' ) {
        this->IncreaseLength();
        this->Draw();
    }
    if ( key == 'd' ) {
        this->IncreaseX();
        this->Draw();
    } else if ( key == 'a' ) {
        this->DecreaseX();
        this->Draw();
    }
    if ( key == 'w' ) {
        this->IncreaseY();
        this->Draw();
    } else if ( key == 's' ) {
        this->DecreaseY();
        this->Draw();
    }
    if ( key == 'e' ) {
        this->RotateAroundStart( true );
        this->Draw();
    } else if ( key == 'q' ) {
        this->RotateAroundStart( false );
        this->Draw();
    }
    if ( key == 'x' ) {
        this->RotateAroundCenter( true );
        this->Draw();
    } else if ( key == 'z' ) {
        this->RotateAroundCenter( false );
        this->Draw();
    }
}

void
AVector::DrawVector() const {
    APoint end = this->GetEndPoint();
    APoint top = this->GetArrowTopPoint();
    APoint bot = this->GetArrowBottomPoint();
    glBegin( GL_LINES );
        glVertex2d( this->start.GetX(), this->start.GetY() );
        glVertex2d( end.GetX(), end.GetY() );

        glVertex2d( top.GetX() + end.GetX(), top.GetY() + end.GetY() );
        glVertex2d( end.GetX(), end.GetY() );

        glVertex2d( bot.GetX() + end.GetX(), bot.GetY() + end.GetY() );
        glVertex2d( end.GetX(), end.GetY() );
    glEnd();
}

APoint
AVector::GetEndPoint() const {
    double coord_x = this->length * cos( this->phi ) + this->start.GetX();
    double coord_y = this->length * sin( this->phi ) + this->start.GetY();
    return APoint( coord_x, coord_y );
}

APoint
AVector::GetArrowTopPoint() const {
    double coord_x = ( this->length / 15 ) * cos( this->PI + this->phi + 0.15 );
    double coord_y = ( this->length / 15 ) * sin( this->PI + this->phi + 0.15 );
    return APoint( coord_x, coord_y );
}

APoint
AVector::GetArrowBottomPoint() const {
    double coord_x = ( this->length / 15 ) * cos( this->PI + this->phi - 0.15 );
    double coord_y = ( this->length / 15 ) * sin( this->PI + this->phi - 0.15 );
    return APoint( coord_x, coord_y );
}

APoint
AVector::GetCenterPoint() const {
    APoint end      = this->GetEndPoint();
    double coord_x  = ( this->start.GetX() + end.GetX() ) / 2;
    double coord_y  = ( this->start.GetY() + end.GetY() ) / 2;
    return APoint( coord_x, coord_y ); 
}

void 
AVector::IncreaseLength() {
    this->length += this->DELTA_LENGTH;
    if ( this->length > this->MAX_LENGTH ) {
        this->length = this->MAX_LENGTH;
    }
}

void 
AVector::DecreaseLength() {
    this->length -= this->DELTA_LENGTH;
    if ( this->length < this->MIN_LENGTH ) {
        this->length = this->MIN_LENGTH;
    }
}

void
AVector::IncreaseX() {
    double coord_x = this->start.GetX();
    coord_x += this->DS;
    if ( coord_x > this->SIZE.width ) {
        coord_x = this->SIZE.width;
    }
    this->start.SetX( coord_x );
}

void
AVector::DecreaseX() {
    double coord_x = this->start.GetX();
    coord_x -= this->DS;
    if ( coord_x < 0 ) {
        coord_x = 0;
    }
    this->start.SetX( coord_x );
}

void
AVector::IncreaseY() {
    double coord_y = this->start.GetY();
    coord_y += this->DS;
    if ( coord_y > this->SIZE.height ) {
        coord_y = this->SIZE.height;
    }
    this->start.SetY( coord_y );
}

void
AVector::DecreaseY() {
    double coord_y = this->start.GetY();
    coord_y -= this->DS;
    if ( coord_y < 0 ) {
        coord_y = 0;
    }
    this->start.SetY( coord_y );
}

void
AVector::RotateAroundStart( bool clockwise ) {
    if ( clockwise ) {
        this->phi -= this->DELTA_PHI;
    } else {
        this->phi += this->DELTA_PHI;
    }
}

void
AVector::RotateAroundCenter( bool clockwise ) {
    APoint center = this->GetCenterPoint();
    if ( clockwise ) {
        this->phi -= this->DELTA_PHI;
    } else {
        this->phi += this->DELTA_PHI;
    }
    double coord_x = ( this->length / 2 ) * cos( this->phi + this->PI ) + center.GetX();
    double coord_y = ( this->length / 2 ) * sin( this->phi + this->PI ) + center.GetY();
    this->start.SetX( coord_x );
    this->start.SetY( coord_y );
}
