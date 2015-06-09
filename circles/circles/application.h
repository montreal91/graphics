
#ifndef __SPEEDOMETER_H__
#define __SPEEDOMETER_H__

#include <iostream>
#include <math.h>
#include <string>
#include <stdlib.h>
#include <time.h>
#include <vector>

#include <GL/freeglut.h>

#include "ring.h"

struct Window {
    int width;
    int height;
};

class AnApplication {
public:
    AnApplication( int argc, char** argv );
    ~AnApplication();

    static      AnApplication* current_instance;
    
    static void DrawCallback();
    static void KeyboardCallback( unsigned char key, int x, int y );
    static void MouseCallback( int key, int state, int x, int y );

    void        SetUpCallback();
    void        Init() const;

private:
    const std::string   TITLE           = "The Lord of the Rings";
    Window              SIZE;
    const int           POINT_SIZE      = 4;
    const double        SPEED           = 5;
    const double        DEFAULT_INNER   = 25;
    const double        DEFAULT_OUTER   = 50;

    std::vector<ARing>  rings_v;

    void                Draw() const;
    
    void                CreateWindow( int argc, char** argv ) const;
    void                HandleKeyboard( unsigned char key, int x, int y );
    void                HandleMouse( int key, int state, int x, int y );
    ARing               CreateRing( const double cx, const double cy ) const;

};

#endif
