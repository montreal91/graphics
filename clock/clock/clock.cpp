
#include "clock.h"

AClock* AClock::current_instance;

AClock::AClock( int argc, char** argv ) {
    this->SIZE.width        = 800;
    this->SIZE.height       = 600;

    this->FILL_COLOR.red    = 1.0;
    this->FILL_COLOR.green  = 1.0;
    this->FILL_COLOR.blue   = 1.0;
    this->FILL_COLOR.alpha  = 0;

    this->POINT_COLOR.red   = 0.0;
    this->POINT_COLOR.green = 0.5;
    this->POINT_COLOR.blue  = 0.5;
    this->POINT_COLOR.alpha = 0;

    this->CreateWindow( argc, argv );
}

void
AClock::DrawCallback() {
    current_instance->Draw();
}

void
AClock::SetUpCallback() {
    current_instance = this;
    ::glutDisplayFunc( AClock::DrawCallback );
}

void
AClock::Draw() const {
    glClear( GL_COLOR_BUFFER_BIT );

    this->DrawBackGround();
    this->DrawCircle();
    this->DrawInnerCircle();
    this->DrawNumbers();
    this->DrawMinutePoints();
    this->DrawHourPoints();
    this->DrawSecondsArrow();
    this->DrawMinutesArrow();
    this->DrawHoursArrow();
    
    glFlush();
    glutPostRedisplay();
}

void
AClock::CreateWindow( int argc, char** argv ) const {
    glutInit( &argc, argv );
    glutInitDisplayMode( GLUT_SINGLE | GLUT_RGB );
    glutInitWindowSize( this->SIZE.width, this->SIZE.height );
    glutCreateWindow( this->TITLE.c_str() );
}

void
AClock::Init() const {
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
AClock::DrawCircle() const {
    glColor3f( this->POINT_COLOR.red, this->POINT_COLOR.green, this->POINT_COLOR.blue );
    glPointSize( this->POINT_SIZE );

    glBegin( GL_POINTS );

    for( double t = 0; t<=this->PI * 2; t += 0.001 ) {
        APoint c_pixel( this->RADIUS * cos( t ), this->RADIUS * sin( t ) );
        c_pixel.Draw();
    }
    glEnd();
}

void
AClock::DrawInnerCircle() const {
    glColor3f( this->POINT_COLOR.red, this->POINT_COLOR.green, this->POINT_COLOR.blue );
    glPointSize( this->POINT_SIZE );

    glBegin( GL_POINTS );

    for( double t = 0; t<=this->PI * 2; t += 0.001 ) {
        APoint c_pixel( this->RADIUS * 0.95 * cos( t ), this->RADIUS * 0.95 * sin( t ) );
        c_pixel.Draw();
    }
    glEnd();
}

void
AClock::DrawSecondsArrow() const {
    APoint vertex = this->GetSecondsArrowEndPoint();

    glColor3f( 1, 0, 0 );
    glBegin( GL_LINES );

    glVertex2d( 0, 0 );
    glVertex2d( vertex.GetX(), vertex.GetY() );

    glEnd();
}

void
AClock::DrawMinutesArrow() const {
    APoint vertex = this->GetMinutesArrowEndPoint();

    glColor3f( 0, 0, 0 );
    glBegin( GL_LINES );

    glVertex2d( 0, 0 );
    glVertex2d( vertex.GetX(), vertex.GetY() );

    glEnd();
}

void
AClock::DrawHoursArrow() const {
    APoint vertex = this->GetHoursArrowEndPoint();

    glColor3f( 1, 1, 1 );
    glBegin( GL_LINES );

    glVertex2d( 0, 0 );
    glVertex2d( vertex.GetX(), vertex.GetY() );

    glEnd();
}

void
AClock::DrawMinutePoints() const {
    for( double phi = 0; phi <= this->PI*2; phi += ( this->PI / 30 ) ) {
        glBegin( GL_LINES );
            glVertex2d( ( this->RADIUS * 0.95 ) * cos( phi ), ( this->RADIUS * 0.95 ) * sin( phi ) );
            glVertex2d( this->RADIUS * cos( phi ), this->RADIUS * sin( phi ) );
        glEnd();
    }
}

void
AClock::DrawHourPoints() const {
    for ( double phi = 0; phi <= this->PI * 2; phi += ( this->PI / 6 ) ) {
        glBegin( GL_LINES );
            glVertex2d( ( this->RADIUS * 0.85 ) * cos( phi ), ( this->RADIUS * 0.85 ) * sin( phi ) );
            glVertex2d( this->RADIUS * cos( phi ), this->RADIUS * sin( phi ) );
        glEnd();
    }
}

void
AClock::DrawBackGround() const {
    float green = 0.5;

    for ( double radius = 0; radius <= this->RADIUS; radius+= 1 ) {
        glColor3f( 0, green, 0 );
        glPointSize( this->POINT_SIZE );
        glBegin( GL_POINTS );

        for( double t = 0; t<=this->PI * 2; t += 0.005 ) {
            APoint c_pixel( radius * cos( t ), radius * sin( t ) );
            c_pixel.Draw();
        }
        glEnd();
        green += 0.00125;
    }
}

APoint
AClock::GetSecondsArrowEndPoint() const {
    std::time_t ct = std::time( nullptr );
    long sec       = ( long )ct % 60;
    double phi     = - this->PI / 30 * sec + this->PI / 2;

    double coord_x = this->SECONDS_ARROW_LENGTH * cos( phi );
    double coord_y = this->SECONDS_ARROW_LENGTH * sin( phi );
    return APoint( coord_x, coord_y );
}

APoint
AClock::GetMinutesArrowEndPoint() const {
    std::time_t ct = std::time( nullptr );
    long min       = ( long )ct % 3600;
    double phi     = - min / 1800.0 * this->PI + this->PI / 2;

    double coord_x = this->MINUTES_ARROW_LENGTH * cos( phi );
    double coord_y = this->MINUTES_ARROW_LENGTH * sin( phi );
    return APoint( coord_x, coord_y );
}

APoint
AClock::GetHoursArrowEndPoint() const {
    std::time_t ct = std::time( nullptr );
    long hour      = ( long )ct % 43200 - 25200;
    double phi     = - hour * 2 / 43200.0 * this->PI + this->PI / 2;

    double coord_x = this->HOURS_ARROW_LENGTH * cos( phi );
    double coord_y = this->HOURS_ARROW_LENGTH * sin( phi );
    return APoint( coord_x, coord_y );
}

void
AClock::DrawIII() const {
    glBegin( GL_LINES );
        glVertex2f(450, 40);
        glVertex2f(450, -40 );
    glEnd();
    glBegin( GL_LINES );
        glVertex2f(480, 40);
        glVertex2f(480, -40 );
    glEnd();
    glBegin( GL_LINES );
        glVertex2f(510, 40);
        glVertex2f(510, -40 );
    glEnd();
}

void
AClock::DrawVI() const {
    glBegin( GL_LINES );
        glVertex2f( -5, -440 );
        glVertex2f( -25, -520 );
    glEnd();
    glBegin( GL_LINES );
        glVertex2f(-40, -440);
        glVertex2f(-25, -520 );
    glEnd();
    glBegin( GL_LINES );
        glVertex2f( 10, -440 );
        glVertex2f( 10, -520 );
    glEnd();
}

void
AClock::DrawIX() const {
    glBegin( GL_LINES );
        glVertex2f(-450, 40);
        glVertex2f(-480, -40 );
    glEnd();
    glBegin( GL_LINES );
        glVertex2f(-480, 40);
        glVertex2f(-450, -40 );
    glEnd();
    glBegin( GL_LINES );
        glVertex2f(-510, 40);
        glVertex2f(-510, -40 );
    glEnd();
}

void
AClock::DrawXII() const {
    glBegin( GL_LINES );
        glVertex2f(-30-15, 40+500);
        glVertex2f(0-15, -40+500 );
    glEnd();
    glBegin( GL_LINES );
        glVertex2f(0-15, 40+500);
        glVertex2f(-30-15, -40+500 );
    glEnd();
    glBegin( GL_LINES );
        glVertex2f(30-15, 40+500);
        glVertex2f(30-15, -40+500 );
    glEnd();
    glBegin( GL_LINES );
        glVertex2f(45, 40+500);
        glVertex2f(45, -40+500 );
    glEnd();
}

void
AClock::DrawNumbers() const {
    this->DrawIII();
    this->DrawVI();
    this->DrawIX();
    this->DrawXII();
}
