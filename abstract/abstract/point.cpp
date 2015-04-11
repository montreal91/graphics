#include "point.h"

APoint::APoint( double coord_x, double coord_y ) : 
    coord_x( coord_x ), 
    coord_y( coord_y ) 
{}

void
APoint::DrawObject() const {
    glBegin( GL_POINTS );
        glVertex2d( this->GetX(), this->GetY() );
    glEnd();
}

double
APoint::GetX() const {
    return this->coord_x;
}

double
APoint::GetY() const {
    return this->coord_y;
}
