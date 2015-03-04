#include "sierpinski.h"

int
main( int argc, char** argv ){
    Sierpinski serp( argc, argv );
    serp.SetUpCallback();
    serp.Init();
    return 0;
}
