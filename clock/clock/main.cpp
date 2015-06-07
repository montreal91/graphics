
#include "clock.h"

using namespace std;

int 
main( int argc, char** argv ){
    AClock clk( argc, argv );
    clk.SetUpCallback();
    clk.Init();

//    std::time_t ct = std::time( nullptr );
//    auto sec = (long)ct;
//    std::cout<< sec % 60 << std::endl;
    return 0;
}

