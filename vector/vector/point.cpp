
#include "point.h"

APoint::APoint() {
    this->coord_x = 0;
    this->coord_y = 0;
}

APoint::APoint( double x, double y ) {
    this->coord_x = x;
    this->coord_y = y;
}

APoint::APoint( const APoint& p ) {
    this->coord_x = p.GetX();
    this->coord_y = p.GetY();
}

double
APoint::GetX() const {
    return this->coord_x;
}

double
APoint::GetY() const {
    return this->coord_y;
}

void
APoint::SetX( const double x ) {
    this->coord_x = x;
}

void
APoint::SetY( const double y ) {
    this->coord_y = y;
}
