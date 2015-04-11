#ifndef __POINT_H
#define __POINT_H

#include "geomobject.h"

class APoint : public AbsGeomObject {
public:
    APoint( double coord_x = 0, double coord_y = 0 );
    
    virtual void DrawObject() const;
    
    double GetX() const;
    double GetY() const;

private:
    double coord_x, coord_y;    
};
#endif
