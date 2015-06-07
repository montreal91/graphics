
#include "vector.h"

using namespace std;

int 
main( int argc, char** argv ){
    AVector vtr( argc, argv );
    vtr.SetUpCallback();
    vtr.Init();
    return 0;
}
