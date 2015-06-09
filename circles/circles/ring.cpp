
#include "ring.h"

const double ARing::PI      = 3.141592;
const int ARing::RED        = 0;
const int ARing::GREEN      = 1;
const int ARing::BLUE       = 2;

ARing::ARing() {
    this->center = APoint( 0, 0 );
    this->inner_radius      = 25;
    this->outer_radius      = 50;
    this->is_selected       = false;
    this->color             = RED;
    this->VERTICES_IN_RING  = 35;
}

ARing::ARing( APoint& center, double inner_radius, double outer_radius, const int& color ) {
    this->center            = center;
    this->inner_radius      = inner_radius;
    this->outer_radius      = outer_radius;
    this->is_selected       = false;
    this->color             = color;
    this->VERTICES_IN_RING  = 35;
}

ARing::~ARing() {
}

void
ARing::MoveCenter( const double dx, const double dy ) {
    if ( this->is_selected ) {
        this->center.Move( dx, dy );
    }
}

void
ARing::ToggleSelection() {
    this->is_selected = !this->is_selected;
}

bool
ARing::PointInRing( const APoint& point ) const {
    bool cond_1 = this->InsideOuterRadius( point.GetX(), point.GetY() );
    bool cond_2 = this->OutsideInnerRadius( point.GetX(), point.GetY() );
    return cond_1 && cond_2;
}

void
ARing::Draw() const {
    AColor clr = this->GetColor();
    glColor3d( clr.GetRed(), clr.GetGreen(), clr.GetBlue() );
    for ( int i=0; i<this->VERTICES_IN_RING; i++ ) {
        APoint a = this->GetVertexOnInnerRadius( i * this->GetSmallestSector() );
        APoint b = this->GetVertexOnInnerRadius( ( i + 1 ) * this->GetSmallestSector() );
        APoint c = this->GetVertexOnOuterRadius( i * this->GetSmallestSector() );
        APoint d = this->GetVertexOnOuterRadius( ( i + 1 ) * this->GetSmallestSector() );
        this->DrawQuadrangle( a, b, c, d );
    }
}

bool
ARing::InsideOuterRadius( const double cx, const double cy ) const {
    return pow( cx - this->center.GetX(), 2 ) + pow( cy - this->center.GetY(), 2 ) <= pow( this->outer_radius, 2 );
}

bool
ARing::OutsideInnerRadius( const double cx, const double cy ) const {
    return pow( cx - this->center.GetX(), 2 ) + pow( cy - this->center.GetY(), 2 ) >= pow( this->inner_radius, 2 );
}

AColor
ARing::GetColor() const {
    if ( this->color == RED ) {
        if ( this->is_selected ) {
            return AColor::ABSOLUTE_RED;
        } else {
            return AColor::RED;
        }
    } else if ( this->color == GREEN ) {
        if ( this->is_selected ) {
            return AColor::ABSOLUTE_GREEN;
        } else {
            return AColor::GREEN;
        }
    } else if ( this->color == BLUE ) {
        if ( this->is_selected ) {
            return AColor::ABSOLUTE_BLUE;
        } else {
            return AColor::BLUE;
        }
    } else {
        return AColor::ABSOLUTE_BLACK;
    }
}

APoint
ARing::GetVertexOnInnerRadius( const double phi ) const {
    double coord_x = this->inner_radius * cos( phi ) + this->center.GetX();
    double coord_y = this->inner_radius * sin( phi ) + this->center.GetY();
    return APoint( coord_x, coord_y );
}

APoint
ARing::GetVertexOnOuterRadius( const double phi ) const {
    double coord_x = this->outer_radius * cos( phi ) + this->center.GetX();
    double coord_y = this->outer_radius * sin( phi ) + this->center.GetY();
    return APoint( coord_x, coord_y );
}

double
ARing::GetSmallestSector() const {
    return 2 * PI / this->VERTICES_IN_RING;
}

void
ARing::DrawQuadrangle( const APoint& a, const APoint& b, const APoint& c, const APoint& d ) const {
    glBegin( GL_POLYGON );
        glVertex2d( a.GetX(), a.GetY() );
        glVertex2d( b.GetX(), b.GetY() );
        glVertex2d( d.GetX(), d.GetY() );

        glVertex2d( a.GetX(), a.GetY() );
        glVertex2d( c.GetX(), c.GetY() );
        glVertex2d( d.GetX(), d.GetY() );
    glEnd();
}
