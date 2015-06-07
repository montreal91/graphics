#ifndef __SERPINSKY_H__

#define __SERPINSKY_H__

#include <string>
#include <stdlib.h>
#include <iostream>
#include <time.h>

#include "GL/freeglut.h"

struct Window{
    int width;
    int height;
};

struct ColorRGBA{
    float red, green, blue;
    float alpha;
};

struct Point2{
    float coord_x, coord_y;
};

class Sierpinski{
public:
    Sierpinski();
    Sierpinski( int argc, char** argv );
    ~Sierpinski();

    static Sierpinski* current_instance;

    static void DrawCallback(){
        current_instance->Draw();
    }

    void SetUpCallback();
    void Init() const;
    void Draw() const;

private:
    const std::string TITLE = "Sierpinski Gasket";
    Window SIZE;
    ColorRGBA FILL_COLOR, POINT_COLOR;
    Point2 LEFT, RIGHT, TOP;
    const int POINT_SIZE    = 1;
    const int ITERATIONS    = 50000;

    void CreateWindow( int argc, char** argv ) const;
    void DrawBasicTriangle() const;
    void DrawGasket() const;

    Point2 GetMiddle( const Point2& start, const Point2& finish ) const;
    Point2 GetRandomVertex() const;
};

#endif
