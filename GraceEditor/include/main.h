#pragma once
#include <GraceEngine/window.h>
//Define the runtime functions
namespace runtimeFunctions {
    graceEngine* start();
    int logic(graceEngine &window);
    int end();
}
