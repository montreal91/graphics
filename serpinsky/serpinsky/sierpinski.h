#ifndef __SERPINSKY_H__

#define __SERPINSKY_H__

#include <string>
#include <stdlib.h>
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
    void Init();
    void Draw();

private:
    const std::string TITLE = "Sierpinski Gasket";
    Window SIZE;
    ColorRGBA FILL_COLOR, POINT_COLOR;
    Point2 LEFT, RIGHT, TOP;
    const int POINT_SIZE    = 1;

//    void Init();
    void CreateWindow( int argc, char** argv );
    void DrawBasicTriangle();
    void DrawGasket();

    Point2 GetMiddle( Point2& start, Point2& finish );
    Point2 GetRandomVertex();
};

#endif
