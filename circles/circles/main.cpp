
#include "application.h"

using namespace std;

int 
main( int argc, char** argv ){
    AnApplication app( argc, argv );
    app.SetUpCallback();
    app.Init();
    return 0;
}
