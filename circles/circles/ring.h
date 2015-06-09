
#ifndef __RING_H__
#define __RING_H__

#include <math.h>

#include <GL/freeglut.h>

#include "color.h"
#include "point.h"

class ARing {
public:
    ARing();
    ARing( APoint& center, double inner_radius, double outer_radius, const int& color );
    ~ARing();

    static const double PI;
    static const int    RED;
    static const int    GREEN;
    static const int    BLUE;

    void                MoveCenter( const double dx, const double dy );
    void                ToggleSelection();

    bool                PointInRing( const APoint& point ) const;
    bool                PointInRing( double coord_x, double coord_y ) const;

    void                Draw() const;

private:
    int     VERTICES_IN_RING;
    double  inner_radius, outer_radius;
    APoint  center;
    bool    is_selected;
    int     color;

    bool    InsideOuterRadius( const double cx, const double cy ) const;
    bool    OutsideInnerRadius( const double cx, const double cy ) const;

    AColor  GetColor() const;
    APoint  GetVertexOnInnerRadius( const double phi ) const;
    APoint  GetVertexOnOuterRadius( const double phi ) const;
    double  GetSmallestSector() const;

    void    DrawQuadrangle( const APoint& a, const APoint& b, const APoint& c, const APoint& d ) const;

};

#endif
