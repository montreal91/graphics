#include "vector.h"

AVector::AVector(){
    APoint start;
    APoint end(1, 1);
    this->start = start;
    this->end   = end;
}

AVector::AVector( const APoint& start, const APoint& end ) : 
    start( start ), 
    end( end ) 
{}

void
AVector::DrawObject() const {
    glBegin( GL_LINES );
        glVertex2d( this->start.GetX(), this->start.GetY() );
        glVertex2d( this->end.GetX(), this->end.GetY() );
    glEnd();
}

APoint
AVector::GetStart() const {
    return this->start;
}

APoint
AVector::GetEnd() const {
    return this->end;
}
