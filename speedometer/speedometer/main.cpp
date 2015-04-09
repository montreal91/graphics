
#include "speedometer.h"

using namespace std;

int 
main( int argc, char** argv ){
    ASpeedometer spm( argc, argv );
    spm.SetUpCallback();
    spm.Init();
    return 0;
}

