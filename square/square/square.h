
#ifndef __SPEEDOMETER_H__
#define __SPEEDOMETER_H__

#include <iostream>
#include <math.h>
#include <string>
#include <stdlib.h>
#include <time.h>
#include <vector>

#include <GL/freeglut.h>

#include "point.h"

struct Window{
    int width;
    int height;
};

struct ColorRGBA{
    float red, green, blue;
    float alpha;
};

class ASquare {
public:
    ASquare( int argc, char** argv );
    ~ASquare();

    static ASquare* current_instance;
    static const bool CLOCKWISE;
    static const bool COUNTER_CLOCKWISE;
    
    static void DrawCallback();
    static void KeyboardCallback( unsigned char key, int x, int y );

    void SetUpCallback();
    void Init() const;

private:
    const std::string TITLE     = "Rotating Square";
    Window SIZE;
    ColorRGBA FILL_COLOR, POINT_COLOR;
    const int POINT_SIZE        = 4;
    const double DX             = 5;
    const double D_PSI          = 0.05;
    const double D_PHI          = 0.10;
    const double PI             = 3.141592;

    const double MAJOR_RADIUS   = 150;
    const double MINOR_RADIUS   = 75;

    const double diagon         = 50;

    APoint center;
    APoint orbit_center;
    double psi, phi;

    void UpdateOrbitCenter() const;

    void Draw() const;
    void DrawCenter() const;
    void DrawSquare() const;
    
    void CreateWindow( int argc, char** argv ) const;
    void HandleKeyboard( unsigned char key, int x, int y );

    void IncreaseCenterX();
    void DecreaseCenterX();
    void Revolve( bool clockwise );
    void Rotate( bool clockwise );
};

#endif
