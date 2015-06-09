
#include "square.h"

using namespace std;

int 
main( int argc, char** argv ){
    ASquare sqr( argc, argv );
    sqr.SetUpCallback();
    sqr.Init();
    return 0;
}
