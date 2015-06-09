
#ifndef __POINT_H__
#define __POINT_H__

class APoint {
public:
    APoint();
    APoint( double x, double y );
    APoint( const APoint& point );

    double  GetX() const;
    double  GetY() const;

    void    SetX( const double x );
    void    SetY( const double y );
    void    Move( const double dx, const double dy );

private:
    double  coord_x, coord_y;

};

#endif
