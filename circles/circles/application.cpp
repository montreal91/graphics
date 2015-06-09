
#include "application.h"

AnApplication* AnApplication::current_instance;

AnApplication::AnApplication( int argc, char** argv ) {
    this->SIZE.width        = 800;
    this->SIZE.height       = 600;

    this->CreateWindow( argc, argv );

    this->rings_v           = std::vector<ARing>();
}

AnApplication::~AnApplication() {
}

void 
AnApplication::DrawCallback() {
    current_instance->Draw();
}

void
AnApplication::KeyboardCallback( unsigned char key, int x, int y ) {
    current_instance->HandleKeyboard( key, x, y );
}

void
AnApplication::MouseCallback( int key, int state, int x, int y ) {
    current_instance->HandleMouse( key, state, x, y );
}

void
AnApplication::SetUpCallback() {
    current_instance = this;
    ::glutDisplayFunc( AnApplication::DrawCallback );
    ::glutKeyboardFunc( AnApplication::KeyboardCallback );
    ::glutMouseFunc( AnApplication::MouseCallback );
}

void
AnApplication::Draw() const {
    glClear( GL_COLOR_BUFFER_BIT );
    for ( const ARing& ring : this->rings_v ) {
        ring.Draw();
    }
    glFlush();
}

void
AnApplication::CreateWindow( int argc, char** argv ) const {
    glutInit( &argc, argv );
    glutInitDisplayMode( GLUT_SINGLE | GLUT_RGB );
    glutInitWindowSize( this->SIZE.width, this->SIZE.height );
    glutCreateWindow( this->TITLE.c_str() );
}

void
AnApplication::Init() const {
    glClearColor(
        AColor::RED.GetRed(),
        AColor::RED.GetGreen(),
        AColor::RED.GetBlue(),
        1
    );
    glPointSize( this->POINT_SIZE );

    glMatrixMode( GL_PROJECTION );
    glLoadIdentity();
    gluOrtho2D( 0, this->SIZE.width, 0, this->SIZE.height );

    glutMainLoop();
}

void
AnApplication::HandleKeyboard( unsigned char key, int x, int y ) {
    if ( key == 'w' ) {
        for( ARing& ring : this->rings_v ) {
            ring.MoveCenter( 0, this->SPEED );
            this->Draw();
        }
    }
    if ( key == 's' ) {
        for( ARing& ring : this->rings_v ) {
            ring.MoveCenter( 0, -this->SPEED );
            this->Draw();
        }
    }
    if ( key == 'a' ) {
        for( ARing& ring : this->rings_v ) {
            ring.MoveCenter( -this->SPEED, 0 );
            this->Draw();
        }
    }
    if ( key == 'd' ) {
        for( ARing& ring : this->rings_v ) {
            ring.MoveCenter( this->SPEED, 0 );
            this->Draw();
        }
    }
    if ( key == 'c' ) {
        this->rings_v.push_back( this->CreateRing( (double)x, (double)(this->SIZE.height - y) ) );
        this->Draw();
    }
}

void
AnApplication::HandleMouse( int key, int state, int x, int y ) {
    APoint point = APoint( x, this->SIZE.height - y );
    if ( key == GLUT_LEFT_BUTTON && state == GLUT_DOWN ) {
        for( ARing& ring : this->rings_v ) {
            if ( ring.PointInRing( point ) ){
                ring.ToggleSelection();
                this->Draw();
            }
        }
    }
}

ARing
AnApplication::CreateRing( const double cx, const double cy ) const {
    APoint center = APoint( cx, cy );
    if ( this->rings_v.size() % 2 == 0 ){
        return ARing( center, this->DEFAULT_INNER, this->DEFAULT_OUTER, ARing::BLUE );
    } else {
        return ARing( center, this->DEFAULT_INNER, this->DEFAULT_OUTER, ARing::GREEN );
    }
}
