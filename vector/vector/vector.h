
#ifndef __SPEEDOMETER_H__
#define __SPEEDOMETER_H__

#include <string>
#include <stdlib.h>
#include <iostream>
#include <time.h>
#include <math.h>

#include "GL/freeglut.h"

#include "point.h"

struct Window {
    int width;
    int height;
};

struct ColorRGBA {
    float red, green, blue;
    float alpha;
};

class AVector {
public:
    AVector( int argc, char** argv );
    ~AVector();

    static AVector* current_instance;

    static void DrawCallback();
    static void KeyboardCallback( unsigned char key, int x, int y );

    void SetUpCallback();
    void Init() const;

private:
    Window SIZE;
    ColorRGBA FILL_COLOR, POINT_COLOR;
    const std::string TITLE     = "Vector";
    const int POINT_SIZE        = 1;
    const double PI             = 3.141592;

    const double MAX_LENGTH     = 500;
    const double MIN_LENGTH     = 50;
    const double DELTA_LENGTH   = 5;
    const double DELTA_PHI      = 0.5;
    const double DS             = 2;

    APoint start;
    double length, phi;

    void Draw() const;
    void DrawVector() const;
    
    void CreateWindow( int argc, char** argv ) const;
    void HandleKeyboard( unsigned char key, int x, int y );

    APoint GetEndPoint() const;
    APoint GetArrowTopPoint() const;
    APoint GetArrowBottomPoint() const;
    APoint GetCenterPoint() const;

    void IncreaseLength();
    void DecreaseLength();

    void IncreaseX();
    void DecreaseX();
    void IncreaseY();
    void DecreaseY();
    
    void RotateAroundStart( bool clockwise );
    void RotateAroundCenter( bool clockwise  );
};

#endif
