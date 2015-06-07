
#ifndef __SPEEDOMETER_H__
#define __SPEEDOMETER_H__

#include <string>
#include <math.h>
#include <ctime>
#include <iostream>

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

class AClock {
public:
    AClock();
    AClock( int argc, char** argv );

    static AClock* current_instance;

    void SetUpCallback();
    void Init() const;

    static void DrawCallback();
    static void KeyboardCallback( unsigned char key, int x, int y );

private:
    const std::string TITLE             = "Clock";
    Window SIZE;
    ColorRGBA FILL_COLOR, POINT_COLOR;
    const int POINT_SIZE                = 1;
    const int RADIUS                    = 400;
    const double SECONDS_ARROW_LENGTH   = this->RADIUS * 0.85;
    const double MINUTES_ARROW_LENGTH   = this->RADIUS * 0.75;
    const double HOURS_ARROW_LENGTH     = this->RADIUS * 0.50;
    const double PI                     = 3.141592;


    void Draw() const;

    void CreateWindow( int argc, char** argv ) const;
    void DrawCircle() const;
    void DrawInnerCircle() const;
    void DrawBackGround() const;
    void DrawSecondsArrow() const;
    void DrawMinutesArrow() const;
    void DrawHoursArrow() const;
    void DrawMinutePoints() const;
    void DrawHourPoints() const;

    void DrawIII() const;
    void DrawVI() const;
    void DrawIX() const;
    void DrawXII() const;

    void DrawNumbers() const;

    APoint GetSecondsArrowEndPoint() const;
    APoint GetMinutesArrowEndPoint() const;
    APoint GetHoursArrowEndPoint() const;
};

#endif
