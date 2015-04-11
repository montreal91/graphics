
#ifndef __GEOM_OBJECT_H__
#define __GEOM_OBJECT_H__

#include "GL/freeglut.h"

class AbsGeomObject {
public:
    virtual void DrawObject() const = 0;    
};
#endif
