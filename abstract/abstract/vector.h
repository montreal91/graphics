#ifndef __VECTOR_H__
#define __VECTOR_H__

#include "geomobject.h"
#include "point.h"

class AVector : public AbsGeomObject {
public:
    AVector();
    AVector( const APoint& start, const APoint& end );

    virtual void DrawObject() const;

    APoint GetStart() const;
    APoint GetEnd() const;

private:
    APoint start, end;    
};

#endif
