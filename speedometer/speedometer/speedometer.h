
#ifndef __SPEEDOMETER_H__
#define __SPEEDOMETER_H__

#include <string>
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

class ASpeedometer{
public:
    ASpeedometer();
    ASpeedometer( int argc, char** argv );

    static ASpeedometer* current_instance;

    void SetUpCallback();
    void Init() const;

    static void DrawCallback();
    static void KeyboardCallback( unsigned char key, int x, int y );

private:
    const std::string TITLE     = "Speedometer";
    Window SIZE;
    ColorRGBA FILL_COLOR, POINT_COLOR;
    const int POINT_SIZE        = 1;
    const int RADIUS            = 400;
    const double ARROW_LENGTH   = this->RADIUS * 0.8;
    const double PI             = 3.141592;

    double phi                  = - this->PI / 2;

    void Draw() const;
    void HandleKeyboard( unsigned char key, int x, int y );

    void CreateWindow( int argc, char** argv ) const;
    void DrawCircle() const;
    void DrawArrow() const;
    void DrawSpeedPoints() const;

    void IncreasePhi();
    void DecreasePhi();

    APoint GetArrowEndPoint() const;
};

#endif
